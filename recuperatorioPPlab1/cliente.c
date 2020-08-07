#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "utn.h"
#include <string.h>
#include <ctype.h>
#include "prestamos.h"
/** \brief busca el primer indice libre de un array y lo devuelve
 *
 * \param vector del tipo ecliente a recorrer
 * \param el tamaño del vector
 * \return devuelve el indice libre y si no hay devuelve -1
 *
 */

int buscarLibre(eCliente vecCliente[],int tamCliente)
{
    int indice=-1;
    for(int i=0; i<tamCliente; i++)
    {

        if(vecCliente[i].isEmpty == 1)
        {

            indice=i;
            break;
        }
    }
    return indice;

}
/** \brief busca el id de un cliente en un array de clientes
 *
 * \param se le pas el id del cliente a buscar
 * \param
 * \return
 *
 */

int buscarIdCliente(int id,eCliente vecCliente[],int tam)
{
    int indice = -1;

    for (int i=0; i<tam; i++)
    {
        if (vecCliente[i].id==id)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void inicializarClientes(eCliente vec[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}


int altaCliente(int proxId,eCliente vecCliente[],int tamCliente)
{

    int retorno=0;
    eCliente auxCliente;
    int indice=buscarLibre(vecCliente,tamCliente);

    if(indice==-1)
    {

        printf("Sistema lleno.\n");
    }
    else
    {
        auxCliente.id=proxId;
        printf("Su ID es: %d\n",auxCliente.id);

        printf("Ingrese su cuil: ");
        scanf("%d",&auxCliente.cuil);
        while(auxCliente.cuil<15000000||auxCliente.cuil>60000000)
        {

            printf("ERROR.Ingrese su cuil nuevamente: ");
            scanf("%d",&auxCliente.cuil);
        }
        do
        {
            printf("Ingrese su nombre: ");
            fflush(stdin);
            gets(auxCliente.nombre);
            strlwr(auxCliente.nombre);
            auxCliente.nombre[0]=toupper(auxCliente.nombre[0]);
        }
        while(isValidName(auxCliente.nombre)!=-1);



        do
        {
            printf("Ingrese su apellido: ");
            fflush(stdin);
            gets(auxCliente.apellido);
            strlwr(auxCliente.apellido);
            auxCliente.apellido[0]=toupper(auxCliente.apellido[0]);
        }
        while(isValidName(auxCliente.apellido)!=-1);

        auxCliente.isEmpty=0;
        vecCliente[indice]=auxCliente;
        retorno=1;
    }




    return retorno;
}


void mostrarCliente(eCliente cliente)
{

    if(cliente.isEmpty==0)
    {

        printf("%4d   %8d %20s %20s \n",cliente.id,cliente.cuil,cliente.nombre,cliente.apellido);
    }

}
void mostrarClienteConPrestamosActivos(ePrestamo vecPrestamo[],int tamPrestamo,eCliente cliente)
{

    int cantidadPrestamosActivos=0;
    if(cliente.isEmpty==0)
    {
        cantidadPrestamosActivos = buscarPrestamosActivos(vecPrestamo,tamPrestamo,cliente);
        printf("%4d   %8d %20s %20s     %2d\n",cliente.id,cliente.cuil,cliente.nombre,cliente.apellido,cantidadPrestamosActivos);
    }


}

void mostrarClientes(eCliente vecCliente[],int tamCliente)
{
    int flag=0;
    printf("ID     CUIL                    NOMBRE             APELLIDO\n");
    printf("_________________________________________________________\n");
    for(int i=0; i<tamCliente; i++)
    {

        if(vecCliente[i].isEmpty==0)
        {

            mostrarCliente(vecCliente[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No hay clientes en la base de datos\n");
    }
}
void mostrarClientesConPrestamosActivos(eCliente vecCliente[],int tamCliente,ePrestamo vecPrestamo[],int tamPrestamo)
{
    int flag=0;
    printf("ID     CUIL                    NOMBRE             APELLIDO   PRESTAMOS ACTIVOS\n");
    printf("_________________________________________________________\n");
    for(int i=0; i<tamCliente; i++)
    {

        if(vecCliente[i].isEmpty==0)
        {

            mostrarClienteConPrestamosActivos(vecPrestamo,tamPrestamo,vecCliente[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No hay clientes en la base de datos\n");
    }
}
int buscarPrestamosActivos(ePrestamo vecPrestamos[],int tamPrestamo, eCliente cliente)
{
    int contador=0;
    for(int i=0; i<tamPrestamo; i++)
    {
        if((strcmp(vecPrestamos[i].estado,"ACTIVO")==0))
        {
            printf("entro al primer if\n");
            if(vecPrestamos[i].idCliente==cliente.id)
            {
                printf("entro al segundo if\n");
                contador++;
            }
        }



    }
    return contador;
}



int modificarCliente(eCliente vecCliente[],int tamCliente)
{

    int id;
    int indice;
    int opcion;
    int retorno=-1;
    printf("MODIFICAR CLIENTE\n\n");
    mostrarClientes(vecCliente,tamCliente);

    printf("Ingrese el ID del cliente a modificar:");
    scanf("%d",&id);

    indice=buscarIdCliente(id,vecCliente,tamCliente);

    if(indice==-1)
    {

        printf("ID invalido.\n");
    }
    else
    {

        do
        {
            printf("MODIFICAR NOMBRE [1]\n");
            printf("MODIFICAR APELLIDO [2]\n");
            printf("MODIFICAR CUIL [3]\n");
            printf("Ingrese una opcion:");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                do
                {
                    printf("Ingrese su nombre: ");
                    fflush(stdin);
                    gets(vecCliente[indice].nombre);
                    strlwr(vecCliente[indice].nombre);
                    vecCliente[indice].nombre[0]=toupper(vecCliente[indice].nombre[0]);
                }
                while(isValidName(vecCliente[indice].nombre)!=-1);
                retorno=1;

                break;

            case 2:

                do
                {
                    printf("Ingrese su apellido: ");
                    fflush(stdin);
                    gets(vecCliente[indice].apellido);
                    strlwr(vecCliente[indice].apellido);
                    vecCliente[indice].apellido[0]=toupper(vecCliente[indice].apellido[0]);
                }
                while(isValidName(vecCliente[indice].apellido)!=-1);
                retorno=1;
                break;



            case 3:
                printf("Ingrese su cuil: ");
                scanf("%d",&vecCliente[indice].cuil);
                while(vecCliente[indice].cuil<15000000||vecCliente[indice].cuil>60000000)
                {

                    printf("ERROR.Ingrese su cuil nuevamente: ");
                    scanf("%d",&vecCliente[indice].cuil);
                }
                break;
            }

        }
        while(opcion!=1&&opcion!=2);




    }

    return retorno;
}

int bajaCliente(eCliente vecCliente[],int tamCliente)
{

    int id;
    int indice;

    int retorno=-1;
    char confirmacion;
    printf("ELIMINAR CLIENTE\n\n");
    mostrarClientes(vecCliente,tamCliente);

    printf("Ingrese el ID del cliente a eliminar:");
    scanf("%d",&id);

    indice=buscarIdCliente(id,vecCliente,tamCliente);
    if(indice!=-1)
    {
        mostrarCliente(vecCliente[indice]);
        //mostrarPrestamosParticulares(vecPrestamo,int tamPrestamo, vecCliente[indice],vecCliente,int tamCliente);
        printf("¿Desea eliminar este cliente?: S/N");
        fflush(stdin);
        scanf("%c",&confirmacion);
        confirmacion=tolower(confirmacion);


        if(confirmacion=='s')
        {
            vecCliente[indice].isEmpty=1;

            retorno=1;
        }
        else
        {
            printf("Baja cancelada.\n");
        }
    }
    else
    {
        printf("ID INVALIDO\n");
    }

    return retorno;
}

int cargarNombreCliente(char descripcion[],char descripcion2[],int id, eCliente vecCiente[],int tamCliente)
{


    int todoOk=0;

    for(int i=0; i < tamCliente ; i++)
    {

        if(vecCiente[i].id == id)
        {

            strcpy(descripcion,vecCiente[i].nombre);
            strcpy(descripcion2,vecCiente[i].apellido);
            todoOk=1;

        }

    }

    return todoOk;

}




