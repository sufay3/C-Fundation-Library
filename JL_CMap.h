#ifndef JL_CMAP_H
#define JL_CMAP_H

// foreward reference
template <class KeyT, class ValueT> class JL_CPair;

// declaration for a mapping structure
template <class KeyT, class ValueT>
class JL_CMap
{
public:
	// constructor
	JL_CMap();

	// copy constructor
	JL_CMap(const JL_CMap &sour);

	// destructor
	~JL_CMap();

	// overload operators
	ValueT operator[](KeyT key) const;

	// inferfaces
	ValueT GetValue(KeyT key) const;
	ValueT GetValueByIndex(int keyIndex) const;
	KeyT GetKey(ValueT value) const;
	KeyT GetKeyByIndex(int keyIndex) const;
	int GetIndex(KeyT key) const;
	int GetIndexByValue(ValueT value) const;

	void SetValue(KeyT key, ValueT newValue);
	void SetKey(ValueT value, KeyT newKey);
	void AlterKey(KeyT key, KeyT newKey);

	JL_CPair<KeyT, ValueT> *GetStart() const;
	int GetLen() const;
	bool ExsitKey(KeyT key) const;

	void Join(KeyT key, ValueT value);
	void Insert(int pos, KeyT key, ValueT value);

	void SetZero();
	void DelByPos(int pos);
	void DelByKey(KeyT key);
	void DelByVal(ValueT value);
private:
	// attributions
	JL_CPair<KeyT, ValueT> *mStart;
	int mLength;
};

template <class KeyT, class ValueT>
class JL_CPair
{
public:
	// constructor
	JL_CPair();
	JL_CPair(KeyT key, ValueT value, JL_CPair<KeyT, ValueT> *fore = 0, JL_CPair<KeyT, ValueT> *back = 0);

	// copy constructor
	JL_CPair(const JL_CPair<KeyT, ValueT> &sour);

	// destructor
	~JL_CPair();

	// interfaces
	void Set(KeyT key, ValueT value, JL_CPair<KeyT, ValueT> *fore = 0, JL_CPair<KeyT, ValueT> *back = 0);

	void SetKey(KeyT key);
	KeyT GetKey() const;

	void SetValue(ValueT value);
	ValueT GetValue() const;

	void SetFore(JL_CPair<KeyT, ValueT> *fore);
	JL_CPair<KeyT, ValueT> *GetFore() const;

	void SetBack(JL_CPair<KeyT, ValueT> *back);
	JL_CPair<KeyT, ValueT> *GetBack() const;
private:
	// attributions
	KeyT mKey;
	ValueT mValue;
	JL_CPair<KeyT, ValueT> *mFore;
	JL_CPair<KeyT, ValueT> *mBack;
};

#endif// JL_CMAP_H
