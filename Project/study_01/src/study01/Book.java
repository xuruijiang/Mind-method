package study01;

import java.math.BigDecimal;

public class Book {

    private String name;
    private String sn;
    private String author;
    private BigDecimal price;

    public Book() {
    }

    public Book(String name, String sn, String author, BigDecimal price) {
        this.name = name;
        this.sn = sn;
        this.author = author;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSn() {
        return sn;
    }

    public void setSn(String sn) {
        this.sn = sn;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public BigDecimal getPrice() {
        return price;
    }

    public void setPrice(BigDecimal price) {
        this.price = price;
    }

    @Override
    public String toString() {
        return "Book{" +
                "name='" + name + '\'' +
                ", sn='" + sn + '\'' +
                ", author='" + author + '\'' +
                ", price=" + price +
                '}';
    }
}
