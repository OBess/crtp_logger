#pragma once
#ifndef FILE_CREATOR_HPP
#define FILE_CREATOR_HPP

// Custom
#include "creator.hpp"
#include "../loggers/file_logger.hpp"

class file_creator : public creator
{
public:
   file_creator(const std::string &file_path) : m_file_path(file_path) {}
   logger *getLogger() const override
   {
      return new file_logger(m_file_path);
   }

private:
   std::string m_file_path;
};

#endif //FILE_CREATOR_HPP