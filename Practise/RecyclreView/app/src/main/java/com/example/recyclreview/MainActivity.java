package com.example.recyclreview;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;
import android.os.Bundle;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    List<String> list = new ArrayList<>();
    RecyclerView recyclerView;
    MyAdapter myAdapter;
    String[] ansArr = {"球门","亏","傻瓜","瀑布","环保署","偷笑"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        recyclerView = findViewById(R.id.recyclerview);
/*        for (int i = 0;i<20;i++){
            list.add("第"+i+"条数据");
        }*/
        list.add("什么门永远关不上？");
        list.add("什么东西没人吃？");
        list.add("什么瓜不能吃？");
        list.add("什么布切不断？");
        list.add("什么鼠最爱干净？");
        list.add("偷什么不犯法？");
        myAdapter = new MyAdapter();
        recyclerView.setAdapter(myAdapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        recyclerView.addItemDecoration(new DividerItemDecoration(this));
    }

    private class MyAdapter extends RecyclerView.Adapter<MyViewHolder>{
        @NonNull
        @Override
        public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(MainActivity.this).
                    inflate(R.layout.activity_items,parent,false);
            MyViewHolder myViewHolder = new MyViewHolder(view);
            return myViewHolder;
        }

        @Override
        public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
            holder.textView.setText(list.get(position));
            holder.textView.setOnClickListener(v -> Toast.makeText(MainActivity.this,
                    "答案："+ansArr[position],Toast.LENGTH_SHORT).show());
        }

        @Override
        public int getItemCount() {
            return list.size();
        }
    }

    private class MyViewHolder extends RecyclerView.ViewHolder{
        TextView textView;
        public MyViewHolder(@NonNull View itemView) {
            super(itemView);
            textView = itemView.findViewById(R.id.textview);
        }
    }




    public class DividerItemDecoration extends RecyclerView.ItemDecoration{

        private int mOrientation = LinearLayoutManager.VERTICAL;
        private int mItemSize = 1;
        private Paint mPaint;

        public DividerItemDecoration(Context context){
            this(context,LinearLayoutManager.VERTICAL,R.color.colorAccent);
        }

        public DividerItemDecoration(Context context,int orientation){
            this(context,orientation,R.color.colorAccent);
        }

        public DividerItemDecoration(Context context, int orientation, int dividerColor) {
            this(context,orientation,dividerColor,1);
        }

        public DividerItemDecoration(Context context, int orientation, int dividerColor, int mItemSize) {
            this.mOrientation = orientation;
            if(orientation != LinearLayoutManager.VERTICAL && orientation != LinearLayoutManager.HORIZONTAL){
                throw new IllegalArgumentException("请输入正确参数");
            }
            this.mItemSize = (int) TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP,
                    mItemSize,context.getResources().getDisplayMetrics());
            mPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
            mPaint.setColor(context.getResources().getColor(dividerColor));
        }

        @Override
        public void onDraw(Canvas c, RecyclerView parent,RecyclerView.State state) {
//            super.onDraw(c, parent, state);
            if (mOrientation == LinearLayoutManager.VERTICAL){
                drawVertical(c,parent);
            }else {
                drawHorizontal(c,parent);
            }
        }

        private void drawHorizontal(Canvas canvas, RecyclerView parent) {
            final int top = parent.getPaddingTop();
            final int bottom = parent.getMeasuredHeight()-parent.getPaddingBottom();
            final int childSize = parent.getChildCount();
            for (int i = 0;i < childSize;i++){
                final View child = parent.getChildAt(i);
                RecyclerView.LayoutParams layoutParams =
                        (RecyclerView.LayoutParams)child.getLayoutParams();
                final int left = child.getRight()+layoutParams.rightMargin;
                final int right = left+mItemSize;
                canvas.drawRect(left,top,right,bottom,mPaint);
            }
        }

        private void drawVertical(Canvas canvas, RecyclerView parent) {
            final int left = parent.getPaddingLeft();
            final int right = parent.getMeasuredWidth()-parent.getPaddingRight();
            final int childSize = parent.getChildCount();
            for (int i = 0;i < childSize;i++){
                final View child = parent.getChildAt(i);
                RecyclerView.LayoutParams layoutParams =
                        (RecyclerView.LayoutParams)child.getLayoutParams();
                final int top = child.getBottom()+layoutParams.bottomMargin;
                final int bottom = top+mItemSize;
                canvas.drawRect(left,top,right,bottom,mPaint);
            }
        }

        @Override
        public void getItemOffsets(Rect outRect,View view,RecyclerView parent,RecyclerView.State state) {
//            super.getItemOffsets(outRect, view, parent, state);
            if (mOrientation == LinearLayoutManager.VERTICAL){
                outRect.set(0,0,0,mItemSize);
            }else {
                outRect.set(0,0,mItemSize,0);
            }
        }
    }
}