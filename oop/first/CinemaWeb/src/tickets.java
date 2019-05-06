import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class tickets extends HttpServlet{
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
			{
								
				request.getSession().setAttribute("tickets","/tickets.jsp");
								
				RequestDispatcher dispatcher = getServletContext().getRequestDispatcher("/tickets.jsp");
				dispatcher.forward(request,response);
				
			}

}
