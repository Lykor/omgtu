package clothes_shop;
import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class sells extends HttpServlet{
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
			{
								
				request.getSession().setAttribute("sells","/sells.jsp");
								
				RequestDispatcher dispatcher = getServletContext().getRequestDispatcher("/sells.jsp");
				dispatcher.forward(request,response);
				
			}
	}
		
