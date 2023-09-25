#include "tasks.h"
#include "database.h"
#include <stdexcept>
#include <iostream>
#include <boost/format.hpp>

using namespace std;

void Tasks::create(string name){
    if(name == ""){
        cerr << "name is empty: " << name << endl;
        exit(EXIT_FAILURE);
    }

    try {
        Db* database = new Db();
        string sql = "INSERT INTO tasks (name, status_id) VALUES ('%1%', 1);";
        sql = (boost::format(sql) % name).str();
        database -> execute(sql);
    } catch (sql::SQLException &e) {
        cerr << "# ERR: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Tasks::done_task(int task_id){
    if(task_id == NULL){
        cerr << "task_id is empty: " << task_id << endl;
        exit(EXIT_FAILURE);
    }

    try {
        Db* database = new Db();
        string sql = "UPDATE tasks SET status_id=2 WHERE id=%1%;";
        sql = (boost::format(sql) % task_id).str();
        database -> execute(sql);
    } catch (sql::SQLException &e) {
        cerr << "# ERR: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Tasks::destroy(int task_id){
    if(task_id == NULL){
        cerr << "task_id is empty: " << task_id << endl;
        exit(EXIT_FAILURE);
    }

    try {
        Db* database = new Db();
        string sql = "DELETE FROM tasks WHERE id=%1%;";
        sql = (boost::format(sql) % task_id).str();
        database -> execute(sql);
    } catch (sql::SQLException &e) {
        cerr << "# ERR: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Tasks::update(string name, int task_id){
    if(task_id == NULL){
        cerr << "task_id is empty: " << task_id << endl;
        exit(EXIT_FAILURE);
    }
    if(name == ""){
        cerr << "name is empty: " << name << endl;
        exit(EXIT_FAILURE);
    }
    cout << name << endl;
    cout << task_id << endl;
    try {
        Db* database = new Db();
        string sql = "UPDATE tasks SET name='%1%' WHERE id=%2%;";
        sql = (boost::format(sql) % name % task_id).str();
        database -> execute(sql);
    } catch (sql::SQLException &e) {
        cerr << "# ERR: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

void Tasks::index(){
    try {
        Db* database = new Db();
        string sql = "SELECT name, created_at FROM tasks WHERE status_id=1;";
        sql::ResultSet* result = database -> execute(sql);
        if (result != NULL){
            while(result -> next()){
                cout << result->getString(1) << "  " << result->getString(2) << endl;
            }
        }
    } catch (sql::SQLException &e) {
        cerr << "# ERR: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}