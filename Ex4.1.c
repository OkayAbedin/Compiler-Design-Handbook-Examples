/*Example 4.1: Write a C program to identify the number of single line and multiline comments in an input C code.*/

#include <stdio.h>

int main() {
    char code[1000], ch;
    int i = 0, single = 0, multi = 0, state = 0;
    printf("Enter C code (end with $):\n");
    
    while ((ch = getchar()) != '$') code[i++] = ch;
    code[i] = '\0'; // Null-terminate the input string
    
    for (i = 0; code[i]; i++) {
        // Detect start of single-line comment
        if (state == 0 && code[i] == '/' && code[i + 1] == '/') 
            state = 1, single++, i++;
        // Detect start of multi-line comment
        else if (state == 0 && code[i] == '/' && code[i + 1] == '*') 
            state = 2, multi++, i++;
        // End of single-line comment
        else if (state == 1 && code[i] == '\n') state = 0;
        // End of multi-line comment
        else if (state == 2 && code[i] == '*' && code[i + 1] == '/') 
            state = 0, i++;
    }
    
    printf("Single-line comments: %d\n", single);
    printf("Multi-line comments: %d\n", multi);
    return 0;
}