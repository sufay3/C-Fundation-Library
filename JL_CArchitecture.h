#ifndef JL_CARCHITECTURE_H
#define JL_CARCHITECTURE_H

// a class intended for global architecture of the entire program
class JL_CArchitecture
{
public:

	// destructor
	~JL_CArchitecture();

	// interfaces
	void MainEntry();// the application entry
	void InitSystem();// initialize the program to be ready to start
	void SubSystem(void* subSysInterface);// callback the specified subsystem interface
	void FreeSystem();// clear resources after the system goes over
private:
	// internal methods
	
	// constructor
	JL_CArchitecture();// private constructor to protect from being called beyond the class self
	JL_CArchitecture();

	// attributions

};

#endif// JL_CARCHITECTURE_H
