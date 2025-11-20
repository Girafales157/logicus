// importacao de arquivos header de bibliotecas padrao

#include <stdio.h>

// importacao de arquivos header de bibliotecas third party

#define RAYGUI_IMPLEMENTATION

#include "raylib.h"
#include "raygui.h"

// importacao de arquivos header de prototipacao e carregamento

#include "save.h"
#include "dialogo.h"
#include "recursos.h"

// declaracao de constantes globais
// ...

// define tamanho da janela

#define LARGURA 800
#define ALTURA 480

// declaracao de variaveis globais
// ...

int main(void) {
    // aloca estaticamente memoria para recursos de imagem
    Imagens imagens = {0};

    // inicializa janela da biblioteca RayGUI
    InitWindow(LARGURA, ALTURA, "Logicus;");
    SetTargetFPS(60);

    // carrega recursos de imagem do jogo
    carregarRecursos(&imagens);

    // inicia game loop para desenhar na janela
    while (!WindowShouldClose()) {

        BeginDrawing();
            // limpa cor de fundo para proxima iteracao
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            // desenha splash arte do menu
            DrawTexture(imagens.interface[SPLASH_ARTE], 0, 0, WHITE);
            
            // desenha titulo
            DrawTexture(imagens.interface[TITULO_ARTE], (LARGURA / 2) - 180, ALTURA / 28, WHITE);
        EndDrawing();

    }
    
    // descarrega recursos de imagem alocadas pelo rayGUI
    descarregarRecursos(&imagens);

    // finaliza janela
    CloseWindow();
    return 0;
}

//função que muda de tela ativamente
void mudarTela (EstadoTela *telaAtual){
    switch(*telaAtual){
        case TELA_INICIAL:
            *telaAtual = telaInicial(&telaAtual);
            break;
        
        case TELA_MENU:
            *telaAtual = telaMenu(&telaAtual);
            break;
        
        case TELA_JOGO:
            *telaAtual = telaJogo(&telaAtual);
    }
}

EstadoTela telaInicial(EstadoTela **tela){
    DrawText("TELA INICIAL - Aperte ENTER ou Clique Esquerdo", 100, 200, 20, BLACK);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER))
    {
        return TELA_MENU;
    } else {
        return **tela;
    }
}

EstadoTela telaMenu(EstadoTela **tela){
    DrawText("TELA DO MENU - Aperte ENTER ou Clique Esquerdo", 100, 200, 20, BLACK);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER))
    {
        return TELA_JOGO;
    } else {
        return **tela;
    }
}

EstadoTela telaJogo(EstadoTela **tela){
    DrawText("TELA DO JOGO - Aperte ENTER ou Clique Esquerdo", 100, 200, 20, BLACK);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER))
    {
        return TELA_MENU;
    } else {
        return **tela;
    }
}