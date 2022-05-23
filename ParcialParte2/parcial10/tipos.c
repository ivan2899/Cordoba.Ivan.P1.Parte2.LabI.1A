#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tipos.h"

int listarTipos(eTipo* tipos, int tam)
{
    int todoOk = 0;

    if(tipos && tam>0)
    {
        printf(" _______________________________________________________________\n");
        printf("|          Listado de tipos de notebook                         |\n");
        printf("|---------------------------------------------------------------|\n");
        for(int i=0; i<tam; i++)
        {
            printf("|  Id: %4d       |    Tipo de notebook: %20s   |\n",tipos[i].id, tipos[i].desc);
        }
        printf("|_______________________________________________________________|\n");
        todoOk = 1;
    }
    return todoOk;
}

int validarIdTipo(eTipo* tipos , int tam, int id)
{
	int esValido = 0;
	int indice;

	buscarIndiceTipo(tipos, tam, id, &indice);

	if(indice != -1)
	{
		esValido = 1;
	}

	return esValido;
}

int buscarDescripcionTipo(eTipo* tipos, int tam, int num, char* descTip)
{
    int todoOk = 0;

    if(tipos && tam>0 && num>0 && descTip)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipos[i].id == num)
            {
                strcpy(descTip, tipos[i].desc);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarIndiceTipo(eTipo* tipos , int tam, int id, int* pIndex)
{
	int todoOk = 0;

	if(tipos && tam>0 && pIndex)
	{
		*pIndex = -1;

		for(int i=0;i<tam;i++)
		{
			if(tipos[i].id == id)
			{
				*pIndex = i;
				break;
			}
		}
		todoOk=1;
	}

	return todoOk;
}
