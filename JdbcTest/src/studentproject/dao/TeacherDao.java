package studentproject.dao;

import studentproject.dao.model.Student;
import studentproject.dao.model.Teacher;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TeacherDao {
    Scanner scanner = new Scanner(System.in);
    /*
    * 查询所有教师信息
    * */
    public List<Teacher> showAll(){
        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("select * from teacher");

            ResultSet rs = ps.executeQuery();

            List<Teacher> teacherList = new ArrayList<>();
            while (rs.next()) {
                int teaNo = rs.getInt("teaNo");
                String teaName = rs.getString("teaName");
                String positionalTitles = rs.getString("positionalTitles");
                Teacher teacher = new Teacher(teaNo, teaName, positionalTitles);
                teacherList.add(teacher);
            }

            return teacherList;
        }catch (Exception ex){
            System.out.println("->> 查询所有教师信息失败" + ex.getMessage());
        }

        return  null;
    }

    /*
    * 添加单条教师信息
    * */
    public void addTeacher(Teacher teacher){

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("insert into  teacher(teaNo,teaName,positionalTitles)"+"values (?,?,?)");

            int next = 1;
            ps.setInt(next++,teacher.getTeaNo());
            ps.setString(next++,teacher.getTeaName());
            ps.setString(next++,teacher.getPositionalTitles());


            if (ps.executeUpdate()>0){
                System.out.println("添加成功!!!");
            }
        }catch (Exception ex){
            System.out.println("->> 添加教师信息失败" + ex.getMessage());
        }


    }

    /*
    * 修改教师信息
    * */
    public void alterTeacher(int _teaNo){

        Teacher teacher = showOne(_teaNo);
        System.out.println(teacher);

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {
            boolean choose = true;
            char [] date;
            while (choose) {
                System.out.print("请输入要修改的教师信息 1.教师编号,2.教师姓名,3.教师职称 :");
                String input = scanner.next();
                date = input.toCharArray();
                for (int i = 0; i < date.length; i++) {
                    if (date[i] >= 49 && date[i] <= 51) {
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
                                PreparedStatement ps = connection.prepareStatement("update teacher set teaNo = ? where teaNo =?");
                                System.out.print("请修改教师编号: " + teacher.getTeaNo() + "-->");
                                ps.setInt(1,scanner.nextInt());
                                ps.setInt(2,_teaNo);
                                if (ps.executeUpdate()>0){
                                    System.out.println("教师编号修改成功");
                                }
                                break;
                            case '2':
                                ps = connection.prepareStatement("update teacher set teaName = ? where teaNo =?");
                                System.out.print("请修改姓名: " + teacher.getTeaName() + "-->");
                                ps.setString(1,scanner.next());
                                ps.setInt(2,_teaNo);
                                if (ps.executeUpdate()>0){
                                    System.out.println("教师姓名修改成功");
                                }
                                break;
                            case '3':
                                ps = connection.prepareStatement("update teacher set positionalTitles = ? where teaNo =?");
                                System.out.print("请修改性别: " + teacher.getPositionalTitles() + "-->");
                                ps.setString(1,scanner.next());
                                ps.setInt(2,_teaNo);
                                if (ps.executeUpdate()>0){
                                    System.out.println("教师职称修改成功");
                                }


                        }
                    }

                }


            }

        }catch (Exception ex){

            System.out.println(">>> 教师信息修改失败" + ex.getMessage());
        }

    }

    /*
    * 查询单条教师信息
    * */

    public Teacher showOne(int _teaNo){

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("select * from teacher where teaNO = ?");
            ps.setInt(1,_teaNo);
            ResultSet rs = ps.executeQuery();
            rs.next();
            int teaNo = rs.getInt("teaNo");
            String teaName = rs.getString("teaName");
            String positionalTitles = rs.getString("positionalTitles");
            Teacher teacher = new Teacher(teaNo,teaName,positionalTitles);
            return teacher;
        }catch (Exception ex){
            System.out.println("->> 查询教师信息失败" + ex.getMessage());
        }
        return  null;
    }
}
