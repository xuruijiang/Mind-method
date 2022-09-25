package com.atguigu.team.view;

import com.atguigu.team.domain.Employee;
import com.atguigu.team.domain.Programmer;
import com.atguigu.team.service.Data;
import com.atguigu.team.service.NameListService;
import com.atguigu.team.service.TeamException;
import com.atguigu.team.service.TeamService;
import org.testng.annotations.Test;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class TeamView {

   private NameListService listSvc = new NameListService(Data.EMPLOYEES.length);
   private TeamService teamSvc = new TeamService();


    public static void main(String[] args) {

//        - listSvc: NameListService = new NameListService()
//        - teamSvc: TeamService = new TeamService()
            TeamView teamView = new TeamView();
            teamView.enterMainMenu();

        //List<Class> list = new ArrayList<Class>();

        //显示员工信息



//        + enterMainMenu(): void
//        - listAllEmployees(): void
//        - getTeam():void
//        - addMember(): void
//        - deleteMember(): void
//        + main(args: String[]) : void


    }
    public void enterMainMenu(){
        boolean chooese = true;
        char key = '0';

        do {
            if (key != 1) {
                listAllEmployees();
            }
            System.out.print("1-团队列表  2-添加团队成员  3-删除团队成员 4-退出   请选择(1-4)：");
            key = TSUtility.readMenuSelection();

            switch (key){
                case '1': this.getTeam();
                break;
                case '2':this.addMenber();
                break;
                case '3':this.deleteMember();
                break;
                case '4':
                    System.out.println("确认是否退出(Y/N)");
                    key = TSUtility.readConfirmSelection();
                    if (key == 'y' || key == 'Y'){
                        chooese = false;
                    }

            }
        }while (chooese);



    }
    private  void listAllEmployees(){
        Employee[] teams = listSvc.getAllEmploee();

        if (teams == null ){
            System.out.println("没有员工信息");
        }else {
            System.out.println("----------------------------------开发团队调度软件--------------------------------");
            //ID     姓名      年龄    工资         职位      状态      奖金        股票     领用设备
            System.out.println("ID" +"\t" + "姓名"+"\t\t"+"年龄"+"\t\t"+"工资"+"\t\t"+"职位"+"\t\t"+"状态"+"\t\t"+"奖金"+"\t\t\t"+"股票"+"\t\t"+"领用设备");
            for (Employee employee :teams){
                System.out.println("" + employee);
            }
            System.out.println("--------------------------------------------------------------------------------");

        }
    }

    private void getTeam(){

      Programmer[] teams1 = teamSvc.getTeam();

      if (teams1 == null){
          System.out.println("没有员工信息");
      }else{
          System.out.println();
          System.out.println("----------------------------------团队成员列表--------------------------------");

          System.out.println("TID/ID" +"\t" + "姓名"+"\t\t"+"年龄"+"\t\t"+"工资"+"\t\t"+"职位"+"\t\t"+"状态"+"\t\t"+"奖金"+"\t\t\t"+"股票"+"\t\t"+"领用设备");

          for (int i = 0; i < teams1.length; i++) {
              if (teams1[i] ==null){
                  break;
              }
              System.out.println(teams1[i].getMemberId() + "\t" +teams1[i]);
          }
          System.out.println("--------------------------------------------------------------------------------");

          System.out.println();

          TSUtility.readReturn();
      }

    }

    private void addMenber(){
        System.out.println("-----------添加成员------------");
        System.out.println("请输入要添加的员工ID");
        int num = TSUtility.readInt();

        try {
            Employee e =  listSvc.getEmploee(num);


            teamSvc.addMenber(e);


        } catch (TeamException ex) {
            System.out.println("" + ex.getMessage());
        }
        TSUtility.readReturn();

    }

    private void deleteMember(){

        System.out.println("请输入想要删除的成员TeamId");
        int num = TSUtility.readInt();

        try {
            teamSvc.removeMember(num);
        } catch (TeamException e) {
            System.out.println("" + e.getMessage());
        }
        TSUtility.readReturn();
    }




}
//目前有一个bug  操作多次后，选择删除团队员工，会报空指针异常。

