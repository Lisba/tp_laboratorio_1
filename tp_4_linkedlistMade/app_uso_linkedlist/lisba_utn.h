#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(int* input, char message[], char eMessage[], int lowLimit, int highLimit);
int getFloat(float* input, char message[], char eMessage[], float lowLimit, float highLimit);
int getChar(char* input, char message[], char eMessage[], char lowLimit, char highLimit);
int getString(char* input, char message[], char eMessage[], int lowLimit, int highLimit);
int getLong(long* input, char message[], char eMessage[], int lowLimit, int highLimit);

int getDni(char* input, char message[], char eMessage[]);
int getPhone(char* input, char message[], char eMessage[], int lowLimit, int highLimit);
int getName(char* input, char message[], char eMessage[], int lowLimit, int highLimit);
int isNumeric(char* string);
int isAlphabetic(char* string);

float add(float, float);
float subtract(float, float);
float divide(float, float);
float multiply(float, float);
long int factorial(float);
void getNameLastName(char nameLastName[]);

void pedirAlumno(int legajo[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam);
void mostrarUnAlumno(int legajo, int edad, char sexo, int nota1, int nota2, float promedio);
void mostrarAlumnos(int legajo[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam);
void ordenarAlumnos(int legajo[], int edad[], char sexo[], int nota1[], int nota2[], float promedio[], int tam);
