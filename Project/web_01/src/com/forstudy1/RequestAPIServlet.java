package com.forstudy1;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class RequestAPIServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

//        getRequestURI()  获取请求的资源路径

        System.out.println("URI => " + req.getRequestURI());

//        getRequestURL()   获取请求的统一资源定位符（绝对路径）
        System.out.println("URL => " + req.getRequestURL());
//        getRemoteHost()   获取客户端的ip地址

        /*
        * idea里 使用localhost访问时，得到的客户端ip地址是====>>>127.0.0.1
        * idea里 使用127.0.0.1访问时，得到的客户端ip地址是====>>>127.0.0.1
        * */
        System.out.println("HOST => " + req.getRemoteHost());
//        getHeader()  获取请求头
        System.out.println("Header  User-Agent => " + req.getHeader("User-Agent"));
//        getMethod()  获取请求的方式GET或POST
        System.out.println("Method => " + req.getMethod());


    }
}
