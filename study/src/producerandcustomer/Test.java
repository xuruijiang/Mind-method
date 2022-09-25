package producerandcustomer;

import java.lang.System;
import java.util.ArrayList;
import java.util.LinkedList;

public class Test {

    public static void main(String[] args) {
        Product product = new Product();

        ArrayList arrayList = new ArrayList();

        arrayList.add("99");

        arrayList.add(22);

        LinkedList linkedList = new LinkedList();

        linkedList.add(0,"22");

        linkedList.add("00");


        linkedList.add(12);


        linkedList.remove(1);

        linkedList.remove();



        System.out.println(linkedList);

        System.out.println(arrayList);


        Customer customer = new Customer(product);
        Producer producer = new Producer(product);


        Thread thread1 = new Thread(customer);
        Thread thread2 = new Thread(customer);
        Thread thread3 = new Thread(customer);
        Thread thread4 = new Thread(customer);
        Thread thread5 = new Thread(customer);

        Thread thread6 = new Thread(producer);
        Thread thread7 = new Thread(producer);
        Thread thread8 = new Thread(producer);

        thread1.setName("生产者 1：");
        thread1.start();

        thread2.setName("生产者 2：");
        thread2.start();

        thread3.setName("生产者 3：");
        thread3.start();

        thread4.setName("生产者 4：");
        thread4.start();

        thread5.setName("生产者 5：");
        thread5.start();

        thread6.setName("消费者 1：");
        thread6.start();
        thread7.setName("消费者 2：");
        thread7.start();
        thread8.setName("消费者 3：");
        thread8.start();

        String str = System.getProperty("user.dir");

        System.out.println(str);


    }
}
