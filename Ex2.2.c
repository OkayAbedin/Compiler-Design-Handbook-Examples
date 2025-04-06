/*Example 2.2: Write a C program that removes special characters from a sentence.*/

#include <stdio.h>

int main() {
    char sentence[200], result[200];
    int i = 0, j = 0;
    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);
    
    while (sentence[i] != '\0') {
        if ((sentence[i] >= 'A' && sentence[i] <= 'Z') || 
            (sentence[i] >= 'a' && sentence[i] <= 'z') || 
            (sentence[i] >= '0' && sentence[i] <= '9') || 
            (sentence[i] == ' ')) {
            result[j++] = sentence[i]; // Add letters, digits, and spaces to result
        }
        i++;
    }
    result[j] = '\0'; // Null-terminate the result
    printf("Processed sentence: \"%s\"\n", result);
    return 0;
}