package studentproject.dao.model;

//v.	Manager管理员表（mno账号、mname用户名、密码）
public class Manager {

    private String mno;
    private String mname;
    private String password;

    public Manager() {
    }

    public Manager(String mno, String mname, String password) {
        this.mno = mno;
        this.mname = mname;
        this.password = password;
    }

    public String getMno() {
        return mno;
    }

    public void setMno(String mno) {
        this.mno = mno;
    }

    public String getMname() {
        return mname;
    }

    public void setMname(String mname) {
        this.mname = mname;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    @Override
    public String toString() {
        return "Manager{" +
                "mno='" + mno + '\'' +
                ", mname='" + mname + '\'' +
                ", password='" + password + '\'' +
                '}';
    }
}
