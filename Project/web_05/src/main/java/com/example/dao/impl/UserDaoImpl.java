package com.example.dao.impl;

import com.example.dao.UserDao;
import com.example.pojo.User;


import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserDaoImpl implements UserDao {
    @Override
    public User queryUserByUsername(String username) {



        try(Connection connection = com.example.utils.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("SELECT user_id,username,password FROM userinfo WHERE username = ?");

            ps.setString(1,username);

            ResultSet rs = ps.executeQuery();

            while (rs.next()) {

                int id = rs.getInt("user_id");
                String usernameOne = rs.getString("username");
                String password = rs.getString("password");

                User user = new User(id,usernameOne,password);

                return user;
            }

        } catch (SQLException e) {
            System.err.println("查询失败->>>"+ e.getMessage());
        }

        return null;
    }

    @Override
    public User queryUserByUsernameAndPassword(String username, String password) {
        try(Connection connection = com.example.utils.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("SELECT user_id,username,password FROM userinfo WHERE username = ? AND password = ?");

            ps.setString(1,username);
            ps.setString(2,password);

            ResultSet rs = ps.executeQuery();

            while (rs.next()) {

                int id = rs.getInt("user_id");
                String usernameOne = rs.getString("username");
                String passwordOne = rs.getString("password");

                User user = new User(id,usernameOne,passwordOne);

                return user;
            }

        } catch (SQLException e) {
            System.err.println("查询失败->>>"+ e.getMessage());
        }

        return null;
    }

    @Override
    public int saveUser(User user) {


        try(Connection connection =  com.example.utils.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("INSERT INTO userinfo(username,password) VALUES (?,?);");
            ps.setString(1,user.getUsername());
            ps.setString(2,user.getPassword());


            return ps.executeUpdate();

        } catch (SQLException e) {
            System.err.println("添加失败->>" + e.getMessage());
        }

        return 0;
    }

}
