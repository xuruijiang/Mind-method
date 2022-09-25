package com.example.myapplicationforlearn;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;
import java.util.List;

public class Lab4 extends AppCompatActivity {

    private CheckBox soup, hbg, coke, chips;
    String msg = "";
    List<String> list = new ArrayList<String>();


    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lab4);

        soup = findViewById(R.id.soup);
        hbg = findViewById(R.id.hbg);
        coke = findViewById(R.id.coke);
        chips = findViewById(R.id.chips);

        Button but = findViewById(R.id.mbut);
        Button button = findViewById(R.id.but_next);
        TextView foods = findViewById(R.id.foods);
        TextView textView = findViewById(R.id.hadbuy);

        //写一个监听器对象
        CompoundButton.OnCheckedChangeListener occl = new CompoundButton.OnCheckedChangeListener() {

            @Override
            //compoundButton-->将checkbox的对象传回
            //b-->传回一个布尔值，用于判断是否被选中
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if (b) {
                    list.add(compoundButton.getText().toString());
                } else {
                    list.remove(compoundButton.getText().toString());
                }

            }
        };

        soup.setOnCheckedChangeListener(occl);
        coke.setOnCheckedChangeListener(occl);
        chips.setOnCheckedChangeListener(occl);
        hbg.setOnCheckedChangeListener(occl);

        but.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (list.isEmpty()) {
                    foods.setText("您没有点购任何餐品，请选择餐品后再点击下单!");
                    textView.setText(null);
                } else {
                    foods.setText("您点购的餐品有:");
                    textView.setText(" " + list.toString().replace("[", "").replace("]", "").replace(",", "").trim());
                }
            }
        });

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(Lab4.this,Lab4_img_Activity.class);
                startActivity(intent);
            }
        });
    }
}
