#include "mainwin.h"

std::vector<Product*> my_products;

Mainwin::Mainwin()
{
    set_default_size(400, 200);
    set_title("Manga");

    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //F I L E
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    Gtk::MenuItem *menuitem_newstore = Gtk::manage(new Gtk::MenuItem("_New_Store", true));
    menuitem_newstore->signal_activate().connect([this] { this->on_new_store_click(); });

    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] { this->on_quit_click(); });

    filemenu->append(*menuitem_newstore);
    filemenu->append(*menuitem_quit);

    //I N S E R T
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool", true));
    menuitem_tool->signal_activate().connect([this] { this->on_new_tool_click(); });

    Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plants", true));
    menuitem_plant->signal_activate().connect([this] { this->on_new_plant_click(); });

    Gtk::MenuItem *menuitem_mulch = Gtk::manage(new Gtk::MenuItem("_Mulch", true));
    menuitem_mulch->signal_activate().connect([this] { this->on_new_mulch_click(); });

    insertmenu->append(*menuitem_tool);
    insertmenu->append(*menuitem_plant);
    insertmenu->append(*menuitem_mulch);

    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);

    vbox->show_all();
}

Mainwin::~Mainwin() {}

void Mainwin::on_new_store_click() {}

void Mainwin::on_new_tool_click()
{
    Gtk::Dialog dialog{"Add Tool", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_price{"Price"};
    Gtk::Entry e_price;
    grid.attach(l_price, 0, 1, 1, 1);
    grid.attach(e_price, 1, 1, 2, 1);

    Gtk::Label l_description{"Description"};
    Gtk::Entry e_description;
    grid.attach(l_description, 0, 2, 1, 1);
    grid.attach(e_description, 1, 2, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Enter", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);

    dialog.show_all();
    int response = dialog.run();

    if (response == Gtk::RESPONSE_OK)
    {  
        my_products.push_back(new Tool(e_name.get_text(), atof(e_price.get_text().c_str()), e_description.get_text()));
        setDisplay(display);
    }
}

void Mainwin::on_new_plant_click()
{
    Gtk::Dialog dialog{"Add Plant", *this};

    Gtk::Grid grid;
    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_price{"Price"};
    Gtk::Entry e_price;
    grid.attach(l_price, 0, 1, 1, 1);
    grid.attach(e_price, 1, 1, 2, 1);

    Gtk::Label l_description{"Description"};
    Gtk::Entry e_description;
    grid.attach(l_description, 0, 2, 1, 1);
    grid.attach(e_description, 1, 2, 2, 1);

    Gtk::Label l_species{"Species"};
    Gtk::Entry e_species;
    grid.attach(l_species, 0, 3, 1, 1);
    grid.attach(e_species, 1, 3, 2, 1);

    Gtk::Label exposure{"EXPOSURE"};
    Gtk::ComboBoxText type{true};

    type.append("SHADE");
    type.append("PARTSUN");
    type.append("SUN");
    type.set_active(0);

    grid.attach(exposure, 0, 4, 1, 1);
    grid.attach(type, 1, 4, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Enter", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);

    dialog.show_all();
    int response = dialog.run();

    if (response == Gtk::RESPONSE_OK)
    {   
        
        my_products.push_back(new Plant(e_name.get_text(), atof(e_price.get_text().c_str()), e_description.get_text(),
                                 e_species.get_text(), ::to_exposure(type.get_active_text())));
        setDisplay(display);
    }
}

void Mainwin::on_new_mulch_click()
{
    Gtk::Dialog dialog{"Add Mulch", *this};
    Gtk::Grid grid;
    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_price{"Price"};
    Gtk::Entry e_price;
    grid.attach(l_price, 0, 1, 1, 1);
    grid.attach(e_price, 1, 1, 2, 1);

    Gtk::Label l_description{"Description"};
    Gtk::Entry e_description;
    grid.attach(l_description, 0, 2, 1, 1);
    grid.attach(e_description, 1, 2, 2, 1);

    Gtk::Label l_volume{"Volume (cubic ft)"};
    Gtk::Entry e_volume;
    grid.attach(l_volume, 0, 3, 1, 1);
    grid.attach(e_volume, 1, 3, 2, 1);

    Gtk::Label material{"Material"};
    Gtk::ComboBoxText type{true};

    type.append("RUBBER");
    type.append("PINE");
    type.append("CEDAR");
    type.append("HARDWOOD");
    type.set_active(0);

    grid.attach(material, 0, 4, 1, 1);
    grid.attach(type, 1, 4, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Enter", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);

    dialog.show_all();
    int response = dialog.run();

    if (response == Gtk::RESPONSE_OK)
    {
         my_products.push_back(new Mulch(e_name.get_text(), atof(e_price.get_text().c_str()), e_description.get_text(),
                                 std::stoi(e_volume.get_text()), ::to_material(type.get_active_text())));
        setDisplay(display);
    }
}

void Mainwin::on_view_product_click()
{
    setDisplay(display);
}

void Mainwin::on_quit_click() { close(); }

void setDisplay(Gtk::Label *display)
{
    std::string s;
    for (int i = my_products.size() - 1; i >= 0; --i)
    {
        std::ostringstream oss;
        oss << *(my_products.at(i)) << std::endl;
        s += oss.str();
    }
    display->set_text(s);
}

Exposure to_exposure(std::string exposure)
{
    if (exposure == "SHADE")
        return Exposure::SHADE;
    else if (exposure == "PARTSUN")
        return Exposure::PARTSUN;
    else if (exposure == "SUN")
        return Exposure::SUN;
    else
        std::cerr << "INVALID SELECTION\n"
                  << std::endl;
}

Material to_material(std::string material)
{
    if (material == "RUBBER")
        return Material::RUBBER;
    else if (material == "PINE")
        return Material::PINE;
    else if (material == "CEDAR")
        return Material::CEDAR;
    else if (material == "HARDWOOD")
        return Material::HARDWOOD;
    else
        std::cerr << "INVALID SELECTION\n"
                  << std::endl;
}
