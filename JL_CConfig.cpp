// JL_CConfig implementation

#include "JL_CConfig.h"
#include "JL_CFile.h"

// constructor
JL_CConfig::JL_CConfig() : mFileName(""), mPropertyMap()
{
	
}

JL_CConfig::JL_CConfig(JL_CString fileName) : mFileName(fileName), mPropertyMap()
{

}

// copy consturctor
JL_CConfig::JL_CConfig(const JL_CConfig &sour)
{
	mFileName = sour.mFileName;
	mPropertyMap = sour.mPropertyMap;
}

// destructor
JL_CConfig::~JL_CConfig()
{
	// no resource to relieve. The system will destroy member object itself.
}


// interfaces
void JL_CConfig::AddItem(JL_CString propertyName, JL_CString propertyVal)
{
	mPropertyMap.Join(propertyName, propertyVal);
}

void JL_CConfig::DelItem(JL_CString propertyName)
{
	mPropertyMap.DelByKey(propertyName);
}

void JL_CConfig::SetPropertyVal(JL_CString propertyName, JL_CString propertyVal)
{
	mPropertyMap.SetValue(propertyName, propertyVal);
}

void JL_CConfig::AlterPropertyName(JL_CString propertyName, JL_CString newPropertyName)
{
	mPropertyMap.AlterKey(propertyName, newPropertyName);
}

JL_CString JL_CConfig::GetPropertyVal(JL_CString propertyName)
{
	return mPropertyMap.GetValue(propertyName);
}

void JL_CConfig::Read()
{
	JL_CFile config(mFileName);
	ParseStr(config.ReadLine());
}

void JL_CConfig::Store()
{
	JL_CFile config(mFileName);

	for (int count = 0; count < mPropertyMap.GetLen(); count++)
		config.WriteLine(BuildStr(mPropertyMap.GetKeyByIndex(count), mPropertyMap.GetValueByIndex(count)));
}

void JL_CConfig::SetFileName(JL_CString fileName)
{
	mFileName = fileName;
}

JL_CString JL_CConfig::GetFileName()
{
	return mFileName;
}


// internal methods
JL_CString JL_CConfig::BuildStr(JL_CString key, JL_CString value)
{
	return ("\"" + key + "\" = \"" + value + "\"");
}

void JL_CConfig::ParseStr(JL_CString configStr)
{

}