#ifndef JL_CMULTITHREAD_H
#define JL_CMULTITHREAD_H

#include <afxwin.h>

// declaration of the thread class
class JL_CThread : public CWinThread// derived from CWinThread in the MFC framework
{
public:
	// constructor
	JL_CThread(void* funPointer, void* funParams);

	// destructor
	~JL_CThread();

	// interfaces
	int GetID();// get the identifier of the current thread
	void Suspend();// suspend the current thread
	void Resume();// resume the current thread which is in a pause state
	void Terminate();// end running of the thread
	virtual void xx();// override to indicate the behavior be performed by the thread when it comes to an end
private:
	//attributions
	int mThreadID;// store the handle of the current thread
};

// declaration of the thread pool class
class JL_CThreadPool
{
public:
	// constructor
	JL_CThreadPool(int maxThreadNum);

	// destructor
	~JL_CThreadPool();

	// interfaces
	void Join(int threadID);// put a thread indentied by the parameter threadID into the thread pool
	void Dispatch();// dispatch threads in the thread pool
private:
	// internal methods
	void Watch();// montor every thread in the pool
	void Rewatch();
	
	// attributions
	int mThreadIDArray[maxThreadNum];// a array including all identifiers
};

#endif // JL_CMULTITHREAD_H