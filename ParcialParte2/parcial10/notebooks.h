#include "tipos.h"
#include "marcas.h"
#include "cliente.h"

#ifndef NOTEBOOKS_H_INCLUDED
#define NOTEBOOKS_H_INCLUDED

typedef struct
{
    int id;
    char modelo[21];
    int idMarca;
    int idTipo;
    int idCliente;
    float precio;
    int isEmpty;

}eNotebook;

#endif // NOTEBOOKS_H_INCLUDED

int inicializarNotebooks(eNotebook* notebooks, int tam);

int buscarPosicionLibreNotebook(eNotebook* notebooks, int tam, int* pIndex);
int buscarPosicionPorIdNotebook(eNotebook* notebooks, int tam,int id, int* pIndex);
int buscarPosicionesDisponiblesNotebooks(eNotebook* notebooks, int tamNot, int* pCont);
int buscarPosicionUsadaNotebook(eNotebook* notebooks, int tamNot, int* pCont);

int altaNotebook(eNotebook* notebooks, int* pId, int tam, int i, eMarca* marcas, int tamMarcas, eTipo* tipos, int tamTipos, eCliente* clientes, int tamClientes, int* pIdCliente);
int bajaNotebook(eNotebook* notebooks, int tam, eTipo* tipos, int tamTIpos, eMarca* marcas, int tamMarcas, eCliente* clientes, int tamCl);
int modificarNotebook(eNotebook* notebooks, int opcion, int tam, int i);

int listarUnaNotebook(eNotebook* notebooks, int tam, eTipo* tipos, int tamTip, eMarca* marcas, int tamMarc, int i, eCliente* clientes, int tamCl);
int listarNotebooks(eNotebook* notebooks, int tam, eTipo* tipos, int tamTip, eMarca* marcas, int tamMarc, eCliente* clientes, int tamCl);

int ordenarNotebooksMarcaPrecio(eNotebook* notebooks, int tam, eTipo* tipos, int tamTip, eMarca* marcas, int tamMarc);
int ordenarNotebooksId(eNotebook* notebooks, int tam);

int harcodearNotebook(eNotebook* notebooks, int tamNot, int rep, int* id, int* pIdCliente);
