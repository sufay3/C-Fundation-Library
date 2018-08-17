#ifndef JL_CQUEUE_H
#define JL_CQUEUE_H

#include "JL_CEnd.h"

// a data structure used to manipulate the queue model
template <class T>
class JL_CQueue
{
public:
	// constructor
	JL_CQueue();

	// copy constructor
	JL_CQueue(const JL_CQueue<T> &sour);

	// destructor
	~JL_CQueue();

	// interfaces
	void Join(const T &value);
	T MoveFirst();
	void Clear();

	int GetLen() const;
private:
	// attributions
	JL_CEnd<T> *mFirst;
	int mLength;
};

#endif// JL_CQUEUE_H