package com.example.shiyan4;

import java.util.ArrayList;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.drawable.BitmapDrawable;
import android.os.Bundle;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.WindowManager.LayoutParams;
import android.widget.Button;
import android.widget.EditText;
import android.widget.PopupWindow;
import android.widget.Toast;

import androidx.core.app.NotificationCompat;

public class MainActivity extends Activity implements Runnable{
    public static int yourChose = 0;
    public static ArrayList<Integer> myChose= new ArrayList<Integer>();
    public static PopupWindow window;

    private void showClickMessage(String str) {
        Toast.makeText(this, str, Toast.LENGTH_SHORT).show();
    }
    //进度条的参数
    ProgressDialog mReadProcessDia=null;
    public final static int MAX_READPROCESS = 100;




    //用于进度条的方法
    private void showProcessDia()
    {
        ProgressDialog processDia= new ProgressDialog(MainActivity.this);
        processDia.setTitle("进度条框");
        processDia.setMessage("内容读取中...");
        processDia.setIndeterminate(true);
        processDia.setCancelable(true);
        processDia.show();
    }



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        Button normalButton = (Button) findViewById(R.id.normal);
        Button multiCheckButton = (Button) findViewById(R.id.multi);
        Button listButton = (Button) findViewById(R.id.list);
        Button radioButton = (Button) findViewById(R.id.radio);
        Button checkBoxButton = (Button) findViewById(R.id.checkBoxes);
        Button progressButton = (Button) findViewById(R.id.progress);
        Button customButton = (Button) findViewById(R.id.custom);
        final Button popbButton = (Button) findViewById(R.id.popWindow);

        normalButton.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                //普通对话框
                AlertDialog.Builder normalDia=new AlertDialog.Builder(MainActivity.this);
                normalDia.setIcon(R.drawable.ic_launcher);
                normalDia.setTitle("普通的对话框");

                normalDia.setMessage("普通对话框的message内容");
                normalDia.setPositiveButton("确定", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        showClickMessage("确定");
                    }
                });
                normalDia.setNegativeButton("取消", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        showClickMessage("取消");
                    }
                });
                normalDia.create().show();
            }
        });


        multiCheckButton.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                //底部多按钮对话框
                AlertDialog.Builder multiDia=new AlertDialog.Builder(MainActivity.this);
                multiDia.setTitle("多选项对话框");
                multiDia.setPositiveButton("按钮一", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        showClickMessage("按钮一");
                    }
                });
                multiDia.setNeutralButton("按钮二", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        showClickMessage("按钮二");
                    }
                });
                multiDia.setNegativeButton("按钮三", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        showClickMessage("按钮三");
                    }
                });
                multiDia.create().show();
            }
        });

        listButton.setOnClickListener(new OnClickListener() {
            //列表对话框
            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                final String[] mList={"选项1","选项2","选项3","选项4","选项5","选项6","选项7"};
                AlertDialog.Builder listDia=new AlertDialog.Builder(MainActivity.this);
                listDia.setTitle("列表对话框");
                listDia.setItems(mList, new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        showClickMessage(mList[which]);
                    }
                });
                listDia.create().show();

            }
        });

        radioButton.setOnClickListener(new OnClickListener() {
            //单项选择对话框
            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                final String[] mList={"选项1","选项2","选项3","选项4","选项5","选项6","选项7"};
                //int  yourChose=-1;
                AlertDialog.Builder sinChosDia=new AlertDialog.Builder(MainActivity.this);
                sinChosDia.setTitle("单项选择对话框");
                sinChosDia.setSingleChoiceItems(mList, 0, new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        yourChose=which;
                    }
                });
                sinChosDia.setPositiveButton("确定", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        if(yourChose!=-1)
                        {
                            showClickMessage(mList[yourChose]);
                        }
                    }
                });
                sinChosDia.create().show();

            }
        });


        checkBoxButton.setOnClickListener(new OnClickListener() {
            //多项选择对话框
            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub

                final String[] mList={"选项1","选项2","选项3","选项4","选项5","选项6","选项7"};
                final boolean mChoseSts[]={false,false,false,false,false,false,false};
                myChose.clear();
                AlertDialog.Builder multiChosDia=new AlertDialog.Builder(MainActivity.this);
                multiChosDia.setTitle("多项选择对话框");
                multiChosDia.setMultiChoiceItems(mList, mChoseSts, new DialogInterface.OnMultiChoiceClickListener() {
                    public void onClick(DialogInterface dialog, int which, boolean isChecked) {
                        if(isChecked)
                        {  myChose.add(which);  }
                        else
                        {   myChose.remove(which);  }
                    }
                });
                multiChosDia.setPositiveButton("确定", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        int size=myChose.size();
                        String str="";
                        for(int i=0;i<size;i++)
                        {   str+=mList[myChose.get(i)];  }
                        showClickMessage(str);
                    }
                });
                multiChosDia.create().show();

            }
        });

        progressButton.setOnClickListener(new OnClickListener() {
            //进度条
            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                mReadProcessDia=new ProgressDialog(MainActivity.this);
                mReadProcessDia.setProgress(0);
                mReadProcessDia.setTitle("进度条窗口");
                mReadProcessDia.setProgressStyle(ProgressDialog.STYLE_HORIZONTAL);
                mReadProcessDia.setMax(MAX_READPROCESS);
                mReadProcessDia.show();
                new Thread(MainActivity.this).start();
            }
        });
        //强烈推荐：自定义布局的对话框
        customButton.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                AlertDialog.Builder customDia=new AlertDialog.Builder(MainActivity.this);
                final View viewDia=LayoutInflater.from(MainActivity.this).inflate(R.layout.dia_input, null);
                customDia.setTitle("自定义对话框");
                customDia.setView(viewDia);
                customDia.setPositiveButton("确定", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int which) {
                        EditText diaInput=(EditText) viewDia.findViewById(R.id.editText1);
                        showClickMessage(diaInput.getText().toString());
                    }
                });
                customDia.create().show();

            }
        });
        //弹出popwindow
        popbButton.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                View popupView;
                Button cusPopupBtn1 = null;
                Button exitButton = null;
                if(window == null||cusPopupBtn1==null)
                {
                    popupView=LayoutInflater.from(MainActivity.this).inflate(R.layout.dia_cuspopup_dia, null);  //设置要弹出的布局文件
                    cusPopupBtn1=(Button)popupView.findViewById(R.id.diaCusPopupSure);
                    exitButton = (Button) popupView.findViewById(R.id.exit);
                    window =new PopupWindow(popupView,LayoutParams.FILL_PARENT,LayoutParams.FILL_PARENT);
                }
                window.setAnimationStyle(android.R.style.Animation_Dialog); //设置弹出的动画效果
                /*必须调用setBackgroundDrawable， 因为popupwindow在初始时，会检测background是否为null,如果是onTouch or onKey events就不会相应，所以必须设置background*/
                /*网上也有很多人说，弹出pop之后，不响应键盘事件了，这个其实是焦点在pop里面的view去了。*/
                window.setFocusable(true);
                window.setBackgroundDrawable(new BitmapDrawable());
                window.update();
                window.showAtLocation(popbButton, Gravity.CENTER_VERTICAL, 0, 0);  //设置有button呼出，还有位置
                cusPopupBtn1.setOnClickListener(new OnClickListener() {
                    public void onClick(View v) {
                        showClickMessage("popup window的确定");
                    }
                });
                exitButton.setOnClickListener(new OnClickListener() {

                    @Override
                    public void onClick(View v) {
                        // TODO Auto-generated method stub
                        window.dismiss();
                    }
                });

            }
        });

        //在通知栏显示消息
        Button notiButton = (Button) findViewById(R.id.notification);
        notiButton.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub

                NotificationCompat.Builder builder = new NotificationCompat.Builder(MainActivity.this);
                builder.setContentTitle("有通知来了");
                builder.setTicker("XXX");
                builder.setContentText("这是内容");
                builder.setSmallIcon(R.drawable.ic_launcher);
                Intent intent2 = new Intent(MainActivity.this,IndexActivity.class);
                PendingIntent pendingIntent2 = PendingIntent.getActivity(MainActivity.this, 1, intent2, PendingIntent.FLAG_ONE_SHOT);
                builder.setContentIntent(pendingIntent2);

                NotificationManager m = (NotificationManager) (MainActivity.this).getSystemService(NOTIFICATION_SERVICE);
                //第一个参数是标志id，用来取消时定位用的
                m.notify(1001, builder.build());

            }
        });
    }




    //用于进度条，拿activity直接当rannable
    @Override
    public void run() {
        // TODO Auto-generated method stub
        int Progress= 0;
        while(Progress < MAX_READPROCESS)
        {
            try {
                Thread.sleep(100);
                Progress++;
                mReadProcessDia.incrementProgressBy(1);
            } catch (InterruptedException e) {   }
        }
        mReadProcessDia.cancel();//读取完了以后窗口自消失

    }
}