#include "Search-Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int a = 0, array[];

int PedirTamano()
{
	if (a == 0)
	{
		printf("Que tamaño tiene el arreglo?\n");
		scanf("%d", &x);
		a++;
		return x;
	}
	return x;
}

/*
 * Pide un arreglo de enteros que el usuario llena
 */
int* PedirArreglo()
{
	const int n = PedirTamano();
	a = 0;
	
	if (n == 0)
	{
		printf("Error:  tamaño del arreglo es 0");
	}
	
	printf("Llenar el arreglo automaticamente?\nS  ->  Si\nN  ->  No\n");
	char opcion;
	scanf(" %c", &opcion);
	if (opcion == 115 || opcion == 83)
	{
		// llena el arreglo con números aleatorios menores a 1000000
		for (int i = 0; i < n; i++)
		{
			array[i] = rand() % 1000000;
		}
	}
	else
	{
		printf("Escribe los valores de arrreglo\n");
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &array[i]);
		}
	}
	
	ShowArray(array);
	return array;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool LiSearch(int valor, const int* array)
{
	const int n = x;
	if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (valor == array[i])
            {
                // printf("Found in [%d] place of the array\n", i")
                return true;
            }
        }
    }
    return false;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool BiSearch(int valor, const int* array)
{
  	const int n = x;
	int medio, inicio = 0, final = n - 1;

    while (inicio <= final)
    {
        medio = (inicio + final) / 2;
        if (array[medio] == valor)
        {
            // printf("Found in [%d] place of the array\n", medio);
            return true;
        }
        else
        {
            if (array[medio] < valor)
            {
                inicio = medio + 1;
            }
            else
            {
                final = medio - 1;
            }
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
int* InsertSort(int* array)
{
    const int n = x;
	for (int i = 1, num_usado = 0; i < n; i++)
    {
        int j;
        num_usado = array[i];
        for (j = i; j > 0 && array[j-1] > num_usado; j--)
        {
            array[j] = array[j-1];
        }
        array[j] = num_usado;
    }
    
	printf("\nArreglo ordenado!");
	return array;
}

/**
 * Sorts array of n values.
 */
// USAGE:  MergeSort(array, 0, n);      MergeSort(array, BEGINING of array, SIZE);
int* MergeSort(int* array, int inicio, int tamano)
{
    const int n = x;
	int final = inicio + tamano - 1;

    // returns if array is of size 1 (SORTED)
    if (inicio == final)
    {
		return 0; 
    }

    // sets the division point por the left and right sides
    int aumento, mitad = (inicio + final) / 2;
	if (tamano % 2 == 0)
	{
		aumento = 1;
	}
	else
	{
		aumento = 0;
	}

    // merge sort the left side
    MergeSort(array, inicio, mitad - inicio + 1);
    // merge sort the right side
    MergeSort(array, mitad + 1, mitad-inicio+aumento);
	
	int merge1, merge2, temp[tamano];
    // remembers the array in a temp
    for (int i = 0; i < tamano; i++)
    {
        temp[i] = array[inicio + i];
    }

    merge1 = 0;
    merge2 = mitad - inicio + 1;

    // SORT
    for (int i = 0; i < tamano; i++)
    {
        if (merge2 <= final - inicio)
        {
            if (merge1 <= mitad - inicio)
            {
                if (temp[merge1] > temp[merge2])
                {
                    array[i + inicio] = temp[merge2++];
                }
                else
                {
                    array[i + inicio] = temp[merge1++];
                }
            }
            else
            {
                array[i + inicio] = temp[merge2++];
            }
        }
        else
        {
            array[i + inicio] = temp[merge1++];
        }
    }
	
	if (tamano == n)
	{
		printf("\nArreglo ordenado!");
	}
	return array;
}

/*
 * Prints the array to show it to de user
 */
void ShowArray(const int* array)
{
	const int n = x;
	char opcion;
	printf("\nMostrar el arreglo? \nS  ->  Si \nN  ->  No\n");
	scanf(" %c", &opcion);
	if (opcion == 115 || opcion == 83)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d,", array[i]);
		}
		printf("\n");
	}
}

int PedirValor()
{
	int valor;
	printf("Escribe el valor que quieres buscar en el arreglo\n");
	scanf("%d", &valor);
	return valor;
}