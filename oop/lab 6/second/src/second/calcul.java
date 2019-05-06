package second;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Objects;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;
import javax.servlet.ServletContext;

public class calcul extends HttpServlet { // ����� � ������ calcul, ������� ����������� �� ������ HttpServlet
	// �� ���� �������(����� ���������) HttpServlet, �� ���� ������������,�������� � ���� �������
	private static final long serialVersionUID = 1L; // �������� �� ���������� �����
       
    /*HttpServletRequest - ������ ������� � ���� �������. ������ ���������� � �������
     * HttpServletResponse - ��������� ������� �� ������
     * doGet - ������������ ������� GET (��������� ������)
     */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
		
		throws ServletException, IOException, FileNotFoundException {
		
            // ������� ������ PrintWriter ��� �������� ������� ������
            PrintWriter out = response.getWriter();// ���������� ������ PrintWriter, ������� ����� ���������� ��������� ����� �������.
            
            // ��������� ������ �� ������
            String n1 = request.getParameter("txt1"); //���������� �������� ��������� ������� ��� String, null - � ������ ���������� ��������� 
           
            response.setContentType("text/html");
            
            
            ServletContext context = getServletContext();


       
           
           
            InputStream is;
            is=context.getResourceAsStream("text.txt");
            
            
           InputStreamReader isr = new InputStreamReader(is);
            
            
            BufferedReader bfread = new BufferedReader(isr); 
            
            String c=null;
            String[] st;
            int n=0;
            
            while(bfread.ready()) c=c+bfread.readLine(); 
            
            st=c.trim().split("\\s+");
            
            
            for(String s:st) 
            {
            	if(Objects.equals(s,n1))n++;
            	System.out.println(s+"="+n1);
            }	
            System.out.println(n+":founded");
                      
            if(n==0)out.println("word is not founded");
            else out.println(n1+"- word founded:"+n);
            
            out.flush();
       
	
	
	}}
	
	


