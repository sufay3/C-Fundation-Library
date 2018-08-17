#ifndef JL_CDATE_H
#define JL_CDATE_H

#include "JL_CString.h"

// a class used to represent and handle a time value with the date
class JL_CDate
{
public:
	// constructor
	JL_CDate();
	JL_CDate(JL_CString dateStr);
	JL_CDate(int year, int month, int day, int hour = 0, int min = 0, int sec = 0, int millSec = 0);

	// copy constructor
	JL_CDate(const JL_CDate &sour);

	// destructor
	~JL_CDate();

	// interfaces
	void SetYear(int year);
	void SetMonth(int month);
	void SetDay(int day);
	void SetHour(int hour);
	void SetMin(int min);
	void SetSec(int sec);
	void SetMillSec(int millSec);

	void SetTimeZone(int timeZone = 8);
	void SetHourForm(int hourForm = 0);
	void SetDateForm(int dateForm = 0);

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	int GetHour() const;
	int GetMin() const;
	int GetSec() const;
	int GetMillSec() const;
	
	int GetTimeZone() const;
	int GetHourForm() const;
	int GetDateForm() const;

	JL_CDate GetDate() const;
	JL_CDate GetTime() const;

	JL_CDate Get12() const;
	JL_CDate Get24() const;
	JL_CDate GetMoon() const;
	JL_CDate GetSun() const;

	int GetDayNum() const;
	int GetWeek() const;

	bool IsYear() const;

	JL_CDate GetCur(int type =0 ) const;
	long GetUnix() const;
	JL_CDate GetGMT() const;
	JL_CString GetStr() const;

	double GetSub(const JL_CDate &date, int type = 0);
protected:
	// internal methods
	JL_CDate TransHour();
	JL_CDate TransDate();
	void ComputeWeek();

	int VerifyYear(int year);
	int VerifyMonth(int month);
	int VerifyDay(int day);
	int VerifyHour(int hour);
	int VerifyMin(int min);
	int VerifySec(int sec);
	int VerifyMillSec(int millSec);
	int VerifyTimeZone(int timeZone);
	int VerifyHourForm(int hourForm);
	int VerifyDateForm(int dateForm);

	int Verify(int value, int down, int up);

	// attributions
	int mYear;
	int mMonth;
	int mDay;
	int mWeek;

	int mHour;
	int mMin;
	int mSec;
	int mMillSec;

	int mTimeZone;
	int mHourForm;
	int mDateForm;
};


// a birthday class which is derived from JL_CDate class
class JL_CBirthday : public JL_CDate
{
public:
	// constructor
	JL_CBirthday();
	JL_CBirthday(int year, int month, int day);

	// copy constructor
	JL_CBirthday(const JL_CBirthday &sour);

	// destructor
	~JL_CBirthday();

	// interfaces
	int GetStar() const;
	int GetBirth() const;
private:
	// internal methods
	void ComputeStar();
	void ComputeBirth();

	// attributions
	int mStar;
	int mBirth;
};

#endif// JL_CDATE_H