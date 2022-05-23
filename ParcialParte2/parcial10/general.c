#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "general.h"
#include "tipos.h"

int menu()
{
    int opcion;

    system("cls");
    printf(" ________________________________________\n");
    printf("|       *** Men%c Principal ***           |\n", 163);
    printf("|----------------------------------------|\n");
    printf("|  1) Darle de alta a la notebook        |\n");
    printf("|  2) Modificar notebook                 |\n");
    printf("|  3) Darle de baja a la notebook        |\n");
    printf("|  4) Listar notebook por marca y precio |\n");
    printf("|  5) Listar marcas                      |\n");
    printf("|  6) Listar tipos                       |\n");
    printf("|  7) Listar servicios                   |\n");
    printf("|  8) Alta trabajo                       |\n");
    printf("|  9) Listar trabajos                    |\n");
    printf("| 10) Harcodear Notebooks                |\n");
    printf("| 11) Harcodear trabajos                 |\n");
    printf("| 12) Informar Notebooks                 |\n");
    printf("| 20) Salir                              |\n");
    printf("|________________________________________|\n\n");

    printf("Ingrese opci%cn: ", 162);
    fflush(stdin); // Limpio el buff porque si en algun otro menu ingresan un numero seguido de enter o una letra, da como erroneo
    scanf("%d", &opcion);
    opcion = toupper(opcion);

    while(((opcion < 1 || opcion > 12) && opcion != 20) || isalpha(opcion) == 1)
    {
        fflush(stdin);      //Limpio el buff de entrada para que en el caso de que arriba ingresen una letra no se rompa el progama
        printf("Se ingreso una opci%cn erronea, ingrese la opci%cn nuevamente: ", 162, 162);
        scanf("%d", &opcion);
    }
    return opcion;
}

int subMenuModificar()
{
    int opcion;
    printf("\n\n ______________________________________ \n");
    printf("|      *** Modificar notebook ***      |\n");
    printf("|______________________________________| \n");
    printf("| Que desea modificar?                 |\n");
    printf("|--------------------------------------| \n");
    printf("| 1) Precio                            |\n");
    printf("| 2) Tipo                              |\n");
    printf("| 3) Salir                             |\n");
    printf("|______________________________________|\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin); // Limpio el buff porque si en algun otro menu ingresan un numero seguido de enter, da como erroneo
    scanf("%d", &opcion);

    while(opcion < 1 || opcion > 3)
    {
        fflush(stdin);
        printf("Se ingreso una opcion erronea, ingrese la opcion nuevamente: ");
        scanf("%d", &opcion);
    }

    return opcion;
}

int confirmaSalida(char* eleccion)
{
    int todoOk = 0;
    char auxSalida;

    if(eleccion)
    {
        do
        {
            system("cls");
            printf(" ______________________________________ \n");
            printf("|   Ha ingresado a la opcion SALIR     |\n");
            printf("|______________________________________|\n\n");
            printf("Esta seguro que desea salir?\n");
            printf("Ingrese una letra, \"s\" para si: ");
            fflush(stdin);
            scanf("%c", &auxSalida);
            auxSalida = toupper(auxSalida);

        }
        while(!isalpha(auxSalida));
        *eleccion = auxSalida;
        todoOk = 1;
    }
    return todoOk;
}

int confirmaIngreso(char* eleccion, char* mensaje, int reintentos)
{
    int todoOk = 0;

    if(eleccion && mensaje)
    {
        system("cls");
        printf("\nEsta seguro que desea ingresar a \"%s\" ?\n", mensaje);
        confirma(eleccion, reintentos);
        todoOk = 1;
    }
    return todoOk;
}

int confirma(char* eleccion, int reintentos)
{
    int todoOk = 0;
    char auxSalida;

    if(eleccion)
    {
        printf("Ingrese una letra, \"s\" para si: ");
        fflush(stdin);
        scanf("%c", &auxSalida);
        auxSalida = toupper(auxSalida);


        do
        {
            if(isalpha(auxSalida))
            {
                break;
            }
            printf("Reingrese una letra, \"s\" para si: ");
            fflush(stdin);
            scanf("%c", &auxSalida);
            auxSalida = toupper(auxSalida);
            reintentos--;
        }
        while(!isalpha(auxSalida) && reintentos > 0);

        *eleccion = auxSalida;
        todoOk = 1;
    }
    return todoOk;
}

int validarGets(int tam, char auxCad[100])
{
    int validacion = 0;
    if(tam > 0 && auxCad)
    {
        if(strlen(auxCad) < tam)
        {
            validacion = 1;
        }
    }
    return validacion;
}

int validarInt(int* num, int minimo, int maximo, char* mensajeError, int reintentos)
{
    int todoOk = 0;

    if(num && minimo<=maximo && mensajeError)
    {
        do
        {
            if( (*(num) < minimo || *(num) > maximo))
            {
                fflush(stdin);  // Se limpia el buffer para que no se quede en bucle el programa si ingresa una letra
                printf("%s", mensajeError);
                scanf("%d", num);
                reintentos--;
            }

            else
            {
                break;
            }
        }
        while(reintentos>=0);


        todoOk = 1;
    }
    return todoOk;
}

int subMenuInformes()
{
    int opcion;
    system("cls");
    printf(" ________________________________________\n");
    printf("|       *** Service de notebooks ***           \n");
    printf("|----------------------------------------\n");
    printf("|  1) Mostrar notebook por tipo        \n");
    printf("|  2) Mostrar notebook por marca                \n");
    printf("|  3) Notebooks mas baratas        \n");
    printf("|  4) Listar notebooks por marca \n");
    printf("|  5) Listar tipo y marcas                      \n");
    printf("|  6) Listar marcas mas elegidas                \n");
    printf("|  7) Listar servicios que se le hicieron a una notebook                   \n");
    printf("|  8) Suma de importe con los servicios que se le hicieron a una notebook                       \n");
    printf("|  9) Ingresar un Servicio y mostrar a las notebooks que se le realizo este servicio                   \n");
    printf("| 10) Pedir fecha y mostrar todos los servicios realizados esta fecha                \n");
    printf("| 11) Salir                              \n");
    printf("|________________________________________\n\n");

    printf("Ingrese opci%cn: ", 162);
    fflush(stdin); // Limpio el buff porque si en algun otro menu ingresan un numero seguido de enter o una letra, da como erroneo
    scanf("%d", &opcion);
    opcion = toupper(opcion);

    while(opcion < 1 || opcion > 11 || isalpha(opcion) == 1)
    {
        fflush(stdin);      //Limpio el buff de entrada para que en el caso de que arriba ingresen una letra no se rompa el progama
        printf("Se ingreso una opci%cn erronea, ingrese la opci%cn nuevamente: ", 162, 162);
        scanf("%d", &opcion);
    }
    return opcion;
}

int informeNotebookTipoSeleccionado(eNotebook* notebooks, int tamNote, eTipo* tipos, int tamTipo, eMarca* marcas, int tamMarcas, int idTipo, eCliente* clientes, int tamCl)
{
    int todoOk=0;

    if(notebooks && tamNote>0)
    {
        for(int i=0; i<tamNote; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idTipo == idTipo)
            {
                listarUnaNotebook(notebooks, tamNote, tipos, tamTipo, marcas, tamMarcas, i, clientes, tamCl);
            }
        }


        todoOk = 1;
    }

    return todoOk;
}

int informeNotebookMarcaSeleccionado(eNotebook* notebooks, int tamNote, eTipo* tipos, int tamTipo, eMarca* marcas, int tamMarcas, int idMarca, eCliente* clientes, int tamCl)
{
    int todoOk=0;

    if(notebooks && tamNote>0)
    {
        for(int i=0; i<tamNote; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca == idMarca)
            {
                listarUnaNotebook(notebooks, tamNote, tipos, tamTipo, marcas, tamMarcas, i, clientes, tamCl);
            }
        }


        todoOk = 1;
    }

    return todoOk;
}

int ordenarNotebooksMarca(eNotebook* notebooks, int tam, eTipo* tipos, int tamTip, eMarca* marcas, int tamMarc)
{
    int todoOk = 0;
    char auxMarca[21];
    char auxTipo[21];
    eNotebook aux;

    if(notebooks && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!(notebooks[i].isEmpty))
            {
                buscarDescripcionMarca(marcas, tamMarc, notebooks[i].idMarca, auxMarca);
                buscarDescripcionTipo(tipos, tamTip, notebooks[i].idTipo, auxTipo);

                for(int j=i+1; j<tam; j++)
                {
                    if(!(notebooks[i].isEmpty) && !(notebooks[j].isEmpty))
                    {
                        if(notebooks[i].idMarca != notebooks[j].idMarca && (notebooks[i].idMarca > notebooks[j].idMarca))
                        {
                            aux = notebooks[i];
                            notebooks[i] = notebooks[j];
                            notebooks[j] = aux;
                        }
                    }

                }
            }

            todoOk = 1;
        }
    }
    return todoOk;
}

int informeNotebooksMasBaratas(eNotebook* notebooks, int tamNote, eTipo* tipos, int tamTipos, eMarca* marcas, int tamMarcas, eCliente* clientes, int tamCl)
{
    int todoOk = 0;
    float acumPrecios = 0;
    float promPrecios = 0;
    int cont = 0;

    if(notebooks && tamNote>0 && tipos && tamTipos>0 && marcas && tamMarcas>0)
    {
        for(int i=0; i<tamNote; i++)
        {
            if(!notebooks[i].isEmpty)
            {
                acumPrecios += notebooks[i].precio;
                cont++;
            }
        }
        if(cont != 0)
        {
            promPrecios = acumPrecios / cont;
        }

        printf("El precio promedio es $%.2f\n", promPrecios);
        for(int j=0; j<tamNote; j++)
        {
            if(!notebooks[j].isEmpty && notebooks[j].precio<promPrecios)
            {
                listarUnaNotebook(notebooks, tamNote, tipos, tamTipos, marcas, tamMarcas, j, clientes, tamCl);
            }
        }
    }

    return todoOk;
}

int contarNotebooksTipoYMarca(eNotebook* notebooks, int tamNote, int tipo, int idMarca)
{
    int todoOk = 0;
    int cont = 0;

    if(notebooks && tamNote>0 && tipo && idMarca>0)
    {
        for(int i=0; i<tamNote; i++)
        {
            if((!notebooks[i].isEmpty) && (notebooks[i].idTipo == tipo) && (notebooks[i].idMarca == idMarca))
            {
                cont++;
            }
        }
        printf("Las notebooks que coinciden con el tipo y marca son: %d", cont);
    }

    return todoOk;
}

int informeMarcaMasElegida(eNotebook* notebooks, int tamNote, eMarca* marcas, int tamMarcas)
{
    int todoOk = 0;
    int vecMarcas[tamMarcas];
    int bandera = 1;
    int mayorMarcaElegida;


    if(notebooks && tamNote>0)
    {
        for(int m=0; m<tamMarcas; m++)
        {
            vecMarcas[m] = 0;
        }

        for(int i=0; i<tamMarcas; i++)
        {
            for(int j=0; j<tamNote; j++)
            {
                if((!notebooks[j].isEmpty) && (notebooks[j].idMarca == marcas[i].id))
                {
                    vecMarcas[i]++;
                }
            }
        }

        for(int i=0; i<tamMarcas; i++)
        {
            if(bandera|| vecMarcas[i]>mayorMarcaElegida)
            {
                mayorMarcaElegida = vecMarcas[i];
                bandera=0;
            }
        }


        printf("La marca de notebooks mas elegida es:\n");
        for(int i=0; i<tamMarcas; i++)
        {
            if(vecMarcas[i] == mayorMarcaElegida)
            {
                printf("%s\n",marcas[i].desc);
            }
        }
    }
    return todoOk;
}

int informarTrabajosRealizados(eTrabajo* trabajos, int tamTrab, eNotebook* notebooks, int tamNote, int indice, eServicio* servicios, int tamServ, int idNotebook)
{
    int todoOk = 0;
    char desc[20];
    int bandera = 1;

    if(trabajos && tamTrab>0 && notebooks && tamNote>0 && indice>= 0 && servicios && tamServ>0 && idNotebook>=30000)
    {
        printf("Listado de trabajos: \n");
        for(int i=0; i<tamTrab; i++)
        {
            buscarDescripcionServicio(servicios, tamServ, trabajos[i].idServicio, desc);

            if(!notebooks[i].isEmpty && !trabajos[i].isEmpty && trabajos[i].idNotebook == idNotebook)
            {
                listarUnTrabajo(trabajos, tamTrab, servicios, tamServ, i);
                bandera = 0;
            }

        }
        if(bandera)
        {
            printf("No se realizaron trabajos a esa notebook");
        }

        todoOk = 1;
    }
    return todoOk;
}

int informarSumaDeImportes(eNotebook* notebooks, int tamNote, eTrabajo* trabajos, int tamTrab, eServicio* servicios, int tamServ, int id)
{
    int todoOk =-1;
    int indice;
    float acumuladorImportes=0;

    if(notebooks && tamNote>0 && id>=0)
    {
        buscarPosicionPorIdNotebook(notebooks, tamNote, id, &indice );

        for(int i=0; i<tamTrab; i++)
        {
            if(!notebooks[i].isEmpty && !trabajos[i].isEmpty && trabajos[i].idNotebook == id)
            {
                for(int j=0; j<tamServ; j++)
                {
                    if(servicios[j].id == trabajos[i].idServicio)
                    {
                        acumuladorImportes = servicios[j].precio + acumuladorImportes;
                    }
                }
            }
        }

        if(acumuladorImportes == 0)
        {
            printf("No se realizaron servicios a esta notebook");
        }
        else
        {
            printf("\nEl total de importes de esta notebook es de $%.2f\n", acumuladorImportes);
        }
        todoOk = 1;
    }
    return todoOk;
}

int informeNotebookServicioFecha(eNotebook* notebooks, int tamNote, eServicio* servicios, int tamServ, eTrabajo* trabajos, int tamTrab, int id)
{
    int todoOk = 0;
    int bandera = 1;
    char desc[20];

    if(notebooks && tamNote>0 && servicios && tamServ>0 && trabajos && tamTrab>0 && id>=0)
    {
        for(int i=0; i<tamTrab; i++)
        {
            buscarDescripcionServicio(servicios, tamServ, trabajos[i].idServicio, desc);

            if(!notebooks[i].isEmpty && !trabajos[i].isEmpty && trabajos[i].idServicio == id)
            {
                listarUnTrabajo(trabajos, tamTrab, servicios, tamServ, i);
                bandera = 0;
            }
        }
        if(bandera)
        {
            printf("No se realizaron trabajos a esa notebook");
        }
    }
    return todoOk;
}

int informarServiciosEnFecha(eNotebook* notebooks, int tamNote, eServicio* servicios, int tamServ, eTrabajo* trabajos, int tamTrab, eFecha fechaAux)
{
    int todoOk=0;
    int bandera = 1;
    char desc[20];

    if(notebooks && tamNote>0 && servicios && tamServ>0 && trabajos && tamTrab>0)
    {
        for(int i=0; i<tamNote; i++)
        {
            if(!notebooks[i].isEmpty)
            {
                if((trabajos[i].fecha.dia == fechaAux.dia) && (trabajos[i].fecha.mes == fechaAux.mes) && (trabajos[i].fecha.anio == fechaAux.anio))
                {
                    buscarDescripcionServicio(servicios, tamServ, trabajos[i].idServicio, desc);
                    bandera = 0;
                }
            }
        }
        if(bandera)
        {
            printf("No se realizaron trabajos en la fecha %d/%02d/%4d", fechaAux.dia, fechaAux.mes, fechaAux.anio);
        }

    todoOk = 1;
    }

    return todoOk;
}

int InformesGral(int opcion, eTipo* tipos, int tamTipos, eMarca* marcas, int tamMarcas, eNotebook* notebooks, int tamNote, eTrabajo* trabajos, int tamTrab, eServicio* servicios, int tamServ, int idNotebook, eCliente* clientes, int tamCl)
{
    int todoOk = 0;
    int tipo;
    int idMarca;
    int idRequerido;
    int indice;
    int idSer;
    char eleccion = 'n';
    char mensaje[50];
    eFecha fecha;

    if(opcion>0 && tipos && tamTipos>0 && marcas && tamMarcas>0 && notebooks && tamNote>0 && trabajos && tamTrab>0 && servicios && tamServ>0 && idNotebook>=30000 )
    {

        switch(opcion)
        {
        case 1:
            listarTipos(tipos, tamTipos);
            printf("Ingrese el id del tipo que quiera listar: \n");
            fflush(stdin);
            scanf("%d", &tipo);

            while(tipo < 5000 || tipo > 5003)
            {
                fflush(stdin);
                printf("Se ingreso un tipo erroneo, ingrese el tipo nuevamente: ");
                scanf("%d", &tipo);
            }
            informeNotebookTipoSeleccionado(notebooks, tamNote, tipos, tamTipos, marcas, tamMarcas, tipo, clientes, tamCl);
            break;
        case 2:
            listarMarcas(marcas, tamMarcas);
            printf("Ingrese el id de la marca que quiera listar: \n");
            fflush(stdin);
            scanf("%d", &idMarca);

            while(idMarca < 1000 || idMarca > 1003)
            {
                fflush(stdin);
                printf("Se ingreso un id de marca erroneo, ingrese el id de marca nuevamente: ");
                scanf("%d", &idMarca);
            }
            informeNotebookMarcaSeleccionado(notebooks, tamNote, tipos, tamTipos, marcas, tamMarcas, idMarca, clientes, tamCl);
            break;
        case 3:
            informeNotebooksMasBaratas(notebooks, tamNote, tipos, tamTipos, marcas, tamMarcas, clientes, tamCl);
            break;
        case 4:
            ordenarNotebooksMarca(notebooks, tamNote, tipos, tamTipos, marcas, tamMarcas);
            listarNotebooks(notebooks, tamNote, tipos, tamTipos, marcas, tamMarcas, clientes, tamCl);
            break;
        case 5:
            listarTipos(tipos, tamTipos);
            printf("Ingrese el id del tipo que quiera listar: \n");
            fflush(stdin);
            scanf("%d", &tipo);

            while(tipo < 5000 || tipo > 5003)
            {
                fflush(stdin);
                printf("Se ingreso un tipo erroneo, ingrese el tipo nuevamente: ");
                scanf("%d", &tipo);
            }

            listarMarcas(marcas, tamMarcas);
            printf("Ingrese el id de la marca que quiera listar: \n");
            fflush(stdin);
            scanf("%d", &idMarca);

            while(idMarca < 1000 || idMarca > 1003)
            {
                fflush(stdin);
                printf("Se ingreso un id de marca erroneo, ingrese el id de marca nuevamente: ");
                scanf("%d", &idMarca);
            }
            contarNotebooksTipoYMarca(notebooks, tamNote, tipo, idMarca);
            break;
        case 6:
            informeMarcaMasElegida(notebooks, tamNote, marcas, tamMarcas);
            break;
        case 7:
            listarNotebooks(notebooks, tamNote, tipos, tamTipos, marcas, tamMarcas, clientes, tamCl);
            printf("\nIngrese el id de la notebook para ver los trabajos que se le hicieron(ingrese 1 si desea salir): ");
            scanf("%d", &idRequerido);
            strcpy(mensaje, "Se ingreso un id no valido, reingrese el id: ");
            if(idRequerido == 1)
            {
                break;
            }
            validarInt(&idRequerido, 30000, idNotebook-1, mensaje, 3);
            buscarPosicionPorIdNotebook(notebooks, tamNote, idRequerido, &indice);

            informarTrabajosRealizados(trabajos, tamTrab, notebooks, tamNote, indice, servicios, tamServ, idRequerido);
            break;
        case 8:
            listarNotebooks(notebooks, tamNote, tipos, tamTipos, marcas, tamMarcas, clientes, tamCl);
            printf("\nIngrese el id de la notebook para ver los trabajos que se le hicieron(ingrese 1 si desea salir): ");
            scanf("%d", &idRequerido);
            strcpy(mensaje, "Se ingreso un id no valido, reingrese el id: ");
            if(idRequerido == 1)
            {
                break;
            }
            validarInt(&idRequerido, 30000, idNotebook-1, mensaje, 3);
            buscarPosicionPorIdNotebook(notebooks, tamNote, idRequerido, &indice);
            informarSumaDeImportes(notebooks, tamNote, trabajos, tamTrab, servicios, tamServ, idRequerido);

            break;
        case 9:
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
            informeNotebookServicioFecha(notebooks, tamNote, servicios, tamServ, trabajos, tamTrab, idSer);
            break;
        case 10:
            pedirYValidarFecha(&fecha.dia, &fecha.mes, &fecha.anio, 1800, 2022);
            informarServiciosEnFecha(notebooks, tamNote, servicios, tamServ, trabajos, tamTrab, fecha);
            break;
        case 11:
            printf("\nIngreso a \"SALIR\"");
            confirmaSalida(&eleccion);
            if(eleccion != 'S')
            {
                printf("La salida se ha cancelado\n");
            }
            break;
        }
        todoOk = 1;
    }
    return todoOk;
}


