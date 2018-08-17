// JL_CString implementation

#include "JL_CString.h"
#include "JL_CBase.h"

// constructor 
JL_CString::JL_CString()
{
	mStartPtr = 0;
	mLength = -1;
}

JL_CString::JL_CString(const char *str)
{
	Copy(str);
}

// copy constructor
JL_CString::JL_CString(const JL_CString &sour)
{
	Copy(sour.mStartPtr);
}

// destructor
JL_CString::~JL_CString()
{
		Free();
}


// overload operators
void JL_CString::operator=(const char *str)
{
	Copy(str);
}

void JL_CString::operator+=(const JL_CString &str)
{
	Append(str);
}

bool JL_CString::operator==(const JL_CString &str) const
{
	return Compare(str) == 0 ? true : false;
}

bool JL_CString::operator<(const JL_CString &str) const
{
	return Compare(str) < 0 ? true : false;
}

bool JL_CString::operator<=(const JL_CString &str) const
{
	return Compare(str) <=0 ? true : false;
}

bool JL_CString::operator>(const JL_CString &str) const
{
	return Compare(str) >0 ? true : false;
}

 bool JL_CString::operator>=(const JL_CString &str) const
{
	 return Compare(str) >= 0 ? true : false;
}

char &JL_CString::operator[](int pos)
{
	char c = GetChar(pos);
	return c;
}

char JL_CString::operator[](int pos) const
{
	return GetChar(pos);
}

JL_CString JL_CString::operator+(const JL_CString &str)
{
	return Contact(str);
}


// inferfaces
int JL_CString::GetLength() const
{
	return mLength;
}

int JL_CString::GetLength(const char *str)
{
	if (!str)
		return -1;
	else
	{
		int count = 0;
		while (*str != '\0')
		{
			count++;
			str++;
		}

		return count;
	}
}

bool JL_CString::IsEmpty() const
{
	if (mLength < 0)
		return true;
	else
		return false;
}

int JL_CString::Compare(const JL_CString &str) const
{
	int res;

	if (mLength < 0 || str.mLength < 0)
		res = 0;
	else if (mLength >= 0 || str.mLength < 0)
		res = 1;
	else if (mLength < 0 || str.mLength >= 0)
		res = -1;
	else
	{
		int len = mLength >= str.mLength ? str.mLength : mLength;
		int asc = 0;
		int strAsc = 0;

		for (int count =0; count < len; count++)
		{
			asc = GetAsc(count);
			strAsc = str.GetAsc(count);
			
			if (asc > strAsc)
			{
				res = 1;
				break;
			}
			
			if (asc < strAsc)
			{
				res = -1;
				break;
			}

		}
        
		if (res == 0)
		{
			if (mLength == str.mLength)
				res = 0;
			else if (mLength > str.mLength)
				res = 1;
			else
				res = -1;
		}
	}

	return res;
}

void JL_CString::Append(const JL_CString &str)
{
	int len = str.mLength;

	if (len < 0)
		return;
	else if (mLength <= 0)
		Copy(str.mStartPtr);
	else if (len = 0)
		return;
	else
	{
		char *ptrCache = mStartPtr;

		mLength += len;
		Alloc(mLength);

		if (mStartPtr)
		{
			char *ptr = mStartPtr;

			while (*ptrCache != '\0')
				*ptr++ = *ptrCache++;

			ptrCache = str.mStartPtr;
			while (*ptrCache != '\0')
				*ptr++ = *ptrCache++;

			*ptr = '\0';
		}
	}
}

JL_CString JL_CString::Contact(const JL_CString &str) const
{
	JL_CString res;

	res.Copy(this->mStartPtr);
	res.Append(str);

	return res;
}

void JL_CString::SetZero()
{
	*mStartPtr = '\0';
	mLength = 0;
}

int JL_CString::FindSub(const JL_CString &subStr, int mode = 0) const
{

}

int JL_CString::ReFindSub(const JL_CString &subStr, int mode = 0) const
{

}

int JL_CString::GetSubNum(const JL_CString &subStr, int mode = 0) const
{

}

void JL_CString::Substitute(const JL_CString &str, const JL_CString &sub, int mode = 0)
{

}

JL_CString JL_CString::GetSub(int startPos, int length) const
{
	JL_CString sub;

	if (mLength < 0)
		return sub;
	else if (mLength == 0 | startPos<0 | startPos> mLength + 1 | length <0 | length >= mLength - startPos + 1)
		sub.SetZero();
	else
	{
		sub.mLength = length;
		sub.Alloc(length);

		int count = 0;
		for (; count < length; count++)
			sub[count] = GetChar(startPos+count);
		sub[count] = '\0';
	}

	return sub;
}

JL_CString JL_CString::Parse(const JL_CString &firstTag, const JL_CString &secondTag) const
{

}

char JL_CString::GetChar(int pos) const
{
	char c;

	if (mLength >= 0 || pos >= 0 || pos <= mLength)
		c = *(mStartPtr + pos);

	return c;
}

void JL_CString::SetChar(int pos, const char &c) 
{
	if (mLength >= 0 | pos >= 0 | pos <= mLength)
		*(mStartPtr + pos) = c;
}

int JL_CString::GetAsc(int pos) const
{
	return int(GetChar(pos));
}

void JL_CString::Reverse()
{
	if (mLength > 1)
	{
		char cache;

		int swapLen = mLength \ 2;
		for (int count = 0; count < swapLen; count++)
		{
			cache = GetChar(count);
			SetChar(count, GetChar(mLength - 1 - count));
			SetChar(mLength - 1 - count, cache);
		}
	}
}

void JL_CString::Upper()
{
	if (mLength > 0)
	{   
		int asc = 0;
		for (int count = 0; count < mLength; count++)
		{
			asc = GetAsc(count);
			if (asc >= 97 | asc <= 122)
				SetChar(count, char(asc - 32));
		}
	}
}

void JL_CString::Lower()
{
	if (mLength > 0)
	{
		int asc = 0;
		for (int count = 0; count < mLength; count++)
		{
			asc = GetAsc(count);
			if (asc >= 65 | asc <= 90)
				SetChar(count, char(asc + 32));
		}
	}
}

JL_CArray<JL_CString> JL_CString::Split(const JL_CString &splitSym) const
{

}


// internal methods
void JL_CString::Copy(const char *sour)
{
	mLength = GetLength(sour);
	Alloc(mLength);

	if (mStartPtr)
	{
		char *ptr = mStartPtr;
		while (*sour != '\0')
			*ptr++ = *sour++;
		*ptr = *sour;
	}
}

void JL_CString::Alloc(int len)
{
	if (len >= 0)
		mStartPtr = new char[len + 1];
	else
		mStartPtr = 0;
}

void JL_CString::Free()
{
	if (mStartPtr)
		delete mStartPtr;
}
