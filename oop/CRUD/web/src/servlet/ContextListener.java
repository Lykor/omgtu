package servlet;

import model.Flower;
import util.Utils;

import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@WebListener
public class ContextListener implements ServletContextListener {

    private Map<Integer, Flower> flowers;

    public DataBase base  = new DataBase();
    @Override
    public void contextInitialized(ServletContextEvent servletContextEvent){


        final ServletContext servletContext =
                servletContextEvent.getServletContext();

        flowers = new ConcurrentHashMap<>();

        servletContext.setAttribute("flowers", flowers);

        final Flower flower = base.getFlower();
        this.flowers.put(flower.getId(), flower);
        base.addFlower(flower);

    }

    @Override
    public void contextDestroyed(ServletContextEvent sce) {

        flowers = null;
    }
}
