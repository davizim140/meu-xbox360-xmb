#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cabeçalhos fundamentais de hardware da arquitetura do Xbox 360
#include <xenon_soc/processor.h>
#include <console/console.h>
#include <video/video.h>
#include <input/input.h>
#include <usb/usbmain.h>

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
    // Código ANSI para limpar o buffer de vídeo e resetar a tela
    printf("\033[2J\033[H");
    
    printf("\n\n   === MINHA DASHBOARD ESTILO PS3 (EXECUTAVEL REAL) ===\n\n");
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
    // Inicialização segura dos componentes do chip do Xbox 360
    xenon_make_it_faster();
    usb_init();
    
    // Liga a saída de vídeo HDMI/AV de texto nativa do ecossistema LibXenon
    console_init(); 

    struct controller_data_s ctrl;

    while(1) {
        // Verifica as conexões das portas USB do console por controles
        usb_do_poll();
        get_controller_data(&ctrl, 0);

        // Processamento de comandos reais do controle do Xbox
        if (ctrl.dpad_right) {
            if (currentX < MAX_CATEGORIES - 1) { currentX++; currentY = 0; }
            delay(200); 
        }
        else if (ctrl.dpad_left) {
            if (currentX > 0) { currentX--; currentY = 0; }
            delay(200);
        }
        else if (ctrl.dpad_down) {
            if (currentY < MAX_ITEMS - 1) currentY++;
            delay(200);
        }
        else if (ctrl.dpad_up) {
            if (currentY > 0) currentY--;
            delay(200);
        }
        
        if (ctrl.a) {
            if (currentX == 2 && currentY == 0) {
                xenon_smc_powerdown(); // Desliga o hardware do console se selecionado
            }
        }

        render_xmb();
        video_wait_vsync(); // Sincroniza a atualização com a taxa da TV (evita tela preta)
    }

    return 0;
}
