package clothes_shop;
import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class contact extends HttpServlet{
	
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
			{
		request.getSession().setAttribute("contact","/contact.jsp");
		
		RequestDispatcher dispatcher = getServletContext().getRequestDispatcher("/contact.jsp");
		dispatcher.forward(request,response);
					
					
					
			}
	
	
	
}
