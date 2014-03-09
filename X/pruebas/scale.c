#include <Xm/Xm.h>
#include <Xm/Scale.h>

/* Prototype callback  */

void scale_cbk(Widget , int , 
               XmScaleCallbackStruct *);

main(int argc, char **argv)

{   Widget        top_wid, scale;
    XmString      title;
    XtAppContext  app;
    
 
    top_wid = XtVaAppInitialize(&app, "Scale_eg", NULL, 0,
        &argc, argv, NULL, NULL);
        
    title = XmStringCreateLocalized("Volume");

    scale = XtVaCreateManagedWidget("scale",
        xmScaleWidgetClass, top_wid,
        XmNtitleString,   title,
        XmNorientation,    XmHORIZONTAL,
        XmNmaximum,       11,
        XmNdecimalPoints, 0,
        XmNshowValue,     True,
        XmNwidth,         200,
        XmNheight,        100,
        NULL);
     
    XtAddCallback(scale,XmNvalueChangedCallback, scale_cbk, 
                  NULL);
 
    XtRealizeWidget(top_wid);
    XtAppMainLoop(app);
}


void scale_cbk(Widget widget, int data, 
               XmScaleCallbackStruct *scale_struct)

{    if (scale_struct->value < 4)
       printf("Volume too quiet (%d)\n");
    else if (scale_struct->value < 7)
       printf("Volume Ok (%d)\n"); 
    
     else
        if (scale_struct->value < 10)
       printf("Volume too loud (%d)\n");
      else /* Volume == 11 */
       printf("Volume VERY Loud (%d)\n");       
}

