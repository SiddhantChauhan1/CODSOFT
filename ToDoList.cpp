#include <iostream>
#include <string.h>
using namespace std;
string tasks[10][2];
int n;
bool choosing = true;

void initialize(){
    cout<<"Enter Number of tasks to initilize: ";
    cin>>n;
    cout<<"Enter tasks below\n";
    for (int i=0;i<n;i++){
        cout<<"Task"<<i+1<<": ";
        string task;
        cin>>task;
        tasks[i][0] = task;
        tasks[i][1] = "pending";
    }
    cout<<"\nTasks added successfully!\n";
}

void viewlist(){
    cout<<"\nTASKS----------------\n";
    for (int i=0;i<n;i++){
        cout<<i+1<<". "<<tasks[i][0]<<" - "<<tasks[i][1]<<endl;
    }
}

void addtask(){
    if (n<10){
        cout<<"Add new Task: ";
        string task;
        cin>>task;
        tasks[n][0] = task;
        tasks[n][1] = "pending";
        n+=1;
        cout<<"\nTask added successfully!\n";
    }
    else{
        cout<<"Too Many tasks, remove one to add!"<<endl;
    }
}

void removetask(){
    cout<<"Which task number you want to remove? ";
    int toremove;
    cin>>toremove;
    for (int i=toremove;i<n;i++){
        tasks[i-1][0] = tasks[i][0];
        tasks[i-1][1] = tasks[i][1];
    }
    n-=1;
    cout<<"\nTask removed successfully!\n";
}

void marktask(){
    cout<<"Which task to you want to mark as done? ";
    int tomark;
    cin>>tomark;
    tasks[tomark-1][1] = "completed";
}

void choose(){
    cout<<"\n 1. View Tasks\n 2. Add Task\n 3. Remove Task\n 4. Mark Task as done\n 5. Exit\n";
    int choice;
    cin>>choice;
    switch (choice){
        case 1:
            viewlist();
            break;
        case 2:
            addtask();
            break;
        case 3:
            removetask();
            break;
        case 4:
            marktask();
            break;
        case 5:
            choosing = false;
            break;
    }
}

int main(){
    cout<<"\nTo-Do List--------------------\n\n";
    initialize();
    while (choosing == true){
        choose();
    }
    return 0;
}