package studentproject.dao;

import studentproject.dao.model.Course;
import studentproject.dao.model.Score;
import studentproject.dao.model.Teacher;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

public class CourseDao {

    Scanner scanner = new Scanner(System.in);
    /*
    * 查询所有课程信息
    * */
    public List<Course> shouAll(){

        try(Connection connection = JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("select * from course");

            List<Course> courseList =new ArrayList<>();
            ResultSet rs = ps.executeQuery();
            while (rs.next()){

                String cno  = rs.getString("cno");
                String cname = rs.getString("cname");
                int credit = rs.getInt("credit");
                Date startTime = rs.getDate("startTime");
                Date overTime = rs.getDate("overTime");
                int teaNo = rs.getInt("teaNo");

                Course course = new Course(cno,cname,credit,startTime,overTime,teaNo);

                courseList.add(course);

            }
            return courseList;
        }catch (Exception ex){
            System.err.println(">>查询所有失败：" + ex.getMessage());
        }
        return null;
    }

    /*
    * 添加单个课程信息
    * */
    public void addOne(Course course){

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();){
            PreparedStatement ps =connection.prepareStatement("insert into course(cno,cname,credit,startTime,overTime,teaNo)" + "values (?,?,?,?,?,?)");

            int index = 1;
            ps.setString(index++,course.getCno());
            ps.setString(index++,course.getCname());
            ps.setInt(index++,course.getCredit());
            ps.setDate(index++,new java.sql.Date(course.getStartTime().getTime()));
            ps.setDate(index++,new java.sql.Date(course.getOverTime().getTime()));
            ps.setInt(index++,course.getTeaNo());

            if (ps.executeUpdate()>0){

                System.out.println("添加成功");
            }
        }catch (Exception ex){
            System.out.println("添加课程信息失败！！！" + ex.getMessage());
        }

    }

    /*
    * 删除单个课程信息
    * */
    public void deleteOne(String _cno){

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("delete from course where cno = ?");

            ps.setString(1,_cno);

            if (ps.executeUpdate()>0){
                System.out.println("删除课程信息成功");
            }

        }catch (Exception ex){
            System.out.println("->> 删除课程信息失败" + ex.getMessage());
        }
    }

    /*
    * 显示单课程信息
    * */
    public Course showOne(String _cno){

        try (Connection connection = studentproject.dao.JdbcUtils.getConnection();){
            PreparedStatement ps = connection.prepareStatement("select * from course where cno = ?");

            ps.setString(1,_cno);
            ResultSet rs = ps.executeQuery();
            rs.next();
            String cno = rs.getString("cno");
            String cname = rs.getString("cname");
            int credit = rs.getInt("credit");
            Date startTime = rs.getDate("startTime");
            Date overTime = rs.getDate("overTime");
            int teaNo = rs.getInt("teaNo");

            Course course = new Course(cno,cname,credit,startTime,overTime,teaNo);

            return course;
        }catch (Exception ex){
            System.out.println("->> 查询失败" + ex.getMessage());
        }


        return null;
    }

    /*
     * 修改课程信息
     * */

    public void alterCourse(String _cno){

        Course course = showOne(_cno);
        System.out.println(course);

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {
            boolean choose = true;
            char [] date;
            while (choose) {
                System.out.print("请输入要修改的课程信息 1.课程编号,2.课程名称,3.课程学分,4.选课开始时间,5.选课结束时间,6.任课教师编号 :");
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

                PreparedStatement ps;
                if (!choose){
                    for (int i = 0; i < date.length; i++) {

                        switch (date[i]){
                            case '1':
                                 ps = connection.prepareStatement("update course set cno = ? where cno =?");
                                System.out.print("请修改课程编号: " + course.getCno() + "-->");
                                ps.setString(1,scanner.next());
                                ps.setString(2,_cno);
                                if (ps.executeUpdate()>0){
                                    System.out.println("课程编号修改成功");
                                }
                                break;
                            case '2':
                                ps = connection.prepareStatement("update course set cname = ? where cno =?");
                                System.out.print("请修改课程名称: " + course.getCname() + "-->");
                                ps.setString(1,scanner.next());
                                ps.setString(2,_cno);
                                if (ps.executeUpdate()>0){
                                    System.out.println("课程名称修改成功");
                                }
                                break;
                            case '3':
                                ps = connection.prepareStatement("update course set credit = ? where cno =?");
                                System.out.print("请修改课程学分: " + course.getCredit() + "-->");
                                ps.setInt(1,scanner.nextInt());
                                ps.setString(2,_cno);
                                if (ps.executeUpdate()>0){
                                    System.out.println("课程学分修改成功");
                                }
                                break;
                            case '4':
                                ps = connection.prepareStatement("update course set startTime = ? where cno =?");
                                System.out.print("请修改课程开始选课时间(yyyy-mm-dd): " + course.getStartTime() + "-->");
                                //日期
                                String staTime = scanner.next();
                                SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-mm-dd");
                                try {
                                    Date dateOne = simpleDateFormat.parse(staTime);
                                    ps.setDate(1,new java.sql.Date(dateOne.getTime()));
                                } catch (ParseException e) {
                                    e.printStackTrace();
                                }
                                ps.setString(2,_cno);
                                if (ps.executeUpdate()>0){
                                    System.out.println("课程开始选课时间修改成功");
                                }
                                break;
                            case '5':
                                ps = connection.prepareStatement("update course set overTime = ? where cno =?");
                                System.out.print("请修改课程结束选课时间(yyyy-mm-dd): " + course.getOverTime() + "-->");
                                //日期
                                String ovTime = scanner.next();
                                SimpleDateFormat simpleDateFormatTwo = new SimpleDateFormat("yyyy-mm-dd");
                                try {
                                    Date dateTwo = simpleDateFormatTwo.parse(ovTime);
                                    ps.setDate(1,new java.sql.Date(dateTwo.getTime()));
                                } catch (ParseException e) {
                                    e.printStackTrace();
                                }
                                ps.setString(2,_cno);
                                if (ps.executeUpdate()>0){
                                    System.out.println("课程结束选课时间修改成功");
                                }
                                break;
                            case '6':
                                ps = connection.prepareStatement("update course set teaNo = ? where cno =?");
                                System.out.print("请修任课教师编号: " + course.getTeaNo() + "-->");
                                ps.setInt(1,scanner.nextInt());
                                ps.setString(2,_cno);
                                if (ps.executeUpdate()>0){
                                    System.out.println("任课教师编号修改成功");
                                }
                                break;

                        }
                    }

                }


            }

        }catch (Exception ex){

            System.out.println(">>> 教师信息修改失败" + ex.getMessage());
        }

    }
}
