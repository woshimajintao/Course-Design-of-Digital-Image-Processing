// HistDemoA.h : main header file for the HISTDEMOA application
//

#if !defined(AFX_HISTDEMOA_H__DAE68CD2_F410_4671_8676_C02D0BD514B6__INCLUDED_)
#define AFX_HISTDEMOA_H__DAE68CD2_F410_4671_8676_C02D0BD514B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHistDemoAApp:
// See HistDemoA.cpp for the implementation of this class
//

class CHistDemoAApp : public CWinApp
{
public:
	CHistDemoAApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistDemoAApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHistDemoAApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTDEMOA_H__DAE68CD2_F410_4671_8676_C02D0BD514B6__INCLUDED_)
