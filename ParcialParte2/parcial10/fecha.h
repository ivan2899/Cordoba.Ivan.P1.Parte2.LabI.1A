#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED

int pedirYValidarFecha(int* dia, int* mes, int* anio, int anioMin, int anioMax);
