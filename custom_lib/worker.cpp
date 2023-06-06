#include "worker.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

#include "manager.h"


worker::worker() {
  std::ifstream myfile;
  myfile.open(manager::get_file_name());

  std::string behavior_tag;

  if (myfile.is_open()) {
    myfile >> behavior_tag;
    std::cout << "worker::ctor() read from file: " << behavior_tag << '\n' << std::endl;
  }
  myfile.close();

  if (behavior_tag == "throw()__run_time_error") {
    throw std::runtime_error("Exception at worker::ctor(), [desctiption]");
  } else if (behavior_tag == "throw()__custom_exception") {
    throw custom_exception();
  }
}


void worker::do_work() {
  throw std::bad_alloc();
}
