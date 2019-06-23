// ImageWnd.h: interface for the CImageWnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEWND_H__0D884C8A_2DB6_4D3C_B5F5_404EC87E6399__INCLUDED_)
#define AFX_IMAGEWND_H__0D884C8A_2DB6_4D3C_B5F5_404EC87E6399__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CImageWnd:public CWnd  
{
public:
	void SetScroll(int cx,int cy);
	void SetImage(int cx,int cy,const void *bits);
	BYTE *lpBits;
	int nByteWidth;
	int nHeight;
	int nWidth;
	int VScrollPosition;
	int VScrollMax;
	int VCurrentPosition;
	int HScrollPosition;
	int HScrollMax;
	int HCurrentPosition;
	CImageWnd();
	virtual ~CImageWnd();
protected:
//{{AFX_MSG(CImageWnd)
afx_msg BOOL OnEraseBkgnd(CDC* pDC);
afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
afx_msg void OnPaint();
afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//}}AFX_MSG
DECLARE_MESSAGE_MAP()
#endif // !defined(AFX_IMAGEWND_H__0D884C8A_2DB6_4D3C_B5F5_404EC87E6399__INCLUDED_)

};

