import java.sql.*;

public class Java_DatabaseMetaData {
    static public String _driver   = "com.mysql.cj.jdbc.Driver";
    static public String _schema   = "jdbc:mysql://";
    static public String _address  = "192.168.190.137:3306/?useSSL=false&serverTimezone=UTC";
    static public String _username = "bss9395";
    static public String _password = "Password";

    static public void main(String[] args) throws Exception {
        _DatabaseMetaData();
    }
    static public void _DatabaseMetaData() throws Exception {
        Connection connection = DriverManager.getConnection(_schema + _address, _username, _password);
        DatabaseMetaData meta = connection.getMetaData();
        System.out.printf("DatabaseMetaData.getDatabaseProductName() = %s%n", meta.getDatabaseProductName());
        System.out.printf("DatabaseMetaData.getDatabaseProductVersion() = %s%n", meta.getDatabaseProductVersion());
        System.out.printf("DatabaseMetaData.getDriverName() = %s%n", meta.getDriverName());
        System.out.printf("DatabaseMetaData.getDriverVersion() = %s%n", meta.getDriverVersion());

        ////////////////////////////////////////////////////////////////////////

        _Print_ResultSet("DatabaseMetaData.getTableTypes();",
                meta.getTableTypes());

        _Print_ResultSet("DatabaseMetaData.getTables();",
                meta.getTables("Management", null, "%", new String[] { "TABLE", "VIEW" }));

        _Print_ResultSet("DatabaseMetaData.getPrimaryKeys();",
                meta.getPrimaryKeys("Management", null, "Student"));

        _Print_ResultSet("DatabaseMetaData.getProcedures();",
                meta.getProcedures("Management", null, "%"));

        _Print_ResultSet("DatabaseMetaData.getCrossReference();",
                meta.getCrossReference("Management", null, "Teacher", null, null, "Student"));

        _Print_ResultSet("DatabaseMetaData.getColumns();",
                meta.getColumns("Management", null, "Student", "%"));
    }
    static public void _Print_ResultSet(String tip, ResultSet result) {
        try {
            System.out.printf("%n====%s============================================================================%n", tip);
            ResultSetMetaData meta = result.getMetaData();
            int[]    widths  = new int[1 + meta.getColumnCount()];
            String[] formats = new String[1 + meta.getColumnCount()];
            for(int i = 1; i <= meta.getColumnCount(); i += 1) {
                String text = meta.getColumnName(i);
                if(text == null) {
                    text = "NULL";
                }
                if(widths[i] < text.length()) {
                    widths[i] = text.length();
                }
            }
            result.beforeFirst();
            while(result.next() == true) {
                for(int i = 1; i <= meta.getColumnCount(); i += 1) {
                    String text = result.getString(i);
                    if(text == null) {
                        text = "NULL";
                    }
                    if(widths[i] < text.length()) {
                        widths[i] = text.length();
                    }
                }
            }
            for(int i = 1; i <= meta.getColumnCount(); i += 1) {
                formats[i] = String.format("|%%%ds", widths[i]);
            }

            ////////////////////////////////////////////////////////////////////

            for (int i = 1; i <= meta.getColumnCount(); i += 1) {
                System.out.printf(formats[i], meta.getColumnName(i));
            }
            System.out.println("|");

            result.beforeFirst();
            while(result.next() == true) {
                for(int i = 1; i <= meta.getColumnCount(); i += 1) {
                    System.out.printf(formats[i], result.getString(i));
                }
                System.out.println(" |");
            }
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }
}
