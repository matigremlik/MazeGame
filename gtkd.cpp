#include <gtkmm/application.h> // Gtk::Application
#include <gtkmm/window.h> // Gtk::Window
#include <iostream>
int main( int argc, char * argv[] ) {
auto app = Gtk::Application::create( argc, argv, "GTKmm.Tutorial.Example1" );
Gtk::Window window;
window.set_title( "Example 1" );
window.set_default_size( 500, 200 );
std::cout << "waiting for window to close" << std::endl;
return app->run( window );
}