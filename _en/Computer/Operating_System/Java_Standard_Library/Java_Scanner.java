/* Java_Scanner.java
Author: BSS9395
Update: 2023-01-07T22:47:00+08@China-Shanghai+08
Design: Java Standard Library: Scanner
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Java_Scanner {
    static public void main(String[] args) {
        _Scanner_System_in();
        // _Scanner_File();
    }
    static public void _Scanner_System_in() {
        Scanner scanner = new Scanner(System.in);
        scanner.useDelimiter("\n");
        while(scanner.hasNext() == true) {
            System.out.println(scanner.next());
        }
    }
    static public void _Scanner_File() {
        try {
            Scanner scanner = new Scanner(new File("Java_Scanner.java"));
            while(scanner.hasNextLine() == true) {
                System.out.println(scanner.nextLine());
            }
        } catch (FileNotFoundException exception) {
            exception.printStackTrace();
        }
    }
}
