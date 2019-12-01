#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "mysql.h"

static char    *host     = "localhost";
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
		int err = mysql_errno(mysql);
		printf("%s: %d: %s\n", msg, err, mysql_error(mysql));
		return err;
	}
	return 0;
}

static char *CREATE_TABLE = " "
"set names utf8; "
" "
"DROP TABLE IF EXISTS test_table; "
" "
"CREATE TABLE test_table ( "
"	 col1 INT, "
"    col2 VARCHAR(10), "
"    col3 VARCHAR(10) "
"); ";

static char *SQL01 = "INSERT INTO test_table(col1,col2,col3) VALUES(10, 'AAA', 'A1'); ";
static char *SQL02 = "INSERT INTO test_table(col1,col2,col3) VALUES(20, 'BBB', 'B2'); ";
static char *SQL03 = "INSERT INTO test_table(col1,col2,col3) VALUES(30, 'CCC', 'C3'); ";
static char *SQL04 = "INSERT INTO test_table(col1,col2,col3) VALUES(40, 'DDD', 'D4'); ";

MYSQL *Connect(const char *host, const char *user, const char *password, const char *database, unsigned int port, const char *socket, unsigned long flag) {
	MYSQL *init = mysql_init(NULL);
	init = mysql_real_connect(init, host, user, password, database, port, socket, flag);
	checkError(init, "Connect", init == NULL);

	return init;	
}

void echoResult(MYSQL *mysql, const char *msg) {
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
		fprintf(stdout, "%s: %ld row(s) affected... \n", msg, rows);
	}
}

int Query(MYSQL *mysql, const char *sql) {
	int err = mysql_query(mysql, sql);
	checkError(mysql, "Query", err != 0);

	int status = 0;
	do {
		echoResult(mysql, "Query");
		status = mysql_next_result(mysql);
		printf("mysql_next_result: %d\n", status);
	} while(status == 0);
	return err;
}

int Transaction(MYSQL *mysql, bool automatic) {
	int err = mysql_query(mysql, "start transaction; ");
	if(automatic) {
		err = mysql_query(mysql, "set autocommit = 1; ");
	} 
	else {
		err = mysql_query(mysql, "set autocommit = 0; ");
	}
	checkError(mysql, "Transaction", err != 0);
	echoResult(mysql, "Transaction");

	return err;
}

int Commit(MYSQL *mysql) {
	int err = mysql_query(mysql, "commit; ");
	checkError(mysql, "Commit", err != 0);
	echoResult(mysql, "Commit");
	return err;
}

int Rollback(MYSQL *mysql) {
	int err = mysql_query(mysql, "rollback; ");
	checkError(mysql, "Rollback", err != 0);
	echoResult(mysql, "rollback");
	return err;
}

int main(int argc, char *argv[]) {
	MYSQL *mysql = Connect(host, user, password, database, port, socket, flag);
	Query(mysql, CREATE_TABLE);

	Transaction(mysql, false);
	Query(mysql, SQL01);
	Query(mysql, SQL02);
	Commit(mysql); 

	Transaction(mysql, true);
	Transaction(mysql, false);
	Query(mysql, SQL03);
	Query(mysql, SQL04);
	Rollback(mysql);

	mysql_close(mysql);
	return 0;
}
