#include <iostream>
using namespace std;

char **tabuleiro(){
    char **mat = (char**)malloc(3*sizeof(char*));
    for(char i = 0; i < 3; i++)
        mat[i] = (char*)calloc(3,sizeof(char));
    return mat;}

bool jogando(char **mat, char jogador){
    cout << "Vez do Jogador " << (int)jogador << endl;
    int lin, col;
    cin >> lin >> col;
    if(lin < 1 || lin > 3){
        cout << "Linha invalida" << endl;
        return true;}
    if(col < 1 || col > 3){
        cout << "Coluna Invalida" << endl;
        return true;}
    if(mat[--lin][--col]){
        cout << "Esta casa pertence ao Jogador " << mat[lin][col] << endl;
        return true;}
    mat[lin][col] = jogador;
    return false;}

void printgame(char **mat){
    for(char i = 0; i < 3; i++){
        for(char j = 0; j < 3; j++)
            cout << ((mat[i][j] == 1) ? "X " : (mat[i][j] == 2) ? "O " : ". ");
        cout << endl;}}

bool verificando(char **mat){
    for(char j = 0; j < 3; j++)
        if((mat[j][0] == mat[j][1] && mat[j][0] == mat[j][2]) && mat[j][0])
            return true;
    for(char j = 0; j < 3; j++)
        if((mat[0][j] == mat[1][j] && mat[0][j] == mat[2][j]) && mat[0][j])
            return true;
    if((mat[0][0] == mat[1][1] && mat[0][0] == mat[2][2]) && mat[0][0])
        return true;
    return (mat[2][0] == mat[1][1] && mat[2][0] == mat[0][2]) && mat[2][0];}

void encerra(char **mat){
    for(char i = 0; i < 3; i++)
        free(mat[i]);
    free(mat);}

int main(){
    char **mat = tabuleiro();
    char i = 0, f = 0;
    printgame(mat);
    while(i < 9){
        if(jogando(mat, i%2 + 1)) continue;
        system("clear");
        printgame(mat);
        if(verificando(mat)){
            f = 1;
            break;}
        i++;}
f ? cout << "O Jogador " << i%2 + 1 << " Ganhou" << endl : cout << "Empate" << endl;
encerra(mat);}