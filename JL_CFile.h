#ifndef JL_CFILE_H
#define JL_CFILE_H

#include "JL_CString.h"

// file class declaration
class JL_CFile
{
public:
	// constructor
	JL_CFile();
	JL_CFile(JL_CString name);

	// copy constructor
	JL_CFile(const JL_CFile &sour);

	// destructor
	~JL_CFile();

	
	// interfaces
	int Open();
	bool Close();

	int GetLen() const;

	JL_CString Read();
	JL_CString Read(int length);
	JL_CString ReadLine();

	void Write(JL_CString datas);
	void WriteLine(JL_CString datas);
private:
	// internal methods
	bool IsOpen();

	// attributions
	JL_CString mName;
	int mHandle;
};

#endif// JL_CFILE_H