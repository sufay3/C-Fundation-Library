// JL_CDataCenter implementation

#include "JL_CDataCenter.h"

// constructor
JL_CDataCenter::JL_CDataCenter()
{

}

// copy constructor
JL_CDataCenter::JL_CDataCenter(const JL_CDataCenter &sour)
{

}

// destructor
JL_CDataCenter::~JL_CDataCenter()
{
	Clear();
}

// interfaces
void JL_CDataCenter::AddDataBase(JL_CDataBase *dataBase, int type)
{
	int index = mDataBaseList.Append(dataBase);
	mDataBaseNum += 1;
	
	if (type == 0)
	{
		mSDBIndexList.Append(index);
		mISDBIndexQueue.Join(index);

		mSDBNum += 1;
		mISDBNum += 1;
	}
	else
	{
		mBDBIndexList.Append(index);
		mIBDBIndexQueue.Join(index);

		mBDBNum += 1;
		mIBDBNum += 1;
	}
}

void JL_CDataCenter::DelDataBase(JL_CDataBase *dataBase)
{
	if
}

void JL_CDataCenter::DelDataBase(int index)
{

}

int JL_CDataCenter::GetSDataBase() const
{

}

int JL_CDataCenter::GetBDataBase() const
{

}

int JL_CDataCenter::GetDataBaseNum() const
{
	return mDataBaseNum;
}

int JL_CDataCenter::GetSDBNum() const
{
	return mSDBNum;
}

int JL_CDataCenter::GetBDBNum() const
{
	return mBDBNum;
}

int JL_CDataCenter::GetISDBNum() const
{
	return mISDBNum;
}

int JL_CDataCenter::GetIBDBNum() const
{
	return mIBDBNum;
}

bool JL_CDataCenter::IsIdle(JL_CDataBase *dataBase) const
{
	int index = mDataBaseList.Search(dataBase);
	if (mISDBIndexQueue.)
}

int JL_CDataCenter::GetType(JL_CDataBase *dataBase) const
{
	int index = mDataBaseList.Search(dataBase);

	if (mSDBIndexList.Search(index) >= 0)
		return 0;
	else if (mBDBIndexList.Search(index) >= 0)
		return 1;
}

int JL_CDataCenter::GetStat(JL_CDataBase *dataBase) const
{
	return mStatList[mDataBaseList.Search(dataBase)];
}

void JL_CDataCenter::Store(JL_CString sql)
{

}

void JL_CDataCenter::GetData(JL_CString sql)
{

}

void JL_CDataCenter::Backup(JL_CString sql)
{

}

void JL_CDataCenter::Restore(JL_CString sql)
{

}