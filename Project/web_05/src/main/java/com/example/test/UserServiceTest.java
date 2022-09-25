package com.example.test;

import com.example.pojo.User;
import com.example.service.UserService;
import com.example.service.impl.UserServiceImpl;

import org.junit.Test;

public class UserServiceTest {

    UserService userService = new UserServiceImpl();
    @Test
    public void registUser() {
        userService.registUser(new User(null,"2451603830","578717377"));
    }

    @Test
    public void login() {
        System.out.println(userService.login(new User(null, "abc", "123")));
    }

    @Test
    public void existsUsername() {

        if (userService.existsUsername("assss")){
            System.out.println("用户名已存在");
        }else {
            System.out.println("用户名可用");
        }

    }
}