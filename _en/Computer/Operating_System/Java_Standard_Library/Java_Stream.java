/* Java_Stream.java
Author: bss9395
Update: 2020/09/28T15:35:00+08@China-GuangDong-ZhanJiang+08
*/

import java.util.ArrayList;
import java.util.Collections;
import java.util.DoubleSummaryStatistics;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Java_Stream {
    static public void main(String[] args) {
        // _Test_count();
        // _Test_filter();
        // _Test_collect();
        // _Test_limit();
        _Test_summaryStatistics();
    }
    static public void _Test_count() {
        List<String> list = new ArrayList<String>();
        Collections.addAll(list, "Java", "JavaScript", "Python", "Ruby", "Go");
        Stream<String> stream = list.stream();
        System.out.println(stream.count());
    }
    static public void _Test_filter() {
        List<String> list = new ArrayList<String>();
        Collections.addAll(list, "Java", "JavaScript", "Python", "Ruby", "Go");
        Stream<String> stream = list.stream();
        long count = stream.filter((element) -> {
            return element.toUpperCase().contains("J");
        }).count();
        System.out.println(count);
    }
    static public void _Test_collect() {
        List<String> list = new ArrayList<String>();
        Collections.addAll(list, "Java", "JavaScript", "Python", "Ruby", "Go");
        Stream<String> stream = list.stream();
        List<String> result = stream.filter((element) -> {
            return element.toUpperCase().contains("J");
        }).collect(Collectors.toList());
        System.out.println(result);
    }
    static public void _Test_limit() {
        List<String> list = new ArrayList<String>();
        Collections.addAll(list, "Java", "JavaScript", "Python", "Json", "Ruby", "JSP", "Go");
        Stream<String> stream = list.stream();
        List<String> result = stream.filter((element) -> {
            return element.toUpperCase().contains("J");
        }).skip(2).limit(1).collect(Collectors.toList());
        System.out.println(result);
    }
    static public void _Test_summaryStatistics() {
        List<Order> list = new ArrayList<Order>();
        list.add(new Order("小强娃娃", 9.9, 10));
        list.add(new Order("林弱充气娃娃", 2987.9, 3));
        list.add(new Order("不强牌笔记本电脑", 8987.9, 8));
        list.add(new Order("强强茶杯", 2.9, 800));
        list.add(new Order("阿强牌煎饼", 0.9, 138));
        DoubleSummaryStatistics stat = list.stream().filter((element) -> {
            return element.getName().contains("强");
        }).mapToDouble((element) -> {
            return element.getPrice() * element.getAmount();
        }).summaryStatistics();

        System.out.println("购买数量：" + stat.getCount());
        System.out.println("购买总价：" + stat.getSum());
        System.out.println("平均花费：" + stat.getAverage());
        System.out.println("最高花费：" + stat.getMax());
        System.out.println("最低花费：" + stat.getMin());
    }
}

class Order {
    private String _name = "";
    private double _price = 0.0;
    private int _amount = 0;

    public Order(String name, double price, int amount) {
        _name = name;
        _price = price;
        _amount = amount;
    }
    public String getName() {
        return _name;
    }
    public double getPrice() {
        return _price;
    }
    public int getAmount() {
        return _amount;
    }
}