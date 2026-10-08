#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 3
#define MAX_ITEMS 3

// Lógica de menus estilo PS3
const char* categories[MAX_CATEGORIES] = { "[ CONFIGURACOES ]", "[    JOGOS     ]", "[   DESLIGAR   ]" };
const char* subItems[MAX_CATEGORIES][MAX_ITEMS] = {
    { "Preferencia de Video", "Configurar Rede", "Informacoes do Sistema" },
    { "Grand Theft Auto V", "Minecraft 360", "Emulador RetroArch" },
    { "Desligar Console", "Reiniciar Sistema", "Voltar para Interface" }
};

int currentX = 0;
int currentY = 0;

// Função para simular a renderização limpa no terminal do Xbox 360
void render_xmb() {
    // Código ANSI para limpar a tela e resetar o cursor na TV
    printf("\033[2J\033[H"); 
    
    printf("\n\n   === DASHBOARD ESTILO PS3 AUTOMATICA (GITHUB) ===\n\n");
    printf("   ");
    
    // Renderiza colunas horizontais (Eixo X)
    for(int x = 0; x < MAX_CATEGORIES; x++) {
        if(x == currentX) printf(" *%s*   ", categories[x]);
        else printf("  %s    ", categories[x]);
    }
    
    printf("\n\n\n   Submenus:\n");
    
    // Renderiza linhas verticais (Eixo Y)
    for(int y = 0; y < MAX_ITEMS; y++) {
        if(y == currentY) printf("     -> [X] %s\n", subItems[currentX][y]);
        else printf("        [ ] %s\n", subItems[currentX][y]);
    }
}

int main() {
    // Força o processador do Xbox 360 a abrir o canal de saída de texto na TV
    // Isso evita o congelamento em tela preta
    #ifdef __powerpc__
    setvbuf(stdout, NULL, _IONBF, 0); 
    #endif

    // Roda a interface na TV
    render_xmb();

    // Loop de segurança para manter a imagem estática na TV sem fechar o app
    while(1) {
        // Aguarda os comandos do sistema
    }

    return 0;
}
