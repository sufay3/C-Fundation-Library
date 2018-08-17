#ifndef JL_CUPDATE_H
#define JL_CUPDATE_H

#include "JL_CString.h"

// a client class used to update the application program when it has a new version
class JL_CUpdateC
{
public:
	// constructor
	JL_CUpdateC();
	JL_CUpdateC(JL_CString addrStr, JL_CString ver, JL_CString path);

	// destructor
	~JL_CUpdateC();

	// interfaces
	void SetServerAddr(JL_CString addrStr);// assign a IP address with a port to specified member attribution. The address represents a server supplying updating
	void SetCurrentVer(JL_CString ver);// set current edition of the software
	void SetLocalPath(JL_CString path);// set a download path used to cache the new edition

	JL_CString GetServerAddr() const;// retrieve the server address
	JL_CString GetCurrentVer() const;// retrieve the current version
	JL_CString GetLocalPath() const;//  retrieve the local path

	bool HasNewVer();// detect whether a newer version exists
	void DownloadUpdated();// download the updated file to local computer
	void InstallUpdated(); // install updated program
private:
	// attributions
	JL_CString mServerAddr;// store a server location
	JL_CString mCurrentVer;// store a version value
	JL_CString mLocalPath;// store a download path
};

#endif// JL_CUPDATE_H