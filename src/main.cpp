#include "tasks.h"
#include <iostream>
#include <cstring>

using namespace std;

void help(){
    cout << "a <name> add a task\n";
    cout << "i show Incomplete tasks\n";
    cout << "u <name> <task_id> update a task\n";
    cout << "do <task_id> done a task\n";
    cout << "d <task_id> destroy a task\n";
}

void action(char *argv[]){
    Tasks* tasks = new Tasks();
    if(strcmp(argv[1], "a") == 0){
        tasks->create(argv[2]);
    } else if(strcmp(argv[1], "i") == 0){ 
        tasks->index();
    } else if(strcmp(argv[1], "u") == 0){
        tasks->update(argv[2], static_cast<int>(*argv[3] - '0'));
    } else if(strcmp(argv[1], "do") == 0){
        tasks->done_task(static_cast<int>(*argv[2] - '0'));
    } else if(strcmp(argv[1], "d") == 0){
        tasks->done_task(static_cast<int>(*argv[2] - '0'));
    } else {
        help();
    }
    delete tasks;
}

int main(int argc, char *argv[]) {
    action(argv);
    return 0;
}