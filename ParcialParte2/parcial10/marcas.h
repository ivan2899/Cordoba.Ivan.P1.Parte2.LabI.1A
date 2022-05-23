#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED

typedef struct
{
    int id;
    char  desc[21];
}eMarca;

#endif // MARCAS_H_INCLUDED

int listarMarcas(eMarca* marcas, int tam);

int validarIdMarca(eMarca* marcas , int tam, int id);

int buscarDescripcionMarca(eMarca* marcas, int tam, int num, char* descMarc);
int buscarIndiceMarca(eMarca* marcas , int tam, int id, int* pIndex);
