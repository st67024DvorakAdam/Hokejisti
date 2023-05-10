#include <stdio.h>
#include <stdlib.h>

#define LENGTH_OF_NAME 20

typedef struct Hokejista {
    char jmeno[LENGTH_OF_NAME];
    int pocetGolu;
    int pocetAsistenci;
} Hokejista;

int spocitejKanadskeBody(Hokejista hokejista) {
    return hokejista.pocetAsistenci + hokejista.pocetGolu;
}

int main() {
    int counter = 0;
    int pocetHokejistu = 0;
    char pocetHokejistuString[5];
    FILE* input = fopen("hokejisti.txt", "r");
    fgets(pocetHokejistuString, 1024, input);
    pocetHokejistu = atoi(pocetHokejistuString);
    Hokejista* poleHokejistu = (Hokejista*)malloc(sizeof(Hokejista) * pocetHokejistu);

    char line[20];
    while (fgets(line, 1024, input) != NULL) {
        Hokejista temp;
        line[strcspn(line, "\n")] = '\0';
        strcpy(temp.jmeno, line);
        fgets(line, 1024, input);
        temp.pocetGolu = atoi(line);
        fgets(line, 1024, input);
        temp.pocetAsistenci = atoi(line);
        poleHokejistu[counter] = temp;
        counter++;
    }

    printf("\nVypis vsech hokejistu z pole:\n");
    for (int i = 0; i < pocetHokejistu; i++) {
        printf("Jmeno: %s, pocet golu: %d, pocet asistenci: %d.\n",
            poleHokejistu[i].jmeno,
            poleHokejistu[i].pocetGolu,
            poleHokejistu[i].pocetAsistenci);
    }

    printf("\nVypis hokejistu s vice goly nez asistencemi:\n");
    for (int i = 0; i < pocetHokejistu; i++) {
        if (poleHokejistu[i].pocetGolu > poleHokejistu[i].pocetAsistenci) {
        printf("Jmeno: %s, pocet golu: %d, pocet asistenci: %d.\n",
            poleHokejistu[i].jmeno,
            poleHokejistu[i].pocetGolu,
            poleHokejistu[i].pocetAsistenci);
        }
    }

    Hokejista hokejista = poleHokejistu[0];
    printf("\nHokejista s nejvetsim poctem kanadskych golu:\n");
    for (int i = 0; i < pocetHokejistu; i++) {
        if (spocitejKanadskeBody(hokejista) < spocitejKanadskeBody(poleHokejistu[i])) {
            hokejista = poleHokejistu[i];
        }
    }
    printf("Jmeno: %s, pocet golu: %d, pocet asistenci: %d, pocet kanadskych golu: %d.\n",
        hokejista.jmeno,
        hokejista.pocetGolu,
        hokejista.pocetAsistenci,
        spocitejKanadskeBody(hokejista));
    fclose(input);
    free(poleHokejistu);
    return 0;
}