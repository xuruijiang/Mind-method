package com.forstudy;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.IOException;

public class ContextServlet1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        //获取ServletContext对象
        ServletContext context = getServletContext();

        System.out.println("保存前   "+context.getAttribute("key1"));

        context.setAttribute("key1","value1");
        context.setAttribute("key2","value2");

        System.out.println(context.getAttribute("key1"));


        System.out.println(context);

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
