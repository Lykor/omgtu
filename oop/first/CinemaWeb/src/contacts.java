import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class contacts extends HttpServlet{
	
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
			{
		request.getSession().setAttribute("contacts","/contacts.jsp");
		
		RequestDispatcher dispatcher = getServletContext().getRequestDispatcher("/contacts.jsp");
		dispatcher.forward(request,response);
					
					
					
			}
	
	
	
}
