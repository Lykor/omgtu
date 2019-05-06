package laborsix;

import java.io.BufferedReader;

import java.io.FileNotFoundException;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;


import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class servlet extends HttpServlet {
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException, FileNotFoundException
			{
				// �������� ,� ���� ������, �������� ����� ��� ����������� 
				String s = request.getParameter("zhanr")+".txt";
				
				//�������� ����, � ���� ������, � ����� ������ ����� getServletContext
				String path=getServletContext().getRealPath("zhanr.zip");
				
				
				// ��������� ��� �����
				ZipFile zf = new ZipFile(path);
				// ��������� �������� ����� ������� �� �������� �� ������
				ZipEntry entry = zf.getEntry(s);
						
				// ��������� ��� ����� ��� ������ �� �������� �������� � �������� ������ �������
		  		PrintWriter out = response.getWriter();
		  		response.setContentType("text/html");
		  		
		  		// ������������� ��� ����������� ������, ������������� �������
		  		
		  		String c="$"; // ������ ������� �� ���������� ��� ������ ������ �� �����
		  		String[] st; // ������ � ������� ������������� ������. ����� ����� $ ����� ���� ����� ������� �������
		  		
		  		// ��������� � ������ ����� ��� ��� �����, � ������� �������� ������������ ����
		  		InputStream is = zf.getInputStream(entry);
		  		
		  		// � ������ ������ ������� ������ ������� ����� ���� ����� �� ������ ����� ���������� � �������
		  		BufferedReader br = new BufferedReader(new InputStreamReader(is, "UTF-8"));
		  		
		  		while(br.ready()) c=c+br.readLine(); // ��������� ������, ���� ���� �� ����
		  		zf.close();// ��������� �����
		  		
	            st=c.trim().split("\\$"); // ����� ������, �� ������ � ���������� � ������. \\$ - ���������,��������� ��������
	            // ���������� ����� ����� �����
		  		  				  		
	            // ���������� ��� �����
		  		for(String outa:st)
		  		{
		  			out.println(outa);
		  		}      
	     
		  			          
	            	            
	            out.flush();
			
			}

}
