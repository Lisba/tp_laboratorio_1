#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "lisba_utn.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}sEmployee;

int menu();

sEmployee* employee_new();
sEmployee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(sEmployee* this,int id);
int employee_getId(sEmployee* this,int* id);

int employee_setNombre(sEmployee* this,char* nombre);
int employee_getNombre(sEmployee* this,char* nombre);

int employee_setHorasTrabajadas(sEmployee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(sEmployee* this,int* horasTrabajadas);

int employee_setSueldo(sEmployee* this,int sueldo);
int employee_getSueldo(sEmployee* this,int* sueldo);

int printEmployee (sEmployee* employee);
int validateEmployee(sEmployee* employee);

int IdAleatorio(void* this);

int arrayIniciado(LinkedList* linkedList);
int ordenarPorId(void* emp1, void* emp2);

#endif // employee_H_INCLUDED
