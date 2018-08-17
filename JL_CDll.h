#ifndef JL_CDLL_H
#define JL_CDLL_H

#include "JL_CString.h"

// a class declaration to handle the operations related to dll
class JL_CDll
{
public:
	// constructor
	JL_CDll();
	JL_CDll(JL_CString dllName);

	// destructor
	~JL_CDll();

	// interfaces
	void Load(JL_CString dllName);
	void Free();

	int GetHandle() const;
	
	void *GetAddress(JL_CString procedureName);
	void Call(JL_CString procedureName, JL_CString args, JL_CString output);
private:
	// copy constructor
	JL_CDll(const JL_CDll &sour);

	// attributions
	int handle;
};

#endif// JL_CDLL_H