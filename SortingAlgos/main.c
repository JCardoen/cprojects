#include <stdio.h>
#include <stdlib.h>

// Function declarations
char *askForUserInput();
void selectionSort(char *stringToSort); // 30: execution time : 3.259 s, 60:  execution time : 3.022 s
void insertionSort(char *stringToSort); // 30: execution time : 3.329 s, 60: execution time :  2.833 s
void shellSort(char *stringToSort); // 30: execution time : 3.258 s, 60: execution time : 3.318 s
void swap(char *stringToSwap, int firstIndex, int secondIndex);

// SHELLSORTEXAMPLESHELLSORTEXAMPSHELLSORTEXAMPLESHELLSORTEXAMP

// Function bodies
void swap(char *stringToSwap, int firstIndex, int secondIndex) {
    char firstValue = stringToSwap[firstIndex];
    char secondValue = stringToSwap[secondIndex];

    stringToSwap[firstIndex] = secondValue;
    stringToSwap[secondIndex] = firstValue;
}

char *askForUserInput() {
    char *stringToSort = malloc(60);
    printf("Which string would you like to sort? (maximum amount of characters is 30), default value = ZXYWSADFRO \n");
    scanf("%s", stringToSort);

    if(stringToSort[0] == '0') {
        stringToSort = "ZXYWSADFRO";
        return stringToSort;
    } else {
        return stringToSort;
    }
}

void shellSort(char *stringToSort) {
    int sizeOfString = 60;

    printf("String to sort: %s \n", stringToSort);

    // Initialize batch of 1
    int batchSize = 1;

    // Calculate boundary of batch
    while(batchSize < sizeOfString / 3) batchSize = 3 * batchSize + 1;

    // Loop
    while(batchSize >= 1) {
        // Loop all values of the string to sort
        for(int iterator = batchSize; iterator < sizeOfString; iterator++) {

            // Loop all elements to the left the currently selected element
            for (
                int secondIterator = iterator;
                secondIterator >= batchSize && (int) stringToSort[secondIterator] < (int) stringToSort[secondIterator - batchSize];
                secondIterator -= batchSize
            ) {
                // Swap elements, pass by reference using the pointer
                swap(stringToSort, secondIterator, secondIterator - 1);
            }
        }

        // Divide batch size
        batchSize = batchSize / 3;

        printf("Batch size of: %i \n", batchSize);
    }
}

void insertionSort(char *stringToSort) {
    int sizeOfString = 60;

    printf("String to sort: %s \n", stringToSort);

    // Loop all values of the string to sort
    for(int iterator = 1; iterator < sizeOfString; iterator++) {

        // Loop all elements to the left the currently selected element
        for(int secondIterator = iterator; secondIterator > 0 && (int) stringToSort[secondIterator] < (int) stringToSort[secondIterator - 1]; secondIterator--) {
            // Swap elements, pass by reference using the pointer
            swap(stringToSort, secondIterator, secondIterator - 1);
        }
    }
}

void selectionSort(char *stringToSort) {
    int sizeOfString = 60;

    printf("String to sort: %s \n", stringToSort);

    // Loop all values of the string to sort
    for(int iterator = 0; iterator < sizeOfString; iterator++) {

        // Set minimum value to the iterator
        int indexOfSmallestElement = iterator;

        // Loop over each value next to the current value from the above loop
        // Check if the value is smaller and set the indexOfSmallestElement as the index of the second iteration
        // Swap the elements
        for(int secondIterator = iterator + 1; secondIterator < sizeOfString; secondIterator++) {
            // Retrieve ASCII values
            int asciiValOfCurrentChar = (int) stringToSort[secondIterator];
            int asciiValOfSmallestChar = (int) stringToSort[indexOfSmallestElement];
            if(asciiValOfCurrentChar < asciiValOfSmallestChar) { indexOfSmallestElement = secondIterator; }

            // Swap elements, pass by reference using the pointer
            swap(stringToSort, iterator, indexOfSmallestElement);
        }
    }
}

int main()
{
    printf("Select a sorting algorithm: \n");
    printf("1. Selection sort\n");
    printf("2. Insertion sort\n");
    printf("3. Shell sort\n");

    char choiceForAlgorithm = getchar();

    switch(choiceForAlgorithm) {
        case '1': {
            char *stringToSort;
            stringToSort = askForUserInput();
            selectionSort(stringToSort);
            printf("Sorted string: %s", stringToSort);
            free(stringToSort);
            break;
        };
        case '2': {
            char *stringToSort;
            stringToSort = askForUserInput();
            insertionSort(stringToSort);
            printf("Sorted string: %s", stringToSort);
            free(stringToSort);
            break;
        };
        case '3': {
            char *stringToSort;
            stringToSort = askForUserInput();
            shellSort(stringToSort);
            printf("Sorted string: %s", stringToSort);
            free(stringToSort);
            break;
        };
    }

    return 0;
}
