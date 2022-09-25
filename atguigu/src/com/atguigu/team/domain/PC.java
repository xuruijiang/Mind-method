package com.atguigu.team.domain;

public class PC implements Equipment {
//    model 表示机器的型号
//    display 表示显示器名称
//    type 表示机器的类型

    private String model;
    private String display;

//    public PC() {
//    }

    public PC(String model, String display) {
        this.model = model;
        this.display = display;

    }

    @Override
    public String getDcription() {

        return this.model + "(" + this.display + ")";
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getDisplay() {
        return display;
    }

    public void setDisplay(String display) {
        this.display = display;
    }


}
