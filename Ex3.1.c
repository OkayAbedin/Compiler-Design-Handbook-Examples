/*Example 3.1: Write a C program that checks if an input string follows the regex b*(a b* a b*)*.*/

#include <stdio.h>

int main() {
    char str[200]; 
    int i = 0, valid = 1;
    printf("Enter a string: "); 
    scanf("%s", str); // input without spaces
    
    while (str[i] == 'b') i++; // b*
    while (str[i] != '\0') {
        if (str[i] != 'a') { valid = 0; break; }
        i++; while (str[i] == 'b') i++;
        if (str[i] != 'a') { valid = 0; break; }
        i++; while (str[i] == 'b') i++; // b*
    }
    if (valid) printf("Valid\n"); else printf("Invalid\n");
    return 0;
}