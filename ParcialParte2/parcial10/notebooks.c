#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "notebooks.h"
#include "tipos.h"
#include "marcas.h"
#include "general.h"
#include "cliente.h"

int altaNotebook(eNotebook* notebooks, int* pId, int tam, int i, eMarca* marcas, int tamMarcas, eTipo* tipos, int tamTipos, eCliente* clientes, int tamClientes, int* pIdCliente)
{
    int todoOk = 0;
    char auxModelo[21];
    int auxIdMarca;
    int auxIdTipo;
    float auxPrecio;
    char auxCadena[100];
    char sexo;

    if(notebooks && pId && tam>0)
    {
        notebooks[i].id = *pId;
        *pId = *pId + 1;

        printf("Si desea salir ingrese la \"s\" \n");
        printf("Ingrese el modelo de la notebook (maximo 20 caracteres): ");
        fflush(stdin);
        gets(auxModelo);

        while(!(validarGets(21,auxModelo)))
        {
            fflush(stdin);
            printf("Reingrese el modelo de la notebook de un maximo de 20 caracteres: ");
            gets(auxModelo);
        }
        strcpy(notebooks[i].modelo, auxModelo);


        printf("\nIngrese el numero correspondiente a la marca de la notebook\n");
        listarMarcas(marcas, tamMarcas);
        printf("\n\nIngrese opci%cn: ",162);
        scanf("%d", &auxIdMarca);
        auxIdMarca = toupper(auxIdMarca);
        while(auxIdMarca < 1000 || auxIdMarca > 1003 || isalpha(auxIdMarca))
        {
            fflush(stdin); //Limpio el buff por si se ingreso una letra
            printf("Reingrese una opci%cn valida (de 1000 a 1003): ", 162);
            scanf("%d", &auxIdMarca);
        }
        notebooks[i].idMarca = auxIdMarca;


        printf("\nIngrese el id del tipo de la notebook\n");
        listarTipos(tipos, tamTipos);
        printf("\n\nIngrese opcion: ");
        scanf("%d", &auxIdTipo);
        auxIdTipo = toupper(auxIdTipo);
        while(auxIdTipo < 5000 || auxIdTipo > 5003 || isalpha(auxIdTipo))
        {
            fflush(stdin); //Limpio el buff por si se ingreso una letra
            printf("Reingrese un id valido (de 5000 a 5003): ");
            scanf("%d", &auxIdTipo);
        }
        notebooks[i].idTipo = auxIdTipo;


        clientes[i].id = *pIdCliente;
        *pIdCliente = *pIdCliente + 1;
        printf("\nIngrese el nombre del cliente (maximo 50 caracteres): ");
        fflush(stdin);
        gets(auxCadena);
        while(!(validarGets(51, auxCadena)))
        {
            printf("Reingrese el nombre del cliente: ");
            gets(auxCadena);
        }

        strcpy(clientes[i].nombre, auxCadena);

        printf("\nIngrese el sexo del cliente (f o m): ");
        fflush(stdin);
        scanf("%c", &sexo);
        sexo = tolower(sexo);
        while(sexo != 'f' && sexo != 'm')
        {
        fflush(stdin);
        printf("\nReingrese el sexo del cliente (f o m): ");
        scanf("%c", &sexo);
        }
        clientes[i].sexo = sexo;


        printf("\nIngrese el precio de la notebook: $");
        scanf("%f", &auxPrecio);
        auxPrecio = toupper(auxPrecio);
        while(auxPrecio<0)
        {
            fflush(stdin); //Limpio el buff por si se ingreso una letra
            printf("\nReingrese el precio de la notebook: $");
            scanf("%f", &auxPrecio);
            auxPrecio = toupper(auxPrecio);
        }
        notebooks[i].precio = auxPrecio;

        notebooks[i].isEmpty = 0;
        todoOk = 1;
    }
    return todoOk;
}

int buscarPosicionLibreNotebook(eNotebook* notebooks, int tam, int* pIndex)
{
    int todoOk = 0;
    if(notebooks && pIndex && tam>0 )
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(notebooks[i].isEmpty)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}



int buscarPosicionPorIdNotebook(eNotebook* notebooks, int tam,int id, int* pIndex)
{
    int todoOk = 0;
    if(notebooks && tam > 0 && pIndex && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(notebooks[i].isEmpty == 0 && notebooks[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



int modificarNotebook(eNotebook* notebooks, int opcion, int tam, int i)
{
    int todoOk = 0;
    float auxPrecio;
    int auxIdTipo;

    if(notebooks && (opcion == 1 || opcion == 2) && tam>0)
    {
            if(opcion == 1)
            {
                printf("\nIngrese el nuevo precio de la notebook: $");
                scanf("%f", &auxPrecio);
                auxPrecio = toupper(auxPrecio);
                while(isalpha(auxPrecio)==1)
                {
                    fflush(stdin); //Limpio el buff por si se ingreso una letra
                    printf("\nReingrese el precio de la notebook: $");
                    scanf("%f", &auxPrecio);
                    auxPrecio = toupper(auxPrecio);
                }
                notebooks[i].precio = auxPrecio;
            }
            else
            {
                printf("\nIngrese el nuevo id del tipo de la notebook\n");
                printf("Id 5000 \"Gamer\"\nId 5001 \"Disenio\"\nId 5002 \"Normalita\"\nId 5003 \"Ultrabook\"\n\nIngrese opcion: ");
                scanf("%d", &auxIdTipo);
                auxIdTipo = toupper(auxIdTipo);
                while(auxIdTipo < 5000 || auxIdTipo > 5003 || isalpha(auxIdTipo))
                {
                    fflush(stdin); //Limpio el buff por si se ingreso una letra
                    printf("Reingrese un id valido (de 5000 a 5003): ");
                    scanf("%d", &auxIdTipo);
                }
                notebooks[i].idTipo = auxIdTipo;
            }
            todoOk = 1;
        }
    return todoOk;
}

int inicializarNotebooks(eNotebook* notebooks, int tam)
{
    int todoOk = 0;
    if(notebooks != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            notebooks[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int bajaNotebook(eNotebook* notebooks, int tam, eTipo* tipos, int tamTIpos, eMarca* marcas, int tamMarcas, eCliente* clientes, int tamCl)
{
    int todoOk = 0;
    int indice;
    int auxId;
    int id;
    char eleccion = 'n';

    if(notebooks != NULL && tam > 0)
    {

        printf("\nIngrese id de una notebook a dar de baja (ingrese 1 si desea salir): ");
        scanf("%d", &auxId);
        auxId = toupper(auxId);

        while(auxId<30000 || isalpha(auxId))
        {
            fflush(stdin);
            if(auxId == 1)
            {
                return todoOk;
            }
            printf("Reingrese un id v%clido: ", 160);
            scanf("%d", &auxId);
        }
        id = auxId;

        if(buscarPosicionPorIdNotebook(notebooks, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay Notebooks con ese id");
            }
            else
            {
                         printf("\nConfirma darle de baja a la notebook con id %d ? \n", id);
                         listarUnaNotebook(notebooks, tam, tipos, tamTIpos, marcas, tamMarcas, indice, clientes, tamCl);
                         printf("\n\n");
                         confirma(&eleccion, 3);
                if(eleccion == 'S')
                {
                notebooks[indice].isEmpty = 1;
                printf("Se dio de baja con %cxito\n\n", 130);
                }
                else
                {
                printf("Se cancelo la baja\n\n");
                }
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int listarNotebooks(eNotebook* notebooks, int tam, eTipo* tipos, int tamTip, eMarca* marcas, int tamMarc, eCliente* clientes, int tamCl)
{
    int todoOk = 0;

    if(notebooks && tam>0 && tipos && tamTip>0 && marcas && tamMarc>0)
    {


        printf(" ______________________________________________________________________________________________________________________________________________\n");
        printf("|                                                         **Listado de notebooks**                                                             |\n");
        printf("|----------------------------------------------------------------------------------------------------------------------------------------------|");
        for(int i=0; i<tam; i++)
        {
            listarUnaNotebook(notebooks, tam, tipos, tamTip, marcas, tamMarc, i, clientes, tamCl);
        }
        printf("\n|______________________________________________________________________________________________________________________________________________|\n");

        todoOk = 1;
    }
    return todoOk;
}

int listarUnaNotebook(eNotebook* notebooks, int tam, eTipo* tipos, int tamTip, eMarca* marcas, int tamMarc, int i, eCliente* clientes, int tamCl)
{
    int todoOk = 0;
    char auxMarca[21];
    char auxTipo[21];

    if(notebooks && tam>0 && tipos && tamTip>0 && marcas && tamMarc>0)
    {
        if(!(notebooks[i].isEmpty))
        {

            buscarDescripcionMarca(marcas, tamMarc, notebooks[i].idMarca, auxMarca);
            buscarDescripcionTipo(tipos, tamTip, notebooks[i].idTipo, auxTipo);

            printf("\n|  Id: %4d       |    Modelo: %20s   | Marca: %20s   |  Tipo: %20s   | Precio: $%10.2f   |", notebooks[i].id, notebooks[i].modelo, auxMarca, auxTipo, notebooks[i].precio);
            printf("\n|Datos del due%co Nombre: %50s    Sexo: %c     Id: %d                                          |",164, clientes[i].nombre , clientes[i].sexo, clientes[i].id);
            printf("\n|----------------------------------------------------------------------------------------------------------------------------------------------|");
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarNotebooksMarcaPrecio(eNotebook* notebooks, int tam, eTipo* tipos, int tamTip, eMarca* marcas, int tamMarc)
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
                for(int i=0; i<tam-1; i++)
                {
                    for(int j=i+1; j<tam; j++)
                    {
                        if(!(notebooks[i].isEmpty) && !(notebooks[j].isEmpty))
                        {
                            if((notebooks[i].idMarca == notebooks[j].idMarca &&(notebooks[i].precio < notebooks[j].precio)) ||
                                    (notebooks[i].idMarca != notebooks[j].idMarca && (notebooks[i].idMarca > notebooks[j].idMarca)))
                            {
                                aux = notebooks[i];
                                notebooks[i] = notebooks[j];
                                notebooks[j] = aux;
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

int ordenarNotebooksId(eNotebook* notebooks, int tam)
{
    int todoOk = 0;
    eNotebook aux;

    if(notebooks && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!(notebooks[i].isEmpty))
            {
                for(int i=0; i<tam-1; i++)
                {
                    for(int j=i+1; j<tam; j++)
                    {
                        if(!(notebooks[i].isEmpty) && !(notebooks[j].isEmpty))
                        {
                            if(notebooks[i].id > notebooks[j].id)
                            {
                                aux = notebooks[i];
                                notebooks[i] = notebooks[j];
                                notebooks[j] = aux;
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

int buscarPosicionesDisponiblesNotebooks(eNotebook* notebooks, int tamNot, int* pCont)
{
    int todoOk = 0;
    int cont = 0;

    if(notebooks && pCont && tamNot>0 )
    {
        for(int i=0; i<tamNot; i++)
        {
            if(notebooks[i].isEmpty)
            {
                cont++;
            }
        }
        todoOk = 1;
        *pCont = cont;
    }
    return todoOk;
}

int buscarPosicionUsadaNotebook(eNotebook* notebooks, int tamNot, int* pCont)
{
    int todoOk = 0;
    int cont = 0;

    if(notebooks && pCont && tamNot>0 )
    {
        for(int i=0; i<tamNot; i++)
        {
            if(!notebooks[i].isEmpty)
            {
                cont++;
            }
        }
        todoOk = 1;
        *pCont = cont;
    }
    return todoOk;
}

int harcodearNotebook(eNotebook* notebooks, int tamNot, int rep, int* id, int* pIdCliente)
{
    int todoOk = 0;
    int i;
    int contEspacio;

    if(notebooks && tamNot > 0 && rep <= tamNot)
    {

        buscarPosicionesDisponiblesNotebooks(notebooks, tamNot, &contEspacio);
        if(rep<=contEspacio)
        {
            for(int in=0; in<rep; in++)
            {
                if(buscarPosicionLibreNotebook(notebooks, tamNot, &i))
                {
                    if(in==8 || !(in%9))
                    {
                        notebooks[i].id = *(id);
                        *id = *(id)+1;
                        notebooks[i].idCliente = *(pIdCliente);
                        *pIdCliente = *(pIdCliente) +1;
                        strcpy(notebooks[i].modelo, "A3215XT");
                        notebooks[i].idMarca = 1000;
                        notebooks[i].idTipo = 5000;
                        notebooks[i].precio = 125036;
                        notebooks[i].isEmpty = 0;
                    }
                    else if(in==7 || !(in%8))
                    {
                        notebooks[i].id = *(id);
                        *id = *(id)+1;
                        notebooks[i].idCliente = *(pIdCliente);
                        *pIdCliente = *(pIdCliente) +1;
                        strcpy(notebooks[i].modelo, "C90315XMK");
                        notebooks[i].idMarca = 1002;
                        notebooks[i].idTipo = 5003;
                        notebooks[i].precio = 241368.19;
                        notebooks[i].isEmpty = 0;
                    }
                    else if(in==6 || !(in%7))
                    {
                        notebooks[i].id = *(id);
                        *id = *(id)+1;
                        notebooks[i].idCliente = *(pIdCliente);
                        *pIdCliente = *(pIdCliente) +1;
                        strcpy(notebooks[i].modelo, "CASAd365");
                        notebooks[i].idMarca = 1001;
                        notebooks[i].idTipo = 5001;
                        notebooks[i].precio = 79850;
                        notebooks[i].isEmpty = 0;
                    }
                    else if(in==5 || !(in%6))
                    {
                        notebooks[i].id = *(id);
                        *id = *(id)+1;
                        notebooks[i].idCliente = *(pIdCliente);
                        *pIdCliente = *(pIdCliente) +1;
                        strcpy(notebooks[i].modelo, "LoaAP58998");
                        notebooks[i].idMarca = 1003;
                        notebooks[i].idTipo = 5002;
                        notebooks[i].precio = 245000;
                        notebooks[i].isEmpty = 0;
                    }
                    else if(in==4 || !(in%5))
                    {
                        notebooks[i].id = *(id);
                        *id = *(id)+1;
                        notebooks[i].idCliente = *(pIdCliente);
                        *pIdCliente = *(pIdCliente) +1;
                        strcpy(notebooks[i].modelo, "Z789AdXT");
                        notebooks[i].idMarca = 1001;
                        notebooks[i].idTipo = 5000;
                        notebooks[i].precio = 200000;
                        notebooks[i].isEmpty = 0;
                    }
                    else if(in==3 || !(in%4))
                    {
                        notebooks[i].id = *(id);
                        *id = *(id)+1;
                        notebooks[i].idCliente = *(pIdCliente);
                        *pIdCliente = *(pIdCliente) +1;
                        strcpy(notebooks[i].modelo, "OLPOLda658");
                        notebooks[i].idMarca = 1000;
                        notebooks[i].idTipo = 5003;
                        notebooks[i].precio = 198560.50;
                        notebooks[i].isEmpty = 0;
                    }
                    else if(in==2 || !(in%3))
                    {
                        notebooks[i].id = *(id);
                        *id = *(id)+1;
                        notebooks[i].idCliente = *(pIdCliente);
                        *pIdCliente = *(pIdCliente) +1;
                        strcpy(notebooks[i].modelo, "InspirionA158");
                        notebooks[i].idMarca = 1002;
                        notebooks[i].idTipo = 5001;
                        notebooks[i].precio = 113000;
                        notebooks[i].isEmpty = 0;
                    }
                    else if(in==0 || !(in%2))
                    {
                        notebooks[i].id = *(id);
                        *id = *(id)+1;
                        notebooks[i].idCliente = *(pIdCliente);
                        *pIdCliente = *(pIdCliente) +1;
                        strcpy(notebooks[i].modelo, "XT5123A");
                        notebooks[i].idMarca = 1000;
                        notebooks[i].idTipo = 5002;
                        notebooks[i].precio = 113113;
                        notebooks[i].isEmpty = 0;
                    }
                    else if(in==1 || (in%2))
                    {
                        notebooks[i].id = *(id);
                        *id = *(id)+1;
                        notebooks[i].idCliente = *(pIdCliente);
                        *pIdCliente = *(pIdCliente) +1;
                        strcpy(notebooks[i].modelo, "158AXT125");
                        notebooks[i].idMarca = 1002;
                        notebooks[i].idTipo = 5000;
                        notebooks[i].precio = 280000;
                        notebooks[i].isEmpty = 0;
                    }
                    todoOk = 1;
                }
            }
        }
    }
    return todoOk;
}
