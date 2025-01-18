#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compute the longest prefix suffix array
void computeLPSArray(char* pattern, int M, int* lps) {
    int len = 0;  // Length of previous longest prefix suffix
    int i = 1;
    
    lps[0] = 0;  // lps[0] is always 0
    
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Algorithm implementation
void KMPSearch(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);
    
    // Create lps[] that will hold the longest prefix suffix values
    int* lps = (int*)malloc(M * sizeof(int));
    
    // Preprocess the pattern
    computeLPSArray(pattern, M, lps);
    
    int i = 0;  // Index for text[]
    int j = 0;  // Index for pattern[]
    
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        
        if (j == M) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    
    free(lps);
}

int main() {
    char text[] = "cABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    
    KMPSearch(pattern, text);
    
    return 0;
}
