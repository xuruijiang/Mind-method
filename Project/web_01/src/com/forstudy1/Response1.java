package com.forstudy1;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class Response1 extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        System.out.println("曾到此一游");
        //设置响应状态码302，表示重定向，（已搬迁）
        //resp.setStatus(302);

        //设置响应头，说明新的地址在哪里
        //resp.setHeader("location","http://localhost:8080/web_01_war_exploded/response2");

        //resp.setHeader("location","http://www.baidu.com");

        resp.sendRedirect("http://www.baidu.com");
    }
}
