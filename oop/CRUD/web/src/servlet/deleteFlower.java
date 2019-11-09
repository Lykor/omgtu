package servlet;

import model.Flower;
import util.Utils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@WebServlet("/delete")
public class deleteFlower extends HttpServlet {

    private Map<Integer, Flower> flowers;

    @Override
    public void init() throws ServletException {

        final Object flowers = getServletContext().getAttribute("flowers");

        if (flowers == null || !(flowers instanceof ConcurrentHashMap)) {

            throw new IllegalStateException("You're repo does not initialize!");
        } else {

            this.flowers = (ConcurrentHashMap<Integer, Flower>) flowers;
        }
    }

    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        req.setCharacterEncoding("UTF-8");

        if (Utils.idIsNumber(req)) {
            int id = Integer.valueOf(req.getParameter("id"));
            DataBase base = new DataBase();
            base.deleteFlower(flowers.get(id));
            flowers.remove(id);
        }
        req.setAttribute("flowers", flowers.values());
        req.getRequestDispatcher("index.jsp")
                .forward(req, resp);
    }
}
