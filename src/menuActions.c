#include "menuActions.h"

void newFile(GtkWidget* button, gpointer window){
    g_print("New...\n");
}

void openFile(GtkWidget* button, gpointer window){
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new("Choose a file", GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_OK, GTK_RESPONSE_OK, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);
    gtk_widget_show_all(dialog);
    gint resp = gtk_dialog_run(GTK_DIALOG(dialog));
    if(resp == GTK_RESPONSE_OK)
        g_print("%s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
    gtk_widget_destroy(dialog);
}

void saveFile(GtkWidget* button, gpointer window){
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new("Save file", GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_SAVE, GTK_STOCK_OK, GTK_RESPONSE_OK, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);
    gtk_widget_show_all(dialog);
    gtk_file_chooser_set_do_overwrite_confirmation (GTK_FILE_CHOOSER(dialog), TRUE);

    gint resp = gtk_dialog_run(GTK_DIALOG(dialog));
    if(resp == GTK_RESPONSE_OK)
        g_print("%s\n", gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
    gtk_widget_destroy(dialog);
    g_print("Saved...\n");
}

//edit menu
void cutMenu(GtkWidget* button, GtkTextView* textView){
    GtkClipboard* clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    GtkTextBuffer* buffer = gtk_text_view_get_buffer(textView);

    gtk_text_buffer_cut_clipboard(buffer, clipboard, TRUE);
}

void copyMenu(GtkWidget* button, GtkTextView* textView){
    GtkClipboard* clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    GtkTextBuffer* buffer = gtk_text_view_get_buffer(textView);

    gtk_text_buffer_copy_clipboard(buffer, clipboard);
}

void pasteMenu(GtkWidget* button, GtkTextView* textView){
    GtkClipboard* clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    GtkTextBuffer* buffer = gtk_text_view_get_buffer(textView);

    gtk_text_buffer_paste_clipboard(buffer, clipboard, NULL, TRUE);
}

void preferencesMenu(GtkWidget* button, gpointer window){
    g_print("Preferences...\n");
}

//execute menu
void buildMenu(GtkWidget* button, gpointer window){
    microMain();
}

void runMenu(GtkWidget* button, gpointer window){
    buildMenu(button, window);
}

void singleStepMenu(GtkWidget* button, gpointer window){
    g_print("Single Step...\n");
}

void convertMenu(GtkWidget* button, gpointer window){
    buildMenu(button, window);
}

//help menu
void instructionDialog(GtkWidget* button, gpointer window){
    GtkWidget* dialog, *label, *image, *vbox;

    dialog = gtk_dialog_new_with_buttons("Instructions", GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, NULL);
    gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
    gtk_window_set_modal(GTK_WINDOW(dialog), FALSE);

    vbox = gtk_vbox_new(0,0);

    image = gtk_image_new_from_stock(GTK_STOCK_INFO, GTK_ICON_SIZE_DIALOG);
    gtk_box_pack_start(GTK_BOX(vbox), image, 0, 0, 0);

    label = gtk_label_new("BOBS' Simulator");
    gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);

    GtkWidget* sep = gtk_separator_menu_item_new();
    gtk_box_pack_start(GTK_BOX(vbox), sep, 0, 0, 0);

    label = gtk_label_new("\nHere comes instruction set and their respective opcode.\n");
    gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
    
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox), vbox, 0, 0, 0);

    gtk_widget_show_all(dialog);
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void helpDialog(GtkWidget* button, gpointer window){
    GtkWidget* dialog, *label, *image, *vbox;

    dialog = gtk_dialog_new_with_buttons("Help", GTK_WINDOW(window), GTK_DIALOG_MODAL, NULL);
    gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);

    vbox = gtk_vbox_new(0,0);

    image = gtk_image_new_from_stock(GTK_STOCK_INFO, GTK_ICON_SIZE_DIALOG);
    gtk_box_pack_start(GTK_BOX(vbox), image, 0, 0, 0);

    label = gtk_label_new("BOBS' Simulator");
    gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);

    GtkWidget* sep = gtk_separator_menu_item_new();
    gtk_box_pack_start(GTK_BOX(vbox), sep, 0, 0, 0);

    label = gtk_label_new("\nHere comes help items for easy running of the simulator.\n");
    gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
    
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox), vbox, 0, 0, 0);

    gtk_widget_show_all(dialog);
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void aboutDialog(GtkWidget* button, gpointer window){
    GtkWidget* dialog, *label, *image, *vbox;

    dialog = gtk_dialog_new_with_buttons("About", GTK_WINDOW(window), GTK_DIALOG_MODAL, NULL);
    gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);

    vbox = gtk_vbox_new(0,0);

    image = gtk_image_new_from_stock(GTK_STOCK_INFO, GTK_ICON_SIZE_DIALOG);
    gtk_box_pack_start(GTK_BOX(vbox), image, 0, 0, 0);

    label = gtk_label_new("BOBS' Simulator");
    gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);

    GtkWidget* sep = gtk_separator_menu_item_new();
    gtk_box_pack_start(GTK_BOX(vbox), sep, 0, 0, 0);

    label = gtk_label_new("\nBOBS' Simulator is a completely GUI implemented and\nfully functioning simulator for 8085 microprocessor\nprogramming with both opcode and instruction mode\ninput, conversion of codes from one mode to another,\nattached 8255 PPI and hardware interrupts.\n");
    gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
    gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
    
    label = gtk_label_new("\nDevelopers");
    gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);

    sep = gtk_separator_menu_item_new();
    gtk_box_pack_start(GTK_BOX(vbox), sep, 0, 0, 0);
    
    label = gtk_label_new("\nPrabesh Pathak, Pramod Maharjan");
    gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
    
    label = gtk_label_new("Prasanna Koirala, Pusparaj Bhattarai\n");
    gtk_box_pack_start(GTK_BOX(vbox), label, 0, 0, 0);
    
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox), vbox, 0, 0, 0);

    gtk_widget_show_all(dialog);
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}