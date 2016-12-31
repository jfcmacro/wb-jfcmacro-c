#include <gtk/gtk.h>

static void destroy (GtkWidget*, gpointer);
static void switch_page (GtkButton*, GtkNotebook*);

int main (int argc, 
          char *argv[])
{
  GtkWidget *window, *notebook;
  GtkWidget *topVBox, *innerHBox;
  GtkWidget *noteLabel1, *noteLabel2, *noteLabel3, *noteLabel4;
  GtkWidget *noteButton1, *noteButton2, *noteButton3, *noteButton4;
  GtkWidget *switchButton, *endButton;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Exercise 3-1");
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);
  gtk_widget_set_size_request (window, 400, 200);

  g_signal_connect (G_OBJECT (window), "destroy",
                    G_CALLBACK (destroy), NULL);

  topVBox = gtk_vbox_new(FALSE, 10);
  notebook = gtk_notebook_new();
  noteLabel1 = gtk_label_new ("Page One");
  noteLabel2 = gtk_label_new ("Page Two");
  noteLabel3 = gtk_label_new ("Page Three");
  noteLabel4 = gtk_label_new ("Page Four");
  noteButton1 = gtk_button_new_with_label ("Go to page 2 to find the answer.");
  noteButton2 = gtk_button_new_with_label ("Go to page 3 to find the answer.");
  noteButton3 = gtk_button_new_with_label ("Go to page 4 to find the answer.");
  noteButton4 = gtk_button_new_with_label ("Go to page 1 to find the answer.");
  
  /* Notice that two widgets were connected to the same callback function! */
  g_signal_connect (G_OBJECT (noteButton1), "clicked",
                    G_CALLBACK (switch_page),
                    (gpointer) notebook);
  g_signal_connect (G_OBJECT (noteButton2), "clicked",
                    G_CALLBACK (switch_page),
                    (gpointer) notebook);
  g_signal_connect (G_OBJECT (noteButton3), "clicked",
                    G_CALLBACK (switch_page),
                    (gpointer) notebook);
  g_signal_connect (G_OBJECT (noteButton4), "clicked",
                    G_CALLBACK (switch_page),
                    (gpointer) notebook);

  /* Append to pages to the notebook container. */
  gtk_notebook_append_page (GTK_NOTEBOOK (notebook), noteButton1, noteLabel1);
  gtk_notebook_append_page (GTK_NOTEBOOK (notebook), noteButton2, noteLabel2);
  gtk_notebook_append_page (GTK_NOTEBOOK (notebook), noteButton3, noteLabel3);
  gtk_notebook_append_page (GTK_NOTEBOOK (notebook), noteButton4, noteLabel4);

  gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_BOTTOM);

  gtk_box_pack_start_defaults(GTK_BOX(topVBox), notebook);

  innerHBox = gtk_hbox_new(TRUE, 10);

  switchButton = gtk_button_new_with_mnemonic("_Switch Notebook");
  gtk_button_set_relief(GTK_BUTTON(switchButton), GTK_RELIEF_NONE);
  endButton = gtk_button_new_with_mnemonic("_End");
  gtk_button_set_relief(GTK_BUTTON(endButton), GTK_RELIEF_NONE);

  g_signal_connect(G_OBJECT(switchButton), "clicked",
                   G_CALLBACK(switch_page),
                   (gpointer) notebook);
  g_signal_connect_swapped(G_OBJECT(endButton), "clicked",
                           G_CALLBACK(destroy),
                           (gpointer) NULL);
  
  gtk_box_pack_start_defaults(GTK_BOX(innerHBox), switchButton);
  gtk_box_pack_start_defaults(GTK_BOX(innerHBox), endButton);

  gtk_box_pack_start_defaults(GTK_BOX(topVBox), innerHBox);
                           
  
  gtk_container_add (GTK_CONTAINER (window), topVBox);
  gtk_widget_show_all (window);

  gtk_main ();
  return 0;
}

/* Switch between the current GtkNotebook page. */
static void 
switch_page (GtkButton *button, 
             GtkNotebook *notebook)
{
  gint page = gtk_notebook_get_current_page (notebook);
  
  switch(page) {
  case 0:
    gtk_notebook_set_current_page (notebook, 1);
    break;
  case 1:
    gtk_notebook_set_current_page (notebook, 2);
    break;
  case 2:
    gtk_notebook_set_current_page(notebook, 3);
    break;
  case 3:
    gtk_notebook_set_current_page(notebook, 0);
    break;
  }
}

static void
destroy (GtkWidget *window,
         gpointer data)
{
  gtk_main_quit ();
}
