#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lisba_utn.h"

int getInt(int* input, char message[], char eMessage[], int lowLimit, int highLimit)
{
    int able = 0;
    int aux;
    int validation;

    do
    {
        printf("%s", message);
        fflush(stdin);
        validation = scanf("%d", &aux);

        if(!validation || aux < lowLimit || aux > highLimit)
        {
            printf("%s", eMessage);
        }

    } while (!validation || aux < lowLimit || aux > highLimit);

    *input = aux;

    return able;
}

int getFloat(float* input, char message[], char eMessage[], float lowLimit, float highLimit)
{
    int able = 0;
    char auxChar[100];
    float aux;
    int isFloat;
    int dotCounter;

    do
    {
        dotCounter = 0;

        printf("%s", message);
        fflush(stdin);
        scanf("%s", auxChar);

        int i=0;
        while(auxChar[i] != '\0')
        {
            if(auxChar[i] < '0' && auxChar[i] > '9' && auxChar[i] != '.')
            {
                isFloat = 0;
            }

            if(auxChar[i] == '.')
            {
                dotCounter++;
            }

            i++;
        }

        if(dotCounter == 1)
        {
            isFloat = 1;
        }
        else
        {
            isFloat = 0;
        }

        if(!isFloat)
        {
            printf("%s", eMessage);
        }

    } while (!isFloat);

        aux = atof(auxChar);

        *input = aux;

    return able;
}

char getChar(char* input, char message[], char eMessage[], char lowLimit, char highLimit)
{
    int able = 0;
    char aux;
    int validation;

    do
    {
        printf("%s", message);
        fflush(stdin);
        validation = scanf("%c", &aux);

        if(!validation || aux < lowLimit || aux > highLimit)
        {
            printf("%s", eMessage);
        }

    } while (!validation || aux < lowLimit || aux > highLimit);

    *input = aux;

    return able;
}

char getString(char input[], char message[], char eMessage[], int lowLimit, int highLimit)
{
    int able = 0;
    char aux[highLimit];

    do
    {
        printf("%s", message);
        fflush(stdin);
        fgets(aux, highLimit, stdin);
        aux[strlen(aux)-1] = '\0';

        if(strlen(aux) < (lowLimit+1))
        {
            printf("%s", eMessage);
        }

    } while (strlen(aux) < (lowLimit+1));

    strcpy(input, aux);

    return able;
}

/** \brief Caclula la suma entre dos n�meros.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la suma de ambos n�meros.
 *
 */
float add(float number1, float number2)
{
    float result;

    result = number1 + number2; // C�lculo de la suma de ambos n�meros recibidos como par�metros.

    return result;
}

/** \brief Caclula la resta entre dos n�meros.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la resta de ambos n�meros.
 *
 */
float subtract(float number1, float number2)
{
    float result;

    result = number1 - number2; // C�lculo de la resta del primer n�mero menos el segundo n�mero recibido como par�metro.

    return result;
}

/** \brief Caclula la divisi�n entre dos n�meros.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la divisi�n entre ambos n�meros.
 *
 */
float divide(float number1, float number2)
{
    float result;

    if(number2 == 0)
    {
        result = 0.00;
    }else
    {
        result = number1 / number2; // C�lculo de la divisi�n entre ambos n�meros recibidos como par�metros.
    }

    return result;
}

/** \brief Caclula la multiplicaci�n entre dos n�meros.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la multiplicaci�n entre ambos n�meros.
 *
 */
float multiply(float number1, float number2)
{
    float result;

    result = number1 * number2; // Calculo del producto de ambos n�meros recibidos como par�metros.

    return result;
}

/** \brief Caclula el factorial de un n�mero.
 *
 * \param number float Operando a calcular.
 * \return long El factorial del n�mero.
 *
 */
long int factorial(float number) //Recibe un flotante pero toma en cuenta solo la parte entera del n�mero y calcula su factorial.
{
    long int result=1;
    int i;

    for(i=number; i>=1; i--) //Iteraci�n para calcular el producto del n�mero recibido como par�metro por cada uno de sus n�meros naturales inferiores hasta 1 (en forma decreciente).
    {
        result *= i;
    }

    return result;
}

void pedirAlumno(int legajo[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo[i]);

        printf("Ingrese la edad: ");
        scanf("%d", &edad[i]);

        printf("Ingrese el sexo: ");
        fflush(stdin);
        scanf("%c", &sexo[i]);

        printf("Ingrese la nota1: ");
        scanf("%d", &nota1[i]);

        printf("Ingrese la nota2: ");
        scanf("%d", &nota2[i]);

        promedio[i] = (float) (nota1[i] + nota2[i]) / 2;
    }
}

void mostrarUnAlumno(int legajo, int edad, char sexo, int nota1, int nota2, float promedio)
{
     printf("%d\t%d\t%c\t%d\t%d\t%.3f\n", legajo, edad, sexo, nota1, nota2, promedio);
}

void mostrarAlumnos(int legajo[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam)
{
    printf("\nleg:\tedad:\tsexo:\tn1:\tn2:\tpromedio:\n\n");
    for(int i=0; i<tam; i++)
    {
        mostrarUnAlumno(legajo[i], edad[i], sexo[i], nota1[i], nota2[i], promedio[i]);
    }

}

void ordenarAlumnos(int legajo[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam)
{

    int auxInt;
    char auxChar;
    float auxFloat;
    int swap = 0;

    for(int i=0; i<tam-1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if(sexo[i] > sexo[j])
            {
                swap = 1;

            } else if (sexo[i] == sexo[j] && legajo[i] > legajo[j])
            {
                swap = 1;
            }

            if (swap == 1)
            {

                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                auxInt = edad[i];
                edad[i] = edad[j];
                edad[j] = auxInt;

                auxChar = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = auxChar;

                auxInt = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxInt;

                auxInt = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxInt;

                auxFloat = promedio[i];
                promedio[i] = promedio[j];
                promedio[j] = auxFloat;

                swap = 0;
            }
        }
    }
}

/** \brief
 *
 * \param nombreApellido[] char Vector donde se guardar� el nombre y apellido.
 * \return void No retorna ya que recibe la variable por referencia (modifica la original).
 *
 */
void getNombreApellido(char nombreApellido[])
{
    char nombre[23];
    char apellido[11];
    char aux[50];

    do
    {
        printf("Ingrese nombre: ");
        gets(aux);

        if(strlen(aux) > 10)
        {
            printf("ERROR. Ingrese un nombre de 10 caracteres o menos: ");
            gets(aux);
        }
    } while (strlen(aux) > 10);

    strcpy(nombre, aux);

    do
    {
        printf("Ingrese apellido: ");
        gets(aux);

        if(strlen(aux) > 10)
        {
            printf("ERROR! Ingrese un apellido de 10 caracteres o menos: ");
            gets(aux);
        }
    } while (strlen(aux) > 10);

    strcpy(apellido, aux);

    strcpy(nombreApellido, nombre);
    strcat(nombreApellido, ", ");
    strcat(nombreApellido, apellido);
}
