package com.example.service;

import com.example.pojo.User;


public interface UserService {



    /**
     * 注册用户
     * @param user
     */
    public void registUser(User user);


    /**
     * 登陆
     * @param user
     * @return
     */
    public User login (User user);

    /**
     * 检查  用户名是否可用
     * @param username
     * @return 返回true 表明用户名已存在，反之不存在
     */
    public boolean existsUsername(String username);

}
