package com.example.myapplicationforlearn;

import android.content.Context;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

/**
 * 通过ListView实现下拉列表
 */
public class Lab3_by_ListView extends AppCompatActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lab3_by_listvew);

        List<Image> list = add_data();

        ListView listview = findViewById(R.id.Lab3_1);
        listview.setAdapter(new MyAdapter(list,this));
    }

    /**
     * 添加元素
     * @return 包含listView属性的集合
     */
    public static List<Image> add_data() {

        List<Image> list = new ArrayList<>();

        int[] pic = {
                R.drawable.bcgl, R.drawable.dcf,
                R.drawable.hgr, R.drawable.hsqz,
                R.drawable.hsr, R.drawable.mpdf,
                R.drawable.nrb};
        String [] name ={"爆炒蛤蜊","蛋炒饭","回锅肉","红烧茄子","红烧肉","麻婆豆腐","牛肉煲"};

        for (int i =0;i<pic.length;i++){
            list.add(new Image(pic[i],name[i]));
        }

        return list;
    }
}

/**
 * 属性类
 */
class Image {
    private int image;
    private String name;

    public Image(int image, String name) {
        this.image = image;
        this.name = name;
    }

    public int getImage() {
        return image;
    }

    public void setImage(int image) {
        this.image = image;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}

/**
 * 适配器类，用于重写某些方法
 */
class MyAdapter extends BaseAdapter {

    private List<Image> data;
    private Context context;

    public MyAdapter(List<Image> data, Context context) {
        this.data = data;
        this.context = context;
    }

    @Override
    public int getCount() {
        return data.size();
    }

    @Override
    public Object getItem(int i) {
        return data.get(i);
    }

    @Override
    public long getItemId(int i) {
        return i;
    }

    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {

        Image image = (Image) getItem(i);
        Viewholder viewholder;

        if (view == null) {
            viewholder = new Viewholder();
            view = LayoutInflater.from(context).inflate(R.layout.list_item, viewGroup, false);

            viewholder.imageView = view.findViewById(R.id.ImageView_List);
            viewholder.textView = view.findViewById(R.id.TextView_List);

            viewholder.imageView.setImageResource(image.getImage());
            viewholder.textView.setText(image.getName());

            view.setTag(viewholder);
        } else {
            viewholder = (Viewholder) view.getTag();
        }
        return view;
    }

    class Viewholder {
        TextView textView;
        ImageView imageView;
    }
}