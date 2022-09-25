package com.example.myapplicationforlearn;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        //获取按键对象
        Button but = findViewById(R.id.mybut);
        Button nextbut = findViewById(R.id.nextActivity);
        Button textbut = findViewById(R.id.textActivity);
        //获取文本对象
        TextView textView = findViewById(R.id.text);
        //获取EditText对象
        EditText editText = findViewById(R.id.scan);


        //点击事件1
        but.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (editText.getText().toString().length() != 0) {
                    //获取输入的非空文本
                    String ss = editText.getText().toString().trim();
                    textView.setText("您的名字是：" + ss);
                    editText.setText(null);
                }
            }
        });

        //点击事件2---切换页面
        nextbut.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, Lab2.class);
                startActivity(intent);
            }
        });

        //点击事件3---切换到text页面
        textbut.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this,textclass.class);
                startActivity(intent);
            }
        });
        //长按事件
        but.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {
                textView.setText("您好！欢迎使用本款APP！");
                return false;
            }
        });

        findViewById(R.id.loading).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this,Lab5Activity.class);
                startActivity(intent);
            }
        });
    }
}