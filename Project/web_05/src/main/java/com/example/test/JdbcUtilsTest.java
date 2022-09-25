package com.example.test;


import com.example.utils.JdbcUtils;
import org.junit.Test;

public class JdbcUtilsTest {



    @Test
    public void testJdbc(){

        for (int i = 0; i < 100; i++) {

            System.out.println(JdbcUtils.getConnection() +"+   " +  i );
        }
    }


}
