package vladservlet;


import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class servlet extends HttpServlet{
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException
			{
			
			
		
		
		
		double n1 = Double.parseDouble(request.getParameter("txt1")); 
		String op = request.getParameter("op");
		String e = request.getParameter("e");
		double res; 
		String out;
		
		if(op.equals("Cos")){ 
		res=Math.cos(n1); 
					
		}
		else if(op.equals("Sin")){
		res=Math.sin(n1);
			
		} else if(op.equals("Tan")){
		res=Math.tan(n1);
		
		} else{
		res=1/Math.tan(n1);
		}
		
		out ="degree - "+(roundOff((res*180/Math.PI),Integer.parseInt(e)))+"; "
				+"radian - "+roundOff(res,Integer.parseInt(e));
		
		request.setAttribute("message", out); // This will be available as ${message}
        request.getRequestDispatcher("index.jsp").forward(request, response);
		
			}
	
	
	
		public double roundOff(double x, int position)// передаются два параметра - double(вещественное число с двойной точностью) и int(целое число)
		{

		if(position==0)return x; 

		double a = x;
		double temp = Math.pow(10.0, position); 
		a *= temp; 
		a = Math.round(a);
		return (a / (float)temp); 
		}
}
