#ifndef _H_DATABASE_
#define _H_DATABASE_

#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

class Db{
    protected:
      sql::Driver *driver;
      sql::Connection *con;
      sql::Statement *stmt;
      sql::PreparedStatement *pstmt;
      sql::ResultSet *result;

    public:
      sql::ResultSet* execute(const string sql);
      Db();
      ~Db();
};

#endif