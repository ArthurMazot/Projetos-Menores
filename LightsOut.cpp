#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

short int tam;

char **tabuleiro(){
    srand(time(NULL));
    char **mat = (char**)calloc(tam, sizeof(char*));
    for(char i = 0; i < tam; i++){
        mat[i] = (char*)calloc(tam ,sizeof(char));
        for(char j = 0; j < tam; j++)
            mat[i][j] = rand() % 3 ? 1 : 0;}
    return mat;}

bool jogando(char **mat){
    cout << "Linha, Coluna (0, 0) acaba o jogo" << endl;
    int lin, col;
    cin >> lin >> col;
    if(!lin && !col)
        return true;
    if(lin < 1 || lin > tam){
        cout << "Linha invalida" << endl;
        return false;}
    if(col < 1 || col > tam){
        cout << "Coluna Invalida" << endl;
        return false;}
    lin--;
    col--;
    mat[lin][col] = !mat[lin][col];
    if((lin + 1) < tam) mat[lin + 1][col] = !mat[lin + 1][col];
    if((lin - 1) >= 0)  mat[lin - 1][col] = !mat[lin - 1][col];
    if((col + 1) < tam) mat[lin][col + 1] = !mat[lin][col + 1];
    if((col - 1) >= 0)  mat[lin][col - 1] = !mat[lin][col - 1];
    return false;}

void printgame(char **mat){
    for(char i = 0; i < tam; i++){
        for(char j = 0; j < tam; j++)
            cout << (mat[i][j] ? "X " : ". ");
        cout << endl;}}

bool verificando(char **mat){
    int soma = 0;
    for(char i = 0; i < tam; i++)
        for(char j = 0; j < tam; j++)
            soma += mat[i][j];
    return !soma;}

void encerra(char **mat){
    for(char i = 0; i < tam; i++)
        free(mat[i]);
    free(mat);}

int main(){
    cout << "Tamanho do tabuleiro (2 - 7)" << endl;
    cin >> tam;
    tam = (tam < 2 || tam > 7) ? 3 : tam;
    char **mat = tabuleiro();
    printgame(mat);
    while(1){
        if(jogando(mat)) break;
        system("clear");
        printgame(mat);
        if(verificando(mat)) break;}
    cout << "O Jogo acabou" << endl;
    encerra(mat);}