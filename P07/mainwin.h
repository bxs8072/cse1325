#include <gtkmm.h>
#include "store.h"
#include "product.h"
#include <vector>
#include <iostream>


Exposure to_exposure(std::string exposure);
void setDisplay(Gtk::Label* display);
Material to_material(std::string material);

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_new_store_click();
    void on_new_tool_click();
    void on_new_plant_click();
    void on_new_mulch_click();
    void on_view_product_click();
    void on_quit_click();
  private:
    Store* store;
    Gtk::Label* display;
};