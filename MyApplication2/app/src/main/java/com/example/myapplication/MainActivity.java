 package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

 public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }


    public void sayHello(View v){
        EditText name = (EditText)findViewById(R.id.editText);
        TextView txv = (TextView)findViewById(R.id.textView);
        String str = name.getText().toString().trim();
        if (str.length() == 0){
            txv.setText("请输入您的名字！");
        }else{
            txv.setText(name.getText().toString() + ", 您好！");
        }
    }


}