
import javax.servlet.http.HttpServletRequest;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;


public class Utils {

    public static boolean idIsNumber(HttpServletRequest request) {
        final String id = request.getParameter("id");
        return id != null &&
                (id.length() > 0) &&
                id.matches("[+]?\\d+");
    }

    public static boolean requestIsValid(HttpServletRequest request) {
        final String name = request.getParameter("name");
        final String balance = request.getParameter("balance");
        final String price = request.getParameter("price");
        final String rating = request.getParameter("rating");


        return name != null && name.length() > 0 &&
                rating != null && rating.length() > 0 &&
                price != null && price.length() > 0 &&
                balance != null && balance.length() > 0 &&
                balance.matches("[+]?\\d+");
    }

    public static Flower createStubUser(final int id,
                                      final String name,
                                      final int balance,
                                      final int price,
                                      final int rating) {
        Flower flower = new Flower();
        flower.setId(id);
        flower.setName(name);
        flower.setBalance(balance);
        flower.setPrice(price);
        flower.setRating(rating);
        return flower;
    }

    public static boolean idIsInvalid(final String id, Map<Integer, Flower> repo) {
        return !(id != null &&
                id.matches("[+]?\\d+") &&
                repo.get(Integer.parseInt(id)) != null);
    }

    public static void WriteToFile(Flower flower) {

        File file = new File("D:\\myCAB\\portf\\lab_3_lag\\web\\web\\WEB-INF\\flower.txt");

        try(BufferedWriter bw = new BufferedWriter(new FileWriter(file,true))){
            bw.write(flower.toString()+"\n");
            bw.close();
        }catch(IOException e) {
            e.printStackTrace();
        }
    }
}
