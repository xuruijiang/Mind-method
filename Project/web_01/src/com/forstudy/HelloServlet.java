package com.forstudy;

import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import java.io.IOException;

public class HelloServlet implements Servlet {

    public HelloServlet() {

        System.out.println("1.构造器方法");
    }


    @Override
    public void init(ServletConfig servletConfig) throws ServletException {

        System.out.println("2.初始化方法");

        System.out.println("HelloServlet程序别名是:" + servletConfig.getServletName());

        System.out.println("HelloServlet初始化参数username的值是:" + servletConfig.getInitParameter("username"));
        System.out.println("HelloServlet初始化参数url的值是:" + servletConfig.getInitParameter("url"));
        System.out.println(servletConfig.getServletContext());
    }


    @Override
    public ServletConfig getServletConfig() {
        return null;
    }

    /**
     * service 方法是专门用来处理请求和响应的
     * @param servletRequest
     * @param servletResponse
     * @throws ServletException
     * @throws IOException
     */
    @Override
    public void service(ServletRequest servletRequest, ServletResponse servletResponse) throws ServletException, IOException {

        System.out.println("3. servlet----Hello Servlet 被访问了");
        HttpServletRequest httpServletRequest = (HttpServletRequest) servletRequest;

        String method = httpServletRequest.getMethod();

        if ("GET".equals(method)){
            doGet();

        }else if ("POST".equals(method)){
            doPost();
        }

    }

    public void doGet(){
        System.out.println("GET请求");

    }

    public void doPost(){
        System.out.println("POST请求");

    }

    @Override
    public String getServletInfo() {
        return null;
    }

    @Override
    public void destroy() {

        System.out.println("4.销毁方法");
    }
}
