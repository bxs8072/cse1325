#include "mainwin.h"
#include "entrydialog.h"

Mainwin::Mainwin() : store{nullptr}, display{new Gtk::Label{}}, msg{new Gtk::Label{}}, filename{"default_store.store"}
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

    // E D I T
    // Create an Edit menu and add to the menu bar
    Gtk::MenuItem *menuitem_edit = Gtk::manage(new Gtk::MenuItem("_Edit", true));
    menubar->append(*menuitem_edit);
    Gtk::Menu *editmenu = Gtk::manage(new Gtk::Menu());
    menuitem_edit->set_submenu(*editmenu);

    //           C U S T O M E R S
    // Append view all products to the view menu
    Gtk::MenuItem *menuitem_ecustomer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_ecustomer->signal_activate().connect([this] { this->on_edit_customer_click(); });
    editmenu->append(*menuitem_ecustomer);

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

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

    //     N E W   S T O R E
    // Add a new store icon
    Gtk::Image *new_store_image = Gtk::manage(new Gtk::Image{"new_file.png"});
    Gtk::ToolButton *new_store_button = Gtk::manage(new Gtk::ToolButton(*new_store_image));
    new_store_button->set_tooltip_markup("Create a new store, discarding any unsaved data");
    new_store_button->signal_clicked().connect([this] { this->on_new_store_click(true); });
    toolbar->append(*new_store_button);

    //     O P E N  S T O R E
    // Add a open store icon
    Gtk::Image *open_store_image = Gtk::manage(new Gtk::Image{"open_file.png"});
    Gtk::ToolButton *open_store_button = Gtk::manage(new Gtk::ToolButton(*open_store_image));
    open_store_button->set_tooltip_markup("Open saved store file");
    open_store_button->signal_clicked().connect([this] { this->on_open_click(); });
    toolbar->append(*open_store_button);

    //     S A V E  S T O R E
    // Add a save store icon
    Gtk::Image *save_store_image = Gtk::manage(new Gtk::Image{"save_file.png"});
    Gtk::ToolButton *save_store_button = Gtk::manage(new Gtk::ToolButton(*save_store_image));
    save_store_button->set_tooltip_markup("Open saved store file");
    save_store_button->signal_clicked().connect([this] { this->on_save_click(); });
    toolbar->append(*save_store_button);

    //     L I S T   P R O D U C T S
    // Add a icon for listing products
    Gtk::Image *list_Products_image = Gtk::manage(new Gtk::Image{"products.png"});
    Gtk::ToolButton *list_products_button = Gtk::manage(new Gtk::ToolButton(*list_Products_image));
    list_products_button->set_tooltip_markup("List products");
    list_products_button->signal_clicked().connect([this] { this->on_view_products_click(); });
    toolbar->append(*list_products_button);

    //      N E W  C U S T O M E R
    // Add a new customer icon
    Gtk::Image *new_customer_image = Gtk::manage(new Gtk::Image{"new_customer.png"});
    Gtk::ToolButton *new_customer_button = Gtk::manage(new Gtk::ToolButton(*new_customer_image));
    new_customer_button->set_tooltip_markup("Create a new customer");
    new_customer_button->signal_clicked().connect([this] { this->on_new_customer_click(); });
    toolbar->append(*new_customer_button);

    //      L I S T  C U S T O M E R S
    // Add a listing customers icon
    Gtk::Image *list_customer_image = Gtk::manage(new Gtk::Image{"customers.png"});
    Gtk::ToolButton *list_customer_button = Gtk::manage(new Gtk::ToolButton(*list_customer_image));
    list_customer_button->set_tooltip_markup("Create a new customer");
    list_customer_button->signal_clicked().connect([this] { this->on_view_customers_click(); });
    toolbar->append(*list_customer_button);

    //     P L A C E   O R D E R
    // Add a icon for placing an order
    Gtk::Image *place_order_image = Gtk::manage(new Gtk::Image{"add_order.png"});
    Gtk::ToolButton *place_order_button = Gtk::manage(new Gtk::ToolButton(*place_order_image));
    place_order_button->set_tooltip_markup("Place an order");
    place_order_button->signal_clicked().connect([this] { this->on_new_order_click(); });
    toolbar->append(*place_order_button);

    //     L I S T   O R D E R S
    // Add a icon for listing orders
    Gtk::Image *list_orders_image = Gtk::manage(new Gtk::Image{"cart.png"});
    Gtk::ToolButton *list_orders_button = Gtk::manage(new Gtk::ToolButton(*list_orders_image));
    list_orders_button->set_tooltip_markup("List an order");
    list_orders_button->signal_clicked().connect([this] { this->on_view_orders_click(); });
    toolbar->append(*list_orders_button);

    //     Q U I T
    // Add a icon for quit
    Gtk::Image *quit_image = Gtk::manage(new Gtk::Image{"quit.png"});
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(*quit_image));
    quit_button->set_tooltip_markup("Quit");
    quit_button->signal_clicked().connect([this] { this->on_quit_click(); });
    toolbar->append(*quit_button);

    // /////////////////////////// ////////////////////////////////////////////
    // M A I N   W I N D O W   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    //SCROLLED WINDOW
    Gtk::ScrolledWindow *scrolledWindow = Gtk::manage(new Gtk::ScrolledWindow);
    scrolledWindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);

    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    scrolledWindow->add(*display);
    vbox->add(*scrolledWindow);

    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

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
    set_status("");
    if (isNewStore)
    {
        EntryDialog edialog(*this, "<big>New Store</big>", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
        edialog.set_secondary_text("Enter new store name: ", true);
        if (edialog.run() == Gtk::RESPONSE_CANCEL)
            throw std::runtime_error{"CANCEL"};
        filename = edialog.get_text() + ".store";
    }
    else
    {
        filename = "default_store.store";
    }
    delete store;
    store = nullptr;
    store = new Store{filename};
    set_title("MANGA MAGIC " + store->name());
    on_view_products_click();
}

void Mainwin::on_save_click()
{
    set_status("");
    try
    {
        std::ofstream ofs{filename};
        store->save(ofs);
        set_status("Saved to " + filename);
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
    set_status("");

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

    dialog.set_filename("default_store.store");

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
    set_status("");

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
    set_status("Opened " + filename);
    set_title("MANGA MAGIC " + store->name());
    on_view_products_click();
}

void Mainwin::on_about_click()
{
    set_status("");
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
    set_status("");
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

    while (response)
    {
        std::string name = std::string(e_name.get_text());
        std::string phone = std::string(e_phone.get_text());
        std::string email = std::string(e_email.get_text());
        try
        {
            store->add_customer(*(new Customer{name, phone, email}));
            set_status("Added Customer " + name);
            break;
        }
        catch (std::exception &e)
        {
            Gtk::MessageDialog{*this, "Unable to create new customer " + name + ": " + std::string{e.what()},
                               false, Gtk::MESSAGE_WARNING}
                .run();
            break;
        }
    }
    on_view_customers_click();
}

void Mainwin::on_new_order_click()
{
    set_status("");
    int order_number;
    std::ostringstream oss;

    {
        Gtk::Dialog dialog{"Order for which customer?", *this};
        Gtk::ComboBoxText customer_selector;
        for (int i = 0; i < store->customers(); ++i)
        {
            oss.str("");
            oss << store->customer(i);
            customer_selector.append(oss.str());
        }
        customer_selector.set_active(store->customers() - 1);
        dialog.get_content_area()->add(customer_selector);

        dialog.add_button("Start Order", 1);
        dialog.add_button("Cancel", 0);
        dialog.show_all();

        int response = dialog.run();
        if (response == 0)
            return;
        order_number = store->add_order(store->customer(customer_selector.get_active_row_number()));
        set_status("Created Order " + std::to_string(order_number));
    }

    {
        Gtk::MessageDialog dialog{*this, "Add to order " + std::to_string(order_number)};

        Gtk::HBox quantityBox;
        Gtk::Label quantityLabel{"Quantity"};
        quantityBox.add(quantityLabel);

        Gtk::SpinButton quantity_button;
        quantityBox.add(quantity_button);
        quantity_button.set_range(1.0, 99.0);
        quantity_button.set_increments(1.0, 10.0);
        quantityBox.add(quantity_button);

        dialog.get_content_area()->add(quantityBox);

        Gtk::ComboBoxText productSelector;
        for (int i = 0; i < store->products(); ++i)
        {
            oss.str("");
            oss << store->product(i);
            productSelector.append(oss.str());
        }
        productSelector.set_active(store->products() - 1);
        dialog.get_content_area()->add(productSelector);

        dialog.add_button("Add To Order", 1);
        dialog.add_button("Complete Order", 0);

        while (true)
        {
            oss.str("");
            oss << store->order(order_number);
            dialog.set_secondary_text(oss.str());
            dialog.show_all();
            int response = dialog.run();
            if (response == 1)
                store->add_item(order_number, store->product(productSelector.get_active_row_number()), static_cast<int>(quantity_button.get_value()));
            else
                break;
        }
    }
    on_view_orders_click();
}

void Mainwin::on_new_tool_click()
{
    set_status("");
    Gtk::Dialog dialog{"Add Customer", *this};
    Gtk::Grid grid;

    Gtk::Label t_name{"Tool Name: "};
    Gtk::Entry e_name;
    grid.attach(t_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label t_price{"Price: "};
    Gtk::Entry e_price;
    grid.attach(t_price, 0, 1, 1, 1);
    grid.attach(e_price, 1, 1, 2, 1);

    Gtk::Label t_description{"Description: "};
    Gtk::Entry e_description;
    grid.attach(t_description, 0, 2, 1, 1);
    grid.attach(e_description, 1, 2, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Add", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();
    int response = dialog.run();

    while (response)
    {
        std::string name = std::string(e_name.get_text());
        double price = atof(e_price.get_text().c_str());
        std::string description = std::string(e_description.get_text());
        try
        {
            store->add_product(*(new Tool{name, price, description}));
            set_status("Added new tool " + name);
            break;
        }
        catch (std::exception &e)
        {
            Gtk::MessageDialog{*this, "Unable to create new tool " + name + ": " + std::string{e.what()},
                               false, Gtk::MESSAGE_WARNING}
                .run();
            break;
        }
    }
    on_view_products_click();
}

void Mainwin::on_new_plant_click()
{
    set_status("");
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

    type.append("Shade");
    type.append("Part Sun");
    type.append("Full Sun");
    type.set_active(0);

    grid.attach(exposure, 0, 4, 1, 1);
    grid.attach(type, 1, 4, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Enter", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();
    while (dialog.run())
    {
        std::string name = std::string(e_name.get_text());
        double price = atof(e_price.get_text().c_str());
        std::string description = std::string(e_description.get_text());
        std::string species = std::string(e_species.get_text());
        Exposure exposure = exposure_from_string(type.get_active_text());
        try
        {
            store->add_product(*(new Plant{name, price, description, species, exposure}));
            set_status("Added New Plant " + name);
            break;
        }
        catch (std::exception &e)
        {
            Gtk::MessageDialog{*this, "Unable to create new plant " + name + ": " + std::string{e.what()},
                               false, Gtk::MESSAGE_WARNING}
                .run();
            break;
        }
    }
    on_view_products_click();
}

void Mainwin::on_new_mulch_click()
{
    set_status("");
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

    type.append("Rubber");
    type.append("Pine");
    type.append("Cedar");
    type.append("Hardwood");
    type.set_active(0);

    grid.attach(material, 0, 4, 1, 1);
    grid.attach(type, 1, 4, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Enter", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();
    while (dialog.run())
    {
        std::string name = std::string(e_name.get_text());
        double price = atof(e_price.get_text().c_str());
        std::string description = std::string(e_description.get_text());
        int volume = std::stoi(e_volume.get_text());
        Material material = material_from_string(type.get_active_text());
        try
        {
            store->add_product(*(new Mulch{name, price, description, volume, material}));
            set_status("Added New Mulch " + name);
            break;
        }
        catch (std::exception &e)
        {
            Gtk::MessageDialog{*this, "Unable to create new plant " + name + ": " + std::string{e.what()},
                               false, Gtk::MESSAGE_WARNING}
                .run();
            break;
        }
    }
    on_view_products_click();
}

void Mainwin::on_edit_customer_click()
{
    set_status("");
    int index_number;
    {
        Gtk::Dialog dialog{"Edit which customer?", *this};
        dialog.set_resizable(true);
        std::ostringstream oss;

        Gtk::ComboBoxText customer_selector;
        for (int i = 0; i < store->customers(); ++i)
        {
            oss.str("");
            oss << store->customer(i);
            customer_selector.append(oss.str());
        }

        customer_selector.set_active(store->customers() - 1);
        dialog.get_content_area()->add(customer_selector);

        dialog.add_button("Edit", 1);
        dialog.add_button("Cancel", 0);
        dialog.show_all();

        int response = dialog.run();
        index_number = customer_selector.get_active_row_number();

        if (response == 0)
            return;
    }

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

        while (response)
        {
            std::string name = std::string(e_name.get_text());
            std::string phone = std::string(e_phone.get_text());
            std::string email = std::string(e_email.get_text());
            try
            {
                store->edit_customer(index_number, name, phone, email);
                set_status("Edited Customer " + name);
                break;
            }
            catch (std::exception &e)
            {
                Gtk::MessageDialog{*this, "Unable to create new customer " + name + ": " + std::string{e.what()},
                                   false, Gtk::MESSAGE_WARNING}
                    .run();
                break;
            }
        }
    }
    on_view_customers_click();
}

void Mainwin::on_view_products_click()
{
    set_status("");
    std::string s = "Current Products\n----------------\n\n";
    for (int i = 0; i < store->products(); ++i)
    {
        std::ostringstream oss;
        oss << store->product(i) << "\n\n";
        s += oss.str();
    }
    display->set_text(s);
    set_status("Products List loaded");
}

void Mainwin::on_view_customers_click()
{
    set_status("");
    std::string s = "Current Customers\n----------------\n\n";
    store->get_sorted_customers();
    for (int i = 0; i < store->customers(); ++i)
    {
        std::ostringstream oss;
        oss << "Customer #" << std::to_string(i + 1) << '\n'
            << store->customer(i) << "\n\n";
        s += oss.str();
    }
    display->set_text(s);
    set_status("Customers List loaded");
}

void Mainwin::on_view_orders_click()
{
    set_status("");
    std::ostringstream oss;
    std::string s = "Current Orders\n----------------\n\n";
    int i = 0;
    for (std::vector<Order *>::iterator o = store->order_list().begin();
         o != store->order_list().end(); ++o)
    {
        oss << "ORDER NUMBER#" << std::to_string(i) << '\n'
            << **o << "\n\n";
        i++;
        s += oss.str();
    }
    display->set_text(s);
    set_status("Orders List loaded");
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

void Mainwin::set_status(std::string status)
{
    msg->set_markup(status);
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
