#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cliente.h"
#include "trabajos.h"
#include "servicios.h"

int buscarNombreCliente(eCliente* clientes, int tam, int num, char* descNomb)
{
    int todoOk = 0;

    if(clientes && tam>0 && num>0 && descNomb)
    {
        for(int i=0; i<tam; i++)
        {
            if(clientes[i].id == num)
            {
                strcpy(descNomb, clientes[i].nombre);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarIndiceCliente(eCliente* clientes , int tam, int id, int* pIndex)
{
	int todoOk = 0;

	if(clientes && tam>0 && pIndex)
	{
		*pIndex = -1;

		for(int i=0;i<tam;i++)
		{
			if(clientes[i].id == id)
			{
				*pIndex = i;
				break;
			}
		}
		todoOk=1;
	}

	return todoOk;
}

int validarIdCliente(eCliente* clientes , int tam, int id)
{
	int esValido = 0;
	int indice;

	buscarIndiceCliente(clientes, tam, id, &indice);

	if(indice != -1)
	{
		esValido = 1;
	}

	return esValido;
}

int listarClientes(eCliente* clientes, int tam)
{
    int todoOk = 0;

    if(clientes && tam>0)
    {
        printf(" _________________________________________________________________________________________\n");
        printf("|                        Listado de clientes de notebook                                 |\n");
        printf("|-----------------------------------------------------------------------------------------|\n");
        for(int i=0; i<tam; i++)
        {
            printf("|  Id: %4d       |    Nombre: %20s   |  Sexo: %c  |\n",clientes[i].id, clientes[i].nombre , clientes[i].sexo);
        }
        printf("|_________________________________________________________________________________________|\n");
        todoOk = 1;
    }
    return todoOk;
}
