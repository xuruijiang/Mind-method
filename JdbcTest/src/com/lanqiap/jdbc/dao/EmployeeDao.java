package com.lanqiap.jdbc.dao;

import com.lanqiap.jdbc.model.Employee;

import java.sql.*;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.lang.String;

public class EmployeeDao {

    public List<Employee> findAll(){
        try (Connection connection = JdbcUtils.getConnection();
             Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery("select * from emp");


        ) {
            List<Employee> employeeList =new ArrayList<>();

            while (resultSet.next()){

                int empno = resultSet.getInt("empno");
                String ename = resultSet.getString("ename");
                String job = resultSet.getString("job");
                int mgr = resultSet.getInt("mgr");
                Date hiredate = resultSet.getDate("hiredate");
                double sal = resultSet.getDouble("sal");
                double comm = resultSet.getDouble("comm");
                int deptno = resultSet.getInt("deptno");

                employeeList.add(new Employee(empno,ename,job,mgr,hiredate,sal,comm,deptno));

            }
            return employeeList;
        }catch (SQLException e){
            System.err.println("查询所有员工失败" + e.getMessage());

        }
        return null;

    }

    public List<Employee> findJob(String job){
        try (Connection connection = JdbcUtils.getConnection();
             Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery("select * from emp where job = '" + job + "'");


        ) {
            List<Employee> employeeList =new ArrayList<>();

            while (resultSet.next()){

                int empno = resultSet.getInt("empno");
                String ename = resultSet.getString("ename");
                String _job = resultSet.getString("job");
                int mgr = resultSet.getInt("mgr");
                Date hiredate = resultSet.getDate("hiredate");
                double sal = resultSet.getDouble("sal");
                double comm = resultSet.getDouble("comm");
                int deptno = resultSet.getInt("deptno");

                employeeList.add(new Employee(empno,ename,_job,mgr,hiredate,sal,comm,deptno));

            }
            return employeeList;
        }catch (SQLException e){
            System.err.println("查询所有员工失败" + e.getMessage());

        }
        return null;

    }

    public List<Employee> findBydeptno(int deptno) {
        try (Connection connection = JdbcUtils.getConnection();
             Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery("select * from emp where deptno =" + deptno);


        ) {
            List<Employee> employeeList = new ArrayList<>();

            while (resultSet.next()) {

                int _empno = resultSet.getInt("empno");
                String ename = resultSet.getString("ename");
                String _job = resultSet.getString("job");
                int mgr = resultSet.getInt("mgr");
                Date hiredate = resultSet.getDate("hiredate");
                double sal = resultSet.getDouble("sal");
                double comm = resultSet.getDouble("comm");
                int _deptno = resultSet.getInt("deptno");

                employeeList.add(new Employee(_empno, ename, _job, mgr, hiredate, sal, comm, _deptno));

            }
            return employeeList;
        } catch (SQLException e) {
            System.err.println("查询所有员工失败" + e.getMessage());

        }
        return null;
    }
    //    -- 9. 列出所有办事员（CLERK）的姓名，编号和部门编号
//    SELECT ename,empno,deptno FROM emp WHERE job = 'clerk';
    public List<Employee> findByjob(String job) {
        try (Connection connection = JdbcUtils.getConnection();
             Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery("select ename,empno,deptno from emp where job ='" + job + "'");


        ) {
            List<Employee> employeeList = new ArrayList<>();

            while (resultSet.next()) {

                int _empno = resultSet.getInt("empno");
                String ename = resultSet.getString("ename");
//                String _job = resultSet.getString("job");
//                int mgr = resultSet.getInt("mgr");
//                Date hiredate = resultSet.getDate("hiredate");
//                double sal = resultSet.getDouble("sal");
//                double comm = resultSet.getDouble("comm");
                int _deptno = resultSet.getInt("deptno");

                employeeList.add(new Employee(_empno, ename, job, _deptno));

            }
            return employeeList;
        } catch (SQLException e) {
            System.err.println("查询所有员工失败" + e.getMessage());

        }
        return null;
    }

    /*
    * 新增员工实体
    * */
    public int insert(Employee employee){
        try(
                Connection connection = JdbcUtils.getConnection();
                Statement statement = connection.createStatement();

                ) {

            String sqlFormat = "insert into emp(empno,ename,job,mgr,hiredate,sal,comm,deptno) " +
                    "values(%d,'%s','%s',%d,'%s',%.1f,%.1f,%d)";

//            String sqlFormat = "delete from emp (empno,ename,job,mgr,hiredate,sal,comm,deptno) "+
//                    "values(%d,'%s','%s',%d,'%s',%.1f,%.1f,%d) ";
            String ss = sqlFormat +
            "values("+ employee.getEmpno() +
                    ", '" + employee.getEname() +
                    "', '" + employee.getJob() +
                    "'," +employee.getMgr() +
                    ",'" + DateUtils.format(employee.getHiredate(), "yyyy-MM-dd") +"'" +
                    "," + employee.getSal() +
                    ", " + employee.getComm() +
                    "," + employee.getDeptno() + ")";
            System.out.println(ss);
            String sql = String.format(sqlFormat,
                    employee.getEmpno(),
                    employee.getEname(),
                    employee.getJob(),
                    employee.getMgr(),
                    DateUtils.format(employee.getHiredate(), "yyyy-MM-dd"),
                    employee.getSal(),
                    employee.getComm(),
                    employee.getDeptno());

            System.out.println(">>> " + sql);
            //返回插入的记录数
            int row = statement.executeUpdate(sql);
            return row;
        } catch (Exception ex) {
            System.err.println("新增员工实体失败：" + ex.getMessage());
        }

        return 0;
    }

    public int save(Employee employee){

        try(Connection connection = JdbcUtils.getConnection();
        ) {
            PreparedStatement ps = connection.prepareStatement("insert into emp(empno ,ename, job, mgr, hiredate, sal, comm, deptno) " + "values (?,?,?,?,?,?,?,?)");

           // PreparedStatement ps1 = connection.prepareStatement("delete from emp where(empno)" +"values (?)");

            int index = 1;

           // ps1.setInt(index,employee.getEmpno());
            ps.setInt(index++,employee.getEmpno());
            ps.setString(index++,employee.getEname());
            ps.setString(index++,employee.getJob());
            ps.setInt(index++,employee.getMgr());
            ps.setDate(index++,new java.sql.Date(employee.getHiredate().getTime()));
            ps.setDouble(index++,employee.getSal());
            ps.setDouble(index++,employee.getComm());
            ps.setInt(index++,employee.getDeptno());
            int row = ps.executeUpdate();
            return row;
        }catch (SQLException ex){
            System.err.println(">>2.新增员工实体失败：" + ex.getMessage());
        }
        return 0;
    }
    public int delete(Employee employee){

        try(Connection connection = JdbcUtils.getConnection();
        ) {

             PreparedStatement ps = connection.prepareStatement("delete from emp where empno = ?");

            int index = 1;


            ps.setInt(index++,employee.getEmpno());
//            ps.setString(index++,employee.getEname());
//            ps.setString(index++,employee.getJob());
//            ps.setInt(index++,employee.getMgr());
//            ps.setDate(index++,new java.sql.Date(employee.getHiredate().getTime()));
//            ps.setDouble(index++,employee.getSal());
//            ps.setDouble(index++,employee.getComm());
//            ps.setInt(index++,employee.getDeptno());
            int row = ps.executeUpdate();
            return row;
        }catch (SQLException ex){
            System.err.println(">>2.新增员工实体失败：" + ex.getMessage());
        }

        return 0;
    }
    public int update(Employee employee,Double sall){

        try(Connection connection = JdbcUtils.getConnection();
        ) {

            PreparedStatement ps = connection.prepareStatement("update emp set sal=? where ename=? ");




            //ps.setInt(index++,employee.getEmpno());
            ps.setDouble(1,sall);
            ps.setString(2,employee.getEname());
//            ps.setString(index++,employee.getJob());
//            ps.setInt(index++,employee.getMgr());
//            ps.setDate(index++,new java.sql.Date(employee.getHiredate().getTime()));
//            ps.setDouble(index++,employee.getComm());
//            ps.setInt(index++,employee.getDeptno());

            int row = ps.executeUpdate();
            return row;
        }catch (SQLException ex){
            System.err.println(">>2.新增员工实体失败：" + ex.getMessage());
        }

        return 0;
    }
    public int update1(Employee employee,String ename){

        try(Connection connection = JdbcUtils.getConnection();
        ) {

            PreparedStatement ps = connection.prepareStatement("update emp set ename=? where ename=? ");




            //ps.setInt(index++,employee.getEmpno());
            ps.setString(1,ename);
            ps.setString(2,employee.getEname());
//            ps.setString(index++,employee.getJob());
//            ps.setInt(index++,employee.getMgr());
//            ps.setDate(index++,new java.sql.Date(employee.getHiredate().getTime()));
//            ps.setDouble(index++,employee.getComm());
//            ps.setInt(index++,employee.getDeptno());

            int row = ps.executeUpdate();
            return row;
        }catch (SQLException ex){
            System.err.println(">>2.新增员工实体失败：" + ex.getMessage());
        }

        return 0;
    }

    public List<Employee> inquiry(Employee employee){

        StringBuffer stringBuffer = new StringBuffer("select * from emp where 1=1 ");
        List<Object> list = new ArrayList<>();

            if (employee.getEmpno()!= null){
                stringBuffer.append(" and empno = ? ");

                list.add(employee.getEmpno());
            }if (employee.getEname()!= null && employee.getEname().trim().length() >0){
                stringBuffer.append(" and ename like ? ");
                list.add("%" +employee.getEname() + "%");
            }if (employee.getJob()!= null && employee.getJob().trim().length() > 0){
                stringBuffer.append(" and job = ? ");

                list.add(employee.getJob());
            }if (employee.getMgr()!= null){
                stringBuffer.append(" and mgr = ? ");

                list.add(employee.getMgr());
            }if (employee.getLowSal()!= null){
                stringBuffer.append(" and sal >= ? ");

                list.add(employee.getLowSal());
            }if (employee.getHigSal()!= null){
            stringBuffer.append(" and sal <= ? ");

            list.add(employee.getHigSal());
        }if (employee.getComm()!= null){
                stringBuffer.append(" and comm = ? ");

                list.add(employee.getComm());
            }if (employee.getDeptno()!= null){
                stringBuffer.append(" and deptno = ? ");

                list.add(employee.getDeptno());
            }

            System.out.println("SQL: " + stringBuffer);


        try(Connection connection = JdbcUtils.getConnection();
        ) {
            //ps.setInt(index++,employee.getEmpno());
            PreparedStatement ps = connection.prepareStatement(stringBuffer.toString());
            for (int i = 0; i < list.size(); i++) {
                ps.setObject(i+1, list.get(i));
            }
            //ps.setString(1,job);
            //ps.setString(2,employee.getEname());
//            ps.setString(index++,employee.getJob());
//            ps.setInt(index++,employee.getMgr());
//            ps.setDate(index++,new java.sql.Date(employee.getHiredate().getTime()));
//            ps.setDouble(index++,employee.getComm());
//            ps.setInt(index++,employee.getDeptno());

            //ParameterMetaData parameterMetaData = ps.getParameterMetaData();
            ResultSet rs = ps.executeQuery();

            List<Employee> employeeList = new ArrayList<Employee>();
            while(rs.next()){
                // 当前记录的每一列
                int empno = rs.getInt("empno");// rs.getInt("列标题、列名")
                String ename = rs.getString("ename");
                String job = rs.getString("job");
                int mgr = rs.getInt("mgr");
                java.sql.Date hiredate = rs.getDate("hiredate");
                double sal = rs.getDouble("sal");
                double comm = rs.getDouble("comm");
                int _deptno = rs.getInt("deptno");
                Employee e = new Employee(empno, ename, job, mgr, hiredate, sal, comm, _deptno);
                employeeList.add(e);
            }
            return employeeList;
        }catch (SQLException ex){
            System.err.println(">>2.新增员工实体失败：" + ex.getMessage());
        }
        return null;
    }
//        public static void main (String[]args){
////            new EmployeeDao().findAll().forEach(System.out::println);
////            System.out.println();
////            new EmployeeDao().findJob("SALESMAN").forEach(System.out::println);
////            System.out.println();
////            new EmployeeDao().findBydeptno(30).forEach(System.out::println);
////            System.out.println();
////            new EmployeeDao().findByjob("CLERK").forEach(System.out::println);
//
//            //System.out.println("insert " + new EmployeeDao().save(new Employee(8798,"徐瑞成","架构师",7654,new java.util.Date(),59999.00,88888.00,1)) +" rows");
//            //System.out.println("insert " + new EmployeeDao().inquiry( "架构师"+" rows"));
//            //System.out.println("insert " + new EmployeeDao().delete(new Employee(8900)) +" rows");
//            //System.out.println("insert " + new EmployeeDao().update(new Employee("徐瑞江"), 88888.0) +"rows");
//
//
//        }


//-- 10. 找出佣金高于薪金的员工。
//    SELECT ename from emp WHERE comm > sal;
//-- 11. 找出佣金高于薪金60%的员工
//    SELECT ename from emp WHERE comm >1.6* sal;
//
//-- 12. 找出部门10中所有的（MANAGER）和部门20中所有办事员（CLERK）。
//    SELECT ename FROM EMP WHERE DEPTNO = '10' AND JOB = 'MANAGER' OR DEPTNO = '20' AND JOB = 'CLERK';
//-- SELECT ENAME FROM EMP WHERE DEPTNO = '20' AND JOB = 'CLERK';
//
//-- 13. 找出收取佣金的员工的不同工作
//-- SELECT JOB FROM EMP WHERE comm is NOT NULL;
//
//    select job,count(job)
//    from emp WHERE comm	 >0
//    group by job
//    order by job;
//
//-- 14. 找出不收取佣金或收取的佣金不低于100的员工
//    SELECT ename,comm FROM emp WHERE comm IS NULL OR comm >= 100;
//-- 15. 找出部门10中所有的（MANAGER）和部门20中所有办事员（CLERK）,
//            -- 和既不是经理又不是办事员但其薪金大于或等于2000的所有员工的详细资料
//    SELECT * FROM emp WHERE (deptno = '10' AND job = 'manager') OR (deptno = '20' AND job = 'clerk') OR (job != 'manager'AND job != 'clerk') AND sal >= '2000';


}
