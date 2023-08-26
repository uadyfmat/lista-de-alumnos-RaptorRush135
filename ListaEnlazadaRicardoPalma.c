#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Alumno{
    char* nombreCompleto;
    int creditosAprobados;
    int semestreEquivalente;
} Alumno;

typedef struct Nodo {
    Alumno* dato;
    struct Nodo* siguientePtr;
} Nodo;

typedef Alumno* AlumnoPtr;
typedef Nodo* NodoPtr;

///

AlumnoPtr crearAlumno(char* nombreCompleto, int creditosAprobados, int semestreEquivalente);

void imprimirAlumno(Alumno alumno);

NodoPtr crearNodo(AlumnoPtr alumno);

void insertarNodoOrdenadoCreditos(NodoPtr* lista, NodoPtr nuevoNodo);

void imprimirLista(NodoPtr lista);

bool listaVacia(NodoPtr lista);

void* reservar(size_t tamanio, const char* mensajeTipo);

void errorCritico(const char* mensaje);

///


int main(void) {
    // Crear 5 instancias de estructuras Alumno.
    AlumnoPtr alumno1 = crearAlumno("Bonilla Perez Miguel", 36, 2);
    AlumnoPtr alumno2 = crearAlumno("Perez Canul Hector", 25, 3);
    AlumnoPtr alumno3 = crearAlumno("Ramos Reyes Francisco", 75, 4);
    AlumnoPtr alumno4 = crearAlumno("Bueno Martin Eric", 80, 6);
    AlumnoPtr alumno5 = crearAlumno("Perez Garcia Mauricio", 60, 3);
    putchar('\n');

    // Crear la lista con las 5 instancias de Alumno.
    NodoPtr lista = NULL;
    NodoPtr nodo1 = crearNodo(alumno1);
    NodoPtr nodo2 = crearNodo(alumno2);
    NodoPtr nodo3 = crearNodo(alumno3);
    NodoPtr nodo4 = crearNodo(alumno4);
    NodoPtr nodo5 = crearNodo(alumno5);
    putchar('\n');

    // Insertar de forma ordenada de acuerdo al número de créditos (descendente).
    insertarNodoOrdenadoCreditos(&lista, nodo1);
    insertarNodoOrdenadoCreditos(&lista, nodo2);
    insertarNodoOrdenadoCreditos(&lista, nodo3);
    insertarNodoOrdenadoCreditos(&lista, nodo4);
    insertarNodoOrdenadoCreditos(&lista, nodo5);

    // Imprimir la lista.
    imprimirLista(lista);

    getchar();
    return 0;
}

AlumnoPtr crearAlumno(char* nombreCompleto, int creditosAprobados, int semestreEquivalente) {
    AlumnoPtr nuevoAlumno = reservar(sizeof(Alumno), "una estructura alumno");
    nuevoAlumno->nombreCompleto = nombreCompleto;
    nuevoAlumno->creditosAprobados = creditosAprobados;
    nuevoAlumno->semestreEquivalente = semestreEquivalente;
    return nuevoAlumno;
}

void imprimirAlumno(Alumno alumno) {
    printf("Nombre: %s, Creditos aprobados: %d, Semestre equivalente: %d",
        alumno.nombreCompleto, alumno.creditosAprobados, alumno.semestreEquivalente
    );
}

NodoPtr crearNodo(AlumnoPtr alumno) {
    NodoPtr nuevoNodo = reservar(sizeof(Nodo), "un nodo en la lista de alumnos");
    nuevoNodo->dato = alumno;
    nuevoNodo->siguientePtr = NULL;
    return nuevoNodo;
}

void insertarNodoOrdenadoCreditos(NodoPtr* lista, NodoPtr nuevoNodo) {
    if (listaVacia(*lista)) {
        *lista = nuevoNodo;
        return;
    }

    NodoPtr elemento = *lista;
    NodoPtr antElemento = elemento;
    while (elemento != NULL && elemento->dato->creditosAprobados > nuevoNodo->dato->creditosAprobados) {
        antElemento = elemento;
        elemento = elemento->siguientePtr;
    }

    if (elemento == *lista) {
        nuevoNodo->siguientePtr = *lista;
        *lista = nuevoNodo;
    } else {
        nuevoNodo->siguientePtr = antElemento->siguientePtr;
        antElemento->siguientePtr = nuevoNodo;
    }
}

void imprimirLista(NodoPtr lista) {
    if (listaVacia(lista)) {
        printf("Lista vacia.\n\n");
        return;
    }

    printf("Contenido de la lista:\n");
    NodoPtr actual = lista;
    while (actual != NULL) {
        imprimirAlumno(*(actual->dato));
        putchar('\n');
        actual = actual->siguientePtr;
    }
}

bool listaVacia(NodoPtr lista) {
    return lista == NULL;
}

void* reservar(size_t tamanio, const char* mensajeTipo) {
    void* memoria = malloc(tamanio);
    if (memoria == NULL) {
        errorCritico("Malloc");
    }

    printf("Se ha creado %s en %p\n", mensajeTipo, memoria);
    return memoria;
}

void errorCritico(const char* mensaje) {
    fputs("Error: ", stderr);
    fputs(mensaje, stderr);
    fputs(".\n", stderr);
    getchar();
    exit(1);
}
