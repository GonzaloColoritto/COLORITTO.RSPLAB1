#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#define TAMCLIENTE 50
#include "menu.h"
#define TAMPRESTAMO 50
#include "prestamos.h"
int main()
{
   char seguir='s';
   eCliente vecCliente[TAMCLIENTE];
   int proximoId=1000;
   int proximoIdTrabajo=100;
   ePrestamo vecPrestamo[TAMPRESTAMO];
   inicializarClientes(vecCliente,TAMCLIENTE);
   inicializarPrestamo(vecPrestamo,TAMPRESTAMO);
   do{

    switch(menuInicio()){

    case 1:
         if(altaCliente(proximoId,vecCliente,TAMCLIENTE))
            {
                printf("Alta exitosa\n");
                proximoId++;

            }
            else
            {
                printf("Error al dar de alta.\n");
            }
        break;

    case 2:
        if(modificarCliente(vecCliente,TAMCLIENTE)==1)
            {
                printf("Modificacion exitosa\n");
            }
            else
            {
                printf("ERROR AL MODIFICAR!\n");
            }
        break;

    case 3:
        if(bajaCliente(vecCliente,TAMCLIENTE)==1)
            {
                printf("Baja exitosa\n");
            }
            else
            {
                printf("ERROR AL ELIMINAR!\n");
            }
        break;

    case 4:
        if(altaPrestamo(proximoIdTrabajo,vecCliente,TAMCLIENTE,vecPrestamo,TAMPRESTAMO)==1){
            proximoIdTrabajo++;
            printf("Alta exitosa\n");
        }else{
        printf("error en la alta\n");
        }
        break;
    case 5:
        saldarPrestamo(vecPrestamo,TAMPRESTAMO,vecCliente,TAMCLIENTE);
        break;
    case 6:
        reanudarPrestamo(vecPrestamo,TAMPRESTAMO,vecCliente,TAMCLIENTE);
        break;
    case 7:
        mostrarClientesConPrestamosActivos(vecCliente,TAMCLIENTE,vecPrestamo,TAMPRESTAMO);
        break;
    case 8:
        mostrarPrestamosActivos(vecPrestamo,TAMPRESTAMO,vecCliente,TAMCLIENTE);
        break;
    case 9:

        break;
    case 10:
        mostrarPrestamosPersonalizados(vecPrestamo,TAMPRESTAMO,vecCliente,TAMCLIENTE);
        break;
    }
    system("pause");
   }while( seguir=='s');
}
