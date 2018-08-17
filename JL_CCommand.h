#ifndef JL_CCOMMAND_H
#define JL_CCOMMAND_H

// declaration of the class which is designed to send and parse a command string transfered between a client and a server
class JL_CCommand
{
public:
	// constructor
	JL_CCommand();

	// destructor
	~JL_CCommand();

	// inferfaces
	void SetRule(CString rule);
	CString GetRule();

	void ImportRule(CString fileName);
	void ExportRule(CStrin fileName);

	bool IsCommand(CString str);

	void Add(CString cmd);
	void AddEx(CString[] cmdSet, int cmdNum);
	void Alter(CString newCmd, int pos);
	void Delete(int pos);
	void Clear();
	
	int GetCommandNum();

	CString[] GetAllExecuted();
	CString GetLastExecuted();

	void SendCommand();
	void ParseCommand();
	void HandleCommand();

	void BeginTransaction();
	void SubmitTransaction();
private:
	// internal methods
	void JoinTransQueue(int cmdPos);
	void RollBack(int cmdPos);

	// attributions
	CString mCmdRule;
	int mCommandNum;
	CString mCommandArray[mCommandNum];
};

#endif// JL_CCOMMAND_H