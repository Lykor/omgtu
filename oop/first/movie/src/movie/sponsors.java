package movie;
import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class sponsors extends HttpServlet{
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
			{
								
				request.getSession().setAttribute("sponsors","/sponsors.jsp");
								
				RequestDispatcher dispatcher = getServletContext().getRequestDispatcher("/sponsors.jsp");
				dispatcher.forward(request,response);
				
			}

}
