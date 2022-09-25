package arraylisttest;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class ArrayListTest  {
    Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        ArrayListTest arrayListTest = new ArrayListTest();
        ArrayList arrayList = new ArrayList();
        arrayListTest.intFace(arrayList);





    }

    public void list(ArrayList arrayList){
        Iterator iterator = arrayList.iterator();

        while (iterator.hasNext()){
            System.out.println(iterator.next());
        }



    }

    public void intFace(ArrayList arrayList){
        boolean choose = true;
        while (choose){

        System.out.println(" 操  作  面  板");
        System.out.println("  1.学生列表");
        System.out.println("  2.添加学生");
        System.out.println("  3.删除学生");
        System.out.println("  4. 退出");
        System.out.print("请输入操作1～4：");

             switch (scanner.nextInt()){

                 case 1:
                     list(arrayList);
                     break;
                 case 2:
                     try {
                         addStudent(readStudent(),arrayList);
                     } catch (StudentExistException e) {
                         System.out.println("" + e.getMessage());
                     }
                     break;
                 case 3:
                     System.out.print("请输入想要移除的学生的学号：");
                     remove(remove(scanner.next(),arrayList),arrayList);
                     break;
                 case 4:
                     System.exit(0);

        }

        }

    }

    public void addStudent(Student student,ArrayList arrayList) throws StudentExistException{

        if(arrayList.contains(student)){
            throw new StudentExistException("已经存在有相同姓名,年龄,学号的学生");
        }else{

            arrayList.add(student);
        }

    }

    public Student readStudent(){

        Student student = new Student();

        System.out.print("请输入学生姓名");
        student.setName(scanner.next());

        System.out.print("请输入学生年龄");
        student.setAge(scanner.nextInt());

        System.out.print("请输入学生学号");
        student.setStudentNo(scanner.next());

        return student;

    }

    public boolean remove (Student student,ArrayList arrayList){

        if (student ==null){

            System.out.println("移除失败，没有找到该学号学生");
        }else{
            arrayList.remove(student);
            System.out.println("移除成功");
            return true;
        }

        return  false;

    }
    public Student remove (String  studentNo,ArrayList arrayList){

        Object[] obj = arrayList.toArray();
        for (int i = 0; i < obj.length ; i++) {
            if (obj[i] instanceof Student){
                Student student = (Student) obj[i];

                if (student.getStudentNo().equals(studentNo)){

                    return student;
                }
            }
        }
        return null;
    }
}
