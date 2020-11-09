#include "mainwin.h"
#include "entrydialog.h"

Mainwin::Mainwin() : store{nullptr}, display{new Gtk::Label{}}
{

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(640, 480);
    set_title("Manga Magic");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //     N E W  S T O R E
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_new_store = Gtk::manage(new Gtk::MenuItem("_New store", true));
    menuitem_new_store->signal_activate().connect([this] { this->on_new_store_click(true); });
    filemenu->append(*menuitem_new_store);

    //         S A V E
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] { this->on_save_click(); });
    filemenu->append(*menuitem_save);

    //         S A V E A S
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("_Save as", true));
    menuitem_save_as->signal_activate().connect([this] { this->on_save_as_click(); });
    filemenu->append(*menuitem_save_as);

    //         OPEN
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] { this->on_open_click(); });
    filemenu->append(*menuitem_open);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] { this->on_quit_click(); });
    filemenu->append(*menuitem_quit);

    //     I N S E R T
    // Create an Insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //           C U S T O M E R
    // Append Customer to the Insert menu
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_customer->signal_activate().connect([this] { this->on_new_customer_click(); });
    insertmenu->append(*menuitem_customer);

    //           O R D E R
    // Append Order to the Insert menu
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_order->signal_activate().connect([this] { this->on_new_order_click(); });
    insertmenu->append(*menuitem_order);

    //           T O O L
    // Append Tool to the Insert menu
    Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool", true));
    menuitem_tool->signal_activate().connect([this] { this->on_new_tool_click(); });
    insertmenu->append(*menuitem_tool);

    //           P L A N T
    // Append Plant to the Insert menu
    Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant", true));
    menuitem_plant->signal_activate().connect([this] { this->on_new_plant_click(); });
    insertmenu->append(*menuitem_plant);

    //           M U L C H
    // Append Mulch to the Insert menu
    Gtk::MenuItem *menuitem_mulch = Gtk::manage(new Gtk::MenuItem("_Mulch", true));
    menuitem_mulch->signal_activate().connect([this] { this->on_new_mulch_click(); });
    insertmenu->append(*menuitem_mulch);

    //     V I E W
    // Create an View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //           P R O D U C T S
    // Append view all products to the view menu
    Gtk::MenuItem *menuitem_product = Gtk::manage(new Gtk::MenuItem("_Products", true));
    menuitem_product->signal_activate().connect([this] { this->on_view_products_click(); });
    viewmenu->append(*menuitem_product);

    //           C U S T O M E R S
    // Append view all customers to the view menu
    Gtk::MenuItem *menuitem_customers = Gtk::manage(new Gtk::MenuItem("_Customers", true));
    menuitem_customers->signal_activate().connect([this] { this->on_view_customers_click(); });
    viewmenu->append(*menuitem_customers);

    //           O R D E R S
    // Append view all orders to the view menu
    Gtk::MenuItem *menuitem_orders = Gtk::manage(new Gtk::MenuItem("_Orders", true));
    menuitem_orders->signal_activate().connect([this] { this->on_view_orders_click(); });
    viewmenu->append(*menuitem_orders);

    //     H E L P
    // Create an Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //          A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] { this->on_about_click(); });
    helpmenu->append(*menuitem_about);

    // /////////////////////////// ////////////////////////////////////////////
    // M A I N   W I N D O W   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new game
    on_new_store_click(false);
}

Mainwin::~Mainwin() {}

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_new_store_click(bool isNewStore)
{
    delete store;
    store = nullptr;

    if (isNewStore)
    {
        filename = get_string("Enter new store name: ");
    }
    else
    {
        filename = "default_store.store";
    }
    store = new Store{filename};
    on_view_products_click();
}

void Mainwin::on_save_click()
{
    try
    {
        std::ofstream ofs{filename};
        store->save(ofs);
    }
    catch (std::exception &e)
    {
        Gtk::MessageDialog{*this, "Unable to save the store: " + std::string{e.what()},
                           false, Gtk::MESSAGE_WARNING}
            .run();
    }
}

void Mainwin::on_save_as_click()
{
    Gtk::FileChooserDialog dialog("Please choose a file",
                                  Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);

    dialog.set_transient_for(*this);

    auto filter_store = Gtk::FileFilter::create();
    filter_store->set_name("Store Files");
    filter_store->add_pattern("*.store");
    dialog.add_filter(filter_store);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any Files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.store");

    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();

    if (result == 1)
    {
        try
        {
            std::ofstream ofs{dialog.get_filename()};
            store->save(ofs);
        }
        catch (const std::exception &e)
        {
            Gtk::MessageDialog(*this, "Unable to save the file").run();
        }
    }
}

void Mainwin::on_open_click()
{
    Gtk::FileChooserDialog dialog("Please choose a file",
                                  Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);

    dialog.set_transient_for(*this);

    auto filter_store = Gtk::FileFilter::create();
    filter_store->set_name("Store Files");
    filter_store->add_pattern("*.store");
    dialog.add_filter(filter_store);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any Files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.store");

    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1)
    {
        try
        {
            filename = dialog.get_filename();
            std::ifstream ifs{filename};
            delete store;
            store == nullptr;
            store = new Store{ifs};
            on_view_products_click();
        }
        catch (const std::exception &e)
        {
            Gtk::MessageDialog(*this, "Unable to open the store" + std::string(e.what())).run();
        }
    }
}

void Mainwin::on_about_click()
{
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this);
    dialog.set_program_name("MANGA");
    auto logo = Gdk::Pixbuf::create_from_file("logo.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 1.0.0");
    dialog.set_copyright("Copyright 2020-2050");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector<Glib::ustring> authors = {"Bhuwan Shrestha"};
    dialog.set_authors(authors);
    std::vector<Glib::ustring> artists = {
        "Logo by Bhuwan Shrestha, licensed under CC BY-SA 3.0",
        "Design by John Rock"};
    dialog.set_artists(artists);
    dialog.run();
}

void Mainwin::on_new_customer_click()
{
    Gtk::Dialog dialog{"Add Customer", *this};
    Gtk::Grid grid;

    Gtk::Label c_name{"Name: "};
    Gtk::Entry e_name;
    grid.attach(c_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label c_phone{"Phone: "};
    Gtk::Entry e_phone;
    grid.attach(c_phone, 0, 1, 1, 1);
    grid.attach(e_phone, 1, 1, 2, 1);

    Gtk::Label c_email{"Email: "};
    Gtk::Entry e_email;
    grid.attach(c_email, 0, 2, 1, 1);
    grid.attach(e_email, 1, 2, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Submit", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();
    int response = dialog.run();

    if (response == 1)
    {
        try
        {
            std::string name = std::string(e_name.get_text());
            std::string phone = std::string(e_phone.get_text());
            std::string email = std::string(e_email.get_text());
            store->add_customer(*(new Customer{name, phone, email}));
            on_view_customers_click();
        }
        catch (std::exception &e)
        {
        }
    }
    else
    {
        throw std::runtime_error{"CANCEL"};
    }
}

void Mainwin::on_new_order_click() {
    Customer customer = get_customer();
    int order_number = store->add_order(customer);
    Gtk::Dialog dialog {"Order for which customer?", *this};
    dialog.set_resizable(true);

    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    Gtk::Label *label_order_number = Gtk::manage(new Gtk::Label());
    
    label_order_number->set_text("For Order " + std::to_string(order_number));
    label_order_number->set_vexpand(true);
    label_order_number->set_hexpand(true);
    vbox->add(*label_order_number);

    Gtk::Label *label_customer = Gtk::manage(new Gtk::Label());

    std::ostringstream oss;
    oss << customer << "\n";

    label_customer->set_text("For Customer " + oss.str());
    label_customer->set_vexpand(true);
    label_customer->set_hexpand(true);
    vbox->add(*label_customer);

    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    msg->set_vexpand(true);
    vbox->add(*msg);
    
    Gtk::SpinButton *quantity_button = Gtk::manage(new Gtk::SpinButton);
    vbox->add(*quantity_button);
    quantity_button->set_range(0, 100);
    quantity_button->set_increments(1,1);

    Gtk::ComboBoxText *type = Gtk::manage(new Gtk::ComboBoxText{true});
    vbox->pack_start(*type);
    for (int i=0; i<store->products(); ++i)
    {   
        std::ostringstream oss;
        oss << store->product(i);
        type->append(oss.str());
    }
    type->set_active(0);

    dialog.get_content_area()->add(*vbox);
    dialog.add_button("Ok", 1);
    dialog.add_button("Add To Order", 2);
    dialog.add_button("Complete Order", 3);

    dialog.show_all();
    int response = dialog.run();
    if (response == 1 || response == 3)
    {   
        Product product = store->product(type->get_active_row_number());
        std::cout << product;
        store->add_item(order_number, product, quantity_button->get_value());
        on_view_orders_click();
    } else {
        Product product = store->product(type->get_active_row_number());
        store->add_item(order_number, product, quantity_button->get_value());
        std::string status;
        for (int i = 0; i < store->orders(); ++i)
    {
        std::ostringstream oss;
        oss << "Order #" << std::to_string(i) << "\n"
            << store->order(i) << "\n\n";
        status += oss.str();
    }
        msg->set_text(status);
  }
}

Customer Mainwin::get_customer()
{   
    Gtk::Dialog dialog {"Order for which customer?", *this};
    dialog.set_resizable(true);
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    Gtk::ComboBoxText *type = Gtk::manage(new Gtk::ComboBoxText{true});
    vbox->pack_start(*type);
    for (int i=0; i<store->customers(); ++i)
    {   
        std::ostringstream oss;
        oss << store->customer(i);
        type->append(oss.str());
    }
    type->set_active(0);
    dialog.get_content_area()->add(*vbox);
    dialog.add_button("Start Order", 1);
    dialog.add_button("Cancel", 0);
    dialog.show_all();
    int response = dialog.run();
    if (response == 1)
    {
        Customer customer = store->customer(type->get_active_row_number());
        return customer;
    }
    else
    {
        throw std::runtime_error{"CANCEL"};
    }
}

void Mainwin::on_new_tool_click()
{
    try
    {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        store->add_product(*(new Tool{name, price, description}));
        on_view_products_click();
    }
    catch (std::exception &e)
    {
    }
}

void Mainwin::on_new_plant_click()
{
    try
    {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        std::string species = get_string("Species?");
        double d = get_double("Exposure? (1) Shade (2) Part Sun (3) Sun");
        Exposure exposure = (d == 1.0) ? Exposure::SHADE : ((d == 3.0) ? Exposure::SUN : Exposure::PARTSUN);
        store->add_product(*(new Plant{name, price, description, species, exposure}));
        on_view_products_click();
    }
    catch (std::exception &e)
    {
    }
}

void Mainwin::on_new_mulch_click()
{
    try
    {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        int volume = get_int("Volume (ft³)?");
        int i = get_int("Material? (1) Rubber (2) Pine (3) Cedar (4) Hardwood");
        Material material;
        if (i == 1)
            material = Material::RUBBER;
        else if (i == 2)
            material = Material::PINE;
        else if (i == 3)
            material = Material::CEDAR;
        else
            material = Material::HARDWOOD;
        store->add_product(*(new Mulch{name, price, description, volume, material}));
        on_view_products_click();
    }
    catch (std::exception &e)
    {
    }
}

void Mainwin::on_view_products_click()
{
    std::string s = "Current Products\n----------------\n\n";
    for (int i = 0; i < store->products(); ++i)
    {
        std::ostringstream oss;
        oss << store->product(i) << "\n\n";
        s += oss.str();
    }
    display->set_text(s);
}

void Mainwin::on_view_customers_click()
{
    std::string s = "Current Customers\n----------------\n\n";
    for (int i = 0; i < store->customers(); ++i)
    {
        std::ostringstream oss;
        oss << "Customer #" << std::to_string(i + 1) << "\n"
            << store->customer(i) << "\n\n";
        s += oss.str();
    }

    display->set_text(s);
}

void Mainwin::on_view_orders_click() {
    std::string s = "Current Orders\n----------------\n\n";
    for (int i = 0; i < store->orders(); ++i)
    {
        std::ostringstream oss;
        oss << "Order #" << std::to_string(i) << "\n" << store->order(i) << "\n\n" ;
        s += oss.str();
    }

    display->set_text(s);
}

void Mainwin::on_quit_click()
{
    close();
}

std::string Mainwin::get_string(std::string prompt)
{
    EntryDialog edialog(*this, "<big>New Product</big>", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
    edialog.set_secondary_text(prompt, true);
    if (edialog.run() == Gtk::RESPONSE_CANCEL)
        throw std::runtime_error{"CANCEL"};
    return edialog.get_text();
}

std::string Mainwin::set_status(std::string status)
{
    return "";
}

double Mainwin::get_double(std::string prompt)
{
    while (true)
    {
        try
        {
            return std::stod(get_string(prompt));
        }
        catch (std::invalid_argument &e)
        {
            prompt = "Invalid value, please try again:";
        }
    }
}

int Mainwin::get_int(std::string prompt)
{
    while (true)
    {
        try
        {
            return std::stoi(get_string(prompt));
        }
        catch (std::invalid_argument &e)
        {
            prompt = "Invalid value, please try again:";
        }
    }
}
