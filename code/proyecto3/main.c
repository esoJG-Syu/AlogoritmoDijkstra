#include "dijkstra.h"
#include <conio.h>

int main() {
    double graph[MAX_NODES][MAX_NODES];
    int opcion;
    for ( i = 0; i < MAX_NODES; i++) {
        for ( j = 0; j < MAX_NODES; j++) {
            graph[i][j] = INF;
        }
    }
    gotoxy(20,10);printf("Maximize la ventana y presione enter...");
    getch();

    do {
        marcoPrincipal();
        gotoxy(110,38); system("PAUSE");
        system("cls");
        marcoPrincipal();

         gotoxy(54, 6); printf("1. Leer conexiones desde archivo\n");
         gotoxy(54, 7); printf("2. Calcular ruta con Dijkstra\n");
         gotoxy(54, 8); printf("3. Salir\n");
         gotoxy(54, 9); printf("Elige una opcion: ");
         scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                system("cls");
                mostrarRutas();
                break;
            case 2:
                system("cls");
                marcoPrincipal();
                calcularRutas(graph);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                exit(0);
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 3);

    return 0;
}
