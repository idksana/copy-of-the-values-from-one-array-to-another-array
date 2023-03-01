
/*
Sana Abbasi
netid: sabbas29
uin: 662260656
proj1
*/

#include <stdio.h>
#include <stdlib.h>

void makeArrayCopy (int fromArray[], int toArray[], int size){
  //function that will make a copy of the values from one array to another array.
  int i;
  for (i = 0; i < size; i++) {
        toArray[i] = fromArray[i];
    }
}

void myFavoriteSort (int arr[], int size){
  // function that will sort an array in ascending order.
  int i;
  int j;
  int temp;
  for(i = 0; i < size; i++) {
        for(j = i + 1; j < size; j++){
            if(arr[i] > arr[j]) { 
              // if element at i is greater than element at j in the array we are going to switch places of the number      
              temp = arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
            }
        }
  }
}

int indexComparison(int unsortedArray[],int sortedArray[],int size){
  //function that performs an element-wise comparison between two arrays and returns the number of elements that remained in the same location/index after sorting. The prototype MUST match the following call. The return type of indexComparison( ) must be void. 
    int i = 0;
    int counter= 0;
    for(i=0; i<size; i++) {
        if(unsortedArray[i] == sortedArray[i]) {
           (counter)++;
        }
    }
    return counter;
}

int targetSum (int arr[], int size, int target,int *index1, int *index2){
	int insideIndex1 = 0;
	int insideIndex2 = size - 1;
	int indexVal;
	for(indexVal = 0; indexVal < size - 1; indexVal++){
		if ((arr[insideIndex1]+arr[insideIndex2]) == target){
			*index1 = insideIndex1;
			*index2 = insideIndex2;
			return 1;
		}
		if ((arr[insideIndex1]+arr[insideIndex2])<target){
			insideIndex1++;
		}
		if ((arr[insideIndex1]+arr[insideIndex2])>target){
			insideIndex2--;
		}
	}
	return -1;
}



int main (int argc, char** argv){
 int val; 
 int userInput; 

 /* prompt the user for input */
 printf ("Enter in a list of numbers to be stored in a dynamic array.\n");
 printf ("End the list with the terminal value of -999\n");

 int k;
 int i=0;
 int *arr;
 int size = 10; //intital size 
 arr = (int *) malloc (size * sizeof(int));
 scanf ("%d", &val);

/* loop until the user enters -999 */
 while(val != -999){
      // sampling from week 2 lecture's code
    	if(i >= size){
           //set tmp to refer to the location of old array
    		int *tmp ; 
    		tmp = arr; 
        //allocate new space for the larger array
    		arr = (int*)malloc(sizeof(int)*size*2); 

        //copy the existing values from the original array to the larger array
    		for(k = 0 ; k < size ; k++)
    			arr[k] = tmp[k];
            //return the allocated memory from the original array back to the OS
    		  free(tmp);

            //update the size1 variable to properly reflect the current size of the array
    		  size = size *2; 
    	}

        //store values in array
      arr[i] = val ; 
      i++;
      scanf("%d", &val);

    //store the value into an array 

    //get next value 
  
   } // end of week 2 lectures code



int *copy;
copy = (int *) malloc (size * sizeof(int));

makeArrayCopy(arr, copy, i);
myFavoriteSort(copy, i);

 printf("Enter 1 to perform index comparison, enter 2 to perform target sum.\n");

 scanf ("%d", &userInput);


if ((userInput != 1) && (userInput != 2)){
  // if not 1 or 2 then print Invalid input. Enter 1 or 2.
 	printf("Invalid input. Enter 1 or 2.\n");
  scanf ("%d", &userInput);

 }

 if(userInput == 1){
   // enters 1 after entering original array to see if wanted index comparions
 	int counter = indexComparison(arr, copy, i);
 	if(counter == 0){
 		printf("All elements change location in the sorted array.\n"); 
	}
	else{
		printf("%d values are in the same location in both arrays.\n",counter);
	}
 
 }

 if(userInput == 2){

 	printf ("Enter in a list of numbers to use for searching.  \n");
 	printf ("End the list with a terminal value of -999\n");
 	int index1 = 0;
 	int index2 = 0;
 	
 	scanf ("%d", &val);
 	while (val != -999){
	 	int output = targetSum (copy, i, val, &index1, &index2);
	 	if(output == 1 & val != 2){
	    	printf ("Success! Elements at indices %d and %d add up to %d\n", index1, index2, val);
		}
		else if(val == 2){
			printf ("Target sum failed!\n");
		}
		else{
			printf ("Target sum failed!\n");
		}
    

		scanf ("%d", &val);
     }



   	
 }
 
 printf ("Good bye");
 return 0;
} 
