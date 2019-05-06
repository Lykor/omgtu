import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import java.io.IOException;
import java.io.PrintWriter;

public class servlet extends javax.servlet.http.HttpServlet {

    int result = 0,i=0,j=0;

    String[] question = {
            "Вопрос N1 - 2+2 =",
            "Вопрос N2 - 3*4 =",
            "Вопрос N3 - 1+0 =",
            "Вопрос N4 - 12/4 ="
    };

    int[] anwers =
            {
                    1,2,3,4,
                    1,12,3,4,
                    10,2,4,1,
                    1,3,4,12
            };


    protected void doPost(HttpServletRequest req, javax.servlet.http.HttpServletResponse resp) throws javax.servlet.ServletException, IOException {


        if(i==4)
        {
            req.setAttribute("question", result + "из 4 - ваш резултать");
            req.getRequestDispatcher("index.jsp").forward(req,resp);
        }

        req.setAttribute("question",question[i]);
        req.setAttribute("answer1",anwers[j]);
        req.setAttribute("answer2",anwers[j+1]);
        req.setAttribute("answer3",anwers[j+2]);
        req.setAttribute("answer4",anwers[j+3]);

        String name=req.getParameter("id");

        System.out.println(i+question[i]);

        if(i!=0) {
            if (name.equals("4") && i == 1) result++;
            if (name.equals("12") && i == 2) result++;
            else if (name.equals("1") && i == 3) result++;
            else if (name.equals("3") && i == 4) result++;
            System.out.println(result);
        }

        req.getRequestDispatcher("index.jsp").forward(req,resp);

       i++;
        j+=4;



    }

    protected void doGet(HttpServletRequest req, javax.servlet.http.HttpServletResponse resp) throws javax.servlet.ServletException, IOException {

     i=0;j=0;result=0;
     doPost(req,resp);

    }
}
