/*Example 1.1: Write a C program that takes a sentence as input and prints it.*/

#include <stdio.h>

int main() {
    char sentence[200];
    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence); // Read input including spaces
    printf("You entered: %s\n", sentence);
    return 0;
}