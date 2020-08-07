#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{

int id;
char nombre[15];
char apellido[15];
int cuil;
int isEmpty;
}eCliente;

int buscarLibre(eCliente vecCliente[],int tamCliente);
int bajaCliente(eCliente vecCliente[],int tamCliente);
int modificarCliente(eCliente vecCliente[],int tamCliente);
void mostrarClientes(eCliente vecCliente[],int tamCliente);
void inicializarClientes(eCliente vec[],int tam);
int buscarIdCliente(int id,eCliente vecCliente[],int tam);
int altaCliente(int proxId,eCliente vecCliente[],int tamCliente);
int cargarNombreCliente(char descripcion[],char descripcion2[],int id, eCliente vecCiente[],int tamCliente);

#endif // CLIENTE_H_INCLUDED
