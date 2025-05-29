#include <stdio.h>
#include <string.h>
#include "funcionvehiculos.h"
#define MAX_VEHICLES 5

void AddCar(char cedula[MAX_VEHICLES][20], char placa[MAX_VEHICLES][8], char nombreVehiculo[MAX_VEHICLES][30], char estado[MAX_VEHICLES][5], int *contarcantidad)
{
    int opci, llenarmasvehiculos = 0, len, val;
    int repetida = 0;
    for (int i = 0; i < MAX_VEHICLES; i++)
    {
        (*contarcantidad)++;
        do
        {
            printf("Ingrese la cedula del dueno del vehiculo %d: ", i + 1);
            fflush(stdin);
            fgets(cedula[i], 20, stdin);
            len = strlen(cedula[i]);

            if (cedula[i][len - 1] == '\n')
            {
                cedula[i][len - 1] = '\0';
                len--;
            }

            if (len == 0)
            {
                printf("Cedula no puede estar vacia. Intente de nuevo.\n");
            }

            repetida = 0; // reset the flag for each new vehicle
            for (int j = 0; j < i; j++)
            {
                if (strcmp(cedula[i], cedula[j]) == 0)
                {
                    printf("La cedula ya existe. Por favor, ingrese una cedula diferente.\n");
                    repetida = 1; // set the flag to indicate that cedula is repeated
                    break;        // exit the loop if cedula already exists
                }
            }
        } while (len == 0 || repetida == 1);
        do
        {
            printf("Ingrese el nombre del vehiculo %d\n", i + 1);
            fflush(stdin);
            fgets(nombreVehiculo[i], 30, stdin);
            len = strlen(nombreVehiculo[i]);

            if (nombreVehiculo[i][len - 1] == '\n')
            {
                nombreVehiculo[i][len - 1] = '\0';
            }

            if (len == 0)
            {
                printf("Nombre del vehiculo no puede estar vacio. Intente de nuevo.\n");
            }
            repetida = 0; // reset the flag for each new vehicle
            for (int j = 0; j < i; j++)
            {
                if (strcmp(nombreVehiculo[i], nombreVehiculo[j]) == 0)
                {
                    printf("El nombre del vehiculo ya existe. Por favor, ingrese un nombre diferente.\n");
                    repetida = 1; // set the flag to indicate that nombreVehiculo is repeated
                    break;        // exit the loop if nombreVehiculo already exists
                }
            }
        } while (len == 0 || repetida == 1);
        do
        {
            printf("Ingrese la placa del vehiculo %d: ", i + 1);
            fflush(stdin);
            fgets(placa[i], 8, stdin);
            len = strlen(placa[i]);

            if (placa[i][len - 1] == '\n')
            {
                placa[i][len - 1] = '\0';
                len--;
            }

            if (len == 0)
            {
                printf("Placa no puede estar vacia. Intente de nuevo.\n");
            }
            // compare if placa already exist or not
            repetida = 0;
            for (int j = 0; j < i; j++)
            {
                if (strcmp(placa[i], placa[j]) == 0)
                {
                    printf("La placa ya existe. Por favor, ingrese una placa diferente.\n");
                    repetida = 1; // set the flag to indicate that placa is repeated
                    break;        // exit the loop if placa already exists
                }
            }

        } while (len == 0 || repetida == 1);

        do
        {
            printf("Por favor marque el estado del vehiculo %d (1. disponible 2. vendido)\n", i + 1);
            fflush(stdin);
            fgets(estado[i], 5, stdin);
            len = strlen(estado[i]);
            if (estado[i][len - 1] == '\n')
            {
                estado[i][len - 1] = '\0';
            }

            if (len == 0)
            {
                printf("Nombre del vehiculo no puede estar vacio. Intente de nuevo.\n");
            }
        } while (len == 0);

        do
        {
            printf("Desea agregar mas vehiculos? (1. Si, 2. No)\n");
            fflush(stdin);
            val = scanf("%d", &llenarmasvehiculos);
            if (val != 1)
            {
                printf("Entrada invalida. Por favor, ingrese un numero.\n");
            }
            if (llenarmasvehiculos == 2)
            {
                printf("\n");
                break; // Exit the loop if the user does not want to add more vehicles
            }
        } while (val != 1 && (llenarmasvehiculos < 1 || llenarmasvehiculos > 2));
        if (llenarmasvehiculos == 2)
        {
            printf("\n");
            break;
        }
    }
}

void searchCar(char cedula[MAX_VEHICLES][20], char placa[MAX_VEHICLES][8], char nombreVehiculo[MAX_VEHICLES][30], char estado[MAX_VEHICLES][5], int *contarcantidad)
{
    char buscar[30];
    int len;
    printf("Por favor ingrese la cedula o placa del vehiculo a buscar\n");
    fflush(stdin);
    fgets(buscar, 30, stdin);

    // Limpiar el \n del input
    len = strlen(buscar);
    if (buscar[len - 1] == '\n')
    {
        buscar[len - 1] = '\0';
        len--;
    }

    if (*contarcantidad == 0)
    {
        printf("No hay vehiculos registrados.\n");
        return;
    }

    // Variable para saber si encontramos el vehículo
    int encontrado = 0;

    for (int i = 0; i < *contarcantidad; i++)
    {
        if (strcmp(cedula[i], buscar) == 0 || strcmp(placa[i], buscar) == 0)
        {
            encontrado = 1;
            printf("\nVehiculo encontrado:\n");
            printf("Cedula: %s\n", cedula[i]);
            printf("Placa: %s\n", placa[i]);
            printf("Nombre del vehiculo: %s\n", nombreVehiculo[i]);

            if (strcmp(estado[i], "1") == 0)
            {
                printf("Estado: Disponible\n");
            }

            if (strcmp(estado[i], "2") == 0)
            {
                printf("Estado: Vendido\n");
            }
            break;
        }
    }

    if (encontrado != 1)
    {
        printf("\nVehiculo no encontrado.\n");
    }
}

void sellCar(char cedula[MAX_VEHICLES][20], char placa[MAX_VEHICLES][8], char nombreVehiculo[MAX_VEHICLES][30], char estado[MAX_VEHICLES][5], int *contarcantidad)
{
    char buscarcar[30];
    int opcin, len, val;
    if (*contarcantidad == 0)
    {
        printf("No hay vehiculos registrados.\n");
        return;
    }
    printf("Por favor ingrese la cedula o placa del vehiculo a vender\n");
    fflush(stdin);
    fgets(buscarcar, 30, stdin);
    len = strlen(buscarcar);
    if (buscarcar[len - 1] == '\n')
    {
        buscarcar[len - 1] = '\0';
        len--;
    }
    int encontrado = 0;
    for (int i = 0; i < *contarcantidad; i++)
    {
        if (strcmp(cedula[i], buscarcar) == 0 || strcmp(placa[i], buscarcar) == 0)
        {
            encontrado = 1;
            printf("\nVehiculo encontrado:\n");
            printf("Cedula: %s\n", cedula[i]);
            printf("Placa: %s\n", placa[i]);
            printf("Nombre del vehiculo: %s\n", nombreVehiculo[i]);
            if (strcmp(estado[i], "1") == 0)
            {
                printf("estado de venta: Disponible\n");
                do
                {
                    printf("Marque 1 para vender el vehiculo\n");
                    fflush(stdin);
                    val = scanf("%d", &opcin);
                    if (val != 1)
                    {
                        printf("Entrada invalida. Por favor, ingrese un numero.\n");
                    }

                } while (val != 1);
                estado[i][0] = '2'; // Marcar como vendido
                estado[i][1] = '\0'; // Asegurarse de que el estado sea una cadena válida
                printf("Vehiculo vendido exitosamente.\n");
            }
            
            if (strcmp(estado[i], "2") == 0)
            {
                printf("Estado: Vendido\n");
                printf("El vehiculo ya ha sido vendido.\n");
            }
        }
    }
}