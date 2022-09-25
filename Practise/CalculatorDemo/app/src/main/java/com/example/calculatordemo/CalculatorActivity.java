package com.example.calculatordemo;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.util.function.DoubleBinaryOperator;

import static android.widget.Toast.*;

public class CalculatorActivity extends AppCompatActivity implements View.OnClickListener {
    private final static String TAG = "CalculatorActivity";
    private TextView textView;//文本视图对象
    private String operator = "";//运算符
    private String firstNum = "";//第一个操作数
    private String secondNum = "";//第二个操作数
    private String result = "";//计算结果
    private String showText = "";//显示文本内容

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_calculator);

        //找到相应控件
        textView = findViewById(R.id.textView);
        findViewById(R.id.btn_ce).setOnClickListener(this);//归零
        findViewById(R.id.btn_c).setOnClickListener(this);//删除
        findViewById(R.id.btn_7).setOnClickListener(this);//数字 7
        findViewById(R.id.btn_8).setOnClickListener(this);//8
        findViewById(R.id.btn_9).setOnClickListener(this);//9
        findViewById(R.id.btn_4).setOnClickListener(this);//4
        findViewById(R.id.btn_5).setOnClickListener(this);//5
        findViewById(R.id.btn_6).setOnClickListener(this);//6
        findViewById(R.id.btn_1).setOnClickListener(this);//1
        findViewById(R.id.btn_2).setOnClickListener(this);//2
        findViewById(R.id.btn_3).setOnClickListener(this);//3
        findViewById(R.id.btn_0).setOnClickListener(this);//0
        findViewById(R.id.btn_dot).setOnClickListener(this);//小数点
        findViewById(R.id.btn_div).setOnClickListener(this);//除号
        findViewById(R.id.btn_mul).setOnClickListener(this);//乘号
        findViewById(R.id.btn_add).setOnClickListener(this);//加号
        findViewById(R.id.btn_sub).setOnClickListener(this);//减号
        findViewById(R.id.ibtn_sq).setOnClickListener(this);//根号
        findViewById(R.id.btn_eq).setOnClickListener(this); // “等号”按钮

    }

    private boolean verify(View v){
        //注意事项
        if(v.getId() == R.id.btn_c){  //点击删除符号时
            if(operator.equals("")&&(firstNum.equals("")||firstNum.equals("0"))){
                //第一个操作数为空及无运算符
                makeText(this,"没有可删除的数字了", LENGTH_SHORT).show();
                return false;
            }
            if(!operator.equals("") && secondNum.equals("")){
                //运算符不为空时，第二个操作数为空
                makeText(this,"没有可删除的数字了", LENGTH_SHORT).show();
                return false;
            }
        }else if(v.getId() == R.id.btn_eq){  //点击等号时
            if(operator.equals("")){//运算符为空
                makeText(this,"请输入运算符", LENGTH_SHORT).show();
                return false;
            }
            if (firstNum.equals("")||secondNum.equals("")){  //第一或者第二操作数为空
                makeText(this,"请输入数字", LENGTH_SHORT).show();
                return false;
            }
            if (operator.equals("÷") && Double.parseDouble(secondNum) == 0){  //除法运算时第二操作时为0
                makeText(this,"被除数不能为零", LENGTH_SHORT).show();
                return false;
            }
        }else if (v.getId() == R.id.btn_add || v.getId() == R.id.btn_sub
                || v.getId() == R.id.btn_mul || v.getId() == R.id.btn_div){  //加减乘除号
            if (firstNum.equals("")){  //第一操作数为空
                makeText(this,"请输入数字", LENGTH_SHORT).show();
                return false;
            }
            if (!operator.equals("")){  // 重复输入运算符
                makeText(this,"已有运算符，请输入数字", LENGTH_SHORT).show();
                return false;
            }
        }else if (v.getId() == R.id.ibtn_sq){  //根号
            if (firstNum.equals("")){  //第一操作数为空
                makeText(this,"请输入数字", LENGTH_SHORT).show();
                return false;
            }
            if (Double.parseDouble(firstNum) < 0){  //第一操作数小于0
                makeText(this,"数值不能为负数", LENGTH_SHORT).show();
                return false;
            }
        }else if (v.getId() == R.id.btn_dot){  //小数点
            if (operator.equals("") && secondNum.contains(".")){  //多次点击小数点
                makeText(this,"不能含有两个小数点", LENGTH_SHORT).show();
                return false;
            }
        }
        return true;
    }

    @Override
    public void onClick(View v) {
        if (!verify(v)){
            return;
        }
        String inputText;
        if (v.getId() == R.id.ibtn_sq){
            inputText = "√";
        }else {
            inputText = ((TextView) v).getText().toString();
        }
        Log.d(TAG,"inputText=" + inputText);
        if (v.getId() == R.id.btn_ce){  //一键清零
            clear();
        }else if(v.getId() == R.id.btn_c){  //单个删除
            if (operator.equals("")){
                if (firstNum.length() == 1){
                    firstNum = "0";
                }else if (firstNum.length() > 1){
                    firstNum = firstNum.substring(0,firstNum.length()-1);
                }
                refreshText(firstNum);
            }else {
                if (secondNum.length() == 1){
                    secondNum = "";
                }else if (secondNum.length() > 1){
                    secondNum = secondNum.substring(0,secondNum.length()-1);
                }
                refreshText(showText.substring(0,showText.length()-1));
            }
        } else if (v.getId() == R.id.btn_add || v.getId() == R.id.btn_sub
                || v.getId() == R.id.btn_mul || v.getId() == R.id.btn_div){
            operator = inputText;
            refreshText(showText + operator);
        } else if (v.getId() == R.id.btn_eq) {
            double calculate_result = calculateFour(); // 加减乘除四则运算
            refreshOperate(String.valueOf(calculate_result));
            refreshText(showText + "=" + result);
        }else if (v.getId() == R.id.ibtn_sq){
            double calculate_result = Math.sqrt(Double.parseDouble(firstNum));
            refreshOperate(String.valueOf(calculate_result));
            refreshText(showText + "√=" + result);
        }else {
            if(result.length() > 0 && operator.equals("")){
                clear();
            }
            if (operator.equals("")){
                firstNum = firstNum + inputText;
            }else {
                secondNum = secondNum + inputText;
            }
            if (showText.equals("0") && !inputText.equals(".")){
                refreshText(inputText);
            }else {
                refreshText(showText + inputText);
            }
        }
    }

    private Double calculateFour() {  //四则运算
        double calculate_result = 0;
        if (operator.equals("+")) { // 加法
            calculate_result = Double.parseDouble(firstNum) + Double.parseDouble(secondNum);

        } else if (operator.equals("-")) { // 减法
            calculate_result = Double.parseDouble(firstNum) - Double.parseDouble(secondNum);
        } else if (operator.equals("×")) { // 乘法
            calculate_result = Double.parseDouble(firstNum) * Double.parseDouble(secondNum);
        } else if (operator.equals("÷")) { // 除法
            calculate_result = Double.parseDouble(firstNum) / Double.parseDouble(secondNum);
        }
        Log.d(TAG, "calculate_result=" + calculate_result); // 把运算结果打印到日志中
        return calculate_result;
    }

    private void clear() {
        refreshOperate("");
        refreshText("");
    }

    private void refreshText(String text) {
        showText = text;
        textView.setText(showText);
    }

    private void refreshOperate(String new_result) {
        result = new_result;
        firstNum = result;
        secondNum = "";
        operator = "";
    }
}
