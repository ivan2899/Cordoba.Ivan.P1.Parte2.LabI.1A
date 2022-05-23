#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "marcas.h"

int listarMarcas(eMarca* marcas, int tam)
{
    int todoOk = 0;

    if(marcas && tam>0)
    {
        printf(" ____________________________________________________\n");
        printf("|          Listado de marcas                         |\n");
        printf("|----------------------------------------------------|\n");
        for(int i=0; i<tam; i++)
        {
            printf("|  Id: %4d       |    Marca: %20s   |\n",marcas[i].id, marcas[i].desc);
        }
        printf("|____________________________________________________|\n");
        todoOk = 1;
    }
    return todoOk;
}

int validarIdMarca(eMarca* marcas , int tam, int id)
{
	int esValido = 0;
	int indice;

	buscarIndiceMarca(marcas, tam, id, &indice);

	if(indice != -1)
	{
		esValido = 1;
	}

	return esValido;
}

int buscarDescripcionMarca(eMarca* marcas, int tam, int num, char* descMarc)
{
    int todoOk = 0;

    if(marcas && tam>0 && num>0 && descMarc)
    {
        for(int i=0; i<tam; i++)
        {
            if(marcas[i].id == num)
            {
                strcpy(descMarc, marcas[i].desc);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarIndiceMarca(eMarca* marcas , int tam, int id, int* pIndex)
{
	int todoOk = 0;

	if(marcas && tam>0 && pIndex)
	{
		*pIndex = -1;

		for(int i=0;i<tam;i++)
		{
			if(marcas[i].id == id)
			{
				*pIndex = i;
				break;
			}
		}
		todoOk=1;
	}

	return todoOk;
}
