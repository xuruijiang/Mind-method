package com.atguigu.team.domain;

public class NoteBook implements Equipment{
    //NoteBook:22, model, price

    private String model;
    private int price;

    public NoteBook(String model, int price) {
        this.model = model;
        this.price = price;
    }

    @Override
    public String getDcription() {
        return this.model + "(" +this.price + ")";
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }
}
