package studentproject.dao;

import studentproject.dao.model.Score;
import studentproject.dao.model.Teacher;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ScoreDao {
    Scanner scanner = new Scanner(System.in);

    /*
    *查询所有成绩
    * */

    public List<Score> showAll(){

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("select * from score");
            List<Score> scoreList =new ArrayList<>();
            ResultSet rs = ps.executeQuery();

            while (rs.next()){
                String cno = rs.getString("cno");
                String stuNo = rs.getString("stuNo");
                int score = rs.getInt("score");

                scoreList.add(new Score(cno,stuNo,score));
            }
            return scoreList;
        }catch (Exception ex){
            System.out.println("->> 查询成绩表单失败" + ex.getMessage());
        }

        return null;
    }
    /*
    * 通过学生学号查成绩
    * */

    public List<Score> select( String _stuNo){

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("select * from score where stuNo = ?");
            ps.setString(1,_stuNo);
            ResultSet rs = ps.executeQuery();
            List<Score> scoreList = new ArrayList<>();
            while (rs.next()){
                String cno = rs.getString("cno");
                String stuNo = rs.getString("stuNo");
                int score = rs.getInt("score");
                scoreList.add(new Score(cno,stuNo,score));
            }
            return scoreList;
        }catch (Exception ex){
            System.out.println("->> 成绩查询失败" + ex.getMessage());
        }


        return  null;
    }

    /*
    * 添加成绩
    * */
    public void addScore(Score score){
        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("insert into score(cno,stuNo,score)" + "values (?,?,?)");
            ps.setString(1,score.getCno());
            ps.setString(2,score.getStuNo());
            ps.setInt(3,score.getScore());

            if (ps.executeUpdate()>0){
                System.out.println("添加成绩成功");
            }

        }catch (Exception ex){
            System.out.println("->> 添加失败" + ex.getMessage());
        }

    }

    /*
    * 通过课程编号和学号查询单条课程成绩
    * */

    public Score showOne(String _cno , String _stuNo){

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("select * from score where cno =? and stuNo =?");
            ps.setString(1,_cno);
            ps.setString(2,_stuNo);
            ResultSet rs = ps.executeQuery();
            rs.next();
            String cno = rs.getString("cno");
            String stuNo = rs.getString("stuNo");
            int score = rs.getInt("score");
            Score score1 = new Score(cno,stuNo,score);
            return score1;
        }catch (Exception ex){
            System.out.println("->>查询失败 " + ex.getMessage());
        }

        return null;
    }

    /*
    * 修改单条成绩信息
    * */

    public void updateScore(String _cno,String _stuNo){

        Score score = showOne(_cno,_stuNo);
        System.out.println(score);

        try(Connection connection = studentproject.dao.JdbcUtils.getConnection();) {
            boolean choose = true;
            char [] date;
            while (choose) {
                System.out.print("请输入要修改的成绩信息 1.课程编号,2.学生学号,3.成绩 :");
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
                                PreparedStatement ps = connection.prepareStatement("update score set cno = ? where cno =? and stuNo =?");
                                System.out.print("请修改课程编号: " + score.getCno() + "-->");
                                ps.setString(1,scanner.next());
                                ps.setString(2,_cno);
                                ps.setString(3,_stuNo);
                                if (ps.executeUpdate()>0){
                                    System.out.println("课程编号修改成功");
                                }
                                break;
                            case '2':
                                ps = connection.prepareStatement("update score set stuNo = ? where cno =? and stuNo =?");
                                System.out.print("请修改学生学号: " + score.getStuNo() + "-->");
                                ps.setString(1,scanner.next());
                                ps.setString(2,_cno);
                                ps.setString(3,_stuNo);
                                if (ps.executeUpdate()>0){
                                    System.out.println("学生学号修改成功");
                                }
                                break;
                            case '3':
                                ps = connection.prepareStatement("update score set score = ? where cno =? and stuNo =?");
                                System.out.print("请修改成绩: " + score.getScore() + "-->");
                                ps.setInt(1,scanner.nextInt());
                                ps.setString(2,_cno);
                                ps.setString(3,_stuNo);
                                if (ps.executeUpdate()>0){
                                    System.out.println("成绩修改成功");
                                }


                        }
                    }

                }


            }

        }catch (Exception ex){

            System.out.println(">>> 成绩信息修改失败" + ex.getMessage());
        }

    }

    /*
    * 删除单条成绩
    * */
    public void deleteOne(String _cno, String _stuNo){

        try (Connection connection = studentproject.dao.JdbcUtils.getConnection();){
            PreparedStatement ps = connection.prepareStatement("delete from score where cno = ? and stuNo = ?");
            ps.setString(1,_cno);
            ps.setString(2,_stuNo);

            if (ps.executeUpdate()>0){
                System.out.println("删除成功");
            }
        }catch (Exception ex){
            System.out.println("->> 删除失败 " + ex.getMessage());
        }

    }
}

