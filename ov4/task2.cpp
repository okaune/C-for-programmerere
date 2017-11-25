#include <gtkmm.h>
#include <iostream>
class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Entry firstName;
  Gtk::Entry lastName;
  Gtk::Button button;
  Gtk::Label firstNameLabel;
  Gtk::Label lastNameLabel;
  Gtk::Label output;
  bool hasFirstName = false;
  bool hasLastName = false;

  Window() {
    set_title("Øving 4");
    button.set_label("Slå sammen navn");
    button.set_sensitive(false);

    firstNameLabel.set_text("Fornavn");
    lastNameLabel.set_text("Etternavn");
    vbox.pack_start(firstNameLabel);
    vbox.pack_start(firstName);
    vbox.pack_start(lastNameLabel);
    vbox.pack_start(lastName);
    vbox.pack_start(button);
    vbox.pack_start(output);

    add(vbox);
    show_all();


    firstName.signal_changed().connect([&]() {

      if(firstName.get_text().length() > 0) {
        hasFirstName = true;
      }
      else {
        hasFirstName = false;
      }
      button.set_sensitive(hasFirstName && hasLastName);

    });

    lastName.signal_changed().connect([&]() {

      if(lastName.get_text().length() > 0) {
        hasLastName = true;
      }
      else {
        hasLastName = false;
      }
      button.set_sensitive(hasFirstName && hasLastName);

    });

    button.signal_clicked().connect([this]() {

      output.set_text(firstName.get_text() + " " + lastName.get_text());
    });
  }
};


int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}
