#include <xenon_soc/processor.h>
#include <input/input.h>
#include <console/console.h>
#include <usb/usbmain.h>
#include <ppc/timebase.h>
#include <stdio.h>

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
    console_clrscr();
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
    xenon_make_it_faster();
    usb_init();
    console_init();
    struct controller_data_s ctrl;

    while(1) {
        usb_do_poll();
        get_controller_data(&ctrl, 0);

        if (ctrl.dpad_right && currentX < MAX_CATEGORIES - 1) { currentX++; currentY = 0; delay(200); }
        else if (ctrl.dpad_left && currentX > 0) { currentX--; currentY = 0; delay(200); }
        else if (ctrl.dpad_down && currentY < MAX_ITEMS - 1) { currentY++; delay(200); }
        else if (ctrl.dpad_up && currentY > 0) { currentY--; delay(200); }
        
        if (ctrl.a) {
            console_clrscr();
            if (currentX == 2 && currentY == 0) xenon_smc_powerdown();
            delay(2000);
        }
        render_xmb();
        delay(16); 
    }
    return 0;
}
