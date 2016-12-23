#include <gtk/gtk.h>
#include <stdio.h>
#include <strings.h>

void destroyEventHandler(GtkWidget*, gpointer);
gboolean keyPressEventHandler(GtkWidget*, GdkEvent*, gpointer);
void notifyEventHandler(GObject*, GParamSpec*,gpointer);

struct InfoEvent {
  const gchar* first;
  const gchar* second;
  GtkWidget *button;
};

int main (int argc,
          char *argv[])
{
  GtkWidget *window, *button, *label;
  struct InfoEvent infoEvent = { "Juan Francisco", "Cardona McCormick", NULL };

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  
  g_object_set(G_OBJECT(window),
               "title", infoEvent.first,
               "default-height", 300,
               "default-width", 400,
               NULL);

  button = gtk_button_new();
  label = gtk_label_new(infoEvent.second);

  infoEvent.button = button;
  
  gtk_container_add(GTK_CONTAINER(button), label);
  gtk_container_add(GTK_CONTAINER(window), button);

  g_object_connect(G_OBJECT(window),
                   "signal::destroy",
                   G_CALLBACK(destroyEventHandler),
                   (gpointer) window,
                   NULL);
  g_object_connect(G_OBJECT(button),
                   "swapped_object_signal::clicked",
                   G_CALLBACK(gtk_widget_destroy),
                   (gpointer) window,
                   NULL);
  g_object_connect(G_OBJECT(window),
                   "signal::key-press-event",
                   G_CALLBACK(keyPressEventHandler),
                   (gpointer) &infoEvent,
                   NULL);
  g_signal_connect(G_OBJECT(window),
                   "notify::title",
                   G_CALLBACK(notifyEventHandler),
                   NULL);
  
  gtk_widget_show_all(window);
  
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
keyPressEventHandler(GtkWidget *window,
                     GdkEvent *event,
                     gpointer data) {

  const gchar* windowTitle = gtk_window_get_title(GTK_WINDOW(window));
  struct InfoEvent *infoEvent = (struct InfoEvent*) data;
  GtkLabel *label = GTK_LABEL(gtk_bin_get_child(GTK_BIN(infoEvent->button)));
  
  if (strcasecmp(windowTitle,infoEvent->first) == 0) { 
    gtk_window_set_title(GTK_WINDOW(window), infoEvent->second);
    gtk_label_set_text(label, infoEvent->first);
  }
  else {
    gtk_window_set_title(GTK_WINDOW(window), infoEvent->first);
    gtk_label_set_text(label, infoEvent->second);
  }

  return TRUE;
}


void
notifyEventHandler(GObject *gobject, GParamSpec *pspec, gpointer data) {
  g_message("Title has changed");
}
