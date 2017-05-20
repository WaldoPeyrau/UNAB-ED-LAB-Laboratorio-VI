#include <stdlib.h>
#include <stdio.h>
#include "mi_libreria_lab_04.h"
#include <stdbool.h>

/****************************************************************
* Programa: lab_06.c
*
* Objetivo: Crear las funciones y estructuras necesarias para generar un árbol binario, cada nodo
*			debe contener una estructura Info que permita almacenar un número entero.
*
* Fecha Creación: 18/05/2017  Fecha última actualización: 18/05/2017
*
* Autor/Grupo: Waldo Peyrau Morales
*
* Asignatura: Estructura de datos INS127     Sección: 651
*
*****************************************************************/

int buscarMenorValor(Nodo*);
int buscarMayorValor(Nodo*);
int determinarCantidadNiveles(Nodo*);
void eliminarElemento(Nodo*,int);
void quitarNodo(Nodo*,Nodo*);
Nodo* buscarAntecesor(Nodo*);

int main(int argc, char **argv)
{
	Nodo* raiz = crearNodo(9);
	insertarNodo(raiz,78);
	insertarNodo(raiz,6);
	insertarNodo(raiz,3);
	insertarNodo(raiz,7);
	insertarNodo(raiz,9);
	insertarNodo(raiz,5);
	insertarNodo(raiz,88);
	insertarNodo(raiz,10);
	insertarNodo(raiz,0);
	insertarNodo(raiz,1);
	insertarNodo(raiz,34);
	insertarNodo(raiz,22);
	insertarNodo(raiz,4);
	insertarNodo(raiz,2);
	insertarNodo(raiz,8);
	insertarNodo(raiz,45);
	insertarNodo(raiz,32);
	insertarNodo(raiz,65);
	insertarNodo(raiz,42);
	
    preOrden(raiz);
    printf("\n");
    inOrden(raiz);
    printf("\n");
    posOrden(raiz);
    printf("\n");
    
    printf("el menor valor es: %d\n",buscarMenorValor(raiz));
    printf("el mayor valor es: %d\n",buscarMayorValor(raiz));
    printf("la altura del arbol es: %d\n",determinarCantidadNiveles(raiz));
    
    eliminarElemento(raiz,88);
    inOrden(raiz);

}

int buscarMenorValor(Nodo *raiz){
	if (raiz->izquierdo == NULL){
		return raiz->dato->num;
	}else{
		buscarMenorValor(raiz->izquierdo);
	}
}		

int buscarMayorValor(Nodo *raiz){
	if (raiz->derecho == NULL){
		return raiz->dato->num;
	}else{
		buscarMayorValor(raiz->derecho);
	}
}		

int determinarCantidadNiveles(Nodo *raiz){
    int AltIzq, AltDer;

    if(raiz==NULL)
        return 0;
    else
    {
        AltIzq = determinarCantidadNiveles(raiz->izquierdo);
        AltDer = determinarCantidadNiveles(raiz->derecho);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}

void eliminarElemento(Nodo* raiz,int valor){
	

     if(raiz==NULL){ 
		 printf("valor no encontrado\n"); 
		 return;
	 }

     if(valor < raiz->dato->num){
         if(valor == raiz->izquierdo->dato->num){
			 quitarNodo(raiz,raiz->izquierdo);
		 }else{ 
			eliminarElemento(raiz->izquierdo, valor);
		}
	}else if(valor > raiz->dato->num){
         if(valor == raiz->derecho->dato->num){
			 quitarNodo(raiz,raiz->derecho);
		 }else{ 
			eliminarElemento(raiz->derecho, valor);
		}
	}
	
}

void quitarNodo(Nodo* padre, Nodo* hijo){
	printf("se eliminara el nodo: %d\n", hijo->dato->num);
	if (hijo->izquierdo == NULL && hijo->derecho == NULL){
		if(padre->izquierdo == hijo){
			padre->izquierdo = NULL;
		}
		else{
			padre->derecho = NULL;			
		}
		free(hijo);
	}else if(hijo->derecho != NULL && hijo->izquierdo != NULL){
		Nodo *aux = buscarAntecesor(hijo->izquierdo);
		int valorAux = hijo->dato->num;
		printf("el antecesor de %d es: %d\n",hijo->dato->num,aux->dato->num);
		
		hijo->dato->num = aux->dato->num;
		aux->dato->num = valorAux;
		//printf("padre: %d - hijo: %d - aux: %d",padre->dato->num,hijo->dato->num,valorAux);
		
		eliminarElemento(hijo->izquierdo,valorAux);
		
	}else{
		if(padre->izquierdo == hijo){
			if(hijo->izquierdo != NULL){
				padre->izquierdo=hijo->izquierdo;
			}else{
				padre->izquierdo=hijo->derecho;
			}
		}
		else{
			if(hijo->izquierdo != NULL){
				padre->derecho=hijo->izquierdo;
			}else{
				padre->derecho=hijo->derecho;
			}
		}
		free(hijo);
	}
	
}

Nodo* buscarAntecesor(Nodo *hijo){
	if (hijo->derecho == NULL){
		return hijo;
	}else{
		buscarAntecesor(hijo->derecho);
	}
}
		
