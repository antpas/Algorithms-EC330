/*
Anthony Pasquariello
BUID: U04061063
Homework 2
*/

#include <iostream>
#include <fstream>
#include "MaxProduct.h"
using namespace std;

long MaxProductClass::MaxProduct(const char *filename){

	ifstream infile(filename);

	//This will check if file opens successfully
	if(infile.is_open())
	{
		int n;
		int count = 0;
    int maxcount = 0;
		int myArray[10000];
    int maxArray[10000];
    int temp;
    int currentmax;
 		
 		while (! infile.eof() )   //While there are numbers in the file
    	{
      		infile >> n;
      		if(n != -999999) //
      		{
	      		myArray[count] = n;    //Reads each num and puts it into array
	      		count++;
      		}

      		else if(n == -999999)
      		{	
      			  for (int i=0; i<count; i++)
      			  {
           				
                if(count > 2)
                {
                  if(myArray[i] > currentmax)
                  {
                    currentmax = myArray[i];
                  }

                  if (myArray[i]*myArray[i+1] > currentmax)
                  {
                    currentmax = myArray[i] * myArray[i+1];
                  }

                  if (myArray[i]*myArray[i+1]*myArray[i+2] > currentmax)
                  {
             			 		currentmax = myArray[i] * myArray[i+1] * myArray[i+2];
                  }
                }
                else if(count == 2)
                {
                  currentmax = myArray[0] * myArray[1];
                }
                else if(count == 1)
                {
                  currentmax = myArray[0];
                }
                  
        			}
              if(count != 0) //This is here to make sure a zero isn't outputted if there's a blank line following the input.txt numbers
              {
                cout << currentmax << endl; 
                maxArray[maxcount] = currentmax;
                maxcount++;
                count = 0;
                currentmax = 0;
              }
              
    	    }
      }

      //Sorts max value array in increasing order
      for (int i=0; i<maxcount; i++)
      {
        for (int j=i+1; j<maxcount; j++)
        {
          if (maxArray[j] > maxArray[i])
          {
            temp = maxArray[i];
            maxArray[i]= maxArray[j];
            maxArray[j] = temp;
          }
        }
      }

		infile.close();	

		return maxArray[0];
	}
	else
		cout << "Error: File did not open correctly!" << endl;
}