package com.atguigu.test;

import com.atguigu.dao.impl.UserDaoImpl;
import com.atguigu.pojo.User;
import org.junit.Test;

import static org.junit.Assert.*;

public class UserDaoTest {

    @Test
    public void queryUserByUsername() {

        UserDaoImpl userDao = new UserDaoImpl();

        System.out.println(userDao.queryUserByUsername("admin"));
    }

    @Test
    public void queryUserByUsernameAndPassword() {
    UserDaoImpl userDao = new UserDaoImpl();

        System.out.println(userDao.queryUserByUsernameAndPassword("admin", "admin"));
    }

    @Test
    public void saveUser() {
        UserDaoImpl userDao = new UserDaoImpl();
        userDao.saveUser(new User(null,"abcd","123","at@com"));

    }
}