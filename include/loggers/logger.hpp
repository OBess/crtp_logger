#pragma once
#ifndef LOGGER_HPP
#define LOGGER_HPP

template <class Derived>
class logger
{
public:
   virtual ~logger() = default;

   template<typename ... Args>
   void Log(const Args &message)
   {
      Derived->open();
      Derived->write(message);
      Derived->close();
   }

protected:
   virtual void open() = 0;
   template<typename ... Args>
   virtual void write(const Args &message) = 0;
   virtual void close() = 0;
};

#endif //LOGGER_HPP