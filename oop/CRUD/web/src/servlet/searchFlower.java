package servlet;

import model.Flower;
import util.Utils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;

@WebServlet("/search")
public class searchFlower extends HttpServlet {

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

        final String name = req.getParameter("name");

        Map<Integer, Flower> flowersSearch = new HashMap<>();

        Set<Map.Entry<Integer, Flower>> set;
        set = flowers.entrySet();
        for (Map.Entry<Integer, Flower> flower : set) {
            if(name.equals(flower.getValue().getName())) {
                flowersSearch.put(flower.getValue().getId(), flower.getValue());
            }
        }

        if(!flowersSearch.isEmpty()) {
            req.setAttribute("flowersSearch", flowersSearch.values());
        }
        req.setAttribute("flowers", flowers.values());
        req.getRequestDispatcher("/index.jsp").forward(req, resp);
    }}
