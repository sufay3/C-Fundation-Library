// JL_CLoadBalance implementation

#include "JL_CLoadBalance.h"

// constructor
JL_CLoadBalance::JL_CLoadBalance()
{

}

// copy constructor
JL_CLoadBalance::JL_CLoadBalance(const JL_CLoadBalance &sour)
{

}

// destructor
JL_CLoadBalance::~JL_CLoadBalance()
{

}

// interfaces
JL_CRpc *JL_CLoadBalance::GetNotBusyServer() const
{
	
}

int JL_CLoadBalance::GetServerNum() const
{
	return mServerNum;
}

int JL_CLoadBalance::GetNotBusyNum() const
{
	return mNotBusyNum;
}

int JL_CLoadBalance::GetTraffic(int index) const
{
	if (index >= 0 || index < mServerNum)
		return mTrafficList[index];
	else
		return -1;
}

int JL_CLoadBalance::GetTraffic(JL_CRpc *rpc) const
{
	int index = mServerList.Search(rpc);

	if (index >= 0)
		return mTrafficList[index];
	else
		return -1;
}

void JL_CLoadBalance::AddServer(JL_CRpc *rpc)
{
	mServerList.Append(rpc);
}

void JL_CLoadBalance::DelServer(int index)
{
	mServerList.Delete(index);
}

// internal methods
void JL_CLoadBalance::ChangeState(int index, int state)
{
	
}