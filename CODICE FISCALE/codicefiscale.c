#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define A 100
#define P 25

char CODICEFISCALE[17];
int max_giorni;

void cerca(const char *luogo, const char *provincia) {
    FILE *comuni;
    char contenuto[A];
    comuni = fopen("codici_catastali.txt", "r");
    if (comuni == NULL) {
        printf("Errore apertura file\n");
        return;
    }
    int k;
    while (fgets(contenuto, A, comuni) != NULL) {
        if (strstr(contenuto, luogo) != NULL && strstr(contenuto, provincia) != NULL) {
            for (k = 11; k <= 14; k++) {
                CODICEFISCALE[k] = contenuto[k - 11];
            }
            fclose(comuni);
            return;
        }
    }
    fclose(comuni);
    printf("Nessun risultato trovato per il luogo di nascita '%s' e la provincia '%s'\n", luogo, provincia);
}

void catastale_inverso(char CODICEFISCALE[]) {
    char riga[P];
    FILE *fp;
    fp = fopen("codici_catastali.txt", "r");
    if (fp == NULL) {
        printf("Errore durante l'apertura del file\n");
        return;
    }
    char cod_catastale[5];
    strncpy(cod_catastale, CODICEFISCALE + 11, 4);
    cod_catastale[4] = '\0';
    while (fgets(riga, P, fp) != NULL) {
        if (strncmp(riga, cod_catastale, 4) == 0) {
            printf("Luogo di nascita: %s\n", riga + 5);
            fclose(fp);
            return;
        }
    }
    printf("Nessun Comune trovato\n");
    fclose(fp);
}

void codice_controllo(char CODICEFISCALE[]) {
    int r = 0, s = 0;
    char lettera_controllo;
    int f;
    for (f = 0; f < 15; f++) {
        if (f % 2 == 0) {
            switch (CODICEFISCALE[f]) {
                case 'A': case '0': r += 1; break;
                case 'B': case '1': r += 0; break;
                case 'C': case '2': r += 5; break;
                case 'D': case '3': r += 7; break;
                case 'E': case '4': r += 9; break;
                case 'F': case '5': r += 13; break;
                case 'G': case '6': r += 15; break;
                case 'H': case '7': r += 17; break;
                case 'I': case '8': r += 19; break;
                case 'J': case '9': r += 21; break;
                case 'K': r += 2; break;
                case 'L': r += 4; break;
                case 'M': r += 18; break;
                case 'N': r += 20; break;
                case 'O': r += 11; break;
                case 'P': r += 3; break;
                case 'Q': r += 6; break;
                case 'R': r += 8; break;
                case 'S': r += 12; break;
                case 'T': r += 14; break;
                case 'U': r += 16; break;
                case 'V': r += 10; break;
                case 'W': r += 22; break;
                case 'X': r += 25; break;
                case 'Y': r += 24; break;
                case 'Z': r += 23; break;
            }
        } else {
            switch (CODICEFISCALE[f]) {
                case 'A': case '0': r += 0; break;
                case 'B': case '1': r += 1; break;
                case 'C': case '2': r += 2; break;
                case 'D': case '3': r += 3; break;
                case 'E': case '4': r += 4; break;
                case 'F': case '5': r += 5; break;
                case 'G': case '6': r += 6; break;
                case 'H': case '7': r += 7; break;
                case 'I': case '8': r += 8; break;
                case 'J': case '9': r += 9; break;
                case 'K': r += 10; break;
                case 'L': r += 11; break;
                case 'M': r += 12; break;
                case 'N': r += 13; break;
                case 'O': r += 14; break;
                case 'P': r += 15; break;
                case 'Q': r += 16; break;
                case 'R': r += 17; break;
                case 'S': r += 18; break;
                case 'T': r += 19; break;
                case 'U': r += 20; break;
                case 'V': r += 21; break;
                case 'W': r += 22; break;
                case 'X': r += 23; break;
                case 'Y': r += 24; break;
                case 'Z': r += 25; break;
            }
        }
    }
    s = r % 26;
    switch (s) {
        case 0: lettera_controllo = 'A'; break;
        case 1: lettera_controllo = 'B'; break;
        case 2: lettera_controllo = 'C'; break;
        case 3: lettera_controllo = 'D'; break;
        case 4: lettera_controllo = 'E'; break;
        case 5: lettera_controllo = 'F'; break;
        case 6: lettera_controllo = 'G'; break;
        case 7: lettera_controllo = 'H'; break;
        case 8: lettera_controllo = 'I'; break;
        case 9: lettera_controllo = 'J'; break;
        case 10: lettera_controllo = 'K'; break;
        case 11: lettera_controllo = 'L'; break;
        case 12: lettera_controllo = 'M'; break;
        case 13: lettera_controllo = 'N'; break;
        case 14: lettera_controllo = 'O'; break;
        case 15: lettera_controllo = 'P'; break;
        case 16: lettera_controllo

 = 'Q'; break;
        case 17: lettera_controllo = 'R'; break;
        case 18: lettera_controllo = 'S'; break;
        case 19: lettera_controllo = 'T'; break;
        case 20: lettera_controllo = 'U'; break;
        case 21: lettera_controllo = 'V'; break;
        case 22: lettera_controllo = 'W'; break;
        case 23: lettera_controllo = 'X'; break;
        case 24: lettera_controllo = 'Y'; break;
        case 25: lettera_controllo = 'Z'; break;
    }
    CODICEFISCALE[15] = lettera_controllo;
    printf("Codice fiscale: %s\n", CODICEFISCALE);
}

int main() {
    int scelta, giorno, anno, mese;
    char datadinascita[12];
    char nome[20];
    char cognome[20];
    char sesso;
    char luogo[30];
    char provincia[20];
    int contatore;
    int w, h;
    int e;

    do {
        printf("Menù:\n\n");
        printf("Scegliere tra le 3 casistiche più appropriate:\n\n");
        printf("1. Inserisci le informazioni necessarie per procedere con la creazione del codice\n");
        printf("2. Estrazione dei dati di un utente\n");
        printf("3. Esci dal programma\n\n");

        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                printf("Inserisci il nome:\n");
                scanf("%s", nome);
                int k;
                for ( k = 0; nome[k]; k++) {
                    nome[k] = toupper(nome[k]);
                }

                printf("Inserisci cognome:\n");
                scanf("%s", cognome);
                int c;
                for ( c = 0; cognome[c]; c++) {
                    cognome[c] = toupper(cognome[c]);
                }

                printf("Inserisci il sesso (inserire M oppure F):\n");
                scanf(" %c", &sesso);
                sesso = toupper(sesso);

                do {
                    printf("Inserire data di nascita (gg/mm/anno): \n");
                    scanf("%s", datadinascita);
                    sscanf(datadinascita, "%d/%d/%d", &giorno, &mese, &anno);

                    switch (mese) {
                        case 4: case 6: case 9: case 11:
                            max_giorni = 30;
                            break;
                        case 2:
                            max_giorni = ((anno % 4 == 0 && anno % 100 != 0) || anno % 400 == 0) ? 29 : 28;
                            break;
                        default:
                            max_giorni = 31;
                            break;
                    }
                } while ( giorno < 1 || giorno > max_giorni || mese < 1 || mese > 12 );

                printf("Inserire il luogo di nascita:\n");
                scanf("%s", luogo);
                int u;
                for ( u = 0; luogo[u]; u++) {
                    luogo[u] = toupper(luogo[u]);
                }

                printf("Inserire la provincia (SIGLA) (EE estero):\n");
                scanf("%s", provincia);
                int r;
                for (r = 0; provincia[r]; r++) {
                    provincia[r] = toupper(provincia[r]);
                }

                contatore = 0;
                for (w = 0; w < strlen(cognome) && contatore < 3; w++) {
                    if (cognome[w] != 'A' && cognome[w] != 'E' && cognome[w] != 'I' && cognome[w] != 'O' && cognome[w] != 'U') {
                        CODICEFISCALE[contatore] = cognome[w];
                        contatore++;
                    }
                }
                for (h = 0; h < strlen(nome) && contatore < 6; h++) {
                    if (nome[h] != 'A' && nome[h] != 'E' && nome[h] != 'I' && nome[h] != 'O' && nome[h] != 'U') {
                        CODICEFISCALE[contatore] = nome[h];
                        contatore++;
                    }
                }
                // Aggiunta delle vocali se necessario
                for (w = 0; w < strlen(cognome) && contatore < 6; w++) {
                    if (cognome[w] == 'A' || cognome[w] == 'E' || cognome[w] == 'I' || cognome[w] == 'O' || cognome[w] == 'U') {
                        CODICEFISCALE[contatore] = cognome[w];
                        contatore++;
                    }
                }
                for (h = 0; h < strlen(nome) && contatore < 6; h++) {
                    if (nome[h] == 'A' || nome[h] == 'E' || nome[h] == 'I' || nome[h] == 'O' || nome[h] == 'U') {
                        CODICEFISCALE[contatore] = nome[h];
                        contatore++;
                    }
                }

                CODICEFISCALE[6] = datadinascita[8];
                CODICEFISCALE[7] = datadinascita[9];

                if (sesso == 'F') {
                    giorno = giorno + 40;
                    int x = giorno / 10;
                    int y = giorno % 10;
                    CODICEFISCALE[9] = '0' + x ;
                    CODICEFISCALE[10] = '0' + y;
                } else {
                    CODICEFISCALE[9] = datadinascita[0];
                    CODICEFISCALE[10] = datadinascita[1];
                }

                switch (mese) {
                    case 1: CODICEFISCALE[8] = 'A'; break;
                    case 2: CODICEFISCALE[8] = 'B'; break;
                    case 3: CODICEFISCALE[8] = 'C'; break;
                    case 4: CODICEFISCALE[8] = 'D'; break;
                    case 5: CODICEFISCALE[8] = 'E'; break;
                    case 6: CODICEFISCALE[8] = 'H'; break;
                    case 7: CODICEFISCALE[8] = 'L'; break;
                    case 8: CODICEFISCALE[8] = 'M'; break;
                    case 9: CODICEFISCALE[8] = 'P'; break;
                    case 10: CODICEFISCALE[8] = 'R'; break;
                    case 11: CODICEFISCALE[8]

 = 'S'; break;
                    case 12: CODICEFISCALE[8] = 'T'; break;
                }
                cerca(luogo, provincia);
                codice_controllo(CODICEFISCALE);
                printf("\n");
                break;

            case 2: 
                printf("Inserisci il codice fiscale dell'utente:\n");
                scanf("%s", CODICEFISCALE);
                for (e = 0; CODICEFISCALE[e]; e++) {
                    CODICEFISCALE[e] = toupper(CODICEFISCALE[e]);
                }
                printf("Nome: %c%c%c\n", CODICEFISCALE[0], CODICEFISCALE[1], CODICEFISCALE[2]);
                printf("Cognome: %c%c%c\n", CODICEFISCALE[3], CODICEFISCALE[4], CODICEFISCALE[5]);

                switch (CODICEFISCALE[8]) {
                    case 'A': CODICEFISCALE[8] = '01'; break;
                    case 'B': CODICEFISCALE[8] = '02'; break;
                    case 'C': CODICEFISCALE[8] = '03'; break;
                    case 'D': CODICEFISCALE[8] = '04'; break;
                    case 'E': CODICEFISCALE[8] = '05'; break;
                    case 'H': CODICEFISCALE[8] = '06'; break;
                    case 'L': CODICEFISCALE[8] = '07'; break;
                    case 'M': CODICEFISCALE[8] = '08'; break;
                    case 'P': CODICEFISCALE[8] = '09'; break;
                    case 'R': CODICEFISCALE[8] = '10'; break;
                    case 'S': CODICEFISCALE[8] = '11'; break;
                    case 'T': CODICEFISCALE[8] = '12'; break;
                }

                if(CODICEFISCALE[9] =='4' || CODICEFISCALE[9] =='5' || CODICEFISCALE[9] =='6' || CODICEFISCALE[9] =='7'){
                    int giorno_F = atoi(&CODICEFISCALE[9]);
                    giorno_F -= 40;
                    printf("Giorno nascita: %d \n", giorno_F);
                    printf("Data di nascita: %d/%c/%c%c\n",  giorno_F , CODICEFISCALE[8] , CODICEFISCALE[6], CODICEFISCALE[7]);
                }
                else {
                    printf("Data di nascita: %c%c/%c/%c%c\n", CODICEFISCALE[9] , CODICEFISCALE[10] , CODICEFISCALE[8] , CODICEFISCALE[6], CODICEFISCALE[7]);
                }
                catastale_inverso(CODICEFISCALE);
                break;

            case 3:
                printf("\n");
                printf("Uscito dal programma\n");
                break;
        }
    } while (scelta >= 1 && scelta < 3);

    return 0;
}


