package com.atguigu.team.domain;
/*
* 设计师
* */
public class Designer extends Programmer{

    //Designer  :  12, id, name, age, salary, bonus

    private  double  bouns;

    public Designer(int id, String name, int age, int salary,Equipment equipment ,double bouns) {
        super(id, name, age, salary,equipment);
        this.bouns = bouns;
    }

    public double getBouns() {
        return bouns;
    }

    public void setBouns(int bouns) {
        this.bouns = bouns;
    }


    public String toString (){

        return super.toStringBase() + "\t设计师\t" + super.getStatus() + "\t" + this.bouns +"\t\t\t\t" + this.getEquipment().getDcription() ;
    }
}
