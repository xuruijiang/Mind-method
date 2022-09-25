package com.lanqiap.jdbc.dao;

import com.lanqiap.jdbc.model.Employee;

import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

public class JdbcTest {
    Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {

        JdbcTest jdbcTest = new JdbcTest();
        jdbcTest.show();

    }

    public void showTime(){
        System.out.println("数据库操作");
        System.out.println("1.显示表所有信息");
        System.out.println("2.插入信息");
        System.out.println("3.根据已有信息查询表");
        System.out.println("4.退出");

        System.out.print("请输入相应数字来操作数据库：");
    }

    public void show(){

        EmployeeDao employeeDao = new EmployeeDao();

        while (true){
            showTime();
            int date = scanner.nextInt();
            switch (date){
                case 1:
                    employeeDao.findAll().forEach(System.out::println);;
                    break;
                case 2:
                    Employee employee = new Employee();
                    System.out.print("请输入编号：");
                    employee.setEmpno(scanner.nextInt());
                    System.out.print("请输入姓名：");
                    employee.setEname(scanner.next());
                    System.out.print("请输入工作岗位：");
                    employee.setJob(scanner.next());
                    System.out.print("请输入代号：");
                    employee.setMgr(scanner.nextInt());
                    employee.setHiredate(new Date());
                    System.out.print("请输入薪资待遇：");
                    employee.setSal(scanner.nextDouble());
                    System.out.print("请输入奖金金额：");
                    employee.setComm(scanner.nextDouble());
                    System.out.print("请输入编组号：");
                    employee.setDeptno(scanner.nextInt());
                    int save = employeeDao.save(employee);
                    if (save != 0){
                        System.out.println("插入信息成功");
                        System.out.println();
                    }
                    break;
                case 3:
                    employeeDao.inquiry(newEmployee()).forEach(System.out::println);
                    break;
                case 4:
                    exit();

            }

        }

    }
    public Employee newEmployee(){
        Employee employee = new Employee();
        System.out.println("请输入你想查询的条件");
        System.out.println("1.empno");
        System.out.println("2.ename");
        System.out.println("3.job");
        System.out.println("4.mgr");
        System.out.println("5.lowsal");
        System.out.println("6.hirsal");
        System.out.println("7.comm");
        System.out.println("8.deptno");

        String next = scanner.next();

        char[] chars = next.toCharArray();

        for (int i = 0; i < chars.length ; i++) {

            switch (chars[i]){

                case '1' : setEmpno(employee);
                break;
                case '2' : setEname(employee);
                break;
                case '3' : setJob(employee);
                break;
                case '4' : setMgr(employee);
                break;
                case '5' : setlowSal(employee);
                break;
                case '6' : sethirSal(employee);
                break;
                case '7' : setComm(employee);
                break;
                case '8' : setDeptno(employee);

            }
        }
        return employee;
    }

    public void exit(){

        System.out.println("确认退出？？ y/n");
        char i = scanner.next().charAt(0);

        if (i =='n'){

        }else {
            System.exit(0);
        }


    }

    public void setEmpno(Employee employee){
        System.out.print("请输入编号：");
        employee.setEmpno(scanner.nextInt());
    }public void setEname(Employee employee){
        System.out.print("请输入姓名：");
        employee.setEname(scanner.next());
    }public void setJob(Employee employee){
        System.out.print("请输入工作：");
        employee.setJob(scanner.next());
    }public void setMgr(Employee employee){
        System.out.print("请输入代号：");
        employee.setMgr(scanner.nextInt());
    }public void setlowSal(Employee employee){
        System.out.print("请输入最低工资：");
        employee.setLowSal(scanner.nextInt());
    }public void sethirSal(Employee employee){
        System.out.print("请输入最高工资：");
        employee.setHigSal(scanner.nextInt());
    }public void setComm(Employee employee){
        System.out.print("请输入奖金金额：");
        employee.setComm(scanner.nextDouble());
    }public void setDeptno(Employee employee){
        System.out.print("请输入部门组号：");
        employee.setDeptno(scanner.nextInt());
    }
}
