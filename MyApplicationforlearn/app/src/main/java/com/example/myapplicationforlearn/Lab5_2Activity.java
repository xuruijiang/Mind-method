package com.example.myapplicationforlearn;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class Lab5_2Activity extends AppCompatActivity {

    private EditText name,password,phone,gender,hobby;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lab5_2);

        Button rg = findViewById(R.id.register);

        name = findViewById(R.id.name);
        password = findViewById(R.id.pass_word);
        phone = findViewById(R.id.phone_number);
        gender = findViewById(R.id.gender);
        hobby = findViewById(R.id.hobby);

        rg.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent = new Intent(Lab5_2Activity.this,Lab5Activity.class);
                Bundle  bundle = new Bundle();

                bundle.putString("phone",phone.getText().toString());
                bundle.putString("password",password.getText().toString());

                intent.putExtras(bundle);
                Lab5_2Activity.this.setResult(0,intent);
                Lab5_2Activity.this.finish();
            }
        });

    }
}
