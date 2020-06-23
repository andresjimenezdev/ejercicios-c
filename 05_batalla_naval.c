/**
 * Crear un programa que represente una partida del famoso juego de mesa "Batalla Naval". Para esto, se
 * crearan algunas funciones que ayuden al desarrollo del juego.
 * 
 * La matriz recibida tendra **~** en las coordenadas donde haya agua, **B** en las coordenadas donde
 * haya un barquito, **X** en las coordenadas donde se haya disparado al agua y **T** en las coordenadas
 * donde se haya tocado a un barco.
 * 
 * En resumen, el programa debe:
 * * Crear un procedimiento que reciba una matriz de caracteres, las coordenas del disparo y con esta
 *   informacion actualizar la matriz, poniendo una **X** si el disparo fue al agua o una **T** si el
 *   disparo toco un barco.
 * * Crear un procedimiento que permita a un usuario cargar barquitos en el tablero.
 * * Crear una funcion que reciba una matriz representando a un tablero y devuelva true si se ha ganado 
 *   la partida.
*/

#include <stdio.h>
#include <stdbool.h>

const char AGUA = '~', BARCO = 'B', TOCADO = 'T', ERRADO = 'X';
const char VERTICAL = 'V', HORIZONTAL = 'H';
const int MIN_TABLERO = 0, MAX_TABLERO = 9, TABLERO = 10;
const int MIN_TAM_BARCO = 1, MAX_TAM_BARCO = 4, CANTIDAD_BARCOS = 9;

/**
 * pre: Recibe una matriz de caracteres vacia.
 * post: Llena la matriz con el caracter "~" simulando agua
*/
void inicializar_tablero(char tablero[TABLERO][TABLERO]) {
    for(int i = 0; i < TABLERO; i++) {
        for(int j = 0; j < TABLERO; j++) {
            tablero[i][j] = AGUA;
        }
    }
}

/**
 * pre: Recibe una matriz de caracteres con contenido
 * post: muestra por consola el contenido de la matriz
*/
void mostar_tablero(char tablero[TABLERO][TABLERO]) {
    for(int i = 0; i < TABLERO; i++) {
        for(int j = 0; j < TABLERO; j++) {
            printf(" %c", tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * pre: Recibe varios parametros necesarios para ubicar un barco en el tablero
 * post: Cambia en la matriz el caracter de agua "~" por el del barco "B" que se ubicara en el tablero
*/
void ubicar_barco(char tablero[TABLERO][TABLERO], char direccion, int tamanio_barco, int fila, int col) {
    if(direccion == VERTICAL) {
        for(int i = 0; i < tamanio_barco; i++ ) {
            tablero[fila + i][col] = BARCO;
        }
    } else if(direccion == HORIZONTAL) {
        for(int i = 0; i < tamanio_barco; i++) {
            tablero[fila][col + i] = BARCO;
        }
    }
}

/**
 * pre: Recibe la informacion necesaria para realizar un disparo en el tablero
 * post: Cambia en la matriz el valor de agua "~" por "T" si le dio a un barco o "X" si le dio al agua
*/
void disparar(char tablero[TABLERO][TABLERO], int fila, int col) {
    if(tablero[fila][col] == BARCO) {
        tablero[fila][col] = TOCADO;
        printf("\nLe diste a un barco... ¡Sigue asi!\n");
    } else {
        tablero[fila][col] = ERRADO;
        printf("\nDisparo errado... ¡Continua disparando!\n");
    }
}

/**
 * pre: Recibe una matriz de caracteres
 * post: Recorre la matriz buscnado barcos, devuelve "true" o "false" si hay o no barcos en la matriz
*/
bool hay_ganador(char tablero[TABLERO][TABLERO]) {
    int cantidad_de_barcos = 0;
    for(int i = 0; i < TABLERO; i++) {
        for(int j = 0; j < TABLERO; j++) {
            if(tablero[i][j] == BARCO)
                cantidad_de_barcos++;
        }
    }

    if(cantidad_de_barcos)
        return false;
    else 
        return true;
}

/**
 * pre: Recibe un caracter
 * post: Devuelve "true" si el caracter es "V" o "H", de lo contrario devuelve "false"  
*/
bool letra_valida(char letra) {
    if(letra == VERTICAL || letra == HORIZONTAL) 
        return true;
    else
        return false;
}

/**
 * pre: Recibe un puntero a caracter donde se almacenara una letra ingresada por el usuario
 * post: Asigna una letra en la variable ingresada como puntero, si es una letra valida. 
*/
void pedir_letra(char* letra) {
    scanf(" %c", letra);
    while(!(letra_valida(*letra))) {
        printf("Opcion no valida. Vuelve a intentarlo: ");
        scanf(" %c", letra);
    }
}

/**
 * pre: Recibe un numero, y un rango de numeros (min y max)
 * post: Devuelve "true" o "false", si el numero ingresado se encuentra o no dentro del rango establecido
*/
bool numero_valido(int numero, int min, int max) {
    return (numero >= min && numero <= max);
}

/**
 * pre: Recibe un puntero a entero y un rango de numeros (min y max)
 * post: Asigna un numero en la variable ingresada como puntero, si es un numero valido. 
*/
void pedir_numero(int* numero, int min, int max) {
    scanf("%d", numero);
    while(!(numero_valido(*numero, min, max))) {
        printf("Lo siento, esa no es una opcion valida. Vuelve a intentarlo: ");
        scanf("%d", numero);
    }
}

int main() {

    char tablero[TABLERO][TABLERO]; 
    char direccion;
    int fila_disparo, col_disparo, fila_barco, col_barco, tamanio_barco, barco_numero;

    inicializar_tablero(tablero);
    
    barco_numero = 1;
    while(barco_numero <= CANTIDAD_BARCOS) {
        
        printf("Ingresa los datos del barco No. %d\n", barco_numero);
        printf("----------------------------------\n\n");

        printf("Tamaño - (1), (2), (3), (4): ");
        pedir_numero(&tamanio_barco, MIN_TAM_BARCO, MAX_TAM_BARCO);

        printf("Direccion - (V)Vertical, (H)Horizontal: ");
        pedir_letra(&direccion);

        printf("¿Donde quieres ubicarlo?\n");
        printf("fila: ");
        pedir_numero(&fila_barco, MIN_TABLERO, MAX_TABLERO);
        printf("columna: ");
        pedir_numero(&col_barco, MIN_TABLERO, MAX_TABLERO);
        
        ubicar_barco(tablero, direccion, tamanio_barco, fila_barco, col_barco);

        mostar_tablero(tablero);

        barco_numero++;

    }

    mostar_tablero(tablero);

    while (!hay_ganador(tablero)) {
        printf("Ingresa las coordenadas de disparo\n");
        printf("fila: ");
        scanf("%d", &fila_disparo);
        printf("columna: ");
        scanf("%d", &col_disparo);
        
        disparar(tablero, fila_disparo, col_disparo);
        
        mostar_tablero(tablero);
    }

    printf("¡Ganaste!... Ya no hay mas barcos\n");

    return 0;
}