# **Proyecto Final**

## Objetivo

La aplicacion busca mejorar la logistica de entrega de paquetes dandole al usuario la ruta mas corta teniendo en terminos de distancia. Todo esto con el fin de minimizar los costos por viaje y optimizar los tiempo de entrega.
La forma de lograr este objetivo es interpretando las calles como un grafo ponderado, donde un nodo representa la esquina de una calle, una arista la conexion de una calle con otra y la ponderacion de una arista la distancia entre calle a calle (nodo a nodo). Con esto en mente, la aplicacion aprovecha el algortimo Dijkstra para encontrar el camino mas rapido desde un punto inicial hasta uno final.
