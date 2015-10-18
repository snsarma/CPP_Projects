//#include "stdafx.h"
#include "Time.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <stdlib.h>
using namespace std;

Time::Time()
{
	total_secs=0;
}                                                           // Constructor with no parameters initializes total_secs to zero
                                                                   

                                         
Time::Time(int secs)
{
	total_secs=secs;                                    //Constructor with parameters
}
bool Time::operator <(const Time &obj) const
{
	return(this->total_secs<obj.total_secs);            //Comparision operators to check if it is less than greater than or equal to
}

bool Time::operator >(const Time &obj) const
{
	return(this->total_secs>obj.total_secs);
}

bool Time::operator==(const Time &obj) const
{
	return(this->total_secs==obj.total_secs);
}


Time Time::operator+=(Time &obj)                                //The short hand operators
{

	this->total_secs=this->total_secs+(obj.total_secs);
	return(*this);


}

Time& Time::operator=(const Time &obj) const
{
       Time t;
	t.total_secs=obj.get_seconds();                         //The assignment operator
	return(t);
}

Time Time::operator/=(int s)
{

	this->total_secs=this->total_secs/s;
	return(*this);

}

Time Time::operator+(Time &obj)                              //Binary addition operator
{
	Time t;
	t.total_secs=this->get_seconds()+obj.get_seconds();
        return(t);
}

Time Time::operator/(int s)
{
	Time t;
	t.total_secs=this->total_secs/s;                         //Division operator
	return(t);
}



void Time::set_time(std::string t)
{

	string minutes,minutes1,minutes2,hours,seconds,seconds1,seconds2,hours1,hours2;
    int hrs,mins,secs; 
   
	int colon_count=0;
  for(int i=0;i<t.length();i++)
  {
	  if(t[i]==':')
	  {
		  ++colon_count;                                  //Meant for splitting the input time string and setting the time
	  }
                                                                 // Calculate the colon count
  }
  if(colon_count == 2)
  {
    if((t[0]==':')&&(t[1]==':')&&(t[2]==' '))                     //Check which part of the string contains colon
	{
		hours="0";
		minutes="0";
		seconds="0";                                    //If there are 2 colons and no input string
		hrs=atoi(hours.c_str());
        mins=atoi(minutes.c_str());
        secs=atoi(seconds.c_str());
        if((hrs<0)||(mins>60)||(mins<0)||(secs<0)||(secs>60))
		{
		  cerr<<"Invalid Time entry:"<<endl;
		  return;
		}
		else
		{	
		  total_secs=(hrs*3600+mins*60+secs);
		}
		  
	}
	else if((t[0]!=':')&&(t[1]==':')&&(t[2]!=' '))
	{
		hours=t[0];
		minutes="0";
		seconds=t[2];
		hrs=atoi(hours.c_str());                       //If there are 2 colons but the seconds part is mentioned
        mins=atoi(minutes.c_str());
        secs=atoi(seconds.c_str());
        if((hrs<0)||(mins>60)||(mins<0)||(secs<0)||(secs>60))
		{
		  cerr<<"Invalid Time entry:"<<endl;
		  return;
		}
		else
		{	
		  total_secs=(hrs*3600+mins*60+secs);          //Check for every error condition if hrs is less than zero and mins and secs greater than 60
		}
        
	}	 
  
	else if((t[0]==':')&&(t[1]==':')&&(t[2]!=' '))
	{
		hours="0";
		minutes="0";                                       //If there are only colons and  seconds part is mentioned
		seconds=t[2];
	   hrs=atoi(hours.c_str());
       mins=atoi(minutes.c_str());
       secs=atoi(seconds.c_str());
       if((hrs<0)||(mins>60)||(mins<0)||(secs<0)||(secs>60))
		{
		  cerr<<"Invalid Time entry:"<<endl;
		  return;
		}
		else
		{	
		  total_secs=(hrs*3600+mins*60+secs);
		}	   
	   
	}
	else
	{
      unsigned colon1=t.find_first_of(":");
      hours=t.substr(0,colon1);
      t=t.substr(colon1+1);
      unsigned colon2=t.find_first_of(":");
      minutes=t.substr(0,colon2);                                       // if the string is provided in the actual format as in HH:MM:SS correctly
      t=t.substr(colon2+1);
      seconds=t;
      hrs=atoi(hours.c_str());
      mins=atoi(minutes.c_str());
      secs=atoi(seconds.c_str());
      if((hrs<0)||(mins>60)||(mins<0)||(secs<0)||(secs>60))
		{
		  cerr<<"Invalid Time entry:"<<endl;
		  return;
		}
		else
		{	
		  total_secs=(hrs*3600+mins*60+secs);
		}
	   
	}
  }
  else if(colon_count == 1)
  {
	  if(t[0]!=':')
	  {
		  hours=t[0];                                         //If there is only one colon present and only hrs part is mentioned
		  minutes="0";
		  seconds="0";
		  hrs=atoi(hours.c_str());
          mins=atoi(minutes.c_str());
          secs=atoi(seconds.c_str());
         if((hrs<0)||(mins>60)||(mins<0)||(secs<0)||(secs>60))
		{
		  cerr<<"Invalid Time entry:"<<endl;
		  return;
		}
		else
		{	
		  total_secs=(hrs*3600+mins*60+secs);
		}
	     	
	  }

	  else if((t[0]==':')&&(t[1]!=' '))
	  {
		  hours="0";
		  minutes=t[1];
		  seconds="0";
		  hrs=atoi(hours.c_str());
          mins=atoi(minutes.c_str());
          secs=atoi(seconds.c_str());
        if((hrs<0)||(mins>60)||(mins<0)||(secs<0)||(secs>60))          //If there is only minutes
		{
		  cerr<<"Invalid Time entry:"<<endl;
		  return;
		}
		else
		{	
		  total_secs=(hrs*3600+mins*60+secs);
		}
	      

	  }
	  else if((t[0]==':')&&(t[1] ==' '))
	  {
		  hours="0";
		  minutes="0";
		  seconds="0";
		  hrs=atoi(hours.c_str());
          mins=atoi(minutes.c_str());
          secs=atoi(seconds.c_str());
          if((hrs<0)||(mins>60)||(mins<0)||(secs<0)||(secs>60))   //Nothing is specified apart from the colon
		{
		  cerr<<"Invalid Time entry:"<<endl;
		  return;
		}
		else
		{	
		  total_secs=(hrs*3600+mins*60+secs);
		}
	      

	  }

  }
  else if((colon_count>2)&&(t[0]!=':'))
  {
	      hours=t[0];
		  minutes="0";
		  seconds="0";
		  hrs=atoi(hours.c_str());
          mins=atoi(minutes.c_str());
          secs=atoi(seconds.c_str());
         if((hrs<0)||(mins>60)||(mins<0)||(secs<0)||(secs>60))    //Colon count is greater than 2
		{
		  cerr<<"Invalid Time entry:"<<endl;
		  return;
		}
		else
		{	
		  total_secs=(hrs*3600+mins*60+secs);
		}
	      

  }
  else if((colon_count>2)&&(t[1]!=':'))
  {
	      hours="0";
		  minutes=t[1];
		  seconds="0";
		  hrs=atoi(hours.c_str());
          mins=atoi(minutes.c_str());
          secs=atoi(seconds.c_str());
         if((hrs<0)||(mins>60)||(mins<0)||(secs<0)||(secs>60)) //colon count is greater than 2 but minutes part is mentioned
 		{
		  cerr<<"Invalid Time entry:"<<endl;
		  return;
		}
		else
		{	
		  total_secs=(hrs*3600+mins*60+secs);
		}
	      

  }
  else if((colon_count>2)&&(t[2]!=':'))
  {
	      hours="0";
		  minutes="0";
		  seconds=t[2];                                //colon count greater than 2 and seconds part is mentioned
		  hrs=atoi(hours.c_str());
          mins=atoi(minutes.c_str());
          secs=atoi(seconds.c_str());
         if((hrs<0)||(mins>60)||(mins<0)||(secs<0)||(secs>60))
		{
		  cerr<<"Invalid Time entry:"<<endl;
		  return;
		}
		else
		{	
		  total_secs=(hrs*3600+mins*60+secs);
		}
	      

  }
  else 
  {
	      hours="0";
		  minutes="0";
		  seconds="0";
		  hrs=atoi(hours.c_str());                     //for everything else it is taken as zero when colon count is greater than 2
          mins=atoi(minutes.c_str());
          secs=atoi(seconds.c_str());
        if((hrs<0)||(mins>60)||(mins<0)||(secs<0)||(secs>60))
		{
		  cerr<<"Invalid Time entry:"<<endl;
		  return;
		}
		else
		{	
		  total_secs=(hrs*3600+mins*60+secs);
		}
	      

  }
  
 }

 int Time :: get_seconds() const
 {
	 return(total_secs);
                                                //accessor for the number of seconds
 }

istream  &operator >>(istream &stream,Time &obj)
 {
	      string st; 
          stream>>st;
		  obj.set_time(st);                // Extraction operator
          return(stream);
  
}

ostream &operator <<(ostream &stream, const Time &obj) 
{
        
	      int hours=obj.get_seconds()/3600;
		  int result=obj.get_seconds()%3600;
          int mm=result/60;
          int ss=result%60;                           //Insertion operators displaying the hours minutes and seconds when mean,median and mode() are called

        stream<<hours << ":" << setfill('0') << setw(2)<< mm<<":"<<setfill('0') << setw(2)<<ss;			
	    
	    return(stream);
}


