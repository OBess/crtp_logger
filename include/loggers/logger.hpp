#pragma once
#ifndef LOGGER_HPP
#define LOGGER_HPP

// C++
#include <utility>

template <class T>
class logger
{
public:
   virtual ~logger() = default;

   template <typename... Args>
   void Log(Args &&...message)
   {
      static_cast<T *>(this)->open();
      static_cast<T *>(this)->write(std::forward<Args>(message));
      static_cast<T *>(this)->close();
   }

protected:
   virtual void open() = 0;
   template <typename... Args>
   virtual void write(Args &&message) = 0;
   virtual void close() = 0;
};

#endif //LOGGER_HPP