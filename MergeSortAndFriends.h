#include <iostream>
#include <vector>
using namespace std;

#ifndef MERGESORTANDFRIENDS_H_
#define MERGESORTANDFRIENDS_H_

class MergeSortAndFriends {

private:

	static int *binaryMerge(int *A, int *B, int lenA, int lenB) { // complete this function
    //4.2
      //Task #1: Implement the binaryMerge Method
      //From Notes
        int lenC = lenA + lenB;
        int *C = new int[lenC]; //Array for C of length lenC

      //While Loop, runs while a < lenA & b < lenB
        int a = 0, b = 0, c = 0;
        while(a < lenA && b < lenB)
          {
            //If Else statement to see if array A is less than array B
              if(A[a] < B[b])
                {
                  //Copy array A to C
                    C[c] = A[a];
                    a++;
                }
              else
                {
                  //Copy array B to C
                    C[c] = B[b];
                    b++;
                }
              c++;
          }

      //While Loop, while a<lenA
        while(a < lenA)
          {
            //Copy array A to C
              C[c] = A[a];
              a++;
              c++;
          }
        
      //While loop, while b<lenB
        while(b < lenB)
          {
            //Copy array B to C
              C[c] = B[b];
              b++;
              c++;
          }

      return C; 
	}

public:

	static vector<int> commonElements(int *A, int *B, int lenA, int lenB) { // complete this function
  //4.3 
    //Task #2: Implement the numCommonElemenets Method
    //Create a dynamic array
      vector <int> dyanmicArray; 

    //Initialize a and b
      int a = 0, b = 0;
    
    //While loop that runs as a < LenA && b <lenB.
      while(a < lenA && b < lenB)
        {
          //If, Else if, else  
            if(A[a] < B[b])
              {
                a++;
              }
            else if(A[a] > B[b])
              {
                b++;
              }
            else  
              {
                //Add A[a] to dyanmic array
                  dyanmicArray.push_back(A[a]);
                  a++;

                //Skip all repeated occurences of A[a]
                  while(a<lenA && A[a] == B[b])
                    {
                      a++;
                    }
              }
        }
      return dyanmicArray; //dyanimc array
	}

	static int *kWayMerge(int **lists, int *listLengths, int k) { // complete this function
    //4.3.1
      //Task #3: Implement the kWayMerge Method
        //If statement 
          if(k == 1)
            {
              //Usign one sorted array
              //Return the first row of jagged array lists.
                return lists[0];
            }
          else if(k == 2)
            {
              //Using two sorted arrays
                return binaryMerge(lists[0], lists[1], listLengths[0], listLengths[1]); 
            }
          else
            {
              //Declare integer
          int newK = (k+1)/2;
        
        //Create a jagged array
          int **mergedList = new int *[newK];
          int *mergedListLengths = new int[newK];

        //Merge with for loops
          for(int i = 0; i <= k/2-1; i++)
            {
              //Set the sum of
                mergedListLengths[i] = listLengths[2*i] + listLengths[(2*i) + 1];
              
              //Set by merging two arrays together
              //Merge lists[2i] and lists[2i+1]
                mergedList[i] = binaryMerge(lists[2*i], lists[(2*i)+1],listLengths[2*i], listLengths[(2*i) + 1]);
            }
          
        //If k is odd statement
          if(k % 2 != 0) 
            {
              //Set
                mergedList[newK - 1] = lists[k - 1];
                mergedListLengths[newK - 1] = listLengths[k - 1];
            }
        
        //Recurviely call and return kWayMerge
          return kWayMerge(mergedList, mergedListLengths, newK);

            }
        
   
	}

	static void mergesort(int *array, int left, int right) {
		if (left < right) {
			int mid = (left + right) / 2;
			mergesort(array, left, mid);
			mergesort(array, mid + 1, right);
			int *mergedArray = binaryMerge(&array[left], &array[mid + 1],
					mid - left + 1, right - mid);
			int i = left;
			int j = 0;
			while (j <= right - left)
				array[i++] = mergedArray[j++];
			delete[] mergedArray;
		}
	}
};

#endif /* MERGESORTANDFRIENDS_H_ */
