/*Example 1.3: Write a C program that counts the character numbers in a string.*/

#include <stdio.h>

int main() {
    char sentence[200];
    int count = 0;
    printf("Enter a sentence: ");
    scanf("%[^\$]", sentence); // Read input until '$' is inserted
    // Count characters until null terminator
    while (sentence[count] != '\0') count++;
    printf("Character count: %d\n", count);
    return 0;
}