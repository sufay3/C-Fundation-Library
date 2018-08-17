#ifndef JL_CEND_H
#define JL_CEND_H

// an end class which will be the junction of a queue or stack structure
template <class T>
class JL_CEnd
{
public:
	// constructor
	JL_CEnd();
	JL_CEnd(const T &value);

	// copy constructor
	JL_CEnd(const JL_CEnd<T> &sour);

	// destructor
	~JL_CEnd();

	// interfaces
	void SetValue(const T &value);
	void SetPtr(const JL_CEnd<T> *end);

	T GetValue() const;
	JL_CEnd<T> *GetPtr() const;
private:
	// attributions
	T mValue;
	JL_CEnd<T> *mPtr;
};

#endif// JL_CEND_H