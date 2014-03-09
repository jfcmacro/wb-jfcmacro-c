#include <X11/Xos.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xproto.h>
#include <X11/keysym.h>

#define WINDOW_WIDTH      50
#define WINDOW_HEIGHT     50
#define WINDOW_BORDER     4
#define WINDOW_X          10
#define WINDOW_Y          10
#define WINDOW_MIN_WIDTH  (WINDOW_WIDTH + \
                           2 * (WINDOW_BORDER + WINDOW_X))
#define WINDOW_MIN_HEIGHT (WINDOW_HEIGHT + \
                           2 * (WINDOW_BORDER + WINDOW_Y))
#define WINDOW_DEF_WIDTH  (WINDOW_MIN_WIDTH + 100)
#define WINDOW_DEF_HEIGHT (WINDOW_MIN_HEIGHT + 100)
#define WINDOW_DEF_X       100
#define WINDOW_DEF_Y       100
#define TRUE               1
#define FALSE              0
#define BAD                -1
#define MAX_CHARS          256

#define max(val1, val2)   ((val1) > (val2) ? (val1) : (val2))

char                       *prog_name;
Display                    *thedisplay;
int                        thescreen;
XSizeHints                 thehints;
XSetWindowAttributes       attributes;
unsigned long mask       = 0L;
char                       *thegeometry;

void init_app(char **argv);
void Key_Func(XEvent *eventp);
void Button_Func(XEvent *eventp);
void MotionNotify_Func(XEvent *eventp);
void Notify_Func(XEvent *eventp);
void Focus_Func(XEvent *eventp);
void KeymapNotify_Func(XEvent *eventp);
void Expose_Func(XEvent *eventp);
void NoExpose_Func(XEvent *eventp);
void set_sizehints(XSizeHints *hintptr, int min_width, int min_height,
		   int defwidth, int defheight, int defx, int defy, 
		   char* geometry);

int
main(int argc, char **argv)
{
  int borderwidth = 2;
  Window thewindow;
  XEvent event;
  int done = FALSE;

  init_app(argv);

  thewindow = XCreateWindow(thedisplay,
			    RootWindow (thedisplay, thescreen),
			    thehints.x, thehints.y,
			    thehints.width, thehints.height,
			    borderwidth, 0, InputOutput,
			    (Visual *) CopyFromParent, mask,
			    &attributes);

  XSetStandardProperties(thedisplay, thewindow, prog_name,
			 prog_name, 0, argv, argc, &thehints);

  XMapWindow(thedisplay, thewindow);

  printf("\n Bucle principal (punto dentro de la ventana creada)");
  printf(" para salir pulse Q o q) ... \n");

  while (!done) {

    XNextEvent(thedisplay, &event);
    switch (event.type) {

    case KeyPress:
    case KeyRelease:
      Key_Func(&event);
      break;
     
    case ButtonPress:
    case ButtonRelease:
      Button_Func(&event);
      break;

    case MotionNotify:
      MotionNotify_Func(&event);
      break;

    case EnterNotify:
    case LeaveNotify:
      Notify_Func(&event);
      break;

    case FocusIn:
    case FocusOut:
      Focus_Func(&event);
      break;

    case KeymapNotify:
      KeymapNotify_Func(&event);
      break;

    case Expose:
      Expose_Func(&event);
      break;
      
    case NoExpose:
      NoExpose_Func(&event);
      break;

    default:
      break;
    }
  }

  XCloseDisplay(thedisplay);
  exit(0);
}

void init_app(char **argv)
{
  prog_name = argv[0];
  thedisplay = XOpenDisplay("");
  if (!thedisplay) {
    exit(1);
  }

  set_sizehints(&thehints, WINDOW_MIN_WIDTH, WINDOW_MIN_HEIGHT,
	       WINDOW_DEF_WIDTH, WINDOW_DEF_HEIGHT,
	       WINDOW_DEF_X, WINDOW_DEF_Y, thegeometry);

  thescreen = DefaultScreen(thedisplay);
  attributes.background_pixel = BlackPixel(thedisplay, thescreen);
  attributes.border_pixel = BlackPixel(thedisplay, thescreen);
  
  /* Mascara de seleccion de todos los suscesos */
  attributes.event_mask = KeyPressMask | KeyReleaseMask
    | ButtonPressMask | ButtonReleaseMask
    | EnterWindowMask | LeaveWindowMask
    | PointerMotionMask | PointerMotionHintMask
    | ExposureMask | ButtonMotionMask
    | KeymapStateMask | FocusChangeMask
    | PropertyChangeMask;

  mask |= (CWBackPixel | CWBorderPixel | CWEventMask);
}

void
set_sizehints(XSizeHints *hintptr, int min_width, int min_height,
	      int defwidth, int defheight, int defx, int defy, char* geometry)
{
  int result;

  /* fija las recomendaciones de tamano con xlib */

  hintptr->width = min_width;
  hintptr->min_width = min_width;
  hintptr->height = min_height;
  hintptr->min_height = min_height;
  hintptr->flags = PMinSize;
  hintptr->x = 0;
  hintptr->y = 0;
  result = BAD;

  if (geometry != NULL) {
    result = XParseGeometry(geometry, &hintptr->x, &hintptr->y,
			    (unsigned int *) &hintptr->width,
			    (unsigned int *) &hintptr->height);
    
    if ((result & WidthValue) && (result & HeightValue)) {
      hintptr->width = max(hintptr->width, hintptr->min_width);
      hintptr->height = max(hintptr->height, hintptr->min_height);
      hintptr->flags |= USSize;
    }

    if ((result & XValue) && (result & YValue)) {
      hintptr->flags += USPosition;
    }

  }

  if (!(hintptr->flags & USSize)) {

    hintptr->width = defwidth;
    hintptr->height = defheight;
    hintptr->flags |= PSize;
  }

  if (result & XNegative) {
    hintptr->x = DisplayWidth(thedisplay, DefaultScreen(thedisplay)) 
      + hintptr->x - hintptr->width;
  }

  if (result & YNegative) {
    hintptr->y = DisplayHeight(thedisplay, DefaultScreen(thedisplay))
      + hintptr->y - hintptr->height;
  }

  return;
}

void
Key_Func(XEvent *eventp) 
{
  XKeyEvent *event = (XKeyEvent *) eventp;
  KeySym keysym;
  char *keysymname;
  int n;
  char string[MAX_CHARS + 1];

  n = XLookupString(event, string, 256, &keysym, NULL);

  if (keysym == NoSymbol)
    keysymname = "Nigun simbolo";
  else
    if (!(keysymname = XKeysymToString(keysym)))
      keysymname = "(ningun nombre)";

  if (n < 0)
    n = 0;
  
  if (n > MAX_CHARS)
    n = MAX_CHARS;

  string[n] = '\0';
  printf("\n XLookupString: pulsado(s) %d caracter(es) -> \"%s \"\n", 
	 n, string);

  if ((keysym == XK_Q) || (keysym == XK_q)) {
    printf("\n Finalizacion del programa ... \n");
    exit(0);
  }

  return;
}

void 
Button_Func(XEvent* eventp)
{
  return;
}

void 
MotionNotify_Func(XEvent* eventp)
{
  return;
}

void 
Notify_Func(XEvent* eventp)
{
  return;
}

void 
Focus_Func(XEvent* eventp)
{
  return;
}

void 
KeymapNotify_Func(XEvent* eventp)
{
  return;
}

void 
Expose_Func(XEvent* eventp)
{
  return;
}

void 
NoExpose_Func(XEvent* eventp)
{
  return;
}
