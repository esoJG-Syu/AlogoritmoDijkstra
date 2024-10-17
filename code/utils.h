//
// Created by tux on 18/09/2024.
//

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <windows.h>


void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

// Interfaz del programa
void marcoPrincipal() {
    // Marco principal ///////////////
    int x = 0, y = 0;
    int i;
    // Esquinas y parte superior
    gotoxy(x, y); printf("%c", 201);
    for(i = 1; i < 155; i++){
        gotoxy(i, y); printf("%c",205);
    }
    gotoxy(x+155, y); printf("%c", 187);

    // Verticales de los lados
    for(i = 1; i < 40; i++){
        gotoxy(x, i); printf("%c",186);
    }
    x = 155;
    for(i = 1; i < 40; i++){
        gotoxy(x, i); printf("%c",186);
    }

    // Esquinas y parte inferior
    x = 0;
    gotoxy(x, y+40); printf("%c",200);
    for(i = 1; i < 155; i++){
        gotoxy(i, y+40); printf("%c",205);
    }
    gotoxy(x+155, y+40); printf("%c",188);
    //////////////////////////////////////////////

    // Marco del titulo y titulo /////////////////

    // Esquinas y parte superior
    gotoxy(x+55, y+1); printf("%c",201);
    for(i = 56; i < 98; i++){
        gotoxy(i, y+1); printf("%c",205);
    }
    gotoxy(x+98, y+1); printf("%c",187);

    // Laterales y titulo/////////////////////////
    gotoxy(x+58, y+2); printf("Algoritmo de Dijkstra en Puerto Esc.");
    gotoxy(x+55, y+2); printf("%c",186);
    gotoxy(x+98, y+2); printf("%c",186);

    // Esquinas y parte inferior
    gotoxy(x+55, y+3); printf("%c",200);
    for(i = 56; i < 98; i++){
        gotoxy(i, y+3); printf("%c",205);
    }
    gotoxy(x+98, y+3); printf("%c",188);
    /////////////////////////////////////////////

    // Marco interior////////////////////////////////
    x = 0, y = 0;
    // Esquinas y parte superior
    gotoxy(x+2, y+4); printf("%c", 201);
    for(i = 3; i < 153; i++){
        gotoxy(i, y+4); printf("%c",205);
    }
    gotoxy(x+153, y+4); printf("%c", 187);

    // Verticales de los lados
    for(i = 5; i < 36; i++){
        gotoxy(x+2, i); printf("%c",186);
    }
    x = 153;
    for(i = 5; i < 36; i++){
        gotoxy(x, i); printf("%c",186);
    }

    // Esquinas y parte inferior
    x = 0;
    gotoxy(x+2, y+36); printf("%c",200);
    for(i = 3; i < 153; i++){
        gotoxy(i, y+36); printf("%c",205);
    }
    gotoxy(x+153, y+36); printf("%c",188);

    ////////////////////////////////////////////////
}

void mostrarRutas() {
    char line[256];
    FILE *file = fopen("C:/Users/jegz1/Documents/rutas/rutas.txt", "r");
    if (file == NULL) {
        gotoxy(24, 7);
        perror("Error al abrir el archivo");
        getchar();
        return;
    }

    int lineCount = 0;
    int x = 34, y = 7;

    while (fgets(line, sizeof(line), file)) {
        lineCount++;
    }

    rewind(file);

    int midPoint = lineCount / 2;
    int currentLine = 0;

    while (fgets(line, sizeof(line), file)) {
        if (currentLine < midPoint) {
            gotoxy(34, 7 + currentLine);
        } else {
            gotoxy(84, 7 + (currentLine - midPoint));
        }

        printf("%s", line);
        currentLine++;
    }

    fclose(file);
}
#endif //UTILS_H
