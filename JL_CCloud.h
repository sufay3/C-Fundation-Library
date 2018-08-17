#ifndef JL_CCLOUD_H
#define JL_CCLOUD_H

// the cloud computing component
class JL_CCloud
{
public:
	// constructor
	JL_CCloud();

	// destructor
	~JL_CCloud();

	// interfaces
	void Initialize();// initialization of client
	void Distribute(int taskID, void* computingInterface);// deliver a task to an unit interface which is idle
	void IndexIdle();// list all idle units 

	void StoreDatas(CString datas, JL_CDataCenter sc);// store information to data center
	void BackupDatas(JL_CDataBase cd, JL_CDataCenter rc);// backup information to a data server specialy used to restore datas
private:
	// internal methods
	void LoadBalance();// lead an access to a unit of less pressure
	void* FindIdle();// fint out first idle end

	// attributions
	CString mUnitNum;
	CString mUnitList[maxUnitsNum];
};

#endif// JL_CCLOUD_H