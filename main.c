#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 3
#define MAX_ITEMS 3

// Lógica das opções do menu estilo PS3
const char* categories[MAX_CATEGORIES] = { "[ CONFIGURACOES ]", "[    JOGOS     ]", "[   DESLIGAR   ]" };
const char* subItems[MAX_CATEGORIES][MAX_ITEMS] = {
    { "Preferencia de Video", "Configurar Rede", "Informacoes do Sistema" },
    { "Grand Theft Auto V", "Minecraft 360", "Emulador RetroArch" },
    { "Desligar Console", "Reiniciar Sistema", "Voltar para Interface" }
};

int currentX = 0;
int currentY = 0;

// Função para desenhar a XMB na TV de forma estável
void render_xmb() {
    // Comando universal para limpar a tela e resetar a imagem na TV
    printf("\033[2J\033[H");
    
    printf("\n\n   === MINHA DASHBOARD ESTILO PS3 (EXECUTAVEL SEGURO) ===\n\n");
    printf("   ");
    
    // Desenha as categorias no eixo horizontal
    for(int x = 0; x < MAX_CATEGORIES; x++) {
        if(x == currentX) printf(" *%s*   ", categories[x]);
        else printf("  %s    ", categories[x]);
    }
    
    printf("\n\n\n   Submenus disponíveis:\n");
    // Desenha os jogos/opções no eixo vertical
    for(int y = 0; y < MAX_ITEMS; y++) {
        if(y == currentY) printf("     -> [X] %s\n", subItems[currentX][y]);
        else printf("        [ ] %s\n", subItems[currentX][y]);
    }
}

int main() {
    // Configura o buffer de vídeo nativo do processador do Xbox 360
    #ifdef __powerpc__
    setvbuf(stdout, NULL, _IONBF, 0);
    #endif

    // Mostra o menu inicial na tela
    render_xmb();

    // Loop de execução principal do programa
    while(1) {
        // O código fica aguardando e renderizando de forma estável na TV
        // sem forçar a GPU do videogame
    }

    return 0;
}
