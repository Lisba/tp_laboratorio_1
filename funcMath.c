#include <stdio.h>
#include <stdlib.h>
#include "funcMath.h"

/** \brief Solicita un número al usuario y devuelve dicho número.
 *
 * \param void No recibe parametros.
 * \return float El número ingresado por el usuario.
 *
 */
float getFloat(void)
{
    float number;
    int validation;

    do
    {
        fflush(stdin);
        printf("\n======================\n");
        printf("INGRESE UN OPERANDO: ");
        validation = scanf("%f", &number); //Validación para números, en caso de ingresar un caracter distinto a un número la variable validation valdrá 0.

        if(!validation) // Si la variable validation vale 0 se muestra el mensaje de error.
        {
            printf("\n%cERROR! DEBE INGRESAR UN N%cMERO.\n", 173, 233);
        }

    }while(!validation); // Si la variable validation es 0 se repite el ciclo hasta que validation sea distinta de 0, es decir, hasta ingresr un número.

    return number;
}

/** \brief Caclula la suma entre dos números.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la suma de ambos números.
 *
 */
float add(float number1, float number2)
{
    float result;

    result = number1 + number2; // Cálculo de la suma de ambos números recibidos como parámetros.

    return result;
}

/** \brief Caclula la resta entre dos números.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la resta de ambos números.
 *
 */
float subtract(float number1, float number2)
{
    float result;

    result = number1 - number2; // Cálculo de la resta del primer número menos el segundo número recibido como parámetro.

    return result;
}

/** \brief Caclula la división entre dos números.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la división entre ambos números.
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
        result = number1 / number2; // Cálculo de la división entre ambos números recibidos como parámetros.
    }

    return result;
}

/** \brief Caclula la multiplicación entre dos números.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la multiplicación entre ambos números.
 *
 */
float multiply(float number1, float number2)
{
    float result;

    result = number1 * number2; // Calculo del producto de ambos números recibidos como parámetros.

    return result;
}

/** \brief Caclula el factorial de un número.
 *
 * \param number float Operando a calcular.
 * \return long El factorial del número.
 *
 */
long int factorial(float number) //Recibe un flotante pero toma en cuenta solo con la parte entera del número y calcula su factorial.
{
    long int result=1;
    int i;

    for(i=number; i>=1; i--) //Iteración para calcular el producto del número recibido como parámetro por cada uno de sus números naturales inferiores hasta 1 (en forma decreciente).
    {
        result *= i;
    }

    return result;
}
