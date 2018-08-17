#ifndef JL_CARRAY_H
#define JL_CARRAY_H

#include "JL_CString.h"

// declaration of a template class. It builds instances handling a array
template <class T>
class JL_CArray
{
public:
	// constructor
	JL_CArray();
	JL_CArray(int maxLen);

	// copy constructor
	JL_CArray(const JL_CArray<T> &sour);

	// destructor
	~JL_CArray();

	//overload operator "[]"
	T operator[](int pos) const; 

	// interfaces
	int GetCurLen() const;// get the current length value
	int GetMaxLen() const;// get the capacity
	T GetAt(int pos) const;// return a value indexed by the parameter

	void Resize(int newLen, int reserveTag = 1);// change the array size. Elements may be droped
	int Append(T value);// add a element to the end. In the meantime, array size will be increased
	int Insert(int pos, T value);// put a value into the specified position, with new memory allocated
	void Delete(int pos);// delete the value in the specified position. Size will be cut
	void Clear();// resize to zero element

	void AppendEx(const JL_CArray<T>& arr);// add a array of the same type to the end
	void BatAssign(T value);// Assign a given value to all elements

	int Search(T value) const;// search for the given value and return the index found out in the first time
	void Sort(int sortType = 0);// sort the array according to the designated method by the parameter
	JL_CString Join(JL_CString splitSym) const;// join every element to a new string only if the type is "JL_CString"
	void Filter(T value, int reserveTag = 0);// filter the array
	void FilterEx();// filter the same value
private:
	// internal methods
	void Copy(const JL_CArray<T> &sour);// copy the source datas to the current object
	void Alloc(int len);// resize the memory capacity
	
	// attributions
	T *mStart;
	int mCurLen;
	int mMaxLen = 100;
};

#endif// JL_CARRAY_H