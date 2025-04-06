/*Example 3.3: Write a C program to convert an NFA with 3 states and a binary alphabet (0 and 1)
to DFA and print the resulting DFA states.*/

#include <stdio.h>
#include <string.h>
#define MAX_STATES 10
#define MAX_ALPHABET 2

int main() {
    int nfa_transitions[3][2][3] = {{{0, 1}, {0}}, {{2}, {2}}, {{3}, {0}}};
    int dfa_states[MAX_STATES][MAX_STATES] = {{0, 1, 0}},
        dfa_state_count = 1; // Initial state of DFA
    
    for (int i = 0; i < dfa_state_count; i++) {
        for (int input = 0; input < MAX_ALPHABET; input++) {
            int next_state[MAX_STATES] = {-1, -1, -1}; // Store next state after transition
            
            for (int j = 0; j < MAX_STATES; j++) {
                if (dfa_states[i][j] != -1)
                    for (int k = 0; k < 3; k++)
                        if (dfa_states[i][j] == k) next_state[k] = nfa_transitions[k][input][0];
            }
            
            int found = 0;
            for (int j = 0; j < dfa_state_count; j++) {
                if (!memcmp(dfa_states[j], next_state, sizeof(next_state))) {
                    found = 1;
                    break;
                }
            }
            
            if (!found) { // If state not found in DFA, add it
                for (int j = 0; j < MAX_STATES; j++)
                    dfa_states[dfa_state_count][j] = next_state[j];
                dfa_state_count++;
            }
        }
    }
    
    for (int i = 0; i < dfa_state_count; i++) { // Print DFA states
        printf("State %d: {", i);
        for (int j = 0; j < MAX_STATES; j++) {
            if (dfa_states[i][j] != -1) printf("%d ", dfa_states[i][j]);
        }
        printf("}\n");
    }
    return 0;
}