package com.lanqiap.jdbc.dao;

import java.text.SimpleDateFormat;
import java.util.Date;

public class DateUtils {
    final static String[] patterns = {
            "yyy-MM-dd HH:mm:ss",
            "yyy/MM/dd HH:mm:ss",
            "yyy-MM-dd",
            "yyy/MM/dd",
    };

    /**
     * 日期格式
     */
    public static String format(Date date, String format) {
        SimpleDateFormat sdf = new SimpleDateFormat(format);
        return sdf.format(date);
    }
}
