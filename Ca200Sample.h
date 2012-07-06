// Ca200Sample.h : main header file for the CA200SAMPLE application
//

#if !defined(AFX_CA200SAMPLE_H__B77E6ED4_5CAE_4ADD_8D60_0384C1E52348__INCLUDED_)
#define AFX_CA200SAMPLE_H__B77E6ED4_5CAE_4ADD_8D60_0384C1E52348__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCa200SampleApp:
// See Ca200Sample.cpp for the implementation of this class
//

class CCa200SampleApp : public CWinApp
{
public:
	CCa200SampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCa200SampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCa200SampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CA200SAMPLE_H__B77E6ED4_5CAE_4ADD_8D60_0384C1E52348__INCLUDED_)
