/*Example 5.2: Write a C program that takes user input for arithmetic expressions and validates if it is a Three-Address Code (TAC) or not.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVar(char *s) {
    return (strlen(s) == 1 && isalpha(s[0])) || (s[0] == 't' && isdigit(s[1]));
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main() {
    char line[100], lhs[20], op[2], rhs1[20], rhs2[20];
    printf("Enter expression: ");
    fgets(line, sizeof(line), stdin);

    // Remove newline
    line[strcspn(line, "\n")] = '\0';

    // Try format: x = y op z
    if (sscanf(line, "%s = %s %s %s", lhs, rhs1, op, rhs2) == 4) {
        if (isVar(lhs) && isVar(rhs1) && isOperator(op[0]) && isVar(rhs2)) {
            printf("Valid Three-Address Code (x = y op z)\n");
            return 0;
        }
    }

    // Try format: x = op y (unary op)
    if (sscanf(line, "%s = %s %s", lhs, op, rhs1) == 3) {
        if (isVar(lhs) && isOperator(op[0]) && isVar(rhs1)) {
            printf("Valid Three-Address Code (x = op y)\n");
            return 0;
        }
    }

    printf("Invalid TAC format\n");
    return 0;
}
