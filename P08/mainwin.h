#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "store.h"
#include <fstream>

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_store_click(bool isNewStore);  // Create a new store
        void on_save_click(); 
        void on_save_as_click();
        void on_open_click(); 
        void on_new_tool_click();      // Create a new tool product
        void on_new_plant_click();     // Create a new plant product
        void on_new_mulch_click();     // Create a new mulch product
        void on_view_products_click(); // Update the display
        void on_about_click();
        void on_quit_click();          // Exit the game
        
    private:
        int get_int(std::string prompt);
        double get_double(std::string prompt);
        std::string get_string(std::string prompt);
        std::string filename;
        Store* store;               // The currently active store
        Gtk::Label* display;        // Status message display
};
#endif 

