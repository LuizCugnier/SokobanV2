#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

//variáveis
bool menu = true;
//Variavel do mapa
int mj[13][13] = {       1,1,1,1,1,1,1,1,1,1,1,1,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                         1,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,0,0,0,0,0,4,0,0,0,0,0,1,
                            1,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,0,0,0,0,0,0,0,0,0,0,0,1,
                            1,1,1,1,1,1,1,1,1,1,1,1,1 };
    //variavel opcao menu
    char opcao_menu = 0;
    //Variavel movimentos jogador
    char tecla = 0;
    //Variavel do jogo
    bool termina_jogo = true;

struct Jogador{
    int x, y;
};

void imprime_mapa(Jogador jogador){

    //Imprime o jogo: mapa e personagem.
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            if (i == jogador.x && j == jogador.y) {
                cout << char(2); //personagem
            }
            
            else {
                switch (mj[i][j]) {
                case 0: cout << " "; break; //caminho
                case 1: cout << char(219); break; //parede
                case 2: cout << " "; break; //espa�o vazio de fora
                case 3: cout << "."; break; //ponto final
                case 4: cout << "#"; break; //caixa
                    //default: cout<<"-"; //erro
                } //fim switch

            }
            
        }
        cout << "\n";
    } //fim for mapa[

    cout << "\nAperte '0' para voltar";
}

//Função para imprimir o menu principal
void imprime_menu() {
    system("cls");
    cout << "=======================\n";
    cout << "Bem Vindo ao Sokoban\n";
    cout << "=======================\n";
    cout << "[1] Novo Jogo\n";
    cout << "[2] Continuar\n";
    cout << "[3] Sobre\n";
    cout << "[4] Fim\n";
}

void fim_jogo(bool& menu) {
    system("cls");
    cout << "FIM DE JOGO!!!\n";
    Sleep(2000);
    menu = false;

}

void input(Jogador &jogador, char &tecla, bool &termina_jogo){
    if (_kbhit()) {
        tecla = _getch();
        switch (tecla)  
        {
        case 72: case 'w': ///cima
            jogador.x--;
            break;
        case 80: case 's': ///baixo
            jogador.x++;
            break;
        case 75: case 'a'://esquerda
            jogador.y--;
            break;
        case 77: case 'd'://direita
            jogador.y++;
            break;
            
        case '0':
            termina_jogo = false;
            system("cls");
            imprime_menu(); 
        }
    }
}

void novo_jogo(bool& termina_jogo, COORD coord, Jogador jogador){
    system("cls");
    termina_jogo = true;
    
    while(termina_jogo){
        //Posiciona a escrita no in�cio do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        imprime_mapa(jogador);
        input(jogador, tecla, termina_jogo);

        //input();

    }
}

void continua_jogo(COORD coord, Jogador jogador){
    novo_jogo(termina_jogo, coord, jogador);
}

void 111jogo(COORD coord, Jogador jogador){
    while (menu){
         
         if (_kbhit()){
            tecla = _getch();

            switch (tecla)
            {
            case '0':
                //imprimir o menu novamente
                imprime_menu();
                break;
            case '1':
                //cria um novo jogo
                novo_jogo(termina_jogo, coord, jogador);
                break;
            case '2':
                //continua um jogo
                continua_jogo(coord, jogador);
                break;
            case '3':
                //informações do jogo
                break;
            case '4':
                //termina jogo
                fim_jogo(menu);
                break;
            default:
                break;
            }
         }
    }
}

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

    Jogador jogador;

    jogador.x = 5;
    jogador.y = 5;

    //começo do jogo.
    imprime_menu();
    jogo(coord, jogador);


    return 0;
}