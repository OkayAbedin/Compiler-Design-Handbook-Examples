/*Example 6.1: Write a C code to implement Basic Block Analysis from a given three-address code (TAC)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INSTRUCTIONS 100
#define MAX_BLOCKS 10

typedef struct { int start, end; } BasicBlock;
char tac[MAX_INSTRUCTIONS][100];
BasicBlock blocks[MAX_BLOCKS];

int isLeader(int i, int n) {
    if (i == 0) return 1;
    if (strstr(tac[i], "goto") || strstr(tac[i], "if")) return 1;
    if (strstr(tac[i-1], "goto") || strstr(tac[i-1], "if")) return 1;
    return 0;
}

void basicBlockAnalysis(int n) {
    int blockCount = 0;
    for (int i = 0; i < n; i++) {
        if (isLeader(i, n)) {
            if (i != 0) blocks[blockCount].end = i - 1;
            blocks[blockCount].start = i;
            blockCount++;
        }
    }
    blocks[blockCount-1].end = n - 1;
    
    for (int i = 0; i < blockCount; i++) {
        printf("Basic Block %d: Instructions %d to %d\n", i+1, 
            blocks[i].start, blocks[i].end);
        for (int j = blocks[i].start; j <= blocks[i].end; j++)
            printf("\t%s\n", tac[j]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of instructions: ");
    scanf("%d", &n);
    getchar(); // consume newline character left by scanf
    printf("Enter the three-address code instructions:\n");
    for (int i = 0; i < n; i++) {
        printf("Instruction %d: ", i + 1);
        fgets(tac[i], sizeof(tac[i]), stdin);
        tac[i][strcspn(tac[i], "\n")] = 0; // Remove trailing newline
    }
    basicBlockAnalysis(n);
    return 0;
}