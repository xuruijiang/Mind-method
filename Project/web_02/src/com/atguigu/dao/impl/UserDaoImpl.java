package com.atguigu.dao.impl;

import com.atguigu.dao.UserDao;
import com.atguigu.pojo.User;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UserDaoImpl implements UserDao {
    @Override
    public User queryUserByUsername(String username) {



        try(Connection connection = com.atguigu.utils.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("SELECT id,username,password,email FROM t_user WHERE username = ?");

            ps.setString(1,username);

            ResultSet rs = ps.executeQuery();

            while (rs.next()) {

                int id = rs.getInt("id");
                String usernameOne = rs.getString("username");
                String password = rs.getString("password");
                String email = rs.getString("email");

                User user = new User(id,usernameOne,password,email);

                return user;
            }

        } catch (SQLException e) {
            System.err.println("查询失败->>>"+ e.getMessage());
        }

        return null;
    }

    @Override
    public User queryUserByUsernameAndPassword(String username, String password) {
        try(Connection connection = com.atguigu.utils.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("SELECT id,username,password,email FROM t_user WHERE username = ? AND password = ?");

            ps.setString(1,username);
            ps.setString(2,password);

            ResultSet rs = ps.executeQuery();

            while (rs.next()) {

                int id = rs.getInt("id");
                String usernameOne = rs.getString("username");
                String passwordOne = rs.getString("password");
                String email = rs.getString("email");

                User user = new User(id,usernameOne,password,email);

                return user;
            }

        } catch (SQLException e) {
            System.err.println("查询失败->>>"+ e.getMessage());
        }

        return null;
    }

    @Override
    public int saveUser(User user) {


        try(Connection connection =  com.atguigu.utils.JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("INSERT INTO t_user(username,password,email) VALUES (?,?,?);");
            ps.setString(1,user.getUsername());
            ps.setString(2,user.getPassword());
            ps.setString(3,user.getEmail());

            return ps.executeUpdate();

        } catch (SQLException e) {
            System.err.println("添加失败->>" + e.getMessage());
        }

        return 0;
    }

}
