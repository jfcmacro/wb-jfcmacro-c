#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>

typedef struct threadarg {
  Display *display;
  Window  window;
  int     id;
  unsigned long theforeground, thebackground;
  int thescreen;
} threadarg_t;

int
handler(Display *thedisplay, XErrorEvent *xerrorEvent)
{
	
  switch (xerrorEvent->error_code) {
  case BadAlloc:
    fprintf(stderr, "BadAlloc \n");
    break;

  case BadPixmap:
    fprintf(stderr, "BadPixmap \n");
    break;

  case BadValue:
    fprintf(stderr, "BadValue \n");
    break;

  default:
    fprintf(stderr, "No reconozco el error %d \n", xerrorEvent->error_code);
    break;
  }
  return 0;
}

void*
control(void *args)
{
  Display *thedisplay = ((threadarg_t *)args)->display;
  Window  thewindow = ((threadarg_t *) args)->window;
  int id = ((threadarg_t *) args)->id;
  unsigned long theforeground = ((threadarg_t *) args)->theforeground;
  unsigned long thebackground = ((threadarg_t *) args)->thebackground;
  int thescreen = ((threadarg_t *) args)->thescreen;
  XEvent theevent;
  char hellow[] = "hola mundo";
  Window thebigwindow;
  XSetWindowAttributes attributes;
  GC thegc;
  unsigned long background_pixel = 0;

  attributes.background_pixmap = None;
  attributes.win_gravity = CenterGravity;
  attributes.cursor = None;
  attributes.event_mask = PointerMotionMask | KeyPressMask | 
    PropertyChangeMask | StructureNotifyMask | SubstructureNotifyMask;
  attributes.override_redirect = 0;
  
  thebigwindow = XDefaultRootWindow(thedisplay);

    /* XCreateWindow(thedisplay,  */
/* 			       XDefaultRootWindow(thedisplay), */
/* 			       0,  */
/* 			       0,  */
/* 			       XWidthOfScreen(XScreenOfDisplay(thedisplay,  */
/* 							       thescreen)), */
/* 			       XHeightOfScreen(XScreenOfDisplay(thedisplay,  */
/* 								thescreen)), */
/* 			       0, */
/* 			       0, */
/* 			       InputOnly,  */
/* 			       0, */
/* 			       /\*XDefaultVisual(thedisplay, */
/* 				 thescreen),*\/ */
/* 			       CWCursor | CWEventMask | CWWinGravity | CWOverrideRedirect, */
/* 			       &attributes); */

   fprintf(stdout, "Id del recurso: %ld\n", thebigwindow);

/*   XMapRaised(thedisplay, thebigwindow); */
			       
  thegc = XCreateGC(thedisplay, thewindow, 0, 0);
  XSetBackground(thedisplay, thegc, thebackground);
  XSetForeground(thedisplay, thegc, theforeground);
  XSelectInput(thedisplay, thewindow, (KeyPressMask | 
				       PointerMotionMask | 
				       ExposureMask | 
				       PropertyChangeMask ));
  XSelectInput(thedisplay, thebigwindow, (KeyPressMask | 
				       PointerMotionMask | 
				       ExposureMask | 
				       PropertyChangeMask ));

  while (1) {
    XNextEvent(thedisplay, &theevent);

    switch (theevent.type) {
    case Expose:
      fprintf(stdout, "Evento en %d capturado\n", id);

      if (theevent.xexpose.count == 0)
	XDrawImageString(theevent.xexpose.display,
			 theevent.xexpose.window, thegc,
			 105, 65, hellow, strlen(hellow));
      break;

    case MappingNotify:
      XRefreshKeyboardMapping((XMappingEvent *) &theevent);
      break;

    case UnmapNotify:
      fprintf(stdout, "Un ventana fue notificada que fue cerrada\n");

    case MotionNotify:
      fprintf(stdout, "El mouse se movio en: %d %ld\n", id,
	      background_pixel);
      attributes.background_pixel = background_pixel++;
      XChangeWindowAttributes(thedisplay, thewindow, 
			      CWBackPixel, &attributes);
      
      break;

    case DestroyNotify:
      fprintf(stdout, "Alguien pido terminar: \n");
    default:
      fprintf(stdout, "algo pasa en: %d\n", id);
      break;
    }
  }

  return (void*) 0;
}

int
main(int argc, char *argv[])
{
  Display *thedisplay;
  Window thewindow;
  Screen *tscreen;
  GC thegc; 
  XSizeHints thehint;
  int thescreen;
  int i;
  unsigned long theforeground, thebackground;
  threadarg_t *pThreadArg;
  pthread_t *threadListId;

  if (argc > 1) 
    threadListId = malloc(sizeof(pthread_t) * (argc - 1));

  XInitThreads();

  for (i = 1; i < argc; i++) {
    thedisplay = XOpenDisplay(argv[i]);
    if (thedisplay == NULL) {
      fprintf(stderr, "No se pudo abrir la ventana: %s \n", argv[i]);
    }
    else {
      XSetErrorHandler(handler);
      
      thescreen = DefaultScreen(thedisplay); // Se puede utilizar tambien XDefaultScreen
      thehint.x = 100;
      thehint.y = 150;
      thehint.width = 275;
      thehint.height = 120;
      thehint.flags = PPosition | PSize;

      thebackground = WhitePixel(thedisplay, thescreen);
      theforeground = BlackPixel(thedisplay, thescreen);

      thewindow = XCreateSimpleWindow(thedisplay, 
				      DefaultRootWindow(thedisplay),
				      thehint.x, thehint.y, 
				      thehint.width, thehint.height,
				      10, theforeground,
				      thebackground);
      
      // screen = 
      XSetStandardProperties(thedisplay, thewindow, 
			     "hola", "Helloi", None,
			     argv, argc, &thehint);
      thegc = XCreateGC(thedisplay, thewindow, 0, 0);
      XSetBackground(thedisplay, thegc, thebackground);
      XSetForeground(thedisplay, thegc, theforeground);
      fprintf(stdout, "Vamos a cerrar la ventana: %s\n", XDisplayString(thedisplay));
      fprintf(stdout, "Version: %d Revision: %d\n", XProtocolVersion(thedisplay),
	      XProtocolRevision(thedisplay));
      fprintf(stdout, "NextRequest: %ld Queue length: %d\n",
	      NextRequest(thedisplay),
	      XQLength(thedisplay));
      fprintf(stdout, "Numero de pantallas: %d\n", XScreenCount(thedisplay));
      fprintf(stdout, "Informacion del fabricante: %s\n", XServerVendor(thedisplay));
      fprintf(stdout, "Release del fabricante: %d\n", XVendorRelease(thedisplay));
      
      tscreen = XScreenOfDisplay(thedisplay, thescreen);

      fprintf(stdout, "Pantalla Ancho: %d Largo: %d \n", 
	      XWidthMMOfScreen(tscreen),
	      XHeightMMOfScreen(tscreen));
     
      XMapRaised(thedisplay, thewindow);
      pThreadArg = malloc(sizeof(threadarg_t));
      pThreadArg->display = thedisplay;
      pThreadArg->window = thewindow;
      pThreadArg->id = i;
      pThreadArg->theforeground = theforeground;
      pThreadArg->thebackground = thebackground;
      pThreadArg->thescreen = thescreen;
      pthread_create(&threadListId[i - 1], NULL, control, (void *) pThreadArg);
    }
  }
  
  for (i = 1; i < argc; i++)
    pthread_join(threadListId[i-1], NULL);
  return 0;
}
