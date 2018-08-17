// JL_CArray implementation

#include "JL_CArray.h"

// constructor
template <class T> JL_CArray<T>::JL_CArray()
{
	mStart = 0;
	mCurLen = 0;
}

template <class T> JL_CArray<T>::JL_CArray(int maxLen)
{
	mStart = new T[maxLen];
	mCurLen = 0;
	mMaxLen = maxLen;
}

// copy constructor
template <class T> JL_CArray<T>::JL_CArray(const JL_CArray<T> &sour)
{
	Copy(sour);
}

// destructor
template <class T> JL_CArray<T>::~JL_CArray()
{
	Clear();
}

//overload operator "[]"
template <class T> T JL_CArray<T>::operator[](int pos) const
{
	return GetAt(pos);
}

// interfaces
template <class T> int JL_CArray<T>::GetCurLen() const
{
	return mCurLen;
}

template <class T> int JL_CArray<T>::GetMaxLen() const
{
	return mMaxLen;
}

template <class T> T JL_CArray<T>::GetAt(int pos) const
{
	if (pos >= 0 || pos < mCurLen)
		return *(mStart + pos);
	else
		return T(0);
}

template <class T> void JL_CArray<T>::Resize(int newLen, int reserveTag = 1)
{

}

template <class T> int JL_CArray<T>::Append(T value)
{
	return(Insert(mCurLen, value));
}

template <class T> int JL_CArray<T>::Insert(int pos, T value)
{ 
	
}

template <class T> void JL_CArray<T>::Delete(int pos)
{

}

template <class T> void JL_CArray<T>::Clear()
{
	if (mStart)
	{
		delete mStart;
		mCurLen = 0;
	}
}

template <class T> void JL_CArray<T>::AppendEx(const JL_CArray<T>& arr)
{
	for (int count = 0; count < arr.mCurLen; count++)
		Append(*(arr.mStart + count));
}

template <class T> void JL_CArray<T>::BatAssign(T value)
{
	for (int count = 0; count < mMaxLen; count++)
		*(mStart + count) = value;
}

template <class T> int JL_CArray<T>::Search(T value) const
{
	for (int count = 0; count < mCurLen; count++)
	if (*(mStart + count) == value)
		return count;

	return -1;
}

template <class T> void JL_CArray<T>::Sort(int sortType)
{

}

template <class T> JL_CString JL_CArray<T>::Join(JL_CString splitSym) const
{
	JL_CString res;

	T *ptrCache = mStart;
	while (ptrCache)
		res = res + *(ptrCache++) + splitSym;

	return res;
}

template <class T> void JL_CArray<T>::Filter(T value, int reserveTag)
{
	int count = 0;
	while (count < mCurLen)
	{
		if (reserveTag == 0)
		{
			if (*(mStart + count) == value)
				Delete(count++);
		}
		else
		{
			if (*(mStart + count) != value)
				Delete(count++);
		}
	}
}

template <class T> void JL_CArray<T>::FilterEx()
{

}

// internal methods
template <class T> void JL_CArray<T>::Copy(const JL_CArray<T> &sour)
{

}

template <class T> void JL_CArray<T>::Alloc(int len)
{

}