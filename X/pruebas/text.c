#include <Xm/Xm.h>
#include <Xm/Text.h>
#include <Xm/MainW.h>
#include <Xm/CascadeB.h>

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>


/* Prototype Callback and other functions */

void  quit_call(),
      help_call(),
      read_file(Widget);




main(int argc, char *argv[])

{   Widget        top_wid, main_w, menu_bar,
                  menu, quit, help, text_wid;
    XtAppContext  app;
    Arg           args[4];

    /* initialize */
    top_wid = XtVaAppInitialize(&app, "Text",
        NULL, 0, &argc, argv, NULL, NULL);




        main_w = XtVaCreateManagedWidget("main_w",
        xmMainWindowWidgetClass, top_wid,
        /* XmNscrollingPolicy,   XmVARIABLE, */
        NULL);

    menu_bar = XmCreateMenuBar(main_w, "main_list",
        NULL, 0);
    XtManageChild(menu_bar);

     /* create quit widget + callback */

    quit = XtVaCreateManagedWidget( "Quit",
        xmCascadeButtonWidgetClass, menu_bar,
        XmNmnemonic, 'Q',
        NULL);





    XtAddCallback(quit, XmNactivateCallback,
        quit_call, NULL);

    /* Create ScrolledText -- this is work area for the
       MainWindow */

    XtSetArg(args[0], XmNrows,      30);
    XtSetArg(args[1], XmNcolumns,   80);
    XtSetArg(args[2], XmNeditable,  False);
    XtSetArg(args[3], XmNeditMode,  XmMULTI_LINE_EDIT);
    text_wid = XmCreateScrolledText(main_w, "text_wid",
                                    args, 4);
    XtManageChild(text_wid);




    /*  read file and put data in text widget */
    read_file(text_wid);

    XtRealizeWidget(top_wid);
    XtAppMainLoop(app);
}

void read_file(Widget  text_wid)

{
    static char *filename = "text.c";
    char  *text;
    struct stat statb;
    FILE *fp;

   /* check file is a regular text file and open it */




    if ( (stat(filename, &statb) == -1)
         || !(fp = fopen(filename, "r")))
    {   fprintf(stderr, "Cannot open file: %s\n", filename);
        XtFree(filename);
        return;
    }

    /* Map file text in the TextWidget */

    if (!(text = XtMalloc((unsigned)(statb.st_size+1))))
    {   fprintf(stderr, "Can't alloc enough space for %s",
                filename);
        XtFree(filename);
        fclose(fp);
        return;
    }




    if (!fread(text, sizeof(char), statb.st_size+1, fp))
        fprintf(stderr, "File read error\n");

    text[statb.st_size] = 0; /* be sure to NULL-terminate */

    /* insert file contents in TextWidget */

    XmTextSetString(text_wid, text);

    /* free memory
    */
    XtFree(text);
    XtFree(filename);
    fclose(fp);
}




void quit_call()

{   printf("Quitting program\n");
    exit(0);
}
