#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 3
#define MAX_ITEMS 3

const char* categories[MAX_CATEGORIES] = { "[ CONFIGURACOES ]", "[    JOGOS     ]", "[   DESLIGAR   ]" };
const char* subItems[MAX_CATEGORIES][MAX_ITEMS] = {
    { "Preferencia de Video", "Configurar Rede", "Informacoes do Sistema" },
    { "Grand Theft Auto V", "Minecraft 360", "Emulador RetroArch" },
    { "Desligar Console", "Reiniciar Sistema", "Voltar para Interface" }
};

int currentX = 0;
int currentY = 0;

void render_xmb() {
    // Código base estrutural da árvore de menus da XMB
    printf("\n\n   === DASHBOARD ESTILO PS3 AUTOMATICA (GITHUB) ===\n\n");
    printf("   ");
    for(int x = 0; x < MAX_CATEGORIES; x++) {
        if(x == currentX) printf(" *%s*   ", categories[x]);
        else printf("  %s    ", categories[x]);
    }
    printf("\n\n\n   Submenus:\n");
    for(int y = 0; y < MAX_ITEMS; y++) {
        if(y == currentY) printf("     -> [X] %s\n", subItems[currentX][y]);
        else printf("        [ ] %s\n", subItems[currentX][y]);
    }
}

int main() {
    // Ponto de entrada padrão para o processador PowerPC do Xbox
    render_xmb();
    return 0;
}
