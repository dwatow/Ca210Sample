#if !defined(AFX_CAEVENT_H__8535B37F_88B8_45A9_A01A_0A62304A2AAB__INCLUDED_)
#define AFX_CAEVENT_H__8535B37F_88B8_45A9_A01A_0A62304A2AAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CaEvent.h : header file
//

//CA-SDK
extern const IID IID_ICaEvent;

/////////////////////////////////////////////////////////////////////////////
// CCaEvent command target

class CCaEvent : public CCmdTarget
{
	DECLARE_DYNCREATE(CCaEvent)

//CA-SDK
//	CCaEvent();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
//CA-SDK
    CCaEvent();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaEvent)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCaEvent();

	// Generated message map functions
	//{{AFX_MSG(CCaEvent)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CCaEvent)
	afx_msg void ExeCalZero();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAEVENT_H__8535B37F_88B8_45A9_A01A_0A62304A2AAB__INCLUDED_)
