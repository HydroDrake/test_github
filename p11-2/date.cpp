#include "date.h"

Date::Date(int year, int month, int day)
{
	year_=year;
	month_=month;
	day_=day;
}

void Date::NextDay(int n )
{
	day_+=n;
	bool OK=true;
	while(OK)
	{
	if(year_%4==0&&month_==2)
	{
		if(year_%100!=0||year_%400==0)
		{
			if(day_>29)
			{
				month_++;
				day_-=29;
			}
		}
		if(year_%100==0)
		{
			if(day_>29)
			{
				month_++;
				day_-=29;
			}
		}
	}
	if(month_==1||month_==3||month_==5||month_==7||month_==8||month_==10||month_==12)
	{
		if(day_>31)
		{
			month_++;
			day_-=31;
		}
		if(month_>12)
		{
			month_=1;
			year_++;
		}
	}
	else if(month_==4||month_==6||month_==9||month_==11)
	{
		if(day_>30)
		{
			month_++;
			day_-=30;
		}
	}
	if(month_==2)
	{
		if(day_>28)
		{
			month_++;
			day_-=30;
		}
	}
	if(day_<=0)
	{
		if(month_!=1)
		{
			month_--;
			if(month_==1||month_==3||month_==5||month_==7||month_==8||month_==10)
				day_+=31;
			else if(month_==4||month_==6||month_==9||month_==11)
				day_+=30;
			else if(month_==2)
			{
				if(GetDaysInYear(year_)==366)
					day_+=29;
				else
					day_+=28;
			}
		}
		if(month_==1)
		{
			month_=12;
			year_--;
			day_+=31;
		}
	}
	if(month_==1||month_==3||month_==5||month_==7||month_==8||month_==10||month_==12)
	{
		if(day_<=31&&day_>0)
			OK=false;
	}
	else if(month_==4||month_==6||month_==9||month_==11&&day_<=30&&day_>0)
	{
		if(day_<=30&&day_>0)
			OK=false;
	}
	else if(month_==2&&GetDaysInYear(year_)==366)
	{
		if(day_<=29&&day_>0)
			OK=false;
	}

	else if(month_==2&&GetDaysInYear(year_)==365)
	{
		if(day_<=28&&day_>0)
			OK=false;
	}
	}
}

int Date::year() const
{
	return year_;
}
int Date::month() const
{
	return month_;
}
int Date::day() const
{
	return day_;
}
int Date::GetDaysInYear(int year)
{
	if(year%4==0)
	{
		if(year%100==0&&year%400!=0)
			return 365;
		return 366;
	}
	return 365;
}
int Date::ComputeDaysFromYearStart(int year, int month, int day)
{
	int days=day-1;
	for(int i=month;month>1;month--)
	{
		if(month==12)
			days+=30;
		else if(month==11)
			days+=31;
		else if(month==10)
			days+=30;
		else if(month==9)
			days+=31;
		else if(month==8)
			days+=31;
		else if(month==7)
			days+=30;
		else if(month==6)
			days+=31;
		else if(month==5)
			days+=30;
		else if(month==4)
			days+=31;
		else if(month==3)
		{
			if(GetDaysInYear(year)==366)
				days+=29;
			else
				days+=28;
		}
		else if(month==2)
			days+=31;
	}
	return days;
}
bool Date::SetDate(int year, int month, int day)
{
	if(month==0||day==0)
	{
		return false;
	}
	if(month>12)
	{
		return false;
	}
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		if(day>31)
		{
			return false;
		}
	}
	if(month==4||month==6||month==9||month==11)
	{
		if(day>30)
		{
			return false;
		}
	}
	if(month==2)
	{
		if(year%4==0)
		{
			if(year%100==0&&year%400!=0)
			{
				if(day>28)
				{
					return false;
				}
			}
			else
			{
				if(day>29)
				{
					return false;
				}
			}
		}
		else
		{
			if(day>28)
			{
				return false;
			}
		}
	}
	return true;
}
istream& operator>>(istream& is, Date& c)
{
	string Dates;
	Date d;
	int ymPoint,mdPoint,year,month,day;
	is>>Dates;
	for(int i=0;i<Dates.size();i++)
	{
		if(Dates[i]=='.')
		{
			ymPoint=i;
			break;
		}
	}
	for(int i=ymPoint+1;i<Dates.size();i++)
	{
		if(Dates[i]=='.')
		{
			mdPoint=i;
			break;
		}
	}
	year=atoi(Dates.substr(0,ymPoint+1).c_str());
	month=atoi(Dates.substr(ymPoint+1,mdPoint+1).c_str());
	day=atoi(Dates.substr(mdPoint+1,Dates.size()).c_str());
	d=c;
	c=Date(year,month,day);
	if(!c.SetDate(year,month,day))
	{
		c=d;
		InvalidDateException e(Dates);
		throw e;
	}
	return is;
}
ostream& operator<<(ostream& os, const Date& c)
{
	os<<c.year()<<'.'<<c.month()<<'.'<<c.day();
	return os;
}