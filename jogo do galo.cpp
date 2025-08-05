
/*
char(218) << string(3, char(196)) << char(194) << string(3, char(196)) << char(194) << string(3, char(196)) << char(191) << "\n";
    cout << char(179) << " 1 " << char(179) << " 2 " << char(179) << " 3 " << char(179) << "\n";
    cout << char(195) << string(3, char(196)) << char(197) << string(3, char(196)) << char(197) << string(3, char(196)) << char(180) << "\n";
    cout << char(179) << " 6 " << char(179) << " 5 " << char(179) << " 4 " << char(179) << "\n";
    cout << char(195) << string(3, char(196)) << char(197) << string(3, char(196)) << char(197) << string(3, char(196)) << char(180) << "\n";
    cout << char(179) << " 7 " << char(179) << " 8 " << char(179) << " 9 " << char(179) << "\n";
    cout << char(192) << string(3, char(196)) << char(193) << string(3, char(196)) << char(193) << string(3, char(196)) << char(217) << "\n";

*/
/*

╔═══╦═══╦═══╗
║ 1 ║ 2 ║ 3 ║
╠═══╬═══╬═══╣
║ 6 ║ 5 ║ 4 ║
╠═══╬═══╬═══╣
║ 7 ║ 8 ║ 9 ║
╚═══╩═══╩═══╝
┌───┬───┬───┐
│   │   │   │
├───┼───┼───┤
│   │   │   │
├───┼───┼───┤
│   │   │   │
└───┴───┴───┘
 ┴┬├

 std::this_thread::sleep_for(std::chrono::seconds(3));

*/

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;



void clear_screen() {
    cout << "\033[2J\033[1;1H";  // Limpa e move o cursor para o canto superior esquerdo
}

class modo{
    public:
        int md;
        modo(){
            cout << endl <<  "----------------------" << endl << endl ;
            cout << "Selecione o Modo de Jogo:" << endl << endl << "--> 1 Jogador" << endl << "--> 2 Jogadores" << endl << endl << "(escreva 1 ou 2 para selecionar)" << endl;
            cin >> md;
        }
};

class jogadores{
    public:
        string j1,j2;
        jogadores(){
            cout << "Insira o nome do jogador 1:" << endl;
            cin >> j1;
            cout << "Insira o nome do jogador 2:" << endl;
            cin >> j2;
        }
};

class tabuleiro{
    private:
        char grelha[3][3];
        int cheio;
    public:

        tabuleiro() : cheio(0){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                     grelha[i][j]=' ';
                }
            }
        }

        int echeio(){
            if (cheio==9) return 1;
            else return 0;
        }


        int vitoria(char simbolo){
            for(int i=0;i<3;i++)
                if(grelha[i][0]==simbolo && grelha[i][1]==simbolo && grelha[i][2]==simbolo)
                    return 1;
            for(int i=0;i<3;i++)
                if(grelha[0][i]==simbolo && grelha[1][i]==simbolo && grelha[2][i]==simbolo)
                    return 1;
            if(grelha[0][0]==simbolo && grelha[1][1]==simbolo && grelha[2][2]==simbolo)
                return 1;
            if(grelha[0][2]==simbolo && grelha[1][1]==simbolo && grelha[2][0]==simbolo)
                return 1;
            return 0;
        }

        void desenhar(int linha, int coluna,char c){
            grelha[linha-1][coluna-1]=c;
            cheio++;
            return;
        }
        bool valido(int linha, int coluna){
            if(linha<1 || linha >3 || coluna <1 ||coluna >3 || grelha[linha-1][coluna-1]!=' ') return false;
            else return true;
        }



        void printt() const{
            cout << char(218) << string(3, char(196)) << char(194) << string(3, char(196)) << char(194) << string(3, char(196)) << char(191) << endl;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout << char(179) << ' ' << grelha[i][j] << ' ';
                }
                if(i!=2) cout << char(179) << endl << char(195) << string(3, char(196)) << char(197) << string(3, char(196)) << char(197) << string(3, char(196)) << char(180) << endl;
            }
            cout << char(179) << endl << char(192) << string(3, char(196)) << char(193) << string(3, char(196)) << char(193) << string(3, char(196)) << char(217) << endl;
            return;
        }

};

class jogo{
    private:
        int vez;
        tabuleiro t;
    public:
        char simbolo(){
            if(vez==1)
                return 'O';
            else return 'X';
        }
        string vervez(jogadores j){
            if(vez==1)
                return j.j1;
            else return j.j2;
        }

        int bot(tabuleiro t1, bool vezbot, char simbolobot){

            char simbol2;
            if(simbolobot=='X') simbol2= 'O';
            else simbol2= 'X';

            if(t1.vitoria(simbolobot)) return 1;
            if(t1.vitoria(simbol2)) return -1;
            if(t1.echeio()) return 0;

            if(vezbot){
                int maximo=-100;
                for(int i=1;i<4;i++){
                    for(int j=1;j<4;j++){
                        if(t1.valido(i,j)){
                            tabuleiro t2=t1;
                            t2.desenhar(i,j,simbolobot);
                            int pontos=bot(t2,false,simbolobot);
                            if(pontos>maximo){
                                maximo=pontos;

                            }
                        } 
                    }
                }
                return maximo;
            }
            else{
                int minimo=100;
                for(int i=1;i<4;i++){
                    for(int j=1;j<4;j++){
                        if(t1.valido(i,j)){
                            tabuleiro t2=t1;
                            t2.desenhar(i,j,simbol2);
                            int pontos=bot(t2,true,simbolobot);
                            if(pontos<minimo){
                                minimo=pontos;

                            }
                        } 
                    }
                }
                return minimo;
            }
        }

        void jogadabot(char simbolobot){
            int linha, coluna;
            int pontos;
            int maximo=-100;
            for(int i=1;i<4;i++){
                for(int j=1;j<4;j++){
                    if(t.valido(i,j)){
                        tabuleiro temp = t;
                        temp.desenhar(i,j,simbolobot);
                        pontos = bot(temp,false,simbolobot);
                        if(pontos>maximo){
                            maximo=pontos;
                            linha=i;
                            coluna=j;
                        }
                    }

                }

            }
            t.desenhar(linha,coluna,simbolobot);
            return;
        }

        void singleplayer(){
            string turn;
            char simbolobot,simboloplayer;
            int linha, coluna;
escolhervez:
            cout << "Quem deve come" << char(135) << "ar?"<< endl << endl << "--> EU" << endl << "--> BOT" << endl;
            cin >> turn;
            if(turn=="EU") vez=2;
            else if(turn=="BOT") vez=1;
            else{
                clear_screen();
                cout << "Escolha inv" << char(160) << "lida" << endl << "Escreva \"EU\" ou \"BOT\" para escolher quem come"<< char(135) << "a." << endl;
                goto escolhervez;
            }

            simbolobot = simbolo();
            if (simbolobot=='O') simboloplayer='X';
            else simboloplayer='O';

            while(!t.echeio()){
                if(vez==1){
                    clear_screen();
                    cout << "-----------------------------------" << endl << "O bot est"<< char(160) <<  " a pensar" << endl;
                    t.printt();
                    Sleep(2000);
                    jogadabot(simbolobot);
                    if(t.vitoria(simbolobot)){
                        clear_screen();
                        cout << "-----------------------------------" << endl;
                        t.printt();
                        cout << "-----------------------------------" << endl << endl << "PERDESTE O JOGO!!!"<< endl << endl;
                        return;
                    }
                    vez++;
                }
                else{
                clear_screen();
                cout << "-----------------------------------" << endl << char(144) << " a tua vez" << endl;
                t.printt();
escrev:
                cout << "escreva o n" <<char(163) << "mero da linha em que pretende jogar:" ;
                cin >> linha;
                cout << "escreva o n"<<char(163)<< "mero da coluna em que pretende jogar:"; 
                cin >> coluna;
                cout << endl;
                if(!t.valido(linha, coluna)){
                    cout << "Posi" << char(135) << char(198) << "o inv" << char(160) << "lida" << endl;
                    goto escrev;
                }

                t.desenhar(linha, coluna, simboloplayer);
                if(t.vitoria(simboloplayer)){
                    clear_screen();
                    cout << "-----------------------------------" << endl;
                    t.printt();
                    cout << "-----------------------------------" << endl << endl << "VENCESTE O JOGO!!!"<< endl << endl;
                    return;
                }
                 vez--;
            }
        }
            clear_screen();
            t.printt();
            cout << endl << "-----------------------------------"<< endl << endl << char(144) <<" UM EMPATE!!!"<< endl << endl;
        }

        void multiplayer(){
            vez = 1;
            int linha, coluna;
            jogadores j;
            while(!t.echeio()){
                char c= simbolo();
                clear_screen();
                cout << "-----------------------------------" << endl << char(144) << " a vez de " << vervez(j) << endl;
                t.printt();
escrev:
                cout << "escreva o n" <<char(163) << "mero da linha em que pretende jogar:" ;
                cin >> linha;
                cout << "escreva o n"<<char(163)<< "mero da coluna em que pretende jogar:"; 
                cin >> coluna;
                cout << endl;
                if(!t.valido(linha, coluna)){
                    cout << "Posi" << char(135) << char(198) << "o inv" << char(160) << "lida" << endl;
                    goto escrev;
                }
                t.desenhar(linha, coluna, c);
                if(t.vitoria(c)){
                    clear_screen();
                    cout << "-----------------------------------" << endl;
                    t.printt();
                    cout << "-----------------------------------" << endl << endl << vervez(j) << " VENCEU O JOGO!!!"<< endl << endl;
                    return;
                }
                if(vez==1)vez++;
                else vez--;
            }
            clear_screen();
            t.printt();
            cout << endl << "-----------------------------------"<< endl << endl << char(144) <<" UM EMPATE!!!"<< endl << endl;
        }
};

int main(){
    cout << endl <<  "O jogo do galo vai come" << char(135) << "ar" << endl;
inicio:
    modo m;
    jogo game;
    if(m.md==2){     
        game.multiplayer();
    }
    else if(m.md==1) game.singleplayer();
    else goto inicio;
    string escolha;
fim:
    cout << "-----------------------------------" << endl << "Escolha:" << endl << endl << "--> JOGAR" << endl << "--> SAIR" << endl;
    cin >> escolha;
    if(escolha == "JOGAR") {
        clear_screen();
        goto inicio;
    }
    else if(escolha =="SAIR") return 0;
    else goto fim;
}
