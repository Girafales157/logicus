// importacao de arquivos header de bibliotecas padrao

#include <stdio.h>

// importacao de arquivos header de bibliotecas third party

#include "raylib.h"
#include "raygui.h"

// importacao de arquivos header de prototipacao

#include "save.h"
#include "dialogo.h"

// declaracao de constantes globais

// declaracao de variaveis globais

int main(void) {
    InitWindow(800, 460, "Logicus;");
    SetTargetFPS(60);

    bool showMessageBox = false;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            if (GuiButton((Rectangle){ 24, 24, 120, 30 }, "#191#Show Message")) showMessageBox = true;

            if (showMessageBox)
            {
                int result = GuiMessageBox((Rectangle){ 85, 70, 250, 100 },
                    "#191#Message Box", "Hi! This is a message!", "Nice;Cool");

                if (result >= 0) showMessageBox = false;
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
