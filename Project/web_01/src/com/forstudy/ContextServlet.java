package com.forstudy;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.IOException;

public class ContextServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        //1.获取web.cml中配置的上下文参数context-param

        ServletContext context = getServletConfig().getServletContext();
        System.out.println(context.getInitParameter("username"));
        System.out.println(context.getInitParameter("password"));
        //2.获取当前的工程路径，格式：/工程路径

        System.out.println(context.getContextPath());

        //3.获取工程部署后在服务器硬盘上的绝对路径

        /*
        * /  斜杠被服务器解析地址为： http://ip:port/工程名/
        * */
        System.out.println(context.getRealPath("/"));
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {


    }
}
