package com.example.shiyan5;

import android.support.v7.app.ActionBarActivity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class AppMainActivity extends AppCompatActivity {
    public Button bt;
    Button bt1;
    public EditText name;
    public EditText password;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_app_main);
        bt = (Button) findViewById(R.id.login_button);
        bt1 = (Button) findViewById(R.id.login_button1);
        bt.setOnClickListener(new Button.OnClickListener() {
            public void onClick(View v) {
                name = (EditText) findViewById(R.id.name);
                password = (EditText) findViewById(R.id.password);
                String myName = name.getText().toString();
                String mypassword = password.getText().toString();// 获取文本框输入信息
                Intent intent = new Intent();
                intent.setClass(AppMainActivity.this, SecondActivity.class);// 指定接下来要启动的class
                Bundle bundle = new Bundle();
                bundle.putString("name", myName);
                bundle.putString("password", mypassword);
                intent.putExtras(bundle);// 封装数据准备传递
                startActivity(intent);// 调用一个新的页面
            }
        });
        bt1.setOnClickListener(new Button.OnClickListener() {
            public void onClick(View v) {

                Intent intent = new Intent();
                intent.setClass(AppMainActivity.this, Shi.class);// 指定接下来要启动的class
                Bundle bundle = new Bundle();

                startActivity(intent);// 调用一个新的页面
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.app_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}