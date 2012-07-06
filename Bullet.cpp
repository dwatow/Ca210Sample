#include"stdafx.h"
#include"Bullet.h"
/****************************************
 *	Define Bullet Class member function *
 ****************************************/

Bullet::Bullet():
m_fSx(0.0), m_fSy(0.0), m_fLv(0.0), 
m_lT(0), m_fDuv(0.0), 
m_fDu(0.0), m_fDv(0.0), 
m_fX(0.0), m_fY(0.0), m_fZ(0.0),
m_strLv(""), m_strSx(""), m_strSy(""), m_strT(""), m_strDuv(""), m_strDu(""), m_strDv(""), m_strX(""), m_strY(""), m_strZ("")
{}

Bullet::Bullet(const Bullet& xp):
m_fSx(xp.m_fSx), m_fSy(xp.m_fSy), m_fLv(xp.m_fLv),
m_lT(xp.m_lT), m_fDuv(xp.m_fDuv), 
m_fDu(xp.m_fDu), m_fDv(xp.m_fDv), 
m_fX(xp.m_fX), m_fY(xp.m_fY), m_fZ(xp.m_fZ),
m_strLv(xp.m_strLv), m_strSx(xp.m_strSx), m_strSy(xp.m_strSy), m_strT(xp.m_strT), m_strDuv(xp.m_strDuv), m_strDu(xp.m_strDu), m_strDv(xp.m_strDv), m_strX(xp.m_strX), m_strY(xp.m_strY), m_strZ(xp.m_strZ)
{}

// Bullet::Bullet(const float& x, const float& y, const float& L, const long& T, const float& Duv):
// m_fLv(L), m_fSx(x), m_fSy(y), m_lT(T), m_fDuv(Duv),
// m_strLv(""), m_strSx(""), m_strSy(""), m_strT(""), m_strDuv(""), m_strDu(""), m_strDv(""), m_strX(""), m_strY(""), m_strZ("")
// {}


Bullet::~Bullet(){}

float Bullet::GetSx()  const {	return m_fSx;}	CString Bullet::GetStrSx()  const {	return m_strSx;}
float Bullet::GetSy()  const {	return m_fSy;}	CString Bullet::GetStrSy()  const {	return m_strSy;}
float Bullet::GetLv()  const {	return m_fLv;}	CString Bullet::GetStrLv()  const {	return m_strLv;}

long  Bullet::GetT()   const {	return m_lT;}	CString Bullet::GetStrT()	const {	return m_strT;}
float Bullet::GetDuv() const {	return m_fDuv;} CString Bullet::GetStrDuv() const {	return m_strDuv;}

float Bullet::GetDu()  const {	return m_fDu;}	CString Bullet::GetStrDu()  const {	return m_strDu;}
float Bullet::GetDv()  const {	return m_fDv;}	CString Bullet::GetStrDv()  const {	return m_strDv;}

float Bullet::GetX()   const {	return m_fX;}	CString Bullet::GetStrX()   const {	return m_strX;}
float Bullet::GetY()   const {	return m_fY;}	CString Bullet::GetStrY()   const {	return m_strY;}
float Bullet::GetZ()   const {	return m_fZ;}	CString Bullet::GetStrZ()   const {	return m_strZ;}

BOOL Bullet::SetSx(float x)
{
	if (x>0 && x<0.8)
	{ 
		m_fSx = x; 
		m_strSx.Format("%f", m_fSx);  //輸出資料用
		return TRUE; 
	} 
	else 
	{
		m_fSx = (float)0.4567; 
		m_strSx.Format("%f", m_fSx);  //輸出資料用
		return FALSE; 
	}
}

BOOL Bullet::SetSy(float y)
{ 
	if (y>0 && y<0.9)
	{	
		m_fSy = y;
		m_strSy.Format("%f", m_fSy);  //輸出資料用
		return TRUE; 
	} 
	else
	{
		m_fSy = (float)0.4567;
		m_strSy.Format("%f", m_fSy);  //輸出資料用
		return FALSE; 
	}
}

BOOL Bullet::SetLv(float L)
{ 
	if (L>=0)        
	{ 
		m_fLv = L;	 
		m_strLv.Format("%f", m_fLv);  //輸出資料用
		return TRUE; 
	} 
	else
	{
		m_fLv = (float)987.65;
		m_strLv.Format("%f", m_fLv);  //輸出資料用
		return FALSE; 
	}
}

BOOL Bullet::SetT(long T)     
{ 
	m_lT = T;     
	m_strT.Format("%d", m_lT);  //輸出資料用
	return TRUE; 
}

BOOL Bullet::SetDuv(float Duv)
{ 
	m_fDuv = Duv;	
	m_strDuv.Format("%f", m_fDuv);  //輸出資料用
	return TRUE; 
}

BOOL Bullet::SetDu(float Du)  
{ 
	m_fDu  = Du;	
	m_strDu.Format("%f", m_fDu);  //輸出資料用
	return TRUE; 
}
BOOL Bullet::SetDv(float Dv)  
{ 
	m_fDv  = Dv;    
	m_strDv.Format("%f", m_fDv);  //輸出資料用
	return TRUE; 
}

BOOL Bullet::SetX(float X)    
{ 
	m_fX   = X;  
	m_strX.Format("%f", m_fX);  //輸出資料用
	return TRUE; 
}
BOOL Bullet::SetY(float Y)    
{ 
	m_fY   = Y;  
	m_strY.Format("%f", m_fY);  //輸出資料用
	return TRUE; 
}
BOOL Bullet::SetZ(float Z)    
{ 
	m_fZ   = Z;  
	m_strZ.Format("%f", m_fZ);  //輸出資料用
	return TRUE; 
}
////////////////////////////////////////
BOOL Bullet::SetSx(CString x)
{
	if (atof(x)>0 && atof(x)<0.8)
	{ 
		m_strSx = x;
		m_fSx = (float)atof(x);
		return TRUE; 
	} 
	else 
		return FALSE; 
}

BOOL Bullet::SetSy(CString y)
{ 
	if (atof(y)>0 && atof(y)<0.9)
	{	
		m_strSy = y;
		m_fSy = (float)atof(y);  //輸出資料用
		return TRUE; 
	} 
	else	
		return FALSE; 
}

BOOL Bullet::SetLv(CString L)
{ 
	if (atof(L)>=0)        
	{ 
		m_strLv = L;	 
		m_fLv = (float)atof(L);  //輸出資料用
		return TRUE; 
	} 
	else	
		return FALSE; 
}

BOOL Bullet::SetT(CString T)     
{ 
	m_strT = T;     
	m_lT = atol(T);  //輸出資料用
	return TRUE; 
}
BOOL Bullet::SetDuv(CString Duv)
{ 
	m_strDuv = Duv;	
	m_fDuv = (float)atof(Duv);  //輸出資料用
	return TRUE; 
}

BOOL Bullet::SetDu(CString Du)  
{ 
	m_strDu = Du;	
	m_fDu   = (float)atof(Du);  //輸出資料用
	return TRUE; 
}
BOOL Bullet::SetDv(CString Dv)  
{ 
	m_strDv = Dv;    
	m_fDv   = (float)atof(Dv);  //輸出資料用
	return TRUE; 
}

BOOL Bullet::SetX(CString X)    
{ 
	m_strX = X;  
	m_fX   = (float)atof(X);  //輸出資料用
	return TRUE; 
}
BOOL Bullet::SetY(CString Y)    
{ 
	m_strY = Y;  
	m_fY   = (float)atof(Y);  //輸出資料用
	return TRUE; 
}
BOOL Bullet::SetZ(CString Z)    
{ 
	m_strZ = Z;  
	m_fZ   = (float)atof(Z);  //輸出資料用
	return TRUE; 
}
////////////////////////////////////////
void Bullet::operator() (float L, float Sx, float Sy, long T, float Duv,
						 float Du, float Dv, float X, float Y, float Z)
{
	m_fLv = L;								m_fX = X;
	m_fSx = Sx;	m_lT   = T;		m_fDu = Du;	m_fY = Y;
	m_fSy = Sy;	m_fDuv = Duv;	m_fDv = Dv;	m_fZ = Z;
}

void Bullet::operator() (Bullet& xp)
{
	m_fLv = xp.m_fLv;											m_fX = xp.m_fX;
	m_fSx = xp.m_fSx;	m_lT   = xp.m_lT;	m_fDu = xp.m_fDu;	m_fY = xp.m_fY;
	m_fSy = xp.m_fSy;	m_fDuv = xp.m_fDuv;	m_fDv = xp.m_fDv;	m_fZ = xp.m_fZ;
}

void Bullet::operator= (const Bullet& xp)
{
	m_fLv = xp.m_fLv;											m_fX = xp.m_fX;
	m_fSx = xp.m_fSx;	m_lT   = xp.m_lT;	m_fDu = xp.m_fDu;	m_fY = xp.m_fY;
	m_fSy = xp.m_fSy;	m_fDuv = xp.m_fDuv;	m_fDv = xp.m_fDv;	m_fZ = xp.m_fZ;
}

CString Bullet::MsgBoxStr()
{
	CString strBullet;
	strBullet.Format("Lv:%f, %s\nx:%f, %s\ny:%f, %s\nT:%d, %s\nDuv:%f, %s\nDu:%f, %s\nDv:%f, %s\nX:%f, %s\nY:%f, %s\nZ:%f, %s"\
		, m_fLv, m_strLv, m_fSx, m_strSx, m_fSy, m_strSy\
		, m_lT, m_strT, m_fDuv, m_strDuv\
		, m_fDu, m_strDu, m_fDv, m_strDv\
		, m_fX, m_strX, m_fY, m_strY, m_fZ, m_strZ);

	return strBullet;
}