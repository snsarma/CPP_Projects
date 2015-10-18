#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <libgen.h>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

bool operator < (const string & fv,const string &fv1) 
{

    return(fv.compare(fv1)<0);
   
}

int main(int argc,char *argv[])
{

 vector <string> filevecs(1000);
 int index=0;
 
 if(argc!=2)
 {
    
    cerr<<"Usage:\t"<<endl;
    cerr<<endl;
    cerr<<basename(argv[0])<<"  "<<"filename:"<<endl;
 }

 else if(argc==2)
 {

   
  ifstream input;
  input.open(argv[1]);
  
  if(input.fail())
  {

   cerr<<basename(argv[1])<<" "<<":does not exit"<<endl;
   exit(2);
  }
  else
  {
    //int i=0;
    char city[40];
    while(!input.eof())
    {
     
     input.getline(city,40,' ');
    char chars[] = "-,.''!?/}{[]<>:;|^";
    string s;
    s=city;
    int count;
    for(count=0;chars[count]!='\0';++count)
               ;
   
    
   for (unsigned int i = 0; i < count; ++i)
   {
      
      s.erase (std::remove(s.begin(), s.end(), chars[i]), s.end());
   } 
    filevecs.at(index)=s;
    cout<<s<<endl;
    ++index;
    }
     
  }
  vector <string>::iterator it;
  //std::sort(filevecs.begin(),filevecs.end());  
  for(int i=0;i<index-1;i++ )
  {
  
    int count_no=count(filevecs.begin(),filevecs.end(),filevecs[i]);
     cout<<filevecs[i]<<" "<<count_no<<endl;

  }
   
 input.close();
 }
 return(0);
}
