// JL_CLog implementation

#include "JL_CLog.h"
#include "JL_CFile.h"

// constructor
JL_CLog::JL_CLog() :mPath("")
{
	mSize = 0;
}

JL_CLog::JL_CLog(JL_CString path) : mPath(path)
{
	SetSize();
	SetTime();
}

// copy constructor
JL_CLog::JL_CLog(const JL_CLog &sour)
{
	mPath = sour.mPath;
	mSize = sour.mSize;
	mTime = sour.mTime;
}

// destructor
JL_CLog::~JL_CLog()
{

}

// interfaces
void JL_CLog::SetPath(JL_CString path)
{
	mPath = path;
}

JL_CString JL_CLog::GetPath() const
{
	return mPath;
}

int JL_CLog::GetSize() const
{
	return mSize;
}

JL_CDate JL_CLog::GetTime() const
{
	return mTime;
}

JL_CString JL_CLog::Read()
{

}

void JL_CLog::Write(JL_CString log)
{

}

void JL_CLog::Clear()
{

}

void JL_CLog::SetSize()
{

}

void JL_CLog::SetTime()
{

}