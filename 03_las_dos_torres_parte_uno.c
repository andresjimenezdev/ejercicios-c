/** 
 * 03_las_dos_torres_parte_uno.c
 * ------------------------------
 * 
 * Este ejrcicio busca representar la épica batalla del Abismo de Helm, en esta primera etapa debes,
 * determinar el porcentaje de humedad en el ambiente, la velocidad del viento y el estado de ánimo de 
 * Legolas y Gimli.
 * 
 * Tanto el ánimo de Legolas como el de Gimli podrá ser Bueno, Regular o Malo, y como grandes líderes 
 * que son, esto afectará a los elfos (si se trata del ánimo de Legolas) o a los enanos (si se trata 
 * del ánimo de Gimli).
 * 
 * Preguntas a realizar al usuario:
 * * Día del mes: Un número entre 1 y 30 (ambos inclusive).
 * * Hora del día: Mañana (M), Tarde (T), Noche (N).
 * * Ánimo del personaje:
 *   * Pie con el que se levantó: Derecho (D), Izquierdo (I).
 *   * Cena de la noche anterior: Ensalada (E), Hamburguesa (H), Pizza (P), Guiso (G).
 *   * Cantidad de horas que durmió: Un número entre 0 y 12 (ambos inclusive).
*/

#include <stdio.h>
#include <stdbool.h>

/* Declaración de constantes necesarias para la ejecucion del programa*/
const int INTERVALO_DIAS_MES = 10, MIN_DIAS_MES = 1, MAX_DIAS_MES = 30;
const int INTERVALO_HORAS_SUENIO = 4, MIN_HORAS_SUENIO = 0, MAX_HORAS_SUENIO = 12; 
const int INTERVALO_PUNTOS_ANIMO = 15, MIN_PUNTOS_ANIMO = 5, MAX_PUNTOS_ANIMO = 50;
const char TARDE = 'T', NOCHE = 'N', MANIANA = 'M';
const char PIE_IZQ = 'I', PIE_DER = 'D';
const char GUIZO = 'G', PIZZA = 'P', HAMBURG = 'H', ENSALADA = 'E';

/* Declaración de constantes para los puntajes */
const int INTERVALO_VELOCIDAD_VIENTO = 25;
const int INTERVALO_HUMEDAD_DIA = 25;
const int INTERVALO_PUNTOS_SUENIO = 10;
const int INTERVALO_PUNTOS_PIE = 10;
const int INTERVALO_PUNTOS_CENA = 5;


/* Declaración de funciones */

void pedir_numero(int* numero, int min, int max);
bool numero_valido(int numero, int min, int max);
void pedir_letra(char* letra);
bool letra_valida(char letra);
int puntaje_letra(char letra, int intervalo_de_puntos);
int velocidad_del_viento(int numero, int interv_dias, int min, int max, int interv_velocidad);
int puntaje_suenio(int numero, int interv_horas, int min, int max, int interv_puntos);
char animo_personaje(char* pie, char* cena, int* horas_de_suenio, int min, int max, int intervalo);

int main() {

    int dia_mes, velocidad_viento, humedad, horas_de_suenio;
    char hora_del_dia, pie, cena, animo_legolas, animo_gimli;

    printf("\nLa epica batalla del Abismo de Helm esta por comenzar.\n");
    printf("------------------------------------------------------\n\n");

    /* Calculando la velocidad del viento segun el dia del mes */
    printf("¿Podrias recordarme que dia del mes es hoy? (entre 1 y 30): ");
    pedir_numero(&dia_mes, MIN_DIAS_MES, MAX_DIAS_MES);
    velocidad_viento = velocidad_del_viento(
        dia_mes,
        INTERVALO_DIAS_MES,
        MIN_DIAS_MES,
        MAX_DIAS_MES,
        INTERVALO_VELOCIDAD_VIENTO
    );
    printf("Velocidad del viento: %d Km/h\n", velocidad_viento);

    /* Calculando la humedad segun la hora del dia */
    printf("\nInteresante... ¿A que hora del dia crees que inicie la batalla?\n");
    printf("Elige: (M)Mañana, (T)Tarde, (N)Noche: ");
    pedir_letra(&hora_del_dia);
    humedad = puntaje_letra(hora_del_dia, INTERVALO_HUMEDAD_DIA);
    printf("Humedad: %d%%\n", humedad);

    /* Calculando el animo de legolas */
    printf("\nVeamos como esta el animo de Legolas.\n");
    printf("-------------------------------------\n");    
    animo_legolas = animo_personaje(
        &pie,
        &cena,
        &horas_de_suenio,
        MIN_PUNTOS_ANIMO,
        MAX_PUNTOS_ANIMO,
        INTERVALO_PUNTOS_ANIMO
    );

    /* Calculando el animo de Gimli */
    printf("\nVeamos como esta el animo de Gimli.\n");
    printf("-------------------------------------\n");    
    animo_gimli = animo_personaje(
        &pie,
        &cena,
        &horas_de_suenio,
        MIN_PUNTOS_ANIMO,
        MAX_PUNTOS_ANIMO,
        INTERVALO_PUNTOS_ANIMO
    );

    /* Mostrando los resultados del algoritmo */
    printf("%d %d %c %c\n", velocidad_viento, humedad, animo_legolas, animo_gimli);

    return 0;
}


/* Procedimiento que recibe un numero entero que debe estar entre un rango de numeros. Asigna el
numero a la variable recibida como parametro, y no devuelve nada. */
void pedir_numero(int* numero, int min, int max) {
    scanf("%d", numero);
    while(!(numero_valido(*numero, min, max))) {
        printf("Lo siento, esa no es una opcion valida. Vuelve a intentarlo: ");
        scanf("%d", numero);
    }
}

/* Funcion que valida que el numero digitado por el usuario, se encuentre dentro del rango. Devuelve 
un booleano segun corresponda. */
bool numero_valido(int numero, int min, int max) {
    return (numero >= min && numero <= max);
}

/* Procedimiento que recibe una letra que debe concordar con alguna de las definidas en las 
constantes. Asigna la letra a la variable recibida como parametro, y no devuelve nada. */
void pedir_letra(char* letra) {
    scanf(" %c", letra);
    while(!(letra_valida(*letra))) {
        printf("Lo siento, esa no es una opcion valida. Vuelve a intentarlo: ");
        scanf(" %c", letra);
    }
}

/* Funcion que valida que la letra ingresa sea valida para el algoritmo. Devuelve un booleano segun 
corresponda. */
bool letra_valida(char letra) {
    if(letra == TARDE || letra == NOCHE || letra == MANIANA) 
        return true;
    else if(letra == PIE_IZQ || letra == PIE_DER)
        return true;
    else if(letra == GUIZO || letra == PIZZA || letra == HAMBURG || letra == ENSALADA)
        return true;
    else
        return false;
}

/* Funcion que asigna un puntaje a cada letra valida segun su uso. Las letras del primer IF 
representan los primeros valores de cada seccion, el segundo IF los segundos valores y asi 
sucesivamente. El return 0 pertenece al pie izquierdo ya que este NO otorga puntaje. Devuelve un 
numero entero con el puntaje onbtenido. */
int puntaje_letra(char letra, int intervalo_de_puntos) {
    if(letra == TARDE || letra == PIE_DER || letra == GUIZO)
        return intervalo_de_puntos;
    else if(letra == NOCHE || letra == PIZZA)
        return intervalo_de_puntos * 2;
    else if(letra == MANIANA || letra == HAMBURG)
        return intervalo_de_puntos * 3;
    else if(letra == ENSALADA)
        return intervalo_de_puntos * 4;
    else
        // PIE_IZQ = 0 puntos
        return 0;
}

/* Funcion que calcula la velocidad del viento segun el dia del mes ingresado por el usuario. Devuelve 
un numero entero con el puntaje onbtenido. */
int velocidad_del_viento(int numero, int interv_dias, int min, int max, int interv_velocidad) {
    if((numero >= min) && (numero <= interv_dias))
        return interv_velocidad * 3;
    else if((numero >= (interv_dias+1)) && (numero <= (interv_dias*2)))
        return interv_velocidad * 2;
    else if((numero >= (interv_dias*2+1)) && (numero <= max))
        return interv_velocidad;
    else
        return 0;
}

/* Funcion que calcula el puntaje segun las horas de sueño de cada personaje. Devuelve un numero 
entero con el puntaje onbtenido. */
int puntaje_suenio(int numero, int interv_horas, int min, int max, int interv_puntos) {
    if((numero >= min) && (numero <= interv_horas))
        return 0;
    else if((numero >= (interv_horas+1)) && (numero <= (interv_horas*2)))
        return interv_puntos;
    else if((numero >= (interv_horas*2+1)) && (numero <= max))
        return interv_puntos * 2;
    else
        return 0;
}

/* Funcion que calcula el animo del cada personaje. Pide todos los datos necesarios para el calculo y 
devuelve un letra con el resultado. */
char animo_personaje(char* pie, char* cena, int* horas_de_suenio, int min, int max, int intervalo) {
    int puntaje = 0;

    /* Calculando puntaje segun el pie con el que se levanto */    
    printf("¿Con cual pie se levanto? Elige: (I)Izquierdo, (D)Derecho: ");
    pedir_letra(pie);
    puntaje += puntaje_letra(*pie, INTERVALO_PUNTOS_PIE);

    /* Calculando puntaje segun la cena de la noche anterior */
    printf("¿Que comio la noche anterior? Elige: (E)Ensalada, (H)Hamburguesas, (P)Pizza, (G)Guizo: ");
    pedir_letra(cena);
    puntaje += puntaje_letra(*cena, INTERVALO_PUNTOS_CENA);

    /* Calculando puntaje segun las horas de sueño de la noche anterior */
    printf("¿Cuantas horas durmio la noche anterior? (entre 0 y 12): ");
    pedir_numero(horas_de_suenio, MIN_HORAS_SUENIO, MAX_HORAS_SUENIO);
    puntaje += puntaje_suenio(
        *horas_de_suenio,
        INTERVALO_HORAS_SUENIO,
        MIN_HORAS_SUENIO,
        MAX_HORAS_SUENIO,
        INTERVALO_PUNTOS_SUENIO
    );

    printf("\n");

    if((puntaje >= min) && (puntaje <= intervalo + min))
        return 'M';
    else if((puntaje >= (intervalo+min) + 1) && (puntaje <= (max - intervalo)))
        return 'R';
    else 
        return 'B';
}