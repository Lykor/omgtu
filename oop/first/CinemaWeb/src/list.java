import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class list extends HttpServlet{
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
			{
								
				request.getSession().setAttribute("list","/list.jsp");
								
				RequestDispatcher dispatcher = getServletContext().getRequestDispatcher("/list.jsp");
				dispatcher.forward(request,response);
				
			}
	}
		
