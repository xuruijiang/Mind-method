package test;

import java.util.LinkedList;

public class Test {
    public static void main(String args[]) throws InterruptedException{
        Thread t = new Thread(new Runnable() {
            public void run() {
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                System.out.print("2");
            }
        });
        t.start();
        t.join();
        System.out.print("1");


        LinkedList list=new  LinkedList();
        list.add("a");
        list.add(2,"b");
        String s=(String)list.get(1);
        System.out.println(s);

    }



}
