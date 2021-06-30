#pragma once
#ifndef CONSOLE_LOGGER_HPP
#define CONSOLE_LOGGER_HPP

// C++
#include <iostream>
#include <chrono>
#include <ctime>

// Custom
#include "logger.hpp"

class console_logger : public logger
{
public:
   ~console_logger() = default;

private:
   void open() override
   {
      std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
      std::cout << m_level++ << ", " << std::ctime(&time) << '[' << std::endl;
   }

   void write(const std::string &message) override
   {
      std::cout << '\t' << message << std::endl;
   }

   void close() override
   {
      std::cout << ']' << std::endl;
   }

   static int m_level;
};

int console_logger::m_level = 1;

#endif //CONSOLE_LOGGER_HPP