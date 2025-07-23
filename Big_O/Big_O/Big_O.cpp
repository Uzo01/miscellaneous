// Big_O.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printUNorderPairs(int arrayA[], int arrayB[], int sizeA, int sizeB) {
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (arrayA[i] < arrayB[j]) {
                std::cout << arrayA[i] << "," << arrayB[j] << std::endl;
            }
        }
    }
}

int main() {
    int array1[] = { 22,3,4,6,2,1,4,6 };
    int array2[] = { 1,2,4,5,77,5,43 };

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    printUNorderPairs(array1, array2, size1, size2);

    return 0;
}



 
