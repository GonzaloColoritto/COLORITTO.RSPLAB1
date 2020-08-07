#include <stdio.h>
#include <stdlib.h>
int menuInicio()
{


    system("cls");
    int opcion;
    printf("-ALQUILER DE MAQUINARIA-\n\n");
    printf("1- ALTA CLIENTE\n");
    printf("2- MODIFICAR CLIENTE\n");
    printf("3- BAJA CLIENTE\n");
    printf("4- ALTA PRESTAMO\n");
    printf("5- SALDAR PRESTAMO\n");
    printf("6- REANUDAR PRESTAMO\n");
    printf("7- IMPRIMIR CLIENTES\n");
    printf("8- IMPRIMIR PRESTAMOS\n");
    printf("9- INFORMAR CLIENTES\n");
    printf("10- INFORMAR PRESTAMOS\n");


    printf("\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
