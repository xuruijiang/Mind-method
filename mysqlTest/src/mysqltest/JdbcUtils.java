package mysqltest;

import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ResourceBundle;

import static javax.xml.bind.JAXBIntrospector.getValue;

public class JdbcUtils {

    private static final String DRIVER = (String) getValue("jdbc.deiver");
    private static final String URL = getValue("jdbc.url");
    public static final String USERNAME = getValue("jdbc.username");
    public static final String PASSWORD = getValue("jdbc.password");

    static {
        try {
            Class.forName(DRIVER);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public static String getValue(String key){
        ResourceBundle bundele = ResourceBundle.getBundle("jdbc");
        return bundele.getString(key);
    }

    public static Connection getConnection(){

        Connection conn = null;
        try {
            return DriverManager.getConnection(URL,USERNAME,PASSWORD);
        } catch (SQLException e) {
            System.err.println("获得数据库链接失败"+ e.getMessage());

        }
        return conn;

    }
    public static void main(String[] args) {
        System.out.println(getValue("jdbc.driver"));
        System.out.println(getValue("jdbc.username"));

        Connection conn = getConnection();
        // java.sql.Connection ???
        System.out.println(conn);
    }
}
