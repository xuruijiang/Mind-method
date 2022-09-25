package studentproject.dao.model;

//i.	Student学生表（sno学号PK，sname姓名，
//        性别，academy学院，grade年级, phone电话）。实现新增和查询，更新，删除
public class Student {
    private String stuNo;
    private String stuName;
    private String stuGender;
    private String stuAcademy;
    private String stuGrade;
    private String stuPhone;


    public Student() {
    }

    public Student(String stuNo, String stuName, String stuGender, String stuAcademy, String stuGrade, String stuPhone) {
        this.stuNo = stuNo;
        this.stuName = stuName;
        this.stuGender = stuGender;
        this.stuAcademy = stuAcademy;
        this.stuGrade = stuGrade;
        this.stuPhone = stuPhone;
    }

    public String getStuNo() {
        return stuNo;
    }

    public void setStuNo(String stuNo) {
        this.stuNo = stuNo;
    }

    public String getStuName() {
        return stuName;
    }

    public void setStuName(String stuName) {
        this.stuName = stuName;
    }

    public String getStuGender() {
        return stuGender;
    }

    public void setStuGender(String stuGender) {
        this.stuGender = stuGender;
    }

    public String getStuAcademy() {
        return stuAcademy;
    }

    public void setStuAcademy(String stuAcademy) {
        this.stuAcademy = stuAcademy;
    }

    public String getStuGrade() {
        return stuGrade;
    }

    public void setStuGrade(String stuGrade) {
        this.stuGrade = stuGrade;
    }

    public String getStuPhone() {
        return stuPhone;
    }

    public void setStuPhone(String stuPhone) {
        this.stuPhone = stuPhone;
    }

    @Override
    public String toString() {
        return "Student{" +
                "stuNo=" + stuNo +
                ", stuName='" + stuName + '\'' +
                ", stuGender='" + stuGender + '\'' +
                ", stuAcademy='" + stuAcademy + '\'' +
                ", stuGrade='" + stuGrade + '\'' +
                ", stuPhone='" + stuPhone + '\'' +
                '}';
    }
}
