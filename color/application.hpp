#pragma once

// This application shall be thought of as singleton.
// We use a namespace as an implementation alternative
// to the standard object-oriented design of a class.
// This allows the use of a global application state
// which is much easier to use with GLFW and lambdas.
namespace application {

// Initialize the application.
// Can be called manually.
// Otherwise called by application::run.
void init();

// Run the application.
// If not initialized, automatically calls application::init.
void run();

// Destroy the application.
// Automatically called when exiting the program.
void free();

}  // namespace application
