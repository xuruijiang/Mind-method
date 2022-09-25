package com.example.dao;

import com.example.pojo.User;

public interface UserDao {



    /**
     * 根据用户名查询用户信息
     * @param username 用户名
     * @return  如果返回null了，说明没有这个用户，反之亦然
     */
    public User queryUserByUsername(String username);

    /**
     * 根据用户名和密码查询用户
     * @param username
     * @return  如果返回null 说明用户名或密码错误，反之亦然
     */
    public User queryUserByUsernameAndPassword(String username,String password);

    /**
     * 保存用户信息
     * @param user
     * @return 返回大于0的数则注册成功   并添加入数据库
     */
    public int saveUser(User user);


}

