/*Example 3.2: Write a C program that checks if an email address is valid or not.*/

#include <stdio.h>

int main() {
    char email[200]; 
    int i = 0, at = 0, dot = 0, valid = 1;
    printf("Enter an email: "); 
    scanf("%s", email); // read input
    
    while (email[i] != '\0') {
        if (email[i] == ' ') { valid = 0; break; } // no space
        if (email[i] == '@') { 
            if (at || i == 0 || email[i+1] == '\0') { 
                valid = 0; break; 
            } 
            at = 1; 
        }
        if (at && email[i] == '.' && email[i+1] != '\0') dot = 1; // dot after @
        i++;
    }
    if (valid && at && dot) printf("Valid\n"); 
    else printf("Invalid\n");
    return 0;
}