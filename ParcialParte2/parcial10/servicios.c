#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "servicios.h"

int listarServicios(eServicio* servicios, int tam)
{
    int todoOk = 0;

    if(servicios && tam>0)
    {
        printf(" _________________________________________________________________________________________\n");
        printf("|                        Listado de servicios de notebook                                 |\n");
        printf("|-----------------------------------------------------------------------------------------|\n");
        for(int i=0; i<tam; i++)
        {
            printf("|  Id: %4d       |    Tipo de servicio: %20s   |  Precio: $%10.2f   |\n",servicios[i].id, servicios[i].desc, servicios[i].precio);
        }
        printf("|_________________________________________________________________________________________|\n");
        todoOk = 1;
    }
    return todoOk;
}

int validarIdServicio(eServicio* servicios , int tam, int id)
{
	int esValido = 0;
	int indice;

	buscarIndiceServicio(servicios, tam, id, &indice);

	if(indice != -1)
	{
		esValido = 1;
	}

	return esValido;
}

int buscarDescripcionServicio(eServicio* servicios, int tam, int num, char* descServ)
{
    int todoOk = 0;

    if(servicios && tam>0 && num>0 && descServ)
    {
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id == num)
            {
                strcpy(descServ, servicios[i].desc);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarIndiceServicio(eServicio* servicios , int tam, int id, int* pIndex)
{
	int todoOk = 0;

	if(servicios && tam>0 && pIndex)
	{
		*pIndex = -1;

		for(int i=0;i<tam;i++)
		{
			if(servicios[i].id == id)
			{
				*pIndex = i;
				break;
			}
		}
		todoOk=1;
	}

	return todoOk;
}

