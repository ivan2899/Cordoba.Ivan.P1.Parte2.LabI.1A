#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char desc[21];
}eTipo;

#endif // TIPOS_H_INCLUDED

int listarTipos(eTipo* tipos, int tam);

int validarIdTipo(eTipo* tipos , int tam, int id);

int buscarDescripcionTipo(eTipo* tipos, int tam, int num, char* descTip);
int buscarIndiceTipo(eTipo* tipos , int tam, int id, int* pIndex);
