// ImageWnd.cpp: implementation of the CImageWnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HistDemoA.h"
#include "ImageWnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CImageWnd::CImageWnd()
{
HScrollPosition=0;
HCurrentPosition=0;
HScrollMax=0;
VScrollPosition=0;
VCurrentPosition=0;
VScrollMax=0;
lpBits=0;
}

CImageWnd::~CImageWnd()
{
if (lpBits) delete lpBits;
}

BEGIN_MESSAGE_MAP(CImageWnd, CWnd)
//{{AFX_MSG_MAP(CImageWnd)
ON_WM_ERASEBKGND()
ON_WM_HSCROLL()
ON_WM_VSCROLL()
ON_WM_PAINT()
ON_WM_CREATE()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CImageWnd::SetImage(int cx, int cy, const void *bits)
{
nWidth=cx;
nHeight=cy;
nByteWidth=nWidth*3;
if (nByteWidth%4) nByteWidth+=4-(nByteWidth%4);
if (lpBits) delete lpBits;
lpBits=new BYTE[nByteWidth*nHeight];
memcpy(lpBits,bits,nByteWidth*nHeight);
if (cx>320 || cy>240) SetScroll(cx,cy);
else SetScroll(0,0);
Invalidate();
}

void CImageWnd::SetScroll(int cx, int cy)
{
HScrollPosition=0;
HCurrentPosition=0;
VScrollPosition=0;
VCurrentPosition=0;
SetScrollPos(SB_HORZ,0);
SetScrollPos(SB_VERT,0);
SCROLLINFO sinfo;
sinfo.cbSize=sizeof(SCROLLINFO);
sinfo.fMask=SIF_PAGE|SIF_RANGE;
sinfo.nMin=0;
//HScroll
sinfo.nMax=cx-1;
sinfo.nPage=302;
SetScrollInfo(SB_HORZ,&sinfo);
HScrollMax=cx-302;
//VScroll
sinfo.nMax=cy-1;
sinfo.nPage=222;
SetScrollInfo(SB_VERT,&sinfo);
VScrollMax=cy-222;
}

#define BACKGROUND RGB(128,128,128)
BOOL CImageWnd::OnEraseBkgnd(CDC* pDC)
{
if (!lpBits) pDC->FillSolidRect(0,0,320,240,BACKGROUND);
return TRUE;
}
void CImageWnd::OnPaint()
{
CPaintDC dc(this); // device context for painting
if (lpBits)
{
int x,y;
x=-HScrollPosition;
y=-VScrollPosition;
if (nWidth<320) x=(320-nWidth)/2;
if (nHeight<240) y=(240-nHeight)/2;
BITMAPINFOHEADER bmi;
bmi.biSize=sizeof(BITMAPINFOHEADER);
bmi.biWidth=nWidth;
bmi.biHeight=nHeight;
bmi.biPlanes=1;
bmi.biBitCount=24;
bmi.biCompression=BI_RGB;
bmi.biSizeImage=0;
bmi.biXPelsPerMeter=0;
bmi.biYPelsPerMeter=0;
bmi.biClrUsed=0;
bmi.biClrImportant=0;
StretchDIBits(dc.m_hDC,x,y,nWidth,nHeight,0,0,nWidth,nHeight,
lpBits,
(BITMAPINFO *)&bmi,
DIB_RGB_COLORS,
SRCCOPY);
}
}

void CImageWnd::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
switch(nSBCode)
{
case SB_LINEDOWN:
HScrollPosition+=5;
break;
case SB_LINEUP:
HScrollPosition-=5;
break;
case SB_PAGEDOWN:
HScrollPosition+=302;
break;
case SB_PAGEUP:
HScrollPosition-=302;
break;
case SB_THUMBPOSITION:
case SB_THUMBTRACK:
HScrollPosition=nPos;
break;
}
if (HScrollPosition<0) HScrollPosition=0;
if (HScrollPosition>HScrollMax) HScrollPosition=HScrollMax;
SetScrollPos(SB_HORZ,HScrollPosition);
if (HCurrentPosition!=HScrollPosition)
{
ScrollWindow((HCurrentPosition-HScrollPosition),0);
HCurrentPosition=HScrollPosition;
}
CWnd::OnHScroll(nSBCode, nPos, pScrollBar);
}
void CImageWnd::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
switch(nSBCode)
{
case SB_LINEDOWN:
VScrollPosition+=5;
break;
case SB_LINEUP:
VScrollPosition-=5;
break;
case SB_PAGEDOWN:
VScrollPosition+=222;
break;
case SB_PAGEUP:
VScrollPosition-=222;
break;
case SB_THUMBPOSITION:
case SB_THUMBTRACK:
VScrollPosition=nPos;
break;
}
if (VScrollPosition<0) VScrollPosition=0;
if (VScrollPosition>VScrollMax) VScrollPosition=VScrollMax;
SetScrollPos(SB_VERT,VScrollPosition);
if (VCurrentPosition!=VScrollPosition)
{
ScrollWindow(0,(VCurrentPosition-VScrollPosition));
VCurrentPosition=VScrollPosition;
}
CWnd::OnVScroll(nSBCode, nPos, pScrollBar);
}
int CImageWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
if (CWnd::OnCreate(lpCreateStruct) == -1)
return -1;

return 0;
}
