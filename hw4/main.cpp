// main.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "Statistics.h"
#include "Time.h"
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <set>
#include <vector>
using namespace std;


//@ author Shravya Narayan Sarma
//A Program that shows the basic functionality of containers over here Statistics is the container and Time is the basic data type


template< typename T >
int showStats( T data )
{
   try
   {
      cout << "min: " << data.min() << endl;
      cout << "max: " << data.max() << endl;
      cout << "mean: " << data.mean() << endl;
      cout << "median: " << data.median() << endl;
      cout << "mode: ";                                                  //showStats function displays the mean,median,mode min and max values

      set<typename T::value_type> mode = data.mode();
      ostream_iterator<typename T::value_type> out_it (cout," ");
      copy( mode.begin(), mode.end(), out_it );
      cout << endl;
   } 
   catch ( runtime_error &e )
   {
      cerr << "Runtime exception: " << e.what() << endl;
   }
   //return(1);
}



int main()
{
   Statistics<Time> stats;
   Time t;
   //Time t1(1250);
   //Time t2(350);
   //Time t3;
   while ( true )
   {
      try 
      {
         cin >> t;
      }
      catch ( runtime_error &e )
      {
         cerr << "Runtime exception: " << e.what() << endl;         //Get the input string from the standard input and invoke the overloaded
	                                                            //extraction operator
         continue;
      }
      if ( cin.eof() )
      {
         break;
      }
      stats.push( t );                                            //pushes the data to the statistics container
   }
   
   showStats(stats);                                             //Invoke the showstats()
   	return 0;
}

