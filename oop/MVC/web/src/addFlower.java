




import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicInteger;

@WebServlet("/addFlower")
public class addFlower extends HttpServlet {

    private Map<Integer, Flower> flowers;

    private AtomicInteger id;

    @Override
    public void init() throws ServletException {

        final Object flowers = getServletContext().getAttribute("flowers");

        if (flowers == null || !(flowers instanceof ConcurrentHashMap)) {

            throw new IllegalStateException("You're repo does not initialize!");
        } else {

            this.flowers = (ConcurrentHashMap<Integer, Flower>) flowers;
        }

        id = new AtomicInteger(2);

    }

    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        req.setCharacterEncoding("UTF-8");

        if (Utils.requestIsValid(req)) {

            final String name = req.getParameter("name");
            final String balance = req.getParameter("balance");
            final String price = req.getParameter("price");
            final String rating = req.getParameter("rating");

            final Flower flower = new Flower();
            final int id = this.id.getAndIncrement();
            flower.setId(id);
            flower.setBalance(Integer.valueOf(balance));
            flower.setName(name);
            flower.setPrice(Integer.valueOf(price));
            flower.setRating(Integer.valueOf(rating));
            flowers.put(id, flower);
            Utils.WriteToFile(flower);
        }
        req.setAttribute("flowers", flowers.values());
        req.getRequestDispatcher("/index.jsp").forward(req, resp);
    }
}
