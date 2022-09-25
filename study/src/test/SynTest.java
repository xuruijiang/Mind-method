package test;

public class SynTest {
    public static void main(String[] args) {

        SynchronizedOne synchronizedOne = new SynchronizedOne();
        SynchronizedOne synchronizedOne1 = new SynchronizedOne();

        RunnableTest runnableTest = new RunnableTest();
        Thread thread = new Thread(runnableTest);

        thread.start();


        thread.setName("实现runnable接口 线程");

        synchronizedOne.start();
        synchronizedOne1.start();

        synchronizedOne.setName("继承 thread类 线程1");
        synchronizedOne1.setName("继承 thread类 线程2");


        Thread.currentThread().setName("主线程");

        for (int i = 0; i < 100 ; i++) {

            System.out.println(Thread.currentThread().getName() +"  "+i);
        }

    }
}
