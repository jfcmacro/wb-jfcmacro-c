#include <gtk/gtk.h>
#include <stdio.h>

void destroyEventHandler(GtkWidget*, gpointer);
gboolean deleteEventHandler(GtkWidget*, GdkEvent*, gpointer);

int main (int argc,
          char *argv[])
{
  GtkWidget *window;
  
  /* Initialize GTK+ and all of its supporting libraries. */
  gtk_init (&argc, &argv);

  /* Create a new window, give it a title and display it to the user. */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Hello World"); 
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroyEventHandler), NULL);
  g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(deleteEventHandler), NULL);

  gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);
  gtk_widget_show(window);

  /* Hand control over to the main loop. */
  gtk_main();
  return 0;
}

void
destroyEventHandler(GtkWidget *window,
                    gpointer data) {
  fprintf(stderr, "GtkWidget: %p data: %p\n",
          window, data);
  gtk_main_quit();
}

gboolean
deleteEventHandler(GtkWidget *window,
                   GdkEvent* event,
                   gpointer data) {
  fprintf(stderr, "GtkWidget: %p GkdEvent %p data: %p\n", window, event, data);
  return FALSE;
}
