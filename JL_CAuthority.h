#ifndef JL_CAUTHORITY_H
#define JL_CAUTHORITY_H

#include "JL_CString.h"
#include "JL_CDate.h"
#include "JL_CArray.h"

// declare a class whose duty is to manage authority of the program
class JL_CAuthority
{
public:
	// constructor
	JL_CAuthority();

	// copy constructor
	JL_CAuthority(const JL_CAuthority &sour);

	// destructor
	~JL_CAuthority();

	// interfaces
	void GenAuthFile();// generate a local file consisting of some authority infomation
	bool IsExpired();// check if authority is expired

	void SetMachineCode(JL_CString machineCode);// set the machine code
	void SetExpirationDate(JL_CDate date);// set a value to the member attribution mExpirationDate
	void SetAuthFileName(JL_CString fileName);// set the file name storing authority datas

	JL_CString GetMachineCode();// retrieve a string identifing a unique computer
private:
	// internal methods
	void GenMachineCode();// get the machine code of some computer
	void GenFeature();// generate a array with three feature strings
	bool IsValidFile();// check if the authority file is valid
	void ExtractFeature(JL_CArray<JL_CString> &feature);// extract feature values from a file with authority datas
	JL_CDate GetExpirationDate();// get the expiration time
	
	// attributions
	JL_CString mMachineCode; // store the machine code
	JL_CDate mExpirationDate;// store the expiration date
	JL_CString mAuthFileName;// store a path of the authority file
	JL_CArray<JL_CString> mFeature;// store the features
};

#endif// JL_CAUTHORITY_H
