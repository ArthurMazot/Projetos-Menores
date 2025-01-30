#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

short int qntlin, qntcol, qnt, tam;
char **esc, **pub;

char **tabuleiro(){
    char **mat = (char**)malloc(qntlin*sizeof(char*));
    for(short int i = 0; i < qntlin; i++)
        mat[i] = (char*)calloc(qntcol,sizeof(char));
    return mat;}

char **minas(char **mat, short qnt){
    srand(time(NULL));
    for(short int q = 0; q < qnt;){
        short int i = rand() % qntlin;
        short int j = rand() % qntcol;
        if(mat[i][j]) continue;
        mat[i][j] = 1;
        q++;}
    return mat;}

void recurcao(short int lin, short int col){
    if(pub[lin][col] || pub[lin][col] == -1) return;
    bool l1 = (lin - 1 >= 0), l2 = (lin + 1 < qntlin), c1 = (col - 1 >= 0), c2 = (col + 1 < qntcol);
    char soma = 0;
    soma += (l1 && c1) ? esc[lin - 1][col - 1] : 0;
    soma += l1 ? esc[lin - 1][col] : 0;
    soma += (l1 && c2) ? esc[lin - 1][col + 1] : 0;
    soma += c1 ? esc[lin][col - 1] : 0;
    soma += c2 ? esc[lin][col + 1] : 0;
    soma += (l2 && c1) ? esc[lin + 1][col - 1] : 0;
    soma += l2 ? esc[lin + 1][col] : 0;
    soma += (l2 && c2) ? esc[lin + 1][col + 1] : 0;
    if(!soma){
        pub[lin][col] = -1;
        if(l1 && c1) recurcao(lin - 1, col - 1);
        if(l1) recurcao(lin - 1, col);
        if(l1 && c2) recurcao(lin - 1, col + 1);
        if(c1) recurcao(lin, col - 1);
        if(c2) recurcao(lin, col + 1);
        if(l2 && c1) recurcao(lin + 1, col - 1);
        if(l2) recurcao(lin + 1, col);
        if(l2 && c2) recurcao(lin + 1, col + 1);}
    else pub[lin][col] = soma;}

bool jogando(){
    short int lin, col;
    do{
        cout << "Linha, Coluna (0,0) acaba o jogo" << endl;
        cin >> lin >> col;
        if(!lin && !col) return true;
    }while((lin < 1 && lin > qntlin) || (col < 1 && col > qntcol));
    if(esc[--lin][--col]) return true;
    recurcao(lin, col);
    return false;}

bool verificando(){
    int soma = 0;
    for(int i = 0; i < qntlin; i++)
        for(int j = 0; j < qntcol; j++)
            soma += !pub[i][j];
    return soma == qnt;}

void printgame(char **mat){
    for(short int i = 0; i < qntlin; i++){
        for(short int j = 0; j < qntcol; j++){
            if(!mat[i][j]) cout << "X ";
            if(mat[i][j] == -1) cout << ". ";
            if(mat[i][j] > 0) cout << (int)mat[i][j] << ' ';}
    cout << endl;}}

void encerra(char **mat){
    for(short int i = 0; i < qntlin; i++)
        free(mat[i]);
    free(mat);}

int main(int n, char** args){
    if(n < 3 || n > 4) return 1;
    qntlin = stoi(args[1]);
    qntcol = stoi(args[2]);
    tam = qntlin * qntcol;
    pub = tabuleiro();
    esc = minas(tabuleiro(), (n == 4) ? stoi(args[3]) : tam * 0.15);
    while(1){
        system("clear");
        printgame(pub);
        if(jogando()){cout << "Perdeu" << endl; break;}
        if(verificando()){cout << "Venceu" << endl; break;}}
    encerra(pub);
    encerra(esc);
    return 0;}