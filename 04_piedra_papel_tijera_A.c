/**
 * Crear un programa que organice una batalla de piedra, papel y tijera. Para que sea completamente
 * justo, cada participante anota en un arreglo todas sus jugadas. Esto es, es un arreglo de
 * caracteres de 5 elementos donde cada elemento representa una jugada tienendo: (R)Rock (P)Papel y
 * (T)Tijera.
 * ParteA: Se pide hacer una funcion que, dados dos arreglos, devuelva 1 si el jugador 1 es el ganador
 * 2 si el jugador 2 es el ganador o 0 si hay empate. 
*/

#include <stdio.h>
#include <stdbool.h>

const char PIEDRA = 'R';
const char PAPEL  = 'P';
const char TIJERA = 'T';
const int MAX_JUGADAS = 5;

void pedir_jugada(char jugador[]);
bool validar_jugada(char jugada);
int quien_gana(char jugador_uno[], char jugador_dos[], int* puntos_uno, int* puntos_dos);


int main() {

    int puntos_uno = 0;
    int puntos_dos = 0;
    int ganador;
    char jugador_uno[MAX_JUGADAS];
    char jugador_dos[MAX_JUGADAS];

    printf("Vamos a jugar Piedra, Papel y Tijera!\n");
    printf("-------------------------------------\n");

    printf("\nJugador Uno. Ingresa tus 5 jugadas. (R)Piedra, (P)Papel, (T)Tijera\n");
    pedir_jugada(jugador_uno);
    printf("\n");

    printf("\nJugador Dos. Ingresa tus 5 jugadas. (R)Piedra, (P)Papel, (T)Tijera\n");
    pedir_jugada(jugador_dos);
    printf("\n");

    ganador = quien_gana(
        jugador_uno,
        jugador_dos,
        &puntos_uno,
        &puntos_dos
    );

    if(ganador)
        printf("Gana el Jugador No. %d\n", ganador);
    else
        printf("Empate!\n");

    return 0;
}

// Definición de funciones declaradas

    /* Procedimiento que recibe una letra que debe concordar con alguna de las definidas en las 
    constantes. Asigna la letra a la posicion i del arreglo del jugador que llama la funcion. */
    void pedir_jugada(char jugador[]) {
        for(int i = 0; i < MAX_JUGADAS; i++) {
            printf("Jugada No. %d: ", i+1);
            scanf(" %c", &jugador[i]);
            while(!validar_jugada(jugador[i])) {
                printf("Jugada NO valida. Vuelve a intentarlo...  Jugada No. %d: ", i+1);
                scanf(" %c", &jugador[i]);
            }
        }
    }

    /* Funcion que valida que la letra ingresa sea valida para el algoritmo. Devuelve un booleano segun corresponda. */
    bool validar_jugada(char jugada) {
        return ((jugada == PIEDRA) || (jugada == PAPEL) || (jugada == TIJERA));
    }

    /* Funcion que recibe los arreglos de jugadas de los dos jugadores y compara jugada a jugada a 
    quien le asigna puntos. Compara los puntajes de los jugadores y devuelve 1 o 2 segun el ganador o 
    0 en caso de empate. */
    int quien_gana(char jugador_uno[], char jugador_dos[], int* puntos_uno, int* puntos_dos) {
        for(int i = 0; i < MAX_JUGADAS; i++) {
            if((jugador_uno[i] == PIEDRA && jugador_dos[i] == TIJERA) ||
                (jugador_uno[i] == PAPEL && jugador_dos[i] == PIEDRA) ||
                (jugador_uno[i] == TIJERA && jugador_dos[i] == PAPEL)) {
                    *puntos_uno += 1;
            }
            else if((jugador_dos[i] == PIEDRA && jugador_uno[i] == TIJERA) ||
                (jugador_dos[i] == PAPEL && jugador_uno[i] == PIEDRA) ||
                (jugador_dos[i] == TIJERA && jugador_uno[i] == PAPEL)) {
                    *puntos_dos += 1;
            }
        }

        if(*puntos_uno > *puntos_dos)
            return 1;
        else if(*puntos_uno < *puntos_dos)
            return 2;
        else
            return 0;
    }   