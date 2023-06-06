#pragma once


#include <exception>


class custom_exception : public std::exception {
public:
  const char* what() const noexcept override {
    return "custom_exception";
  };
};


class worker {
public:
  worker();

  void do_work();
};
