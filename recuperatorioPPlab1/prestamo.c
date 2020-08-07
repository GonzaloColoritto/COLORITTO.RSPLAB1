#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "menu.h"
#include <ctype.h>
#include <string.h>
#include "prestamos.h"

void inicializarPrestamo(ePrestamo prestamo[], int tamPrestamo)
{
    for (int i =0; i < tamPrestamo; i++)
    {
        prestamo[i].isEmpty = 1;
    }
}


int buscarIndiceLibrePrestamos(ePrestamo prestamo[], int tamPrestamo)
{
    int indiceLibre = -1;
    for (int i =0 ; i< tamPrestamo; i++)
    {
        if (prestamo[i].isEmpty)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre;
}


int altaPrestamo(int proximoId,eCliente vecCliente[],int tamCliente,ePrestamo vecPrestamo[],int tamPrestamo)
{

    int retorno=0;
    ePrestamo auxPrestamo;

    int indice=buscarIndiceLibrePrestamos(vecPrestamo,tamPrestamo);


    if(indice==-1)
    {
        printf("sistema lleno\n");
    }
    else
    {
        auxPrestamo.id=proximoId;
        printf("Su ID de prestamo es %d.\n",auxPrestamo.id);

        mostrarClientes(vecCliente,tamCliente);

        printf("Ingrese el id del cliente que desea el prestamo:");
        scanf("%d",&auxPrestamo.idCliente);

        while( buscarIdCliente(auxPrestamo.idCliente,vecCliente,tamCliente)<0)
        {
            printf("ERROR. ID invalido.\n");
            printf("Ingrese el id del cliente que desea el prestamo:");
            scanf("%d",&auxPrestamo.idCliente);
        }

        printf("Ingres el importe que desea como prestamo min[750] max[5000]:");
        scanf("%d",&auxPrestamo.importe);

        while(auxPrestamo.importe<750||auxPrestamo.importe>5000)
        {

            printf("ERROR. Importe invalido.");
            printf("Ingres el importe que desea como prestamo: ");
            scanf("%d",&auxPrestamo.importe);
        }

        printf("Ingrese el numero de cuotas min[4] max[18]:");
        scanf("%d",&auxPrestamo.cantidadCuotas);

        while(auxPrestamo.cantidadCuotas<4||auxPrestamo.cantidadCuotas>18)
        {

            printf("ERROR. Cuotas invalidas.");
            printf("Ingrese el numero de cuotas min[4] max[18]:");
            scanf("%d",&auxPrestamo.cantidadCuotas);
        }

        strcpy(auxPrestamo.estado,"ACTIVO");
        auxPrestamo.isEmpty=0;
        vecPrestamo[indice]=auxPrestamo;
        retorno=1;
    }



    return retorno;
}


void mostrarPrestamo(ePrestamo prestamo, eCliente vecCliente[],int tamCliente)
{

    char auxNombre[15];
    char auxApellido[15];

    if(prestamo.isEmpty==0)
    {
        cargarNombreCliente(auxNombre,auxApellido,prestamo.idCliente,vecCliente,tamCliente);
        printf("%3d  %15s %15s    %4d %2d %10s\n",prestamo.id,auxNombre,auxApellido,prestamo.importe,prestamo.cantidadCuotas,prestamo.estado);
    }

}


void mostrarPrestamos(ePrestamo vecPrestamo[],int tamPrestamo,eCliente vecCLiente[],int tamCliente)
{

    int flag=0;
    printf("ID            NOMBRE        APELLIDO IMPORTE CUOTAS ESTADO \n");
    for(int i=0; i<tamPrestamo; i++)
    {
        if(vecPrestamo[i].isEmpty==0)
        {
            mostrarPrestamo(vecPrestamo[i],vecCLiente,tamCliente);
            flag=1;
        }

    }

    if(flag==0)
    {

        printf("No hay prestamos.\n");
    }
}
void mostrarPrestamosParticulares(ePrestamo vecPrestamos[],int tamPrestamos,eCliente cliente,eCliente vecCliente[],int tamCliente)
{
    int flag=0;
             for(int i=0; i<tamPrestamos; i++)
    {
        if(vecPrestamos[i].isEmpty==0&&vecPrestamos[i].idCliente==cliente.id)
        {
            mostrarPrestamo(vecPrestamos[i],vecCliente,tamCliente);
            flag=1;
        }

    }

    if(flag==0)
    {
        printf("Este cliente no tiene prestamos.\n");
    }
}




void mostrarPrestamosActivos(ePrestamo vecPrestamo[],int tamPrestamo,eCliente vecCLiente[],int tamCliente)
{

    int flag=0;
    printf("PRESTAMOS ACTIVOS.\n");
    printf("ID            NOMBRE        APELLIDO IMPORTE CUOTAS ESTADO \n");
    for(int i=0; i<tamPrestamo; i++)
    {
        if(vecPrestamo[i].isEmpty==0&&strcmp(vecPrestamo[i].estado,"ACTIVO")==0)
        {
            mostrarPrestamo(vecPrestamo[i],vecCLiente,tamCliente);
            flag=1;
        }

    }

    if(flag==0)
    {

        printf("No hay prestamos.\n");
    }
}

int buscarIdPrestamos(int id,ePrestamo vecPrestamo[],int tam)
{
    int indice = -1;

    for (int i=0; i<tam; i++)
    {
        if (vecPrestamo[i].id==id)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


int saldarPrestamo(ePrestamo vecPrestamo[],int tamPrestamo,eCliente vecCliente[], int tamCliente)
{
    int retorno=0;
    int id;
    int indice;
    char confirmacion;
    mostrarPrestamos(vecPrestamo,tamPrestamo,vecCliente,tamCliente);
    printf("Ingrese el id del alquiler a saldar: ");
    scanf("%d",&id);

    indice=buscarIdPrestamos(id,vecPrestamo,tamPrestamo);

    while(indice<0)
    {

        printf("ERROR. ID no valido. \n");
        printf("Ingrese el ID del prestamo a saldar: ");
        scanf("%d",&id);
        indice=buscarIdPrestamos(id,vecPrestamo,tamPrestamo);
    }

    mostrarPrestamo(vecPrestamo[indice],vecCliente,tamCliente);
    printf("Desea saldar este prestamo? S/N");
    fflush(stdin);
    scanf("%c",&confirmacion);
    confirmacion=tolower(confirmacion);


    if(confirmacion=='s')
    {

        strcpy(vecPrestamo[indice].estado,"SALDADO");
        printf("Prestamo saldado.\n");
        retorno=1;
    }
    else
    {
        printf("Operacion cancelada.\n");
    }


    return retorno;
}

int reanudarPrestamo(ePrestamo vecPrestamo[],int tamPrestamo,eCliente vecCliente[], int tamCliente)
{

    int id;
    int indice;
    char confirmacion;
    int retorno=0;
    mostrarPrestamos(vecPrestamo,tamPrestamo,vecCliente,tamCliente);
    printf("Ingrese el id del prestamo a reanudar: ");
    scanf("%d",&id);

    indice=buscarIdPrestamos(id,vecPrestamo,tamPrestamo);

    while(indice<0)
    {

        printf("ERROR. ID no valido. \n");
        printf("Ingrese el ID del prestamo a reanudar: ");
        scanf("%d",&id);
        indice=buscarIdPrestamos(id,vecPrestamo,tamPrestamo);
    }
    if(strcmp(vecPrestamo[indice].estado,"SALDADO")==0)
    {
        mostrarPrestamo(vecPrestamo[indice],vecCliente,tamCliente);
        printf("Desea reanudar este prestamo? S/N");
        fflush(stdin);
        scanf("%c",&confirmacion);
        confirmacion=tolower(confirmacion);


        if(confirmacion=='s')
        {

            strcpy(vecPrestamo[indice].estado,"ACTIVO");
            printf("Prestamo reanudado.\n");
            retorno=1;
        }
        else
        {
            printf("Operacion cancelada.\n");
        }

    }
    else
    {
        printf("Ese prestamo ya esta activo y no se puede reanudar.\n");
    }


    return retorno;
}

void mostrarPrestamosPersonalizados(ePrestamo vecPrestamo[],int tamPrestamo,eCliente vecCLiente[],int tamCliente)
{
    int cant;
    int flag=0;
    printf("Ingrese el importe que desea mostrar, debe ser mayor a $1000: ");
    scanf("%d",&cant);

    while(cant<1000)
    {
        printf("ERROR. El importe debe ser mayor a 1000.\n");
        printf("Ingrese el importe que desea mostrar, debe ser mayor a $1000: ");
        scanf("%d",&cant);


    }
    printf("LISTADO DE PRESTAMOS ACTIVOS POR $%d\n\n",cant);
    for(int i=0; i<tamPrestamo; i++)
    {

        if(vecPrestamo[i].importe==cant&&strcmp(vecPrestamo[i].estado,"ACTIVO")==0)
        {
            mostrarPrestamo(vecPrestamo[i],vecCLiente,tamCliente);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("No hay un prestamo con ese importe.\n");
    }
}







