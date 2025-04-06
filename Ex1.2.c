/*Example 1.2: Write a C program that takes multiple sentences as input and prints it.*/

#include <stdio.h>

int main() {
    char sentence[200];
    printf("Enter a sentence: ");
    scanf("%[^\$]", sentence); // Read input until '$' inserted
    printf("You entered: %s\n", sentence);
    return 0;
}