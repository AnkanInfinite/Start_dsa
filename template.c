#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Highly recommended for returning true/false

// ==========================================
// 1. FUNCTION PROTOTYPES
// Declare your logic and helper functions here
// ==========================================
void printArray(int arr[], int size);
void executeLogic(int arr[], int size);


// ==========================================
// 2. MAIN EXECUTION
// Set up your test cases here
// ==========================================
int main() {
    // Hardcode a test case so you don't have to type inputs every time
    int testArray[] = {8, 3, 12, 5, 9, 1};
    
    // C doesn't know array sizes automatically. This calculates it:
    int size = sizeof(testArray) / sizeof(testArray[0]);

    printf("--- Before ---\n");
    printArray(testArray, size);

    // Call your algorithm
    executeLogic(testArray, size);

    printf("--- After ---\n");
    printArray(testArray, size);

    return 0; // Exit successfully
}


// ==========================================
// 3. ALGORITHM IMPLEMENTATION
// Write your Brute -> Better -> Optimal code here
// ==========================================
void executeLogic(int arr[], int size) {
    // TODO: Implement the daily problem logic here.
    // Example: A simple loop just to test the structure
    for(int i = 0; i < size; i++) {
        // manipulate arr[i]
    }
}

// Helper function to visualize what is happening to your data
void printArray(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n\n");
}