/**
 * Crear un programa que organice una batalla de piedra, papel y tijera. Para que sea completamente
 * justo, cada participante anota en un arreglo todas sus jugadas. Esto es, es un arreglo de
 * caracteres de 5 elementos donde cada elemento representa una jugada tienendo: (R)Rock (P)Papel y
 * (T)Tijera.
 * 
 * ParteB: Supongamos ahora que las reglas cambian, cada jugador puede elegir todas las jugadas que
 * quiere (no mas de 100), se llevara 1 punto el primero que gane 5 veces y ademas, se llevara
 * un punto extra si eligio menos jugadas que su rival. Crear un algoritmo que solicite las jugadas a
 * cada jugador y luego determine el ganador. Elegir las convenciones necesarias.
*/

#include <stdio.h>
#include <stdbool.h>

const char PIEDRA = 'R';
const char PAPEL  = 'P';
const char TIJERA = 'T';
const char SALIR  = 'S';
const int MAX_JUGADAS = 100;

void pedir_jugada(char jugador[], int* jugadas);
bool validar_jugada(char jugada);
void numero_victorias(char jugador_uno[], char jugador_dos[], int limite, int* puntaje_uno, 
    int* puntaje_dos, int jugadas_uno, int jugadas_dos);
void calcular_puntaje(int* puntaje, int jugadas_ganador_cinco, int jugadas_perdedor_cinco);
int quien_gana(int puntos_uno, int puntos_dos);


int main() {

    int puntos_uno = 0, puntos_dos = 0;
    int num_jugadas_uno = 0, num_jugadas_dos = 0;
    int ganador, numero_de_comparaciones;
    char jugador_uno[MAX_JUGADAS];
    char jugador_dos[MAX_JUGADAS];

    printf("Vamos a jugar Piedra, Papel y Tijera!\n");
    printf("-------------------------------------\n");

    printf("\nJugador Uno. Puedes Ingresar hasta 100 jugadas.\n");
    printf("Elige: (R)Piedra, (P)Papel, (T)Tijera, (S)Salir\n");
    pedir_jugada(jugador_uno, &num_jugadas_uno);
    printf("\n");

    printf("\nJugador Dos. Puedes Ingresar hasta 100 jugadas.\n");
    printf("Elige: (R)Piedra, (P)Papel, (T)Tijera, (S)Salir\n");
    pedir_jugada(jugador_dos, &num_jugadas_dos);
    printf("\n");

    if(num_jugadas_uno > num_jugadas_dos)
        numero_de_comparaciones = num_jugadas_dos;
    else
        numero_de_comparaciones = num_jugadas_uno;

    numero_victorias(
        jugador_uno,
        jugador_dos,
        numero_de_comparaciones,
        &puntos_uno,
        &puntos_dos,
        num_jugadas_uno,
        num_jugadas_dos
    );

    printf("Jugador Uno: %d - Jugador Dos: %d\n", puntos_uno, puntos_dos);
    (ganador = quien_gana(puntos_uno, puntos_dos)) ? 
        printf("Gana el Jugador No. %d\n", ganador) : 
        printf("Empate!\n");

    return 0;
}

// Definición de funciones declaradas

    /* Procedimiento que recibe una letra que debe concordar con alguna de las definidas en las 
    constantes. Asigna la letra a la posicion i del arreglo del jugador que llama la funcion. */
    void pedir_jugada(char jugador[], int* jugadas) {
        for(int i = 0; i < MAX_JUGADAS; i++) {
            printf("Jugada No. %d: ", i+1);
            scanf(" %c", &jugador[i]);
            while(!validar_jugada(jugador[i])) {
                printf("Jugada NO valida. Vuelve a intentarlo...  Jugada No. %d: ", i+1);
                scanf(" %c", &jugador[i]);
            }

            if(jugador[i] == SALIR) {
                jugador[i] = '\0';
                break;
            }

            *jugadas += 1;
        }
    }

    /* Funcion que valida que la letra ingresa sea valida para el algoritmo. Devuelve un booleano segun corresponda. */
    bool validar_jugada(char jugada) {
        return ((jugada == PIEDRA) || (jugada == PAPEL) || (jugada == TIJERA) || (jugada == SALIR));
    }

    /* Funcion que recibe los arreglos de jugadas de los dos jugadores y compara jugada a jugada para determinar a quien le asigna puntos. No devuelve ningun valor pero cada vez que un jugador obtiene 5 victorias, llama a la funcion que se encarga de calcular y asignar el puntaje. */
    void numero_victorias(char jugador_uno[], char jugador_dos[], int limite, int* puntos_uno, 
        int* puntos_dos, int jugadas_uno, int jugadas_dos) {

        int victorias_uno = 0;
        int victorias_dos = 0;

        for(int i = 0; i < limite; i++) {
            if((jugador_uno[i] == PIEDRA && jugador_dos[i] == TIJERA) ||
                (jugador_uno[i] == PAPEL && jugador_dos[i] == PIEDRA) ||
                (jugador_uno[i] == TIJERA && jugador_dos[i] == PAPEL)) {
                    victorias_uno += 1;
            }
            else if((jugador_dos[i] == PIEDRA && jugador_uno[i] == TIJERA) ||
                (jugador_dos[i] == PAPEL && jugador_uno[i] == PIEDRA) ||
                (jugador_dos[i] == TIJERA && jugador_uno[i] == PAPEL)) {
                    victorias_dos += 1;
            }

            if(victorias_uno == 5) {
                calcular_puntaje(puntos_uno, jugadas_uno, jugadas_dos);
                victorias_uno = 0;
                victorias_dos = 0;
            } else if(victorias_dos == 5) {
                calcular_puntaje(puntos_dos, jugadas_dos, jugadas_uno);
                victorias_uno = 0;
                victorias_dos = 0;
            }
        }  
    }   

    /* Funcion que calcula el puntaje de cada jugador. Recibe como parametros la variable donde se 
    almacenara el puntaje del jugador y el numero de jugadas que ingreso cada usuario. */
    void calcular_puntaje(int* puntaje, int jugadas_ganador_cinco, int jugadas_perdedor_cinco) {
        if(jugadas_ganador_cinco < jugadas_perdedor_cinco)
            *puntaje += 2;
        else 
            *puntaje += 1;
    }

    /* Funcion que compara los puntajes de los jugadores y devuelve 1 o 2 segun el ganador o 
    0 en caso de empate. */
    int quien_gana(int puntos_uno, int puntos_dos) {
        if(puntos_uno > puntos_dos)
            return 1;
        else if(puntos_uno < puntos_dos)
            return 2;
        else
            return 0;
    }  