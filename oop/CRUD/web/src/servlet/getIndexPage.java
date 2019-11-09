package servlet;

import com.mysql.fabric.jdbc.FabricMySQLDriver;

import model.Flower;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class getIndexPage extends HttpServlet {

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
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        req.setAttribute("flowers", flowers.values());
        req.getRequestDispatcher("/index.jsp").forward(req, resp);
    }
}
