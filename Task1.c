#include "utils.h"

#define CODMAX 300
#define NMAX 30

int este_palindrom(int nr) {
    int copie_nr = nr , oglindit = 0;
    while (copie_nr) {
        oglindit = oglindit * 10 + copie_nr % 10;
        copie_nr /= 10;
    }
    if (nr == oglindit)
        return 1;
    return 0;
}

int este_prim(int nr) {
    if (nr < 2)
        return 0;
    for (int d = 2 ; d * d <= nr ; d++) {
        if (nr % d == 0)
            return 0;
    }
    return 1;
}

void SolveTask1() {
    int n, m, matrix[NMAX][NMAX]={0}, i = 0 , j = 0, count = 1;
    matrix[0][0] = count;
    scanf("%d%d", &n, &m);
    getchar();
    getchar();
    char cod_sir[CODMAX];
    fgets(cod_sir, CODMAX-1, stdin);
    char *p, *rest = NULL;  // Pentru impartire in coduri si restul de sir
    p = strtok_r(cod_sir, " ", &rest);
    while (p) {
        count++;
    switch (*(p + 0)) {
        case 'a' :
        {
            int cif_max = 0, cif_indice = 0;
            for (int k = 1; k <= 4; k++) {
                if (*(p + k) - '0' > cif_max) {
                    cif_max = *(p + k) - '0';
                    cif_indice = k;
                }
            }
            if (cif_indice == 1) {
                j++;  // dreapta
            } else if (cif_indice == 2) {
                i--;  // sus
            } else if (cif_indice == 3) {
                j--;  // stanga
            } else {
                i++;  // jos
            }
        break;
        }
        case 'b' :
        {
            int K = 0, X;
            for (int k = 1; k < strlen(p); k++) {
                K = K * 10 + (*(p + k) - '0');
            }
            X = K % 100;
            int conditia1 = este_palindrom(K);
            int conditia2 = este_prim(X);
            if (conditia1 == 1 && conditia2 == 1) {
                j--;  // stanga
            } else if (conditia1 == 1 && conditia2 == 0) {
                j++;  // dreapta
            } else if (conditia1 == 0 && conditia2 == 1) {
                i--;  // sus
            } else {
                i++;  // jos
            }
            break;
        }
        case 'c' :
        {
            int n = *(p + 1) - '0', k = *(p + 2) - '0';
            int S = 0;
            for (int z = 0; z < k; z++) {
                S += *(p + 3 + (z * k) % n) - '0';
            }
            if (S % 4 == 0) {
                j--;  // stanga
            } else if (S % 4 == 1) {
                i--;  // sus
            } else if (S % 4 == 2) {
                j++;  // dreapta
            } else {
                i++;  // jos
            }
            break;
        }
    }
        matrix[i][j] = count;
        p = strtok_r(NULL, " ", &rest);
    }
    for (int k = 0; k < n; k++) {
        for (int z = 0; z < m; z++) {
            printf("%d ", matrix[k][z]);
        }
        printf("\n");
    }
}
