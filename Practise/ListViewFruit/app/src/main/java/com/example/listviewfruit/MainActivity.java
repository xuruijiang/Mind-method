package com.example.listviewfruit;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    private ArrayList<Fruit> fruitList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        fruitList = new ArrayList<>();
        initFruit();

        ListView listView = (ListView)findViewById(R.id.listview_fruit);
        listView.setAdapter(new FruitAdapter(fruitList,MainActivity.this));

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Fruit fruit = fruitList.get(position);
                Toast.makeText(MainActivity.this,fruit.getName(),Toast.LENGTH_SHORT).show();
            }
        });

    }

    public void initFruit(){
        Fruit fruit0 = new Fruit("柠檬",R.drawable.pic_nm);
        Fruit fruit1 = new Fruit("橙子",R.drawable.pic_cz);
        Fruit fruit2 = new Fruit("毛桃",R.drawable.pic_mt);
        Fruit fruit3 = new Fruit("油桃",R.drawable.pic_yt);
        Fruit fruit4 = new Fruit("梨",R.drawable.pic_l);
        Fruit fruit5 = new Fruit("西瓜",R.drawable.pic_xg);
        Fruit fruit6 = new Fruit("荔枝",R.drawable.pic_lz);
        Fruit fruit7 = new Fruit("火龙果",R.drawable.pic_hlg);
        Fruit fruit8 = new Fruit("三华李",R.drawable.pic_shl);
        Fruit fruit9 = new Fruit("圣女果",R.drawable.pic_sng);
        Fruit fruit10 = new Fruit("香蕉",R.drawable.pic_xg);

        fruitList.add(fruit0);
        fruitList.add(fruit1);
        fruitList.add(fruit2);
        fruitList.add(fruit3);
        fruitList.add(fruit4);
        fruitList.add(fruit5);
        fruitList.add(fruit6);
        fruitList.add(fruit7);
        fruitList.add(fruit8);
        fruitList.add(fruit9);
        fruitList.add(fruit10);
    }
}