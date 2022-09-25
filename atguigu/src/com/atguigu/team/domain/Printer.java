package com.atguigu.team.domain;

public class Printer implements Equipment{

    //Printer :23, name, type

    private String name;
    private String type;

    public Printer(String name, String type) {
        this.name = name;
        this.type = type;
    }

    @Override
    public String getDcription() {
        return this.name + "(" + this.type + ")";
    }


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
}
