#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include "config.h"

using namespace std;


int main(){
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    short int CX = 0, CY = 0;
    COORD coord;
    coord.X = CX;
    coord.Y = CY;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.
    
    //variáveis
    //Variavel movimentos jogador
    char tecla = 0;
    //variavel opcao menu
    char opcao_menu = 0;
    
    //Variavel do mapa
    int mj[13][13] = {      1,1,1,1,1,1,1,1,1,1,1,1,1,
                            1,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,0,0,1,0,0,2,0,0,1,1,0,1,
                            1,0,0,1,0,0,0,0,0,0,1,0,1,
                            1,0,0,1,0,0,0,0,0,1,1,0,1,
                            1,0,0,1,0,0,0,0,0,0,0,0,1,
                            1,0,0,1,1,1,0,0,1,1,1,0,1,
                            1,0,0,0,0,0,0,0,0,0,1,0,1,
                            1,0,0,0,0,0,0,0,0,0,1,0,1,
                            1,0,0,0,0,0,3,0,0,0,0,0,1,
                            1,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,1,1,1,1,1,1,1,1,1,1,1,1 };

    Menu menu1;
    menu1.principal = true;
    menu1.termina_jogo = true;

    Jogador jogador;
    jogador.x = 5;
    jogador.y = 5;

    //começo do jogo.
    imprime_menu();
    jogo(coord, jogador, menu1, tecla, mj);


    return 0;
}
