/*Example 4.3: Write a C program that calculates the FIRST set for a given context-free grammar (CFG)
consisting of multiple production rules.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

void calculateFirst(char *grammar) {
    char firstSet[MAX];
    int j = 0;
    
    // Calculate FIRST set for each production rule
    for (int i = 0; grammar[i] != '\0'; i++) {
        if (islower(grammar[i])) firstSet[j++] = grammar[i];  // Add terminal symbols
    }
    firstSet[j] = '\0';  // Null-terminate
    printf("FIRST(%s) = %s\n", grammar, firstSet);
}

int main() {
    char grammar[MAX];
    printf("Enter grammar (type 'END' to stop):\n");
    
    // Input multiple lines of grammar
    while (1) {
        printf("Enter production rule: ");
        fgets(grammar, MAX, stdin);
        grammar[strcspn(grammar, "\n")] = 0;
        if (strcmp(grammar, "END") == 0) break;
        calculateFirst(grammar);
    }
    return 0;
}