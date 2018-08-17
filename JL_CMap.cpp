// JL_CMap and JL_CPair implementation

#include "JL_CMap.h"

//JL_CMap implementation

// constructor
template <class KeyT, class ValueT> JL_CMap<KeyT, ValueT>::JL_CMap()
{
	mStart = 0;
	mLength = 0;
}

// copy constructor
template <class KeyT, class ValueT> JL_CMap<KeyT, ValueT>::JL_CMap(const JL_CMap &sour)
{
	mLength = sour.mLength;
	
	if (mLength == 0)
		mStart = 0;
	else
		for (int count = 0; count < mLength; count++)
			Join(sour.mStart->GetKey(), sour.mStart->GetValue());
}

// destructor
template <class KeyT, class ValueT> JL_CMap<KeyT, ValueT>::~JL_CMap()
{
	SetZero();
}

// overload operators
template <class KeyT, class ValueT> ValueT JL_CMap<KeyT, ValueT>::operator[](KeyT key) const
{
	return GetValue(key);
}

// inferfaces
template <class KeyT, class ValueT> ValueT JL_CMap<KeyT, ValueT>::GetValue(KeyT key) const
{
	ValueT res;

	JL_CPair<class KeyT, class ValueT> *ptrCache = mStart;
	while (ptrCache)
	{
		if (ptrCache->GetKey() == key)
		{
			res = ptrCache->GetValue();
			break;
		}
		else
			ptrCache = ptrCache->GetBack();
	}
	
	return res;
}

template <class KeyT, class ValueT> ValueT JL_CMap<KeyT, ValueT>::GetValueByIndex(int keyIndex) const
{
	ValueT res;

	if (keyIndex >= 0 || keyIndex < mLength)
	{
		JL_CPair<class KeyT, class ValueT> *ptrCache = mStart;
		int count = 0;

		while (count++ <keyIndex)
			ptrCache = ptrCache->GetBack();

		res = ptrCache->GetValue();
	}
	
	return res;
}

template <class KeyT, class ValueT> KeyT JL_CMap<KeyT, ValueT>::GetKey(ValueT value) const
{
	KeyT res;

	JL_CPair<class KeyT, class ValueT> *ptrCache = mStart;
	while (ptrCache)
	{
		if (ptrCache->GetValue() == value)
		{
			res = ptrCache->GetKey();
			break;
		}
		else
			ptrCache = ptrCache->GetBack();
	}

	return res;
}

template <class KeyT, class ValueT> KeyT JL_CMap<KeyT, ValueT>::GetKeyByIndex(int keyIndex) const
{
	KeyT res;

	if (keyIndex >= 0 || keyIndex < mLength)
	{
		JL_CPair<class KeyT, class ValueT> *ptrCache = mStart;
		int count = 0;

		while (count++ < keyIndex)
			ptrCache = ptrCache->GetBack();

		res = ptrCache->GetKey();
	}

	return res;
}

template <class KeyT, class ValueT> int JL_CMap<KeyT, ValueT>::GetIndex(KeyT key) const
{
	int res = -1;

	JL_CPair<class KeyT, class ValueT> *ptrCache = mStart;
	int count = 1;

	while (ptrCache)
	{
		if (ptrCache->GetKey() != key)
		{
			count++;
			ptrCache = ptrCache->GetBack();
		}
		else
		{
			res += count;
			break;
		}
	}

	return res;
}

template <class KeyT, class ValueT> int JL_CMap<KeyT, ValueT>::GetIndexByValue(ValueT value) const
{
	int res = -1;

	JL_CPair<class KeyT, class ValueT> *ptrCache = mStart;
	int count = 1;

	while (ptrCache)
	{
		if (ptrCache->GetValue() != value)
		{
			count++;
			ptrCache = ptrCache->GetBack();
		}
		else
		{
			res += count;
			break;
		}
	}

	return res;
}

template <class KeyT, class ValueT> void JL_CMap<KeyT, ValueT>::SetValue(KeyT key ,ValueT newValue)
{
	JL_CPair<class KeyT, class ValueT> *ptrCache = mStart;
	while (ptrCache)
	{
		if (ptrCache->GetKey() == key)
		{
			ptrCache->SetValue(newValue);
			break;
		}
		else
			ptrCache = ptrCache->GetBack();
	}
}

template <class KeyT, class ValueT> void JL_CMap<KeyT, ValueT>::SetKey(ValueT value, KeyT newKey)
{
	JL_CPair<class KeyT, class ValueT> *ptrCache = mStart;
	while (ptrCache)
	{
		if (ptrCache->GetValue() == value)
		{
			ptrCache->SetKey(newKey);
			break;
		}
		else
			ptrCache = ptrCache->GetBack();
	}
}

template <class KeyT, class ValueT> void JL_CMap<KeyT, ValueT>::AlterKey(KeyT key, KeyT newKey)
{
	JL_CPair<class KeyT, class ValueT> *ptrCache = mStart;
	while (ptrCache)
	{
		if (ptrCache->GetKey() == key)
		{
			ptrCache->SetKey(newKey);
			break;
		}
		else
			ptrCache = ptrCache->GetBack();
	}
}

template <class KeyT, class ValueT> JL_CPair<KeyT, ValueT> *JL_CMap<KeyT, ValueT>::GetStart() const
{
	return mStart;
}

template <class KeyT, class ValueT> int JL_CMap<KeyT, ValueT>::GetLen() const
{
	return mLength;
}

template <class KeyT, class ValueT> bool JL_CMap<KeyT, ValueT>::ExsitKey(KeyT key) const
{
	JL_CPair<class KeyT, class ValueT> *ptrCache = mStart;
	while (ptrCache)
	{
		if (ptrCache->GetKey() == key)
			return true;
		else
			ptrCache = ptrCache->GetBack();
	}

	return false;
}

template <class KeyT, class ValueT> void JL_CMap<KeyT, ValueT>::Join(KeyT key, ValueT value)
{

}

template <class KeyT, class ValueT> void JL_CMap<KeyT, ValueT>::Insert(int pos, KeyT key, ValueT value)
{

}

template <class KeyT, class ValueT> void JL_CMap<KeyT, ValueT>::SetZero()
{

}

template <class KeyT, class ValueT> void JL_CMap<KeyT, ValueT>::DelByPos(int pos)
{

}

template <class KeyT, class ValueT> void JL_CMap<KeyT, ValueT>::DelByKey(KeyT key)
{

}

template <class KeyT, class ValueT> void JL_CMap<KeyT, ValueT>::DelByVal(ValueT value)
{

}



// JL_CPair implementation

// constructor
template <class KeyT, class ValueT> JL_CPair<KeyT, ValueT>::JL_CPair()
{
	Set(KeyT(0), ValueT(0));
}

template <class KeyT, class ValueT> JL_CPair<KeyT, ValueT>::JL_CPair(KeyT key, ValueT value, JL_CPair<KeyT, ValueT> *fore, JL_CPair<KeyT, ValueT> *back)
{
	Set(key, value, fore, back);
}

// copy constructor
template <class KeyT, class ValueT> JL_CPair<KeyT, ValueT>::JL_CPair(const JL_CPair<KeyT, ValueT> &sour)
{
	Set(sour.mKey, sour.mValue);
}

// destructor
template <class KeyT, class ValueT> JL_CPair<KeyT, ValueT>::~JL_CPair()
{
	mFore = 0;
	mBack = 0;
}

// interfaces
template <class KeyT, class ValueT> void JL_CPair<KeyT, ValueT>::Set(KeyT key, ValueT value, JL_CPair<KeyT, ValueT> *fore, JL_CPair<KeyT, ValueT> *back)
{
	mKey = key;
	mvalue = value;
	mFore = fore;
	mBack = back;
}

template <class KeyT, class ValueT> void JL_CPair<KeyT, ValueT>::SetKey(KeyT key)
{
	mKey = key;
}

template <class KeyT, class ValueT> KeyT JL_CPair<KeyT, ValueT>::GetKey() const
{
	return mKey;
}

template <class KeyT, class ValueT> void JL_CPair<KeyT, ValueT>::SetValue(ValueT value)
{
	mValue = value;
}

template <class KeyT, class ValueT> ValueT JL_CPair<KeyT, ValueT>::GetValue() const
{
	return mValue;
}

template <class KeyT, class ValueT> void JL_CPair<KeyT, ValueT>::SetFore(JL_CPair<KeyT, ValueT> *fore)
{
	mFore = fore;
}

template <class KeyT, class ValueT> JL_CPair<KeyT, ValueT> *JL_CPair<KeyT, ValueT>::GetFore() const
{
	return mFore;
}
template <class KeyT, class ValueT> void JL_CPair<KeyT, ValueT>::SetBack(JL_CPair<KeyT, ValueT> *back)
{
	mBack = back;
}

template <class KeyT, class ValueT> JL_CPair<KeyT, ValueT> *JL_CPair<KeyT, ValueT>::GetBack() const
{
	return mBack;
}