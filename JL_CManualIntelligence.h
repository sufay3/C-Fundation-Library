#ifndef JL_CMANUALINTELLIGENCE_H
#define JL_CMANUALINTELLIGENCE_H

#include "JL_CString.h"
#include "JL_CArray.h"
#include "JL_CMap.h"

// declaration for the class which will perform the manual intelligence
class JL_CManualIntelligence
{
public:
	// constructor
	JL_CManualIntelligence(){ mIndexLibPath = ""; }

	// copy constructor
	JL_CManualIntelligence(const JL_CManualIntelligence &sour);

	// destructor
	~JL_CManualIntelligence(){}

	// interfaces
	void AutoResponse(JL_CString sentence, void (*resHandle)(JL_CString res));
	JL_CArray<JL_CString> SentenceAnalyze(JL_CString sentence);
	void ConstituteIndexLib(JL_CString sourceDatas);

	virtual void SyntaxAnalyze(JL_CString stream)
	{
		// realized by child classes
	}

	void AddIndex(JL_CString keyword, JL_CString response);
	void DeleteIndex(JL_CString keyword);
	void ClearIndexLib();
	
	void SetIndexLibPath(JL_CString indexLibPath);// set the path of the index library
	JL_CString GetIndexLibPath();// get the index library location

	virtual void ImportIndexLib();
	virtual void ExportIndexLib();
private:
	// attributions
	JL_CMap<JL_CString, JL_CString> mIndexLib; // a map including index datas
	JL_CString mIndexLibPath;// store the index library path
};

#endif// JL_CMANUALINTELLIGENCE_H