/*
    02_partida_de_ajedrez.c
    ----------------------
    Crear un programa que permita iniciar una partida de ajedrez entre dos jugadores con una ficha cada uno. 

    Para inicializar el tablero se deben pedir:
        Ficha blanca con la cual jugar (inicial).
        Ficha negra con la cual jugar (inicial).
        Pedir posición inicial (fila y columna) para la ficha blanca.
        Pedir posición inicial (fila y columna) para la ficha negra.

    Y luego de inicializarlo, empezar el juego:
        Pedir y realizar movimiento de la ficha blanca.
        Pedir y realizar movimiento de la ficha negra.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* Declaración de constantes */
const char ALFIL = 'a', CABALLO = 'c', PEON = 'p', REINA = 'r', REY = 'R', TORRE = 't';
const int FILAS = 8, COLUMNAS = 8, JUGADOR_BLANCAS = 1, JUGADOR_NEGRAS = 2;

/* Declaración de funciones */
void elegir_ficha(char* ficha_a_mover);
bool validar_ficha_a_mover(char ficha_a_mover);
void preguntar_posicion(int* fila, int* columna);
bool validar_posicion(int fila, int columna);
void movimiento_ficha(int fila_ini, int col_ini, int fila_fin, int col_fin, int* filas, int* columnas);
int validar_movimiento_ficha(int desp_filas, int desp_columnas, char ficha_a_mover);
void actualizar_posicion(int* fila_ini, int* col_ini, int* fila_fin, int* col_fin);
void mover_ficha(char* ficha, int* fila_ini, int* col_ini, int* fila_fin, int* col_fin, int* filas, int* columnas);
bool hay_ganador(int fila_ini_bla, int col_ini_bla, int fila_ini_neg, int col_ini_neg);

int main() {

    /* Declaración de Variables */
    char ficha_blanca, ficha_negra;
    int fila_ini_bla = 0, col_ini_bla = 0, fila_ini_neg = 0, col_ini_neg = 0;
    int desp_filas, desp_columnas, turno = JUGADOR_BLANCAS;
    bool ganador = false;
    
    /* Variables que comparten las 2 fichas. Siempre deben volver a -1 cuando se termine un turno. */
    int fila_fin = -1, col_fin = -1;

    printf("Bienvenido al ajedrez de consola escrito en C.\n");
    printf("Tienes %d filas y %d columnas para mover tus fichas\n", FILAS, COLUMNAS);
    printf("Estas son las fichas que puedes usar (%c)Alfil, (%c)Caballo, (%c)Peon, (%c)Reina, (%c)Rey, (%c)Torre: \n\n", ALFIL, CABALLO, PEON, REINA, REY, TORRE);

    /* Pedir inicial y posición de la ficha blanca */
    printf("Las blancas inician eligiendo ficha\n");
    elegir_ficha(&ficha_blanca);
    preguntar_posicion(&fila_ini_bla, &col_ini_bla);
    
    /* Pedir inicial y posición de la ficha negra */
    printf("Ahora eligen las negras\n");
    elegir_ficha(&ficha_negra);
    preguntar_posicion(&fila_ini_neg, &col_ini_neg);

    /* Se inicia el juego hasta que alguien gane */
    while(!ganador) {

        if(turno == JUGADOR_BLANCAS) {
            printf("\nJuegan las blancas...\n");
            mover_ficha(
                &ficha_blanca,
                &fila_ini_bla,
                &col_ini_bla,
                &fila_fin,
                &col_fin,
                &desp_filas,
                &desp_columnas
            );
            turno++;

        } else if (turno == JUGADOR_NEGRAS) {
            printf("\nJuegan las negras...\n");
            mover_ficha(
                &ficha_negra,
                &fila_ini_neg,
                &col_ini_neg,
                &fila_fin,
                &col_fin,
                &desp_filas,
                &desp_columnas
            );
            turno--;
        }
        // Detiene el juego si hay un ganador.
        ganador = hay_ganador(fila_ini_bla, col_ini_bla, fila_ini_neg, col_ini_neg);
    }

    // Validando quien es el ganador
    if(turno == 1)
        printf("\n¡¡¡Ganan las negras!!!\n");
    else if (turno == 2)
        printf("\n¡¡¡Ganan las blancas!!!\n");
}

/* Definición de las funciones declaradas*/

    /* Funcion que le pide al cada usuario cual sera la ficha con la que van a jugar */
    void elegir_ficha(char* ficha_a_mover) {
        printf("Elige la ficha con la que deseas jugar: ");
        scanf(" %c", ficha_a_mover);
        while(!validar_ficha_a_mover(*ficha_a_mover)) {
            printf("Ooops... Esa ficha no es valida. Selecciona una ficha correcta: ");
            scanf(" %c", ficha_a_mover);
        }
    }
    
    /* Funcion que valida si la letra inicial de la ficha seleccionada concuerda con alguna de las fichas del juego. Devuelve true o false. */
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
        int posicion_invalida = 0;

        while(!validar_posicion(*fila, *columna)) {    
            if(posicion_invalida)
                printf("Ooops... Esa no es una posicion valida. El tablero es de %d filas y %d columnas.\n", FILAS, COLUMNAS);

            /* Seleccional el mensaje que vera el usuario. Si fila y columna == 0 entonces el juego apenas esta empezando... */
            if((*fila == 0) && (*columna == 0))
                printf("Elige la posicion inicial de tu ficha...\n");
            else
                printf("Ingresa la posicion a donde quieres mover tu ficha...\n"); 

            printf("Fila: ");
            scanf("%d", fila);
            printf("Columna: ");
            scanf("%d", columna);
            printf("\n");

            posicion_invalida++;
        }
    }

    /* Funcion que valida si la posicion de la ficha se encuentra dentro del tablero de 8 filas y 8 columnas. Devuelve true o false */
    bool validar_posicion(int fila, int columna) {
        return((fila >= 1 && fila <= 8) && (columna >= 1 && columna <= 8));
    }

    /* Funcion que calcula la cantidad de filas y columnas que se desplazara la ficha
    * Parametros que recibe:
    * 1. fila_ini = Fila inicial de la ficha a mover
    * 2. col_ini  = Columna inicial de la ficha a mover
    * 3. fila_fin = Fila final de la ficha a mover
    * 4. col_fin  = Columna final de la ficha a mover
    * 5. filas    = Puntero a la variable "desp_filas" para alojar resultado
    * 6. columnas = Puntero a la variable "desp_columnas" para alojar resultado */
    void movimiento_ficha(int fila_ini, int col_ini, int fila_fin, int col_fin, int* filas, int* columnas) {
        *filas = fabs(fila_fin - fila_ini);
        *columnas = fabs(col_fin - col_ini);
    }

    /* int validar_movimiento_ficha: Funcion que valida el movimiento de la ficha.
    * Parametros que recibe:
    * 1. filas = desp_filas
    * 2. columnas = desp_columnas
    * 3. ficha_a_mover */
    int validar_movimiento_ficha(int filas, int columnas, char ficha_a_mover) {
        // Validando Movimiento Diagonal
        if(((filas == 1 && columnas == 1) && (ficha_a_mover == REY)) ||
           ((filas == columnas) && (ficha_a_mover == REINA || ficha_a_mover == ALFIL)))
            return 1;
        // Validando Movimiento Vertical
        else if(((filas == 1 && columnas == 0) && (ficha_a_mover == PEON  || ficha_a_mover == REY)) ||
                ((filas >= 1 && columnas == 0) && (ficha_a_mover == REINA || ficha_a_mover == TORRE)))
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

    /* Esta funcion es la que maneja el turno de cada ficha, invocando las funciones que necesita para mover una ficha donde desee el usuario */
    void mover_ficha(char* ficha, int* fila_ini, int* col_ini, int* fila_fin, int* col_fin, int* filas, int* columnas) {

        preguntar_posicion(fila_fin, col_fin);
        movimiento_ficha(*fila_ini, *col_ini, *fila_fin, *col_fin, filas, columnas);
        
        while(!validar_movimiento_ficha(*filas, *columnas, *ficha)) {
            printf("Tu ficha NO se puede mover asi.\n"); 
            *fila_fin = -1;
            *col_fin = -1;
            preguntar_posicion(fila_fin, col_fin);
            movimiento_ficha(*fila_ini, *col_ini, *fila_fin, *col_fin, filas, columnas);
        }

        actualizar_posicion(fila_ini, col_ini, fila_fin, col_fin);
        printf("Tu ficha se movio exitosamente.\n");
    }

    /* Funcion que cambia los valores iniciales de fila y columna, confirmando que la ficha se movio exitosamente. */
    void actualizar_posicion(int* fila_ini, int* col_ini, int* fila_fin, int* col_fin) {
        *fila_ini = *fila_fin;
        *col_ini = *col_fin;
        *fila_fin = -1;
        *col_fin = -1;
    }

    /* Funcion que valida despues de cada turno si hay un ganador */
    bool hay_ganador(int fila_ini_bla, int col_ini_bla, int fila_ini_neg, int col_ini_neg) {
        return ((fila_ini_bla == fila_ini_neg) && (col_ini_bla == col_ini_neg));
    }