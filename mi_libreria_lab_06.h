#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//declaracion de estructuras
typedef struct info{
   int num;
}Info;

typedef struct nodo{
   Info *dato;
   struct nodo *derecho;
   struct nodo *izquierdo;
}Nodo;



Nodo *crearNodo(int num){
	Nodo *n = (Nodo*) malloc(sizeof(Nodo));
	Info *dato = (Info*) malloc(sizeof(Info));
	dato->num = num;
    n->dato = dato;
    n->izquierdo = NULL;
    n->derecho = NULL;
    return n;
}

void agregarHijoDerecho(Nodo *padre, Nodo *hijo){
	padre->derecho = hijo;
}

void agregarHijoIzquierdo(Nodo *padre, Nodo *hijo){
	padre->izquierdo = hijo;
}

void insertarNodo(Nodo *raiz, int valor){
	if (valor < raiz->dato->num){
		if (raiz->izquierdo == NULL){
			agregarHijoIzquierdo(raiz,crearNodo(valor));
		}else{
			insertarNodo(raiz->izquierdo,valor);
		}
	}
	if (valor > raiz->dato->num){
		if (raiz->derecho == NULL){
			agregarHijoDerecho(raiz,crearNodo(valor));
		}else{
			insertarNodo(raiz->derecho,valor);
		}
	}
}


void imprimirNodo(Nodo* n){
    printf(" %d ",n->dato->num);
}


void preOrden(Nodo *raiz){
	if (raiz != NULL){
		imprimirNodo(raiz);
		preOrden(raiz->izquierdo);
		preOrden(raiz->derecho);
	}
}

void inOrden(Nodo *raiz){
	if (raiz != NULL){
		
		inOrden(raiz->izquierdo);
		imprimirNodo(raiz);
		inOrden(raiz->derecho);
	}
}

void posOrden(Nodo *raiz){
	if (raiz != NULL){
		
		posOrden(raiz->izquierdo);
		posOrden(raiz->derecho);
		imprimirNodo(raiz);
	}
}

Nodo* buscarPadre(Nodo *raiz, int hijo){
	if (raiz==NULL){
		return NULL;
	}else if(raiz->derecho->dato->num == hijo || raiz->izquierdo->dato->num == hijo){
		return raiz;
	}else{
		if(hijo < raiz->dato->num){
			buscarPadre(raiz->izquierdo,hijo);
		}else{
			buscarPadre(raiz->derecho,hijo);
		}
	}
}
	
