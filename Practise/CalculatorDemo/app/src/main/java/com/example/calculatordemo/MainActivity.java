package com.example.calculatordemo;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.ibtn_calculator).setOnClickListener(this);
    }


    public void onClick(View v){
        if (v.getId() == R.id.ibtn_calculator){
            Intent intent = new Intent(this,CalculatorActivity.class);
            startActivity(intent);
        }
    }
}