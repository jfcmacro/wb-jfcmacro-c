#include <Xm/Xm.h>
#include <Xm/MainW.h>
#include <Xm/CascadeB.h>
#include <Xm/DrawingA.h>

/* Prototype callbacks */

void quit_call(void);
void clear_call(void);
void colour_call(Widget , int); 
void draw_cbk(Widget , XButtonEvent *, 
               String *, int *);

GC gc;
XGCValues gcv;
Widget draw;
String colours[] = { "Black",  "Red", "Green", "Blue", 
                     "Grey", "White"};
long int fill_pixel = 1; /* stores current colour 
                         of fill - black default */
Display *display; /* xlib id of display */
Colormap cmap;

main(int argc, char *argv[])

{   Widget top_wid, main_w, menu_bar, quit, clear, colour;
    XtAppContext app;
    XmString  quits, clears, colourss, red, green, 
              blue, black, grey, white;
    XtActionsRec actions;
    
   
    String translations = "<Btn1Motion>: draw_cbk(motion) ManagerGadgetButtonMotion()\
<Btn1Down>: draw_cbk(down) ManagerGadgetArm() \n\
<Btn1Up>: draw_cbk(up) ManagerGadgetActivate()";

    top_wid = XtVaAppInitialize(&app, "Draw", NULL, 0, 
        &argc, argv, NULL,
        XmNwidth,  500,
        XmNheight, 500,
        NULL);
   
    main_w = XtVaCreateManagedWidget("main_window",
        xmMainWindowWidgetClass,   top_wid,
        XmNwidth, 500,         
        XmNheight, 500,
        NULL);
        
    /* Create a simple MenuBar that contains three menus */
    quits = XmStringCreateLocalized("Quit");
    clears = XmStringCreateLocalized("Clear");
    colourss = XmStringCreateLocalized("Colour");
      
    menu_bar = XmVaCreateSimpleMenuBar(main_w, "main_list",
        XmVaCASCADEBUTTON, quits, 'Q',
        XmVaCASCADEBUTTON, clears, 'C',
        XmVaCASCADEBUTTON, colourss, 'o',
        NULL); 
               
    XtManageChild(menu_bar);
    

/* First menu is quit menu -- callback is quit_call() */
    
    XmVaCreateSimplePulldownMenu(menu_bar, "quit_menu", 0, 
        quit_call, XmVaPUSHBUTTON, quits, 'Q', NULL, NULL,
        NULL);
    XmStringFree(quits);
    
/* Second menu is clear menu -- callback is clear_call() */
    
    XmVaCreateSimplePulldownMenu(menu_bar, "clear_menu", 1, 
        clear_call, XmVaPUSHBUTTON, clears, 'C', NULL, NULL,
        NULL);
    XmStringFree(clears);
   
     /* create colour pull down menu */
    
    black = XmStringCreateLocalized(colours[0]);
    red = XmStringCreateLocalized(colours[1]);
    green = XmStringCreateLocalized(colours[2]);
    blue = XmStringCreateLocalized(colours[3]);
    grey = XmStringCreateLocalized(colours[4]);
    white = XmStringCreateLocalized(colours[5]);
 
    colour = XmVaCreateSimplePulldownMenu(menu_bar, 
        "edit_menu", 2, colour_call,
        XmVaRADIOBUTTON, black, 'k', NULL, NULL,
        XmVaRADIOBUTTON, red, 'R', NULL, NULL,
        XmVaRADIOBUTTON, green, 'G', NULL, NULL,
        XmVaRADIOBUTTON, blue, 'B', NULL, NULL,
        XmVaRADIOBUTTON, grey, 'e', NULL, NULL,
        XmVaRADIOBUTTON, white, 'W', NULL, NULL,
        XmNradioBehavior, True,     
        /* RowColumn resources to enforce */
        XmNradioAlwaysOne, True,    
        /* radio behavior in Menu */
        NULL);

    XmStringFree(black);
    XmStringFree(red);
    XmStringFree(green);
    XmStringFree(blue);
    XmStringFree(grey);
    XmStringFree(white);


    /* Create a DrawingArea widget. */
    /* make new actions */
    
    actions.string = "draw_cbk";
    actions.proc = draw_cbk;
    XtAppAddActions(app, &actions, 1);
    
    draw = XtVaCreateWidget("draw",
     xmDrawingAreaWidgetClass, main_w,
     XmNtranslations, XtParseTranslationTable(translations),
     XmNbackground, WhitePixelOfScreen(XtScreen(main_w)),
     NULL);




        
    cmap = DefaultColormapOfScreen(XtScreen(draw));
    display = XtDisplay(draw);
    
/* set the DrawingArea as the "work area" of main window */
    XtVaSetValues(main_w,
        XmNmenuBar,    menu_bar,
        XmNworkWindow, draw,
        NULL);


/* Create a GC. Attach GC to DrawingArea's XmNuserData. */
    gcv.foreground = BlackPixelOfScreen(XtScreen(draw));
    gc = XCreateGC(XtDisplay(draw),
        RootWindowOfScreen(XtScreen(draw)), 
        GCForeground, &gcv);

    XtManageChild(draw);
    XtRealizeWidget(top_wid);
    XtAppMainLoop(app);
}

/* CALL BACKS */

void quit_call()

{   printf("Quitting program\n");
    exit(0);
}

void clear_call() /* clear work area */

{ XClearWindow(display, XtWindow(draw)); 
}


/* called from any of the "Colour" menu items.  
   Change the colour of the label widget. 
   Note: we have to use dynamic setting with setargs()..
 */

void
colour_call(Widget w, int item_no)

  /*  w -- menu item that was selected */
  /*  item_no --- the index into the menu */

{
    int n =0;
    Arg args[1];
    
    XColor xcolour, spare; /* xlib colour struct */
        
    if (XAllocNamedColor(display, cmap, colours[item_no], 
        &xcolour, &spare) == 0)
       return;
    
    /* remember new colour */        
    fill_pixel = xcolour.pixel;     
}

/*  DrawingArea Callback.*/ 
 
void  draw_cbk(Widget w, XButtonEvent *event, 
               String *args, int *num_args)

{   static Position x, y, last_x, last_y;
    Position width, height;
    
    int line_style;
    unsigned int line_width = 1;
    int cap_style = CapRound;
    int join_style = JoinRound;    
  
    if (strcmp(args[0], "down") == 0) 
          {  /* anchor initial point (save its value) */
            x = event->x;
            y = event->y;
          } 
     else 
       if (strcmp(args[0], "motion") == 0) 
          { /* draw "ghost" box to show where it could go */
             /* undraw last box */
             
             line_style = LineOnOffDash;
            
             /* set line attributes */

             XSetLineAttributes(event->display, gc,  
              line_width, line_style, cap_style, join_style);
             
             gcv.foreground 
               = WhitePixelOfScreen(XtScreen(w));

             XSetForeground(event->display, gc, 
                            gcv.foreground);
             
             XSetFunction(event->display, gc, GXinvert);

           
            XDrawLine(event->display, event->window, gc,  
                       x, y, last_x, y);
            XDrawLine(event->display, event->window, gc, 
                       last_x, y, last_x, last_y);
            XDrawLine(event->display, event->window, gc, 
                       last_x, last_y, x, last_y);
            XDrawLine(event->display, event->window, gc,  
                       x, last_y, x, y);
       
            /* Draw New Box */
            gcv.foreground 
              = BlackPixelOfScreen(XtScreen(w));
            XSetForeground(event->display, gc, 
                   gcv.foreground);
          
            XDrawLine(event->display, event->window, gc, 
                      x, y, event->x, y);
            XDrawLine(event->display, event->window, gc, 
                      event->x, y, event->x, event->y);
            XDrawLine(event->display, event->window, gc, 
                      event->x, event->y, x, event->y);
            XDrawLine(event->display, event->window, gc,  
                      x, event->y, x, y);
          }

        else       
         if (strcmp(args[0], "up") == 0)             
          { /* draw full line */
          
             XSetFunction(event->display, gc, GXcopy);
          
             line_style = LineSolid;
             
             /* set line attributes */

             XSetLineAttributes(event->display, gc, 
        line_width, line_style, cap_style, join_style);
             
             XSetForeground(event->display, gc, fill_pixel);
          
            XDrawLine(event->display, event->window, gc, 
                      x, y, event->x, y);
            XDrawLine(event->display, event->window, gc, 
                      event->x, y, event->x, event->y);
            XDrawLine(event->display, event->window, gc, 
                      event->x, event->y, x, event->y);
            XDrawLine(event->display, event->window, gc, 
                      x, event->y, x, y);   
        
            width = event->x - x;
            height = event->y - y;
            XFillRectangle(event->display, event->window, 
                           gc, x, y, width, height);
          }
          last_x = event->x;
          last_y = event->y;
              
}

