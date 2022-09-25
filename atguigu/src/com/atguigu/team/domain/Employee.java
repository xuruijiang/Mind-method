package com.atguigu.team.domain;
/*
* 普通员工
* */
public class Employee {
    //Employee  :  10, id, name, age, salary
    private int id;
    private String name;
    private int age;
    private  int salary;

    public Employee(int id, String name, int age, int salary) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.salary = salary;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    public String toStringBase(){
        return this.id + "\t" + this.name
                + "\t" + this.age + "\t\t" + this.salary;
    }

    public String toString(){
//        1      马 云      22      3000.0

        return this.toStringBase();
    }
}
