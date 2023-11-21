//Nome: Gabriel de Souza Muniz 
//RA: 2475430

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6 // Número de vértices no grafo

int encontrarMenorDistancia(int dist[], bool sptSet[]) {
    int min = INT_MAX, indice_minimo;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], indice_minimo = v;

    return indice_minimo;
}

void mostrarSolucao(int dist[]) {
    printf("Vértice \t Distância do vértice inicial\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V]; 
    bool sptSet[V]; 

    
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = encontrarMenorDistancia(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    mostrarSolucao(dist);
}

int main() {
    int graph[V][V] = {{0, 1, 4, 0, 0, 0},
                       {1, 0, 4, 2, 7, 0},
                       {4, 4, 0, 3, 5, 0},
                       {0, 2, 3, 0, 4, 6},
                       {0, 7, 5, 4, 0, 7},
                       {0, 0, 0, 6, 7, 0}
                      };
    int origem = 0;
    dijkstra(graph, origem);

    return 0;
}