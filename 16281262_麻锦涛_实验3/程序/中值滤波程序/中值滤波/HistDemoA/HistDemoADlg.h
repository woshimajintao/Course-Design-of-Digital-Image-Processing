// HistDemoADlg.h : header file
//

#if !defined(AFX_HISTDEMOADLG_H__350C6DAB_6DAF_4BBC_A0E5_D8365A13C70C__INCLUDED_)
#define AFX_HISTDEMOADLG_H__350C6DAB_6DAF_4BBC_A0E5_D8365A13C70C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHistDemoADlg dialog

#include "ImageWnd.h"

class CHistDemoADlg : public CDialog
{
// Construction
public:
	void NoColor();
	void HistogramEq1(int nWidth,int nHeight,BYTE *lpInput,BYTE *lpOutput);
	void HistogramEq();
	void LoadBitmap ( );
	CHistDemoADlg(CWnd* pParent = NULL);	// standard constructor

int nWidth;
int nHeight;
int nLen;
int nByteWidth;
BYTE *lpBackup;
BYTE *lpBitmap;
BYTE *lpBits;
CString FileName;
CImageWnd source,dest;

// Dialog Data
	//{{AFX_DATA(CHistDemoADlg)
	enum { IDD = IDD_HISTDEMOA_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistDemoADlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHistDemoADlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	afx_msg void OnHist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTDEMOADLG_H__350C6DAB_6DAF_4BBC_A0E5_D8365A13C70C__INCLUDED_)
