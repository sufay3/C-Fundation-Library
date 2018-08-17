#ifndef JL_CSTRING_H
#define JL_CSTRING_H

#include "JL_CArray.h"

class JL_CString
{
public:
	// constructor
	JL_CString();
	JL_CString(const char *str);

	// copy constructor
	JL_CString(const JL_CString &sour);

	// destructor
	~JL_CString();

	// overload operators
	void operator=(const char *str);
	void operator+=(const JL_CString &str);

	bool operator==(const JL_CString &str) const;
	bool operator<(const JL_CString &str) const;
	bool operator<=(const JL_CString &str) const;
	bool operator>(const JL_CString &str) const;
	bool operator>=(const JL_CString &str) const;

	char &operator[](int pos);
	char operator[](int pos) const;
	JL_CString operator+(const JL_CString &str);
	
	// inferfaces
	int GetLength() const;
	static int GetLength(const char *str);
	bool IsEmpty() const;

	int Compare(const JL_CString &str) const;
	void Append(const JL_CString &str);
	JL_CString Contact(const JL_CString &str) const;
	void SetZero();
	
	int FindSub(const JL_CString &subStr, int mode = 0) const;
	int ReFindSub(const JL_CString &subStr, int mode = 0) const;
	int GetSubNum(const JL_CString &subStr, int mode = 0) const;
	void Substitute(const JL_CString &str, const JL_CString &sub, int mode = 0);

	JL_CString GetSub(int startPos, int length) const;
	JL_CString Parse(const JL_CString &firstTag, const JL_CString &secondTag) const;
	
	char GetChar(int pos) const;
	void SetChar(int pos, const char &c);
	int GetAsc(int pos) const;

	void Reverse();
	void Upper();
	void Lower();

	JL_CArray<JL_CString> Split(const JL_CString &splitSym) const;
private:
	// internal methods
	void Copy(const char *sour);

	void Alloc(int len);
	void Free();

	// attributions
	char *mStartPtr;
	int mLength;
};

#endif// JL_CSTRING_H