package movie;
import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class merch extends HttpServlet{
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
			{
								
				request.getSession().setAttribute("merch","/merch.jsp");
								
				RequestDispatcher dispatcher = getServletContext().getRequestDispatcher("/merch.jsp");
				dispatcher.forward(request,response);
				
			}
	}
		
