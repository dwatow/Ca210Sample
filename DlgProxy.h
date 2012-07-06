// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__4DE07E26_5B9E_49FD_A9CD_A3C57FC5FD82__INCLUDED_)
#define AFX_DLGPROXY_H__4DE07E26_5B9E_49FD_A9CD_A3C57FC5FD82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCa200SampleDlg;

/////////////////////////////////////////////////////////////////////////////
// CCa200SampleDlgAutoProxy command target

class CCa200SampleDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CCa200SampleDlgAutoProxy)

	CCa200SampleDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CCa200SampleDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCa200SampleDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCa200SampleDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CCa200SampleDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CCa200SampleDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CCa200SampleDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__4DE07E26_5B9E_49FD_A9CD_A3C57FC5FD82__INCLUDED_)
