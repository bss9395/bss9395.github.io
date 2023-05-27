/* Composition.java
Author: BSS9395
Update: 2023-05-26T17:08:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Composition
*/

import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

abstract class Employee {
    public String _type      = null;
    public String _name      = null;
    public List   _employees = null;
    abstract public void _Add(Employee employee);
    abstract public void _Remove(Employee employee);
    public void _Print_Info() {
        System.out.printf("[%s:%s]{ ", _type, _name);
        boolean first = true;
        ListIterator<Employee> iter = _employees.listIterator();
        while(iter.hasNext()) {
            Employee employee = iter.next();
            if(first == true) {
                first = false;
                System.out.printf("[%s:%s]", employee._type, employee._name);
            } else {
                System.out.printf(", [%s:%s]", employee._type, employee._name);
            }
        }
        System.out.println(" }");
    }
}

class Manager extends Employee {
    public Manager(String name) {
        this._type = "经理";
        this._name = name;
        _employees = new ArrayList();
    }
    public void _Add(Employee employee) {
        _employees.add(employee);
    }
    public void _Remove(Employee employee) {
        _employees.remove(employee);
    }
}

class Assistant extends Employee {
    public Assistant(String name) {
        this._type = "助手";
        this._name = name;
        _employees = null;
    }
    public void _Add(Employee employee) {

    }
    public void _Remove(Employee employee) {

    }
}

class Programmer extends Employee {
    public Programmer(String name) {
        this._type = "程序员";
        this._name = name;
        _employees = null;
    }
    @Override
    public void _Add(Employee employee) {

    }
    @Override
    public void _Remove(Employee employee) {

    }
}

public class Composition {
    public static void main(String[] args) {
        Employee manager    = new Manager("项目经理");
        Employee assistant  = new Assistant("项目助理");
        Employee programmer = new Programmer("程序员");

        manager._Add(assistant);
        manager._Add(programmer);
        manager._Print_Info();
    }
}

