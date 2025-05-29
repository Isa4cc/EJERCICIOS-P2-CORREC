#include <stdio.h>
#include <string.h>
#include "estetica.h"
#define MAX_CITAS 5
/*
Descripción del sistema a desarrollar:
Se desea crear un sistema para gestión de citas en una peluquería canina con las siguientes funcionalidades:
- Registrar cita
- Buscar cita por fecha
- Buscar cita por cliente
- Atributos de cada cita:
  - Nombre del cliente
  - Fecha (dd/mm/yy)
- Validación requerida:
  - Evitar que se registren múltiples citas en la misma fecha para el mismo cliente.
*/
int main (int argc, char *argv[]) {
    int opcin, val, cant_citas = 0;
    char citas[MAX_CITAS], nombreMascota[MAX_CITAS][30],clientes[MAX_CITAS][30], fecha[MAX_CITAS][10];

    do
    {
        printf("===Sistema de Gestion de Citas para Peluqueria Canina===\n");
        printf("1. Registrar Cita\n");
        printf("2. Buscar Cita por Fecha\n");
        printf("3. Buscar Cita por Cliente\n");
        printf("4. Salir\n");
        do
        {
            fflush(stdin);
            val = scanf("%d", &opcin);
            if (val !=1)
            {
                printf("Por favor ingrese un valor corecto (1-4)\n");
            }
            
        } while (val != 1);
        if (opcin < 1 || opcin >4)
        {
            printf("Por favor ingrese un valor corecto (1-4)\n");
        }
        switch (opcin)
        {
        case 1:
            registrarcita(clientes, nombreMascota,fecha, &cant_citas);
            break;
        case 2:
            buscarcitaFecha(clientes, nombreMascota, fecha, &cant_citas);
            break;
        case 3:
            buscarcitaCliente(clientes, nombreMascota, fecha, &cant_citas);
            break;
        default:
            break;
        }
    } while (opcin != 4);
    return 0;
}