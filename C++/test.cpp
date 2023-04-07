#include <iostream>
using namespace std;

class Clock
{
private:
	int hour;
	int minute;
	int second;

public:
	Clock(int h = 0, int m = 0, int s = 0)
	{
		this->hour = h;
		this->minute = m;
		this->second = s;
	}
	Clock(Clock &p)
	{
		this->hour = p.hour;
		this->minute = p.minute;
		this->second = p.second;
	}
	//	析构函数什么都不做
	void show_time();
	void Time_substract(Clock &p); //时间减法
	void Time_Add(Clock &p);	   //时间加法
};

void Clock::show_time()
{
	if (hour < 10)
		cout << 0;
	cout << hour << ":";
	if (minute < 10)
		cout << 0;
	cout << minute << ":";
	if (second < 10)
		cout << 0;
	cout << second << endl;
}
void Clock::Time_substract(Clock &p)
{
	second -= p.second;
	if (second < 0)
	{
		minute--;
		second += 60;
	}

	minute -= p.minute;
	if (minute < 0)
	{
		minute += 60;
		hour--;
	}

	hour = hour - p.hour;
	if (hour < 0)
		hour += 24;
}
void Clock::Time_Add(Clock &p)
{
	int t1, t2;
	t1 = (second + p.second) / 60;
	second = (second + p.second) % 60;
	t2 = (minute + p.minute + t1) / 60;
	minute = (minute + p.minute + t1) % 60;
	hour = (hour + p.hour + t2) % 24;
}

int main()
{
	Clock c1(0, 0, 0);
	Clock c2(12, 23, 34);
	Clock c3(23, 56, 49);
	Clock &c4 = c3;
	Clock c5(0, 0, 0);
	cout << "c1 :";
	c1.show_time();
	cout << "c2 :";
	c2.show_time();

	cout << "c1-c2 :";
	c1.Time_substract(c2);
	c1.show_time();

	cout << "c1+c2 :";
	c1.Time_Add(c2);
	c1.show_time();

	cout << "c2-c3 :";
	c2.Time_substract(c3);
	c2.show_time();

	cout << "c4 :";
	c4.show_time();
	cout << "c5 :";
	c5.show_time();

	cout << "c4+c5 :";
	c5.Time_Add(c4);
	c5.show_time();
	return 0;
}
