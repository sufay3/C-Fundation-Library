#ifndef JL_CSOCKET_H
#define JL_CSOCKET_H

#include "JL_CString.h"

// a socket wrapper
class JL_CSocket
{
public:
	// constructor
	JL_CSocket();
	JL_CSocket(int socketType);

	// copy constructor
	JL_CSocket(const JL_CSocket &sour);

	// destructor
	~JL_CSocket();

	// interfaces
	bool Connect(const JL_CString &destAddr);
	int Send(const JL_CString &datas);
	int Receive(JL_CString &buffer);

	bool IsConnected();
	void DisConnect();
	void Destroy();
private:
	// internal methods
	void Create();
	int GetIP(const JL_CString &ipStr);

	// attributions
	int mSocket;
	int mSocketType;
};

#endif// JL_CSOCKET_H