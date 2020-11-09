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
        void on_new_customer_click(); // Create a new customer
        void on_new_order_click(); // Create a new order
        void on_new_tool_click();      // Create a new tool product
        void on_new_plant_click();     // Create a new plant product
        void on_new_mulch_click();     // Create a new mulch product
        void on_view_products_click(); // Update the display and show all the products
        void on_view_customers_click(); // Update the display and show customers
        void on_view_orders_click();    // Update the display and show orders
        void on_about_click();          // about MANGA
        void on_quit_click();          // Exit the app
        
    private:
        int get_int(std::string prompt);
        double get_double(std::string prompt);
        std::string get_string(std::string prompt);
        std::string set_status(std::string status);
        std::string filename;
        Customer get_customer();
        Store* store;               // The currently active store
        Gtk::Label* display;        // Status message display
        Gtk::Label* msg;
};

#endif 

