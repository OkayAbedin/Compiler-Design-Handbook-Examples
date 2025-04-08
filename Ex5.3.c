/*Example 5.3: Write a C program that checks whether a user-entered line of code is a valid for loop header or not.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidForLoop(char *line) {
    while (*line == ' ') line++; // skip leading spaces
    if (strncmp(line, "for(", 4) != 0 && strncmp(line, "for (", 5) != 0) return 0;

    char *open = strchr(line, '(');
    char *close = strrchr(line, ')');
    if (!open || !close || close < open) return 0;

    char content[200];
    strncpy(content, open + 1, close - open - 1);
    content[close - open - 1] = '\0';

    int semiCount = 0;
    for (int i = 0; content[i]; i++) {
        if (content[i] == ';') semiCount++;
    }

    return semiCount == 2;
}

int main() {
    char line[200];
    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0'; // remove newline

    if (isValidForLoop(line)) printf("Valid for loop syntax\n");
    else printf("Invalid for loop syntax\n");

    return 0;
}
