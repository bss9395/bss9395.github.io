/*MySQL_query.c
* gcc -lmysqlclient -I/usr/include/mysql
*/

#if 0
• my_init() : Initializes global variables and the thread handler in thread - safe programs.
• mysql_affected_rows() : Returns the number of rows changed / deleted / inserted by the last UPDATE, DELETE, or INSERT query.
• mysql_autocommit() : Toggles autocommit mode on / off.
• mysql_change_user() : Changes the user and database on an open connection.
• mysql_character_set_name() : Returns the default character set name for the current connection.
• mysql_client_find_plugin() : Returns a pointer to a plugin.
• mysql_client_register_plugin() : Registers a plugin.
• mysql_close() : Closes a server connection.
• mysql_commit() : Commits the transaction.
• mysql_connect() : Connects to a MySQL server.This function is deprecated; use mysql_real_connect() instead.
• mysql_create_db() : Creates a database.This function is deprecated; use the SQL statement CREATE DATABASE instead.
• mysql_data_seek() : Seeks to an arbitrary row number in a query result set.
• mysql_debug() : Does a DBUG_PUSH with the given string.
• mysql_drop_db() : Drops a database.This function is deprecated; use the SQL statement DROP DATABASE instead.
• mysql_dump_debug_info() : Causes the server to write debug information to the log.
• mysql_eof() : Determines whether the last row of a result set has been read.This function is deprecated; use mysql_errno() or mysql_error() instead.
• mysql_errno() : Returns the error number for the most recently invoked MySQL function.
• mysql_error() : Returns the error message for the most recently invoked MySQL function.
• mysql_escape_string() : Escapes special characters in a string for use in an SQL statement.
• mysql_fetch_field() : Returns the type of the next table field.
• mysql_fetch_field_direct() : Returns the type of a table field, given a field number.
• mysql_fetch_fields() : Returns an array of all field structures.
• mysql_fetch_lengths() : Returns the lengths of all columns in the current row.
• mysql_fetch_row() : Fetches the next row from the result set.
• mysql_field_count() : Returns the number of result columns for the most recent statement.
• mysql_field_seek() : Puts the column cursor on a specified column.
• mysql_field_tell() : Returns the position of the field cursor used for the last mysql_fetch_field().
• mysql_free_result() : Frees memory used by a result set.
• mysql_get_character_set_info() : Returns information about default character set.
• mysql_get_client_info() : Returns client version information as a string.
• mysql_get_client_version() : Returns client version information as an integer.
• mysql_get_host_info() : Returns a string describing the connection.
• mysql_get_option() : Returns the value of a mysql_options() option.
• mysql_get_proto_info() : Returns the protocol version used by the connection.
• mysql_get_server_info() : Returns the server version number.
• mysql_get_server_version() : Returns the server version number as an integer.
• mysql_get_ssl_cipher() : Returns the current SSL cipher.
• mysql_hex_string() : Encodes a string in hexadecimal format.
• mysql_info() : Returns information about the most recently executed query.
• mysql_init() : Gets or initializes a MYSQL structure.
• mysql_insert_id() : Returns the ID generated for an AUTO_INCREMENT column by the previous query.
• mysql_kill() : Kills a given thread.
• mysql_library_end() : Finalizes the MySQL C API library.
• mysql_library_init() : Initializes the MySQL C API library.
• mysql_list_dbs() : Returns database names matching a simple regular expression.
• mysql_list_fields() : Returns field names matching a simple regular expression.
• mysql_list_processes() : Returns a list of the current server threads.
• mysql_list_tables() : Returns table names matching a simple regular expression.
• mysql_load_plugin() : Loads a plugin.
• mysql_load_plugin_v() : Loads a plugin.
• mysql_more_results() : Checks whether any more results exist.
• mysql_next_result() : Returns / initiates the next result in multiple - result executions.
• mysql_num_fields() : Returns the number of columns in a result set.
• mysql_num_rows() : Returns the number of rows in a result set.
• mysql_options() : Sets connect options for mysql_real_connect().
• mysql_options4() : Sets connect options for mysql_real_connect().
• mysql_ping() : Checks whether the connection to the server is working, reconnecting as necessary.
• mysql_plugin_options() : Sets a plugin option.
• mysql_query() : Executes an SQL query specified as a null - terminated string.
• mysql_real_connect() : Connects to a MySQL server.
• mysql_real_escape_string() : Escapes special characters in a string for use in an SQL statement, taking into account the current character set of the connection.
• mysql_real_escape_string_quote() : Escapes special characters in a string for use in an SQL statement, taking into account the current character set of the connection and the quoting context.
• mysql_real_query() : Executes an SQL query specified as a counted string.
• mysql_refresh() : Flushes or resets tables and caches.
• mysql_reload() : Tells the server to reload the grant tables.
• mysql_reset_connection() : Resets the connection to clear session state.
• mysql_reset_server_public_key() : Clears a cached RSA public key from the client library.
• mysql_result_metadata() : Whether a result set has metadata.
• mysql_rollback() : Rolls back the transaction.
• mysql_row_seek() : Seeks to a row offset in a result set, using value returned from mysql_row_tell().
• mysql_row_tell() : Returns the row cursor position.
• mysql_select_db() : Selects a database.
• mysql_server_end() : Finalizes the MySQL C API library.
• mysql_server_init() : Initializes the MySQL C API library.
• mysql_session_track_get_first() : Gets the first part of session state - change information.
• mysql_session_track_get_next() : Gets the next part of session state - change information.
• mysql_set_character_set() : Sets the default character set for the current connection.
• mysql_set_local_infile_default() : Sets the LOAD DATA LOCAL handler callbacks to their default values.
• mysql_set_local_infile_handler() : Installs application - specific LOAD DATA LOCAL handler callbacks.
• mysql_set_server_option() : Sets an option for the connection(like multi - statements).
• mysql_sqlstate() : Returns the SQLSTATE error code for the last error.
• mysql_shutdown() : Shuts down the database server.
• mysql_ssl_set() : Prepares to establish an SSL connection to the server.
• mysql_stat() : Returns the server status as a string.
• mysql_store_result() : Retrieves a complete result set to the client.
• mysql_thread_end() : Finalizes a thread handler.
• mysql_thread_id() : Returns the current thread ID.
• mysql_thread_init() : Initializes a thread handler.
• mysql_thread_safe() : Returns 1 if the clients are compiled as thread - safe.
• mysql_use_result() : Initiates a row - by - row result set retrieval.
• mysql_warning_count() : Returns the warning count for the previous SQL statement.
#endif


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "mysql/mysql.h"

static char     host[128] = "127.0.0.1";
static char     user[128] = "root";
static char     password[128] = "Password9395";
static char     database[128] = "mysql";
static unsigned port = 3306;
static char     *unix_socket = NULL;
static unsigned clientflag = CLIENT_MULTI_STATEMENTS;

bool checkInitialWord(const char *str, const char *word, int len) {
	int i = 0;
	for (; i < len && str[i] != '\0' && word[i] != '\0'; ++i) {
		if (toupper(*str) != toupper(*word)) {
			return false;
		}
	}
	return (i == len);
}

int checkError(MYSQL *mysql, const char *msg, bool failed) {
	if (failed) {
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

static char SETUP[512] = "set names utf8";

static char TEST_SQL[512] = " "
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
	mysql = mysql_real_connect(mysql, host, user, password, database, port, unix_socket, clientflag);
	checkError(mysql, "mysql_real_connect", mysql == NULL);

	err = mysql_query(mysql, SETUP);
	checkError(mysql, "mysql_query", err != 0);

	Welcome();

	char prompt[BUFSIZ] = "mysql> ";
	char commandline[BUFSIZ] = { '\0' };
	for (; true;) {
		fprintf(stdout, prompt);
		fgets(commandline, sizeof(commandline), stdin);

		if (checkInitialWord(commandline, "QUIT", 4) || checkInitialWord(commandline, "EXIT", 4)) {
			break;
		}

		if (!(commandline[0] == '\n' || commandline[0] == '\0')) {
			err = mysql_query(mysql, commandline);
		}
		else {
			err = mysql_query(mysql, TEST_SQL);
		}
		checkError(mysql, "mysql_query", err != 0);

		int status = 0;
		do {
			MYSQL_RES *result = mysql_store_result(mysql);
			if (result) {
				unsigned cols = mysql_num_fields(result);
				MYSQL_FIELD *fields = mysql_fetch_fields(result);

				for (int c = 0; c < cols; ++c) {
					printf("%*s", (int)strlen(fields[c].name) + 1, fields[c].name);
				}
				printf("\n");

				for (MYSQL_ROW row; row = mysql_fetch_row(result), row; ) {
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
		} while (status == 0);
	}

	mysql_close(mysql);
	return 0;
}
