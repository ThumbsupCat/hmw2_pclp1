#include "utils.h"

int FindFrequency(char* sirinitial, char* douagr) {
    int lung = 0;
    int douagrlung = 0;
    int cnt = 0;
    int flag = 0;
    int i = 0;
    int j = 0;
    lung = strlen(sirinitial);
    douagrlung = strlen(douagr);
    for (i = 0; i <= lung - douagrlung; i++) {
        flag = 1;
        for (j = 0; j < douagrlung; j++) {
            if (sirinitial[i + j] != douagr[j]) {  // cauta 2-grama
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            cnt++;
    }
    return cnt;
}

void SolveTask3() {
    char sir[10001], copiesir[10001], ngrame[500][500], *p;
    char previous[500], *rest = NULL;  // cuvantul de dinainte si rest de sir
    int k = 1, freq[500];
    getchar();
    strncat(sir, "  ", 1);
    while (scanf("%c", &sir[k]) != EOF) {
        if (strchr("\n", sir[k]) != 0) {
            if (sir[k - 1] != ' ') {
                sir[k] = ' ';
                k++;
            }
        } else if (strchr(",.!;?", sir[k]) == 0) {
            k++;
        }
    }  // citirea sirului si eliminarea semnelor de punctuatie + newlines
    sir[k++]=' ';
    sir[k] = '\0';
    strncpy(copiesir, sir, strlen(sir));
    p = strtok_r(sir, " ", &rest);
    strncpy(previous, p, strlen(p));  // copiaza primul cuv. anterior
    p = strtok_r(NULL, " ", &rest);
    k = 0;
    while (p) {
        char douagrama[500];
        int ok = 1;
        strncat(douagrama, "  ", 1);
        strncat(douagrama, previous, strlen(previous));
        strncat(douagrama, "  ", 1);
        strncat(douagrama, p, strlen(p));
        strncat(douagrama, "  ", 1);
        douagrama[strlen(douagrama)] = '\0';
        // formare douagrama
        for (int i = 0; i < k; i++) {
            if (strcmp(ngrame[i], douagrama) == 0)
                ok = 0;
        }  // cauta in vectorul de douagrame deja gasite sirul format anterior
        if (ok == 1) {
        int contor = FindFrequency(copiesir, douagrama);
            strncpy(ngrame[k], douagrama, strlen(douagrama));
            freq[k] = contor;
            k++;
            // retine douagrama gasita si frecv. acesteia
        }
        memcpy(previous, p, 500);
        douagrama[0] = 0;
        p = strtok_r(NULL, " ", &rest);
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        printf("%s", ngrame[i] + 1);
        printf("%d\n", freq[i]);
        // afisare vectorul de douagrame
    }
}
