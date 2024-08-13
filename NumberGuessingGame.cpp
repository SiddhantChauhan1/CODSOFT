#include <iostream>
#include <cstdlib>  
#include <ctime>  
using namespace std;

int welcome(){
    int response;
    cout<<"Welcome to Number Guessing Game!";
    cout<< "\n 1. Start Game \n 2. How To Play? \n 3. Exit \n";
    cin>>response;
    return response;
}

void game(){
    // Choose Level
    int level;
    cout<<"Choose level: ";
    cout<<"\n1. Easy (1-25)\n2. Hard (1-100)\n";
    cin>>level;
    int lvlnum = (level==1)?25:100;
    // Generate random number
    srand(time(0));
    int num = (rand() % lvlnum + 1);
    cout<<"A random number has been generated bw 1 and "<<lvlnum<<"! \n";
    // Start Game
    bool game_running = true;
    int guess = 0;
    int i=1;
    while (game_running == true) {
        cout<<"Guess "<<i<<": ";
        cin>>guess;
        if (guess == num){
            cout<<"Correct!!!\n";
            cout<<"Number guessed in "<<i<<" tries!\n\n";
            game_running=false;
        }
        else {
            cout<<"Wrong guess!\n";
            if (num<guess) {
                cout<<"Too High\n";
            }
            else {cout<<"Too Low\n";}
            i+=1;
        }
    }
}
void tutorial(){
    cout<<"In this game, the program generates a random number between 1 and 50 and the user has to guess it.";
    cout<<"\nIf the user guesses it incorrectly, the program will print whether the guessed number is higher or lower than the real number.";
    cout<<"\nThe game ends once the user guesses the number correctly.";
}

int main(){
    int response = welcome();
    if (response==1) {
        bool playing = true;
        while (playing){
            game();
            cout<<"\n Play again? (1: yes  2: no)";
            int choice;
            cin>>choice;
            if (choice == 2) {
                cout<<"THANKS FOR PLAYING!";
                playing = false;
            }
        }
    }
    else if (response==2) {
        tutorial();
    }
    else if (response==3) {
    }
    else {
        cout<<"Wrong choice, Enter 1/2/3";
    }
    return 0;
}