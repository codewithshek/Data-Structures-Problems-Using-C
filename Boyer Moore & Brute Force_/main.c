#include <stdio.h>
#include <string.h>

#define NO_OF_CHARS 256

void badCharHeuristic(char *str, int size, int badChar[NO_OF_CHARS]) {
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1;
    for (i = 0; i < size; i++)
        badChar[(unsigned char)str[i]] = i;
}

void boyerMooreSearch(char *text, char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    int badChar[NO_OF_CHARS];
    badCharHeuristic(pattern, m, badChar);

    int s = 0; // s is the shift of the pattern with respect to text
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            printf("Using Boyer Moore, Pattern found at location = %d\n", s);
            s += (s + m < n) ? m - badChar[(unsigned char)text[s + m]] : 1;
        } else {
            s += (j - badChar[(unsigned char)text[s + j]] > 1) ? j - badChar[(unsigned char)text[s + j]] : 1;
        }
    }
}

void bruteForceSearch(char *text, char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            printf("Using brute force, pattern found at %d\n", i);
        }
    }
}

int main() {
    char text[] = "ABAAABCD";
    char pattern[] = "ABC";
    boyerMooreSearch(text, pattern);
    bruteForceSearch(text, pattern);
    return 0;
}
