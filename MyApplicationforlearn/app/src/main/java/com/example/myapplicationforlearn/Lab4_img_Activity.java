package com.example.myapplicationforlearn;

import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.ImageView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.example.myapplicationforlearn.R;

public class Lab4_img_Activity extends AppCompatActivity {

    private CheckBox soup, hbg, coke, chips;

    private ImageView img1, img2, img3, img4;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lab4_img);

        soup = findViewById(R.id.soup);
        hbg = findViewById(R.id.hbg);
        coke = findViewById(R.id.coke);
        chips = findViewById(R.id.chips);

        img1 = findViewById(R.id.img1);
        img2 = findViewById(R.id.img2);
        img3 = findViewById(R.id.img3);
        img4 = findViewById(R.id.img4);


        CompoundButton.OnCheckedChangeListener occl = new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton cb, boolean b) {
                int id = cb.getId();
                if (b) {
                    switch (id) {
                        case R.id.soup:
                            img1.setVisibility(View.VISIBLE);
                            break;
                        case R.id.hbg:
                            img2.setVisibility(View.VISIBLE);
                            break;
                        case R.id.coke:
                            img3.setVisibility(View.VISIBLE);
                            break;
                        case R.id.chips:
                            img4.setVisibility(View.VISIBLE);
                            break;
                    }
                } else {
                    switch (id) {
                        case R.id.soup:
                            img1.setVisibility(View.GONE);
                            break;
                        case R.id.hbg:
                            img2.setVisibility(View.GONE);
                            break;
                        case R.id.coke:
                            img3.setVisibility(View.GONE);
                            break;
                        case R.id.chips:
                            img4.setVisibility(View.GONE);
                            break;
                    }
                }
            }
        };

        soup.setOnCheckedChangeListener(occl);
        hbg.setOnCheckedChangeListener(occl);
        chips.setOnCheckedChangeListener(occl);
        coke.setOnCheckedChangeListener(occl);

    }
}
