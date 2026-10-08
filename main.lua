-- === DASHBOARD ESTILO PS3 PARA AURORA (17559) ===

local MAX_CATEGORIES = 3
local MAX_ITEMS = 3

local categories = { "[ CONFIGURACOES ]", "[    JOGOS     ]", "[   DESLIGAR   ]" }
local subItems = {
    { "Preferencia de Video", "Configurar Rede", "Informacoes do Sistema" },
    { "Grand Theft Auto V", "Minecraft 360", "Emulador RetroArch" },
    { "Desligar Console", "Reiniciar Sistema", "Voltar para Interface" }
}

local currentX = 1 -- Controla a categoria (Eixo X)
local currentY = 1 -- Controla o subitem (Eixo Y)

-- Função que o Aurora chama para desenhar na TV
function OnRender()
    -- Define a cor do fundo da tela (Simulando o azul escuro do PS3)
    Aurora.DrawBackground(0x14, 0x14, 0x1E)

    -- 1. Desenha as Categorias Horizontais (Eixo X)
    for x = 1, MAX_CATEGORIES do
        local color = 0x646464 -- Cinza apagado para abas inativas
        local text = categories[x]
        
        if x == currentX then
            color = 0xFFFFFF -- Branco brilhante para a ativa
            text = "*" .. text .. "*"
        end
        
        -- Desenha o texto na tela (Texto, Posição X, Posição Y, Cor)
        Aurora.DrawText(text, 100 + (x * 200), 200, color)
    end

    -- 2. Desenha os Subitens Verticais (Eixo Y) abaixo da categoria ativa
    Aurora.DrawText("Submenus disponíveis:", 300, 300, 0x8A8A8A)
    for y = 1, MAX_ITEMS do
        local itemColor = 0x969696
        local itemText = subItems[currentX][y]
        
        if y == currentY then
            itemColor = 0x00FF00 -- Verde para o item selecionado
            itemText = "-> [X] " .. itemText
        else
            itemText = "   [ ] " .. itemText
        end
        
        Aurora.DrawText(itemText, 300, 320 + (y * 40), itemColor)
    end
end

-- Função que o Aurora chama quando você mexe no controle do Xbox 360
function OnInput(button)
    if button == "DPAD_RIGHT" and currentX < MAX_CATEGORIES then
        currentX = currentX + 1
        currentY = 1 -- Reseta a linha vertical ao mudar de aba
    elseif button == "DPAD_LEFT" and currentX > 1 then
        currentX = currentX - 1
        currentY = 1
    elseif button == "DPAD_DOWN" and currentY < MAX_ITEMS then
        currentY = currentY + 1
    elseif button == "DPAD_UP" and currentY > 1 then
        currentY = currentY - 1
    elseif button == "BUTTON_A" then
        -- Ação ao pressionar o botão A do controle
        if currentX == 3 and currentY == 1 then
            Aurora.ShutdownConsole() -- Desliga o Xbox nativamente
        else
            Aurora.ShowNotification("Executando: " .. subItems[currentX][currentY])
        end
    end
end
