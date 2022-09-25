package com.atguigu.team.domain;


import com.atguigu.team.service.Status;

/*
* 程序员
* */
public class Programmer extends Employee{
    //Programmer:  11, id, name, age, salary
//    memberId : int
//    status: Status = FREE
//    equipment: Equipment

    private  int memberId;
    private Status status = Status.FREE;
    private  Equipment equipment;

    public Programmer(int id, String name, int age, int salary,   Equipment equipment) {
        super(id, name, age, salary);
        this.memberId = memberId;
        this.equipment = equipment;
    }

    public int getMemberId() {
        return memberId;
    }

    public void setMemberId(int memberId) {
        this.memberId = memberId;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }

    public Equipment getEquipment() {
        return equipment;
    }

    public void setEquipment(Equipment equipment) {
        this.equipment = equipment;
    }
    public String toString(){
 //      3      李彦宏   23       7000.0    程序员   FREE                                戴尔(NEC17寸)

        return super.toStringBase() + "\t程序员\t" + this.status  +"\t\t\t\t\t\t" +this.equipment.getDcription();
    }
}
