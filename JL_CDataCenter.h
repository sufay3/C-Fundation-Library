#ifndef JL_CDATACENTER_H
#define JL_CDATACENTER_H

#include "JL_CDataBase.h"
#include "JL_CArray.h"
#include "JL_CQueue.h"

// data center class
class JL_CDataCenter
{
public:
	// costructor
	JL_CDataCenter();
	
	// copy constructor
	JL_CDataCenter(const JL_CDataCenter &sour);

	// destructor
    ~JL_CDataCenter();

	// interfaces
	void AddDataBase(JL_CDataBase *dataBase, int type = 0);
	void DelDataBase(JL_CDataBase *dataBase);
	void DelDataBase(int index);
	void Clear();

	int GetSDataBase() const;
	int GetBDataBase() const;

	int GetDataBaseNum() const;
	int GetSDBNum() const;
	int GetBDBNum() const;
	int GetISDBNum() const;
	int GetIBDBNum() const;

	bool IsIdle(JL_CDataBase *dataBase) const;
	int GetType(JL_CDataBase *dataBase) const;
	int GetStat(JL_CDataBase *dataBase) const;

	void Store(JL_CString sql);
	void GetData(JL_CString sql);
	void Backup(JL_CString sql);
	void Restore(JL_CString sql);
private:
	// attributions
	JL_CArray<JL_CDataBase *> mDataBaseList;
	JL_CArray<int> mSDBIndexList;
	JL_CArray<int> mBDBIndexList;

	JL_CArray<int> mStatList;
	JL_CQueue<int> mISDBIndexQueue;
	JL_CQueue<int> mIBDBIndexQueue;

	int mDataBaseNum;
	int mSDBNum;
	int mBDBNum;
	int mISDBNum;
	int mIBDBNum;
};

#endif// JL_CDATACENTER_H