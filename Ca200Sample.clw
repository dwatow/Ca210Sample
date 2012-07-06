; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCaEvent
LastTemplate=CCmdTarget
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ca200Sample.h"
ODLFile=Ca200Sample.odl

ClassCount=5
Class1=CCa200SampleApp
Class2=CCa200SampleDlg
Class3=CAboutDlg
Class4=CCa200SampleDlgAutoProxy

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CCaEvent
Resource3=IDD_CA200SAMPLE_DIALOG

[CLS:CCa200SampleApp]
Type=0
HeaderFile=Ca200Sample.h
ImplementationFile=Ca200Sample.cpp
Filter=N

[CLS:CCa200SampleDlg]
Type=0
HeaderFile=Ca200SampleDlg.h
ImplementationFile=Ca200SampleDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CCa200SampleDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=Ca200SampleDlg.h
ImplementationFile=Ca200SampleDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CCa200SampleDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_CA200SAMPLE_DIALOG]
Type=1
Class=CCa200SampleDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1073807361
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC_LV,static,1342312972
Control9=IDC_STATIC_X,static,1342312972
Control10=IDC_STATIC_Y,static,1342312972
Control11=IDC_STATIC_T,static,1342312972
Control12=IDC_STATIC_DUV,static,1342312972
Control13=IDC_BUTTON_MSR,button,1342242816
Control14=IDC_BUTTON_CAL0,button,1342242816

[CLS:CCaEvent]
Type=0
HeaderFile=CaEvent.h
ImplementationFile=CaEvent.cpp
BaseClass=CCmdTarget
Filter=N
VirtualFilter=C
LastObject=CCaEvent

