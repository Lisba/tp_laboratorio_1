#include "lisba_utn.h"

 /** \brief  Pide un numero entero al usuario y valida y retorna el numero entero ingresado.
 *
 * \param input int* Variable puntero origen-destino.
 * \param message[] char mensaje a mostrar al usuario.
 * \param eMessage[] char mensaje a mostrar en caso de ingresar dato invalido.
 * \param lowLimit int rango limite inferior.
 * \param highLimit int rango limite superior.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 */
int getInt(int* input, char message[], char eMessage[], int lowLimit, int highLimit)
{
    int able=0;
    char auxNumber[10];
    int numberReturn;
    int counterDash=0;
    int isInt;

    do
    {
        isInt = 1;
        counterDash = 0;

        printf("%s", message);
        fflush(stdin);
        scanf("%s", auxNumber);

        int i=0;
        while(auxNumber[i] != '\0')
        {
            if((auxNumber[i] < '0' || auxNumber[i] > '9') && (auxNumber[i] != '-'))
            {
               isInt = 0;
            }

            if(auxNumber[i] == '-')
            {
                if(i != 0)
                {
                    isInt = 0;
                }
            }

            if(auxNumber[i] == '-')
            {
                counterDash++;
            }

            i++;
        }

        if(counterDash > 1)
        {
            isInt = 0;
        }

        numberReturn = atoi(auxNumber);

        if((numberReturn < lowLimit) || (numberReturn > highLimit))
         {
             isInt = 0;
         }

        if(!isInt)
        {
            printf(eMessage);
        }

    } while (!isInt);

    *input = numberReturn;

    able = 1;

    return able;
}

int getLong(long* input, char message[], char eMessage[], int lowLimit, int highLimit)
{
    int able=0;
    char auxNumber[10];
    long numberReturn;
    int counterDash=0;
    int isInt;

    do
    {
        isInt = 1;
        counterDash = 0;

        printf("%s", message);
        fflush(stdin);
        scanf("%s", auxNumber);

        int i=0;
        while(auxNumber[i] != '\0')
        {
            if((auxNumber[i] < '0' || auxNumber[i] > '9') && (auxNumber[i] != '-'))
            {
               isInt = 0;
            }

            if(auxNumber[i] == '-')
            {
                if(i != 0)
                {
                    isInt = 0;
                }
            }

            if(auxNumber[i] == '-')
            {
                counterDash++;
            }

            i++;
        }

        if(counterDash > 1)
        {
            isInt = 0;
        }

        numberReturn = atol(auxNumber);

        if((numberReturn < lowLimit) || (numberReturn > highLimit))
         {
             isInt = 0;
         }

        if(!isInt)
        {
            printf(eMessage);
        }

    } while (!isInt);

    *input = numberReturn;

    able = 1;

    return able;
}

/** \brief  Pide un numero flotante al usuario y valida y retorna el numero flotante ingresado.
 *
 * \param input float* Variable puntero origen-destino.
 * \param message[] char mensaje a mostrar al usuario.
 * \param eMessage[] char mensaje a mostrar en caso de ingresar dato invalido.
 * \param lowLimit float rango limite inferior.
 * \param highLimit float rango limite superior.
 * \return int retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int getFloat(float* input, char message[], char eMessage[], float lowLimit, float highLimit)
{
    int able = 0;
    char auxChar[100];
    float floatReturn;
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
            if((auxChar[i] < '0' || auxChar[i] > '9') && (auxChar[i] != '.'))
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

        floatReturn = atof(auxChar);

        if((floatReturn < lowLimit) || (floatReturn > highLimit))
        {
            isFloat = 0;
        }

        if(!isFloat)
        {
            printf("%s", eMessage);
        }

    } while (!isFloat);

    *input = floatReturn;

    return able;
}

/** \brief Pide un caracter al usuario, valida y retorna el caracter ingresado.
 *
 * \param input char* Variable puntero origen-destino.
 * \param message[] char mensaje a mostrar al usuario.
 * \param eMessage[] char mensaje a mostrar en caso de ingresar dato invalido.
 * \param lowLimit char rango limite inferior.
 * \param highLimit char rango limite superior.
 * \return int retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int getChar(char* input, char message[], char eMessage[], char lowLimit, char highLimit)
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

/** \brief Pide una cadena de caracteres al usuario, valida y retorna la cadena de caracteres ingresada.
 *
 * \param input char* Variable puntero origen-destino.
 * \param message[] char mensaje a mostrar al usuario.
 * \param eMessage[] char mensaje a mostrar en caso de ingresar dato invalido.
 * \param lowLimit int rango limite inferior de caracteres.
 * \param highLimit int rango limite superior de caracteres.
 * \return int retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int getString(char* input, char message[], char eMessage[], int lowLimit, int highLimit)
{
    int able = 0;
    char aux[highLimit];

    do
    {
        printf("%s", message);
        fflush(stdin);
        gets(aux);

        if( (strlen(aux) < (lowLimit)) || (strlen(aux) > (highLimit)) )
        {
            printf("%s", eMessage);
        }

    } while ( (strlen(aux) < (lowLimit)) || (strlen(aux) > (highLimit)) );

    strcpy(input, aux);

    return able;
}

int isNumeric(char* string)
{
    int isNum = 0;
    int i = 0;

    if(string != NULL)
    {
        while(string[i] != '\0')
        {
            if(string[i] < '0' || string[i] > '9')
            {
                break;
            }
            i++;
        }

        if(string[i] == '\0')
        {
            isNum = 1;
        }
    }

    return isNum;
}

int isAlphabetic(char* string)
{
    int isAlphabetic = 0;
    int i = 0;

    if(string != NULL)
    {
        while(string[i] != '\0')
        {
            if( (string[i] < 'A' || string[i] > 'Z') && (string[i] < 'a' || string[i] > 'z') )
            {
                break;
            }
            i++;
        }

        if(string[i] == '\0')
        {
            isAlphabetic = 1;
        }
    }

    return isAlphabetic;
}

int getName(char* input, char message[], char eMessage[], int lowLimit, int highLimit)
{
    int able = 0;
    char aux[highLimit];

    do
    {
        printf("%s", message);
        fflush(stdin);
        scanf("%s", aux);

        if( !isAlphabetic(aux) )
        {
            printf("%s", eMessage);
        }
        else if( (strlen(aux) < (lowLimit)) || (strlen(aux) > (highLimit)) )
        {
            printf("%s", eMessage);
        }

    } while ( !isAlphabetic(aux) || strlen(aux) < (lowLimit) || strlen(aux) > (highLimit) );

    strcpy(input, aux);

    return able;
}

/** \brief Pide un telefono al usuario, valida y retorna el telefono ingresado.
 *
 * \param input char* Variable puntero origen-destino.
 * \param message[] char Mensaje a mostrar al usuario.
 * \param eMessage[] char Mensaje a mostrar en caso de ingresar dato invalido.
 * \param lowLimit int Rango limite inferior.
 * \param highLimit int Ranfo limite superior.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int getPhone(char* input, char message[], char eMessage[], int lowLimit, int highLimit)
{
    int able=0;
    char auxNumber[21];
    int counterDash;
    int counterSpace;
    int isPhone;

    do
    {
        isPhone = 1;
        counterDash = 0;
        counterSpace = 0;

        printf("%s", message);
        fflush(stdin);
        scanf("%[^\n]", auxNumber);

        int i=0;
        while(auxNumber[i] != '\0')
        {
            if((auxNumber[i] < '0' || auxNumber[i] > '9') && (auxNumber[i] != '-') && (auxNumber[i] != ' '))
            {
               isPhone = 0;
            }

            if(auxNumber[i] == ' ')
            {
                counterSpace++;
            }

            if(auxNumber[i] == '-')
            {
                counterDash++;
            }

            i++;
        }

        if(counterDash > 2)
        {
            isPhone = 0;
        }

        if(counterSpace > 2)
        {
            isPhone = 0;
        }

        if((strlen(auxNumber) < lowLimit) || (strlen(auxNumber) > highLimit))
         {
             isPhone = 0;
         }

        if(!isPhone)
        {
            printf(eMessage);
        }

    } while (!isPhone);

    strcpy(input, auxNumber);

    able = 1;

    return able;
}

/** \brief  Pide, valida y retorna un numero de DNI.
 *
 * \param input char* Variable puntero origen-destino.
 * \param message[] char mensaje a mostrar al usuario.
 * \param eMessage[] char mensaje a mostrar en caso de ingresar dato invalido.
 * \return int retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int getDni(char* input, char message[], char eMessage[])
{
    int able = 0;
    char aux[11];
    int i=0;

    do
    {
        printf("%s", message);
        fflush(stdin);
        gets(aux);

        while(aux[i] != '\0')
        {
            if( (strlen(aux) < (6) || strlen(aux) > (10)) && (aux[i] < '0' || aux[i] > '9') )
            {
                printf("%s", eMessage);
            }

            i++;
        }

    } while ( (strlen(aux) < (6)) || (strlen(aux) > (10)) );

    strcpy(input, aux);
    able = 1;

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

/** \brief Pide un nombre y un apellido al usuario y lo muestra concatenado separado por una coma un un espacio.
 *
 * \param nameLastName[] char Vector donde se guardar� el nombre y apellido.
 * \return void
 *
 */
void getNameLastName(char nameLastName[])
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

    strcpy(nameLastName, nombre);
    strcat(nameLastName, ", ");
    strcat(nameLastName, apellido);
}

//----------------------------------------------------------------------------------------------------------
//*******************************Paralells Vectors***************************************
//----------------------------------------------------------------------------------------------------------

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
