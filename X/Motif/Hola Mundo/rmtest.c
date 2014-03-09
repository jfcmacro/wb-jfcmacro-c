#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>

typedef struct {
  Pixel fg, bg;
  int   delay;
  Boolean verbose;
} ApplicationData, *ApplicationDataPtr;

static XtResource resources[] = {
  { XtNforeground, XtCForeground, XtRPixel, sizeof(Pixel), 
    XtOffset(ApplicationDataPtr, fg), XtRString, "Black" },
  { XtNbackground, XtCBackground, XtRPixel, sizeof(Pixel),
    XtOffset(ApplicationDataPtr, bg), XtRString, "White" },
  { "delay", "Delay", XtRInt, sizeof(int),
    XtOffset(ApplicationDataPtr, delay), XtRString, "2" },
  { "verbose", "Verbose", XtRBoolean, sizeof(Boolean),
    XtOffset(ApplicationDataPtr, verbose), XtRString, "False"},
};

int
main(int argc, char *argv[])
{
  Widget toplevel;
  ApplicationData data;

  toplevel = XtInitialize(argv[0], "Rmtest", NULL, 0,
			  &argc, argv);

  XtGetApplicationResources(toplevel, &data, resources,
			    XtNumber(resources), NULL, 0);

  printf("fg = %d, bg = %d, delay = %d, verbose = %d\n",
	 data.fg, data.bg, data.delay, data.verbose);
}
