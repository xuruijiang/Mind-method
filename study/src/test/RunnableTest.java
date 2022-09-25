package test;

public class RunnableTest implements Runnable{

    @Override
    public void run() {
        boolean choose = true;

        int i =0;
        while (choose){


            if (i==100) {
                choose = false;
            }
            System.out.println(Thread.currentThread().getName()+"  "+ i++);


        }


    }
}
