// JL_CDll implementation

#include "JL_CDll.h"

// constructor
JL_CDll::JL_CDll()
{

}

JL_CDll::JL_CDll(JL_CString dllName)
{

}

// copy constructor
JL_CDll::JL_CDll(const JL_CDll &sour)
{

}

// destructor
JL_CDll::~JL_CDll()
{

}

// interfaces
void JL_CDll::Load(JL_CString dllName)
{

}

void JL_CDll::Free()
{

}

int JL_CDll::GetHandle() const
{

}

void *JL_CDll::GetAddress(JL_CString procedureName)
{

}

void JL_CDll::Call(JL_CString procedureName, JL_CString args, JL_CString output)
{

}