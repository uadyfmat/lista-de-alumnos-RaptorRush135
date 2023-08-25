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

void imprimirAlumno(Alumno alumno);

NodoPtr crearNodo(AlumnoPtr alumno);

int insertarNodoOrdenadoCreditos(NodoPtr* lista, NodoPtr nodo);

void imprimirLista(NodoPtr lista);

void errorCritico(const char* mensaje);

///


int main(void) {
    // Crear 5 instancias de estructuras Alumno.
    AlumnoPtr alumno1 = crearAlumno("Bonilla Perez Miguel", 36, 3);
    AlumnoPtr alumno2 = crearAlumno("Perez Canul Hector", 25, 2);
    AlumnoPtr alumno3 = crearAlumno("Ramos Reyes Francisco", 75, 4);
    AlumnoPtr alumno4 = crearAlumno("Bueno Martin Eric", 80, 1);
    AlumnoPtr alumno5 = crearAlumno("Perez Garcia Mauricio", 60, 3);

    // Crear la lista con las 5 instancias de Alumno.
    NodoPtr lista = NULL;
    NodoPtr nodo1 = crearNodo(alumno1);
    NodoPtr nodo2 = crearNodo(alumno2);
    NodoPtr nodo3 = crearNodo(alumno3);
    NodoPtr nodo4 = crearNodo(alumno4);
    NodoPtr nodo5 = crearNodo(alumno5);

    // Insertar de forma ordenada de acuerdo al número de créditos (descendente).
    insertarNodoOrdenadoCreditos(&lista, nodo1);
    insertarNodoOrdenadoCreditos(&lista, nodo2);
    insertarNodoOrdenadoCreditos(&lista, nodo3);
    insertarNodoOrdenadoCreditos(&lista, nodo4);
    insertarNodoOrdenadoCreditos(&lista, nodo5);

    // Imprimir la lista.
    imprimirLista(lista);

    return 0;
}

AlumnoPtr crearAlumno(char* nombreCompleto, int creditosAprobados, int semestreEquivalente) {
    AlumnoPtr nuevoAlumno = malloc(sizeof(Alumno));
    if (nuevoAlumno == NULL) {
        errorCritico("Malloc (crearAlumno)");
    }

    nuevoAlumno->nombreCompleto = nombreCompleto;
    nuevoAlumno->creditosAprobados = creditosAprobados;
    nuevoAlumno->semestreEquivalente = semestreEquivalente;
    return nuevoAlumno;
}

void errorCritico(const char* mensaje) {
    fputs("Error: ", stderr);
    fputs(mensaje, stderr);
    fputs(".\n", stderr);
    getchar();
    exit(1);
}
