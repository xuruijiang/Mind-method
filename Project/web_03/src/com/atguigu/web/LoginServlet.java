package com.atguigu.web;

import com.atguigu.pojo.User;
import com.atguigu.service.UserService;
import com.atguigu.service.impl.UserServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class LoginServlet extends HttpServlet {

    private UserService userService = new UserServiceImpl();
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        //获取请求参数
        String username = req.getParameter("username");
        String password = req.getParameter("password");

        //调用userService.login() 登陆处理业务
        User loginUser = userService.login(new User(null, username, password, null));

        //如果loginUser==null 说明登陆失败
        if (loginUser == null){
            //跳回登陆页面
            req.getRequestDispatcher("/pages/user/login.html").forward(req,resp);
        }else {
            //跳到login_success.html页面

            req.getRequestDispatcher("/pages/user/login_success.html").forward(req,resp);

        }
    }
}
