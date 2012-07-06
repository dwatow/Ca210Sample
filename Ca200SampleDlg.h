// Ca200SampleDlg.h : header file
//

#if !defined(AFX_CA200SAMPLEDLG_H__60424BCC_866E_4A04_83A0_FDB413B29EA7__INCLUDED_)
#define AFX_CA200SAMPLEDLG_H__60424BCC_866E_4A04_83A0_FDB413B29EA7__INCLUDED_


//CA-SDK
#import "C:\Program Files\CA-SDK\SDK\CA200Srvr.dll" no_namespace no_implementation

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCa200SampleDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CCa200SampleDlg dialog

class CCa200SampleDlg : public CDialog
{
	DECLARE_DYNAMIC(CCa200SampleDlg);
	friend class CCa200SampleDlgAutoProxy;

// Construction
public:
	DWORD               m_dwCk;
	IDispatch*          m_pIDispatch;
	IConnectionPointPtr m_pIConnectionPointObj;

	IOutputProbesPtr    m_pOutputProbesObj;
	IProbesPtr          m_pProbesObj;
	ICasPtr             m_pCasObj;
	IMemoryPtr          m_pMemoryObj;
	IProbePtr           m_pProbeObj;
	ICaPtr              m_pCaObj;
	ICa200Ptr           m_pCa200Obj;
	CCa200SampleDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CCa200SampleDlg();

// Dialog Data
	//{{AFX_DATA(CCa200SampleDlg)
	enum { IDD = IDD_CA200SAMPLE_DIALOG };
	CString	m_strLv;
	CString	m_strduv;
	CString	m_strT;
	CString	m_strx;
	CString	m_stry;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCa200SampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CCa200SampleDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CCa200SampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonMsr();
	afx_msg void OnButtonCal0();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CA200SAMPLEDLG_H__60424BCC_866E_4A04_83A0_FDB413B29EA7__INCLUDED_)
