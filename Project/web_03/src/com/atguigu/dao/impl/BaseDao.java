package com.atguigu.dao.impl;

import com.atguigu.utils.JdbcUtils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public abstract class BaseDao {


    public void del(int id){

        try(Connection connection = JdbcUtils.getConnection();) {
            PreparedStatement ps = connection.prepareStatement("DELETE FROM t_user WHERE id = ?");

            ps.setInt(1,id);

            if (ps.executeUpdate()>0){

                System.out.println("删除成功");
            }

        } catch (SQLException e) {
            System.out.println("删除失败");
        }


    }
}
