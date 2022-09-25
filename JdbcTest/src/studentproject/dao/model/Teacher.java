package studentproject.dao.model;
//ii.	Teacher(tno教师编号, tname教师姓名, 密码, 职称)，实现新增和查询
public class Teacher {

    private Integer teaNo;
    private String teaName;
    private String positionalTitles;

    public Teacher() {
    }

    public Teacher(Integer teaNo, String teaName, String positionalTitles) {
        this.teaNo = teaNo;
        this.teaName = teaName;
        this.positionalTitles = positionalTitles;
    }

    public Integer getTeaNo() {
        return teaNo;
    }

    public void setTeaNo(Integer teaNo) {
        this.teaNo = teaNo;
    }

    public String getTeaName() {
        return teaName;
    }

    public void setTeaName(String teaName) {
        this.teaName = teaName;
    }

    public String getPositionalTitles() {
        return positionalTitles;
    }

    public void setPositionalTitles(String positionalTitles) {
        this.positionalTitles = positionalTitles;
    }

    @Override
    public String toString() {
        return "Teacher{" +
                "teaNo=" + teaNo +
                ", teaName='" + teaName + '\'' +
                ", positionalTitles='" + positionalTitles + '\'' +
                '}';
    }
}
