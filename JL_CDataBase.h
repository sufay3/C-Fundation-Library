#ifndef JL_CDATABASE_H
#define JL_CDATABASE_H

#include " "

class JL_CDataBase
{
public:
	// constructor
	JL_CDataBase();

	//destructor
	~JL_CDataBase();

	// interfaces
	bool Add();// add a record
	bool Alter();// alter a record
	bool Delete();// delete a record

	bool AddEx();// add multiple records
	bool AlterEx();// alter multiple records
	bool DeleteEx();// delete multiple records

	bool Query();// query datas
	bool SQL();// execute the SQL sentence
private:
	// internal methods
	bool Connect();// connect the data source
	bool Disconnect(); // disconnect the data source
	bool IsConnected();// check if the connection is established
	bool GetRecordSet();// get the existing records

	// attributions
	//CDatabase mDatabase;// a instance of the class named CDatabase
};

#endif// JL_CDATABASE_H