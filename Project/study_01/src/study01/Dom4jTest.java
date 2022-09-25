package study01;

import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;
import org.junit.Test;

import java.math.BigDecimal;
import java.util.List;

public class Dom4jTest {

    @Test
    public void test1() {

        SAXReader saxReader = new SAXReader();
        Document document = null;
        try {
            document = saxReader.read("/Users/xuruijiang/IdeaProjects/Project/study_01/xml/Books.xml");
        } catch (DocumentException e) {
            e.printStackTrace();
        }
        System.out.println(document);
    }

    /**
     * 读取Books.xml文件生成Book类
     */

    @Test
    public void test2(){

        SAXReader saxReader = new SAXReader();
        try {
            Document document = saxReader.read("/Users/xuruijiang/IdeaProjects/Project/study_01/xml/Books.xml");
            Element rootElement = document.getRootElement();
            List<Element> books = rootElement.elements("book");
            for (Element book: books){
                //asXML 把标签对象转化为标签字符串。
                //System.out.println(book.asXML());

                //Element nameElement = book.element("name");
                //System.out.println(nameElement.asXML());

//                this.name = name;
//                this.sn = sn;
//                this.author = author;
//                this.price = price;
                //String nameText = nameElement.getText();
                //System.out.println(nameText);
                String nameText = book.elementText("name");
                String snText = book.attributeValue("sn");
                String anthorText = book.elementText("author");
                String priceText = book.elementText("price");

                //System.out.println(priceText);

                System.out.println(new Book(nameText,snText,anthorText,BigDecimal.valueOf(Double.parseDouble(priceText))));
            }
        } catch (DocumentException e) {
            e.printStackTrace();
        }




    }
}
