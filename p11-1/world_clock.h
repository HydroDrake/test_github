#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;

class WorldClock 
{
	public:
		WorldClock(){};
		WorldClock(int hour, int minute, int second);
		void Tick(int seconds = 1);
		// �߸��� �� �Է½� false �����ϰ� ���� �ð��� �ٲ��� ����.
		bool SetTime(int hour, int minute, int second);
		// static bool LoadTimezoneFromFile(const string& file_path);
		// �߸��� �� �Է½� false �����ϰ� ���� �ð��� �ٲ��� ����.
		bool SetTimezone(const string& timezone);
		static void AddTimezoneInfo(const string& city, int diff);
		int hour() const;
		int minute() const;
		int second() const;
		int time_difference() const { return time_difference_; }
	private:
		// ���⿡ �ð� ���� ��� ���� ����. (GMT �ð��� ���)
		// Timezone ���� ������ �Ʒ� ������ ����. ������ �ð� �����θ� ���.
		int total_second;
		int time_difference_;
		int minute_;
		int hour_;
		int second_;
		static map<string, int> timezone_;
};
struct InvalidTimeException 
{
	string input_time;
	InvalidTimeException(const string& str) : input_time(str) {}
};
// hh:mm:ss �������� �����. ǥ�ؽð� �ƴ� ��� (+xx) �������� ������ ǥ��.
// ����� �Է� ������ >> operator�� InvalidDateException�� �߻��� �� ����.
ostream& operator<<(ostream& os, const WorldClock& c);
istream& operator>>(istream& is, WorldClock& c); // hh:mm:ss �� �Է¹���.