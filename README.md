# Jogo do Galo (Tic-Tac-Toe)

Este repositório contem uma versão do jogo do galo desenvolvida por mim como um pequeno projeto em alguns dias, totalmente em C++ para ser jogada no terminal do Windows. O jogo utiliza caracteres em ASCII para desenhar a interface.

## Sobre o Jogo

* Modo Single-player: Jogue contra um Bot inteligente que calcula as melhores jogadas. O bot analisa todas as possibilidades, sendo portanto impossível vencer contra ele.
* Modo Multi-player: Jogue contra outro jogador no mesmo computador, alternando turnos.

## Como Compilar

Para compilar este jogo no Windows execute o seguinte comando:

    g++ "jogo do galo.cpp" -o jogo_do_galo.exe -static-libgcc -static-libstdc++ -static

## Controlos

Para navegar na interface escreva a opção desejada.

Quando for a sua vez de jogar, o programa ira pedir-te as coordenadas:
1. Insira o número da linha desejada e pressione Enter.
2. Insira o número da coluna desejada e pressione Enter.
