// JL_CManualIntelligence implementation

#include "JL_CManualIntelligence.h"

// copy constructor
JL_CManualIntelligence::JL_CManualIntelligence(const JL_CManualIntelligence &sour)
{
	mIndexLib = sour.mIndexLib;
	mIndexLibPath = "";
}

void JL_CManualIntelligence::AutoResponse(JL_CString sentence, void (*resHandle)(JL_CString res))
{
	JL_CArray<JL_CString> keyList = SentenceAnalyze(sentence);

	if (keyList.GetLen() > 0)
		resHandle(mIndexLib.GetValue(keyList[0]));
}

JL_CArray<JL_CString> JL_CManualIntelligence::SentenceAnalyze(JL_CString sentence)
{
	JL_CArray<JL_CString> keyList;

	JL_CPair<JL_CString, JL_CString> *ptrCache = mIndexLib.GetStart();
	JL_CString key;
	while (ptrCache)
	{
		key = ptrCache->GetKey();
		if (sentence.FindSub(key) >= 0)
			keyList.Append(key);
		else
			ptrCache = ptrCache->GetBack();
	}

	return keyList;
}

void JL_CManualIntelligence::ConstituteIndexLib(JL_CString sourceDatas)
{

}

void JL_CManualIntelligence::AddIndex(JL_CString keyword, JL_CString response)
{
	mIndexLib.Join(keyword, response);
}

void JL_CManualIntelligence::DeleteIndex(JL_CString keyword)
{
	mIndexLib.DelByKey(keyword);
}

void JL_CManualIntelligence::ClearIndexLib()
{
	mIndexLib.SetZero();
}

void JL_CManualIntelligence::SetIndexLibPath(JL_CString indexLibPath)
{
	mIndexLibPath = indexLibPath;
}

JL_CString JL_CManualIntelligence::GetIndexLibPath()
{
	return mIndexLibPath;
}

void JL_CManualIntelligence::ImportIndexLib()
{

}

void JL_CManualIntelligence::ExportIndexLib()
{

}