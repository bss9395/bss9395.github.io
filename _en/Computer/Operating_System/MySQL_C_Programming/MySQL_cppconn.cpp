/* mysql_cppconn.cpp
* g++ -lmysqlcppconn mysql_cppconn.cpp
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <memory>

using std::cin;
using std::cout;
using std::clog;
using std::cerr;
using std::endl;
using std::setw;
using std::string;

#include "cppconn/driver.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"
#include "cppconn/resultset.h"
#include "cppconn/exception.h"

using ::get_driver_instance;
using sql::Driver;
using sql::Connection;
using sql::Statement;
using sql::ResultSet;
using sql::SQLException;

static const char *URI      = "tcp://192.168.12.127";
static const char *USER     = "abc";
static const char *PASSWORD = "1234567";
static const char *DATABASE = "mysql";

static const char *SQL = ""
    "SELECT user, host, plugin from mysql.user;";

int main(int argc, char *argv[]) {
    try {
        Driver *driver = get_driver_instance();
        Connection *connection = driver->connect(URI, USER, PASSWORD);
        connection->setSchema(DATABASE);

        Statement *statement = connection->createStatement();
        ResultSet *resultSet = statement->executeQuery(SQL);

        while(resultSet->next()) {
            cout << setw(20) << resultSet->getString(1) << "  ";
            cout << setw(20) << resultSet->getString("user") << "  ";
            cout << setw(20) << resultSet->getString("host") << "  ";
            cout << setw(20) << resultSet->getString("plugin") << "  ";
            cout << endl;
        }
    } catch (SQLException &ex) {
        cerr << "\e[33m" << ex.what() << "\e[0m" << endl;
        cerr << "\e[33m" << ex.getErrorCode() << "\e[0m" << endl;
        cerr << "\e[33m" << ex.getSQLState() << "\e[0m" << endl;
    }

    return 0;
}

