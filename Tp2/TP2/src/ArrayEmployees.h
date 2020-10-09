/*
 * ArrayEmployees.h
 *
 *  Created on: 8 oct. 2020
 *      Author: gisel
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

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

int initEmployees(eEmployee list[], int tam);
void showEmployee(eEmployee x ,eSector* list,int tamsec);
void showEmployeeS(eEmployee* list ,eSector listSec[],int tam,int tamsec);
int addEmployee(eEmployee list[], int tam, int id, char nombre[], char apellido[], float salario, int sector, int index);
int findEmployeeById(eEmployee list[], int tam, int id);
int removeEmployee(eEmployee*list, int tam, int id, eSector* sectors, int tamsec);
int sortEmployees(eEmployee* list, int tam, int order);
void hardCodearEmpleados(eEmployee* list, int tam);
int menuModificar(eEmployee *list,int tam ,eSector* sector,int tamsec);
int informes(eEmployee list[], int tam, eSector sector[], int tamsec);
int totalAndPromedySalaries(eEmployee* list, int tam);
int menuInform();


int get_sector(eSector* list,int tamsec,int id,char* desc);
void menuSectores();

#endif /* ARRAYEMPLOYEES_H_ */
