#include <stdio.h>
#include <string.h>
#define MAX_VEHICLES 5
void AddCar(char cedula[MAX_VEHICLES][20], char placa[MAX_VEHICLES][8],
            char nombreVehiculo[MAX_VEHICLES][30], char estado[MAX_VEHICLES][5], int *contarcantidad);

void searchCar(char cedula[MAX_VEHICLES][20], char placa[MAX_VEHICLES][8],
             char nombreVehiculo[MAX_VEHICLES][30], char estado[MAX_VEHICLES][5], int *contarcantidad);

void sellCar(char cedula[MAX_VEHICLES][20], char placa[MAX_VEHICLES][8],
             char nombreVehiculo[MAX_VEHICLES][30], char estado[MAX_VEHICLES][5], int *contarcantidad);