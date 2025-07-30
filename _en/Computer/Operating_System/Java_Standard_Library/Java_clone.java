class Student1 {
    private int _number;

    public int getNumber() {
        return _number;
    }

    public void setNumber(int number) {
        _number = number;
    }
}

class Address2 {
    private String _address;

    public String getAddress() {
        return _address;
    }

    public void setAddress(String address) {
        _address = address;
    }
}

class Student2 implements Cloneable {
    private int _number;
    private Address2 _address;

    public Address2 getAddress() {
        return _address;
    }

    public void setAddress(Address2 address) {
        _address = address;
    }

    public int getNumber() {
        return _number;
    }

    public void setNumber(int number) {
        _number = number;
    }

    @Override
    public Object clone() {
        Student2 student = null;
        try {
            student = (Student2)super.clone();   //浅复制
        } catch(CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return student;
    }
}

class Address3 implements Cloneable {
    private String _address;

    public String getAddress() {
        return _address;
    }

    public void setAddress(String address) {
        _address = address;
    }

    @Override
    public Object clone() {
        Address3 address = null;
        try {
            address = (Address3)super.clone();
        } catch(CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return address;
    }
}

class Student3 implements Cloneable {
    private int _number;
    private Address3 _address;

    public Address3 getAddress() {
        return _address;
    }

    public void set_address(Address3 address) {
        _address = address;
    }

    public int getNumber() {
        return _number;
    }

    public void setNumber(int number) {
        _number = number;
    }

    @Override
    public Object clone() {
        Student3 student = null;
        try {
            student = (Student3)super.clone();   //浅复制
        } catch(CloneNotSupportedException e) {
            e.printStackTrace();
        }
        student._address = (Address3) _address.clone();   //深度复制
        return student;
    }
}

public class Java_clone {
    public static void Test_ShadowCopy() {
        Student1 stu1 = new Student1();
        stu1.setNumber(12345);
        Student1 stu2 = stu1;
        stu1.setNumber(54321);
        System.out.println("学生1:" + stu1.getNumber());
        System.out.println("学生2:" + stu2.getNumber());
    }

    public static void Test_ShadowClone() {
        Address2 addr = new Address2();
        addr.setAddress("杭州市");
        Student2 stu1 = new Student2();
        stu1.setNumber(123);
        stu1.setAddress(addr);

        Student2 stu2 = (Student2)stu1.clone();
        System.out.println("学生1: " + stu1.getNumber() + ", 地址: " + stu1.getAddress().getAddress());
        System.out.println("学生2: " + stu2.getNumber() + ", 地址: " + stu2.getAddress().getAddress());

        addr.setAddress("西湖区");
        System.out.println("学生1: " + stu1.getNumber() + ", 地址: " + stu1.getAddress().getAddress());
        System.out.println("学生2: " + stu2.getNumber() + ", 地址: " + stu2.getAddress().getAddress());
    }

    public static void Test_DeepClone() {
        Address3 addr = new Address3();
        addr.setAddress("杭州市");
        Student3 stu1 = new Student3();
        stu1.setNumber(123);
        stu1.set_address(addr);

        Student3 stu2 = (Student3)stu1.clone();
        System.out.println("学生1:" + stu1.getNumber() + ",地址:" + stu1.getAddress().getAddress());
        System.out.println("学生2:" + stu2.getNumber() + ",地址:" + stu2.getAddress().getAddress());

        addr.setAddress("西湖区");
        System.out.println("学生1:" + stu1.getNumber() + ",地址:" + stu1.getAddress().getAddress());
        System.out.println("学生2:" + stu2.getNumber() + ",地址:" + stu2.getAddress().getAddress());
    }

    public static void main(String[] args) {
        // Test_ShadowCopy();
        Test_ShadowClone();
        // Test_DeepClone();
    }
}