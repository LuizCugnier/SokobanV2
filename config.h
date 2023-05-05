using namespace std;

struct Menu{
    bool principal;
    bool termina_jogo;

    
};
struct Jogador{
    int x, y;

};

void imprime_mapa(Jogador jogador, int (&mj)[13][13]){

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
                case 2: cout << "#"; break; //caixa em espaço vazio
                case 3: cout << "."; break; //posição final
                case 4: cout << "&"; break; //caixa na posição final
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

void fim_jogo(Menu &menu1) {
    system("cls");
    cout << "FIM DE JOGO!!!\n";
    Sleep(2000);
    menu1.principal = false;

}

void input(Jogador &jogador, char &tecla, Menu &menu1, int (&mj)[13][13]){
    if (_kbhit()) {
        tecla = _getch();
        switch (tecla)  
        {
        case 72: case 'w': ///cima
            if (jogador.x > 0 && mj[jogador.x - 1][jogador.y] == 0){
                jogador.x--;
            } else if (jogador.x > 0 && mj[jogador.x - 1][jogador.y] == 2 && mj[jogador.x - 2][jogador.y] != 2 && mj[jogador.x - 2][jogador.y] != 1){
                mj[jogador.x - 2][jogador.y] = 2;
                mj[jogador.x - 1][jogador.y] = 0;
                jogador.x--;
            }
            break;
        case 80: case 's': ///baixo
            if (jogador.x > 0 && mj[jogador.x + 1][jogador.y] == 0){
                jogador.x++;
            } else if (jogador.x > 0 && mj[jogador.x + 1][jogador.y] == 2 && mj[jogador.x + 2][jogador.y] != 2 && mj[jogador.x + 2][jogador.y] != 1){
                mj[jogador.x + 2][jogador.y] = 2;
                mj[jogador.x + 1][jogador.y] = 0;
                jogador.x++;
            }
            break;
        case 75: case 'a'://esquerda
            if (jogador.y > 0 && mj[jogador.x][jogador.y - 1] == 0){
                jogador.y--;
            } else if (jogador.y > 0 && mj[jogador.x][jogador.y - 1] == 2 && mj[jogador.x][jogador.y - 2] != 2 && mj[jogador.x][jogador.y - 2] != 1){
                mj[jogador.x][jogador.y - 2] = 2;
                mj[jogador.x][jogador.y - 1] = 0;
                jogador.y--;
            }
            break;
        case 77: case 'd'://direita
            if (jogador.y > 0 && mj[jogador.x][jogador.y + 1] == 0){
                jogador.y++;
            } else if (jogador.y > 0 && mj[jogador.x][jogador.y + 1] == 2 && mj[jogador.x][jogador.y + 2] != 2 && mj[jogador.x][jogador.y + 2] != 1){
                mj[jogador.x][jogador.y + 2] = 2;
                mj[jogador.x][jogador.y + 1] = 0;
                jogador.y++;
            }
            break;
            
        case '0':
            menu1.termina_jogo = false;
            system("cls");
            imprime_menu(); 
        }
    }
}

void novo_jogo(Menu &menu1, COORD coord, Jogador jogador, char tecla, int (&mj)[13][13]){
    system("cls");
    menu1.termina_jogo = true;
    
    while(menu1.termina_jogo){
        //Posiciona a escrita no in�cio do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        imprime_mapa(jogador, mj);
        input(jogador, tecla, menu1, mj);

        //input();

    }
}

void continua_jogo(COORD coord, Jogador jogador, Menu &menu1, char tecla, int (&mj)[13][13]){
    novo_jogo(menu1, coord, jogador, tecla, mj);
}

void jogo(COORD coord, Jogador jogador, Menu menu1, char tecla, int (&mj)[13][13]){
    while (menu1.principal){
         
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
                novo_jogo(menu1, coord, jogador, tecla, mj);
                break;
            case '2':
                //continua um jogo
                continua_jogo(coord, jogador, menu1, tecla, mj);
                break;
            case '3':
                //informações do jogo
                break;
            case '4':
                //termina jogo
                fim_jogo(menu1);
                break;
            default:
                break;
            }
         }
    }
}

