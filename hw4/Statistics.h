#ifndef _STATISTICS_H_
#define _STATISTICS_H_
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <functional>

template< class T >
class Statistics
{
public:
   /**
    * Calculate the mean (average) of the data entered.
    *
    * @return the mean of the data pushed into our data set
    */typedef T value_type;
   T mean()
   {
	   T res;
	   int count_no=TimeObjs.size();
	   int result=0;
	   res=accumulate(TimeObjs.begin(),TimeObjs.end(),T(0));  //Accumulate function to add up and calculate the average
	   res/=count_no;
	   //for(int i=0;i<TimeObjs.size();i++)
	    //{
	      //   result=result+(TimeObjs[i].get_seconds());
	    
	   // }
	   //std::cout<<"Result:"<<result<<std::endl;
	   //std::cout<<"Count no:"<<count_no<<std::endl;
	   //std::cout<<"Res seconds:"<<res.get_seconds();
	   //std::cout<<"Mean method";
           return(res);
   }
   /**
    * Calculate the median (middle element when the data is sorted)
    *
    * @return the mode of the data pushed into our data set
    */
   T median()
   {
	   sort(TimeObjs.begin(),TimeObjs.end());
	   int size=TimeObjs.size();
	   if((size%2)==0)                                               //sort the vector and check if the size or the number of elements is even
		   return(TimeObjs[size/2]+TimeObjs[(size-1)/2])/2;      //If it is even take the average of the mid and the prev one to mid element
	   else
		   return(TimeObjs[size/2]);                             //If it is odd it is the mid element
	   
   }
   /**
    * Calculate the mode (most common element). 
    *
    * @return a set of the most common elements.  This can be the empty set if
    * there is a uniform distribution
    */
  std::set<T> mode()
  {
	  typedef T value_type;
	  typename std::set<T> myset;
         typename std::vector<T>::iterator it;
	  int max_count=1;                                              //Let's consider the maximum count to be 1 as in 1 to be the minimum frequency
         int count_no;
	  for(it=TimeObjs.begin();it!=TimeObjs.end();it++)
	  {
		  count_no=count(TimeObjs.begin(),TimeObjs.end(),*it);  //Iterate through the entire vector and count the frequency of each element
		  if(count_no>max_count)
		  {
			  max_count=count_no;                        //If it is greater than max_count update it each time
		  }
		  
	  }

	  if(max_count==1)
	  {
		return(myset);                                   //If there is just one occurence of each element return an empty set 
	  }


	  for(it=TimeObjs.begin();it!=TimeObjs.end();it++)
	  {
		  int count_no=count(TimeObjs.begin(),TimeObjs.end(),*it);
		  
		  
		  if(count_no==max_count)
		  {
			  myset.insert(*it);                      //if frequency is more add it to the set
		  }

	  }
	  
	  return(myset);          // return the set
	   
	   
  }
   /**
    * Get the value of the smallest element
    *
    * @return the minimum value of the data pushed in 
    */
   T min()
   {
	   	   
	   return(*std::min_element(TimeObjs.begin(),TimeObjs.end()));  //return the minimum element
   }
   /**
    * Get the value of the largest element
    *
    * @return the maximum value of the data pushed in 
    */
   T max()
   {
	   
	   return(*std::max_element(TimeObjs.begin(),TimeObjs.end())); // return the max element which invokes the > operator
	   

   }
   /**
    * Add an element to our data set
    *
    * @param t Element to add to our data
    */
   void push( T t )
   {
	   
	   TimeObjs.push_back(t);          //push it to the Statistics container
   }
   /**
    * Removes all elements from the data
    */
   void clear()
   {
	   TimeObjs.clear();         //clear the elements

   }

private: 
	std::vector<T> TimeObjs;  //container to hold the Time Objects
};
#endif // _STATISTICS_H_
