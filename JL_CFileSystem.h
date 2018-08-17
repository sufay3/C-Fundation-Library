#ifndef JL_CFILESYSTEM_H
#define JL_CFILESYSTEM_H

#include <cstring>

// a class declaration which is intended to operate file system 
class JL_CFileSystem
{
public:
	// constructor
	JL_CFileSystem();

	// destructor
	~JL_CFileSystem();

	// inferfaces
	void CreateFile(CString fileFullName);
	void CreateFileEx(CString[] fileNameSet);
	void RemoveFile(CString fileFullName);
	void RemoveFileEx(CString[] fileNameSet);
	void RenameFile(CString oldFileName, CString newFileName);
	void RenameFileEx(CString[] oldFileNameSet, CString newFileName, int[] index);

	bool FileExsits(CString fileName);

	int FindFile(CString fileName);
	int FindFileEx(CString[] fileNameSet);
	int FindFileByKey(CString key);
	int FindFileByKeyEx(CString[] keySet);
	int FindFileByType(CString typeName);
	int FindFileByTypeEx(CString[] typeSet);
	int FindFileBySize(int size, int mode);
	int FindFileByDate(CDate fileDate, int mode);

	void SetFileAttributes();
	void GetFileAttributes();

	int GetFileType(CString fileName);
	int GetFileSize(CString fileName);
	int GetFileDate(CString fileName);

	CString GetFilePath(CString fileName);
	int GetFileNum(int typeName);
	int GetFileNum(CString directoryName);

	CString[] GetRecentFiles();

	void CreateDirectory(CString directoryName);
	void CreateDirectoryEx(CString[] directorySet);
	void RemoveDirectory(CString derectoryName);
	void RemoveDirectoryEx(CString[] directorySet);
	void RenameDirectory(CString oldDirectoryName, CString newDirectoryName);
	void RenameDirectoryEx(CString[] oldDirectorySet, CString newDirectoryName, int[] index);
	
	bool DirectoryExits(CString directoryName);

	void FindDirectory(CString directoryName);
	int FindDirectoryEx(CString[] directorySet);
	int FindDirectoryByKey(CString key);
	int FindDirectoryByKeyEx(CString[] keySet);
	int FindDirectoryByFileNum(int fileNum, int mode);
	int FindDirectoryBySize(int size, int mode);
	int FindDirectoryByDate(CDate directoryDate, int mode);
	
	void SetDirectoryAttributes();
	void GetDirectoryAttributes();

	int GetDirectorySize(CString directoryName);
	int GetDirectoryDate(CString directoryName);

	int GetDirectoryNum();
	int GetDirectoryNum(CString directoryName);

	CString GetCurrentDirectory();
	void ListAll(CString directoryName, int mode);
};

#endif// JL_CCOMMAND_H