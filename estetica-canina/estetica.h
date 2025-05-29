#include <stdio.h>
#include <string.h>
#define MAX_CITAS 5

void registrarcita(char clientes[MAX_CITAS][30], char nombreMascota[MAX_CITAS][30], char fecha[MAX_CITAS][10], int *cant_citas);
void buscarcitaFecha(char clientes[MAX_CITAS][30], char nombreMascota[MAX_CITAS][30], char fecha[MAX_CITAS][10], int *cant_citas);
void buscarcitaCliente(char clientes[MAX_CITAS][30], char nombreMascota[MAX_CITAS][30], char fecha[MAX_CITAS][10], int *cant_citas);