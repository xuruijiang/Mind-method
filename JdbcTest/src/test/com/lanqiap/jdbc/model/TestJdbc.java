package test.com.lanqiap.jdbc.model;

import org.junit.Test;

import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.util.Properties;

public class TestJdbc {

    // 获取数据库连接方式一
    @Test
    public void testJdbcOne() throws Exception{

        Driver driver = new com.mysql.cj.jdbc.Driver();
        String url = "jdbc:mysql://localhost:3306/out";
        Properties info = new Properties();
        info.setProperty("user","root");
        info.setProperty("password","12345678");
        Connection connection = driver.connect(url,info);

        System.out.println(connection);


    }

    //方式二 对方式一的迭代  反射
    @Test
    public void testJdbcTwo() throws Exception{
        Class clazz = Class.forName("com.mysql.cj.jdbc.Driver");

        Driver driver = (Driver) clazz.newInstance();

        String url = "jdbc:mysql://localhost:3306/out";
        Properties info = new Properties();
        info.setProperty("user","root");
        info.setProperty("password","12345678");
        Connection connection = driver.connect(url,info);

        System.out.println(connection);
    }

    //方式三 使用DriverManager替换Driver
    @Test
    public void testJdbcThree() throws Exception{

        Class clazz = Class.forName("com.mysql.cj.jdbc.Driver");

        Driver driver = (Driver) clazz.newInstance();
        String url = "jdbc:mysql://localhost:3306/out";
        String user = "root";
        String password = "12345678";
        DriverManager.registerDriver(driver);
        Connection connection = DriverManager.getConnection(url, user, password);

        System.out.println(connection);

    }

    //方式四 在三的基础上做优化
    @Test
    public void testJdbcFour() throws Exception{

        String url = "jdbc:mysql://localhost:3306/out";
        String user = "root";
        String password = "12345678";
         Class.forName("com.mysql.cj.jdbc.Driver");

//        Driver driver = (Driver) clazz.newInstance();
//        DriverManager.registerDriver(driver);
        Connection connection = DriverManager.getConnection(url, user, password);

        System.out.println(connection);

    }
    //方式五 将数据库连接的四个基本信息声明在配置文件中
    @Test
    public void testJdbcFive() throws Exception{

        String url = "jdbc:mysql://localhost:3306/out";
        String user = "root";
        String password = "12345678";
        Class.forName("com.mysql.cj.jdbc.Driver");

//        Driver driver = (Driver) clazz.newInstance();
//        DriverManager.registerDriver(driver);
        Connection connection = DriverManager.getConnection(url, user, password);

        System.out.println(connection);

    }
}
