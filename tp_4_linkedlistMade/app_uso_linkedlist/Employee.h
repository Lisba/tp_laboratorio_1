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


/** \brief Libera el espacio ocupado en memoria.
 *
 * \param sEmployee* puntero a la variable a eliminar.
 * \return void
 *
 */
void employee_delete(sEmployee*);

/** \brief  Agrega un id a la estructura pasada por parametros
 *
 * \param this sEmployee*
 * \param id int
 * \return int
 *
 */
int employee_setId(sEmployee* this,int id);

/** \brief Obtiene el id del empleado pasado por parametros y lo guarda en una variable.
 *
 * \param this sEmployee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(sEmployee* this,int* id);

/** \brief Agrega el nombre a la estructura pasada por parametros.
 *
 * \param this sEmployee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(sEmployee* this,char* nombre);

/** \brief Obtiene el nombre del empleado pasado por parametros y lo guarda en una variable.
 *
 * \param this sEmployee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(sEmployee* this,char* nombre);

/** \brief Agrega las horas trabajadas a la estructura pasada por parametros.
 *
 * \param this sEmployee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(sEmployee* this,int horasTrabajadas);

/** \brief Recibe las horas trabajadas del empleado pasado por parametros y lo guarda en una variable.
 *
 * \param this sEmployee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(sEmployee* this,int* horasTrabajadas);

/** \brief Agrega el sueldo a la estructura pasada por parametros.
 *
 * \param this sEmployee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(sEmployee* this,int sueldo);

/** \brief Recibe el sueldo del empleado pasado por parametros y lo guarda en una variable.
 *
 * \param this sEmployee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(sEmployee* this,int* sueldo);

/** \brief Imprime un empleado en pantalla.
 *
 * \param Empleado a imprimir
 * \return
 *
 */
int printEmployee (sEmployee* employee);

/** \brief Imprime los empleados de la linkedlist.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int printEmployees(LinkedList* pArrayListEmployee);

/** \brief Valida un empleado.
 *
 * \param employee sEmployee*
 * \return int
 *
 */
int validateEmployee(sEmployee* employee);

/** \brief Funcion que determina el parametro de ordenamiento para la funcion ll_sort.
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int
 *
 */
int ordenarPorId(void* emp1, void* emp2);

/** \brief  Funcion que determina el parametro de ordenamiento para la funcion ll_sort.
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int
 *
 */
int ordenarPorNombre(void* emp1, void* emp2);

/** \brief Funcion que determina el parametro de ordenamiento para la funcion ll_sort.
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int
 *
 */
int ordenarPorHorasTrabajadas(void* emp1, void* emp2);

/** \brief Funcion que determina el parametro de ordenamiento para la funcion ll_sort.
 *
 * \param emp1 void*
 * \param emp2 void*
 * \return int
 *
 */
int ordenarPorSueldo(void* emp1, void* emp2);

#endif // employee_H_INCLUDED
