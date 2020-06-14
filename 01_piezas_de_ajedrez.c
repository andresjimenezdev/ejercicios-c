/*
01_piezas_de_ajedrez.c
----------------------
El ajedrez tiene 6 tipos de fichas distintas. Cada una de ellas tiene movimientos particulares  dependiendo del tipo. 

* Crear un programa que le pida al usuario:
    * Inicial de la ficha que quiere mover.
    * Posicion inicial (fila y columna).
    * Posicion final (fila y columna).
  Y determinar si el movimiento es valido.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/* Declaracion de constantes */
const char ALFIL = 'a', CABALLO = 'c', PEON = 'p', REINA = 'r', REY = 'R', TORRE = 't';
const int FILAS = 8, COLUMNAS = 8;

/* Declaracion de funciones */
bool validar_ficha_a_mover(char ficha_a_mover);
void preguntar_posicion(int* fila, int* columna);
bool validar_posicion(int fila, int columna);
int validar_movimiento_ficha(int desp_filas, int desp_columnas, char ficha_a_mover);
void mover_ficha(int* fila_inicial, int* columna_inicial, int* fila_final, int* columna_final);

int main() {

    char ficha_a_mover;
    int fila_inicial, columna_inicial, fila_final, columna_final, desp_filas, desp_columnas;

    printf("Bienvenido al ajedrez de consola escrito en C.\n");
    printf("Estas son las fichas que puedes usar (%c)Alfil, (%c)Caballo, (%c)Peon, (%c)Reina, (%c)Rey, (%c)Torre: \n", ALFIL, CABALLO, PEON, REINA, REY, TORRE);
    printf("Como todo tablero de ajedrez, tienes %d filas y %d columnas para mover tus fichas\n\n", FILAS, COLUMNAS);

    /* Pedir al usuario la letra inicial de la ficha que desea mover */
    printf("Selecciona la ficha que desea mover: ");
    scanf(" %c", &ficha_a_mover);
    while(!validar_ficha_a_mover(ficha_a_mover)) {
        printf("Ooops... Esa ficha no es valida. Selecciona una ficha correcta: ");
        scanf(" %c", &ficha_a_mover);
    }

    /* Pedir al usuario la posicion inicial de la ficha que desea mover */
    printf("¿Cual es la posicion inicial de la ficha?\n");
    preguntar_posicion(&fila_inicial, &columna_inicial);
    while (!validar_posicion(fila_inicial, columna_inicial)) {
        printf("Ooops... Esa no es una posicion valida. El tablero es de %d filas y %d columnas.\n", FILAS, COLUMNAS);
        printf("¿Cual es la posicion inicial de la ficha?\n");
        preguntar_posicion(&fila_inicial, &columna_inicial);
    }

    /* Pedir al usuario la posicion hacia donde desea mover la ficha*/
    printf("¿A que posicion quieres mover la ficha?\n");
    preguntar_posicion(&fila_final, &columna_final);
    while (!validar_posicion(fila_final, columna_final)) {
        printf("Ooops... Esa no es una posicion valida. El tablero es de %d filas y %d columnas.\n", FILAS, COLUMNAS);
        printf("¿A que posicion quieres mover la ficha?\n");
        preguntar_posicion(&fila_final, &columna_final);
    }    

    /* Calculando el desplazamiento de la ficha */
    desp_filas = fabs(fila_final - fila_inicial);
    desp_columnas = fabs(columna_final - columna_inicial);

    /* Verificar si el movimiento es valido para la ficha */
    if(validar_movimiento_ficha(desp_filas, desp_columnas, ficha_a_mover)){
        mover_ficha(&fila_inicial, &columna_inicial, &fila_final, &columna_final);
        printf("Tu ficha se movio exitosamente\n");
    } else
        printf("Tu ficha NO se puede mover asi\n");    
}

/* Definicion de las funciones declaradas*/
    
    /* Funcion que valida si la inicial de la ficha seleccionada concuerda con alguna de las fichas del juego. Devuelve true o false. */
    bool validar_ficha_a_mover(char ficha_a_mover) {
        return(
            ficha_a_mover == ALFIL   || 
            ficha_a_mover == CABALLO || 
            ficha_a_mover == PEON    || 
            ficha_a_mover == REINA   || 
            ficha_a_mover == REY     || 
            ficha_a_mover == TORRE
        );
    }

    /* Funcion que pide una posicion en el tablero */
    void preguntar_posicion(int* fila, int* columna) {
        printf("Fila: ");
        scanf("%d", fila);
        printf("Columna: ");
        scanf("%d", columna);
    }


    /* Funcion que valida si la posicion de la ficha se encuentra dentro del tablero de 8 filas y 8 columnas. Devuelve true o false */
    bool validar_posicion(int fila, int columna) {
        return((fila >= 1 && fila <= 8) && (columna >= 1 && columna <= 8));
    }

    /* int validar_movimiento_ficha: Es una funcion que valida el movimiento de la ficha
        Parametros que recibe:
        - filas = desp_filas
        - columnas = desp_columnas
        - ficha_a_mover */
    int validar_movimiento_ficha(int filas, int columnas, char ficha_a_mover) {
        
        // Validando Movimiento Diagonal
        if(((filas == 1 && columnas == 1) && (ficha_a_mover == REY)) ||
           ((filas == columnas) && (ficha_a_mover == REINA || ficha_a_mover == ALFIL)))
            return 1;

        // Validando Movimiento Vertical
        else if(((filas == 1 && columnas == 0) && (ficha_a_mover == PEON  || ficha_a_mover == REY)) ||       ((filas >= 1 && columnas == 0) && (ficha_a_mover == REINA || ficha_a_mover == TORRE)))
            return 1;

        // Validando Movimiento Horizontal
        else if(((columnas == 1 && filas == 0) && (ficha_a_mover == REY)) || 
                ((columnas >= 1 && filas == 0) && (ficha_a_mover == REINA || ficha_a_mover == TORRE)))
            return 1;

        // Validando Movimiento en "L"    
        else if((filas == 1 && columnas == 2) && (ficha_a_mover == CABALLO))
            return 1;
        
        // Movimiento NO Valido
        else 
            return 0;
    }

    /* Funcion que cambia los valores iniciales de fila y columna, confirmando que la ficha se movio exitosamente. */
    void mover_ficha(int* fila_inicial, int* columna_inicial, int* fila_final, int* columna_final) {
        *fila_inicial = *fila_final;
        *columna_inicial = *columna_final;
        *fila_final = 0;
        *columna_final = 0;
    }