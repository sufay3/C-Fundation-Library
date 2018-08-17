// JL_CEnd implementation

#include "JL_CEnd.h"

// constructor
template <class T> JL_CEnd<T>::JL_CEnd()
{
	mValue = T(0);
	mPtr = 0;
}

template <class T> JL_CEnd<T>::JL_CEnd(const T &value)
{
	mValue = value;
	mPtr = 0;
}

// copy constructor
template <class T> JL_CEnd<T>::JL_CEnd(const JL_CEnd<T> &sour)
{
	mValue = sour.mValue;
	mPtr = 0;
}

// destructor
template <class T> JL_CEnd<T>::~JL_CEnd()
{
	mPtr = 0;
}

// interfaces
template <class T> void JL_CEnd<T>::SetValue(const T &value)
{
	mValue = value;
}

template <class T> void JL_CEnd<T>::SetPtr(const JL_CEnd<T> *end)
{
	mPtr = end;
}

template <class T> T JL_CEnd<T>::GetValue() const
{
	return mValue;
}

template <class T> JL_CEnd<T> *JL_CEnd<T>::GetPtr() const
{
	return mPtr;
}