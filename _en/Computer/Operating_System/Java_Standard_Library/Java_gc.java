/* Java_gc.java
Author: BSS9395
Update: 2023-01-06T20:53:00+08@China-Shanghai+08
Design: Java Garbage Collection: gc()
*/

/*
javac Java_gc.java
java -verbose:gc Java_gc
*/
public class Java_gc {
    static public Java_gc _java_gc = null;
    static public void main(String[] args) {
        // _Normal();
        _gc();
        // _runFinalization();
    }
    static public void _Normal() {
        System.out.println("static public void _gc() {");
        for (int i = 0; i < 4; i += 1) {
            new Java_gc();
        }
        System.out.println("========================================");
        _java_gc._Info();
    }
    static public void _gc() {
        System.out.println("static public void _gc() {");
        for (int i = 0; i < 4; i += 1) {
            new Java_gc();
        }
        // System.gc();
        Runtime.getRuntime().gc();               // invoke System.gc();
        System.out.println("========================================");
        _java_gc._Info();
    }
    static public void _runFinalization() {
        System.out.println("static public void _runFinalization() {");
        for (int i = 0; i < 4; i += 1) {
            new Java_gc();
        }
        // System.gc();
        // System.runFinalization();
        Runtime.getRuntime().gc();               // invoke System.gc();
        Runtime.getRuntime().runFinalization();
        System.out.println("========================================");
        _java_gc._Info();
    }
    public void finalize() {
        System.out.println("public void finalize() {");
        _java_gc = this;
    }
    public void _Info() {
        System.out.println("public void _Info() {");
    }
}
