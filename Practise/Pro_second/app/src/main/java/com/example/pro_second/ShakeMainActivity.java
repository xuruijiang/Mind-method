package com.example.pro_second;

import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.os.Vibrator;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class ShakeMainActivity extends AppCompatActivity implements SensorEventListener {

    private SensorManager sensorManager;
    private Vibrator vibrator;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_shake);
        sensorManager = (SensorManager)getSystemService(Context.SENSOR_SERVICE);
        vibrator = (Vibrator)getSystemService(Context.VIBRATOR_SERVICE);
    }

    @Override
    protected void onPause() {
        super.onPause();
        sensorManager.unregisterListener(this);
    }

    @Override
    protected void onResume() {
        super.onResume();
        sensorManager.registerListener(this,
                sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER),
                SensorManager.SENSOR_DELAY_NORMAL);
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        if (event.sensor.getType() == Sensor.TYPE_ACCELEROMETER){
            float[] values = event.values;
            if ((Math.abs(values[0]) > 15) || Math.abs(values[1]) > 15 || Math.abs(values[2]) > 15){
                Toast.makeText(this,"您成功摇一摇了",Toast.LENGTH_SHORT).show();
                vibrator.vibrate(500);
            }
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }
}
