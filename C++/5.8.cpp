#include<iostream>
#include<cstring>
using namespace std;

class Time {
	protected:
		int hour;
		int minute;
		int second;
	
	public:
		Time(int h,int m, int s);	//构造函数
		void Show_time();
		void Set_time(int h, int m, int s);
		int Hour() { return hour; }
		int Minute() { return minute; }
		int Second() { return second; }

};

Time::Time(int h = 0, int m = 0, int s = 0) {
	this->hour = h;
	this->minute = m;
	this->second = s;
}

void Time::Show_time() {
	printf("%02d:", hour);
	printf("%02d:", minute);
	printf("%02d", second);
	// if(hour < 10)	printf("0");
	// printf("%d", hour);
	// printf(":");

	// if(minute < 10)	printf("0");
	// printf("%d", minute);
	// printf(":");

	// if(second < 10)	printf("0");
	// printf("%d", second);

	// putchar('\n');
}

void Time::Set_time(int h, int m, int s) {
	this->hour = h;
	this->minute = m;
	this->second = s;
}

class Train_trip {
	public:
        Train_trip(const char *, const char *, const char *, int , int sh, int sm, int ss, int eh, int em, int es);
		Train_trip(const char *s1, const char *s2, const char *s3, int , Time t1, Time t2);
		void Calculate_time();	//计算耗费的时间
		void show();

	protected:
		char Train_number[20];	//车次
		char start_place[20];	//起点站
		char end_place[20];		//终点站
		int  price;				//价格
		Time start_t;			//发车时间
		Time end_t;				//到站时间
		Time consume_t;			//耗费时间
};

//构造函数
Train_trip::Train_trip(const char* Train_number, const char* start_p, const char* end_p, int price, Time start_t, Time end_t) {
	strcpy(this->Train_number,Train_number);
	strcpy(this->start_place, start_p);
	strcpy(this->end_place, end_p);
	this->price = price;
	this->start_t = start_t;
	this->end_t = end_t;
}

Train_trip::Train_trip(const char *s1, const char *s2, const char *s3, int p, int sh, int sm, int ss, int eh, int em, int es) :
                        price(p), start_t(sh,sm,ss), end_t(eh,em,es) 
{
    // this->price = price;
    strcpy(Train_number, s1);
    strcpy(start_place, s2);
    strcpy(end_place, s3);
}

void Train_trip::Calculate_time() {
	int h = 0,m = 0,s = 0;
	s = end_t.Second() - start_t.Second();
	m = end_t.Minute() - start_t.Minute();
	h = end_t.Hour() - start_t.Hour();
	if(s < 0) {
		s += 60;
		m--;
	}
	if(m < 0) {
		m += 60;
		h--;
	}
	if(h < 0) {
		h += 24;
	}
	consume_t.Set_time(h,m,s);
}

void Train_trip::show() {
	start_t.Show_time();
	printf("\t%s\t\t", Train_number);
	end_t.Show_time();
	putchar('\n');

	printf("%s\t\t", start_place);
	consume_t.Show_time();
	printf("\t%s\n", end_place);

	printf("%d\n\n", price);
}

int main() {
	// Time t1(8,10,10), t2(6,1,2);
	// Train_trip train("K1057","西宁","峨眉",54,t1,t2);
    Train_trip train("K1057","西宁","乐山",54,8,10,10,6,1,2);
	train.Calculate_time();
	train.show();
	train.~Train_trip();
	return 0;
}