#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <unistd.h>
using namespace std;

short int qntlin = 24, qntcol = 208, tam = qntlin * qntcol;

char **tabuleiro(){
    char **mat = (char**)malloc(qntlin*sizeof(char*));
    for(int i = 0; i < qntlin; i++)
        mat[i] = (char*)calloc(qntcol,sizeof(char));
    return mat;}

char **sementes(char **mat){
    srand(time(NULL));
    short int qnt = tam * 0.3;
    for(short int q = 0; q < qnt;){
        short int i = rand() % qntlin;
        short int j = rand() % qntcol;
        if(mat[i][j]) continue;
        mat[i][j] = 1;
        q++;}
    return mat;}

char **evolui(char **mat, char **cop){
    for(short int i = 0; i < qntlin; i++)
        for(short int j = 0; j < qntcol; j++){
            short int l1 = (i - 1 < 0) ? qntlin - 1 : i - 1, l2 = (i + 1 == qntlin) ? 0 : i + 1, c1 = (j - 1 < 0) ? qntcol - 1 : j - 1, c2 = (j + 1 == qntcol) ? 0 : j + 1;
            short int soma = mat[l1][c1]+ mat[l1][j] + mat[l1][c2] + mat[i][c1] + mat[i][c2] + mat[l2][c1] + mat[l2][j] + mat[l2][c2];
            if(soma < 2 || soma > 3) cop[i][j] = 0;
            if(soma == 3) cop[i][j] = 1;
            if(soma == 2) cop[i][j] = mat[i][j];}
    return cop;}

void printgame(char **mat, char **cop){
    system("clear");
    for(short int i = 0; i < qntlin; i++){
        for(short int j = 0; j < qntcol; j++){
            cout << ((mat[i][j] && cop[i][j]) ? "\033[1;34m" : (mat[i][j] && !cop[i][j]) ? "\033[1;32m" : (!mat[i][j] && cop[i][j]) ? "\033[1;31m" : "\033[1;37m");
            cout << (mat[i][j] ? 'X' : '.');}
        cout << endl;}
    usleep(200000);}

void encerra(char **mat){
    for(short int i = 0; i < qntlin; i++)
        free(mat[i]);
    free(mat);}

int main(){
    char **mat = sementes(tabuleiro());
    char **cop = tabuleiro();
    printgame(mat, cop);
    while(1){
        short int rodadas;
        cout << "\033[1;0mQuantas gerações (0 termina o programa)" << endl;
        cin >> rodadas;
        if(rodadas < 1) break;
        while(rodadas--){
            char **aux = mat;
            mat = evolui(mat, cop);
            cop = aux;
            printgame(mat, cop);}}
    encerra(mat);
    encerra(cop);}