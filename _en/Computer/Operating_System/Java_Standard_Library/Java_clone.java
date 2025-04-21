class Student1 {
    private int number;

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }
}

class Address2 {
    private String add;

    public String getAdd() {
        return add;
    }

    public void setAdd(String add) {
        this.add = add;
    }
}

class Student2 implements Cloneable {
    private int number;

    private Address2 addr;

    public Address2 getAddr() {
        return addr;
    }

    public void setAddr(Address2 addr) {
        this.addr = addr;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    @Override
    public Object clone() {
        Student2 stu = null;
        try{
            stu = (Student2)super.clone();   //浅复制
        }catch(CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return stu;
    }
}

class Address3 implements Cloneable {
    private String add;

    public String getAdd() {
        return add;
    }

    public void setAdd(String add) {
        this.add = add;
    }

    @Override
    public Object clone() {
        Address3 addr = null;
        try{
            addr = (Address3)super.clone();
        }catch(CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return addr;
    }
}

class Student3 implements Cloneable{
    private int number;

    private Address3 addr;

    public Address3 getAddr() {
        return addr;
    }

    public void setAddr(Address3 addr) {
        this.addr = addr;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    @Override
    public Object clone() {
        Student3 stu = null;
        try{
            stu = (Student3)super.clone();   //浅复制
        }catch(CloneNotSupportedException e) {
            e.printStackTrace();
        }
        stu.addr = (Address3)addr.clone();   //深度复制
        return stu;
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
        addr.setAdd("杭州市");
        Student2 stu1 = new Student2();
        stu1.setNumber(123);
        stu1.setAddr(addr);

        Student2 stu2 = (Student2)stu1.clone();
        System.out.println("学生1:" + stu1.getNumber() + ",地址:" + stu1.getAddr().getAdd());
        System.out.println("学生2:" + stu2.getNumber() + ",地址:" + stu2.getAddr().getAdd());

        addr.setAdd("西湖区");
        System.out.println("学生1:" + stu1.getNumber() + ",地址:" + stu1.getAddr().getAdd());
        System.out.println("学生2:" + stu2.getNumber() + ",地址:" + stu2.getAddr().getAdd());
    }

    public static void Test_DeepClone() {
        Address3 addr = new Address3();
        addr.setAdd("杭州市");
        Student3 stu1 = new Student3();
        stu1.setNumber(123);
        stu1.setAddr(addr);

        Student3 stu2 = (Student3)stu1.clone();
        System.out.println("学生1:" + stu1.getNumber() + ",地址:" + stu1.getAddr().getAdd());
        System.out.println("学生2:" + stu2.getNumber() + ",地址:" + stu2.getAddr().getAdd());

        addr.setAdd("西湖区");
        System.out.println("学生1:" + stu1.getNumber() + ",地址:" + stu1.getAddr().getAdd());
        System.out.println("学生2:" + stu2.getNumber() + ",地址:" + stu2.getAddr().getAdd());
    }

    public static void main(String[] args) {
        // Test_ShadowCopy();
        Test_ShadowClone();
        // Test_DeepClone();
    }
}