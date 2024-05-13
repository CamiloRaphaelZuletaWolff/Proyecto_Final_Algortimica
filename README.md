# **Proyecto Final**

## Objetivo

La aplicacion busca mejorar la logistica de entrega de paquetes dandole al usuario la ruta mas corta teniendo en terminos de distancia. Todo esto con el fin de minimizar los costos por viaje y optimizar los tiempo de entrega.

La forma de lograr este objetivo es interpretando las calles como un grafo ponderado, donde un nodo representa la esquina de una calle, una arista la conexion de una calle con otra y la ponderacion de una arista la distancia entre calle a calle (nodo a nodo). Con esto en mente, la aplicacion aprovecha el algortimo Dijkstra para encontrar el camino mas rapido desde un punto inicial hasta uno final.

## ¿Como funciona?

Para utilizar correctamente la aplicacion primero se debe establecer el grafo que representa las calles por donde se repartira el paquete. Dicha accion puede ser realizada en 'conexiones' donde se inicializa los valores del grafo a ser tratado.

Una vez ejecuatada la aplicacion se introduce el nodo en el que el usuario se encuentra y posterior a ello a que nodo desea ir. Despues se decide que requiere el usuario, si la distancia minima hasta el lugar(opcion 1), la mejor ruta posible(opcion 2) o ambas cosas(opcion 3).

## Requisitos

El proyecto esta escrito en c++ en su totalidad por lo que es esencial tener un compilador de este lenguaje, se sugiere el uso de visual code. 
