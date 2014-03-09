#include <Xm/Xm.h>
#include <Xm/MainW.h>
#include <Xm/RowColumn.h>
#include <Xm/Frame.h>
#include <Xm/PushB.h>
#include <Xm/CascadeB.h>
#include <Xm/MessageB.h>

void 
help_func(Widget w, XtPointer client_data, XtPointer call_data)
{
  Widget keep_data;

  keep_data = client_data;
  printf("ha seleccionado el boton de ayuda ...\n");
  XtManageChild(keep_data);
}

void quitbutton_func(Widget w, XtPointer client_data, XtPointer call_data)
{
  printf("Ha seleccionado el boton de salida y el programa termina\n");
  exit(0);
}

int
main(int argc, char *argv[])
{
  Widget theParent, thewindow, thebar, theframe, thebutton, themenu,
    quitbutton;
  Window thehelp, thehelpbox, dummy;
  XtAppContext app_context;

  theParent = XtVaAppInitialize(&app_context, "Motif ejemplo 5", NULL,
				0, &argc, argv, NULL, NULL);

  thewindow = XtVaCreateManagedWidget("theWindow", 
				      xmMainWindowWidgetClass,
				      theParent, NULL);

  thebar = XmCreateMenuBar(thewindow, "thebar",
			   NULL, 0);

  XtManageChild(thebar);

  theframe = XtVaCreateManagedWidget("theframe",
				     xmFrameWidgetClass,
				     thewindow, NULL);

  XmMainWindowSetAreas(thewindow, thebar, NULL, NULL, NULL, theframe);

  thebutton = XtVaCreateManagedWidget("thebutton", 
				     xmCascadeButtonWidgetClass,
				     thebar, NULL);

  themenu = XmCreatePulldownMenu(thebar, "themenu",
				 NULL, 0);

  quitbutton = XtVaCreateManagedWidget("quitbutton",
				       xmPushButtonWidgetClass,
				       themenu, NULL);

  XtVaSetValues(thebutton, XmNsubMenuId, themenu, NULL);

  XtAddCallback(quitbutton, XmNactivateCallback, quitbutton_func, 0);

  thehelp = XtVaCreateManagedWidget("thehelp",
				    xmCascadeButtonWidgetClass,
				    thebar, 
				    NULL);

  XtVaSetValues(thebar, XmNmenuHelpWidget, thehelp, NULL);

  thehelpbox = XmCreateMessageDialog(thehelp, "thehelpbox", NULL, 0);

  dummy = XmMessageBoxGetChild(thehelpbox, XmDIALOG_CANCEL_BUTTON);
  
  XtUnmanageChild(dummy);

  dummy = XmMessageBoxGetChild(thehelpbox, XmDIALOG_HELP_BUTTON);

  XtUnmanageChild(dummy);

  XtAddCallback(thehelp, XmNactivateCallback, help_func, thehelpbox);

  XtRealizeWidget(theParent);
  
  XtAppMainLoop(app_context);
}
