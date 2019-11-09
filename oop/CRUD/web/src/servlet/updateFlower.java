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

@WebServlet("/update")
public class updateFlower extends HttpServlet {

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

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        req.setCharacterEncoding("UTF-8");

        final String id = req.getParameter("id");
        final String name = req.getParameter("name");

        final Flower flower = flowers.get(Integer.parseInt(id));
        flower.setName(name);
        DataBase base = new DataBase();
        base.updateFlower(flower);
        req.setAttribute("flowers", flowers.values());
        req.getRequestDispatcher("index.jsp").forward(req, resp);
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        final String id = req.getParameter("id");

        if (Utils.idIsInvalid(id, flowers)) {
            resp.sendRedirect(req.getContextPath() + "/");
            return;
        }
        final Flower flower = flowers.get(Integer.parseInt(id));
        req.setAttribute("flower", flower);
        req.getRequestDispatcher("/update.jsp").forward(req, resp);
    }
}
