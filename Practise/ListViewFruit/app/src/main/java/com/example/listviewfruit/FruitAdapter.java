package com.example.listviewfruit;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class FruitAdapter extends BaseAdapter {
    private ArrayList<Fruit> fruitList;
    Context context;

    public FruitAdapter(ArrayList<Fruit> fruitList,Context context){
        this.fruitList = fruitList;
        this.context = context;
    }


    @Override
    public int getCount() {
        return fruitList.size();
    }

    @Override
    public Object getItem(int position) {
        return null;
    }

    @Override
    public long getItemId(int position) {
        return 0;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        final Fruit fruit = fruitList.get(position);

        View v;
        ViewHolder holder;

        if (convertView == null){
            v = LayoutInflater.from(context).inflate(R.layout.item_fruit,null);

            holder = new ViewHolder();
            holder.fruitName = (TextView)v.findViewById(R.id.name_fruit);
            holder.fruitImage = (ImageView) v.findViewById(R.id.image_fruit);
            holder.fruitSubmit = (Button) v.findViewById(R.id.btn_submit);
            v.setTag(holder);
        } else {
            v = convertView;
            holder = (ViewHolder)v.getTag();
        }

        holder.fruitName.setText(fruit.getName());
        holder.fruitImage.setImageResource(fruit.getImageId());
        holder.fruitSubmit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(context,"您已经订购"+fruit.getName(),Toast.LENGTH_SHORT).show();
            }
        });
        return v;
    }

    class ViewHolder{
        ImageView fruitImage;
        TextView fruitName;
        Button fruitSubmit;
    }
}
