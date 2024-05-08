#include<iostream>
#include<Windows.h>
using namespace std;
char board[3][3] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};

bool if_win(char player){
    for(int i=0; i<3; i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true;
        }
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return true;
        }
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return true;
    }
    return false;
}

void show(){
    system("cls");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << board[i][j] << " ";
        }
        cout <<"\n";
    }
}

void AI(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == '_'){
                board[i][j] = 'o';
                if(if_win('o')){
                    return;
                }
                board[i][j] = '_';
            }
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == '_'){
                board[i][j] = 'x';
                if(if_win('x')){
                    board[i][j] = 'o';
                    return;
                }
                board[i][j] = '_';
            }
        }
    }
    for(int i=3; i>-1; i--){
        for(int j=0; j<3; j++){
            if(board[i][j] == '_'){
                board[i][j] = 'o';
                return;
            }
        }
    }

}

int main(){
    show();
    while(1){
        int x,y;
        cout<<"Position:_ _\b\b\b";
        cin>>x>>y;
        while(board[x-1][y-1]!='_'){
            cout<<"Error\n";
            cout<<"Position:_ _\b\b\b";
            cin>>x>>y;
        }
        x-=1;
        y-=1;
        board[x][y]='x';
        show();
        if(if_win('x')){
            cout<<"You win!";
            break;
        }
        AI();
        if(if_win('o')){
            cout<<"You lose!";
            break;
        }
        show();
    }

    return 0;
}