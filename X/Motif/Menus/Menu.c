#include <Xm/MainW.h>
#include <Xm/RowColumn.h>
#include <Xm/Frame.h>
#include <Xm/PushB.h>
#include <Xm/CascadeB.h>
#include <Xm/MessageB.h>
#include <Xm/Text.h>
#include <stdio.h>
#include <stdlib.h>

void
quitbutton_func(Widget w, XtPointer client_data, XtPointer call_data)
{
  printf("Ha seleccionado el boton de salida y el programa termina\n");
  exit(0);
} 

void
activate_func(Widget w, XtPointer client_data, XtPointer call_data)
{
  static int valor = 1;
  char *texto;
  XmTextPosition pos = XmTextGetInsertionPosition(w);
  char value[10];

  texto = XmTextGetString(w);

  fprintf(stdout, "Llego el siguiente texto %s\n", texto);
  
  sprintf(value, "\n%d:", valor++);

  XmTextInsert(w, pos, value);
  XmTextSetInsertionPosition(w, pos + strlen(value));
  XtFree(texto);
}

void
helloworld_func(Widget w, XtPointer client_data, XtPointer call_data)
{
  static int foreground = 0;
  static int background = 1000;

  printf("Hola Mundo\n");
  XtVaSetValues(w, XtNforeground, foreground++,
		XtNbackground, background++, NULL);
}

void
ayuda_func(Widget w, XtPointer client_data, XtPointer call_data)
{
  printf("Ayuda\n");
}

int
main(int argc, char *argv[])
{
  Widget theparent, thewindow, thebar, theframe, thebutton, 
    themenu, quitbutton, helloworldbutton, thehelp,
    thetext;
  XtAppContext app_context;
  XmString label;
  char hola[] ="0:";
  Arg  args[10];

  XtSetLanguageProc(NULL, NULL, NULL);
  theparent = XtVaOpenApplication(&app_context, "Xmenu", NULL, 0,
				  &argc, argv, NULL, 
				  sessionShellWidgetClass, NULL);

  thewindow = XtVaCreateManagedWidget("thewindow",
				      xmMainWindowWidgetClass,
				      theparent, NULL);
  
  thebar = XmCreateMenuBar(thewindow, "thebar", NULL, 0);
  
  XtManageChild(thebar);

  theframe = XtVaCreateManagedWidget("theframe",
				     xmFrameWidgetClass,
				     thewindow, NULL);

  label = XmStringCreateLocalized("Esto es una prueba");

  thetext = XtVaCreateManagedWidget("thetext",
				    xmTextWidgetClass,
				    theframe,
				    XmNvalue, hola,
				    NULL);

/*   thetext = XmCreateTextField(theframe, "thetext",  */
/* 			      NULL, 0); */
/*   XtManageChild(thetext); */

  XtAddCallback(thetext, XmNactivateCallback, activate_func, NULL);

  /* Esta forma esta en desuso. Se recomienda utilizar XtVaSetValues 
  XmMainWindowSetAreas(thewindow, thebar, NULL, NULL, NULL, theframe);
  */
  XtVaSetValues(thewindow, 
		XmNmenuBar, thebar,
		XmNworkWindow, theframe, 
		XmNshowSeparator, TRUE,
		NULL);

  thebutton = XtVaCreateManagedWidget("thebutton", 
				      xmCascadeButtonWidgetClass,
				      thebar,
				      NULL);

  thehelp = XtVaCreateManagedWidget("thehelp", 
				    xmCascadeButtonWidgetClass,
				    thebar,
				    NULL);

  XtAddCallback(thehelp, XmNactivateCallback, ayuda_func, 0);

  themenu = XmCreatePulldownMenu(thebar, "themenu", NULL, 0);

  helloworldbutton = XtVaCreateManagedWidget("helloworld",
					     xmPushButtonWidgetClass,
					     themenu, NULL);

  quitbutton = XtVaCreateManagedWidget("quitbutton",
				       xmPushButtonWidgetClass,
				       themenu, NULL);

  XtVaSetValues(thebutton, XmNsubMenuId, themenu, NULL);
  
  XtAddCallback(quitbutton, XmNactivateCallback, quitbutton_func, 0);
  XtAddCallback(helloworldbutton, XmNactivateCallback, helloworld_func, 0);
  XtRealizeWidget(theparent);

  XtAppMainLoop(app_context);
}
