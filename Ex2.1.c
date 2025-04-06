/*Example 2.1: Write a C program that removes extra whitespace from a sentence.*/

#include <stdio.h>

int main() {
    char sentence[200], result[200];
    int i = 0, j = 0;
    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);
    
    while (sentence[i] == ' ') i++; // Remove leading spaces
    while (sentence[i] != '\0') {
        if (sentence[i] != ' ' || (i > 0 && sentence[i - 1] != ' ')) 
            result[j++] = sentence[i];
        i++;
    }
    result[j] = '\0'; // Null-terminate the result
    printf("Processed sentence: \"%s\"\n", result);
    return 0;
}