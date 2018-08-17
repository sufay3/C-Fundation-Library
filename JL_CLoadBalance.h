#ifndef JL_CLOADBALANCE_H
#define JL_CLOADBALANCE_H

#include "JL_CRpc.h"
#include "JL_CArray.h"
#include "JL_CQueue.h"

// to realize a load balance component
class JL_CLoadBalance
{
public:
	// constructor
	JL_CLoadBalance();

	// copy constructor
	JL_CLoadBalance(const JL_CLoadBalance &sour);

	// destructor
	~JL_CLoadBalance();

	// interfaces
	JL_CRpc *GetNotBusyServer() const;

	int GetServerNum() const;
	int GetNotBusyNum() const;
	int GetTraffic(int index) const;
	int GetTraffic(JL_CRpc *rpc) const;

	void AddServer(JL_CRpc *rpc);
	void DelServer(int index);
private:
	// internal methods
	void ChangeState(int index, int state);

	// attributions
	JL_CArray<JL_CRpc *> mServerList;
	JL_CArray<int> mTrafficList;
	JL_CQueue<int> mNotBusyIndexQueue;

	int mServerNum;
	int mNotBusyNum;
};

#endif// JL_CLOADBALANCE_H