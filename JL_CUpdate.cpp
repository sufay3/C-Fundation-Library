// JL_CUpdateC implementation

#include "JL_CUpdate.h"

// constructor
JL_CUpdateC::JL_CUpdateC() : mServerAddr(""), mCurrentVer(""), mLocalPath("")
{

}

JL_CUpdateC::JL_CUpdateC(JL_CString addrStr, JL_CString ver, JL_CString path) : mServerAddr(addrStr), mCurrentVer(ver), mLocalPath(path)
{

}

// destructor
JL_CUpdateC::~JL_CUpdateC()
{

}

// interfaces
void JL_CUpdateC::SetServerAddr(JL_CString addrStr)
{
	mServerAddr = addrStr;
}

void JL_CUpdateC::SetCurrentVer(JL_CString ver)
{
	mCurrentVer = ver;
}

void JL_CUpdateC::SetLocalPath(JL_CString path)
{
	mLocalPath = path;
}

JL_CString JL_CUpdateC::GetServerAddr() const
{
	return mServerAddr;
}

JL_CString JL_CUpdateC::GetCurrentVer() const
{
	return mCurrentVer;
}

JL_CString JL_CUpdateC::GetLocalPath() const
{
	return mLocalPath;
}

bool JL_CUpdateC::HasNewVer()
{

}

void JL_CUpdateC::DownloadUpdated()
{

}

void JL_CUpdateC::InstallUpdated()
{

}