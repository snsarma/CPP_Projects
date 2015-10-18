#ifndef _TIME_H_
#define _TIME_H_
#include<string>
#include<iostream>

class Time
{

        friend std::istream& operator>> (std::istream& stream,Time& obj);
        friend std::ostream& operator<< (std::ostream& stream,const Time& obj);//Overloading the insertion and the extraction opreators
public:	
	         Time();
		 Time(int seconds); 
	         void set_time(std::string t);
		 Time operator+(Time &obj);
		 Time operator+=(Time &obj);
		 Time operator/(int s);
		 Time operator/=(int s);                                 //Interface for the Time.cpp file
		 bool  operator<(const Time &obj)const;                  //Overloads the following operators
		 bool  operator>(const Time &obj)const;
		 bool operator ==(const Time &obj)const;                 //Member Functions
		 Time &operator=(const Time &obj)const;
		 int get_seconds()const;
                                                                          //Instance variables
private:         std::string str;
		 int total_secs;

};
#endif
