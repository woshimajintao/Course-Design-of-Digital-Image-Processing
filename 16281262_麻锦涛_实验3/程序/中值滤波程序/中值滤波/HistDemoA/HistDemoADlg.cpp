// HistDemoADlg.cpp : implementation file
//

#include "stdafx.h"
#include "HistDemoA.h"
#include "HistDemoADlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#define Point(x,y) lpPoints[(x)+(y)*nWidth]
#define Point1(x,y) lpPoints1[(x)+(y)*nWidth]
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistDemoADlg dialog

CHistDemoADlg::CHistDemoADlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHistDemoADlg::IDD, pParent)
{
	lpBitmap=0;
	lpBackup=0;
	//{{AFX_DATA_INIT(CHistDemoADlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void GetPoints(int nWidth,int nHeight,BYTE *lpBits,BYTE *lpPoints)
{
int x,y,p;
int nByteWidth=nWidth*3;
if (nByteWidth%4) nByteWidth+=4-(nByteWidth%4);
for(y=0;y<nHeight;y++)
{
for(x=0;x<nWidth;x++)
{
p=x*3+y*nByteWidth;
lpPoints[x+y*nWidth]=(BYTE)(0.299*(float)lpBits[p+2]+0.587*(float)lpBits[p+1]+0.114*(float)lpBits[p]+0.1);
}
}
}
void PutPoints(int nWidth,int nHeight,BYTE *lpBits,BYTE *lpPoints)
{
int nByteWidth=nWidth*3;
if (nByteWidth%4) nByteWidth+=4-(nByteWidth%4);
int x,y,p,p1;
for(y=0;y<nHeight;y++)
{
for(x=0;x<nWidth;x++)
{
p=x*3+y*nByteWidth;
p1=x+y*nWidth;
lpBits[p]=lpPoints[p1];
lpBits[p+1]=lpPoints[p1];
lpBits[p+2]=lpPoints[p1];
}
}
}

void CHistDemoADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistDemoADlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHistDemoADlg, CDialog)
	//{{AFX_MSG_MAP(CHistDemoADlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_BN_CLICKED(IDC_Hist, OnHist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistDemoADlg message handlers

BOOL CHistDemoADlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	source.Create(0,"Source",WS_CHILD|WS_VISIBLE,CRect(40,40,360,280), this, 10000);
    dest.Create(0,"Destination",WS_CHILD|WS_VISIBLE,CRect(400,40,720,280), this, 10001);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHistDemoADlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHistDemoADlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHistDemoADlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CHistDemoADlg::LoadBitmap()
{
BITMAPINFOHEADER *pInfo;
pInfo=(BITMAPINFOHEADER *)(lpBitmap+sizeof(BITMAPFILEHEADER));
nWidth=pInfo->biWidth;
nByteWidth=nWidth*3;
if (nByteWidth%4) nByteWidth+=4-(nByteWidth%4);
nHeight=pInfo->biHeight;
if (pInfo->biBitCount!=24)
{
if (pInfo->biBitCount!=8)
{
AfxMessageBox("无效位图");
delete lpBitmap;
lpBitmap=0;
return;
}
unsigned int PaletteSize=1<<pInfo->biBitCount;
if (pInfo->biClrUsed!=0 && pInfo->biClrUsed<PaletteSize) PaletteSize=pInfo->biClrUsed;
lpBits=lpBitmap+sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
RGBQUAD *pPalette=(RGBQUAD *)lpBits;
lpBits+=sizeof(RGBQUAD)*PaletteSize;
nLen=sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+nByteWidth*nHeight;
BYTE *lpTemp=lpBitmap;
lpBitmap=new BYTE[nLen];
BITMAPFILEHEADER bmh;
BITMAPINFOHEADER bmi;
bmh.bfType='B'+'M'*256;
bmh.bfSize=nLen;
bmh.bfReserved1=0;
bmh.bfReserved2=0;
bmh.bfOffBits=54;
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
int nBWidth=pInfo->biWidth;
if (nBWidth%4) nBWidth+=4-(nBWidth%4);
memset(lpBitmap,0,nLen);
memcpy(lpBitmap,&bmh,sizeof(BITMAPFILEHEADER));
memcpy(lpBitmap+sizeof(BITMAPFILEHEADER),&bmi,sizeof(BITMAPINFOHEADER));
BYTE *lpBits2=lpBitmap+sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
int x,y,p1,p2,Palette;
for(y=0;y<nHeight;y++)
{
for(x=0;x<nWidth;x++)
{
p1=y*nBWidth+x;
p2=y*nByteWidth+x*3;
if (lpBits[p1]<PaletteSize) Palette=lpBits[p1];
else Palette=0;
lpBits2[p2]=pPalette[Palette].rgbBlue;
lpBits2[p2+1]=pPalette[Palette].rgbGreen;
lpBits2[p2+2]=pPalette[Palette].rgbRed;
}
}
delete lpTemp;
}
lpBits=lpBitmap+sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
if (lpBackup) delete lpBackup;
lpBackup=new BYTE[nLen];
memcpy(lpBackup,lpBitmap,nLen);
}

void CHistDemoADlg::OnOpen() 
{
	// TODO: Add your control notification handler code here
CFile File=0;
CFileDialog dlg(TRUE,0,0,OFN_HIDEREADONLY,"位图文件|*.bmp|所有文件|*.*||",this);
if (dlg.DoModal()==IDOK)
{
FileName=dlg.GetPathName();
if (!File.Open(FileName,CFile::modeRead)) return;
// TODO: add loading code here
if (lpBitmap) delete lpBitmap;
nLen=File.GetLength();
lpBitmap=new BYTE[nLen];
File.Read(lpBitmap,nLen);
LoadBitmap();
if (lpBitmap) source.SetImage(nWidth,nHeight,lpBits);
}
}

void CHistDemoADlg::OnHist() 
{
	// TODO: Add your control notification handler code here
    HistogramEq();
}

void CHistDemoADlg::HistogramEq()
{
if (lpBitmap==0) return;
BYTE *lpOutput=new BYTE[nByteWidth*nHeight];
HistogramEq1(nWidth,nHeight,lpBits,lpOutput);
dest.SetImage(nWidth,nHeight,lpOutput);
delete lpOutput;
NoColor();
}

void sort(int a[],int n)//冒泡排序 
{
	int i,j,t;
	for(i=0;i<n-1;i++)//共需要n-1趟 
		for(j=0;j<n-1-i;j++)//每一趟需要n-i次两两比较 
		{
			if(a[j]<a[j+1]){   //比大到小 
				t=a[j];a[j]=a[j+1];a[j+1]=t;
			}
		}
}

void CHistDemoADlg::HistogramEq1(int nWidth, int nHeight, BYTE *lpInput, BYTE *lpOutput)
{
int x,y,m,n;
int p = 0;
int a[5];
BYTE *lpPoints=new BYTE[nWidth*nHeight];
GetPoints(nWidth,nHeight,lpInput,lpPoints);
int u[256*256];
for(m=0;m<nHeight-2;m++){
       y=m;
for(n=0;n<nWidth-2;n++){
       x=n;
	   a[0] = Point(x+1,y);
	   a[1] = Point(x,y+1);
	   a[2] = Point(x+1,y+1);
	   a[3] = Point(x+2,y+1);
	   a[4] = Point(x+1,y+2);
	   sort(a,5);
	   u[p] = a[2];
	   p++;
}
}

p=0;

for(m=1;m<nHeight-1;m++){
       y=m;
for(n=1;n<nWidth-1;n++){
       x=n;
       Point(x,y) = u[p];
	   p++;
}
}
PutPoints(nWidth,nHeight,lpOutput,lpPoints);
delete lpPoints;
}

void CHistDemoADlg::NoColor()
{
if (lpBitmap==0) return;
int x,y,p;
BYTE Point;
for(y=0;y<nHeight;y++)
{
for(x=0;x<nWidth;x++)
{
p=x*3+y*nByteWidth;
Point=(BYTE)(0.299*(float)lpBits[p+2]+0.587*(float)lpBits[p+1]+0.114*(float)lpBits[p]+0.1);
lpBits[p+2]=Point;
lpBits[p+1]=Point;
lpBits[p]=Point;
}
}
source.SetImage(nWidth,nHeight,lpBits);
}
