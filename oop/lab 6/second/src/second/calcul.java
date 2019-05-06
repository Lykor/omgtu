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

public class calcul extends HttpServlet { // класс с именем calcul, которые наследуется от класса HttpServlet
	// то есть функции(кроме приватных) HttpServlet, за счет наследования,доступны в этом классев
	private static final long serialVersionUID = 1L; // добавлен по требованию среды
       
    /*HttpServletRequest - запрос клиента в виде объекта. Хранит информацию о запросе
     * HttpServletResponse - управляет ответом на запрос
     * doGet - обрабатывает запросы GET (получение данных)
     */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
		
		throws ServletException, IOException, FileNotFoundException {
		
            // создаем объект PrintWriter для отправки клиенту текста
            PrintWriter out = response.getWriter();// возвращает объект PrintWriter, который может отправлять текстовый текст клиенту.
            
            // принимаем строку со словом
            String n1 = request.getParameter("txt1"); //Возвращает значение параметра запроса как String, null - в случае отсутствия параметра 
           
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
	
	


