#include <stdio.h>
#include <string.h>
#include "funcionvehiculos.h"
#define MAX_VEHICLES 5 // that is te max number because the mr. says this

/*
Descripción del sistema a desarrollar:
Se desea crear un sistema para compra y venta de vehículos con las siguientes funcionalidades:
- Agregar vehículo
- Vender vehículo
- Buscar vehículo por cédula del dueño
- Atributos de cada vehículo:
- Nombre del dueño
- Cédula del dueño
- Placa
- Estado (vendido o disponible)
- Validación requerida:
- Evitar que se repitan vehículos (por ejemplo, por placa o cédula).
*/

int main (int argc, char *argv[]) {

    int opcion, val, contarcantidad = 0;
    char cedula[MAX_VEHICLES][20], placa[MAX_VEHICLES][8];
    char nombreVehiculo[MAX_VEHICLES][30], estado[MAX_VEHICLES][5];

    do
    {
        printf("================================\n");
        printf("Sistema de Gestion de Vehiculos\n");
        printf("================================\n");
        printf("\n");
        printf("======MENU DE OPCIONES======\n");
        printf("1. Agregar vehiculo\n");
        printf("2. Buscar vehiculo por cedula del dueño\n");
        printf("3. Vender vehiculo\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        do
        {
            fflush(stdin);
            val = scanf("%d", &opcion);
            if (val != 1)
            {
                printf("Entrada invalida. Por favor, ingrese un numero.\n");
            }
        } while (val != 1);

        if (opcion < 1 || opcion > 4)
        {
            printf("Opcion invalida. Por favor, seleccione una opcion del 1 al 4.\n");
            continue; //skip the rest of the loop and prompt again
        }
        switch (opcion)
    {
    case 1:
        AddCar(cedula, placa, nombreVehiculo, estado, &contarcantidad);
        break;
    
    case 2:
        searchCar(cedula, placa, nombreVehiculo, estado, &contarcantidad);
        break;

    case 3:
        sellCar(cedula, placa, nombreVehiculo, estado, &contarcantidad);
        break;
    default:
        break;
    }
    } while (opcion != 4);
    
    return 0;
}