// C++
#include <iostream>
#include <memory>

// Custom
#include "include/factory/console_creator.hpp"
#include "include/factory/file_creator.hpp"

int main()
{
   
   // Test 1 - console logger
   auto console_cr = std::make_unique<console_creator>();
   auto console = console_cr->getLogger();
   console->Log("Start work");
   console->Log("Did something");
   console->Log("End work");

   // Test 2 - file logger
   auto file_cr = std::make_unique<file_creator>("log.txt");
   auto file = file_cr->getLogger();
   file->Log("Start work");
   file->Log("Did something");
   file->Log("End work");

   // Clear data
   delete console;
   delete file;

   return EXIT_SUCCESS;
}