package com.atguigu.test;

import com.atguigu.dao.impl.BaseDao;
import com.atguigu.utils.JdbcUtils;
import org.junit.Test;

public class JdbcUtilsTest {



    @Test
    public void testJdbc(){

        for (int i = 0; i < 100; i++) {

            System.out.println(JdbcUtils.getConnection() +"+   " +  i );
        }
    }

    @Test
    public void testJdbc1(){
       BaseDao baseDao = new BaseDao() {
           @Override
           public void del(int id) {
               super.del(id);
           }
       };

       baseDao.del(1);

    }
}
