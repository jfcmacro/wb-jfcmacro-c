#include <Xm/Xm.h>
#include <Xm/Label.h>

int
main(int argc, char *argv[])
{
  XtAppContext app_context; // Conexion con el servidor
  Widget theParent, hellow;
  XmString  label;

  /*
  theParent = XtVaAppInitialize(&app_context, // Contexto de la aplicacion
				"holamundo", NULL, 0,
				&argc, argv,
				NULL, NULL);
  */
  theParent = XtVaOpenApplication(&app_context, "holamundo", NULL, 0, 
				  &argc, argv, NULL, sessionShellWidgetClass,
				  NULL);

/*   label = XmStringCreateLocalized("Diga hola"); */
  
/*   hellow = XtVaCreateManagedWidget("holal", */
/* 				   xmLabelWidgetClass, */
/* 				   theParent, */
/* 				   XmNlabelString, label, */
/* 				   NULL); */

  hellow = XtVaCreateManagedWidget("holal",
				   xmLabelWidgetClass,
				   theParent,
				   NULL);
  // XmStringFree(label);
  XtRealizeWidget(theParent);

  XtAppMainLoop(app_context);
}
