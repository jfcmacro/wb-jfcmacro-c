#include <gtk/gtk.h>
#include <stdio.h>
#include <pthread.h>

gint
CloseAppWindow(GtkWidget *widget, gpointer gdata)
{
  g_print("Quitting...\n");
  gtk_main_quit();

  return (FALSE);
}

void
button_was_clicked(GtkWidget *widget, gpointer gdata)
{
  g_print("Button was clicked\n");
}

void
button_enter(GtkWidget *widget, gpointer gdata)
{
  g_print("GtkWidget: %p gpointer: %p\n", widget, gdata);
  g_print("Bien venido dentro del boton\n");
}

void
button_leave(GtkWidget *widget, gpointer gdata)
{
  g_print("GtkWidget: %p gpointer: %p\n", widget, gdata);
  g_print("Vuelva proto a boton\n");
}

int
main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *button;
  // char holaMundo[] = "Hola Mundo";

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_signal_connect(GTK_OBJECT(window), "delete_event", 
		     GTK_SIGNAL_FUNC(CloseAppWindow), NULL);

  gtk_container_border_width(GTK_CONTAINER(window), 16);
  
  button = gtk_button_new_with_label("Presioname");

  gtk_signal_connect(GTK_OBJECT(button),
		     "clicked",
		     GTK_SIGNAL_FUNC(button_was_clicked),
		     NULL);

  gtk_signal_connect(GTK_OBJECT(button),
		     "enter",
		     GTK_SIGNAL_FUNC(button_enter),
		     NULL);

  gtk_signal_connect(GTK_OBJECT(button),
		     "leave",
		     GTK_SIGNAL_FUNC(button_leave),
		     NULL);

  gtk_signal_connect(GTK_OBJECT(button),
		     "enter",
		     GTK_SIGNAL_FUNC(button_leave),
		     NULL);

  gtk_container_add(GTK_CONTAINER(window), button);

  gtk_widget_show(button);

  gtk_widget_show(window);

  gtk_main();

  return 0;
}
