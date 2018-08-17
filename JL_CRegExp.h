#ifndef JL_CREGEXP_H
#define JL_CREGEXP_H

#include <atlstr.h>

// declaration of the class used to implementation regular expression
class JL_CRegExp
{
public:
	// constructor
	JL_CRegExp(CString& regExp);

	// destructor
	~JL_CRegExp();

	// interfaces
	bool Conform(CString exp);// check if a given expression conforms to the regularity
	int FindFirst(CString source);// retrieve the first position in which the sub-string conforms to the regular expression
	CString Replace(CString source, CString sub, int& subNum);// replace all sub-strings according to the regular expression with the parameter sub
private:
	// attributions
	CString mRegExp;// store the regular expression
};

#endif// JL_CREGEXP_H