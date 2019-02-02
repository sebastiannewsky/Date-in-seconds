#include "TimeStamp.h"
#include <iostream>
using namespace std;

CTimeStamp::CTimeStamp(int iDay, int iMonth, int iYear, int iHour, int iMinute)
{
	d_date = 0;
	b_is_correct = true;
	vCheckIfCorrect(iDay, iMonth, iYear, iHour,iMinute);
	if (b_is_correct)
	{
		vSetDate(iDay, iMonth, iYear, iHour, iMinute);

	}//if (b_is_correct)

}//CTimeStamp::CTimeStamp(int iDay, int iMonth, int iYear, int iHour, int iMinute)


void CTimeStamp::vPrintTimeStamp()
{
	if (!b_is_correct)return;
	
	int i_time = d_date;
	
	int i_years = (i_time / iDayInSeconds()) / iSumOfDays();
	
	int i_leaps = 0;
	if (i_years > LEAP_YEARS)
		i_leaps = iLeapYears(DEFAULT_YEAR, DEFAULT_YEAR + i_years);
	
	int i_is_cheat_day = 0;
	//if (bCheckLeapYear(DEFAULT_DAY + i_years)) i_is_cheat_day = 1;
	int i_cheat_years = i_leaps / iSumOfDays();
	i_years = i_years - i_cheat_years;
	if (i_leaps != 0)
		i_time = i_time - i_leaps* iDayInSeconds();
	
	i_time = i_time - i_years * iSumOfDays()*iDayInSeconds();
	
	int i_month = 0;
	int i_helper = i_time;
	i_time = i_time - MONTHS[i_month]* iDayInSeconds();
	while (i_time > 0)
	{
		i_month++;
		i_helper = i_time;
		i_time = i_time - MONTHS[i_month]* iDayInSeconds();
	}//while (i_days > 0)
	i_time = i_helper;
	int i_days = i_time/ iDayInSeconds();;
	//i_days = i_days + DEFAULT_DAY;
	i_time = i_time - i_days * iDayInSeconds();
	int i_hours = i_time /(iHourInSeconds());

	i_time = i_time - i_hours* iHourInSeconds();
	
	int i_minute = i_time/MINUTE_IN_SECONDS; 
	cout << "(" << i_hours + DEFAULT_HOUR << ", " << i_minute + DEFAULT_MINUTE << ")";
	cout << "[" << i_days + DEFAULT_DAY << ", " << i_month + DEFAULT_MONTH << ", " << i_years + DEFAULT_YEAR << "]" << endl;


}//void CTimeStamp::vPrintTimeStamp()

int CTimeStamp::iMinutesDiffrence(CTimeStamp & pcOther)
{
	if (b_is_correct&&pcOther.b_is_correct)
	{
		int i_value = ((d_date - pcOther.d_date) / MINUTE_IN_SECONDS);
		if (i_value < 0)i_value = i_value * (-1);
		return i_value;
	}//if (b_is_correct&&pcOther.b_is_correct)
}//int CTimeStamp::iMinutesDiffrence(CTimeStamp & pcOther)


void CTimeStamp::vAddHours(int iHours)
{
	if (!b_is_correct) return;
	d_date = d_date + (iHours* iHourInSeconds());
	if (d_date < 0) b_is_correct = false;
}//void CTimeStamp::vAddHours(int iHours)
void CTimeStamp::operator+(int iAdd)
{
	vAddHours(iAdd);
}//void CTimeStamp::operator+(int iAdd)

void CTimeStamp::operator-(int iMinus)
{
	vAddHours(-iMinus);
}//void CTimeStamp::operator-(int iMinus)

int CTimeStamp::operator-(CTimeStamp & pcOther)
{
	return iMinutesDiffrence(pcOther);
}//int CTimeStamp::operator-(CTimeStamp & pcOther)



bool CTimeStamp::operator<(CTimeStamp & pcOther)
{
	if (b_is_correct&&pcOther.b_is_correct)
	{
		if (d_date < pcOther.d_date) return true;
	}//if (b_is_correct&&pcOther.b_is_correct)
	return false;
}//bool CTimeStamp::operator<(CTimeStamp & pcOther)

bool CTimeStamp::operator<=(CTimeStamp & pcOther)
{
	if (b_is_correct&&pcOther.b_is_correct)
	{
		if (d_date <= pcOther.d_date) return true;
	}//if (b_is_correct&&pcOther.b_is_correct)
	return false;
}//bool CTimeStamp::operator<=(CTimeStamp & pcOther)

bool CTimeStamp::operator>(CTimeStamp & pcOther)
{
	if (b_is_correct&&pcOther.b_is_correct)
	{
		if (d_date > pcOther.d_date) return true;
	}//if (b_is_correct&&pcOther.b_is_correct)
	return false;
}//bool CTimeStamp::operator>(CTimeStamp & pcOther)

bool CTimeStamp::operator>=(CTimeStamp & pcOther)
{
	if (b_is_correct&&pcOther.b_is_correct)
	{
		if (d_date >= pcOther.d_date) return true;
	}//if (b_is_correct&&pcOther.b_is_correct)
	return false;
}//bool CTimeStamp::operator>=(CTimeStamp & pcOther)

bool CTimeStamp::operator==(CTimeStamp & pcOther)
{
	if (b_is_correct&&pcOther.b_is_correct)
	{

		if (d_date == pcOther.d_date) return true;
	}//if (b_is_correct&&pcOther.b_is_correct)
	return false;
}//bool CTimeStamp::operator==(CTimeStamp & pcOther)

void CTimeStamp::vCheckIfCorrect(int iDay, int iMonth, int iYear, int iHour, int iMinute)
{

	CDate::vCheckIfCorrect(iDay, iMonth, iYear);
	if (b_is_correct)
	{
		if (iHour < 0 || iHour >= NUMBER_OF_HOURS)
		{
			b_is_correct = false;
		}//if (iHour < 0 || iHour >= NUMBER_OF_HOURS)
		else if(iMinute<0||iMinute>=NUMBER_OF_MINUTES)
		{
			b_is_correct = false;
		}//		else if(iMinute<0||iMinute>=NUMBER_OF_MINUTES)
		else b_is_correct = true;
	}//	if (b_is_correct)

}//void CTimeStamp::vCheckIfCorrect(int iDay, int iMonth, int iYear, int iHour, int iMinute)


void CTimeStamp::vSetDate(int iDay, int iMonth, int iYear, int iHour, int iMinute)
{
	CDate::vSetDate(iDay, iMonth, iYear);
	if (!b_is_correct) return;
	d_date = d_date + iHour * iHourInSeconds();
	d_date = d_date + iMinute * MINUTE_IN_SECONDS;
	if (d_date < 0) b_is_correct = false;

}//void CTimeStamp::vSetDate(int iDay, int iMonth, int iYear, int iHour, int iMinute)
