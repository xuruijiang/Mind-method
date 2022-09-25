package com.example.myapplicationforlearn;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class Lab3_by_RecycleView extends AppCompatActivity {

    private int[] pic = {
            R.drawable.f14, R.drawable.f16, R.drawable.f22,
            R.drawable.su27, R.drawable.su30, R.drawable.j20,
            R.drawable.j201, R.drawable.mg21};

    private String[] name = {
            "F-14雄猫战斗机", "F-16隼战斗机", "F-22猛禽隐形战斗机",
            "Su-27侧卫战斗机", "Su30mk侧卫战斗机", "J-20威龙隐形战斗机",
            "F-15鹰战斗机"};

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lab3_by_recycleview);
        RecyclerView rv = findViewById(R.id.recy);

        rv.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, true));
        rv.setAdapter(new RecyAdapt());
        rv.setVisibility(View.VISIBLE);

    }

    class RecyAdapt extends RecyclerView.Adapter<RecyAdapt.MyViewHolder> {

        @NonNull
        @Override
        public RecyAdapt.MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            View view = View.inflate(Lab3_by_RecycleView.this, R.layout.recy_item, null);
            return new RecyAdapt.MyViewHolder(view);
        }

        @Override
        public void onBindViewHolder(@NonNull RecyAdapt.MyViewHolder holder, int position) {
            holder.imageView.setImageResource(pic[position]);
            holder.textView.setText(name[position]);
        }

        @Override
        public int getItemCount() {
            return pic.length;
        }

        class MyViewHolder extends RecyclerView.ViewHolder {

            ImageView imageView;
            TextView textView;

            public MyViewHolder(@NonNull View itemView) {
                super(itemView);
                imageView = itemView.findViewById(R.id.recy_image);
                textView = itemView.findViewById(R.id.recy_text);
            }
        }
    }
}

class reView {

    private int image;
    private String text;

    public reView(int image, String text) {
        this.image = image;
        this.text = text;
    }

    public int getImage() {
        return image;
    }

    public void setImage(int image) {
        this.image = image;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }
}