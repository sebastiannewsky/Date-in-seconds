#include "Date.h"
#include <iostream>

using namespace std;
CDate::CDate()
{
	d_date = 0;
	b_is_correct = true;
}//Date::Date()

CDate::CDate(int iDay, int iMonth, int iYear)
{
	d_date = 0;
	b_is_correct = true;
	vCheckIfCorrect(iDay, iMonth, iYear);
	if (b_is_correct)
	{
		vSetDate(iDay, iMonth, iYear);
		
	}//if (b_is_correct)
	
}//Date::Date(int iDay, int iMonth, int iYear)

int CDate::bDateDiffrence(CDate & pcOther)
{
	if (b_is_correct&&pcOther.b_is_correct)
	{
		int i_value = ((d_date - pcOther.d_date) / iDayInSeconds());
		
		if (i_value < 0) i_value=i_value*(-1);
		
		return i_value;
	}//if (b_is_correct&&pcOther.b_is_correct)
}//bool Date::bDateDiffrence(Date & pcOther)

void CDate::vPrint()
{
	if (!b_is_correct)return;
	//cout << "DDATE: " << d_date<< endl;
	int i_days = d_date / (24*60*60);
	//cout << "IDAYS: " << i_days << endl;
	int i_years = i_days / iSumOfDays();
	//cout << "IYEARS: " << i_days << endl;
	int i_leaps = 0;
	if(i_years>LEAP_YEARS)
	i_leaps = iLeapYears(DEFAULT_YEAR, DEFAULT_YEAR + i_years);
	//cout << i_leaps << endl;
	int i_is_cheat_day=0;
	//if (bCheckLeapYear(DEFAULT_DAY + i_years)) i_is_cheat_day = 1;
	int i_cheat_years = i_leaps / iSumOfDays();
	i_years = i_years - i_cheat_years;
	if(i_leaps!=0)
	i_days = i_days - i_leaps;
	//cout << "IDAYS: " << i_days << endl;
	i_days = i_days - i_years * iSumOfDays();
	//cout << "IDAYS: " << i_days << endl;
	int i_month = DEFAULT_MONTH-1;
	int i_helper = i_days;
	i_days = i_days - MONTHS[i_month];
	while (i_days > 0)
	{
		i_month++;
		i_helper = i_days;
		i_days = i_days - MONTHS[i_month];
	}//while (i_days > 0)
	i_days = i_helper;

	cout << "[" << i_days+DEFAULT_DAY << ", " << i_month+DEFAULT_MONTH << ", " << i_years+DEFAULT_YEAR<<"]"<<endl;

}//void Date::vPrintDate()


void CDate::vAddDays(int iDays)
{
	if (!b_is_correct) return;
	d_date = d_date + (iDays*iDayInSeconds());
	if (d_date < 0) b_is_correct = false;
}//void Date::vAddDays(int iDays)
void CDate::operator+(int iAdd)
{
	vAddDays(iAdd);
}//void CDate::operator+(int iAdd)

void CDate::operator-(int iMinus)
{
	vAddDays(-iMinus);
}//void CDate::operator-(int iMinus)

int CDate::operator-(CDate & pcOther)
{
	return bDateDiffrence(pcOther);
}//int CDate::operator-(CDate & pcOther)

//void CDate::operator+(int iAdd)



bool CDate::operator<(CDate&  pcOther)
{
	if (b_is_correct&&pcOther.b_is_correct)
	{
		if (iReturnDays() < pcOther.iReturnDays()) return true;
	}//if (b_is_correct&&pcOther.b_is_correct)
	return false;
}//bool Date::operator<(Date & pcOther)

bool CDate::operator<=(CDate&  pcOther)
{
	if (b_is_correct&&pcOther.b_is_correct)
	{
		if (iReturnDays() <= pcOther.iReturnDays()) return true;
	}//if (b_is_correct&&pcOther.b_is_correct)
	return false;
}//bool Date::operator<=(Date & pcOther)

bool CDate::operator>(CDate&  pcOther)
{
	if (b_is_correct&&pcOther.b_is_correct)
	{
		if (iReturnDays() > pcOther.iReturnDays()) return true;
	}//if (b_is_correct&&pcOther.b_is_correct)
	return false;
}//bool Date::operator>(Date & pcOther)

bool CDate::operator>=(CDate&  pcOther)
{
	if (b_is_correct&&pcOther.b_is_correct)
	{
		if (iReturnDays() >= pcOther.iReturnDays()) return true;
	}//if (b_is_correct&&pcOther.b_is_correct)
	return false;
}//bool Date::operator>=(Date & pcOther)

bool CDate::operator==(CDate&  pcOther)
{
	if (b_is_correct&&pcOther.b_is_correct)
	{
		if (iReturnDays() == pcOther.iReturnDays()) return true;
	}//if (b_is_correct&&pcOther.b_is_correct)
	return false;
}//bool Date::operator==(Date & pcOther)

void CDate::vCheckIfCorrect(int iDay, int iMonth, int iYear)
{

	if (iYear < DEFAULT_DAY)
	{
		b_is_correct = false; return;
	}//if (iYear < DEFAULT_DAY)
	else if (iMonth<1 || iMonth>NUMBER_OF_MONTHS)
	{
		b_is_correct = false; return;
	}//else if (iMonth<1 || iMonth>NUMBER_OF_MONTHS)
	else if (iDay<1 || iDay>MONTHS[iMonth])
	{
		b_is_correct = false; return;
	}//else if (iDay<1 || iDay>MONTHS[iMonth])
	else
	{
		if (iDay < 1)
		{
			b_is_correct = false; return;
		}//if (iDay < 1)
		else if (bCheckLeapYear(iYear))
		{
			if (iDay > LEAP_YEAR[iMonth])
			{
				b_is_correct = false; return;
			}//if (iDay > LEAP_YEAR[iMonth])
		}//else if (bCheckLeapYear(iYear))
		else
		{
			if (iDay > MONTHS[iMonth])
			{
				b_is_correct = false; return;
			}//f (iDay > MONTHS[iMonth])
		}//else if (bCheckLeapYear(iYear))
	}//else

}//void CDate::vCheckIfCorrect(int iDay, int iMonth, int iYear)
void CDate::vSetDate(int iDay, int iMonth, int iYear)
{
	int i_leaps = iLeapYears(DEFAULT_YEAR, iYear);



	d_date = (iYear - DEFAULT_YEAR) * iSumOfDays()*iDayInSeconds();
	if (d_date < 0)
	{
		b_is_correct = false;
		d_date = 0;
	}//if (d_date < 0)
	for (int i = 1; i < iMonth; i++)
	{
		d_date = d_date + MONTHS[i - 1] * iDayInSeconds();
	}//for (int i = 1; i < iMonth; i++)

	d_date = d_date + (iDay - DEFAULT_DAY) * iDayInSeconds();

	d_date = d_date + i_leaps * iDayInSeconds();
	if (d_date < 0)
	{
		b_is_correct = false;
		d_date = 0;
	}//if (d_date < 0)

	
}//void CDate::vSetDate(int iDay, int iMonth, int iYear)


bool CDate::bCheckLeapYear(int iYear)
{
	if (iYear % LEAP_YEARS != 0) return false;
	else if (iYear % 100 != 0) return true;
	else if (iYear % (LEAP_YEARS * 100) != 0) return false;
	else return true;
}//bool Date::bCheckLeapYear(int iYear)

int CDate::iLeapYears(int iYear1, int iYear2)
{
	int i_100leap = 100 * LEAP_YEARS;
	//cout << "LEAPS: " << ((iYear2 / LEAP_YEARS - iYear2 / 100 + iYear2 / i_100leap) - (iYear1 / LEAP_YEARS - iYear1 / 100 + iYear1 / i_100leap)) << endl;
	return ((iYear2 / LEAP_YEARS - iYear2 / 100 + iYear2 / i_100leap) - (iYear1 / LEAP_YEARS - iYear1 / 100 + iYear1 / i_100leap));
}//int Date::iLeapYears(int iYear1, int iYear2)

int CDate::iSumOfDays()
{
	int i_sum = 0;
	for (int i = 0; i < NUMBER_OF_MONTHS; i++)
	{
		i_sum = i_sum + MONTHS[i];
	}//for (int i = 0; i < NUMBER_OF_MONTHS; i++)
	return i_sum;
}//int Date::iSumOfDays()
int CDate::iFirstLeapYear()
{
	int i_new_leap = DEFAULT_YEAR;
	bool bIsLeap = false;
	do
	{
		bIsLeap = bCheckLeapYear(i_new_leap);
		if (!bIsLeap)
		{
			i_new_leap++;
		}//if (!bIsLeap)
	} while (!bIsLeap);//do
	return i_new_leap;
}//int Date::iFirstLeapYear()
bool CDate::bIsCOrrect()
{
	return b_is_correct;
}//bool CDate::bIsCOrrect()
int CDate::iReturnDays()
{
	return (d_date / (NUMBER_OF_HOURS * NUMBER_OF_MINUTES * NUMBER_OF_SECONDS));
}//int CDate::iReturnDays()
int CDate::iDayInSeconds()
{
	return (NUMBER_OF_HOURS * NUMBER_OF_MINUTES * NUMBER_OF_SECONDS);
}//int CDate::iDayInSeconds()
int CDate::iHourInSeconds()
{
	return (NUMBER_OF_MINUTES*NUMBER_OF_SECONDS);
}//int CDate::iHourInSeconds()





