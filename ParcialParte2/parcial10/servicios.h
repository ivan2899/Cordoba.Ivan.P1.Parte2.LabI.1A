#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char desc[26];
    float precio;
}eServicio;

#endif // SERVICIOS_H_INCLUDED

int listarServicios(eServicio* servicios, int tam);

int validarIdServicio(eServicio* servicios , int tam, int id);

int buscarDescripcionServicio(eServicio* servicios, int tam, int num, char* descServ);
int buscarIndiceServicio(eServicio* servicios , int tam, int id, int* pIndex);
