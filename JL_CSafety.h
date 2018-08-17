#ifndef JL_CSAFETY_H
#define JL_CSAFETY_H

class JL_CSafety
{
public:
	// constructor
	JL_CSafety();

	// destructor
	~JL_CSafety();

	// inferfaces
	CString GenSafetyParameter();// generate an argument which decides the program's safety status
	CString GetSafetyParameter();// retrieve the secure parameter
	
	bool DetectSafetyState();// be sure that the application is running in a common state
	bool Fix();// fix the program when a danger is encountered
private:
	// attributions
	CString mSafetyParameter;// store the safety parameter
};

#endif// JL_CSAFETY_H