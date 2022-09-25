package com.example.myapplicationforlearn;

import android.annotation.SuppressLint;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Adapter;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.NotificationCompat;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class textclass extends AppCompatActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_textclass);

        List<RcImage> list = add_data();

        //获取RecyclerView对象
        RecyclerView rv = findViewById(R.id.recy);

        //设置布局，ListView不需要设置布局
        LinearLayoutManager ll  = new LinearLayoutManager(this,LinearLayoutManager.VERTICAL,true);
        rv.setLayoutManager(ll);
        //设置Adapter
        rv.setAdapter(new MyRcAdapter(list,textclass.this));
    }

    public static List<RcImage> add_data() {

        List<RcImage> list = new ArrayList<>();

        int[] pic = {
                R.drawable.f14, R.drawable.f16, R.drawable.f22,
                R.drawable.su27, R.drawable.su30, R.drawable.j20,
                R.drawable.j201, R.drawable.mg21};
        String[] name = {
                "F-14雄猫战斗机", "F-16隼战斗机", "F-22猛禽隐形战斗机",
                "Su-27侧卫战斗机", "Su30mk侧卫战斗机", "J-20威龙隐形战斗机",
                "F-15鹰战斗机"};

        for (int i = 0; i < pic.length; i++) {
            list.add(new RcImage(name[i], pic[i]));
        }

        return list;
    }
}

class MyRcAdapter extends RecyclerView.Adapter<MyRcAdapter.MyViewholder> {

    private List<RcImage> list;
    private Context context;

    public MyRcAdapter(List<RcImage> list, Context context) {
        this.list = list;
        this.context = context;
    }

    @NonNull
    @Override
    //获取item的师徒对象，并将视图传递给myviewholder
    public MyViewholder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = View.inflate(context,R.layout.list_item,null);
        return new MyViewholder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewholder holder, int position) {
        holder.textView.setText(list.get(position).getName());
        holder.imageView.setImageResource(list.get(position).getImage());
    }

    @Override
    public int getItemCount() {
        return list.size();
    }

    class MyViewholder extends RecyclerView.ViewHolder {

        //定义需要赋值的控件对象
        ImageView imageView;
        TextView textView;

      public MyViewholder(@NonNull View itemView) {
          super(itemView);
          imageView = itemView.findViewById(R.id.ImageView_List);
          textView = itemView.findViewById(R.id.TextView_List);
      }
  }
}

class RcImage {
    private String name;
    private int image;

    public RcImage(String name, int image) {
        this.name = name;
        this.image = image;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getImage() {
        return image;
    }

    public void setImage(int image) {
        this.image = image;
    }
}


