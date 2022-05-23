#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "trabajos.h"
#include "servicios.h"

int inicializarTrabajos(eTrabajo* trabajos, int tam)
{
    int todoOk = 0;
    if(trabajos != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarPosicionLibreTrabajo(eTrabajo* trabajos, int tam, int* pIndex)
{
    int todoOk = 0;
    if(trabajos && pIndex && tam>0 )
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(trabajos[i].isEmpty)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int altaTrabajo(eTrabajo* trabajos, int tamTrab, eServicio* servicios, int tamServ, int* pId, int i)
{
    int todoOk = 0;
    int idNot;
    int idSer;
    eFecha fecha;

    if(trabajos && pId && tamTrab>0)
    {
        trabajos[i].id = *pId;
        *pId = *pId + 1;

        printf("\nSi desea salir ingrese el n%cmero \"1\" \n", 163);
        printf("Ingrese id de la notebook (mayor o igual a 30000): ");
        scanf("%d", &idNot);
        idNot = toupper(idNot);

        while(idNot < 30000 || isalpha(idNot))
        {
            if(idNot == 1)
            {
                return todoOk;
            }
            fflush(stdin);
            printf("Reingrese el id de la notebook v%clido (mayor o igual a 30000):", 160);
            scanf("%d", &idNot);
            idNot = toupper(idNot);
        }
        trabajos[i].idNotebook = idNot;

        listarServicios(servicios, tamServ);
        printf("\nIngrese id del servicio: ");
        scanf("%d", &idSer);
        idSer = toupper(idSer);

        while(idSer < 20000 || idSer >20003 || isalpha(idSer))
        {
            fflush(stdin);
            printf("Reingrese el id del servicio (de 20000 a 20003):");
            scanf("%d", &idSer);
            idSer = toupper(idSer);
        }
        trabajos[i].idServicio = idSer;

        pedirYValidarFecha(&fecha.dia, &fecha.mes, &fecha.anio, 1800, 2022);
        trabajos[i].fecha = fecha;

        trabajos[i].isEmpty = 0;
    }
    return todoOk;
}

int buscarPosicionPorId(eTrabajo* trabajos, int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if(trabajos && tam > 0 && pIndex && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarUnTrabajo(eTrabajo* trabajos, int tamTrab, eServicio* servicios, int tamServ, int i)
{
    int todoOk = 0;
    char descServicio[20];

    if(trabajos && tamTrab>0 && servicios && tamServ>0 && i >=0)
    {
        if(!(trabajos[i].isEmpty))
        {
            buscarDescripcionServicio(servicios, tamServ, trabajos[i].idServicio, descServicio);
            printf("\n| Id: %7d       | Id Notebook: %7d   | Servicio: %20s   | Fecha: %2d/%02d/%4d    |", trabajos[i].id, trabajos[i].idNotebook, descServicio, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio );
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarTrabajos(eTrabajo* trabajos, int tamTrab, eServicio* servicios, int tamServ)
{
    int todoOk = 0;

    if(trabajos && tamTrab>0 && servicios && tamServ>0)
    {
        printf(" ______________________________________________________________________________________________________\n");
        printf("|                                             **Listado de trabajos**                                  |\n");
        printf("|------------------------------------------------------------------------------------------------------|");
        for(int i=0; i<tamTrab; i++)
        {
            listarUnTrabajo(trabajos, tamTrab, servicios, tamServ, i);
        }
        printf("\n|______________________________________________________________________________________________________|\n");

        todoOk = 1;
    }
    return todoOk;
}

int buscarPosicionesDisponiblesTrabajos(eTrabajo* trabajos, int tam, int* pCont)
{
    int todoOk = 0;
    int cont = 0;

    if(trabajos && pCont && tam>0 )
    {
        for(int i=0; i<tam; i++)
        {
            if(trabajos[i].isEmpty)
            {
                cont++;
            }
        }
        todoOk = 1;
        *pCont = cont;
    }
    return todoOk;
}

int ordenarTrabajosId(eTrabajo* trabajos, int tam)
{
    int todoOk = 0;
    eTrabajo aux;

    if(trabajos && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!(trabajos[i].isEmpty))
            {
                for(int i=0; i<tam-1; i++)
                {
                    for(int j=i+1; j<tam; j++)
                    {
                        if(!(trabajos[i].isEmpty) && !(trabajos[j].isEmpty))
                        {
                            if(trabajos[i].id > trabajos[j].id)
                            {
                                aux = trabajos[i];
                                trabajos[i] = trabajos[j];
                                trabajos[j] = aux;
                            }
                        }
                    }
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int harcodearTrabajos(eTrabajo* trabajos, int tam, int rep, int* id, int usadoNot)
{
    int todoOk = 0;
    int i;
    int contEspacio;

    if(trabajos && tam > 0 && rep <= tam)
    {
        buscarPosicionesDisponiblesTrabajos(trabajos, tam, &contEspacio);
        if(rep<=contEspacio && rep <= usadoNot)
        {
            for(int in=0; in<rep; in++)
            {
                if(buscarPosicionLibreTrabajo(trabajos, tam, &i))
                {
                    if(in == 0)
                    {
                        trabajos[i].id = *(id);
                        *id = *(id)+1;
                        trabajos[i].idNotebook = 30000;
                        trabajos[i].idServicio = 20000;
                        trabajos[i].fecha.dia = 1;
                        trabajos[i].fecha.mes = 12;
                        trabajos[i].fecha.anio = 2018;
                        trabajos[i].isEmpty = 0;
                    }
                    else if(in == 1)
                    {
                        trabajos[i].id = *(id);
                        *id = *(id)+1;
                        trabajos[i].idNotebook = 30001;
                        trabajos[i].idServicio = 20001;
                        trabajos[i].fecha.dia = 4;
                        trabajos[i].fecha.mes = 8;
                        trabajos[i].fecha.anio = 2017;
                        trabajos[i].isEmpty = 0;
                    }
                    else if(in == 2)
                    {
                        trabajos[i].id = *(id);
                        *id = *(id)+1;
                        trabajos[i].idNotebook = 30002;
                        trabajos[i].idServicio = 20002;
                        trabajos[i].fecha.dia = 27;
                        trabajos[i].fecha.mes = 2;
                        trabajos[i].fecha.anio = 2019;
                        trabajos[i].isEmpty = 0;
                    }
                }
            }



        }
        todoOk = 1;
    }

    return todoOk;
}


