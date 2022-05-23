#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "notebooks.h"
#include "fecha.h"
#include "marcas.h"
#include "tipos.h"
#include "servicios.h"
#include "trabajos.h"
#include "general.h"
#include "cliente.h"

#define TAM_NOT 100
#define TAM_MARCAS 4
#define TAM_TIPOS 4
#define TAM_SERVICIOS 4
#define TAM_TRAB 100
#define TAM_CL 100

#define REINTENTOS 4


int main()
{
    eMarca marca[TAM_MARCAS] =
    {
        {1000, "Asus"},
        {1001, "Acer"},
        {1002, "Compaq"},
        {1003, "HP"}
    };
    eTipo tipos[TAM_TIPOS] =
    {
        {5000, "Disenio"},
        {5001, "Gamer"},
        {5002, "Normalita"},
        {5003, "Ultrabook"}
    };
    eServicio servicios[TAM_SERVICIOS] =
    {
        {20000, "Bateria", 2250},
        {20001, "Display", 10300},
        {20002, "Mantenimiento", 4400},
        {20003, "Fuente", 5600}
    };
    eCliente clientes[TAM_CL];
    eNotebook listaN[TAM_NOT];
    eTrabajo listaT[TAM_TRAB];
    char eleccion;
    int opcion;
    char confIngreso = 'n';
    char mensaje[50];
    int indice;
    int idRequerido;
    int banderaMenu = 0;
    int harNot;
    int usadoNot;
    int contNot = 0;
    int opcionSubMenuInforme;

    //IDs
    int idNotebook = 30000;
    int idTrabajos = 200000;
    int idCliente = 500000;

    inicializarNotebooks(listaN, TAM_NOT);
    inicializarTrabajos(listaT, TAM_TRAB);

    do
    {
        switch(menu())
        {
        case 1:
            strcpy(mensaje, "Alta Notebook");
            confirmaIngreso(&confIngreso, mensaje, REINTENTOS);

            if(confIngreso == 'S')
            {
                if(buscarPosicionLibreNotebook(listaN, TAM_NOT, &indice))
                {
                    system("cls");
                    printf("Ha ingresado a la opcion Alta Notebook\n\n");
                    altaNotebook(listaN, &idNotebook, TAM_NOT, indice, marca, TAM_MARCAS, tipos, TAM_TIPOS, clientes, TAM_CL, &idCliente);
                    banderaMenu = 1;
                }
                else
                {
                    printf("No hay mas espacio en el sistema!!\n");
                }
                confIngreso = 'n'; // Reset de la variable
            }
            else
            {
                printf("Se cancelo el alta de la notebook\n\n");
            }
            break;
        case 2:
            if(banderaMenu)
            {
                strcpy(mensaje, "Modificar Notebook");
                confirmaIngreso(&confIngreso, mensaje, REINTENTOS);

                if(confIngreso == 'S')
                {

                    printf("Ha ingresado a la opcion Modificar Notebook\n\n");
                    ordenarNotebooksId(listaN, TAM_NOT);
                    listarNotebooks(listaN, TAM_NOT, tipos, TAM_TIPOS, marca, TAM_MARCAS, clientes, TAM_CL);
                    printf("\nIngrese el id de la notebook a la que le quiera modificar un valor (ingrese 1 si desea salir): ");
                    scanf("%d", &idRequerido);
                    strcpy(mensaje, "Se ingreso un id no valido, reingrese el id: ");
                    if(idRequerido == 1)
                    {
                        break;
                    }
                    validarInt(&idRequerido, 30000, idNotebook-1, mensaje, REINTENTOS);

                    if(buscarPosicionPorIdNotebook(listaN, TAM_NOT, idRequerido, &indice))
                    {
                        system("cls");
                        listarUnaNotebook(listaN, TAM_NOT, tipos, TAM_TIPOS, marca, TAM_MARCAS, indice, clientes, TAM_CL);
                        opcion = subMenuModificar();
                        modificarNotebook(listaN, opcion, TAM_NOT, indice);
                        confIngreso = 'n';
                    }
                    else
                    {
                        printf("Ese id no se encuentra en el sistema");
                    }
                }
                else
                {
                    printf("Se cancelo la modificacion de la notebook\n\n");
                }
            }
            else
            {
                printf("Primero debe ingresar alguna notebook\n");
            }
            break;
        case 3:
            if(banderaMenu)
            {
                strcpy(mensaje, "Baja Notebook");
                confirmaIngreso(&confIngreso, mensaje, REINTENTOS);

                if(confIngreso == 'S')
                {
                    printf("Ha ingresado a baja notebook\n\n");
                    ordenarNotebooksId(listaN, TAM_NOT);
                    listarNotebooks(listaN, TAM_NOT, tipos, TAM_TIPOS, marca, TAM_MARCAS, clientes, TAM_CL);
                    bajaNotebook(listaN, TAM_NOT, tipos, TAM_TIPOS, marca, TAM_MARCAS, clientes, TAM_CL);


                }
                else
                {
                    printf("Se cancelo la baja de la notebook\n\n");
                }
            }
            else
            {
                printf("Primero debe ingresar alguna notebook\n");
            }
            break;
        case 4:
            if(banderaMenu)
            {
                printf("\nIngreso a listar notebook por marca y precio\n\n");
                ordenarNotebooksMarcaPrecio(listaN, TAM_NOT, tipos, TAM_TIPOS, marca, TAM_MARCAS);
                listarNotebooks(listaN, TAM_NOT, tipos, TAM_TIPOS, marca, TAM_MARCAS, clientes, TAM_CL);
            }
            else
            {
                printf("Primero debe ingresar alguna notebook\n");
            }
            break;
        case 5:
            printf("\nIngreso a listar marcas\n\n");
            listarMarcas(marca, TAM_MARCAS);
            break;
        case 6:
            printf("\nIngreso a listar tipos\n\n");
            listarTipos(tipos, TAM_TIPOS);
            break;
        case 7:
            printf("\nIngreso a listar servicios\n\n");
            listarServicios(servicios, TAM_SERVICIOS);
            break;
        case 8:
            if(banderaMenu)
            {
                strcpy(mensaje, "Alta Trabajo");
                confirmaIngreso(&confIngreso, mensaje, REINTENTOS);

                if(confIngreso == 'S')
                {
                    if(buscarPosicionLibreTrabajo(listaT, TAM_TRAB, &indice))
                    {
                        system("cls");
                        printf("Ha ingresado a la opcion Alta Trabajo\n\n");
                        ordenarNotebooksId(listaN, TAM_NOT);
                        listarNotebooks(listaN, TAM_NOT, tipos, TAM_TIPOS, marca, TAM_MARCAS, clientes, TAM_CL);
                        altaTrabajo(listaT, TAM_TRAB, servicios, TAM_SERVICIOS, &idTrabajos, indice);
                    }
                    else
                    {
                        printf("No hay mas espacio en el sistema!!\n");
                    }
                    confIngreso = 'n'; // Reset de la variable
                }
                else
                {
                    printf("Se cancelo el alta del trabajo\n\n");
                }
            }
            else
            {
                printf("Primero debe ingresar alguna notebook\n");
            }
            break;
        case 9:
            if(banderaMenu)
            {
                printf("Ingreso a listar trabajos\n\n");
                ordenarTrabajosId(listaT, TAM_TRAB);
                listarTrabajos(listaT, TAM_TRAB, servicios, TAM_SERVICIOS);
            }
            else
            {
                printf("Primero debe ingresar alguna notebook\n");
            }
            break;
        case 10:
            printf("Ingreso a harcodear Notebooks\n\n");

            buscarPosicionesDisponiblesNotebooks(listaN, TAM_NOT, &contNot);
            printf("Ingrese la cantidad de notebooks a harcodear (maximo %d): ", contNot);
            scanf("%d", &harNot);

            if(harcodearNotebook(listaN, TAM_NOT, harNot, &idNotebook, &idCliente))
            {
                printf("Las Notebooks se harcodearon con %cxito!!\n", 130);
                banderaMenu = 1;
            }
            else
            {
                printf("Ocurri%c un error al harcodear las Notebooks\n", 162);
            }
            break;
        case 11:
            buscarPosicionUsadaNotebook(listaN, TAM_NOT, &usadoNot);
            harcodearTrabajos(listaT, TAM_TRAB, 3, &idTrabajos, usadoNot);
            break;
        case 12:
            if(banderaMenu)
            {
                printf("Ha ingresado a informar");
                opcionSubMenuInforme = subMenuInformes();
                InformesGral(opcionSubMenuInforme, tipos, TAM_TIPOS, marca, TAM_MARCAS, listaN, TAM_NOT, listaT, TAM_TRAB, servicios, TAM_SERVICIOS, idNotebook, clientes, TAM_CL);
            }
            else
            {
                printf("Primero debe ingresar alguna notebook\n");
            }
            break;

        case 20:
            printf("\nIngreso a \"SALIR\"");
            confirmaSalida(&eleccion);
            if(eleccion != 'S')
            {
                printf("La salida se ha cancelado\n");
            }
            break;
        }
        printf("\n");
        system("pause");
    }
    while(eleccion != 'S');
    return 0;
}
