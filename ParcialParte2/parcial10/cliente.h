#include "servicios.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char sexo;
}eCliente;

#endif // CLIENTE_H_INCLUDED

int listarClientes(eCliente* clientes, int tam);

int validarIdCliente(eCliente* clientes , int tam, int id);

int buscarNombreCliente(eCliente* clientes, int tam, int num, char* descNomb);
int buscarIndiceCliente(eCliente* clientes , int tam, int id, int* pIndex);
