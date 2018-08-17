// JL_CQueue implementation

#include "JL_CQueue.h"

// constructor
template <class T> JL_CQueue<T>::JL_CQueue()
{
	mFirst = 0;
	mLength = 0;
}

// copy constructor
template <class T> JL_CQueue<T>::JL_CQueue(const JL_CQueue<T> &sour)
{
	mFirst = sour.mFirst;
	mLength = sour.mLength;

	if (mFirst)
	{
		JL_CEnd<T> *ptrCache = mFirst;
		while (ptrCache)
		{
			Join(ptrCache->GetValue());
			ptrCache = ptrCache->GetPtr();
		}
	}
}

// destructor
template <class T> JL_CQueue<T>::~JL_CQueue()
{
	Clear();
}

// interfaces
template <class T> void JL_CQueue<T>::Join(const T &value)
{
	JL_CEnd<T> *newEnd = new JL_CEnd<T>(value);

	if (mFirst)
		mFirst->GetPtr = newEnd;
	else
		mFirst = newEnd;
}

template <class T> T JL_CQueue<T>::MoveFirst()
{
	T first;

	if (mFirst)
	{
		first = mFirst->GetValue();
		
		JL_CEnd<T> *ptrCache = mFirst;
		mFirst = mFirst->GetPtr();
		mLength--;

		delete ptrCache;
	}

	return first;
}

template <class T> void JL_CQueue<T>::Clear()
{
	JL_CEnd<T> *ptrCache = 0;
	while (mFirst)
	{
		ptrCache = mFirst->GetPtr();
		delete mFirst;

		mFirst = ptrCache;
	}

	mLength = 0;
}

template <class T> int JL_CQueue<T>::GetLen() const
{
	return mLength;
}

