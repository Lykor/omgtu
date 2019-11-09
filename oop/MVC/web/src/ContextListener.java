
import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@WebListener
public class ContextListener implements ServletContextListener {

    private Map<Integer, Flower> flowers;


    @Override
    public void contextInitialized(ServletContextEvent servletContextEvent){


        final ServletContext servletContext =
                servletContextEvent.getServletContext();

        flowers = new ConcurrentHashMap<>();

        servletContext.setAttribute("flowers", flowers);



        final Flower flower = Utils.createStubUser(1,"flower",3,1,4);
        Utils.WriteToFile(flower);

        this.flowers.put(flower.getId(), flower);

    }

    @Override
    public void contextDestroyed(ServletContextEvent sce) {
        flowers = null;
    }
}
