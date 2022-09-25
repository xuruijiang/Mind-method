package mysqltest;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class EmployeeDao {

    public List<Employee> findAll(){

        try {
            Connection conn = JdbcUtils.getConnection();
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("select * from emp");
            List<Employee> employeeList = new ArrayList<>();

            while (rs.next()){

                int empno = rs.getInt("empno");// rs.getInt("列标题、列名")
                String ename = rs.getString("ename");
                String job = rs.getString("job");
                int mgr = rs.getInt("mgr");
                Date hiredate = rs.getDate("hiredate");
                double sal = rs.getDouble("sal");
                double comm = rs.getDouble("comm");
                int deptno = rs.getInt("deptno");
                Employee e = new Employee(empno, ename, job, mgr, hiredate, sal, comm, deptno);
                employeeList.add(e);
            }
            return employeeList;
        } catch (SQLException e) {
            System.err.println("查询所有员工失败：" + e.getMessage());
        }

        return null;
    }
    public List<Employee> findByDepartment(Integer deptno) { //job
        // 2. 获得数据库连接
        try (Connection conn = JdbcUtils.getConnection(); // 连接用完会自动关闭
             //3.通过Connection对象创建 Statement 对象
             Statement stmt = conn.createStatement();
             // 4.执行语句，获得查询结果集
             ResultSet rs = stmt.executeQuery("select * from emp where deptno=" + deptno);
        ) {
            List<Employee> employeeList = new ArrayList<>();
            //5.遍历结果集
            while(rs.next()){
                // 当前记录的每一列
                int empno = rs.getInt("empno");// rs.getInt("列标题、列名")
                String ename = rs.getString("ename");
                String job = rs.getString("job");
                int mgr = rs.getInt("mgr");
                Date hiredate = rs.getDate("hiredate");
                double sal = rs.getDouble("sal");
                double comm = rs.getDouble("comm");
                int _deptno = rs.getInt("deptno");
                Employee e = new Employee(empno, ename, job, mgr, hiredate, sal, comm, _deptno);
                employeeList.add(e);
            }

            return employeeList;

        } catch (SQLException e) {
            System.err.println("查询所有员工失败：" + e.getMessage());
        }
        return null;
    }

    public static void main(String[] args) {
        // new EmployeeDao().findAll().forEach(System.out::println);

        new EmployeeDao().findAll().forEach(e -> System.out.println(e));

        System.out.println("--------------------");

        new EmployeeDao().findByDepartment(10).forEach(System.out::println);;
    }
}
