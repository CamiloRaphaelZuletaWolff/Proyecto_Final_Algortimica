#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
vector<pair<int,int>> rutas [50];
const int INF = numeric_limits<int>::max();
vector<int> dist(50, INF);
vector<int> antecesor(50, -1);


void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, start)); 
    dist[start] = 0;
    while (!pq.empty()) {
        int current_node = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();
        if (current_distance > dist[current_node]) {
            continue;}
        for (int i = 0; i < rutas[current_node].size(); i++) {
            int next_node = rutas[current_node][i].second;
            int weight = rutas[current_node][i].first;
            int next_distance = current_distance + weight;
            if (next_distance < dist[next_node]) {
                antecesor[next_node] = current_node; 
                dist[next_node] = next_distance;
                pq.push(make_pair(next_distance, next_node));
                
            }
        }
    }
}


void conexiones(){
    rutas[0] = {make_pair(3,1), make_pair(5,2), make_pair(5,6), make_pair(9,8)};
    rutas[1] = {make_pair(3,3), make_pair(3,5)};
    rutas[2] = {make_pair(5,4), make_pair(3,8)};
    rutas[3] = {make_pair(3,1), make_pair(4,2)};
    rutas[4] = {make_pair(4,3), make_pair(4,7), make_pair(3,8)};
    rutas[5] = {make_pair(5,6), make_pair(3,7)};
    rutas[6] = {make_pair(5,0), make_pair(5,5)};
    rutas[7] = {make_pair(4,4), make_pair(3,5)};
    rutas[8] = {make_pair(3,4), make_pair(9,0)};
}

void siguienteMenu(int posicionInicial, int posicionFinal){
    std::cout << "¿Que deseas hacer ahora?" << std::endl;
    std::cout << "1. Terminar" << std::endl;
    std::cout << "2. Volver al menu" << std::endl;
    int eleccion = 0;
    cin>>eleccion;
    switch(eleccion){
        case 1:{
            exit(0);
            break;}
        case 2:{
            cout << "\033[2J\033[1;1H";
            break;
        }
    }
}


void abrirMenu(int posicionInicial, int posicionFinal){
    int eleccion;
    do{
        cout << "Selecciona que accion deseas realizar "<<endl;
        cout << "1. Distancia minima desde tu posicion hasta tu destino"<<endl;
        cout << "2. Ruta ideal hasta tu destino"<<endl;
        cout << "3. Ruta ideal y distancia minima a tu destino"<<endl;
        std::cout << "4. Dibujar ruta cargada" << std::endl;
        cin >> eleccion;
        switch(eleccion){
            case 1:{
            cout<<"La distancia minima hasta tu destino es de: "<< dist[posicionFinal]<<endl;
            siguienteMenu(posicionInicial,posicionFinal);
            break;}
            case 2:{
            cout<<"La ruta ideal hasta tu destino es: ";
            int i = posicionFinal;
            vector<int> rutaIdeal;
            while (antecesor[i]!=-1){
                rutaIdeal.push_back(antecesor[i]);
                i=antecesor[i];
                
            }for (int j = rutaIdeal.size() - 1; j >= 0; --j) {
                cout << rutaIdeal[j]<<" ";
            }
            std::cout << std::endl;
            siguienteMenu(posicionInicial,posicionFinal);
            break;}
            case 3:{
            cout<<"La distancia minima hasta tu destino es de: "<< dist[posicionFinal]<<endl;
            cout<<"La ruta ideal hasta tu destino es: ";
            int i = posicionFinal;
            vector<int> rutaIdeal;
            while (antecesor[i]!=-1){
                rutaIdeal.push_back(antecesor[i]);
                i=antecesor[i];
                
            }for (int j = rutaIdeal.size() - 1; j >= 0; --j) {
                cout << rutaIdeal[j] << " ";
            }
            std::cout << std::endl;
            siguienteMenu(posicionInicial,posicionFinal);
            break;}
            
            
            
            
        }
        
        
    }while(eleccion!=5);

}


int main(){
    conexiones();
    std::cout << "----- Bienvenido al sistema de optimizacion de rutas de trabajo ----- " << std::endl;
    //dibujarGrafo();  Que salga en la consola la ruta que esta cargada
    std::cout << "Introduzca su posicion actual" << std::endl;
    int posicionInicial, posicionFinal;
    cin >> posicionInicial;
    std::cout << "Introduzca su destino" << std::endl;
    cin>>posicionFinal;
    dijkstra(posicionInicial);
    abrirMenu(posicionInicial, posicionFinal);



    return 0;
}
