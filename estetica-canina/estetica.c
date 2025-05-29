#include <stdio.h>
#include <string.h>
#include "estetica.h"
#define MAX_CITAS 5

int cant_citas = 0;

void registrarcita(char clientes[MAX_CITAS][30], char nombreMascota[MAX_CITAS][30], char fecha[MAX_CITAS][10], int *cant_citas)
{
    int opcion, len, repetido;
    int val;

    if (*cant_citas >= MAX_CITAS)
    {
        printf("No se puede registrar mas citas, el limite ha sido alcanzado.\n");
        return;
    }

    for (int i = 0; i < MAX_CITAS; i++)
    {
        // NOMBRE DE LA PERSONA
        do
        {
            printf("Por favor ingrese el nombre de la persona %d\n", i + 1);
            fflush(stdin);
            fgets(clientes[i], 30, stdin);
            len = strlen(clientes[i]);

            if (clientes[i][len - 1] == '\n')
            {
                clientes[i][len - 1] = '\0';
                len--;
            }

            if (len == 0)
            {
                printf("El nombre no puede estar vacio, intente de nuevo\n");
                continue;
            }

            repetido = 0; // Reiniciar la bandera para cada nueva cita
            for (int j = 0; j < i; j++)
            {
                if (strcmp(clientes[i], clientes[j]) == 0)
                {
                    printf("El cliente ya existe. Por favor, ingrese una nombre diferente.\n");
                    repetido = 1; // set the flag to indicate that nombre is repeated
                    break;
                }
            }
        } while (len == 0 || repetido == 1);

        // NOMBRE DE LA MASCOTA

        do
        {
            printf("Por favor ingrese el nombre de la mascota %d\n", i + 1);
            fflush(stdin);
            fgets(nombreMascota[i], 30, stdin);
            len = strlen(nombreMascota[i]);
            if (nombreMascota[i][len - 1] == '\n')
            {
                nombreMascota[i][len - 1] = '\0';
                len--;
            }
            if (len == 0)
            {
                printf("El nombre no puede estar vacio, intente de nuevo\n");
            }

            repetido = 0; // Reiniciar la bandera para cada nueva cita
            for (int j = 0; j < i; j++)
            {
                if (strcmp(nombreMascota[i], clientes[j]) == 0)
                {
                    printf("El nombre ya existe. Por favor, ingrese un nombre diferente.\n");
                    repetido = 1; // set the flag to indicate that nombre is repeated
                    break;
                }
            }
        } while (len == 0 || repetido == 1);

        // FECHA DE LA CITA
        do
        {
            printf("Por favor ingrese la fecha de la cita %d (dd/mm/yy)\n", i + 1);
            fflush(stdin);
            fgets(fecha[i], 10, stdin);
            len = strlen(fecha[i]);
            if (fecha[i][len - 1] == '\n')
            {
                fecha[i][len - 1] = '\0';
                len--;
            }
            if (len == 0)
            {
                printf("El nombre no puede estar vacio, intente de nuevo\n");
            }

            repetido = 0; // Reiniciar la bandera para cada nueva cita
            for (int j = 0; j < i; j++)
            {
                if (strcmp(fecha[i], fecha[j]) == 0)
                {
                    printf("La fecha ya esta ocupada. Por favor, ingrese una fecha diferente.\n");
                    repetido = 1; // set the flag to indicate that nombre is repeated
                    break;
                }
            }
        } while (len == 0 || repetido == 1);
        // VALIDAR SI DESEA SEGUIR INGRESANDO CITAS
        do
        {
            printf("Desea agregar mas citas? (1. Si, 2. No)\n");
            fflush(stdin);
            val = scanf("%d", &opcion);
            if (val != 1 || opcion < 1 || opcion > 2)
            {
                printf("Por favor ingrese una opcion valida (1 o 2)\n");
            }
        } while (val != 1 && (opcion < 1 || opcion > 2));

        (*cant_citas)++;

        if (opcion == 2)
        {
            break; // Salir del bucle si el usuario no desea agregar más citas
        }
    }
}

void buscarcitaFecha(char clientes[MAX_CITAS][30], char nombreMascota[MAX_CITAS][30], char fecha[MAX_CITAS][10], int *cant_citas)
{
    char buscar[30];
    int len, encontrado = 0;
    if (*cant_citas == 0)
    {
        printf("No hay citas registradas.\n");
        return;
    }

    printf("Por favor ingrese la fecha de la cita a buscar (dd/mm/yy):\n");

    fflush(stdin);
    fgets(buscar, 30, stdin);

    len = strlen(buscar);
    if (buscar[len - 1] == '\n')
    {
        buscar[len - 1] = '\0';
        len--;
    }

    encontrado = 0;
    for (int i = 0; i < *cant_citas; i++)
    {
        if (strcmp(fecha[i], buscar) == 0)
        {
            encontrado = 1;
            printf("\nCita encontrada:\n");
            printf("Cliente: %s\n", clientes[i]);
            printf("Mascota: %s\n", nombreMascota[i]);
            printf("Fecha agendada: %s\n", fecha[i]);
        }
        if (encontrado != 1)
        {
            printf("Cita no hallada.\n");
        }
    }
}

void buscarcitaCliente(char clientes[MAX_CITAS][30], char nombreMascota[MAX_CITAS][30], char fecha[MAX_CITAS][10], int *cant_citas)
{
    char buscar[30];
    int len, encontrado = 0;
    if (*cant_citas == 0)
    {
        printf("No hay citas registradas.\n");
        return;
    }

    printf("Por favor ingrese el nombre del cliente a buscar\n");

    fflush(stdin);
    fgets(buscar, 30, stdin);

    len = strlen(buscar);
    if (buscar[len - 1] == '\n')
    {
        buscar[len - 1] = '\0';
        len--;
    }

    encontrado = 0;
    for (int i = 0; i < *cant_citas; i++)
    {
        if (strcmp(clientes[i], buscar) == 0)
        {
            encontrado = 1;
            printf("\nCita encontrada:\n");
            printf("Cliente: %s\n", clientes[i]);
            printf("Mascota: %s\n", nombreMascota[i]);
            printf("Fecha agendada: %s\n", fecha[i]);
        }
        if (encontrado != 1)
        {
            printf("Cliente no encontrado.\n");
        }
    }
}