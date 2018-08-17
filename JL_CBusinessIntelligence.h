#ifndef JL_CBUSINESSINTELLIGENCE_H
#define JL_CBUSINESSINTELLIGENCE_H

// declaration for the class which will perform the business intelligence
class JL_CBusinessIntelligence
{
public:
	// constructor
	JL_CBusinessIntelligence();

	// destructor
	~JL_CBusinessIntelligence();

	// inferfaces
	void SetDataSource(CString ds);
	CString GetDataSource();

	void SetRule(CString rule);
	CString GetRule();

	void Analyze();
	void Statistics();
	void DigData();
	void ExecuteRule();
private:
	// internal methods
	void ParseRule(CString rule);

	// attributions
	CString mDataSource;
	CString mRule;
};

#endif// JL_CBUSINESSINTELLIGENCE_H