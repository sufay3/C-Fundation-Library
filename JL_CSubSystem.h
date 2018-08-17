#ifndef JL_SUBSYSTEM_H
#define JL_SUBSYSTEM_H

class JL_CSubSystem
{
public:
	// constructor
	JL_CSubSystem();

	// destructor
	~JL_CSubSystem();

	// inferfaces
	void LogicalBusiness();// key business entry
private:
	// internal methods
	void JoinSubSystem();// add a logical process to the subsystem
};

#endif// JL_SUBSYSTEM_H