# Ejercicio de Programacion en C
Este repositorio fue creado para almacenar los ejercicios que voy solucionando mientras aprendo a programar con el lenguaje de programacion C.

## Ejercicio 2 [(Solución)](https://github.com/andresjimenezdev/ejercicios-c/blob/master/02_partida_de_ajedrez.c)
Siguiendo con el ejercicio del ajedrez, se pide un programa que permita a dos jugadores iniciar una partida, pero con una sola ficha cada uno.

Para inicializar el tablero se deben pedir:
* Ficha blanca con la cual jugar (inicial).
* Ficha negra con la cual jugar (inicial).
* Pedir posición inicial (fila y columna) para la ficha blanca.
* Pedir posición inicial (fila y columna) para la ficha negra.

Y luego de inicializarlo, empezar el juego:
* Pedir y realizar movimiento de la ficha blanca.
* Pedir y realizar movimiento de la ficha negra.

## Ejercicio 1 [(Solución)](https://github.com/andresjimenezdev/ejercicios-c/blob/master/01_piezas_de_ajedrez.c)
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