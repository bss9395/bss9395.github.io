set CLASSPATH=%CLASSPATH%;./mysql-connector-j-8.0.31.jar

javac JDBC_DataSource.java -encoding       UTF-8
java  JDBC_DataSource      -Dfile.encoding=UTF-8

cmd
