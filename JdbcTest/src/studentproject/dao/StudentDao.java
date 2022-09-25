package studentproject.dao;

import studentproject.dao.model.Student;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class StudentDao {

    Scanner scanner = new Scanner(System.in);
    /*
    * 查询所有学生信息
    * */
    public List<Student> showAll(){

        try(Connection connection = JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("select * from student");

            List<Student> studentsList =new ArrayList<>();
            ResultSet rs = ps.executeQuery();
            while (rs.next()){
//            private Integer stuNo;
//            private String stuName;
//            private String stuGender;
//            private String stuAcademy;
//            private String stuGrade;
//            private String stuPhone;
                String stuNO  = rs.getString("stuNo");
                String stuName = rs.getString("stuName");
                String stuGender = rs.getString("stuGender");
                String stuAcademy = rs.getString("stuAcademy");
                String stuGrade = rs.getString("stuGrade");
                String stuPhone = rs.getString("stuPhone");

                Student stu = new Student(stuNO,stuName,stuGender,stuAcademy,stuGrade,stuPhone);

                studentsList.add(stu);
            }

            return studentsList;

        }catch (Exception ex){
            System.err.println(">>查询所有失败：" + ex.getMessage());

        }

        return null;
    }

    /*
    * 添加学生信息
    * */
    public void addStu(Student student){

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();
        ) {
            PreparedStatement ps = connection.prepareStatement("insert into student(stuNo,stuName,stuGender,stuAcademy,stuGrade,stuPhone) " + "values (?,?,?,?,?,?)");

            int index = 1;
            ps.setString(index++,student.getStuNo());
            ps.setString(index++,student.getStuName());
            ps.setString(index++,student.getStuGender());
            ps.setString(index++,student.getStuAcademy());
            ps.setString(index++,student.getStuGrade());
            ps.setString(index++,student.getStuPhone());

            if (ps.executeUpdate()>0) {
                System.out.println("添加成功");
            }
        }catch (SQLException ex){
            System.err.println(">>2.新增员工实体失败：" + ex.getMessage());
        }


    }

    /*
    * 修改学生信息
    * */


    public void alter(String _stuNo){

        Student student = showOne(_stuNo);
        System.out.println(student);

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {
            boolean choose = true;
            char [] date;
            while (choose) {
                System.out.print("请输入要修改的学生信息 1.学号,2.姓名,3.性别,4.所在学院,5.年级,6.手机号码 :");
                String input = scanner.next();
                date = input.toCharArray();
                for (int i = 0; i < date.length; i++) {
                    if (date[i] >= 49 && date[i] <= 54) {
                        choose = false;
                    }else {
                        choose = true;
                        System.out.println("请输入符合要求的序号！！！");
                        break;
                    }
                }

                if (!choose){
                    for (int i = 0; i < date.length; i++) {

                        switch (date[i]){
                            case '1':
                                PreparedStatement ps = connection.prepareStatement("update student set stuNo = ? where stuNo =?");
                                System.out.print("请修改学号: " + student.getStuNo() + "-->");
                                ps.setString(1,scanner.next());
                                ps.setString(2,_stuNo);
                                if (ps.executeUpdate()>0){
                                    System.out.println("学号修改成功");
                                }
                                break;
                            case '2':
                                 ps = connection.prepareStatement("update student set stuName = ? where stuNo =?");
                                System.out.print("请修改姓名: " + student.getStuName() + "-->");
                                ps.setString(1,scanner.next());
                                ps.setString(2,_stuNo);
                                if (ps.executeUpdate()>0){
                                    System.out.println("姓名修改成功");
                                }
                                break;
                            case '3':
                                ps = connection.prepareStatement("update student set stuGender = ? where stuNo =?");
                                System.out.print("请修改性别: " + student.getStuGender() + "-->");
                                ps.setString(1,scanner.next());
                                ps.setString(2,_stuNo);
                                if (ps.executeUpdate()>0){
                                    System.out.println("性别修改成功");
                                }
                                break;

                            case '4':
                                ps = connection.prepareStatement("update student set stuAcademy = ? where stuNo =?");
                                System.out.print("请修改所在学院: " + student.getStuAcademy() + "-->");
                                ps.setString(1,scanner.next());
                                ps.setString(2,_stuNo);
                                if (ps.executeUpdate()>0){
                                    System.out.println("所在学院修改成功");
                                }
                                break;
                            case '5':
                                ps = connection.prepareStatement("update student set stuGrade = ? where stuNo =?");
                                System.out.print("请修改年级: " + student.getStuGrade() + "-->");
                                ps.setString(1,scanner.next());
                                ps.setString(2,_stuNo);
                                if (ps.executeUpdate()>0){
                                    System.out.println("年级修改成功");
                                }
                                break;
                            case '6':
                                ps = connection.prepareStatement("update student set stuPhone = ? where stuNo =?");
                                System.out.print("请修改学生手机号码: " + student.getStuPhone() + "-->");
                                ps.setString(1,scanner.next());
                                ps.setString(2,_stuNo);
                                if (ps.executeUpdate()>0){
                                    System.out.println("手机号码修改成功");
                                }
                                break;
                        }
                    }

                }


            }


        }catch (Exception ex){

            System.out.println(">>> 修改失败" + ex.getMessage());
        }

    }

    /*
    * 删除学生信息
    * */

    public void deleteStu(String _stuNO){

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {

            PreparedStatement ps = connection.prepareStatement("delete from student where stuNo = ?");
            ps.setString(1,_stuNO);

           if (ps.executeUpdate()>0){
               System.out.println("删除学生成功！！！");
           }

        }catch (Exception ex){

            System.out.println("删除学生信息失败->>" + ex.getMessage());
        }
    }

    /*
    * 查询单个学生信息
    * */
    public Student showOne(String _stuNo){

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();
        ) {

            PreparedStatement ps = connection.prepareStatement("select stuNo,stuName,stuGender,stuAcademy,stuGrade,stuPhone from student where stuNo = ?");
            ps.setString(1,_stuNo);
            ResultSet rs = ps.executeQuery();
            rs.next();
            String stuNo = rs.getString("stuNo");
            String stuName = rs.getString("stuName");
            String stuGender = rs.getString("stuGender");
            String stuAcademy = rs.getString("stuAcademy");
            String stuGrade = rs.getString("stuGrade");
            String stuPhone = rs.getString("stuPhone");

            Student stu = new Student(stuNo,stuName,stuGender,stuAcademy,stuGrade,stuPhone);
            return stu;
        }catch (SQLException ex){
            System.err.println(">>查询学生失败：" + ex.getMessage());
        }

        return null;
    }
}
