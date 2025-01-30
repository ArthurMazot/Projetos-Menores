#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

char **inicializa(short int lin, short int col){
    char **mat = (char**)malloc(lin*sizeof(char*));
    for(short int i = 0; i < lin; i++)
        mat[i] = (char*)calloc(col,sizeof(char));
    return mat;}

void definePontos(char **mat, short int pontos[5][2], short int lin, short int col){
    srand(time(NULL));
    for(char k = 0; k < 5;){
        short int i = rand() % lin;
        short int j = rand() % col;
        if(mat[i][j] == -1) continue;
        mat[i][j] = -1;
        pontos[k][0] = i;
        pontos[k++][1] = j;}}

void evolui(char **mat, short int pontos[5][2], short int lin, short int col){
    char ponto;
    float distancia, aux;
    for(short int i = 0; i < lin; i++)
        for(short int j = 0; j < col; j++){
            if(mat[i][j] == -1) continue;
            ponto = 0;
            distancia = sqrt((pontos[0][0] - i)*(pontos[0][0] - i) + (pontos[0][1] - j)*(pontos[0][1] - j));
            for(char k = 1; k < 5; k++){
                aux = sqrt((pontos[k][0] - i)*(pontos[k][0] - i) + (pontos[k][1] - j)*(pontos[k][1] - j));
                if(aux < distancia){
                    distancia = aux;
                    ponto = k;}}
            mat[i][j] = ponto;}}

void printgame(char **mat, short int lin, short int col){
    for(short int i = 0; i < lin; i++){
        for(short int j = 0; j < col; j++)
            cout << ((mat[i][j] == 0) ? '.' : (mat[i][j] == 1) ? '/' : (mat[i][j] == 2) ? '*' : (mat[i][j] == 3) ? '=' : (mat[i][j] == 4) ? '+' : 'P');
        cout << endl;}}

void encerra(char **mat, short int lin){
    for(short int i = 0; i < lin; i++)
        free(mat[i]);
    free(mat);}

int main(int n, char **args){
    if(n != 3){
        cout << "Linhas || Colunas" << endl;
        return 1;}
    short int lin = stoi(args[1]);
    short int col = stoi(args[2]);
    short int pontos[5][2];
    char **mat = inicializa(lin+1, col+1);
    definePontos(mat, pontos, lin+1, col+1);
    evolui(mat, pontos, lin, col);
    printgame(mat, lin, col);
    encerra(mat, lin);}