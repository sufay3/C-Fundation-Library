// JL_CAuthority implementation

#include "JL_CAuthority.h"
#include "JL_CFile.h"

// constructor
JL_CAuthority::JL_CAuthority() : mMachineCode(""), mAuthFileName(""), mFeature(3)
{
	
}

// copy constructor
JL_CAuthority::JL_CAuthority(const JL_CAuthority &sour)
{
	mMachineCode = sour.mMachineCode;
	mExpirationDate = sour.mExpirationDate;
	mFeature = sour.mFeature;
	mAuthFileName = "";
}

// destructor
JL_CAuthority::~JL_CAuthority()
{

}

// interfaces
void JL_CAuthority::GenAuthFile()
{

}

bool JL_CAuthority::IsExpired()
{

}

void JL_CAuthority::SetMachineCode(JL_CString machineCode)
{
	mMachineCode = machineCode;
}

void JL_CAuthority::SetExpirationDate(JL_CDate date)
{
	mExpirationDate = date;
}

void JL_CAuthority::SetAuthFileName(JL_CString fileName)
{
	mAuthFileName = fileName;
}

// internal methods
JL_CString JL_CAuthority::GetMachineCode()
{
	return mMachineCode;
}

void JL_CAuthority::GenMachineCode()
{

}

void JL_CAuthority::GenFeature()
{

}

bool JL_CAuthority::IsValidFile()
{

}

void JL_CAuthority::ExtractFeature(JL_CArray<JL_CString> &feature)
{

}

JL_CDate JL_CAuthority::GetExpirationDate()
{
	return mExpirationDate;
}