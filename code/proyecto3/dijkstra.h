#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include "utils.h"

#define MAX_NODES 30
#define INF 999999.99
#define BUFFER_SIZE 50

int i, j, v;
int count;

const char *nodes[MAX_NODES] = {
    "UMAR", "B.J", "OXXOCH", "PEMEXBAC", "BODPEPSI", "PXM", "COLORADA", "BACOCHO",
    "PLAYACORAL", "CAFECITO", "AGENCIAMPL", "SANTANDER", "CHEDRAUI", "CONALEP",
    "KOREZ", "IMMS", "COPPEL", "HANGELMAR", "PLAYAPRINC", "CARACOLPLZ", "BBVA",
    "ZICATELA", "OXXOLAZ", "MERCADOZIC", "SUPER71", "PUNTAZIC", "CFE"
};

int findNodeIndex(const char *name) {
	int i;
    for ( i = 0; i < MAX_NODES; i++) {
        if (strcmp(nodes[i], name) == 0) {
            return i;
        }
    }
    return -1; // No encontrado
}

void dijkstra(double graph[MAX_NODES][MAX_NODES], int start_node, int target_node) {
    double distance[MAX_NODES];
    int parent[MAX_NODES];
    bool visited[MAX_NODES];

    // Inicializar distancias y padres
    for (i = 0; i < MAX_NODES; i++) {
        distance[i] = graph[start_node][i];
        parent[i] = start_node;
        visited[i] = false;
    }

    visited[start_node] = true;

    while (!visited[target_node]) {
        double min_distance = INF;
        int min_index = -1;

        for (v = 0; v < MAX_NODES; v++) {
            if (!visited[v] && distance[v] <= min_distance) {
                min_distance = distance[v];
                min_index = v;
            }
        }

        if (min_index == -1) break; // No hay más nodos accesibles

        visited[min_index] = true;

        for (v = 0; v < MAX_NODES; v++) {
            if (!visited[v] && graph[min_index][v] != INF &&
                distance[min_index] + graph[min_index][v] < distance[v]) {
                distance[v] = distance[min_index] + graph[min_index][v];
                parent[v] = min_index;
            }
        }

        if (visited[target_node]) {
            break;
        }
    }

    if (distance[target_node] == INF) {
    	gotoxy(20, 12); printf("No hay camino desde %s a %s.\n", nodes[start_node], nodes[target_node]);
    } else {
    	gotoxy(20, 12);printf("Camino desde %s a %s:\n", nodes[start_node], nodes[target_node]);
        int path[MAX_NODES];
        int path_length = 0;

        int current_node = target_node;
        while (current_node != start_node) {
            path[path_length++] = current_node;
            current_node = parent[current_node];
        }
        path[path_length++] = start_node;

    	gotoxy(20, 13);printf("Camino: ");
        for (j = path_length - 1; j >= 0; j--) {
            printf("%s", nodes[path[j]]);
            if (j > 0) {
                printf(" -> ");
            }
        }
    	gotoxy(20, 14);printf("Peso: %.2f\n", distance[target_node]);
    }
}

void calcularRutas(double graph[MAX_NODES][MAX_NODES]) {
	// Establecer las conexiones según los datos proporcionados
	graph[findNodeIndex("UMAR")][findNodeIndex("B.J")] = 1713.7;
	graph[findNodeIndex("B.J")][findNodeIndex("UMAR")] = 1713.7; // Conexión bidireccional
	graph[findNodeIndex("B.J")][findNodeIndex("OXXOCH")] = 498.78;
	graph[findNodeIndex("OXXOCH")][findNodeIndex("B.J")] = 498.78; // Conexión bidireccional
	graph[findNodeIndex("OXXOCH")][findNodeIndex("PEMEXBAC")] = 366.3;
	graph[findNodeIndex("PEMEXBAC")][findNodeIndex("OXXOCH")] = 366.3; // Conexión bidireccional
	graph[findNodeIndex("PEMEXBAC")][findNodeIndex("BODPEPSI")] = 811.26;
	graph[findNodeIndex("BODPEPSI")][findNodeIndex("PEMEXBAC")] = 811.26; // Conexión bidireccional
	graph[findNodeIndex("BODPEPSI")][findNodeIndex("PXM")] = 918.67;
	graph[findNodeIndex("PXM")][findNodeIndex("BODPEPSI")] = 918.67; // Conexión bidireccional
	graph[findNodeIndex("PXM")][findNodeIndex("COLORADA")] = 1331.92;
	graph[findNodeIndex("COLORADA")][findNodeIndex("PXM")] = 1331.92; // Conexión bidireccional
	graph[findNodeIndex("PEMEXBAC")][findNodeIndex("BACOCHO")] = 1618.01;
	graph[findNodeIndex("BACOCHO")][findNodeIndex("PEMEXBAC")] = 1618.01; // Conexión bidireccional
	graph[findNodeIndex("BODPEPSI")][findNodeIndex("BACOCHO")] = 1360.07;
	graph[findNodeIndex("BACOCHO")][findNodeIndex("BODPEPSI")] = 1360.07; // Conexión bidireccional
	graph[findNodeIndex("BODPEPSI")][findNodeIndex("PLAYACORAL")] = 1251.83;
	graph[findNodeIndex("PLAYACORAL")][findNodeIndex("BODPEPSI")] = 1251.83; // Conexión bidireccional
	graph[findNodeIndex("BACOCHO")][findNodeIndex("PLAYACORAL")] = 1162.71;
	graph[findNodeIndex("PLAYACORAL")][findNodeIndex("BACOCHO")] = 1162.71; // Conexión bidireccional
	graph[findNodeIndex("PLAYACORAL")][findNodeIndex("CAFECITO")] = 861.13;
	graph[findNodeIndex("CAFECITO")][findNodeIndex("PLAYACORAL")] = 861.13; // Conexión bidireccional
	graph[findNodeIndex("PEMEXBAC")][findNodeIndex("CAFECITO")] = 1126.22;
	graph[findNodeIndex("CAFECITO")][findNodeIndex("PEMEXBAC")] = 1126.22; // Conexión bidireccional
	graph[findNodeIndex("CAFECITO")][findNodeIndex("AGENCIAMPL")] = 806.28;
	graph[findNodeIndex("AGENCIAMPL")][findNodeIndex("CAFECITO")] = 806.28; // Conexión bidireccional
	graph[findNodeIndex("PEMEXBAC")][findNodeIndex("SANTANDER")] = 623.63;
	graph[findNodeIndex("SANTANDER")][findNodeIndex("PEMEXBAC")] = 623.63; // Conexión bidireccional
	graph[findNodeIndex("SANTANDER")][findNodeIndex("AGENCIAMPL")] = 528.52;
	graph[findNodeIndex("AGENCIAMPL")][findNodeIndex("SANTANDER")] = 528.52; // Conexión bidireccional
	graph[findNodeIndex("AGENCIAMPL")][findNodeIndex("CHEDRAUI")] = 549.95;
	graph[findNodeIndex("CHEDRAUI")][findNodeIndex("AGENCIAMPL")] = 549.95; // Conexión bidireccional
	graph[findNodeIndex("B.J")][findNodeIndex("CONALEP")] = 553.26;
	graph[findNodeIndex("CONALEP")][findNodeIndex("B.J")] = 553.26; // Conexión bidireccional
	graph[findNodeIndex("CONALEP")][findNodeIndex("KOREZ")] = 471.87;
	graph[findNodeIndex("KOREZ")][findNodeIndex("CONALEP")] = 471.87; // Conexión bidireccional
	graph[findNodeIndex("KOREZ")][findNodeIndex("IMMS")] = 184.9;
	graph[findNodeIndex("IMMS")][findNodeIndex("KOREZ")] = 184.9; // Conexión bidireccional
	graph[findNodeIndex("IMMS")][findNodeIndex("COPPEL")] = 373.87;
	graph[findNodeIndex("COPPEL")][findNodeIndex("IMMS")] = 373.87; // Conexión bidireccional
	graph[findNodeIndex("B.J")][findNodeIndex("CFE")] = 902.2;
	graph[findNodeIndex("CFE")][findNodeIndex("B.J")] = 902.2; // Conexión bidireccional
	graph[findNodeIndex("CFE")][findNodeIndex("COPPEL")] = 124.61;
	graph[findNodeIndex("COPPEL")][findNodeIndex("CFE")] = 124.61; // Conexión bidireccional
	graph[findNodeIndex("COPPEL")][findNodeIndex("HANGELMAR")] = 295.0;
	graph[findNodeIndex("HANGELMAR")][findNodeIndex("COPPEL")] = 295.0; // Conexión bidireccional
	graph[findNodeIndex("IMMS")][findNodeIndex("HANGELMAR")] = 422.23;
	graph[findNodeIndex("HANGELMAR")][findNodeIndex("IMMS")] = 422.23; // Conexión bidireccional
	graph[findNodeIndex("HANGELMAR")][findNodeIndex("CHEDRAUI")] = 683.26;
	graph[findNodeIndex("CHEDRAUI")][findNodeIndex("HANGELMAR")] = 683.26; // Conexión bidireccional
	graph[findNodeIndex("CHEDRAUI")][findNodeIndex("PLAYAPRINC")] = 671.86;
	graph[findNodeIndex("PLAYAPRINC")][findNodeIndex("CHEDRAUI")] = 671.86; // Conexión bidireccional
	graph[findNodeIndex("CHEDRAUI")][findNodeIndex("CARACOLPLZ")] = 539.13;
	graph[findNodeIndex("CARACOLPLZ")][findNodeIndex("CHEDRAUI")] = 539.13; // Conexión bidireccional
	graph[findNodeIndex("CHEDRAUI")][findNodeIndex("BBVA")] = 857.4;
	graph[findNodeIndex("BBVA")][findNodeIndex("CHEDRAUI")] = 857.4; // Conexión bidireccional
	graph[findNodeIndex("CARACOLPLZ")][findNodeIndex("BBVA")] = 381.96;
	graph[findNodeIndex("BBVA")][findNodeIndex("CARACOLPLZ")] = 381.96; // Conexión bidireccional
	graph[findNodeIndex("BBVA")][findNodeIndex("ZICATELA")] = 929.34;
	graph[findNodeIndex("ZICATELA")][findNodeIndex("BBVA")] = 929.34; // Conexión bidireccional
	graph[findNodeIndex("BBVA")][findNodeIndex("OXXOLAZ")] = 1501.91;
	graph[findNodeIndex("OXXOLAZ")][findNodeIndex("BBVA")] = 1501.91; // Conexión bidireccional
	graph[findNodeIndex("ZICATELA")][findNodeIndex("OXXOLAZ")] = 1078.95;
	graph[findNodeIndex("OXXOLAZ")][findNodeIndex("ZICATELA")] = 1078.95; // Conexión bidireccional
	graph[findNodeIndex("OXXOLAZ")][findNodeIndex("MERCADOZIC")] = 655.52;
	graph[findNodeIndex("MERCADOZIC")][findNodeIndex("OXXOLAZ")] = 655.52; // Conexión bidireccional
	graph[findNodeIndex("MERCADOZIC")][findNodeIndex("SUPER71")] = 860.95;
	graph[findNodeIndex("SUPER71")][findNodeIndex("MERCADOZIC")] = 860.95; // Conexión bidireccional
	graph[findNodeIndex("SUPER71")][findNodeIndex("PUNTAZIC")] = 1001.05;
	graph[findNodeIndex("PUNTAZIC")][findNodeIndex("SUPER71")] = 1001.05; // Conexión bidireccional

    char start_name[BUFFER_SIZE];
    char target_name[BUFFER_SIZE];

	gotoxy(20, 8); printf("Ingresa el nodo inicial: ");
    scanf("%s", start_name);
	gotoxy(20, 9);printf("Ingresa el nodo objetivo: ");
    scanf("%s", target_name);

    int start_node = findNodeIndex(start_name);
    int target_node = findNodeIndex(target_name);

    if (start_node == -1 || target_node == -1) {
        printf("Nodo no valido.\n");
        return;
    }

    //printMatrix(graph);
    dijkstra(graph, start_node, target_node);
}


#endif //FUNCTIONS_H
