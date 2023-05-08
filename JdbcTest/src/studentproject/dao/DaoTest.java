package studentproject.dao;

import studentproject.dao.model.Course;
import studentproject.dao.model.Score;
import studentproject.dao.model.Student;
import studentproject.dao.model.Teacher;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;


/*
 * 目前各个表之间没有联系
 * 应当建立联系
 * 还有要利用输入类
 * */


public class DaoTest {
    CourseDao courseDao = new CourseDao();
    ScoreDao scoreDao = new ScoreDao();
    StudentDao studentDao = new StudentDao();
    TeacherDao teacherDao = new TeacherDao();
    Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        DaoTest daoTest = new DaoTest();
        daoTest.start();
    }

    public void show() {
        System.out.println("-----------------桂林理工大学教务处----------------");
        System.out.println("                  1.学生管理系统");
        System.out.println("                  2.教师管理系统");
        System.out.println("                  3.课程管理系统");
        System.out.println("                  4.成绩管理系统");
        System.out.println("                  5.退出管理系统");
        System.out.println("------------------------------------------------");
        System.out.print("请输入要进行的操作序号：");
    }

    public void start() {

        while (true) {
            show();
            char charOne = InputUtils.readMenuSelection();
            switch (charOne) {
                case '1':
                    // StudentDAO studentDAO = new StudentDAO();
                    while (true) {
                        System.out.println("---------------------学 生 系 统-------------------");
                        System.out.println("                  1. 查询所有学生");
                        System.out.println("                  2. 单个添加学生信息");
                        System.out.println("                  3. 修改学生信息");
                        System.out.println("                  4. 删除学生信息");
                        System.out.println("                  5. 查询单个学生信息包括各科成绩");
                        System.out.println("                  6. 返回上一界面");
                        System.out.println("--------------------------------------------------");
                        System.out.println();
                        System.out.print("请输入操作序号：");
                        int chooseOne = scanner.nextInt();
                        if (chooseOne == 6) {
                            break;
                        }
                        switch (chooseOne) {
                            case 1:
                                studentDao.showAll().forEach(System.out::println);
                                InputUtils.readReturn();
                                break;
                            case 2:
                                studentDao.addStu(newStudent());
                                InputUtils.readReturn();
                                break;
                            case 3:
                                System.out.print("请输入学生学号:");
                                studentDao.alter(scanner.next());
                                InputUtils.readReturn();
                                break;
                            case 4:
                                System.out.print("请输入学生学号:");
                                String stuno = scanner.next();
                                System.out.println(studentDao.showOne(stuno));
                                System.out.print("是否删除该学生信息(y/n) :");
                                char ch = InputUtils.readConfirmSelection();
                                if (ch == 'y' || ch == 'Y') {
                                    studentDao.deleteStu(stuno);
                                }
                                InputUtils.readReturn();
                                break;
                            case 5:

                                //ScoreDAO scoreDAO = new ScoreDAO();
                                System.out.print("请输入学号来查询学生信息:");
                                String stuNo = scanner.next();
                                Student student = studentDao.showOne(stuNo);
                                List<Score> select = scoreDao.select(stuNo);
                                System.out.println("学生姓名:" + student.getStuName());
                                System.out.println();
                                for (Iterator<Score> it = select.iterator(); it.hasNext(); ) {
                                    //System.out.println(courseDao.showOne(it.next().getCno()));
                                    Score sc = it.next();

                                    System.out.print("科目: " + courseDao.showOne(sc.getCno()).getCname() + "  ");
                                    System.out.print("成绩: " + sc.getScore() + "  ");
                                    System.out.print("学分: " + courseDao.showOne(sc.getCno()).getCredit() + "  ");
                                    System.out.println("教师: " + teacherDao.showOne(courseDao.showOne(sc.getCno()).getTeaNo()).getTeaName() + "  ");
                                }
                                //select.forEach(System.out::println);
                                InputUtils.readReturn();
                                System.out.println();
                                break;
                        }

                    }
                    break;
                case '2':

                    //TeacherDao teacherDao = new TeacherDao();
                    while (true) {
                        System.out.println("---------------------教 师 系 统-------------------");
                        System.out.println("                  1. 查询所有教师");
                        System.out.println("                  2. 单个添加教师信息");
                        System.out.println("                  3. 修改教师信息");
                        System.out.println("                  4. 删除教师信息");
                        System.out.println("                  5. 返回上一界面");
                        System.out.println("--------------------------------------------------");

                        System.out.print("请输入操作序号：");
                        int chooseThree = scanner.nextInt();
                        if (chooseThree == 5) {
                            break;
                        }

                        switch (chooseThree) {
                            case 1:
                                teacherDao.showAll().forEach(System.out::println);
                                InputUtils.readReturn();
                                break;
                            case 2:
                                Teacher teacher = newTeacher();
                                teacherDao.addTeacher(teacher);
                                InputUtils.readReturn();
                                break;
                            case 3:
                                System.out.print("请输入要修改信息的教师编号:");
                                teacherDao.alterTeacher(scanner.nextInt());
                                InputUtils.readReturn();
                                break;
                            case 4:

                        }
                    }

                    break;

                case '3':
                    //CourseDao courseDao = new CourseDao();
                    while (true) {
                        System.out.println("------------------课程管理系统------------------");
                        System.out.println("               1.查看所有课程信息");
                        System.out.println("               2.添加单条课程信息");
                        System.out.println("               3.删除单条课程信息");
                        System.out.println("               4.修改单条课程信息");
                        System.out.println("               5. 返回上一界面");
                        System.out.println("----------------------------------------------");
                        System.out.print("请输入操作序号：");
                        int chooseTwo = scanner.nextInt();
                        if (chooseTwo == 5) {
                            break;
                        }
                        switch (chooseTwo) {
                            case 1:
                                courseDao.shouAll().forEach(System.out::println);
                                InputUtils.readReturn();
                                break;
                            case 2:
                                courseDao.addOne(newCourse());
                                InputUtils.readReturn();
                                break;
                            case 3:
                                System.out.println("请输入要删除的课程编号");
                                String inp = scanner.next();
                                System.out.println(courseDao.showOne(inp));
                                System.out.print("确认删除(y/n): ");
                                char c = InputUtils.readConfirmSelection();

                                if (c == 'y' || c == 'Y') {
                                    courseDao.deleteOne(inp);
                                    InputUtils.readReturn();
                                }
                                break;
                            case 4:
                                System.out.print("请输入要修改信息的课程编号:");
                                courseDao.alterCourse(scanner.next());
                                InputUtils.readReturn();
                                break;
                            case 5:

                        }
                    }
                    break;
                case '4':
                    //ScoreDAO scoreDAO = new ScoreDAO();
                    while (true) {
                        System.out.println("------------------成绩管理系统------------------");
                        System.out.println("               1.查看所有成绩信息");
                        System.out.println("               2.添加单条成绩信息");
                        System.out.println("               3.删除单条成绩信息");
                        System.out.println("               4.修改单条成绩信息");
                        System.out.println("               5.查看单条成绩信息");
                        System.out.println("               6. 返回上一界面");
                        System.out.println("----------------------------------------------");
                        System.out.print("请输入操作序号：");
                        int chooseFour = scanner.nextInt();
                        if (chooseFour == 6) {
                            break;
                        }
                        switch (chooseFour) {
                            case 1:
                                scoreDao.showAll().forEach(System.out::println);
                                InputUtils.readReturn();
                                break;
                            case 2:
                                scoreDao.addScore(newScore());
                                InputUtils.readReturn();
                                break;
                            case 3:
                                System.out.print("请输入要删除成绩的课程编号:");
                                String inpcno = scanner.next();
                                System.out.print("请输入要删除成绩的学生学号:");
                                String inpstuNo = scanner.next();
                                System.out.println(scoreDao.showOne(inpcno, inpstuNo));
                                System.out.print("确认删除(y/n): ");
                                char c = InputUtils.readConfirmSelection();

                                if (c == 'y' || c == 'Y') {
                                    scoreDao.deleteOne(inpcno, inpstuNo);
                                    InputUtils.readReturn();
                                }
                                break;
                            case 4:
                                System.out.print("请输入要修改的成绩的课程编号:");
                                String _cno = scanner.next();
                                System.out.print("请输入要修改的成绩的学生学号:");
                                String _stuNo = scanner.next();
                                scoreDao.updateScore(_cno, _stuNo);
                                InputUtils.readReturn();
                                break;
                            case 5:
                                System.out.print("请输入课程编号:");
                                String cno = scanner.next();

                                System.out.print("请输入学生学号:");
                                String stuNo = scanner.next();


                                System.out.println(scoreDao.showOne(cno, stuNo));
                                InputUtils.readReturn();
                                break;
                            case 6:


                        }
                    }
                    break;
                case '5':
                    System.exit(0);

            }


        }

    }

    /*
     * 创建学生实体
     * 并给各项属性赋值
     * */
    public Student newStudent() {
        Student student = new Student();

        System.out.print("请输入学生学号:");
        student.setStuNo(scanner.next());
        System.out.print("请输入学生姓名:");
        student.setStuName(scanner.next());
        System.out.print("请输入学生性别(男/女):");
        student.setStuGender(scanner.next());
        System.out.print("请输入学生所在学院:");
        student.setStuAcademy(scanner.next());
        System.out.print("请输入学生年级:");
        student.setStuGrade(scanner.next());
        System.out.print("请输入学生电话号码:");
        student.setStuPhone(scanner.next());

        return student;
    }

    /*
     * 创建教师实体
     * */
    public Teacher newTeacher() {
        Teacher teacher = new Teacher();
        System.out.print("请输入教师编号: ");
        teacher.setTeaNo(scanner.nextInt());
        System.out.print("请输入教师姓名: ");
        teacher.setTeaName(scanner.next());
        System.out.print("请输入教师职称: ");
        teacher.setPositionalTitles(scanner.next());

        return teacher;
    }

    /*
     * 创建课程实体
     * */

    public Course newCourse() {
        Course course = new Course();
        System.out.print("请输入课程编号: ");
        course.setCno(scanner.next());
        System.out.print("请输入课程名称: ");
        course.setCname(scanner.next());
        System.out.print("请输入课程学分: ");
        course.setCredit(scanner.nextInt());
        System.out.print("请输入课程开始选课时间(yyyy-mm-dd): ");
        String staTime = scanner.next();
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-mm-dd");
        try {
            Date dateOne = simpleDateFormat.parse(staTime);
            course.setStartTime(dateOne);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        System.out.print("请输入课程结束选课时间(yyyy-mm-dd): ");
        String ovTime = scanner.next();
        //Date dateTwo = null;
        try {
            Date dateTwo = simpleDateFormat.parse(ovTime);
            course.setOverTime(dateTwo);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        System.out.print("请输入课程代课老师编号: ");
        course.setTeaNo(scanner.nextInt());

        return course;
    }

    /*
     * 创建成绩表单实体
     * */
    public Score newScore() {
        Score score = new Score();
        System.out.print("请输入课程编号:");
        score.setCno(scanner.next());
        System.out.print("请输入学生编号:");
        score.setStuNo(scanner.next());
        System.out.print("请输入课程成绩:");
        score.setScore(scanner.nextInt());

        return score;
    }
}
