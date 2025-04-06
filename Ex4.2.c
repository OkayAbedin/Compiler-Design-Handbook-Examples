/*Example 4.2: Write a C program that implements a predictive parser using recursive descent techniques 
or a simplified expression grammar of a mini-language.*/

#include <stdio.h>
#include <string.h>

char input[100]; 
int pos = 0;

// Match expected token
void match(char expected) {
    if (input[pos] == expected) pos++;
    else { printf("Error: expected '%c'\n", expected); exit(1); }
}

// T → id
void T() {
    if (input[pos] == 'i' && input[pos+1] == 'd') pos += 2;
    else { printf("Error: expected id\n"); exit(1); }
}

// E' → + T E' | ε
void Eprime() {
    if (input[pos] == '+') { match('+'); T(); Eprime(); }
}

// E → T E'
void E() { T(); Eprime(); }

int main() {
    printf("Enter input (e.g., id+id): ");
    scanf("%s", input);
    
    E();
    if (input[pos] == '\0') printf("Parsing successful.\n");
    else printf("Error: Unexpected symbol at position %d\n", pos);
    return 0;
}