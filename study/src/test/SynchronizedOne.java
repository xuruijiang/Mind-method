package test;

public class SynchronizedOne extends Thread{

   private static int num = 100;
   private static Object obj = new Object();
    @Override
    public void run() {


        for (int i = 0; i < 100; i++) {
            synchronized (SynchronizedOne.class){
            if (num == 0) {
                break;
            }
            System.out.println(currentThread().getName() +"  " +num);
            num--;


        }
    }

    }


}

