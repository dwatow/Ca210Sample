// Ca200SampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ca200Sample.h"
#include "Ca200SampleDlg.h"
#include "DlgProxy.h"
#include "CaEvent.h"
#include "Const.h"

//CA-SDK
#import "C:\Program Files\CA-SDK\SDK\CA200Srvr.dll" no_namespace implementation_only

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCa200SampleDlg dialog

IMPLEMENT_DYNAMIC(CCa200SampleDlg, CDialog);

CCa200SampleDlg::CCa200SampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCa200SampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCa200SampleDlg)
	m_strLv = _T("");
	m_strduv = _T("");
	m_strT = _T("");
	m_strx = _T("");
	m_stry = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CCa200SampleDlg::~CCa200SampleDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CCa200SampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCa200SampleDlg)
	DDX_Text(pDX, IDC_STATIC_LV, m_strLv);
	DDX_Text(pDX, IDC_STATIC_DUV, m_strduv);
	DDX_Text(pDX, IDC_STATIC_T, m_strT);
	DDX_Text(pDX, IDC_STATIC_X, m_strx);
	DDX_Text(pDX, IDC_STATIC_Y, m_stry);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCa200SampleDlg, CDialog)
	//{{AFX_MSG_MAP(CCa200SampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_MSR, OnButtonMsr)
	ON_BN_CLICKED(IDC_BUTTON_CAL0, OnButtonCal0)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCa200SampleDlg message handlers

BOOL CCa200SampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
 
	
   
	//CA-SDK
    long lcan = 1;              //CA儀器CA號碼=1
	_bstr_t strcnfig(_T("1"));  //探測器：連結1組，號碼=1
    long lprt = PORT_USB;       //lprt   USB連結
    long lbr  = 38400;
    _bstr_t strprbid(_T("P1"));
    _variant_t vprbid(_T("P1"));

    try
	{
        m_pCa200Obj = ICa200Ptr(__uuidof(Ca200));//1.建立Ca200物件（1）
        m_pCa200Obj->SetConfiguration(lcan, strcnfig, lprt, lbr);
		//2.使用SetConfiguration() method,設定程式使用一台CA儀器如（2）
		//括號設定的，如上述宣告的部份
    }
    catch(_com_error e)
	{
        CString strerr;
		strerr.Format(_T("HR:0x%08x\nMSG:%s"), e.Error(), (LPCSTR)e.Description());
        AfxMessageBox((LPCSTR)strerr);
		return TRUE;
    }
//3.用CA-SDK物件的方式  設定物件來控制CA儀器（儀控）

    m_pCasObj               = m_pCa200Obj  ->  Cas;                 //從Ca200物件，取得Cas集合。
    m_pCaObj                = m_pCasObj    ->  ItemOfNumber[lcan];  //從Cas物件中取得Ca物件。
    m_pOutputProbesObj      = m_pCaObj     ->  OutputProbes;        //從Ca物件取得Outprobes集合。
    m_pOutputProbesObj ->  RemoveAll();                             //Reset OutProbes 集合。
    m_pOutputProbesObj ->  Add(strprbid);                           //增加探測器 #1 OutProbes 集合並且設定它如同輸出探測器。
    m_pProbeObj             = m_pOutputProbesObj ->Item[vprbid];    //從OutputProbes集合，取得 Probe物件。
    m_pMemoryObj            = m_pCaObj->Memory;                     //從Ca物件取得Memory物件。

//4.使用various物件表現下列CA儀器初始化和記憶Channel設定：
    m_pCaObj->SyncMode      = SYNC_UNIV;  //設定NTSC同步模式
    m_pCaObj->AveragingMode = AVRG_FAST;  //設定FAST/SLOW模式到FAST
    m_pCaObj->SetAnalogRange(2.5, 2.5);   //設定類比顯示範圍2.5%,2.5%
    m_pCaObj->DisplayMode   = DSP_LXY;    //設定輸出顯示為Lvxy
    m_pCaObj->DisplayDigits = DIGT_4;     //設定顯示數位數字為4
    m_pMemoryObj->ChannelNO = 61;          //設定記憶Channel到0（原廠校準）

	// END CA-SDK

	//CA-SDK about Sink Object
	//1.建立sink物件（沒有標示）
	m_dwCk = 0;
	CCaEvent* pevntobj;
	if (NULL != (pevntobj = new CCaEvent)){ //{bmc circle1.bmp}

		m_pIDispatch = pevntobj ->GetIDispatch(FALSE);//2.獲得sink介面的物件
		
		IConnectionPointContainerPtr pcpcobj;
		DWORD dwck;
		
		pcpcobj = m_pCaObj;//3.
		pcpcobj -> FindConnectionPoint(IID_ICaEvent, &m_pIConnectionPointObj);//4.找sink介面的物件（IConnectionPoint interface connection point）
		m_pIConnectionPointObj ->Advise(m_pIDispatch, &dwck);//5.增加物件的連結
		m_dwCk = dwck;//6.儲存最新連線的ID
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCa200SampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCa200SampleDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCa200SampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CCa200SampleDlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}

void CCa200SampleDlg::OnOK() 
{
	if (CanExit())
	//	CDialog::OnOK();
	//CA-SDK
	{
		if (m_dwCk != 0)
			m_pIConnectionPointObj ->  Unadvise(m_dwCk);//1.CA-SDK的終端連線
		    m_pIDispatch           ->  Release();       //2.在Sample軟體的sink物件執行Release()。當它準備好，sink物件會使自己失效。
                                                        //  靠sample軟體的處理CA-SDK物件hold住smart指標，必須靠著自動化自我失效
		    m_pCaObj               ->  RemoteMode = 0;  //3.設定Ca物件的RemoteMode屬性到OFF並且取消CA儀器的遠端模式
		CDialog::OnOK();
	}
}

void CCa200SampleDlg::OnCancel() 
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CCa200SampleDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CCa200SampleDlg::OnButtonMsr() 
{
	// TODO: Add your control notification handler code here
	
	//量測的部份
	// CA-SDK
	int i;
	float fLv;
	float fx;
	float fy;
	long  lT;
	float fduv;
	
	for (i = 0; i < 10; i++)
	{
		m_pCaObj->Measure(0);//1.Ca物件的Measure法被呼叫，並且準備好量測

		fLv  = m_pProbeObj ->Lv;//2.Probe物件原型和顯示量測結果的DDX成員相關設定 得到的量測結果和最後反映都在控制。
		fx   = m_pProbeObj ->sx;
		fy   = m_pProbeObj ->sy;
		lT   = m_pProbeObj ->T;
		fduv = m_pProbeObj ->duv;

		m_strLv.Format ("%4.2f",fLv);
		m_strx.Format  ("%1.4f",fx);
		m_stry.Format  ("%1.4f",fy);
		m_strT.Format  ("%4d"  ,lT);
		m_strduv.Format("%1.4f",fduv);

		UpdateData(FALSE);
	}	
	// END CA-SDK
}

void CCa200SampleDlg::OnButtonCal0() 
{
	// TODO: Add your control notification handler code here
	
	//0-Cal的部份
	// CA-SDK
	try
	{
		m_pCaObj->CalZero();//1.Ca物件的CalZero method被呼叫，且執行0-Cal
	}
	catch(_com_error e)
	{
		CString strerr;
		strerr.Format(_T("HR:0x%08x\nMSG:%s"), e.Error(), (LPCSTR)e.Description());
		AfxMessageBox((LPCSTR)strerr);
		return;
	}
	CButton* pb;
	pb = (CButton *)GetDlgItem(IDC_BUTTON_MSR);
	pb->EnableWindow(TRUE);
	// END CA-SDK
}
