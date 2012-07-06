#include "StdAfx.h"
#include "CA210.h"
#include <cstdlib>
#include <ctime>

Ca210::Ca210(BOOL tr):ImpsbStr("1. ���uPrt Scm��v��U�ثe���ù��A�ö}�p�e�a�K�W�A�t�s������\n2. Mail�����{���]�p�̡A�ԲӴy�z�ϥιL�{�ñN���ɦs������\n�o�O�|���w����X�{�����D�C�]���Ӥ��|�o�ͪ����ءC�^")
{
	/*
	��l��ca-210
	�]�w�O�_��������
	*/
	m_DebugFlag = FALSE;
	m_isTrue = tr;  //TRUE���������, FALSE��������
	if (m_isTrue)
	{
		if (m_DebugFlag) DBugModeBox("TRUE of Ca210(BOOL tr)");
		int flag = 0;
		CString CloseSetp("1. �ˬdUSB�u�M�q��\n2. ���T�w");
		do 
		{
			try
			{
				m_ICa200.CreateDispatch("CA200Srvr.Ca200.1");
			}
			catch (CException* e)
			{
				MsgFrmt(e, "m_ICa200.CreateDispatch(\"CA200Srvr.Ca200.1\");�X���D", CloseSetp);
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
				MsgFrmt(e, "m_ICa200.AutoConnect();�X���D", CloseSetp);
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
				MsgFrmt(e, "LPDISPATCH pICa = m_ICa200.GetSingleCa();�X���D", CloseSetp);
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
				MsgFrmt(e, "LPDISPATCH pIProbe = m_ICa.GetSingleProbe();�X���D", CloseSetp);
				flag++;
				continue;
			}
			
			m_IProbe.AttachDispatch(pIProbe);
		
			//�P�_�O�_Zero Cal
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

			//MsgFrmt(e, "�q���X���D", "���O���O�����`�ϥζq���]���O�n���ι�۱j����...�������^\n�_�h�A���n���ʶq�����T�w���q��誺�I");			
			m_isZeroCal = FALSE;
		}
		SetOnline(FALSE);
	}
	else
	{
		//������
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
	�s�u ���
	caes 11   ����ZeroCal
			    �ҥ~�B�z:
				  ��MessageBox
			      �A����ZeroCal
	case 10   Delay1sec ����ZeroCal���ɶ�
	default   �^��FALSE  �L�k����
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
					MsgFrmt(e,"�N�M���٨S���0-Cal�N����Zero Cal", "1. �N�q�������0-Cal�ɡC\n2. ���u�T�w�v");
				else
					MsgFrmt("1. �N�q�������0-Cal�ɡC\n2. ���u�T�w�v");
				flag++;
			}
 		} while (flag);
		return TRUE;
	}
	else if(m_Online && !m_isTrue)
	{
		//������
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
			MsgFrmt(e, "pMemory = m_ICa.GetMemory();�X���D", ImpsbStr);
		}

		try
		{
			m_IMemory.AttachDispatch(pMemory);
		}
		catch (CException* e)
		{
			MsgFrmt(e, "m_IMemory.AttachDispatch(pMemory);�X���D", ImpsbStr);
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
	0 �S�s�u
	1 �s�u
	2 �|��Zero Cal
	3 �ɦ줣�bMEAS
	4 �q�����`
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

// 					MsgFrmt(e, "�q���X���D", "���O���O�����`�ϥζq���]���O�n���ι�۱j����...�������^\n�_�h�A���n���ʶq�����T�w���q��誺�I");
// 					flag++;
					continue;
				}
			} while (flag);
		}
		else
		{
			//MsgFrmt("�O�_Zero Cal!!!");
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
			MsgFrmt(e, "�s�u/���u�X���D", ImpsbStr);
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
				 MsgFrmt(e, "�Ҳդؤo�j�p�]�w�X���D", ImpsbStr);
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
			temp.Format(m_isTrue ? "%ld - %s", m_IMemory.GetChannelNO(), m_IMemory.GetChannelID() : "XX - �����W�D");
		}
		catch (CException* e)
		{
			MsgFrmt(e, "�qCA-210��Channel����ƥX�ӥX���D", ImpsbStr);
		}
	}
	else
		temp.Format("�w���u - �L�W�D");
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
				MsgFrmt(e, "�qCA-210Ū���q���ȥX���D", ImpsbStr);
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
			
			T.Format("%3d�X", m_blt.GetT());//T
			Duv.Format("%1.4f", m_blt.GetDuv());//duv
			
			Du.Format("%1.4f", m_blt.GetDu());//du
			Dv.Format("%1.4f", m_blt.GetDv());//dv
			
			X.Format("%3.2f", m_blt.GetX());//X
			Y.Format("%3.2f", m_blt.GetY());//Y
			Z.Format("%3.2f", m_blt.GetZ());//Z
		}
		catch (CException* e)
		{
			MsgFrmt(e, "�qCA-210Ū���q���ȥX���D", ImpsbStr);
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
// 		T.Format("%3d�X" ,         rand()%10000);//T
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
		Lv.Format("���u�F");//Lv
		SX.Format("���u�F");//Small x
		SY.Format("���u�F");//Small y
		
		T.Format("���u�F");//T
		Duv.Format("���u�F");//duv
		
		Du.Format("���u�F");//du
		Dv.Format("���u�F");//dv
		
		X.Format("���u�F");//X
		Y.Format("���u�F");//Y
		Z.Format("���u�F");//Z

	} 
	return " Lv =" + Lv  + "     \n" 
		+ "  x =" +  SX + "     \n" 
		+ "  y =" +  SY + "     \n" 
		+ "  T =" +  T  + "     \n" 
		+ "�Guv=" + Duv + "     \n" 
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
  0  �G��0�A�ثe0-Cal
  1  �зǪ��e�Ȥ��G�~��q��+�ʤ���
  2  �зǪ��e�ȥ~�G�~��q��-�ʤ���
  3  ���s�u
 */
	if (m_Online)
	{
		float XFristValue = 0.0, deltaX = 0.0,
			  YFristValue = 0.0, deltaY = 0.0,
			  ZFristValue = 0.0, deltaZ = 0.0, deltaAll;

		if (m_isTrue)
		{
			if (m_DebugFlag) DBugModeBox("TRUE of MsrAI(float MsrDeviation)");
			//�Ĥ@����ƼȦs�Ŷ�  //�ŧi�~�t�ȭp��Ŷ�

			Measure();

			if((double)m_IProbe.GetLv() == 0.0)
				return 0;//0 cal �ɦ�

			//��Ѧҭ�
				XFristValue = m_IProbe.GetX();
				YFristValue = m_IProbe.GetY();
				ZFristValue = m_IProbe.GetZ();

			Measure();

			//�~�t�������
				deltaX = ((XFristValue-m_IProbe.GetX())>=0) ? XFristValue - m_IProbe.GetX() : m_IProbe.GetX() - XFristValue;
				deltaY = ((YFristValue-m_IProbe.GetY())>=0) ? YFristValue - m_IProbe.GetY() : m_IProbe.GetY() - YFristValue;
				deltaZ = ((ZFristValue-m_IProbe.GetZ())>=0) ? ZFristValue - m_IProbe.GetZ() : m_IProbe.GetZ() - ZFristValue;
		}
		else
		{
			if (m_DebugFlag) DBugModeBox("FALSE of MsrAI(float MsrDeviation)");
			srand(time(NULL));

			 //�~�t�������
				deltaX = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
				deltaY = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
				deltaZ = (float)(rand()%100000)/100 - (float)(rand()%100000)/100;
		}

		deltaAll = deltaX * deltaY * deltaZ;

		if (deltaAll < MsrDeviation )    return 1;//���e�Ȥ�
		else                             return 2;//���e�ȥ~
	}
	else
		return 3; //���s�u
}

CString Ca210::GetSetupValue() const
{
	CString str;
	str.Format("�s�u:%d, ���:%d, ZeroCal�F�S:%d", m_Online, m_isTrue, m_isZeroCal);
	return str;
}

//�]�wĵ�i�Хܪ��зǮ榡
void Ca210::MsgFrmt(CException* e, CString mean, CString steps)
{
	CString str;
	TCHAR buf[255];
	e->GetErrorMessage(buf, 255);
	
	str.Format("�V�|!!!�X�{ERROR!!!\n\n��t���~�T��:\n%s\n\n�ݤ����S���Y�A�N��N�O:\n�u%s�v\n\n�A�u�n��:\n%s", buf, mean, steps);
	AfxMessageBox(str);
}

void Ca210::MsgFrmt(CString steps)
{
	CString str;
	str.Format("�A�o�b�ܡH\n%s", steps);
	AfxMessageBox(str);
}

void Ca210::DBugModeBox(CString str) const
{
	CString strTemp;
	strTemp.Format("%s\n%s�Ҧ�, %s", str, m_isTrue?"�u��":"����", m_Online?"�s�u":"���u");
	AfxMessageBox(strTemp);
}
