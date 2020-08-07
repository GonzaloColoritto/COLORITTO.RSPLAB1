#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

typedef struct{

int id;
int idCliente;
int importe;
int cantidadCuotas;
char estado[15];
int isEmpty;

}ePrestamo;

int reanudarPrestamo(ePrestamo vecPrestamo[],int tamPrestamo,eCliente vecCliente[], int tamCliente);
int saldarPrestamo(ePrestamo vecPrestamo[],int tamPrestamo,eCliente vecCliente[], int tamCliente);
int buscarIdPrestamos(int id,ePrestamo vecPrestamo[],int tam);
void mostrarPrestamos(ePrestamo vecPrestamo[],int tamPrestamo,eCliente vecCLiente[],int tamCliente);
void mostrarPrestamo(ePrestamo prestamo, eCliente vecCliente[],int tamCliente);
int altaPrestamo(int proximoId,eCliente vecCliente[],int tamCliente,ePrestamo vecPrestamo[],int tamPrestamo);
void inicializarPrestamo(ePrestamo prestamo[], int tamPrestamo);
void mostrarPrestamosActivos(ePrestamo vecPrestamo[],int tamPrestamo,eCliente vecCLiente[],int tamCliente);
void mostrarPrestamosPersonalizados(ePrestamo vecPrestamo[],int tamPrestamo,eCliente vecCLiente[],int tamCliente);
#endif // PRESTAMOS_H_INCLUDED
