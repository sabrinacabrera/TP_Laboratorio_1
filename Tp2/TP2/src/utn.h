/*
 * utn.h
 *
 *  Created on: 8 oct. 2020
 *      Author: gisel
 */

#ifndef UTN_H_
#define UTN_H_

int menuABM();

int get_sector(eSector* list,int tamsec,int id,char* desc);

int lookEmpty( eEmployee* list,int tam);

int getCadena(char* pAux, int limite);

int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);

int getFloat(float*pAux);

int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);


int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

int getInt(int* pAux);

int isFloat(char* pAux);

int isChar(char str[]);

int isInt(char *pAux);


int normalizeStr(char* str);


#endif /* UTN_H_ */
