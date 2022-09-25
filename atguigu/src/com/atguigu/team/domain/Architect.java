package com.atguigu.team.domain;

/*
* 架构师
* */
public class Architect extends Designer{

    //Architect :  13, id, name, age, salary, bonus, stock

    private  int stock;

    public Architect(int id, String name, int age, int salary, Equipment equipment, double bouns) {
        super(id, name, age, salary, equipment, bouns);
    }

    public Architect(int id, String name, int age, int salary, Equipment equipment, double bouns, int stock) {
        super(id, name, age, salary,equipment, bouns);
        this.stock = stock;
    }

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }

    public String toString(){
        return this.toStringBase()+"\t架构师\t"+ this.getStatus()+"\t"+ this.getBouns() +"\t\t" + this.stock +"\t" +this.getEquipment().getDcription();
    }
}
