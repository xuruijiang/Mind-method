package studentproject.dao.model;
//iii.	Score成绩表（cno课程编号FK，sno学号FK， 成绩），PK(课程编号，学号)复合主键。实现新增和查询
//        create table score(
//        ……
//        cno integer not null reference COURSE(CNO),  	--外键
//        sno integer not null reference SCORE(SNO),	   	--外键
//        constraint pk_cno_sno primary key(cno,sno);	--复合主键
//        )
//
//        Alter table score
//        Add constrain pk_xx_yy primary key(cno,sno);

public class Score {

    private String cno;
    private String stuNo;
    private Integer score;

    public Score() {
    }

    public Score(String cno, String stuNo, Integer score) {
        this.cno = cno;
        this.stuNo = stuNo;
        this.score = score;
    }

    public String getCno() {
        return cno;
    }

    public void setCno(String cno) {
        this.cno = cno;
    }

    public String getStuNo() {
        return stuNo;
    }

    public void setStuNo(String stuNo) {
        this.stuNo = stuNo;
    }

    public Integer getScore() {
        return score;
    }

    public void setScore(Integer score) {
        this.score = score;
    }

    @Override
    public String toString() {
        return "Score{" +
                "cno=" + cno +
                ", stuNo=" + stuNo +
                ", score=" + score +
                '}';
    }
}
