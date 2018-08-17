#ifndef JL_CLOG_H
#define JL_CLOG_H

#include "JL_CString.h"
#include "JL_CDate.h"

// declaration of the class used to record the program logs when running
class JL_CLog
{
public:
	// constructor
	JL_CLog();
	JL_CLog(JL_CString path);

	// copy constructor
	JL_CLog(const JL_CLog &sour);

	// destructor
	~JL_CLog();

	// interfaces
	void SetPath(JL_CString path);// set the path

	JL_CString GetPath() const;// retrieve the path stored
	int GetSize() const;// get the size of log file
	JL_CDate GetTime() const;// get the latest update date

	JL_CString Read();// get the log contents
	void Write(JL_CString log);// log information to the file
	void Clear();// clear the logs
private:
	// internal methods
	void SetSize();// set the size according to the path
	void SetTime();// set the date according to the path

	// attributions
	JL_CString mPath;// store the log path
	int mSize;// store the log size
	JL_CDate mTime;// store the latest update time
};

#endif// JL_CLOG_H