package com.atguigu.utils;

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


//    private static DruidDataSource druidDataSource;
//
//
//    static {
//
//        try {
//            Properties properties = new Properties();
//            InputStream inputStream = JdbcUtils.class.getClassLoader().getResourceAsStream("jdbc.properties");
//            properties.load(inputStream);
//            druidDataSource = (DruidDataSource) DruidDataSourceFactory.createDataSource(properties);
//            System.out.println(druidDataSource.getConnection());
//        } catch (Exception e) {
//            e.printStackTrace();
//        }
//
//    }

//    public static void main(String[] args) {
//
//    }

    /**
     *
     *获取数据库链接池的链接
     * @return
     */
    public static Connection getConnection(){

        Connection connection = null;
        try {
            connection = DriverManager.getConnection(URL, USERNAME, PASSWORD);
        } catch (SQLException e) {
            System.err.println("数据库连接失败" + e.getMessage());
        }
        return connection ;
    }


    public static void close(Connection conn){
        if (conn !=null){
            try {
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }


    public static String getValue(String key){
        ResourceBundle bundle = ResourceBundle.getBundle("jdbc");
        return bundle.getString(key);
    }



}

