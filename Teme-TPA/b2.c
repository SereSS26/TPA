#include <stdio.h>
#include <stdlib.h>

#define MAX 26 // At most 26 letters in the alphabet
char alfabet[MAX];
char parola[MAX];
int n, k;

int vocala(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int solutie(int poz) {
    if (poz == 0) {
        return 1;
    }
    if (parola[poz] == parola[poz - 1]) {
        return 0;
    }
    if (vocala(parola[poz]) && vocala(parola[poz - 1])) {
        return 0;
    }
    if (abs(parola[poz] - parola[poz - 1]) == 1) {
        return 0;
    }
    return 1;
}

void backtracking(int n, int k, char alfabet[], int poz) {
    int i;

    if (poz == k) {
        for (i = 0; i < k; i++) {
            printf("%c", parola[i]);
        }
        printf("\n");
        return;
    }

    for (i = 0; i < n; i++) {
        parola[poz] = alfabet[i];
        if (solutie(poz)) {
            backtracking(n, k, alfabet, poz + 1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("EROARE\n");
        return -1;
    }

    n = atoi(argv[1]);
    k = atoi(argv[2]);

    if (n > MAX || k > n || n <= 0 || k <= 0) {
        printf("EROARE\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        alfabet[i] = argv[i + 3][0];
    }

    backtracking(n, k, alfabet, 0);

    return 0;
}
