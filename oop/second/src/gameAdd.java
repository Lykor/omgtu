

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class gameAdd
 */
@WebServlet("/gameAdd")
public class gameAdd extends HttpServlet {   
    

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
		protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		response.setContentType("text/html;charset=UTF-8"); 
		
		String line = null;
		String buff = null;
		
		File file = new File(getServletContext().getRealPath("/")+"games.txt");
				
		try(BufferedReader br = new BufferedReader(new FileReader(file))){			
			while((line=br.readLine())!=null) {
				buff = line;
			}					
		}		
		PrintWriter pw = response.getWriter();
		pw.println(buff);
		System.out.println("read from file"+buff);		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		StringBuffer sb = new StringBuffer();
		String line = null;
		BufferedReader reader = request.getReader();
		
		while((line=reader.readLine())!=null) {
			sb.append(line);			
		}			
		
		File file = new File(getServletContext().getRealPath("/")+"games.txt");
		
				
		try(BufferedWriter bw = new BufferedWriter(new FileWriter(file,true))) {
			bw.write(sb.toString()+"\n");
			bw.close();			
		}catch(IOException e) {
			e.printStackTrace();
		}	
		
		System.out.println(getServletContext().getRealPath("/")+"games.txt - write");		
		
	}

}
