#include "application.hpp"
int main() {
  // Initialize the application.
  // Is automatically called by application::run()
  // but can be called manually.
  // application::init();

  // Run the application loop and show the triangle.
  application::run();

  // Destroy the application.
  // Is automatically called at the end of program execution
  // but can be called manually.
  // application::free();
}
