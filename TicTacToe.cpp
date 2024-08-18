//Tic Tac Toe
#include <iostream>
using namespace std;

char board[3][3];
void generateboard(){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            board[i][j] = ' ';
        }
    }
}

void showboard(){
    cout<<"  "<<board[0][0]<<"  | "<<" "<<board[0][1]<<"  |  "<<board[0][2]<<endl;
    cout<<"- - - - - - - - -"<<endl;
    cout<<"  "<<board[1][0]<<"  | "<<" "<<board[1][1]<<"  |  "<<board[1][2]<<endl;
    cout<<"- - - - - - - - -"<<endl;
    cout<<"  "<<board[2][0]<<"  | "<<" "<<board[2][1]<<"  |  "<<board[2][2]<<endl;
}

char turn(char player){
    int i, j;
    cout<<player<<"'s turn"<<endl;
    cout<<"Enter Row: ";
    cin>>i;
    cout<<"Enter Column: ";
    cin>>j;
    if (board[i][j] == ' '){
        board[i][j] = player;
        player=='X'?player='O':player='X';
    }
    else{
        cout<<"\n-----Invalid move-------\n";
        cout<<"try again\n";
    }
    return player;
}

bool checkwin(){
    //check rows & columns
    for (int i=0;i<3;i++){
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' '){
            return true;
        }
        else if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' '){
            return true;
        }
    }
    //checking diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' '){
        return true;
    }
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' '){
        return true;
    }
    return false;
}

bool checkdraw(){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(board[i][j] == ' '){return false;}
        }
    }
    //When no spot is empty
    return true;
}

void game(){
    bool game_running = true;
    generateboard();
    showboard();
    char player = 'X';
    while (game_running == true){
        player = turn(player);
        showboard();
        //Check Win / Draw
        if (checkwin()){
            //changing player back to prev after winning because it changed after last turn
            player=='X'?player='O':player='X';
            cout<<"\n--------"<<player<<" WON!--------\n";
            game_running = false;
        }
        else if (checkdraw()){
            cout<<"\n--------GAME DRAW--------\n";
            game_running = false;
        };
    }
    
}

bool asktoplay(){
    int choice;
    bool playing = true;
    cin>>choice;
    if (choice == 1){
        playing = true;
    }
    else{
        cout<<"Thank you!";
        playing = false;
    }
    return playing;
}

int main(){
    cout<<"WELCOME TO TIC TAC TOE"<<endl;
    cout<<" 1. Start Game\n 2. Exit"<<endl;
    bool playing = asktoplay();
    while (playing == true){
        game();
        cout<<"Play again?\n1. Yes\n2. No"<<endl;
        playing = asktoplay();
    }
    return 0;
}