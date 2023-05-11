#include "utils.h"
#define SMAX 1001

void reverse(char s[SMAX]) {
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        char temp;
        temp = *(s + i);
        *(s + i) = *(s + n - i - 1);
        *(s + n - i - 1) = temp;
    }
    *(s + n) = 0;
}

char* decriptare_caesar(int cheie, char text[SMAX]) {
    int i = 0;
    for (i = 0; i < strlen(text); i++) {
        for (int j = 1; j <= cheie; j++) {
            if (*(text + i) <= 'z' && *(text + i) >='a') {
                if (*(text + i) == 'a') {
                    *(text + i) = 'z';
                } else {
                    *(text + i) -= 1;
                }
            } else if (*(text + i) >= '0' && *(text + i) <= '9') {
                if (*(text + i) == '0') {
                    *(text + i) = '9';
                } else {
                    *(text + i) -= 1;
                }
            } else if (*(text + i) >= 'A' && *(text + i) <= 'Z') {
                if (*(text + i) == 'A') {
                    *(text + i) = 'Z';
                } else {
                    *(text + i) -= 1;
                }
            }
        }
    }
    return text;
}
void decriptare_vigenere(char cheie[11], char text[SMAX]) {
    for (int i = 0; i < strlen(text); i++) {
        int nr_deplasari = *(cheie + i % strlen(cheie)) - 'A';
            for (int j = 1; j <= nr_deplasari; j++) {
                if (*(text + i) <= 'z' && *(text + i) >='a') {
                    if (*(text + i) == 'a') {
                    *(text + i) = 'z';
                    } else {
                        *(text + i) -= 1;
                    }
                } else if (*(text + i) >= '0' && *(text + i) <= '9') {
                    if (*(text + i) == '0') {
                        *(text + i) = '9';
                    } else {
                        *(text + i) -= 1;
                    }
                } else if (*(text + i) >= 'A' && *(text + i) <= 'Z') {
                    if (*(text + i) == 'A') {
                        *(text + i) = 'Z';
                    } else {
                        *(text + i) -= 1;
                }
            }
        }
    }
    printf("%s\n", text);
}

void suma_numere_mari(char nr1[SMAX], char nr2[SMAX]) {
    char S[SMAX];
    int l1 = strlen(nr1), l2 = strlen(nr2);
    reverse(nr1);
    reverse(nr2);
    int rest = 0 , k = 0;
    if (l1 < l2) {
        for (int i = 0; i < l1; i++) {
            int suma = ((*(nr1 + i) - '0') + (*(nr2 + i) - '0')) + rest;
            *(S + k) = suma % 10 + '0';
            *(S + k + 1) = 0;
            k++;
            rest = suma / 10;
        }
        for (int i = l1; i < l2; i++) {
            int suma = (*(nr2 + i) - '0') + rest;
            *(S + k) = suma % 10 + '0';
            *(S + k + 1) = 0;
            k++;
            rest = suma / 10;
        }
    } else {
        for (int i = 0; i < l2; i++) {
            int suma = ((*(nr1 + i) - '0') + (*(nr2 + i) - '0')) + rest;
            *(S + k) = suma % 10 + '0';
            *(S + k + 1) = 0;
            k++;
            rest = suma / 10;
        }
        for (int i = l2; i < l1; i++) {
            int suma = (*(nr1 + i) - '0') + rest;
            *(S + k) = suma % 10 + '0';
            *(S + k + 1) = 0;
            k++;
            rest = suma / 10;
        }
    }
    if (rest != 0) {
        *(S + k) = rest + '0';
        *(S + k + 1) = 0;
    } else {
        *(S + k) = 0;
    }
    reverse(S);
    while (*(S + 0) - '0' == 0) {
        for (int i = 0; i < strlen(S) - 1; i++) {
            char temp = *(S + i);
            *(S + i) = *(S + i + 1);
            *(S + i + 1) = temp;
        }
        *(S + strlen(S) - 1) = 0;
    }

    printf("%s\n", S);
}

void SolveTask2() {
    char cifru[15];  // recunoasterea comenzii de catre program
    getchar();
    fgets(cifru, 14, stdin);
    if (*(cifru + strlen(cifru) - 1) == '\n')
        *(cifru + strlen(cifru) - 1) = 0;
    if (strcmp("caesar", cifru) == 0) {
        int K;
        char S[SMAX];
        scanf("%d ", &K);
        fgets(S, SMAX-1, stdin);
        printf("%s", decriptare_caesar(K, S));
    } else if (strcmp("vigenere", cifru) == 0) {
        char cheie_vigenere[11], S[SMAX];
        fgets(cheie_vigenere, 10, stdin);
        *(cheie_vigenere + strlen(cheie_vigenere) - 1) = 0;
        fgets(S, SMAX - 1, stdin);
        *(S + strlen(S) - 1) = 0;
        decriptare_vigenere(cheie_vigenere, S);
    } else {
        int K;
        char N1[SMAX], N2[SMAX];
        scanf("%d ", &K);
        fgets(N1, SMAX, stdin);
        fgets(N2, SMAX, stdin);
        if (*(N1 + strlen(N1) - 1) == '\n')
        *(N1 + strlen(N1)- 1) = 0;
        if (*(N2 + strlen(N2) - 1) == '\n')
        *(N2 + strlen(N2) - 1) = 0;
        suma_numere_mari(decriptare_caesar(K, N1), decriptare_caesar(K, N2));
    }
}
