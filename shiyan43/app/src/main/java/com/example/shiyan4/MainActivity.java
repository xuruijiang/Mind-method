package com.example.shiyan4;

import androidx.appcompat.app.AppCompatActivity;

import android.icu.text.CaseMap;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemClickListener {

    String[] queArr = {"什么门永远关不上","什么东西没人爱吃？",  "什么瓜不能吃？","什么布切不断？",  "什么鼠最爱干净？","偷什么不犯法？"};

    String[] ansArr = { "球门", "亏",  "傻瓜","瀑布",  " 环保署","偷笑" };
//    ListView mylist = null;
//
//    TextView title ;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ArrayAdapter<String> adapter = new ArrayAdapter<>( this,
                android.R.layout.simple_list_item_1, // 使用内置的布局资源
                queArr);                  // 以 queArr 数组当数据源

        ListView lv = (ListView)findViewById(R.id.lv);  //获取 ListView
        lv.setAdapter(adapter);           //设置 ListView 使用的 Adapter
        lv.setOnItemClickListener(this); //设置 ListView 项目被单击时的事件监听器
    }
    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        Toast.makeText(this, "答案︰" + ansArr[position], Toast.LENGTH_SHORT).show();
    }



//        mylist = findViewById(R.id.mylist);
//
//        MyAdapter md = new MyAdapter();
//
//        mylist.setAdapter(md);


//    private class MyAdapter extends BaseAdapter {
//        @Override
//        public int getCount() {
//            return queArr .length;
//        }
//
//        @Override
//        public Object getItem(int i) {
//            return queArr[i];
//        }
//
//        @Override
//        public long getItemId(int i) {
//            return i;
//        }
//
//        @Override
//        public View getView(int i, View view, ViewGroup viewGroup) {
//            View vie = View.inflate(MainActivity.this,R.layout.layout,null);
//
//           title   = vie.findViewById(R.id.list);
//
//           title.setText(queArr[i]);
//            return null;
//        }
//    }
}