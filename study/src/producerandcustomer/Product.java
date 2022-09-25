package producerandcustomer;
//产品
public class Product {
    static int  number = 3 ;

    //生产

    public static synchronized void addNumber(){

        if (number<10) {
            number++;
            System.out.println(Thread.currentThread().getName() + "生产出一个：" + number);


        }





    }

    //消费

    public static synchronized void moveNumber(){
        if (number>0) {
            number--;
            System.out.println(Thread.currentThread().getName() + "购买一个：" + number);



        }
    }

}
