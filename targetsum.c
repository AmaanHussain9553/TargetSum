#include "stdio.h"
#include "stdlib.h"


//Function to sort numbers in ascending order
//using bubble sort
void sortNumerical(int *array,int counter){
    for (size_t j = 0; j < counter-1; j++) {
        for (int i = 0; i < counter-1 ; i++) {
            if (array[i] > array[i + 1]) {
                int swap = 0;
                swap = array[i + 1];
                array[i + 1] = array[i];
                array[i] = swap;
            }
        }
    }
}


//Function to display array for debugging
void displayArray(int *array, int counter){
    for(size_t i = 0; i < counter; i++){
        printf("%d\n", array[i]);
    }
}


//Function to make a copy of an array and use that so that
//the original array entered for user is not manipulated
void copyArray(int *array, int* copyarray, int counter){
    for(size_t i = 0; i < counter; i++){
        copyarray[i] = array[i];
    }
}


//Function that performs the search for two indexes that sum up to give
//up the search value entered by user
int* findTargetSum(int target, int* copyArray, int counter){
    int *resultArray = (int*)malloc(2* sizeof(int)); //creating array of size 2 to
                                                         //store index values
    //initializing index values to identify later
    //if indexes found or not
    resultArray[0] = -999;
    resultArray[1] = -999;

    //setting two variables to change indexes based on search value
    //based on added values of two indexes
    int i = 0;
    int j = counter - 1;

        while(i != j){
            if((copyArray[i] + copyArray[j]) == target){
                resultArray[0] = i; //storing index values in pointer array
                resultArray[1] = j;
                return resultArray; //returning pointer array that has index values
            }
            else if((copyArray[i] + copyArray[j]) < target){
                i++; //if indexed added value less than searchValue move low right
            }
            else if((copyArray[i] + copyArray[j]) > target){
                j--; //if indexed added value less than searchValue move high left
            }
    }
        return resultArray; //returning pointer array that has index values

}


int main (int argc, char** argv)
{
    /*declaration of variables */
    int val;
    int *originalMatrix;
    int capacity = 100;
    originalMatrix = (int*) malloc(capacity*sizeof(int));

    /* prompt the user for input */
    printf ("Enter in a list of numbers ito be stored in a dynamic array.\n");
    printf ("End the list with the terminal value of -999\n");

int counter = 0;
    /* loop until the user enters -999 */
    scanf ("%d", &val);
    while (val != -999)
    {
        originalMatrix[counter] = val;

        //increasing size of original matrix if it reaches capacity
        if((counter-1) == capacity){
            int* tempMatrix = (int*)malloc(2*capacity*sizeof(int));
            for(size_t i = 0; i < (counter - 1); i++){
                tempMatrix[i] = originalMatrix[i];
            }
            originalMatrix = tempMatrix;
            free(tempMatrix);
        }
        counter ++;
        scanf("%d", &val);
    }

    int sizeArray = counter; //setting a size to search through


    //creating new pointer to array and storing all values
    int* copyMatrix;
    copyMatrix = (int*)malloc(capacity* sizeof(int));
    copyArray(originalMatrix, copyMatrix, sizeArray);


    /* call function to sort one of the arrays */
    sortNumerical(copyMatrix, sizeArray);

    //initializing new matrix to store the values
    //to be searched
    int* searchMatrix;
    searchMatrix = (int*)malloc(capacity* sizeof(int));
    int searchCounter = 0;

    /* loop until the user enters -999 */
    printf ("Enter in a list of numbers to use for searching.  \n");
    printf ("End the list with a terminal value of -999\n");
    scanf ("%d", &val);
    while (val != -999)
    {
        searchMatrix[searchCounter] = val;

        //increases size of array incase it reaches capacity size
        if((searchCounter-1) == capacity){
            int* tempMatrix1 = (int*)malloc(2*capacity*sizeof(int));
            for(size_t i = 0; i < (counter - 1); i++){
                tempMatrix1[i] = searchMatrix[i];
            }
            searchMatrix = tempMatrix1;
            free(tempMatrix1);
        }

        //setting to a pointer array of size two where the indexes are stored.
        int* check = findTargetSum(searchMatrix[searchCounter], copyMatrix, sizeArray);

        if (check[0] != -999 || check[1] != -999) {//if values are not -999 that means found
            printf("Target sum successful\n");
            printf("Target index 1 is %d\n", check[0]);
            printf("Target index 2 is %d\n", check[1]);
        }
        else{ //if values are -999 that means not found
            printf("Target sum unsuccessful, no two indexes add up to search value\n");
        }

        searchCounter++;
        /* get next value */
        scanf("%d", &val);
    }
    printf ("Good bye\n");
    return 0;
}
