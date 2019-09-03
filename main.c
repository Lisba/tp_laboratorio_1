#include <stdio.h>
#include <stdlib.h>
#include "funcMath.h"

int main()
{

    float number1 = 0.00;
    float number2 = 0.00;
    float resultAdd;
    float resultSubtract;
    float resultDivide;
    float resultMultiply;
    float resultFactorialA;
    float resultFactorialB;
    char option;
    char option2;


    do
    {
        printf("\n================================\n");
        printf(" %cBIENVENIDO A SU CALCULADORA!\n", 173);
        printf("================================\n\n");

        printf("SELECCIONE UNA OPCI%cN DEL MEN%c:\n\n", 224, 233);

        printf("1) AGREGAR PRIMER OPERANDO (A = %.2f)\n", number1);
        printf("2) AGREGAR SEGUNDO OPERANDO (B = %.2f)\n", number2);
        printf("3) CALCULAR TODAS LAS OPERACIONES\n");
        printf("4) MOSTRAR RESULTADOS\n");
        printf("5) SALIR\n");
        fflush(stdin);
        printf("\nINGRESE UNA OPCI%cN: ", 224);
        scanf("%c", &option);

        switch(option)
        {
        case '1':

            system("cls");
            number1 = getNumber();
            break;

        case '2':

            system("cls");
            number2 = getNumber();
            break;

        case '3':

            do
            {
                system("cls");

                printf("\n===================================================\n");
                printf("  SELECCIONE LAS OPERACIONES QUE DESEA EJECUTAR\n");
                printf("===================================================\n\n");

                printf("SELECCIONE UNA POR UNA LAS OPCIONES QUE DESEA DEL MEN%c:\n\n", 233);

                printf("a) SUMAR (A+B)\n");
                printf("b) RESTAR (A-B)\n");
                printf("c) DIVIDIR (A/B)\n");
                printf("d) MULTIPLICAR (A*B)\n");
                printf("e) FACTORIAL (A!) y (B!)\n");
                printf("f) SALIR\n\n");

                printf("SELECCIONE UNA OPCI%cN: ", 224);
                fflush(stdin);
                scanf("%c", &option2);

                switch(option2)
                {
                    case 'a':
                        resultAdd = add(number1, number2);
                        break;
                    case 'b':
                        resultSubtract = subtract(number1, number2);
                        break;
                    case 'c':
                        resultDivide = divide(number1, number2);
                        break;
                    case 'd':
                        resultMultiply = multiply(number1, number2);
                        break;
                    case 'e':
                        resultFactorialA = factorial(number1);
                        resultFactorialB = factorial(number2);
                        break;
                }

            }while(option2!='f');
            break;

        case '4':
            printf("\n===================================================\n\n");
            printf("a) El resultado de A+B es: %f\n", resultAdd);
            printf("b) El resultado de A-B es: %f\n", resultSubtract);
            printf("c) El resultado de A/B es: %f\n", resultDivide);
            printf("d) El resultado de A*B es: %f\n", resultMultiply);
            printf("e) El resultado del 1er operando es: %f y el factorial del 2do operando es: %f\n", resultFactorialA, resultFactorialB);
            printf("\n===================================================\n\n");
            break;
        }

        system("pause");

        system("cls");

    }while(option!='5');

    return 0;
}
