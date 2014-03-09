#include <Xm/MainW.h>
#include <Xm/RowColumn.h>
#include <Xm/Frame.h>
#include <Xm/PushB.h>
#include <Xm/CascadeB.h>
#include <Xm/MessageB.h>

void 
help_func(Widget w, XPointer client_data, 
	       XPointer call_data)
{
  Widget keep_data;

  keep_data = (Widget) client_data;

  printf("Ha seleccionado el boton de ayuda ...\n");
  XtManageChild(keep_data);
}

void 
quitbutton_func(Widget w,
		      XPointer client_data,
		      XPointer call_data)
{
  printf("ha seleccionado el boton de salida y el programa termina\n");
  exit(0);
}

int
main(int argc, char *argv[])
{
  Widget theparent, thewindow, thebar, theframe, thebutton, themenu,
    quitbutton;
  Widget thehelp, thehelpbox, dummy;
  XtAppContext app_context;

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

  XtVaSetValues(thewindow, 
		XmNmenuBar, thebar,
		XmNworkWindow, theframe, 
		XmNshowSeparator, TRUE,
		NULL);

  thebutton = XtVaCreateManagedWidget("thebutton",
				      xmCascadeButtonWidgetClass,
				      thebar, NULL);

  themenu = XmCreatePulldownMenu(thebar, "themenu",
				 NULL, 0);

  quitbutton = XtVaCreateManagedWidget("quitbutton",
				       xmPushButtonWidgetClass,
				       themenu, NULL);

  XtVaSetValues(thebutton, XmNsubMenuId, themenu, NULL);

  XtAddCallback(quitbutton, XmNactivateCallback, 
		quitbutton_func, 0);

  thehelp = XtVaCreateManagedWidget("thehelp", 
				    xmCascadeButtonWidgetClass,
				    thebar, NULL);

  XtVaSetValues(thebar, XmNmenuHelpWidget, thehelp, NULL);

  thehelpbox = XmCreateMessageDialog(thehelp, "thehelpbox",
				     NULL, 0);

  dummy = XmMessageBoxGetChild(thehelpbox, XmDIALOG_CANCEL_BUTTON);

  XtUnmanageChild(dummy);
  
  dummy = XmMessageBoxGetChild(thehelpbox, XmDIALOG_HELP_BUTTON);
  
  XtUnmanageChild(dummy);

  XtAddCallback(thehelp, XmNactivateCallback, help_func, thehelpbox);

  XtRealizeWidget(theparent);

  XtAppMainLoop(app_context);
}
