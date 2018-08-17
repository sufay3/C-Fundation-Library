// JL_CSocket implementation

#include "JL_CSocket.h"

// constructor
JL_CSocket::JL_CSocket()
{
	mSocketType = 0;
	Create();
}

JL_CSocket::JL_CSocket(int socketType)
{
	mSocketType = socketType;
	Create();
}

// copy constructor
JL_CSocket::JL_CSocket(const JL_CSocket &sour)
{
	mSocket = sour.mSocket;
	mSocketType = sour.mSocketType;
}

// destructor
JL_CSocket::~JL_CSocket()
{

}

// interfaces
bool JL_CSocket::Connect(const JL_CString &destAddr)
{

}

int JL_CSocket::Send(const JL_CString &datas)
{

}

int JL_CSocket::Receive(JL_CString &buffer)
{

}

bool JL_CSocket::IsConnected()
{

}

void JL_CSocket::DisConnect()
{

}

void JL_CSocket::Destroy()
{

}

// internal methods
void JL_CSocket::Create();
{

}

int JL_CSocket::GetIP(const JL_CString &ipStr)
{

}
