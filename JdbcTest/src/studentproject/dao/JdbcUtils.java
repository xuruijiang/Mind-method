package studentproject.dao;

import com.lanqiap.jdbc.dao.EmployeeDao;
import com.lanqiap.jdbc.model.Employee;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ResourceBundle;



public class JdbcUtils {
    //加载数据库的驱动
    public static final String DRIVER = getValue("jdbc.driver");
    public static final String URL = getValue("jdbc.url");
    public static final String USERNAME = getValue("jdbc.username");
    public static final String PASSWORD = getValue("jdbc.password");

    static {
        try {
            Class.forName(DRIVER);
        } catch (ClassNotFoundException e) {

        }
    }

    /**
     * 获得数据库连接
     *
     * @return
     */
    public static Connection getConnection() {
        Connection connection = null;
        try {
            connection = DriverManager.getConnection(URL, USERNAME, PASSWORD);
        } catch (SQLException e) {
            System.err.println("数据库连接失败" + e.getMessage());
        }
        return connection;
    }

    public static String getValue(String key) {
        ResourceBundle bundle = ResourceBundle.getBundle("jdbc");
        return bundle.getString(key);
    }

}
