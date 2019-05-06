import javax.swing.*;
import java.awt.event.*;
import java.util.*;
import java.awt.*;
import java.applet.*;
import java.text.*;
import java.awt.event.ActionEvent; 
import java.awt.event.ActionListener; 

public class Clock extends Applet implements Runnable,ActionListener {
     
    Panel p;
    Button addh, delh, addmin,delmin,addsec,delsec;  
    private Thread timer;       
    private int lastxs, lastys, lastxm,
                lastym, lastxh, lastyh;  
    private SimpleDateFormat formatter;  
   private Font clockFaceFont;          
    private Date currentDate;            
    private Color handColor;             
    private Color numberColor;   
    private int changeS=0,changeM=0,changeH=0; //  изменения времени

    public void init() { // инициализация апплета
        int x,y;
        lastxs = lastys = lastxm = lastym = lastxh = lastyh = 0;
        formatter = new SimpleDateFormat ("EEE MMM dd hh:mm:ss yyyy", 
                                          Locale.getDefault());
 
        p = new Panel(); 
        p.setLayout(new GridLayout(10, 1, 6, 10)); 
        addh= new Button("+H"); 
        addh.addActionListener((ActionListener) this); 
        p.add(addh); 
        delh= new Button("-H"); 
        delh.addActionListener((ActionListener) this); 
        p.add(delh); 
        addmin= new Button("+M"); 
        addmin.addActionListener((ActionListener) this); 
        p.add(addmin);
        delmin= new Button("-M"); 
        delmin.addActionListener((ActionListener) this); 
        p.add(delmin);

        addsec= new Button("+S"); 
        addsec.addActionListener((ActionListener) this); 
        p.add(addsec);

        delsec= new Button("-S"); 
        delsec.addActionListener((ActionListener) this); 
        p.add(delsec);
        add(p); 
        currentDate = new Date();
        clockFaceFont = new Font("Serif", Font.PLAIN, 14);
        handColor = Color.blue;
        numberColor = Color.darkGray;
        resize(400,400);              
    }
    
    public void paint(Graphics g) { // отрисовка часов
        int xh, yh, xm, ym, xs, ys;
        int s = 0, m = 10, h = 10;
        int xcenter = 80, ycenter = 55;
        currentDate = new Date();
         formatter.applyPattern("s");
        try {
            s = Integer.parseInt(formatter.format(currentDate))+changeS;
        } catch (NumberFormatException n) {
            s = 0;
        }
        formatter.applyPattern("m");
        try {
            m = Integer.parseInt(formatter.format(currentDate))+changeM;
        } catch (NumberFormatException n) {
            m = 10;
        }    
        formatter.applyPattern("h");
        try {
            h = Integer.parseInt(formatter.format(currentDate))+changeH;
        } catch (NumberFormatException n) {
            h = 10;
        }
          xs = (int) (Math.cos(s * Math.PI / 30 - Math.PI / 2) * 45 + xcenter);
        ys = (int) (Math.sin(s * Math.PI / 30 - Math.PI / 2) * 45 + ycenter);
        xm = (int) (Math.cos(m * Math.PI / 30 - Math.PI / 2) * 40 + xcenter);
        ym = (int) (Math.sin(m * Math.PI / 30 - Math.PI / 2) * 40 + ycenter);
        xh = (int) (Math.cos((h*30 + m / 2) * Math.PI / 180 - Math.PI / 2) * 30
                   + xcenter);
        yh = (int) (Math.sin((h*30 + m / 2) * Math.PI / 180 - Math.PI / 2) * 30
                   + ycenter);
         
        g.setFont(clockFaceFont);
        g.setColor(handColor);
        g.drawArc(xcenter-50, ycenter-50, 100, 100, 0, 360);
        g.setColor(numberColor);
        g.drawString("9", xcenter-45, ycenter+3); 
        g.drawString("3", xcenter+40, ycenter+3);
        g.drawString("12", xcenter-5, ycenter-37);
        g.drawString("6", xcenter-3, ycenter+45);
       g.setColor(getBackground()); // цвет заднего фона
        if (xs != lastxs || ys != lastys) { // стерание старых линих
            g.drawLine(xcenter, ycenter, lastxs, lastys);
            
        }
        if (xm != lastxm || ym != lastym) {
            g.drawLine(xcenter, ycenter-1, lastxm, lastym);
            g.drawLine(xcenter-1, ycenter, lastxm, lastym); 
        }
        if (xh != lastxh || yh != lastyh) {
            g.drawLine(xcenter, ycenter-1, lastxh, lastyh);
            g.drawLine(xcenter-1, ycenter, lastxh, lastyh); 
        }
        g.setColor(numberColor);
        g.drawLine(xcenter, ycenter, xs, ys);
        g.setColor(handColor);
        g.drawLine(xcenter, ycenter-1, xm, ym);
        g.drawLine(xcenter-1, ycenter, xm, ym);
        g.drawLine(xcenter, ycenter-1, xh, yh);
        g.drawLine(xcenter-1, ycenter, xh, yh);
        lastxs = xs; lastys = ys;
        lastxm = xm; lastym = ym;
        lastxh = xh; lastyh = yh;
 }
    public void update(Graphics g) 
    {  paint(g);  } 

    public void start()  
{  timer = new Thread(this);
        timer.start(); }

    public void stop() 
{   timer = null;   }
  
  
    public void run() {

        Thread me = Thread.currentThread();
        while (timer == me) { // бесконечный цикл
            try {
                Thread.currentThread().sleep(1);
            } catch (InterruptedException e) {
            }
            repaint();
        }
    }

    public void actionPerformed(ActionEvent e) // обработка событий
    {     if (e.getSource() == addh) { 
             changeH++;
       } 
      if(e.getSource()==delh)
       {   changeH--;
        }

        if(e.getSource()==delmin)
        {
            changeM--;
        }

        if(e.getSource()==delsec)
        {
            changeS--;
        }

        
        if (e.getSource() == addmin) { 
            
            changeM++; 
            
        } 

        if (e.getSource() == addsec) { 
          
            changeS++;
        } 
    } 

}
