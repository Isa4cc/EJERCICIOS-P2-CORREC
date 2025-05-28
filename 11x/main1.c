/*
Generar un programa que permita ingresar el nombre de un equipo de fut, (cuadrangular), y los
valores de los partidos disputados (ganados, empatados y perdidos) y calcule el puntaje final del
equipo.
El puntaje final se calcula de la siguiente manera:
• 3 puntos por cada partido ganado.
• 1 punto por cada partido empatado.
• 0 puntos por cada partido perdido.
debe de tener en cuenta los goles anotados y los goles recibidos, en caso de empatar, se debe
tomar en cuenta la diferencia de goles.
Modularizar el programa, en funciones.h y funciones.c.
*/

#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define MAX_PLAYERS 4

int main(int argc, char *argv[])
{

    char equipos[MAX_PLAYERS][30], tabla[MAX_PLAYERS][30];
    int puntajes[MAX_PLAYERS], diferenciagoles[MAX_PLAYERS], cant_equipos = 0, val;
    int opci_menu, ValidarIngresaEquipoa = 0, len, repetido;

    printf("=====SOCCER QUADRANGULAR ANALYSIS SISTEM====\n");
    printf("\n");

    do
    {
        printf("====MENÚ GENERAL====\n");
        printf("1. Ingresar nombre de equipos\n");
        printf("2. Ingresar valores de los partidos\n");
        printf("3. Ver tabla final de posiciones\n");
        printf("4. Ingresar datos de la final\n");
        printf("5. Salir\n");
        do
        {
            fflush(stdin);
            val = scanf("%d", &opci_menu);
            if (val != 1)
            {
                printf("Por favor ingrese un valor correcto\n");
            }
        } while (val != 1);
        if (opci_menu < 1 || opci_menu > 4)
        {
            printf("Por favor ingrese un valor que este en el menu.\n");
            continue;
        }
        switch (opci_menu)
        {
        case 1:
            ValidarIngresaEquipoa = 1;
            for (int i = 0; i < MAX_PLAYERS; i++)
            {
                repetido = 0;
                do
                {
                    printf("Por favor ingrese el nombre del equipo %d\n", i + 1);
                    fflush(stdin);
                    fgets(equipos[i], 30, stdin);
                    len = strlen(equipos[i]) - 1;

                    if (equipos[i][len - 1] == '\n')
                    {
                        equipos[i][len - 1] = '\0';
                        len--;
                    }

                    if (len < 1)
                    {
                        printf("El nombre no puede estar vacio. Intentelo de nuevo.\n");
                        continue; // Vuelve al inicio del do-while
                    }

                    repetido = 0; // Reiniciar bandera
                    for (int j = 0; j < i; j++)
                    {
                        if (strcmp(equipos[i], equipos[j]) == 0)
                        {
                            repetido = 1;
                            printf("El nombre ya fue ingresado. Introduzca un nombre distinto.\n");
                            break;
                        }
                    }
                } while (len < 1 || repetido == 1);
            }
            break;
        case 2: // llenar info de los partidos: goles, victorias, empates.
            LlenarLlavesPredefinidas(equipos, puntajes, diferenciagoles, &cant_equipos, tabla);
            break;
        case 3: // ver tabla de posiciones
        {
            if (ValidarIngresaEquipoa == 0)
            {
                printf("Por favor ingrese los equipos primero.\n");
                break;
            }
            TablaPuntajes(puntajes, diferenciagoles, equipos, &cant_equipos);
        }

        default:
            break;
        }
    } while (opci_menu != 5);

    return 0;
}