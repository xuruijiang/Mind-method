package producerandcustomer;
//生产者
public class Customer implements Runnable{
    private  Product product ;

    public Customer(Product product){
        this.product =product;


    }
    @Override
    public void run() {

        boolean choose = true;
        while (choose){

                    product.addNumber();

            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        }


    }
}
