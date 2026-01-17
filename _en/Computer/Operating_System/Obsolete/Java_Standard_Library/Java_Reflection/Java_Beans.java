/* Java_Beans.java
Author: bss9395
Update: 2025/09/26T17:36:00+08@China-GuangDong-ZhanJiang+08
*/

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Java_Beans {
    static public void main(String[] args) {
        String value = "empno:7369|ename:Smith|job:Clerk|salary:750.00|hiredate:1989-10-10";
        value = value + "|dept.name:财务部|dept.company.name:MLDN";
        Emp emp = ClassInstanceFactory.create(Emp.class, value);
        System.out.println("雇员编号：" + emp.getEmpno() + "姓名：" + emp.getEname() + ", 职位：" + emp.getJob() + ", 基本工资：" + emp.getSalary() + "，雇佣日期：" + emp.getHiredate());
        System.out.println(emp.getDept().getName());
        System.out.println(emp.getDept().getCompany().getName());
    }
}

class ClassInstanceFactory {
    private ClassInstanceFactory() { }
    static public <T> T create(Class<T> clazz, String value) {
        try {
            Object obj = clazz.getDeclaredConstructor().newInstance();
            BeanUtils.setValue(obj, value);
            return (T)obj;
        } catch (Exception exception) {
            exception.printStackTrace();
        }
        return null;
    }
}

class StringUtils {
    static public String initcap(String str) {
        if(str == null || "".equals(str)) {
            return str;
        }
        return str.substring(0, 1).toUpperCase() + str.substring(1);
    }
}

class BeanUtils {
    private BeanUtils() {}
    public static void setValue(Object obj, String value) {
        String[] results = value.split("[|]");
        for(int x = 0; x < results.length; x += 1) {
            String[] attval = results[x].split(":");
            try {
                String[] temp = attval[0].split("[.]");
                Object currentObject = obj;
                if(attval[0].contains(".")) {
                    for (int y = 0; y < temp.length - 1; y += 1) {
                        Method getMethod = currentObject.getClass().getDeclaredMethod("get" + StringUtils.initcap(temp[y]));
                        Object tempObject = getMethod.invoke(currentObject);
                        if (tempObject == null) {
                            Field field = currentObject.getClass().getDeclaredField(temp[y]);
                            Method method = currentObject.getClass().getDeclaredMethod("set" + StringUtils.initcap(temp[y]), field.getType());
                            Object newObject = field.getType().getDeclaredConstructor().newInstance();
                            method.invoke(currentObject, newObject);
                            currentObject = newObject;
                        } else {
                            currentObject = tempObject;
                        }
                    }
                }
                Field field = currentObject.getClass().getDeclaredField(temp[temp.length - 1]);
                Method setMethod = currentObject.getClass().getDeclaredMethod("set" + StringUtils.initcap(temp[temp.length - 1]), field.getType());
                Object convertValue = BeanUtils.convertValue(field.getType().getName(), attval[1]);
                setMethod.invoke(currentObject, convertValue);
            } catch (Exception exception) {
                // exception.printStackTrace();
            }
        }
    }
    static private Object convertValue(String type, String value) {
        // System.out.println("type = " + type + ", value = " + value);
        if("long".equals(type) || "java.lang.Long".equals(type)) {
            return Long.parseLong(value);
        } else if("int".equals(type) || "java.lang.Integer".equals(type)) {
            return Integer.parseInt(value);
        } else if("double".equals(type) || "java.lang.Double".equals(type)) {
            return Double.parseDouble(value);
        } else if("java.util.Date".equals(type)) {
            try {
                if(value.matches("[0-9]{4}-[0-9]{2}-[0-9]{2}")) {
                    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
                    return sdf.parse(value);
                } else if(value.matches("[0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}")) {
                    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                    return sdf.parse(value);
                }
            } catch (Exception exception) {
                // exception.printStackTrace();
            }
            return new Date();
        }
        return value;
    }
}

class Company {
    private String name;
    private Date createdate;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Date getCreatedate() {
        return createdate;
    }

    public void setCreateDate(Date createdate) {
        this.createdate = createdate;
    }
}

class Dept {
    private String name;
    private String location;
    private Company company;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public Company getCompany() {
        return company;
    }

    public void setCompany(Company company) {
        this.company = company;
    }
}

class Emp {
    private long empno;
    private String ename;
    private String job;
    private double salary;
    private Date hiredate;
    private Dept dept;

    public void setEname(String ename) {
        this.ename = ename;
    }

    public void setJob(String job) {
        this.job = job;
    }

    public String getEname() {
        return ename;
    }

    public String getJob() {
        return job;
    }

    public long getEmpno() {
        return empno;
    }

    public void setEmpno(long empno) {
        this.empno = empno;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public Date getHiredate() {
        return hiredate;
    }

    public void setHiredate(Date hiredate) {
        this.hiredate = hiredate;
    }

    public Dept getDept() {
        return dept;
    }

    public void setDept(Dept dept) {
        this.dept = dept;
    }
}
