#include <stdio.h>
#include <stdlib.h>

void afis(int n, int *v) {
    for(int i = 0; i < n; i++)
        printf("%d ", v[i] + 1); // Afisam numerele permutate de la 1 la n
    printf("\n");
}

void back(int poz, int n, int *v, char *folosit) {
    for(int i = 0; i < n; i++) {
        if(!folosit[i]) {
            v[poz] = i;
            folosit[i] = 1;
            if(poz == n - 1)
                afis(n, v);
            else
                back(poz + 1, n, v, folosit);
            folosit[i] = 0;
        }
    }
}

int main(void) {   
    int n = 0;
    printf("Introduceti numarul de elemente din multime: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Numarul de elemente trebuie sa fie pozitiv.\n");
        return 1;
    }

    int v[100];
    printf("Introduceti elementele multimii (numere separate prin spatiu): ");
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    // Vom folosi un vector de caractere pentru a tine evidenta elementelor folosite in permutare
    char folosit[100];
    for(int i = 0; i < n; i++)
        folosit[i] = 0;

    back(0, n, v, folosit);

    return 0;
}
