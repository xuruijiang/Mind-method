package com.example.shiyan4;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity  {




    Button b1,b2,b3,b4,b5,b6;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        b1=(Button)findViewById(R.id.bt1);
        b2=(Button)findViewById(R.id.bt2);
        b3=(Button)findViewById(R.id.bt3);
        b4=(Button)findViewById(R.id.bt4);
        b5=(Button)findViewById(R.id.bt5);
        b6=(Button)findViewById(R.id.bt6);


        View.OnLongClickListener occ= new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {

                Toast.makeText(MainActivity.this,"球门",Toast.LENGTH_LONG);

                if (b1.getText().toString().equals("什么门永远关不上")){
                    Toast.makeText(MainActivity.this,"球门",Toast.LENGTH_LONG);
                }else if (b2.getText().toString().equals("什么门永远关不上")){
                    Toast.makeText(MainActivity.this,"吃亏",Toast.LENGTH_LONG);
                }else if (b3.getText().toString().equals("什么门永远关不上")){
                    Toast.makeText(MainActivity.this,"傻瓜",Toast.LENGTH_LONG);
                }else if (b4.getText().toString().equals("什么门永远关不上")){
                    Toast.makeText(MainActivity.this,"瀑布",Toast.LENGTH_LONG);
                }else if (b5.getText().toString().equals("什么门永远关不上")){
                    Toast.makeText(MainActivity.this,"环保署",Toast.LENGTH_LONG);
                }else if (b6.getText().toString().equals("什么门永远关不上")){
                    Toast.makeText(MainActivity.this,"偷笑",Toast.LENGTH_LONG);
                }
                return false;
            }
        };


        View.OnClickListener onClickListener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                 Toast.makeText(MainActivity.this,"球门",Toast.LENGTH_LONG);

                if (b1.getText().toString().equals("什么门永远关不上")){
                    Toast.makeText(MainActivity.this,"球门",Toast.LENGTH_LONG);
                }else if (b2.getText().toString().equals("什么门永远关不上")){
                    Toast.makeText(MainActivity.this,"吃亏",Toast.LENGTH_LONG);
                }else if (b3.getText().toString().equals("什么门永远关不上")){
                    Toast.makeText(MainActivity.this,"傻瓜",Toast.LENGTH_LONG);
                }else if (b4.getText().toString().equals("什么门永远关不上")){
                    Toast.makeText(MainActivity.this,"瀑布",Toast.LENGTH_LONG);
                }else if (b5.getText().toString().equals("什么门永远关不上")){
                    Toast.makeText(MainActivity.this,"环保署",Toast.LENGTH_LONG);
                }else if (b6.getText().toString().equals("什么门永远关不上")){
                    Toast.makeText(MainActivity.this,"偷笑",Toast.LENGTH_LONG);
                }
            }
        };
        b1.setOnClickListener(onClickListener);
        b2.setOnClickListener(onClickListener);
        b3.setOnClickListener(onClickListener);
        b4.setOnClickListener(onClickListener);
        b5.setOnClickListener(onClickListener);
        b6.setOnClickListener(onClickListener);


       /* class ButtonListener implements View.OnClickListener{
            @Override
            public void onClick(View v){

                if (v.getId() == R.id.bt1){
                    Toast.makeText(MainActivity.this,"球门",Toast.LENGTH_LONG);
                }else if (v.getId() == R.id.bt2){
                    Toast.makeText(MainActivity.this,"吃亏",Toast.LENGTH_LONG);
                }else if (v.getId() == R.id.bt3){
                    Toast.makeText(MainActivity.this,"傻瓜",Toast.LENGTH_LONG);
                }else if (v.getId() == R.id.bt4){
                    Toast.makeText(MainActivity.this,"瀑布",Toast.LENGTH_LONG);
                }else if (v.getId() == R.id.bt5){
                    Toast.makeText(MainActivity.this,"环保署",Toast.LENGTH_LONG);
                }else if (v.getId() == R.id.bt6){
                    Toast.makeText(MainActivity.this,"偷笑",Toast.LENGTH_LONG);
                }


            }

        }*/

       // ButtonListener buttonListener =new ButtonListener();



    }
}
