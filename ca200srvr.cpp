// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "ca200srvr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// ICa200 properties

/////////////////////////////////////////////////////////////////////////////
// ICa200 operations

LPDISPATCH ICa200::GetCas()
{
	LPDISPATCH result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void ICa200::SetConfiguration(long CaNumberVal, LPCTSTR ConnecStringVal, long PortVal, long BaudRateVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_I4 VTS_I4;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 CaNumberVal, ConnecStringVal, PortVal, BaudRateVal);
}

void ICa200::AutoConnect()
{
	InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH ICa200::GetSingleCa()
{
	LPDISPATCH result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// ICa properties

/////////////////////////////////////////////////////////////////////////////
// ICa operations

LPDISPATCH ICa::GetProbes()
{
	LPDISPATCH result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH ICa::GetOutputProbes()
{
	LPDISPATCH result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH ICa::GetMemory()
{
	LPDISPATCH result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString ICa::GetDisplayProbe()
{
	CString result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void ICa::SetDisplayProbe(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPDISPATCH ICa::GetSingleProbe()
{
	LPDISPATCH result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

float ICa::GetSyncMode()
{
	float result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void ICa::SetSyncMode(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long ICa::GetDisplayMode()
{
	long result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ICa::SetDisplayMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long ICa::GetDisplayDigits()
{
	long result;
	InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ICa::SetDisplayDigits(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long ICa::GetAveragingMode()
{
	long result;
	InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ICa::SetAveragingMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long ICa::GetBrightnessUnit()
{
	long result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ICa::SetBrightnessUnit(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString ICa::GetCAType()
{
	CString result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString ICa::GetCAVersion()
{
	CString result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

long ICa::GetNumber()
{
	long result;
	InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString ICa::GetPortID()
{
	CString result;
	InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString ICa::GetId()
{
	CString result;
	InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void ICa::SetId(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void ICa::CalZero()
{
	InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ICa::Measure(long newVal)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 newVal);
}

void ICa::SetAnalyzerCalMode()
{
	InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ICa::Enter()
{
	InvokeHelper(0x14, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ICa::SetAnalogRange(float Range1Val, float Range2Val)
{
	static BYTE parms[] =
		VTS_R4 VTS_R4;
	InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Range1Val, Range2Val);
}

void ICa::SetPWROnStatus()
{
	InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long ICa::GetCalStandard()
{
	long result;
	InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void ICa::SetCalStandard(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x22, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void ICa::ResetAnalyzerCalMode()
{
	InvokeHelper(0x23, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ICa::SetLvxyCalMode()
{
	InvokeHelper(0x24, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ICa::ResetLvxyCalMode()
{
	InvokeHelper(0x25, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void ICa::SetAnalyzerCalData(long ColorVal)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x26, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ColorVal);
}

void ICa::SetDisplayProbe(long ProbeNumberVal)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x27, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ProbeNumberVal);
}

void ICa::SetLvxyCalData(long ColorVal, float XVal, float YVal, float LvVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_R4 VTS_R4 VTS_R4;
	InvokeHelper(0x28, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ColorVal, XVal, YVal, LvVal);
}

void ICa::SetRemoteMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x29, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void ICa::SetFMAAnalogRange(float RangeVal)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x2a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 RangeVal);
}

void ICa::GetAnalogRange(float* Range1Val, float* Range2Val)
{
	static BYTE parms[] =
		VTS_PR4 VTS_PR4;
	InvokeHelper(0x2b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Range1Val, Range2Val);
}

void ICa::GetFMAAnalogRange(float* RangeVal)
{
	static BYTE parms[] =
		VTS_PR4;
	InvokeHelper(0x2c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 RangeVal);
}


/////////////////////////////////////////////////////////////////////////////
// IProbe properties

/////////////////////////////////////////////////////////////////////////////
// IProbe operations

float IProbe::GetX()
{
	float result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetY()
{
	float result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetZ()
{
	float result;
	InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetFlckrJEITA()
{
	float result;
	InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

long IProbe::GetNumber()
{
	long result;
	InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString IProbe::GetId()
{
	CString result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void IProbe::SetId(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString IProbe::GetSerialNO()
{
	CString result;
	InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

float IProbe::GetLv()
{
	float result;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetUd()
{
	float result;
	InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetVd()
{
	float result;
	InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

long IProbe::GetT()
{
	long result;
	InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

float IProbe::GetDEUser()
{
	float result;
	InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetFlckrFMA()
{
	float result;
	InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetSy()
{
	float result;
	InvokeHelper(0x16, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetSx()
{
	float result;
	InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetDuv()
{
	float result;
	InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetUsUser()
{
	float result;
	InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetVsUser()
{
	float result;
	InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetLsUser()
{
	float result;
	InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetLvfL()
{
	float result;
	InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetR()
{
	float result;
	InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetG()
{
	float result;
	InvokeHelper(0x1f, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

float IProbe::GetB()
{
	float result;
	InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

long IProbe::GetRd()
{
	long result;
	InvokeHelper(0x21, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long IProbe::GetRad()
{
	long result;
	InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long IProbe::GetRfma()
{
	long result;
	InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long IProbe::GetRjeita()
{
	long result;
	InvokeHelper(0x24, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

float IProbe::GetSpectrum(long Frequency)
{
	float result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x25, DISPATCH_METHOD, VT_R4, (void*)&result, parms,
		Frequency);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// IMemory properties

/////////////////////////////////////////////////////////////////////////////
// IMemory operations

long IMemory::GetChannelNO()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IMemory::SetChannelNO(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString IMemory::GetChannelID()
{
	CString result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void IMemory::SetID(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void IMemory::GetReferenceColor(LPCTSTR ProbeIDVal, float* XVal, float* YVal, float* LvVal)
{
	static BYTE parms[] =
		VTS_BSTR VTS_PR4 VTS_PR4 VTS_PR4;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ProbeIDVal, XVal, YVal, LvVal);
}

void IMemory::SetChannelID(LPCTSTR ChannelIDVal)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ChannelIDVal);
}

void IMemory::GetMemoryStatus(long ProbeNOVal, long* CalProbeSNOVal, long* RefProbeSNOVal, long* CalModeVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ProbeNOVal, CalProbeSNOVal, RefProbeSNOVal, CalModeVal);
}

long IMemory::CheckCalData(long ProbeNOVal, LPCTSTR FileNameVal)
{
	long result;
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		ProbeNOVal, FileNameVal);
	return result;
}

void IMemory::CopyToFile(long ProbeNOVal, LPCTSTR FileNameVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ProbeNOVal, FileNameVal);
}

void IMemory::CopyFromFile(long ProbeNOVal, LPCTSTR FileNameVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ProbeNOVal, FileNameVal);
}

