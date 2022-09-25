package producerandcustomer;
//消费者
public class Producer implements Runnable{

    private  Product product;

    public Producer(Product product){
        this.product = product;
    }
    @Override
    public void run() {


        boolean choose = true;
        while (choose){





                    product.moveNumber();


            try {
                Thread.sleep(1200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }


        }



        }





}
