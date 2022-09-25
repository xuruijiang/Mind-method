package com.atguigu.team.service;

import com.atguigu.team.domain.*;

import static com.atguigu.team.service.Data.*;

public class NameListService {

    private Employee[] employees;
    private Equipment equipment;



    public NameListService(int num) {
        employees = new Employee[num];

        for (int i = 0; i < EQUIPMENTS.length; i++) {

            if(EQUIPMENTS[i].length == 0){
                equipment = new PC("","");
            }else if (PC == Integer.parseInt(EMPLOYEES[i][0])){
                equipment = new PC(EQUIPMENTS[i][1],EQUIPMENTS[i][2]);
            }else if(NOTEBOOK ==Integer.parseInt(EMPLOYEES[i][0])){
                equipment = new NoteBook(EQUIPMENTS[i][1],Integer.parseInt(EQUIPMENTS[i][2]));

            }else {
                equipment = new Printer(EQUIPMENTS[i][1],EQUIPMENTS[i][2]);
            }

            if (ARCHITECT == Integer.parseInt(EMPLOYEES[i][0]) ){
                employees[i] = new Architect(Integer.parseInt(EMPLOYEES[i][1]),EMPLOYEES[i][2],
                        Integer.parseInt(EMPLOYEES[i][3]),Integer.parseInt(EMPLOYEES[i][4]),
                        equipment,Double.parseDouble(EMPLOYEES[i][5]),Integer.parseInt(EMPLOYEES[i][6]) );


            }else if (DESIGNER == Integer.parseInt(EMPLOYEES[i][0])){
                employees[i] = new Designer(Integer.parseInt(EMPLOYEES[i][1]),EMPLOYEES[i][2],
                        Integer.parseInt(EMPLOYEES[i][3]),Integer.parseInt(EMPLOYEES[i][4]),
                        equipment,Double.parseDouble(EMPLOYEES[i][5]));
            }else if(PROGRAMMER == Integer.parseInt(EMPLOYEES[i][0])){
                employees[i] = new Programmer(Integer.parseInt(EMPLOYEES[i][1]),EMPLOYEES[i][2],
                        Integer.parseInt(EMPLOYEES[i][3]),Integer.parseInt(EMPLOYEES[i][4]),
                        equipment);

            }else {
                employees[i] = new Employee(Integer.parseInt(EMPLOYEES[i][1]),EMPLOYEES[i][2],
                        Integer.parseInt(EMPLOYEES[i][3]),Integer.parseInt(EMPLOYEES[i][4]));
            }

        }


    }




    public Employee[] getAllEmploee(){

        return employees;
    }

    public void setStatuss(int num){


    }


//    public String toString(){
//
//        return employee[0] +"\n" +employee[1] +"\n" +employee[2] +"\n" +employee[3] +"\n" +employee[4]
//                +"\n" +employee[5] +"\n" +employee[6] +"\n" +employee[7] +"\n"
//                +employee[8] +"\n" +employee[9] +"\n" +employee[10] +"\n" +employee[11];
//    }

    public  Employee getEmploee(int id) throws TeamException{

        for (int i = 0; i <employees.length ; i++) {
            if (employees[i].getId() == id){
                return employees[i];
            }
        }

        throw new  TeamException("没有找该到员工");
    }


}
