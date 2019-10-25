#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "mysql.h" 

static MYSQL   *mysql    = NULL;
static char    *host     = "192.168.126.172";
static char    *user     = "qwe";
static char    *password = "1234567";
static char    *database = "scott";
static unsigned port     = 3306;
static char    *socket   = NULL;
static unsigned flag     = CLIENT_MULTI_STATEMENTS;

////////////////////////////////////////////////////////////////////////////////

static char *SETUP = "set names utf8";

static char *DROP_TABLE = " "
"DROP TABLE IF EXISTS test_table; ";

static char *CREATE_TABLE = " "
"CREATE TABLE IF NOT EXISTS test_table( "
"    col1 INT, "
"    col2 VARCHAR(40), "
"    col3 INT, "
"    col4 TIMESTAMP default now() "
"); ";

static char *INSERT_VALUES = " "
"INSERT INTO test_table "
"(col1, col2, col3, col4) "
"VALUES "
"(?, ?, ?, ?); ";

#define PARAMS 4

static int           col0         = 0;
static char          col1[BUFSIZ] = { '\0' };
static unsigned long col1_length  = 0;
static int           col2         = 0;
static bool          col2_is_null = false; 
static MYSQL_TIME    col3;
static bool          col3_is_null = false;

static MYSQL_STMT *stmt     = NULL;
static long        params   = 0;
static long        affected = 0;
static MYSQL_BIND  bind[PARAMS];

static void initialize() {
    bind[0].buffer_type = MYSQL_TYPE_LONG;
    bind[0].buffer = (char *)&col0;
    bind[0].buffer_length = sizeof(col0);
    bind[0].is_null = NULL;
    bind[0].length = 0;

    bind[1].buffer_type = MYSQL_TYPE_STRING;
    bind[1].buffer = (char *)col1;
    bind[1].buffer_length = sizeof(col1);
    bind[1].is_null = NULL;
    bind[1].length = &col1_length;

    bind[2].buffer_type = MYSQL_TYPE_LONG;
    bind[2].buffer = (char *)&col2;
    bind[2].buffer_length = sizeof(col2);
    bind[2].is_null = &col2_is_null;
    bind[2].length = 0;

    bind[3].buffer_type = MYSQL_TYPE_TIMESTAMP;
    bind[3].buffer = (char *)&col3;
    bind[3].buffer_length = sizeof(col3);
    bind[3].is_null = &col3_is_null;
    bind[3].length = 0;
}

////////////////////////////////////////////////////////////////////////////////

bool checkInitialWord(char *str, char *word, int len) {
    int i = 0;
    for(; i < len && str[i] != '\0' && word[i] != '\0'; ++i) {
        if(toupper(*str) != toupper(*word)){
            return false;            
        }
    }
    return (i == len);
}

int checkError(const char *msg, bool failed) {
    if(failed) {
        unsigned int err = mysql_errno(mysql);
        fprintf(stdout, "%s: %d: %s\n", msg, err, mysql_error(mysql));
        return err;
    }   

    return 0;
}

static int  err = 0;

int main(int argc, char *argv[]) { 
    initialize();

    mysql = mysql_init(NULL);
    mysql = mysql_real_connect(mysql, host, user, password, database, port, socket, flag);
    checkError("mysql_real_connect", mysql == NULL);

    err = mysql_query(mysql, SETUP);
    err = mysql_query(mysql, DROP_TABLE);
    err = mysql_query(mysql, CREATE_TABLE);
    checkError("mysql_query", err != 0);

    stmt = mysql_stmt_init(mysql);
    err = mysql_stmt_prepare(stmt, INSERT_VALUES, strlen(INSERT_VALUES));
    checkError("mysql_stmt_prepare", err != 0);
    params = mysql_stmt_param_count(stmt);
    fprintf(stdout, " %ld parameter(s) in the prepared statement...\n", params);

    err = mysql_stmt_bind_param(stmt, bind);
    checkError("mysql_stmt_bind_param", err != 0);

    col0 = 10;             
    strncpy(col1, "MySQL", BUFSIZ); 
    col1_length= strlen(col1);
    col2_is_null = true;
    col3_is_null = false;
    col3.year = 1993;
    col3.month = 9;
    col3.day = 5;
    col3.hour = 19;
    col3.minute = 30;
    col3.second = 00;

    err = mysql_stmt_execute(stmt);
    checkError("mysql_stmt_execute", err != 0);

    affected = mysql_stmt_affected_rows(stmt);
    fprintf(stdout, "%ld rows affected...\n", affected);


    col0 = 1000;
    strncpy(col1, "The most popular Open Source database", BUFSIZ);
    col1_length= strlen(col1);
    col2_is_null = false; 
    col2 = 100;  
    col3_is_null = true;


    err = mysql_stmt_execute(stmt);
    checkError("mysql_stmt_execute", err != 0);

    affected= mysql_stmt_affected_rows(stmt);
    fprintf(stdout, "%ld rows affected...\n", affected);


    mysql_stmt_close(stmt);
    mysql_close(mysql);
    return 0;	
}
