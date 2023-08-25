#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Alumno{
    char* nombreCompleto;
    int creditosAprobados;
    int semestreEquivalente;
} Alumno;

typedef struct Nodo {
    Alumno* dato;
    Nodo* siguientePtr;
} Nodo;

typedef Alumno* AlumnoPtr;
typedef Nodo* NodoPtr;

///

AlumnoPtr crearAlumno(char* nombreCompleto, int creditosAprobados, int semestreEquivalente);

void imprimirAlumno();

NodoPtr crearNodo(AlumnoPtr alumno);

int insertarNodoOrdenadoCreditos(NodoPtr nodo);

void imprimirLista();

///


int main(void) {

    return 0;
}
