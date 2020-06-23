# Ejercicio de Programacion en C
Este repositorio fue creado para almacenar los ejercicios que voy solucionando mientras aprendo a programar con el lenguaje de programacion C.

## Ejercicio 5 - [(Solución Parte A)](https://github.com/andresjimenezdev/ejercicios-c/blob/master/05_batalla_naval.c)
Crear un programa que represente una partida del famoso juego de mesa "Batalla Naval". Para esto, se crearan algunas funciones que ayuden al desarrollo del juego.

La matriz recibida tendra **~** en las coordenadas donde haya agua, **B** en las coordenadas donde haya un barquito, **X** en las coordenadas donde se haya disparado al agua y **T** en las coordenadas donde se haya tocado a un barco.

En resumen, el programa debe:

* Crear un procedimiento que reciba una matriz de caracteres, las coordenas del disparo y con esta informacion actualizar la matriz, poniendo una **X** si el disparo fue al agua o una **T** si el disparo toco un barco.
* Crear un procedimiento que permita a un usuario cargar barquitos en el tablero.
* Crear una funcion que reciba una matriz representando a un tablero y devuelva true si se ha ganado la partida.

## Ejercicio 4 - [(Solución Parte A)](https://github.com/andresjimenezdev/ejercicios-c/blob/master/04_piedra_papel_tijera_A.c) [(Solución Parte B)](https://github.com/andresjimenezdev/ejercicios-c/blob/master/04_piedra_papel_tijera_B.c)
### Conocimientos previos = Estructuras de control, Tipos de dato simples, Modularización, Arreglos
Crear un programa que organice una batalla de piedra, papel y tijera.
Para que sea completamente justo, cada participante anota en un arreglo todas sus jugadas. Esto es, es un arreglo de caracteres de 5 elementos donde cada elemento representa una jugada tienendo: **R**ock **P**apel y **T**ijera.

* **Parte A**: Se pide hacer una funcion que, dados dos arreglos, devuelva **1** si el jugador 1 es el ganador, **2** si el jugador 2 es el ganador o **0** si hay empate.
* **Parte B**: Supongamos ahora que las reglas cambian, cada jugador puede elegir todas las jugadas que quiere (no mas de 100), se llevara **1** punto el primero que gane **5** veces y ademas, se llevara un punto extra si eligio menos jugadas que su rival. Crear un algoritmo que solicite las jugadas a cada jugador y luego determine el ganador. Elegir las convenciones necesarias.

## Ejercicio 3 - [(Solución)](https://github.com/andresjimenezdev/ejercicios-c/blob/master/03_las_dos_torres_parte_uno.c)
### Conocimientos previos = Estructuras de control, Tipos de dato simples, Modularización
Crear un programa que represente la épica batalla del Abismo de Helm, en esta primera parte, debe determinar el porcentaje de humedad en el ambiente, la velocidad del viento y el estado de ánimo de Legolas y Gimli.

Para ello se le harán ciertas preguntas al usuario y, dependiendo de los valores ingresados, se determinarán los datos antes mencionados.

Legolas tendrá a su disposición para luchar a los Elfos, quienes tendrán un porcentaje de error en sus disparos, el cual está ligado a la velocidad del viento, mientras que Gimli posee a los Enanos, cuyos golpes se verán afectados por la humedad.

Tanto el ánimo de Legolas como el de Gimli podrá ser Bueno, Regular o Malo, y como grandes líderes que son, esto afectará a los elfos (si se trata del ánimo de Legolas) o a los enanos (si se trata del ánimo de Gimli).

**Preguntas a realizar al usuario:**
* Día del mes: Un número entre 1 y 30 (ambos inclusive).
* Hora del día: Mañana (M), Tarde (T), Noche (N).
* Ánimo del personaje (Legolas/Gimli):
    * Pie con el que se levantó: Derecho (D), Izquierdo (I).
    * Cena de la noche anterior: Ensalada (E), Hamburguesa (H), Pizza (P), Guiso (G).
    * Cantidad de horas que durmió: Un número entre 0 y 12 (ambos inclusive).

Cabe destacar que las últimas tres se deben realizar para cada uno de los personajes (Legolas y Gimli).
Cualquiera de estos datos que no esté dentro del rango definido debe ser solicitado nuevamente. No se podrá avanzar a la próxima pregunta sin antes cumplir con las condiciones establecidas.

**Determinación de la velocidad del viento:**
* Entre el día 1 y 10 (ambos inclusive): 75 km/h.
* Entre 11 y 20 (ambos inclusive): 50 km/h.
* Entre 21 y 30 (ambos inclusive): 25 km/h.

**Determinación de la humedad:**
* Mañana: 75 % de humedad.
* Tarde: 25 % de humedad.
* Noche: 50 % de humedad.

**Determinación del ánimo:**
Según el pie con el que se levantó, el pie derecho le dará 10 puntos, mientras que el izquierdo le dará 0 puntos.
Dependiendo la cena, la ensalada tendrá un valor de 20 puntos, las hamburguesas 15 puntos, la pizza 10 puntos, y el guiso 5 puntos.
Según las horas que durmió, de 0 a 4 horas (ambos inclusive), serán 0 puntos. De 5 a 8 (ambos inclusive) horas, 10 puntos. Y más de 8 horas, 20 puntos.

El resultado final obtenido, definirá el ánimo buscado:
* Entre 5 y 20 (ambos inclusive): El ánimo será malo (M).
* Entre 21 y 35 (ambos inclusive): El ánimo será regular (R).
* Entre 36 y 50 (ambos inclusive): El ánimo será bueno (B).

Luego que pueda ser ejecutado realizando las preguntas correspondientes y, por último, deberá 
mostrarse por pantalla un mensaje que contenga todos los datos obtenidos.

```c
Resumen: 75 50 B R
```

## Ejercicio 2 - [(Solución)](https://github.com/andresjimenezdev/ejercicios-c/blob/master/02_partida_de_ajedrez.c)
### Conocimientos previos = Estructuras de control, Tipos de dato simples, Modularización
Siguiendo con el ejercicio del ajedrez, se pide un programa que permita a dos jugadores iniciar una partida, pero con una sola ficha cada uno.

Para inicializar el tablero se deben pedir:
* Ficha blanca con la cual jugar (inicial).
* Ficha negra con la cual jugar (inicial).
* Pedir posición inicial (fila y columna) para la ficha blanca.
* Pedir posición inicial (fila y columna) para la ficha negra.

Y luego de inicializarlo, empezar el juego:
* Pedir y realizar movimiento de la ficha blanca.
* Pedir y realizar movimiento de la ficha negra.

## Ejercicio 1 - [(Solución)](https://github.com/andresjimenezdev/ejercicios-c/blob/master/01_piezas_de_ajedrez.c)
### Conocimientos previos = Estructuras de control, Tipos de dato simples, Modularización
El ajedrez es un juego milenario, tiene 6 tipos de fichas distintas. Cada una de ellas tiene movimientos particulares dependiendo del tipo que son:
* Los peones se mueven una casilla a la vez y solo hacia adelante.
* Las torres se mueven vertical u horizontalmente, la cantidad de casillas que se quiera.
* Los alfiles se mueven diagonal, la cantidad de casillas que se quiera.
* Los caballos en forma de "L", una casilla hacia adelante y 2 a uno de los costados.
* La reina, en cualquier dirección, la cantidad de casillas que se quiera.
* El rey, en cualquier dirección, solo una casilla.

Teniendo en cuenta que el tablero tiene 8 filas y 8 columnas y que las piezas no pueden moverse fuera del tablero.

Crear un programa que le pida al usuario:
* Letra inicial de la ficha que quiere mover.
* Posición inicial (fila y columna).
* Posición final (fila y columna).
* Determinar si el movimiento es valido.