#include <iostream>
using namespace std;

void corrige(char &c){
    c = (c >= 'A' && c <= 'Z') ? c + 32 : c;}

void jogando(){
    string esc, pub;
    cout << "Uma palavra" << endl;
    cin >> esc;
    system("clear");

    for(char i = 0; esc[i]; i++){
        corrige(esc[i]);
        pub += '_';}
    
    bool C[26] = {};
    char chances = 7;
    char c;
    do{ 
        cout << "Uma letra" << endl;
        cin >> c;
        system("clear");
        corrige(c);

        if(C[c - 'a']){
            cout << "Ja foi usada" << endl;
            continue;}
        C[c-'a'] = 1;

        bool n = 1;
        for(char i = 0; esc[i]; i++)
            if(esc[i] == c){
                pub[i] = c;
                n = 0;}
        chances -= n;
        
        cout << pub << endl;
        cout << "[";
        for(char i = 0; i < 26; i++)
            if(C[i]) cout << char('a' + i) << " ";
        cout << "]" << endl;
        
    }while((esc != pub) && chances);
    cout << (chances ? "Venceu" : "Perdeu") << endl;
}

int main(){
    char c;
    do{
        cout << "Jogar = j\nSair = s" << endl;
        cin >> c;
        system("clear");
        switch(c){
            case 'J':
            case 'j': 
                    jogando(); 
                    break;
            
            case 'S': c = 's';
            case 's': break;

            default: cout << "Opção invalida\n";
        }
    }while(c != 's');
    
}