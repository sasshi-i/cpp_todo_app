#include "database.h"
#include <stdexcept>

#define DB_URL "tcp://db:3306"
#define DBUSER "root"
#define DBPASS "password"
#define DBNAME "todo"

using namespace std;

Db::Db(){
    try{
        driver = get_driver_instance();
        con = driver -> connect(DB_URL, DBUSER, DBPASS);
        con->setSchema("todo");
    } catch (exception &e) {
        cerr << "# ERR: in " << __FILE__ << " on line " << __LINE__ << endl;
        cerr << "# ERR: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

Db::~Db(){
    if(con){
        delete con;
        delete stmt;
        delete pstmt;
        delete result;
    }
}

sql::ResultSet* Db::execute(string sql){
    try {
        pstmt = con->prepareStatement(sql);
        result = pstmt->executeQuery();
        return result;
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__ << " on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        exit(EXIT_FAILURE);
    }
    
}