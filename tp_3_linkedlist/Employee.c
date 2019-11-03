#include "Employee.h"
#include "LinkedList.h"

int menu(void)
{
    int opcion;

    system("cls");
    printf("****** ABM Empleados *******\n\n");
    printf("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2-Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3-Alta de empleado.\n");
    printf("4-Modificar datos de empleado.\n");
    printf("5-Baja de empleado.\n");
    printf("6-Listar empleados.\n");
    printf("7-Ordenar empleados.\n");
    printf("8-Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9-Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10-Salir.\n\n");
    getInt(&opcion, "Ingrese opcion: ", "Opcion invalida. ", 1, 10);

    return opcion;
}

sEmployee* employee_new(void)
{
    sEmployee* this = (sEmployee*) malloc(sizeof(sEmployee));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, " ");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}

sEmployee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    sEmployee* this;

        if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
        {
            this = employee_new();

            if(this != NULL)
            {
                if( ( !employee_setId(this, atoi(idStr)) ) || ( !employee_setNombre(this, nombreStr) ) || ( !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) ) || ( !employee_setSueldo(this, atoi(sueldoStr)) ) )
                {
                        free(this);
                        this = NULL;
                }
            }
        }

    return this;
}

void employee_delete(sEmployee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(sEmployee* this, int id)
{
    int able = 0;

    if(this != NULL && id > 0)
    {
        this->id = id;
        able = 1;
    }

    return able;
}

int employee_getId(sEmployee* this, int* id)
{
    int able = 0;

    if(this != NULL && id > 0)
    {
        *id = this->id;
        able = 1;
    }

    return able;
}

int employee_setNombre(sEmployee* this, char* nombre)
{
    int able = 0;

    if(this != NULL && (nombre != NULL && strlen(nombre)>0))
    {
        strcpy(this->nombre, nombre);
        able = 1;
    }

    return able;
}

int employee_getNombre(sEmployee* this, char* nombre)
{
    int able = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        able = 1;
    }

    return able;
}

int employee_setHorasTrabajadas(sEmployee* this, int horasTrabajadas)
{
    int able = 0;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        able = 1;
    }

    return able;
}

int employee_getHorasTrabajadas(sEmployee* this, int* horasTrabajadas)
{
    int able = 0;

    if(this != NULL && horasTrabajadas > 0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        able = 1;
    }

    return able;
}

int employee_setSueldo(sEmployee* this, int sueldo)
{
    int able = 0;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        able = 1;
    }

    return able;
}

int employee_getSueldo(sEmployee* this, int* sueldo)
{
    int able = 0;

    if(this != NULL && sueldo > 0)
    {
        *sueldo = this->sueldo;
        able = 1;
    }

    return able;
}

int printEmployee(sEmployee* this)
{
    int able = 0;

    printf("%d %16s %6d %6d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
    able = 1;

    return able;
}

int validateEmployee(sEmployee* this)
{
    int isUsed = 0;
    int id;
    int horas;
    int sueldo;
    char nombre[128];

    if(this != NULL)
    {
        employee_getId(this, &id);
        employee_getHorasTrabajadas(this, &horas);
        employee_getSueldo(this, &sueldo);
        employee_getNombre(this, nombre);

        if(id > 0 && horas > 0 &&  nombre != NULL && sueldo > 0)
        {
            isUsed = 1;
        }
    }

    return isUsed;
}

int IdAleatorio(void* this)
{
    int value = -1;

    value = ll_len(this) + 1;

    return value;
}

int arrayIniciado(LinkedList* linkedList)
{
    int iniciado = 0;

    if( ll_len(linkedList) > 0 )
    {
        iniciado = 1;
    }

    return iniciado;
}
