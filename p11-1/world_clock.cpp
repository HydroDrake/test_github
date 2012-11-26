#include "world_clock.h"

WorldClock::WorldClock(int hour, int minute, int second)
{
	hour_=hour;
	minute_=minute;
	second_=second;
	total_second=hour*3600 + minute*60 + second;
	time_difference_=0;
}
 map<string, int> WorldClock::timezone_;
void WorldClock::Tick(int seconds)
{
	total_second=hour_*3600 + minute_*60 + second_;
	total_second+=seconds;
	int total2=total_second;
	hour_=total_second/3600;
	total2-=hour_*3600;
	minute_=total2/60;
	total2-=minute_*60;
	second_=total2;
	while(hour_>=24)
		hour_-=24;
	if(second_<0)
	{
		second_+=60;
		minute_--;
	}
	if(minute_<0)
	{
		minute_+=60;
		hour_--;
	}
	while(hour_<0)
		hour_+=24;
}


istream& operator>>(istream& is, WorldClock& c)
{
	string time;
	is>>time;
	int hm, ms;
	for(int i=0;i<time.size();i++)
	{
		if(time[i]==':')
		{
			hm=i;
			break;
		}
	}
	for(int i=hm+1;i<time.size();i++)
	{
		if(time[i]==':')
		{
			ms=i;
			break;
		}
	}
	int hour=atoi(time.substr(0,hm+1).c_str());
	int minute=atoi(time.substr(hm+1,ms+1).c_str());
	int second=atoi(time.substr(ms+1,time.size()-1).c_str());
	if(hour>=24||minute>=60||second>=60)
	{
		InvalidTimeException e(time);
		throw e;
	}
	c=WorldClock(hour,minute,second);
	return is;
}
ostream& operator<<(ostream& os, const WorldClock& c)
{
	os<<c.hour()<<':'<<c.minute()<<':'<<c.second();
	if(c.time_difference()>0)
		os<<" ("<<"+"<<c.time_difference()<<")";
	else if(c.time_difference()<0)
		os<<" ("<<c.time_difference()<<")";
	return os;
}
int WorldClock::hour() const
{
	return hour_;
}
int WorldClock::minute() const
{
	return minute_;
}
int WorldClock::second() const
{
	return second_;
}
void WorldClock::AddTimezoneInfo(const string& city, int diff)
{
	timezone_[city]=diff;
}
bool WorldClock::SetTimezone(const string& timezone)
{
	hour_-=time_difference_;
	if(hour_<0)
		hour_+=24;
	map<string, int>::iterator t=timezone_.begin();
	bool settime=false;
	for(t;t!=timezone_.end();t++)
	{
		if(t->first==timezone)
		{
			hour_+=t->second;
			time_difference_=t->second;
			if(hour_>=24)
				hour_-=24;
			return true;
		}
	}
	return settime;
}