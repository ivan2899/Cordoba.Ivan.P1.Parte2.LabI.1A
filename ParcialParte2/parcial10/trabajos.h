#include "fecha.h"
#include "tipos.h"
#include "marcas.h"
#include "servicios.h"

#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJOS_H_INCLUDED

int inicializarTrabajos(eTrabajo* trabajos, int tam);

int buscarPosicionLibreTrabajo(eTrabajo* trabajos, int tam, int* pIndex);
int buscarPosicionPorIdTrabajo(eTrabajo* trabajos, int tam, int id, int* pIndex);
int buscarPosicionesDisponiblesTrabajos(eTrabajo* trabajos, int tam, int* pCont);

int altaTrabajo(eTrabajo* trabajos, int tamTrab, eServicio* servicios, int tamServ, int* pId, int i);

int listarUnTrabajo(eTrabajo* trabajos, int tamTrab, eServicio* servicios, int tamServ, int i);
int listarTrabajos(eTrabajo* trabajos, int tamTrab, eServicio* servicios, int tamServ);

int ordenarTrabajosId(eTrabajo* trabajos, int tam);

int harcodearTrabajos(eTrabajo* trabajos, int tam, int rep, int* id, int usadoNot);
