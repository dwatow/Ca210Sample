// CaEvent.cpp : implementation file
//

#include "stdafx.h"
#include "Ca200Sample.h"
#include "CaEvent.h"
#include "Ca200SampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCaEvent

IMPLEMENT_DYNCREATE(CCaEvent, CCmdTarget)

CCaEvent::CCaEvent()
{
	EnableAutomation();
}

CCaEvent::~CCaEvent()
{
}


void CCaEvent::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CCaEvent, CCmdTarget)
	//{{AFX_MSG_MAP(CCaEvent)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CCaEvent, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CCaEvent)
	DISP_FUNCTION(CCaEvent, "ExeCalZero", ExeCalZero, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ICaEvent to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

//CA-SDK
/*
//原本的
// {0E058377-850A-4490-9A69-87B9EE9B4BBB}
static const IID IID_ICaEvent =
{ 0xe058377, 0x850a, 0x4490, { 0x9a, 0x69, 0x87, 0xb9, 0xee, 0x9b, 0x4b, 0xbb } };
*/
//改上去的
// {f7663750-5900-45eb-905f-78c5d5378481}
const IID IID_ICaEvent =
{ 0xf7663750, 0x5900, 0x45eb, { 0x90, 0x5f, 0x78, 0xc5, 0xd5, 0x37, 0x84, 0x81 } };

//END CA-SDK

BEGIN_INTERFACE_MAP(CCaEvent, CCmdTarget)
	INTERFACE_PART(CCaEvent, IID_ICaEvent, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCaEvent message handlers

void CCaEvent::ExeCalZero() 
{
	// TODO: Add your dispatch handler code here
	// CA-SDK
    //增加CCaEvent::ExeCaZero()的動態處理程式如下
    //在Sample軟體當動作發生，量測按鈕就不可以使用了。
	
	CWinApp* papp = AfxGetApp();
	CCa200SampleDlg* pdlg = reinterpret_cast<CCa200SampleDlg *>(papp -> m_pMainWnd);
	CButton* pb;
	pb = (CButton *)(pdlg ->GetDlgItem(IDC_BUTTON_MSR));
	pb->EnableWindow(FALSE);
}
