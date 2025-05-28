#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define MAX_PLAYERS 4

void LlenarLlavesPredefinidas(char equipos[][30], int puntajes[], int diferenciagoles[], int *cant_equipos, char tabla[][30])
{
    int len;
    // LLave 1: E1 vs E2
    do
    {
        printf("Quien fue el ganador del partido? %s o %s\n", equipos[0], equipos[1]);
        fflush(stdin);
        fgets(tabla[0], 30, stdin);
        len = strlen(tabla[0]) - 1;
        if (tabla[0][len - 1] == '\n')
        {
            tabla[0][len - 1] = '\0';
            len--;
        }
        if (len < 1)
        {
            printf("El nombre no puede estar vacio. Intentelo de nuevo.\n");
            continue; // Vuelve al inicio del do-while
        }
        printf("Indique los goles del ganador:\n");
        fflush(stdin);
        scanf("%d", &puntajes[0]);
        printf("Indique los goles del perdedor:\n");
        fflush(stdin);// uso fflush porque getchar no necesito, mi compilador es reciente ;)
        scanf("%d", &puntajes[1]);
    } while (len < 1);
    // LLave 2: E3 vs E4
    do
    {
        printf("Quien fue el ganador del partido? %s o %s\n", equipos[2], equipos[3]);
        fflush(stdin);
        fgets(tabla[0], 30, stdin);
        len = strlen(tabla[0]) - 1;
        if (tabla[0][len - 1] == '\n')
        {
            tabla[0][len - 1] = '\0';
            len--;
        }
        if (len < 1)
        {
            printf("El nombre no puede estar vacio. Intentelo de nuevo.\n");
            continue; // Vuelve al inicio del do-while
        }
        printf("Indique los goles del ganador:\n");
        fflush(stdin);
        scanf("%d", &puntajes[2]);
        printf("Indique los goles del perdedor:\n");
        fflush(stdin);// uso fflush porque getchar no necesito, mi compilador es reciente ;)
        scanf("%d", &puntajes[3]);
    } while (len < 1);
}

void TablaPuntajes(int puntajes[], int diferenciagoles[], char equipos[][30], int *cant_equipos)
{
    int minimo;
    char temporal[30];
    int tempal;
     
    // Ordenar por puntajes (de mayor a menor)
    for (int i = 0; i < MAX_PLAYERS - 1; i++)
    {
        minimo = i;
        for (int j = i + 1; j < MAX_PLAYERS; j++)
        {
            // Si el puntaje es mayor O si los puntajes son iguales pero tiene mejor diferencia de goles
            if (puntajes[j] > puntajes[minimo] || 
               (puntajes[j] == puntajes[minimo] && diferenciagoles[j] > diferenciagoles[minimo]))
            {
                minimo = j;
            }
        }
        
        if (minimo != i)
        {
            // Intercambiar equipos
            strcpy(temporal, equipos[i]);
            strcpy(equipos[i], equipos[minimo]);
            strcpy(equipos[minimo], temporal);

            // Intercambiar puntajes
            tempal = puntajes[i];
            puntajes[i] = puntajes[minimo];
            puntajes[minimo] = tempal;

            // Intercambiar diferencia de goles
            tempal = diferenciagoles[i];
            diferenciagoles[i] = diferenciagoles[minimo];
            diferenciagoles[minimo] = tempal;
        }
    }

    printf("Tabla de posiciones:\n");
    printf("Equipo\t\tPuntos\tDiferencia de goles\n");
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        printf("%s\t\t%d\t%d\n", equipos[i], puntajes[i], diferenciagoles[i]);
    }
}
