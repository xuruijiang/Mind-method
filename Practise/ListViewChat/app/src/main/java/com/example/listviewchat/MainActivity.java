package com.example.listviewchat;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    private ListView listView;
    private ListViewAdapter adapter;
    private List<Message> messages;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        init();

        listView = (ListView)findViewById(R.id.listview);
        listView.setAdapter(adapter=new ListViewAdapter(this,messages));
    }

    private void init(){
        messages = new ArrayList<>();
        messages.add(new Message("你在哪个班级呢？",false));
        messages.add(new Message("物联网19-2班",true));

        messages.add(new Message("你叫什么名字呀？",false));
        messages.add(new Message("徐瑞江",true));

        messages.add(new Message("你的学号是什么？",false));
        messages.add(new Message("3182052051639",true));
    }
}