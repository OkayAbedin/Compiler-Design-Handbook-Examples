/*Example 2.3: Write a C program that counts the number of vowels and consonants in a sentence.*/

#include <stdio.h>

int main() {
    char sentence[200];
    int i = 0, vowels = 0, consonants = 0;
    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);
    
    while (sentence[i] != '\0') {
        char ch = sentence[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || 
                ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || 
                ch == 'o' || ch == 'u') {
                vowels++; // Increment vowels
            } else {
                consonants++; // Increment consonants
            }
        }
        i++;
    }
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    return 0;
}