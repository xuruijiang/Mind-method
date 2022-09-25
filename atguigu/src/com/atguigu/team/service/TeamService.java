package com.atguigu.team.service;

import com.atguigu.team.domain.Architect;
import com.atguigu.team.domain.Designer;
import com.atguigu.team.domain.Employee;
import com.atguigu.team.domain.Programmer;

public class TeamService {
//    - counter: int = 1
//    MAX_MEMBER: final int = 5
//    team: Programmer[] = new Programmer[MAX_MEMBER];
//- total: int = 0;

    private  int counter = 1;
    private final int MAX_MEMBER = 5;
    private Programmer team[] = new Programmer[MAX_MEMBER];
    private int total = 0;

    public TeamService( ) {



    }

    //+ getTeam(): Programmer[]
//+ addMember(e: Employee) throws TeamException: void
//+ removeMember(memberId: int) throws TeamException: void
    public Programmer[] getTeam(){
        return team ;
    }

    public void addMenber(Employee e) throws  TeamException{
//        成员已满，无法添加
//        该成员不是开发人员，无法添加
//        该员工已在本开发团队中
//        该员工已是某团队成员
//        该员正在休假，无法添加
//        团队中至多只能有一名架构师
//        团队中至多只能有两名设计师
//        团队中至多只能有三名程序员

        int programmernumber = 0;
        int designernumber = 0;
        int architectnumber = 0;

        for (int i = 0; i < total; i++) {
            if (team[i] instanceof Architect){
                architectnumber++;
            }else  if (team[i]  instanceof Designer){
                designernumber++;
            }else if (team[i] instanceof  Programmer){
                programmernumber++;
            }


        }
        for (int i = 0; i <= total; i++) {

            if (total == 5){
                throw new TeamException("成员已满，无法添加");
            }else if (e.getName().equals("马云 ")){
                throw new TeamException("该成员不是开发人员，无法添加");
            }else if (total !=0 && i !=total && e.getId() ==team[i].getId()) {
                throw new TeamException("该成员已在本开发团队中");
            }else if(e instanceof Programmer){
                if (((Programmer) e).getStatus() == Status.BUSY ){
                    throw new TeamException("该员工已是某团队成员");

                }else if (((Programmer) e).getStatus() == Status.VOCATION){
                    throw new TeamException("该员正在休假，无法添加");
                }

            } if(e instanceof Architect){

                if (architectnumber == 1){
                    throw new TeamException("团队中至多只能有一名架构师");
                }
            }else if (e instanceof Designer){
                if (designernumber == 2){
                    throw new TeamException("团队中至多只能有两名设计师");
                }

            }else if (e instanceof Programmer){
                if (programmernumber == 3){
                    throw new TeamException("团队中至多只能有三名程序员");
                }
            }

        }


        team[total] = (Programmer) e;
        team[total].setStatus(Status.BUSY);
        team[total].setMemberId(total+1);
        setTotal(getTotal()+1);
        System.out.println("添加成功");


    }

    public  void removeMember(int memberId)throws TeamException{

//        System.out.println(team[0].getMemberId());
        boolean choose =false;

        for (int i = 0; i < total; i++) {
            if(team[i].getMemberId() == memberId){
                choose = true;
                team[i].setStatus(Status.FREE);
                for (int j = i; j < total; j++) {

                    if (j == total-1){
                        team[j] = null;
                    }else {
                        team[j] = team[j + 1];
                    }
                }

            }
        }


        if (!choose){
            throw new TeamException("找不到指定memberId的员工，删除失败");
        }
        System.out.println("删除成功");
        setTotal(getTotal() -1);

    }

    public int getCounter() {
        return counter;
    }

    public void setCounter(int counter) {
        this.counter = counter;
    }

    public int getMAX_MEMBER() {
        return MAX_MEMBER;
    }

    public void setTeam(Programmer[] team) {
        this.team = team;
    }

    public int getTotal() {
        return total;
    }

    public void setTotal(int total) {
        this.total = total;
    }
//    public String toString(Programmer team){
//        if (team instanceof Architect){
//            return team.toString();
//        }else if (team instanceof Designer){
//            return team.toString();
//        }else{
//            return team.toString();
//        }
//    }

}
