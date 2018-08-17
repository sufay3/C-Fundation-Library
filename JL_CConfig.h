#ifndef JL_CCONFIG_H
#define JL_CCONFIG_H

#include "JL_CString.h"
#include "JL_CMap.h"

// configuration class declaration
class JL_CConfig
{
public:
	// constructor
	JL_CConfig();
	JL_CConfig(JL_CString fileName);

	// copy constructor
	JL_CConfig(const JL_CConfig &sour);

	// destructor
	~JL_CConfig();


	//interfaces
	void AddItem(JL_CString propertyName, JL_CString propertyVal);// add a item to the config map
	void DelItem(JL_CString propertyName);// delete a item from the config map

	void SetPropertyVal(JL_CString propertyName, JL_CString propertyVal);// set a value to given config property
	void AlterPropertyName(JL_CString propertyName, JL_CString newPropertyName);// assign a new value to the given propert name
	JL_CString GetPropertyVal(JL_CString propertyName);// get an expected property value

	void Read();// read all datas in the file to memory managed by this class
	void Store();// store inner config information to the destination file

	void SetFileName(JL_CString fileName); // set a file name with full path to store the configuration datas
	JL_CString GetFileName(); // retrieve the config file name
private:
	// internal methods
	JL_CString BuildStr(JL_CString key, JL_CString value);// turn the map into a string
	void ParseStr(JL_CString configStr);// generate a map from the given string

	// attributions
	JL_CString mFileName;// store the config file name
	JL_CMap<JL_CString, JL_CString> mPropertyMap;// a map structure storing configurations
};

#endif// JL_CCONFIG_H