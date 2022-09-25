package com.example.myapplicationforlearn;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class Lab2 extends AppCompatActivity {
    private int count =0;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lab2);

        //获取文本对象
        TextView view1 = findViewById(R.id.lab2);

        //获取计数数值对象
        TextView view2 = findViewById(R.id.count);

        //加一按钮
        Button but = findViewById(R.id.addbut);
        //清零按钮
        Button butc = findViewById(R.id.clear);
        //跳转到上一页（计数器的上一页，即首页）
        Button but1 = findViewById(R.id.last);
        //跳转到下一页按钮
        Button butn = findViewById(R.id.next);

        Button button = findViewById(R.id.next_2);

        Button food_but = findViewById(R.id.buyfoods);


        //计数器加一操作
        but.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                //按下，设置文本
                count+=1;
                view1.setText("你的数值为:");
                String s = count+" ";
                view2.setText(s);
            }
        });

        //清零操作
        butc.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                count=0;
                view2.setText("0");
            }
        });

        //跳转到上一页
        but1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent = new Intent(Lab2.this,MainActivity.class);
                startActivity(intent);
            }
        });

        //跳转到下一页
        butn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(Lab2.this,Lab3_by_ListView.class);
                startActivity(intent);
            }
        });

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(Lab2.this,Lab3_by_RecycleView.class);
                startActivity(intent);
            }
        });

        //点购餐品
        food_but.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(Lab2.this,Lab4.class);
                startActivity(intent);
            }
        });
    }
}
