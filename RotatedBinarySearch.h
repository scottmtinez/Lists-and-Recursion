ifndef ROTATEDBINARYSEARCH_H_
#define ROTATEDBINARYSEARCH_H_

class RotatedBinarySearch {

public:

	static int search(int *array, int length, int key) { // complete this function
    //Find the index of the maximum value in the array
      int index;
      int maxInd = maxIndex(array, array[length - 1], 0, length - 1); 

    //If key equals array[maxInd], return maxIndex
      if(key == array[maxInd])
        {
          return maxInd;
        }
    
    //If key ≥ array[0], then binary search the array from index 0 to maxIndex − 1 (both inclusive) and return the index //found by binary search
      if(key >= array[0])
        {
          //Binary search the array from index 0 to maxIndex - 1
           index =  binarySearch(array, 0, maxInd - 1, key);

          //Return index found by binary search
            return index;
        }
      else //Else binary search the array from index maxIndex+1 to the last index (both inclusive) and return the index found by binary search
        {
          //Binary search the array from index 
            index = binarySearch(array, maxInd + 1, length - 1, key);
          
          //Return the index founnd by Binary search
            return index;
        }
      
	}

	static int maxIndex(int *array, int lastValue, int left, int right) { // complete this function
      //The base-case is when left equals right; here, you return left.
        if(left == right)
          {
            return left;
          }
      
      //Compute
        int mid = (left+right)/2;
      
      //If value exceeds value
        if(array[mid] > array[mid + 1])
          {
            return mid; 
          }
        else if(array[mid] < array[right])
          {
            return maxIndex(array, lastValue, left, mid - 1);
          }
        else 
          {
            return maxIndex(array, lastValue, mid + 1, right);
          }
	}

	static int binarySearch(int *array, int left, int right, int key) {
		if (left <= right) {
			int mid = (left + right) / 2;
			if (array[mid] == key) {
				return mid;
			} else if (array[mid] < key)
				return binarySearch(array, mid + 1, right, key);
			else
				return binarySearch(array, left, mid - 1, key);
		}
		return -1;
	}
};

#endif /* ROTATEDBINARYSEARCH_H_ */
