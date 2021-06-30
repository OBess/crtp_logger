#pragma once
#ifndef LOGGER_HPP
#define LOGGER_HPP

class logger
{
public:
   virtual ~logger() = default;

   void Log(const std::string &message)
   {
      this->open();
      this->write(message);
      this->close();
   }

protected:
   virtual void open() = 0;
   virtual void write(const std::string &message) = 0;
   virtual void close() = 0;
};

#endif //LOGGER_HPP