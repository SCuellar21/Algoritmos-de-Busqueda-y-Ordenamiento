/* 
 * File:   Search & Sort.h
 * Author: Sergio
 *
 * Created on 25 de junio de 2015, 12:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int x;

#ifndef SEARCH___SORT_H
#define	SEARCH___SORT_H

#ifdef	__cplusplus
extern "C"
{
#endif

	int* PedirArreglo();
	bool LiSearch(int valor, const int* array);    
    bool BiSearch(int valor, const int* array);    
    int* InsertSort(int* array);    
	int* MergeSort(int* array, int inicio, int tamano);
	void ShowArray(const int* array);
	int PedirTamano();
	int PedirValor();

#ifdef	__cplusplus
}
#endif

#endif	/* SEARCH___SORT_H */
