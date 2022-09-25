package com.forstudy1;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

public class ParameterServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("-------get-------");
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        String[] hobbies = req.getParameterValues("hobby");

        System.out.println("用户名: " + username);
        System.out.println("密码: " + password);

        System.out.println("兴趣爱好: " + Arrays.asList(hobbies));
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {


        //设置字符集，否则使用post请求时，出现中文会乱码，
        //设置字符集必须在获取请求参数之前调用才可以生效，记住是所有请求之前。。
        req.setCharacterEncoding("UTF-8");
        System.out.println("-------post-------");
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        String[] hobbies = req.getParameterValues("hobby");

        System.out.println("用户名: " + username);
        System.out.println("密码: " + password);

        System.out.println("兴趣爱好: " + Arrays.asList(hobbies));
    }

}
