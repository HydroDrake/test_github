#include <map>
#include <string>
#include <set>
#include <iostream>
using namespace std;

template <typename T>
set<T> operator+(const set<T>& lhs, const set<T>& rhs)
{
	set<T> plus;
	plus = lhs;
	for(typename set<T>::const_iterator it = rhs.begin();it!=rhs.end();it++)
	{
		plus.insert(*it);
	}
	return plus;
}
template <typename T>
set<T> operator-(const set<T>& lhs, const set<T>& rhs)
{
	set<T> minus;
	int error = -3;
	for(typename set<T>::const_iterator it = lhs.begin();it!=lhs.end();it++)
	{
		error = -3;
		for(typename set<T>::const_iterator at = rhs.begin();at!=rhs.end();at++)
		{
			if(*it==*at)
			{
				error = -2;
			}
		}
		if(error == -3)
			minus.insert(*it);
	}
	return minus;
}
template <typename T>
set<T> operator*(const set<T>& lhs, const set<T>& rhs)
{
	set<T> product;
	for(typename set<T>::const_iterator it = rhs.begin();it!=rhs.end();it++)
	{
		for(typename set<T>::const_iterator at = lhs.begin();at!=lhs.end();at++)
		{
			if(*it==*at)
			{
				product.insert(*it);
			}
		}
	}
	return product;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s)
{
	os<<"{ ";
	for(typename set<T>::const_iterator it = s.begin();it!=s.end();it++)
	{
		os<<*it<<' ';
	}
	os<<"}";
	return os;
}
template <typename T>
istream& operator>>(istream& is, set<T>& s)
{
	int setNum;
	T setS;
	is>>setNum;
	for(int i=0;i<setNum;i++)
	{
		is>>setS;
		s.insert(setS);
	}
	return is;
}
template <typename T, typename S>
set<T> Cast(const set<S>& s)
{
	set<T> P;
	for(typename set<S>::const_iterator it = s.begin();it!=s.end();it++)
	{
		P.insert(static_cast<T>(*it));
	}
	return P;
}