#include <iostream>
#include <string>
using namespace std;

#ifndef RECURSION_H_
#define RECURSION_H_

class Recursion {

public:

	static int sumEvenDigits(int n) { // complete this function
      //If it is, then this digit contributes to the overall sum,
        //Base - Case
        if(n <= 0)
          {
            return 0;
          }
      
      //Checks if n is a even number and then adds it the sum
        if(n % 2 == 0)
          {
            return sumEvenDigits(n/10) + n%10;
          }
        return sumEvenDigits(n/10);
	}

	static void allBinaryStringsWithMoreOnes(int n) {
		allBinaryStringsWithMoreOnes("", 0, 0, n);
	}

private:

	static void allBinaryStringsWithMoreOnes(string str, int numZeroes,
			int numOnes, int n) { // complete this function
        //Prints all n-length binary strings having more ones than zeroes.
        //Base - Case
          if(str.length() == n && numZeroes < numOnes)
            {
              cout<<str<<" ";
              cout<<endl;
            }
          else if(str.length() < n)
            { 
              //Calling the function twice
              allBinaryStringsWithMoreOnes(str + "0", numZeroes + 1, numOnes, n);
              allBinaryStringsWithMoreOnes(str + "1", numZeroes, numOnes + 1, n);
            }
      }
          
	
};

#endif /* RECURSION_H_ */
