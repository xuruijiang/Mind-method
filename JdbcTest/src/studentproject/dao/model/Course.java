package studentproject.dao.model;

import java.util.Date;

//iv.	Course课程表(cno课程号PK，cname课程名，学分, 选课起始时间,
//        选课结束时间，tno教师号FK)。课程编号：”C”+3位数字。实现查询。
public class Course {
    private  String cno; //  C + 三位数字
    private  String cname;
    private  Integer credit;
    private Date  startTime;
    private Date overTime;
    private Integer teaNo;

    public Course() {
    }

    public Course(String cno, String cname, Integer credit, Date startTime, Date overTime, Integer teaNo) {
        this.cno = cno;
        this.cname = cname;
        this.credit = credit;
        this.startTime = startTime;
        this.overTime = overTime;
        this.teaNo = teaNo;
    }

    public String getCno() {
        return cno;
    }

    public void setCno(String cno) {
        this.cno = cno;
    }

    public String getCname() {
        return cname;
    }

    public void setCname(String cname) {
        this.cname = cname;
    }

    public Integer getCredit() {
        return credit;
    }

    public void setCredit(Integer credit) {
        this.credit = credit;
    }

    public Date getStartTime() {
        return startTime;
    }

    public void setStartTime(Date startTime) {
        this.startTime = startTime;
    }

    public Date getOverTime() {
        return overTime;
    }

    public void setOverTime(Date overTime) {
        this.overTime = overTime;
    }

    public Integer getTeaNo() {
        return teaNo;
    }

    public void setTeaNo(Integer teaNo) {
        this.teaNo = teaNo;
    }

    @Override
    public String toString() {
        return "Course{" +
                "cno=" + cno +
                ", cname='" + cname + '\'' +
                ", credit=" + credit +
                ", startTime=" + startTime +
                ", overTime=" + overTime +
                ", teaNo=" + teaNo +
                '}';
    }
}
