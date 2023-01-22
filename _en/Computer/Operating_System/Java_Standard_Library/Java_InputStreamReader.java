/* Java_InputStreamReader.java
Author: BSS9395
Update: 2023-01-08T17:08:00+08@China-Shanghai+08
Design: Java Standard Library: InputStreamReader
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_InputStreamReader {
    static public void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String line = null;
            while((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
}
