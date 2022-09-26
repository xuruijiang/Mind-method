package com.example.ballview;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;

import androidx.annotation.Nullable;

public class BallView extends View {
    public float currentX=60;
    public float currentY=60;
    Paint paint = new Paint();

    public BallView(Context context) {
        super(context);
    }

    public BallView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    protected void onDraw(Canvas canvas){
        super.onDraw(canvas);
        paint.setColor(Color.BLACK);
        canvas.drawCircle(currentX,currentY,20,paint);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event){
        currentX = event.getX();
        currentY = event.getY();
        invalidate();
        return true;
    }
}
