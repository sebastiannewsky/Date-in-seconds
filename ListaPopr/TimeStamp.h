#pragma once
#include "Date.h"

class CTimeStamp: public CDate
{
public:
	CTimeStamp(int iDay, int iMonth, int iYear, int iHour, int iMinute);
	void vPrint();
	int iMinutesDiffrence(CTimeStamp& pcOther);
	void vAddHours(int iHours);
	void operator+  (int iAdd);
	void operator-  (int iMinus);
	int operator-  (CTimeStamp& pcOther);
	bool operator<  (CTimeStamp& pcOther);
	bool operator<= (CTimeStamp& pcOther);
	bool operator>  (CTimeStamp& pcOther);
	bool operator>= (CTimeStamp& pcOther);
	bool operator== (CTimeStamp& pcOther);
	void vCheckIfCorrect(int iDay, int iMonth, int iYear, int iHour, int iMinute);
	void vSetDate(int iDay, int iMonth, int iYear, int iHour, int iMinute);
};
