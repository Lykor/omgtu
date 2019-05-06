package labsixxx;


import java.util.Objects;
import java.util.regex.Pattern;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;
import javax.servlet.ServletContext;

public class servlet extends HttpServlet { 
	
	private static final long serialVersionUID = 1L; 
    
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
		
		throws ServletException, IOException, FileNotFoundException {
		
            PrintWriter out = response.getWriter();
            
            response.setContentType("text/html");
             
            ServletContext context = getServletContext();
            
            InputStream is;
            is=context.getResourceAsStream("text.txt");
            InputStreamReader isr = new InputStreamReader(is);
                        
            BufferedReader bfread = new BufferedReader(isr); 
            
            String c="\0";
          
            char[] stringout=null;
         
            while(bfread.ready()) 
            	{
            	
            	c=c+bfread.readLine();
            	
            	}
           
            stringout=c.toCharArray();
            out.print("<pre>");
            out.print("   ");
            for(int s=0;s<stringout.length;s++)
            {
            	if(s%79==0&&s!=0) out.print("<br>");
            	if(stringout[s]=='@') {out.print("<br>");out.print("   "); continue;}
            	out.print(stringout[s]);
            	
            }
            out.print("</pre>");
            out.print("<br>");
            
            out.flush();
       
	
	
	}}
