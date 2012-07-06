// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "Ca200Sample.h"
#include "DlgProxy.h"
#include "Ca200SampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCa200SampleDlgAutoProxy

IMPLEMENT_DYNCREATE(CCa200SampleDlgAutoProxy, CCmdTarget)

CCa200SampleDlgAutoProxy::CCa200SampleDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CCa200SampleDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CCa200SampleDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CCa200SampleDlgAutoProxy::~CCa200SampleDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CCa200SampleDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CCa200SampleDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CCa200SampleDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CCa200SampleDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CCa200SampleDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ICa200Sample to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {62E8CDC5-8F2A-4374-A788-627B4E0D4721}
static const IID IID_ICa200Sample =
{ 0x62e8cdc5, 0x8f2a, 0x4374, { 0xa7, 0x88, 0x62, 0x7b, 0x4e, 0xd, 0x47, 0x21 } };

BEGIN_INTERFACE_MAP(CCa200SampleDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CCa200SampleDlgAutoProxy, IID_ICa200Sample, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {E440C772-86A9-4D98-B2DE-C54ADD2FC821}
IMPLEMENT_OLECREATE2(CCa200SampleDlgAutoProxy, "Ca200Sample.Application", 0xe440c772, 0x86a9, 0x4d98, 0xb2, 0xde, 0xc5, 0x4a, 0xdd, 0x2f, 0xc8, 0x21)

/////////////////////////////////////////////////////////////////////////////
// CCa200SampleDlgAutoProxy message handlers
