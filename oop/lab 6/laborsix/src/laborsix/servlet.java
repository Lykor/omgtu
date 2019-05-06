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
				// ѕолучаем ,в виде строки, название файла дл€ отображени€ 
				String s = request.getParameter("zhanr")+".txt";
				
				//получаем путь, в виде строки, к файлу архива через getServletContext
				String path=getServletContext().getRealPath("zhanr.zip");
				
				
				// открываем зип архив
				ZipFile zf = new ZipFile(path);
				// указываем название файла который мы достанем из архива
				ZipEntry entry = zf.getEntry(s);
						
				// указываем наш вывод дл€ печати на странице браузера в качестве ответа клиенту
		  		PrintWriter out = response.getWriter();
		  		response.setContentType("text/html");
		  		
		  		// ”станавливает тип содержимого ответа, отправл€емого клиенту
		  		
		  		String c="$"; // строка которую мы используем дл€ записи текста из файла
		  		String[] st; // массив в котором структурируем строки. ѕосле знака $ будет идти новый элемент массива
		  		
		  		// указываем в потоке ввода наш зип архив, в котором выбираем определенный файл
		  		InputStream is = zf.getInputStream(entry);
		  		
		  		// в буфере чтени€ создаем объект который будет наши байты из потока ввода переводить в символы
		  		BufferedReader br = new BufferedReader(new InputStreamReader(is, "UTF-8"));
		  		
		  		while(br.ready()) c=c+br.readLine(); // считываем строки, пока файл не пуст
		  		zf.close();// закрываем архив
		  		
	            st=c.trim().split("\\$"); // делим строку, на мелкие и записываем в массив. \\$ - выражение,отделение элемента
	            // происходит после этого знака
		  		  				  		
	            // отображаем наш текст
		  		for(String outa:st)
		  		{
		  			out.println(outa);
		  		}      
	     
		  			          
	            	            
	            out.flush();
			
			}

}
