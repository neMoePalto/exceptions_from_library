#include "manager.h"

#include <cassert>
#include <fstream>
#include <iostream>


manager::manager() {
  worker_ = new worker();
  worker_->do_work();
}


manager::~manager() {
  delete worker_;
}


const std::string manager::file_name_ = "../file_with_tag.txt";


const std::map<behavior_tag, std::string> manager::tags_{{behavior_tag::bad_alloc,        "throw()__bad_alloc"},
                                                         {behavior_tag::runtime_error,    "throw()__run_time_error"},
                                                         {behavior_tag::custom_exception, "throw()__custom_exception"}};

std::string manager::get_file_name() noexcept {
  return file_name_;
}


std::string manager::get_text_by_tag(behavior_tag tag) noexcept {
  auto it = tags_.find(tag);
  if (it != tags_.cend()) {
    return it->second;
  } else {
    assert(false);
  }
}


void manager::save_tag(behavior_tag t) {
  std::string behavior_tag_as_text = get_text_by_tag(t);

  std::ofstream myfile;
  myfile.open(file_name_);

  if (myfile.is_open()) {
    myfile << behavior_tag_as_text;
//    std::cout << "manager::save_tag() write to file: " << behavior_tag_as_text << '\n' << std::endl;
  }
  myfile.close();
}
