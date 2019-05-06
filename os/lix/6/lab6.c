#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define X 0
#define Y 0
#define WIDTH 300
#define HEIGHT 300
#define WIDTH_MIN 100
#define HEIGHT_MIN 100
#define BORDER_WIDTH 5

int main(int argc, char *argv[])
{
 Display *display;  /* Указатель на структуру Display */
 int screen_number;    /* Номер экрана */
 GC gc;
 XEvent report;
 Window window;
 KeySym	keySym;
 int x = 0, y = 0;
 XWindowAttributes window_attr;
 //int button;
  
 /* Устанавливаем связь с сервером */
 if ( ( display = XOpenDisplay ( NULL ) ) == NULL ) {
  puts ("Can not connect to the X server!\n");
  exit ( 1 );
 }

 /* Получаем номер основного экрана */
 screen_number = DefaultScreen ( display );

 /* Создаем окно */
 window = XCreateSimpleWindow ( display,
     RootWindow ( display, screen_number ),
     X, Y, WIDTH, HEIGHT, BORDER_WIDTH,
     BlackPixel ( display, screen_number ),
     WhitePixel ( display, screen_number ) );

 /* Выбираем события, обрабатываемые программой */
 XSelectInput ( display, window, ExposureMask | KeyPressMask | ButtonPressMask |
		 ButtonReleaseMask);

 /* Показываем окно */
 XMapWindow ( display, window );
 char str_x[5];
 char str_y[5];
 char str_h[5];
 char str_w[5];
 char key_str[20];
 /* Цикл получения и обработки ошибок */
 while ( 1 ) {
  XNextEvent ( display, &report );
  gc = XCreateGC ( display, window, 0 , NULL );

  XGetWindowAttributes(display, window, &window_attr);

  int Height = window_attr.height;
  int Width = window_attr.width;

  sprintf(str_w, "%i", Width);
  sprintf(str_h, "%i", Height);

  XDrawString (display, window, gc, 30, 30, str_w, strlen(str_w));
  XDrawString (display, window, gc, 80, 30, str_h, strlen(str_h));
  
  switch (report.type ) {
     
    case ButtonPress:
     x = report.xbutton.x;
     y = report.xbutton.y;
    sprintf(str_x, "%i", x);
    sprintf(str_y, "%i", y);
     window = report.xbutton.window;
	 /* проверяем, какая из кнопок была нажата, */
    switch(report.xbutton.button) {
        case Button1:
        /* очищаем экран */
        XClearWindow( display, window );
        XDrawString (display, window, gc, x, y-25, "Press LBM", strlen("Press LBM"));
	    XDrawString (display, window, gc, x, y, str_x, strlen(str_x));
        XDrawString (display, window, gc, x + 25, y, str_y, strlen(str_y));
	    break;
        case Button3:
	    XClearWindow( display, window );
        XDrawString (display, window, gc, x, y-25, "Press RBM", strlen("Press RBM"));
        XDrawString (display, window, gc, x, y, str_x, strlen(str_x));
        XDrawString (display, window, gc, x + 25, y, str_y, strlen(str_y));
	    break;
	default:           
    	    break;
    }
    /*отпускание кнопки мыши*/
    case ButtonRelease:
    break;
    /*обрабатывает нажатие на клав*/
    case KeyPress :
    XClearWindow( display, window );
    memset(key_str, 0, sizeof(key_str));
    XLookupString(&report.xkey, key_str, sizeof(key_str), &keySym, NULL);
    XDrawString (display, window, gc, 150, 150, key_str, strlen (key_str));
    break;
  }
  
 XFreeGC ( display, gc );
 }
return 0;
}