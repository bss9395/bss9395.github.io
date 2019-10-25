#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "mysql.h"

static char    *host     = "192.168.126.190";
static char    *user     = "qwe";
static char    *password = "1234567";
static char    *database = "scott";
static unsigned port     = 3306;
static char    *socket   = NULL;
static unsigned flag     = CLIENT_MULTI_STATEMENTS;

bool checkInitialWord(char *str, char *word, int len) {
    int i = 0;
    for(; i < len && str[i] != '\0' && word[i] != '\0'; ++i) {
        if(toupper(*str) != toupper(*word)){
            return false;
        }
    }
    return (i == len);
}

int checkError(MYSQL *mysql, const char *msg, bool failed) {
    if(failed) {
        unsigned int err = mysql_errno(mysql);
        printf("%s: %d: %s\n", msg, err, mysql_error(mysql));
        return err;
    }
    return 0;
}

void Welcome() {
    fprintf(stdout, "%s\n",
            "Reading table information for completion of table and column names\n"
            "You can turn off this feature to get a quicker startup with -A\n"
            "\n"
            "Welcome to the MySQL monitor.  Commands end with ; or \\g.\n"
            "Your MySQL connection id is 36\n"
            "Server version: 8.0.18 MySQL Community Server - GPL\n"
            "\n"
            "Copyright (c) 2000, 2019, Oracle and/or its affiliates. All rights reserved.\n"
            "\n"
            "Oracle is a registered trademark of Oracle Corporation and/or its\n"
            "affiliates. Other names may be trademarks of their respective\n"
            "owners.\n"
            "\n"
            "Type 'help;' or '\\h' for help. Type '\\c' to clear the current input statement.\n"
           );
}

static char *SETUP = "set names utf8";

static char *TEST_SQL = " "
"DROP TABLE IF EXISTS test_table; "
""
"CREATE TABLE test_table ( "
"   id INT "
"); "
" "
"INSERT INTO test_table "
"VALUES "
"(10); "
" "
"UPDATE test_table "
"SET id=20 "
"WHERE id=10; "
" "
"SELECT * "
"FROM test_table; ";

static int err = 0;

int main(int argc, char *argv[]) {
    MYSQL *mysql = mysql_init(NULL);
    mysql = mysql_real_connect(mysql, host, user, password, database, port, socket, flag);
    checkError(mysql, "mysql_real_connect", mysql == NULL);

    err = mysql_query(mysql, SETUP);
    checkError(mysql, "mysql_query", err != 0);

    Welcome();

    char prompt[BUFSIZ] = "mysql> ";
    char commandline[BUFSIZ] = { '\0' };
    for(; true;) {
        fprintf(stdout, prompt);
        fgets(commandline, sizeof(commandline), stdin);

        if (checkInitialWord(commandline, "QUIT", 4) || checkInitialWord(commandline, "EXIT", 4)) {
            break;
        }

        if(!(commandline[0] == '\n' || commandline[0] == '\0')) {
            err = mysql_query(mysql, commandline);
        }
        else{
            err = mysql_query(mysql, TEST_SQL);
        }
        checkError(mysql, "mysql_query", err != 0);

        int status = 0;
        do {
            MYSQL_RES *result = mysql_store_result(mysql);
            if(result) {
                unsigned cols = mysql_num_fields(result);
                MYSQL_FIELD *fields = mysql_fetch_fields(result);

                for(int c = 0; c < cols; ++c) {
                    printf("%*s", (int)strlen(fields[c].name) + 1, fields[c].name);
                }
                printf("\n");

                for(MYSQL_ROW row; row = mysql_fetch_row(result), row; ) {
                    unsigned long *lens = mysql_fetch_lengths(result);
                    for (int c = 0; c < cols; ++c) {
                        printf("%*.*s", (int)lens[c] + 1, (int)lens[c] + 1, row[c]);
                    }
                    printf("\n");
                }

                long rows = mysql_num_rows(result);
                printf("%ld row(s) in set...\n", rows);

                mysql_free_result(result);
            }
            else {
                unsigned long rows = mysql_affected_rows(mysql);
                fprintf(stdout, "%ld row(s) affected... \n", rows);
            }

            status = mysql_next_result(mysql);
            printf("mysql_next_result: %d\n", status);
        } while(status == 0);
    }

    mysql_close(mysql);
    return 0;
}
