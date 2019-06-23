; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHistDemoADlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HistDemoA.h"

ClassCount=4
Class1=CHistDemoAApp
Class2=CHistDemoADlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CImageWnd
Resource3=IDD_HISTDEMOA_DIALOG

[CLS:CHistDemoAApp]
Type=0
HeaderFile=HistDemoA.h
ImplementationFile=HistDemoA.cpp
Filter=N
LastObject=CHistDemoAApp

[CLS:CHistDemoADlg]
Type=0
HeaderFile=HistDemoADlg.h
ImplementationFile=HistDemoADlg.cpp
Filter=D
LastObject=IDC_Hist
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=HistDemoADlg.h
ImplementationFile=HistDemoADlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_HISTDEMOA_DIALOG]
Type=1
Class=CHistDemoADlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308865
Control3=IDC_STATIC,static,1342308865
Control4=IDC_OPEN,button,1342242816
Control5=IDC_Hist,button,1342242816

[CLS:CImageWnd]
Type=0
HeaderFile=ImageWnd.h
ImplementationFile=ImageWnd.cpp
BaseClass=CWnd

