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

/** \brief Muestra un menu en pantalla.
 *
 * \return int retorna la opcion seleccionada.
 *
 */
int menu();

/** \brief Reserva espacio en memoria dinamica para un nuevo empleado.
 *
 * \return sEmployee* Retorna el puntero a la variable reservada en memoria dinamica.
 *
 */
sEmployee* employee_new();

/** \brief Toma los datos recibidos por parametro en formato string y los parsea y carga en la estructura en memoria dinamica.
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return sEmployee* Retorna el puntero a la variable reservada en memoria dinamica con los datos cargados.
 *
 */
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
int printEmployees(LinkedList* pArrayListEmployee);
int validateEmployee(sEmployee* employee);

int IdAleatorio(void* this);

int ordenarPorId(void* emp1, void* emp2);
int ordenarPorNombre(void* emp1, void* emp2);
int ordenarPorHorasTrabajadas(void* emp1, void* emp2);
int ordenarPorSueldo(void* emp1, void* emp2);

int eliminarLinkedListEntera(LinkedList* this);

#endif // employee_H_INCLUDED
