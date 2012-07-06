#include "StdAfx.h"
#include "CA210.h"
#include <cstdlib>
#include <ctime>

Ca210::Ca210(BOOL tr):ImpsbStr("1. 按「Prt Scm鍵」抓下目前的螢幕，並開小畫家貼上，另存成圖檔\n2. Mail給此程式設計者，詳細描述使用過程並將圖檔存成附件\n這是尚未預測到出現的問題。（應該不會發生的那種。）")
{
	/*
	初始化ca-210
	設定是否為模擬機
	*/
	m_DebugFlag = FALSE;
	m_isTrue = tr;  //TRUE接實體儀器, FALSE模擬儀器
	if (m_isTrue)
	{
		if (m_DebugFlag) DBugModeBox("TRUE of Ca210(BOOL tr)");
		int flag = 0;
		CString CloseSetp("1. 檢查USB線和量筒\n2. 按確定");
		do 
		{
			try
			{
				m_ICa200.CreateDispatch("CA200Srvr.Ca200.1");
			}
			catch (CException* e)
			{
				MsgFrmt(e, "m_ICa200.CreateDispatch(\"CA200Srvr.Ca200.1\");出問題", CloseSetp);
				flag++;
				continue;
			}

			m_ICa200.m_bAutoRelease = TRUE;

			try
			{
				m_ICa200.AutoConnect();
			}
			catch (CException* e)
			{
				MsgFrmt(e, "m_ICa200.AutoConnect();出問題", CloseSetp);
				flag++;
				continue;
			}

			LPDISPATCH pICa;

			try
			{
				pICa = m_ICa200.GetSingleCa();
			}			
			catch (CException* e)
			{
				MsgFrmt(e, "LPDISPATCH pICa = m_ICa200.GetSingleCa();出問題", CloseSetp);
				flag++;
				continue;
			}

			m_ICa.AttachDispatch(pICa);
			
			LPDISPATCH pIProbe;
			try
			{
				pIProbe = m_ICa.GetSingleProbe();
				flag = 0;
			}			
			catch (CException* e)
			{
				MsgFrmt(e, "LPDISPATCH pIProbe = m_ICa.GetSingleProbe();出問題", CloseSetp);
				flag++;
				continue;
			}
			
			m_IProbe.AttachDispatch(pIProbe);
		
			//判斷是否Zero Cal
		} while (flag);

		try
		{
			m_ICa.Measure(0);
			m_isZeroCal = TRUE;
		}
		catch (CException* e)
		{
			TCHAR buf[255];
			e->GetErrorMessage(buf, 255);

			//MsgFrmt(e, "量測出問題", "剛剛是不是不正常使用量筒（像是搖它或對著強光源...之類的）\n否則，不要移動量筒按確定重量剛剛的點");			
			m_isZeroCal = FALSE;
		}
		SetOnline(FALSE);
	}
	else
	{
		//模擬機
		if (m_DebugFlag) DBugModeBox("FALSE of Ca210(BOOL tr)");
		m_isZeroCal = FALSE;
		m_Online    = FALSE;
	}
}

Ca210::~Ca210()
{
	if (m_isTrue)
	{
		if (m_DebugFlag) DBugModeBox("TRUE of ~Ca210()");
		SetOnline(FALSE);
	}
}
BOOL Ca210::isTrue() const
{
	if (m_DebugFlag) DBugModeBox("TRUE of isTrue()");
	return m_isTrue;
}

BOOL Ca210::CalZero()
{
	/*
	連線 實機
	caes 11   執行ZeroCal
			    例外處理:
				  給MessageBox
			      再執行ZeroCal
	case 10   Delay1sec 模擬ZeroCal的時間
	default   回傳FALSE  無法執行
	*/	
	if(m_Online && m_isTrue)
	{
		if (m_DebugFlag) DBugModeBox("TRUE of CalZero()");

		int flag = 0;
 		do 
 		{
			try
			{
				m_ICa.CalZero();
				m_isZeroCal = TRUE;
				flag = 0;
			}
			catch (CException* e)
			{
				if (flag < 1)
					MsgFrmt(e,"將套筒還沒轉至0-Cal就執行Zero Cal", "1. 將量測筒轉至0-Cal檔。\n2. 按「確定」");
				else
					MsgFrmt("1. 將量測筒轉至0-Cal檔。\n2. 按「確定」");
				flag++;
			}
 		} while (flag);
		return TRUE;
	}
	else if(m_Online && !m_isTrue)
	{
		//模擬的
		if (m_DebugFlag) DBugModeBox("FALSE of CalZero()");

		m_isZeroCal = TRUE;
		Sleep(1000);
		return TRUE;
	}
	else
	{
		if (m_DebugFlag) DBugModeBox("TRUE of CalZero()");
		return FALSE;
	}
}

BOOL Ca210::LinkMemory()
{
	if (m_isTrue && m_Online)
	{
		if (m_DebugFlag) DBugModeBox("TRUE of LinkMemory()");
		LPDISPATCH pMemory;
		try
		{
			pMemory = m_ICa.GetMemory();
		}
		catch (CException* e)
		{
			MsgFrmt(e, "pMemory = m_ICa.GetMemory();出問題", ImpsbStr);
		}

		try
		{
			m_IMemory.AttachDispatch(pMemory);
		}
		catch (CException* e)
		{
			MsgFrmt(e, "m_IMemory.AttachDispatch(pMemory);出問題", ImpsbStr);
		}
	 	return TRUE;
	} 
	else
	{
		if (m_DebugFlag) DBugModeBox("FALSE of LinkMemory()");
		return FALSE;
	}
}

UINT Ca210::Measure()
{
	/*
	0 沒連線
	1 連線
	2 尚未Zero Cal
	3 檔位不在MEAS
	4 量測正常
	*/
	UINT Mode = m_Online;
	if(m_Online && m_isTrue)
	{
		if (m_DebugFlag) DBugModeBox("TRUE of Measure()");
		int flag = 0;
	
		if (m_isZeroCal)
		{
			do 
			{
				try
				{
					m_ICa.Measure(0);
					if (m_IProbe.GetLv() < 0.01)
						Mode = 3;
					else
						Mode = 4;
					flag = 0;
				}
				catch (CException* e)
				{
					TCHAR buf[255];
					e->GetErrorMessage(buf, 255);

// 					MsgFrmt(e, "量測出問題", "剛剛是不是不正常使用量筒（像是搖它或對著強光源...之類的）\n否則，不要移動量筒按確定重量剛剛的點");
// 					flag++;
					continue;
				}
			} while (flag);
		}
		else
		{
			//MsgFrmt("是否Zero Cal!!!");
			Mode = 2;
		}
	}
	return Mode;
}

BOOL Ca210::SetOnline(BOOL isOnline)
{
	if (m_isTrue)
	{
		if (m_DebugFlag) DBugModeBox("TRUE of SetOnline(BOOL isOnline)");
		try
		{
			m_ICa.SetRemoteMode(isOnline);
		}
		catch (CException* e)
		{
			MsgFrmt(e, "連線/離線出問題", ImpsbStr);
		}
	}
	m_Online = isOnline;
	return isOnline;
}

BOOL Ca210::GetOnline() const
{
	return m_Online;
}

CString Ca210::GetLcmSize()
{
	if (m_Online)
	{
		 if (m_isTrue)
		 {
			 if (m_DebugFlag) DBugModeBox("TRUE of GetLcmSize()");
			 CString str;
			 try
			 {
				 str = m_IMemory.GetChannelID().Left(2);
			 }
			 catch (CException* e)
			 {
				 MsgFrmt(e, "模組尺寸大小設定出問題", ImpsbStr);
				 return "-1";
			 }
			 return str;
		 }
		 else
		 {
			 if (m_DebugFlag) DBugModeBox("TRUE of GetLcmSize()");
			 return (CString)"24";
		 }
	}
	else 
		return (CString)"-1";
}

CString Ca210::GetChData()
{
	CString temp;
	if (m_Online)
	{
		try
		{
			if (m_DebugFlag) DBugModeBox("Unknow of GetLcmSize()");
			temp.Format(m_isTrue ? "%ld - %s", m_IMemory.GetChannelNO(), m_IMemory.GetChannelID() : "XX - 模擬頻道");
		}
		catch (CException* e)
		{
			MsgFrmt(e, "從CA-210抓Channel的資料出來出問題", ImpsbStr);
		}
	}
	else
		temp.Format("已離線 - 無頻道");
	return temp;
}

Bullet Ca210::GetMsrData()
{
	if (m_Online)
	{
		if (m_isTrue)
		{
			if (m_DebugFlag) DBugModeBox("TRUE of GetMsrData()");
			else
			try
			{
				m_blt.SetLv(m_IProbe.GetLv());
				m_blt.SetSx(m_IProbe.GetSx());
				m_blt.SetSy(m_IProbe.GetSy());
				
				m_blt.SetT(m_IProbe.GetT());
				m_blt.SetDuv(m_IProbe.GetDuv());
				
				m_blt.SetDu(m_IProbe.GetUd());
				m_blt.SetDv(m_IProbe.GetVd());
				
				m_blt.SetX(m_IProbe.GetX());
				m_blt.SetY(m_IProbe.GetY());
				m_blt.SetZ(m_IProbe.GetZ());
			}
			catch (CException* e)
			{
				MsgFrmt(e, "從CA-210讀取量測值出問題", ImpsbStr);
			}
		}
		else
		{
			if (m_DebugFlag) DBugModeBox("FALSE of GetMsrData()");

			srand(time(NULL));
			m_blt.SetLv((float)(rand()%100000)/100);    //%3.2f
			m_blt.SetSx((float)(rand()%10000 +1)/(float)10000);  //%1.4f
			m_blt.SetSy((float)(rand()%10000 +1)/(float)10000);  //%1.4f
			
			m_blt.SetT(rand()%1000);//%3d
			m_blt.SetDuv((float)(rand()%100000)/10000);  //%1.4f
			
			m_blt.SetDu((float)(rand()%100000)/10000);  //%1.4f
			m_blt.SetDv((float)(rand()%100000)/10000);  //%1.4f
			
			m_blt.SetX((float)(rand()%100000)/100);  //%3.2f
			m_blt.SetY((float)(rand()%100000)/100);  //%3.2f
			m_blt.SetZ((float)(rand()%100000)/100);  //%3.2f
		}
	}
	return m_blt;
}

CString Ca210::OutData()
{
	CString Lv, SX, SY;
	CString T, Duv;
	CString Du, Dv;
	CString X, Y, Z;

	if (m_Online)
	{
		if (m_DebugFlag) DBugModeBox("TRUE of OutData()");
		else
		try
		{
			Lv.Format("%3.2f", m_blt.GetLv());//Lv
			SX.Format("%1.4f", m_blt.GetSx());//Small x
			SY.Format("%1.4f", m_blt.GetSy());//Small y
			
			T.Format("%3d°", m_blt.GetT());//T
			Duv.Format("%1.4f", m_blt.GetDuv());//duv
			
			Du.Format("%1.4f", m_blt.GetDu());//du
			Dv.Format("%1.4f", m_blt.GetDv());//dv
			
			X.Format("%3.2f", m_blt.GetX());//X
			Y.Format("%3.2f", m_blt.GetY());//Y
			Z.Format("%3.2f", m_blt.GetZ());//Z
		}
		catch (CException* e)
		{
			MsgFrmt(e, "從CA-210讀取量測值出問題", ImpsbStr);
		}
	}	
// 	else if (m_Online && !m_isTrue)
// 	{
// 		if (m_DebugFlag) DBugModeBox("FALSE of OutData()");
// 		srand(time(NULL));
// 		
// 		Lv.Format("%3.2f", (float)(rand()%100000)/100);//Lv
// 		SX.Format("%1.4f", (float)(rand()%10000 +1)/10000);//Small x
// 		SY.Format("%1.4f", (float)(rand()%10000 +1)/10000);//Small y
// 		
// 		T.Format("%3d°" ,         rand()%10000);//T
// 		Duv.Format("%1.4f", (float)(rand()%100000)/10000);//duv
// 		
// 		Du.Format("%1.4f", (float)(rand()%100000)/10000);//du
// 		Dv.Format("%1.4f", (float)(rand()%100000)/10000);//dv
// 		
// 		X.Format("%3.2f", (float)(rand()%100000)/100);//X
// 		Y.Format("%3.2f", (float)(rand()%100000)/100);//Y
// 		Z.Format("%3.2f", (float)(rand()%100000)/100);//Z
// 	}
	else
	{
		Lv.Format("離線了");//Lv
		SX.Format("離線了");//Small x
		SY.Format("離線了");//Small y
		
		T.Format("離線了");//T
		Duv.Format("離線了");//duv
		
		Du.Format("離線了");//du
		Dv.Format("離線了");//dv
		
		X.Format("離線了");//X
		Y.Format("離線了");//Y
		Z.Format("離線了");//Z

	} 
	return " Lv =" + Lv  + "     \n" 
		+ "  x =" +  SX + "     \n" 
		+ "  y =" +  SY + "     \n" 
		+ "  T =" +  T  + "     \n" 
		+ "Δuv=" + Duv + "     \n" 
		+ " u' =" + Du  + "     \n"
		+ " v' =" +  Dv + "     \n"
		+ "  X =" +  X  + "     \n"
		+ "  Y =" +  Y  + "     \n"
		+ "  Z =" +  Z;
}

UINT Ca210::MsrAI(float MsrDeviation)
{
/*
  return 
  0  亮度0，目前0-Cal
  1  標準門檻值內：繼續量測+百分比
  2  標準門檻值外：繼續量測-百分比
  3  未連線
 */
	if (m_Online)
	{
		float XFristValue = 0.0, deltaX = 0.0,
			  YFristValue = 0.0, deltaY = 0.0,
			  ZFristValue = 0.0, deltaZ = 0.0, deltaAll;

		if (m_isTrue)
		{
			if (m_DebugFlag) DBugModeBox("TRUE of MsrAI(float MsrDeviation)");
			//第一筆資料暫存空間  //宣告誤差值計算空間

			Measure();

			if((double)m_IProbe.GetLv() == 0.0)
				return 0;//0 cal 檔位

			//抓參考值
				XFristValue = m_IProbe.GetX();
				YFristValue = m_IProbe.GetY();
				ZFristValue = m_IProbe.GetZ();

			Measure();

			//誤差取絕對值
				deltaX = ((XFristValue-m_IProbe.GetX())>=0) ? XFristValue - m_IProbe.GetX() : m_IProbe.GetX() - XFristValue;
				deltaY = ((YFristValue-m_IProbe.GetY())>=0) ? YFristValue - m_IProbe.GetY() : m_IProbe.GetY() - YFristValue;
				deltaZ = ((ZFristValue-m_IProbe.GetZ())>=0) ? ZFristValue - m_IProbe.GetZ() : m_IProbe.GetZ() - ZFristValue;
		}
		else
		{
			if (m_DebugFlag) DBugModeBox("FALSE of MsrAI(float MsrDeviation)");
			srand(time(NULL));

			 //誤差取絕對值
				deltaX = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
				deltaY = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
				deltaZ = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
		}

		deltaAll = deltaX * deltaY * deltaZ;

		if (deltaAll < MsrDeviation )    return 1;//門檻值內
		else                             return 2;//門檻值外
	}
	else
		return 3; //未連線
}

CString Ca210::GetSetupValue() const
{
	CString str;
	str.Format("連線:%d, 實機:%d, ZeroCal了沒:%d", m_Online, m_isTrue, m_isZeroCal);
	return str;
}

//設定警告標示的標準格式
void Ca210::MsgFrmt(CException* e, CString mean, CString steps)
{
	CString str;
	TCHAR buf[255];
	e->GetErrorMessage(buf, 255);
	
	str.Format("糟糕!!!出現ERROR!!!\n\n原廠錯誤訊息:\n%s\n\n看不懂沒關係，意思就是:\n「%s」\n\n你只要做:\n%s", buf, mean, steps);
	AfxMessageBox(str);
}

void Ca210::MsgFrmt(CString steps)
{
	CString str;
	str.Format("你發呆嗎？\n%s", steps);
	AfxMessageBox(str);
}

void Ca210::DBugModeBox(CString str) const
{
	CString strTemp;
	strTemp.Format("%s\n%s模式, %s", str, m_isTrue?"真實":"模擬", m_Online?"連線":"離線");
	AfxMessageBox(strTemp);
}
