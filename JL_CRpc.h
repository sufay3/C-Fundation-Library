#ifndef JL_CRPC_H
#define JL_CRPC_H

#include "JL_CSocket.h"
#include "JL_CString.h"

// a class used to implementation the RPC protocol
class JL_CRpc
{
public:
	// constructor
	JL_CRpc(int mRpcType=0);

	// destructor
	~JL_CRpc();

	// interfaces
	bool Request(CString reqMethodName, CString reqArglist="", CString reqRes="");// send a request to the connected end which lies in a distributed architecture
	CString ReturnRes(CString req);// return the handled result to the end who sent it a request
private:
	// internal methods
	CString BuildRequest(CString reqMethodName, CString reqArglist = "");// build a request string by given arguments
	void ParseRequest(CString req, CString reqMethodName, CString reqArglist);// parse a request string to what needed
	
	bool IsActive();// if the member mSocket stays in a connected status, return ture. Otherwise,return false
	 
	// attributions
	JL_CSocket mSocket;// an instance of JL_CSocket
};

#endif // JL_CRPC_H