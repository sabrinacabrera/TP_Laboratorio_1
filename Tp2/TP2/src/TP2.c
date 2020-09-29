/*
 ============================================================================
 Name        : TP2.c
 Author      : Sabrina Cabrera
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo práctico numero 2 de la materia Laboratorio 1, curso 1E
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM 3
#define TAMSEC 5

typedef struct
{
    int idSector;
    char nombreSector[21];
} eSector;

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float salary;
	int idSector;
	int isEmpty;

} eEmployee;



int menuABM();
int initEmployees(eEmployee list[], int tam);
void showEmployee(eEmployee x ,eSector* list,int tamsec);
void showEmployeeS(eEmployee* list ,eSector* listSec,int tam,int tamsec);
int get_sector(eSector* list,int tamsec,int id,char* desc);
int lookEmpty( eEmployee* list,int tam);
int get_Data(eEmployee list[], int tam, int* nextId, char nombre[], char apellido[], float* salario, int* sector, int* index);
int getCadena(char* pAux, int limite);
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);
int isFloat(char* pAux);
int getFloat(float*pAux);
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);
int isChar(char str[]);
int isInt(char *pAux);
int getInt(int* pAux);
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);
int normalizeStr(char* str);
int addEmployee(eEmployee list[], int tam, int id, char nombre[], char apellido[], float salario, int sector, int index);
void menuSectores();


int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	char salir;
	int nextId = 999;
	int i=0;
	int cantidad;
	int index;
	//Variables escritas por get_Data y luego leidas por addEmployee:
	char auxName[51];
	char auxLastname[51];
	float auxSalary;
	int auxSector;
	int flagOp1=0;

	eSector sectores[TAMSEC]=
	    {
	        {1,"RRHH"},
	        {2,"SISTEMAS"},
	        {3,"LEGALES"},
	        {4,"VENTAS"},
	        {5,"COMPRAS"}
	    };

	eEmployee list[TAM];


	initEmployees(list,TAM);

	do{
		system("cls");

		switch(menuABM())
		{
		case 1:
			printf("****MENU ALTAS ****\n");
			utn_getEntero(&cantidad, 3, "Cuantos empleados ingresa ?:\n", "Error, la cantidad ingresada es incorrecta.\n", 1, 1000);

			do{
				i++;
				if(get_Data(list, TAM, &nextId, auxName, auxLastname, &auxSalary, &auxSector, &index)==0 && addEmployee(list, TAM, nextId, auxName, auxLastname, auxSalary, auxSector, index) == 0)
					{
						flagOp1 = 1; //modifico el flag si las dos funciones retornaron 0
					}

			}while(i < cantidad);

			i = 0;


			break;

		case 2:
				if (flagOp1==1)
				{


				}else
					{
						printf("error,debe cargar empleados.\n");

					}
			break;


		case 3:
			break;
		case 4:
			break;
		case 5:
			system("cls");
			printf("\n***** Salir *****\n\n ");
			printf("Segur@ desea salir? s/n: \n");
			fflush(stdin);
		    scanf("%c", &salir);
			if(salir == 's')
				{
					opcion = 's';
				}
			break;
		default:
			system("cls");
			printf("Ingrese opción valida");


		}

		system("pause");

	}while(opcion!='s');



	return 0;
}


int menuABM()
{
    int opcion;

    system("cls");
    printf("***** Menu ABM *****\n\n");
    printf("1. Altas.\n");
    printf("2. Modificar.\n");
    printf("3. Bajas.\n");
    printf("4. Informar.\n");
    printf("5. Salir.\n\n");
    printf("Ingresar opcion: \n");
    scanf("%d",&opcion);

    return opcion;
}

int initEmployees(eEmployee list[], int tam)
{
	if(list != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			list[i].isEmpty = 1;
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

void showEmployee(eEmployee x ,eSector* list,int tamsec)
{
	char descripcion[30];

	get_sector(list,tamsec,x.idSector,descripcion);

	printf( "%d %s %s %f %s \n",x.id ,x.lastName,x.name,x.salary,descripcion);
}

int get_sector(eSector* list,int tamsec,int id,char* desc)
{
	int itsOK=0;

	for(int i=0; i<tamsec;i++)
	{
		if(list[i].idSector == id)
		{
			strcpy(desc,list[i].nombreSector);
			itsOK=1;
			break;
		}

	}
	return itsOK;
}

void menuSectores()
	{
	 	printf("***** Menu sectores *****\n\n");
	    printf("1. RRHH\n");
	    printf("2. Sistemas\n");
	    printf("3. Legales\n");
	    printf("4. Ventas\n");
	    printf("5. Compras\n\n");

	}


void showEmployeeS(eEmployee* list ,eSector* listSec,int tam,int tamsec)
{
	printf("id    Nombre  Apellido   Salario    Sector\n");

	for(int i=0; i<tam;i++)
	{
		if(list[i].isEmpty==0){
			showEmployee(list[i],listSec,tamsec);
		}


	}

}

int lookEmpty( eEmployee* list,int tam){
	int index=-1; //retorna -1 si NO hay lugares vacios

	for(int i=0; i < tam;i++)
	{
		if (list[i].isEmpty ==1)
		{
			index= i; //retorna el primer subindice vacio
			break;
		}
	}

	return index;

}


int get_Data(eEmployee list[], int tam, int* nextId, char nombre[], char apellido[], float* salario, int* sector, int* index)
{
	int id = *nextId;
	int newId = id + 1;
	int isOk = -1;

	if(list != NULL && tam > 0 && nextId != NULL && nombre != NULL && apellido != NULL && salario != NULL && sector != NULL)
	{
		*index = lookEmpty(list, tam);

		if(index < 0) //si lookEmpty devolvio -1
		{
			printf("El sistema esta lleno.\n");
		}
		else
		{
			utn_getCadena(nombre, 51, 3, "Ingrese nombre: \n", "ERROR,El nombre ingresado es invalido.\n");
			utn_getCadena(apellido, 51, 3, "Ingrese apellido: \n ", "ERROR,El apellido ingresado es invalido.\n");
			utn_getFlotante(salario, 3, "Ingrese salario:\n ", "ERROR,El salario ingresado no es valido.\n", 20000.00, 500000.00);
			menuSectores();
			utn_getEntero(sector, 3, "Ingrese sector: \n", "ERROR,El sector ingresado no es valido.\n", 1, 5);

			*nextId = newId;
			isOk = 0;
		}
	}
	return isOk;
}



int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError)
{
	int isOk = -1;
    char auxString[limit];

    if(pAux != NULL && msg != NULL && msgError != NULL && limit > 0 && retry >= 0){
        do{
        	printf("%s", msg);

            if(getCadena(auxString, limit) == 0 && isChar(auxString) == 0)
            {
                strncpy(pAux, auxString, limit);
                isOk = 0; //todoOK
                break;
            }else
            {
            	printf("%s", msgError);
            }
            retry--;

        }while(retry>=0);
    }

    return isOk;
}



int getCadena(char* pAux, int limite)
{
    char auxString[4000];
    int isOk = -1;

    if (pAux != NULL && limite > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limite)
        {
            strncpy(pAux, auxString, limite);
            isOk=0; //exito
        }
    }

    return isOk;
}

int isChar(char str[])
{

	int isOk = 0; //todoOK

	for(int i = 0; str[i] != '\0'; i++)
	{
		//si no es espacio, si es menor a 'a' o may a 'z', si es men a 'A' o may a 'Z', NO es letra:
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			isOk = -1;
		}
	}

	return isOk;

}




int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max)
{
    int todoOK = -1;
    float auxFloat;

    if(pFloat != NULL&& msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s",msg);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat <= max)
            {
                *pFloat= auxFloat;
                todoOK = 0; //exito
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(retry >= 0);
    }
    return todoOK;
}



int getFloat(float*pAux)
{
    char auxString[200];
    int todoOK =-1;

    if(getCadena(auxString,200) == 0 && isFloat(auxString) == 0)
    {
        *pAux = atof(auxString); //to float
        todoOK = 0; //exito
    }
    return todoOK;
}



int isFloat(char* pAux)
{
    int todoOk = -1;
    int i = 0;
    int dotCount=0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) == '.')
        {
            dotCount++;
            if(dotCount == 2)
            {
                break;
            }
        }
        else if(*(pAux + i) < '0'|| *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
    	todoOk = 0; //exito
    }
    return todoOk;
}


int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max)
{
    int isOk = -1;
    int auxInt;

    if(pEntero != NULL && msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s", msg);

            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt <= max)
            {
                *pEntero = auxInt;
                isOk = 0; //exito
                break;
            }
            else
            {
                printf("%s", msgError);
            }
        }
        while(retry >= 0);
    }
    return isOk;
}

int getInt(int* pAux)
{
    char auxString[400];
    int isOk = -1;

    if(getCadena(auxString, sizeof(auxString)) == 0 && isInt(auxString ) == 0)
    {
        *pAux = atoi(auxString); //to integer
        isOk = 0; //exito
    }
    return isOk;
}


int isInt(char *pAux)
{
    int isOk = -1;
    int i = 0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) < '0' || *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        isOk = 0; //exito
    }

    return isOk;
}

int normalizeStr(char* str)
{
	int isOk = -1;
	int i = 0;

	if(str != NULL)
	{

		strlwr(str);
		str[0] = toupper(str[0]);

		while(str[i] != '\0')
		{
			if(str[i] == ' ')
			{
				str[i + 1] = toupper(str[i + 1]);
				isOk = 0; //exito
			}
			i++;
		}
	}
	return isOk;
}


int addEmployee(eEmployee list[], int tam, int id, char nombre[], char apellido[], float salario, int sector, int index)
{
	int isOk = -1;

	if(list != NULL && nombre != NULL && apellido != NULL && tam > 0)
	{
		normalizeStr(nombre);
		normalizeStr(apellido);

		list[index].id = id;
		strcpy(list[index].name, nombre);
		strcpy(list[index].lastName, apellido);
		list[index].salary = salario;
		list[index].idSector = sector;
		list[index].isEmpty = 0;
		isOk = 0;
	}
	return isOk;
}
