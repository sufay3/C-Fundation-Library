// JL_CDate and JL_CBirthday implementation

#include "JL_CDate.h"

// JL_CDate implementation

// constructor
JL_CDate::JL_CDate()
{
	mYear = 1900;
	mMonth = 1;
	mDay = 1;
	
	mHour = 0;
	mMin = 0;
	mSec = 0;
	mMillSec = 0;

	mTimeZone = 8;
	mHourForm = 0;
	mDateForm = 0;

	ComputeWeek();
}

JL_CDate::JL_CDate(JL_CString dateStr)
{

}

JL_CDate::JL_CDate(int year, int month, int day, int hour, int min, int sec, int millSec)
{
	SetYear(year);
	SetMonth(month);
	SetDay(day);

	SetHour(hour);
	SetMin(min);
	SetSec(sec);
	SetMillSec(millSec);

	mTimeZone = 8;
	mHourForm = 0;
	mDateForm = 0;

	ComputeWeek();
}

// copy constructor
JL_CDate::JL_CDate(const JL_CDate &sour)
{
	mYear = sour.mYear;
	mMonth = sour.mMonth;
	mDay = sour.mDay;

	mHour = sour.mHour;
	mMin = sour.mMin;
	mSec = sour.mSec;
	mMillSec = sour.mMillSec;

	mTimeZone = sour.mTimeZone;
	mHourForm = sour.mHourForm;
	mDateForm = sour.mDateForm;

	mWeek = sour.mWeek;
}

// destructor
JL_CDate::~JL_CDate()
{

}

// interfaces
void JL_CDate::SetYear(int year)
{
	mYear =VerifyYear(year);
}

void JL_CDate::SetMonth(int month)
{
	mMonth = VerifyMonth(month);
}

void JL_CDate::SetDay(int day)
{
	mDay = VerifyDay(day);
}

void JL_CDate::SetHour(int hour)
{
	mHour = VerifyHour(hour);
}

void JL_CDate::SetMin(int min)
{
	mMin = VerifyMin(min);
}

void JL_CDate::SetSec(int sec)
{
	mSec = VerifySec(sec);
}

void JL_CDate::SetMillSec(int millSec)
{
	mMillSec = VerifyMillSec(millSec);
}

void JL_CDate::SetTimeZone(int timeZone)
{
	mTimeZone = VerifyTimeZone(timeZone);
}

void JL_CDate::SetHourForm(int hourForm)
{
	mHourForm = VerifyHourForm(hourForm);
}

void JL_CDate::SetDateForm(int dateForm)
{
	mDateForm = VerifyDateForm(dateForm);
}

int JL_CDate::GetYear() const
{
	return mYear;
}

int JL_CDate::GetMonth() const
{
	return mMonth;
}

int JL_CDate::GetDay() const
{
	return mDay;
}

int JL_CDate::GetHour() const
{
	return mHour;
}

int JL_CDate::GetMin() const
{
	return mMin;
}

int JL_CDate::GetSec() const
{
	return mSec;
}

int JL_CDate::GetMillSec() const
{
	return mMillSec;
}

int JL_CDate::GetTimeZone() const
{
	return mTimeZone;
}

int JL_CDate::GetHourForm() const
{
	return mHourForm;
}

int JL_CDate::GetDateForm() const
{
	return mDateForm;
}

JL_CDate JL_CDate::GetDate() const
{

}

JL_CDate JL_CDate::GetTime() const
{

}

JL_CDate JL_CDate::Get12() const
{

}

JL_CDate JL_CDate::Get24() const
{

}

JL_CDate JL_CDate::GetMoon() const
{

}

JL_CDate JL_CDate::GetSun() const
{

}

int JL_CDate::GetDayNum() const
{

}

int JL_CDate::GetWeek() const
{
	return mWeek;
}

bool JL_CDate::IsYear() const
{

}

JL_CDate JL_CDate::GetCur(int type) const
{

}

long JL_CDate::GetUnix() const
{

}

JL_CDate JL_CDate::GetGMT() const
{

}

JL_CString JL_CDate::GetStr() const
{

}

double JL_CDate::GetSub(const JL_CDate &date, int type)
{

}

// internal methods
JL_CDate JL_CDate::TransHour()
{

}

JL_CDate JL_CDate::TransDate()
{

}

int JL_CDate::VerifyYear(int year)
{
	return (Verify(year, 1900, 2099));
}

int JL_CDate::VerifyMonth(int month)
{
	return(Verify(month, 1, 12));
}

int JL_CDate::VerifyDay(int day)
{
	return (Verify(day, 1, 31));
}

int JL_CDate::VerifyHour(int hour)
{
	return (Verify(hour, 0, 23));
}

int JL_CDate::VerifyMin(int min)
{
	return (Verify(min, 0, 59));
}

int JL_CDate::VerifySec(int sec)
{
	return (Verify(sec, 0, 59));
}

int JL_CDate::VerifyMillSec(int millSec)
{
	return (Verify(millSec, 0, 999));
}

int JL_CDate::VerifyTimeZone(int timeZone)
{
	return (Verify(timeZone, -12, 11));
}

int JL_CDate::VerifyHourForm(int hourForm)
{
	return (Verify(hourForm, 0, 1));
}

int JL_CDate::VerifyDateForm(int dateForm)
{
	return (Verify(dateForm, 0, 1));
}

int JL_CDate::Verify(int value, int down, int up)
{
	if (value < down)
		value = down;
	else
	{
		if (value > up)
			value = up;
	}

	return value;
}


// JL_CBirthday implementation

// constructor
JL_CBirthday::JL_CBirthday()
{
	ComputeStar();
	ComputeBirth();
}

JL_CBirthday::JL_CBirthday(int year, int month, int day) : JL_CDate(year, month, day)
{
	ComputeStar();
	ComputeBirth();
}

// copy constructor
JL_CBirthday::JL_CBirthday(const JL_CBirthday &sour)
{
	mYear = sour.mYear;
	mMonth = sour.mMonth;
	mDay = sour.mDay;
	mDateForm = sour.mDateForm;

	mStar = sour.mStar;
	mBirth = sour.mBirth;
}

// destructor
JL_CBirthday::~JL_CBirthday()
{

}

// interfaces
int JL_CBirthday::GetStar() const
{
	return mStar;
}

int JL_CBirthday::GetBirth() const
{
	return mBirth;
}


// internal methods
void JL_CBirthday::ComputeStar()
{

}

void JL_CBirthday::ComputeBirth()
{

}