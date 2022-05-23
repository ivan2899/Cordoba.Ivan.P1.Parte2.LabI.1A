#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "fecha.h"

int pedirYValidarFecha(int* dia, int* mes, int* anio, int anioMin, int anioMax)
{
    int todoOk = 0;
    int auxDia;
    int auxMes;
    int auxAnio;
    int anioBisiesto;
    int diasFebrero;
    int flag;

    if(dia && mes && anio && anioMin > 0 && anioMax >= anioMin)
    {
        system("cls");
        printf("Ingres%c a la opci%cn para \"ingresar fecha\"  ", 162, 162);
        printf("\n   Introduzca el d%ca: ", 161);
        scanf("%d", &auxDia );
        while(auxDia < 1 || auxDia > 31)
        {
            fflush(stdin);
            printf("Reingrese el d%ca (de 1 a 31): ", 161);
            scanf("%d", &auxDia);
        }

        printf("\n   Introduzca el mes: " );
        scanf("%d", &auxMes );
        while(auxMes < 1 || auxMes > 12)
        {
            fflush(stdin);
            printf("Reingrese el mes (de 1 a 12): ");
            scanf("%d", &auxMes);
        }

        printf( "\n   Introduzca a%co: ", 164 );
        scanf( "%d", &auxAnio );
        while(auxAnio < anioMin || auxAnio > anioMax)
        {
            fflush(stdin);
            printf("Reingrese un a%co valido (mayor o igual a %d y menor o igual a %d): ", 164, anioMin, anioMax);
            scanf("%d", &auxAnio);
        }

        switch(auxMes)
        {
        case 2:
            anioBisiesto = auxAnio % 4; // Si es 0 quiere decir que es un año bisiesto
            if(anioBisiesto == 0)
            {
                diasFebrero = 29;
            }
            else
            {
                diasFebrero = 28;
            }
            flag = 0;
            while(auxDia < 1 || auxDia > diasFebrero)
            {
                if(!flag)
                {
                    printf("\n%d no es un a%co bisiesto, por lo que Febrero no puede tener m%cs de %d dias \n", auxAnio, 164, 160, diasFebrero);
                    flag = 1;
                }
                fflush(stdin);
                printf("Reingrese el d%ca (de 1 a %d): ", 161, diasFebrero);
                scanf("%d", &auxDia);
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            flag = 0;
            while(auxDia < 1 || auxDia > 30)
            {
                if(!flag)
                {
                    printf("No se pueden ingresar mas de 30 dias para el mes elegido, reingrese el dia (de 1 a 30): ");
                    flag = 1;
                }
                fflush(stdin);
                printf("Reingrese el d%ca (de 1 a 30): ", 161);
                scanf("%d", &auxDia);
            }
            break;
        }
        *dia = auxDia;
        *mes = auxMes;
        *anio = auxAnio;

        todoOk = 1;
    }
    return todoOk;
}
