#pragma once
#define DEFAULT_DAY 1
#define DEFAULT_MONTH 1
#define DEFAULT_YEAR 1900
#define NUMBER_OF_MONTHS 12
#define LEAP_YEARS 4
#define NUMBER_OF_HOURS 24
#define NUMBER_OF_MINUTES 60
#define NUMBER_OF_SECONDS 60
#define MINUTE_IN_SECONDS 60

#define DEFAULT_HOUR 0
#define DEFAULT_MINUTE 0
class CDate
{

public:
	CDate();
	CDate(int iDay, int iMonth, int iYear);

	int bDateDiffrence(CDate& pcOther);
	void vPrint();
	void vAddDays(int iDays);

	void operator+  (int iAdd);
	void operator-  (int iMinus);
	int operator-  (CDate& pcOther);
	bool operator<  (CDate& pcOther);
	bool operator<= (CDate& pcOther);
	bool operator>  (CDate& pcOther);
	bool operator>= (CDate& pcOther);
	bool operator== (CDate& pcOther);
protected:

	double d_date;
	bool b_is_correct;

	void vCheckIfCorrect(int iDay, int iMonth, int iYear);
	void vSetDate(int iDay, int iMonth, int iYear);
	bool bCheckLeapYear(int iYear);
	int iLeapYears(int iYear1, int iYear2);
	int iSumOfDays();
	int iFirstLeapYear();
	bool bIsCOrrect();
	int iReturnDays();
	int iDayInSeconds();
	int iHourInSeconds();

	const  int MONTHS[NUMBER_OF_MONTHS] = { 31, 28, 31,30,31,30,31,31,30,31,30,31 };
	const  int LEAP_YEAR[NUMBER_OF_MONTHS] = { 31, 29, 31,30,31,30,31,31,30,31,30,31 }; 

	int x = 'd';
};