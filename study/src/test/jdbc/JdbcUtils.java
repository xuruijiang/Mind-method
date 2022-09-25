package test.jdbc;

import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ResourceBundle;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ResourceBundle;

/**
 * @author 张建平
 * @createtime 2022/3/27 下午4:49
 */
public class JdbcUtils {

    public static final String DRIVER = getValue("jdbc.driver");
    public static final String URL = getValue("jdbc.url");
    public static final String USERNAME = getValue("jdbc.username");
    public static final String PASSWORD = getValue("jdbc.password");

    static  {
        try {
            // 1. 加载数据库的驱动类，在系统运行时只需加载一次即可
            Class.forName(DRIVER);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    /**
     * 2. 获得数据库连接
     * @return java.sql.Connection
     */
    public static Connection getConnection() {
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);
        } catch (SQLException e) {
            System.err.println("连接数据库失败：" + e.getMessage());
        }
        return conn;
    }



    public static String getValue(String key) {
        ResourceBundle bundle = ResourceBundle.getBundle("jdbc");
        return bundle.getString(key);
    }



    public static void main(String[] args) {
        System.out.println(getValue("jdbc.driver"));
        System.out.println(getValue("jdbc.username"));

        Connection conn = getConnection();
        // java.sql.Connection ???
        System.out.println(conn);
    }
}
