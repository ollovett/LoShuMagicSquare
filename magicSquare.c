#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool magicSquare(int array[3][3]);

int main(){
    //call magic square test method with array that is a magic square
    int testArray1[3][3] = {{4, 9, 2},
                            {3, 5, 7},
                            {8, 1, 6}};
    if (magicSquare(testArray1) == 1){
        printf("Array 1 is a Lo Shu Magic Square.\n");
    }
    else {
        printf("Array 1 is not a Lo Shu Magic Square.\n");
    }

    //call magic square test method with array that is not a magic square
    int testArray2[3][3] = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};
    if (magicSquare(testArray2) == 1){
        printf("Array 2 is a Lo Shu Magic Square.\n");
    }
    else {
        printf("Array 2 is not a Lo Shu Magic Square.\n");
    }

    bool found = false;
    int array2[3][3];
    int counter = 0;
    srand(time(NULL));

   while (!found){
        //initialize 1d array
        int array1[9];
        int random;
        int unique;

        //reset array 1 to all zero
        for (int i = 0; i < 9; i++){
            array1[i] = 0;
        }
        
        //gen random unique numbers
        for (int i = 0; i < 9; i++){
            do {
                random = (rand() % 9) + 1;
                unique = 1;
                    for (int j = 0; j < i; j++){
                        if (array1[j] == random){
                            unique = 0;
                        }
                    }
            }
            while (unique == 0);
            array1[i] = random;
        }

        //copy array1 into 2d array
        int k = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                array2[i][j] = array1[k];
                k++;
            }
        }
        //test 2d array
        if (magicSquare(array2) == true){
            found = true;
            break;
        }
        counter++;
    }   
    //print counter
    printf("Amount of random squares created: %d\n", counter);
    //print square
    printf("Randomly generated square: \n");
    printf("[%d, %d, %d]\n[%d, %d, %d]\n[%d, %d, %d]\n", array2[0][0], array2[0][1], array2[0][2],
                                                        array2[1][0], array2[1][1], array2[1][2],
                                                        array2[2][0], array2[2][1], array2[2][2]);
    return 0;
}

bool magicSquare(int array[3][3]){
    //add each element in all rows together and store in variables for each row
    int row1;
    int row2;
    int row3;
    row1 = array[0][0] + array[0][1] + array[0][2];
    row2 = array[1][0] + array[1][1] + array[1][2];
    row3 = array[2][0] + array[2][1] + array[2][2];
    //do same as above but for columns
    int column1;
    int column2;
    int column3;
    column1 = array[0][0] + array[1][0] + array[2][0];
    column2 = array[0][1] + array[1][1] + array[2][1];
    column3 = array[0][2] + array[1][2] + array[2][2];
    //do same for diagonals
    int diagonal1;
    int diagonal2;
    diagonal1 = array[0][0] + array[1][1] + array[2][2];
    diagonal2 = array[0][2] + array[1][1] + array[2][0];
    //compare all variables
        if (row1 == row2 && row1 == row2 && row1 == row3
            && row1 == column1 && row1 == column2 && row1 == column3
            && row1 == diagonal1 && row1 == diagonal2){
                return true;
            }
        else{
            return false;
        }
}