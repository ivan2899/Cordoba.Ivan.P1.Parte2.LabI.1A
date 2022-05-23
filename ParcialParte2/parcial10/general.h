#include "tipos.h"
#include "marcas.h"
#include "notebooks.h"
#include "trabajos.h"

#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED



#endif // GENERAL_H_INCLUDED

int menu();
int subMenuModificar();
int subMenuInformes();

int InformesGral(int opcion, eTipo* tipos, int tamTipos, eMarca* marcas, int tamMarcas, eNotebook* notebooks, int tamNote, eTrabajo* trabajos, int tamTrab, eServicio* servicios, int tamServ, int idNotebook, eCliente* clientes, int tamCl);

int confirmaSalida(char* eleccion);
int confirmaIngreso(char* eleccion, char* mensaje, int reintentos);
int confirma(char* eleccion, int reintentos);
int validarGets(int tam, char auxCad[100]);
int validarInt(int* num, int minimo, int maximo, char* mensajeError, int reintentos);

int informeNotebookTipoSeleccionado(eNotebook* notebooks, int tamNote, eTipo* tipos, int tamTipo, eMarca* marcas, int tamMarcas, int idTipo, eCliente* clientes, int tamCl);
int informeNotebookMarcaSeleccionado(eNotebook* notebooks, int tamNote, eTipo* tipos, int tamTipo, eMarca* marcas, int tamMarcas, int idMarca, eCliente* clientes, int tamCl);
int informeNotebooksMasBaratas(eNotebook* notebooks, int tamNote, eTipo* tipos, int tamTipos, eMarca* marcas, int tamMarcas, eCliente* clientes, int tamCl);
int informarTrabajosRealizados(eTrabajo* trabajos, int tamTrab, eNotebook* notebooks, int tamNote, int indice, eServicio* servicios, int tamServ, int idNotebook);
int informarSumaDeImportes(eNotebook* notebooks, int tamNote, eTrabajo* trabajos, int tamTrab, eServicio* servicios, int tamServ, int id);
int informeNotebookServicioFecha(eNotebook* notebooks, int tamNote, eServicio* servicios, int tamServ, eTrabajo* trabajos, int tamTrab, int id);
int informarServiciosEnFecha(eNotebook* notebooks, int tamNote, eServicio* servicios, int tamServ, eTrabajo* trabajos, int tamTrab, eFecha fechaAux);
