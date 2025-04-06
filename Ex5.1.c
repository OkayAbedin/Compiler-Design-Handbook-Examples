/*Example 5.1: Write a C program that takes user input
for arithmetic expressions and generates Three-Address Code (TAC).*/

#include <stdio.h>
#include <string.h>

char expr[100], temp = 't';
int idx = 0;

void tac(char *e) {
    int len = strlen(e);
    if (len == 1) return; // single variable
    int i;
    
    for (i = len - 2; i > 0; i--) {
        if (e[i] == '+' || e[i] == '-' || e[i] == '*' || e[i] == '/') 
            break;
    }
    
    char op = e[i];
    char a = e[i - 1], b = e[i + 1];
    printf("%c = %c %c %c\n", temp, a, op, b);
    e[i - 1] = temp;
    temp++;
    strcpy(&e[i], &e[i + 2]); // remove processed part
    tac(e);
}

int main() {
    printf("Enter fully parenthesized expression (e.g., (a+b*c)): ");
    scanf("%s", expr);
    tac(expr);
    return 0;
}