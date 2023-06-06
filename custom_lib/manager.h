#pragma once


#include <map>
#include <string>

#include "worker.h"


enum class behavior_tag {
  bad_alloc,
  runtime_error,
  custom_exception
};


class manager {
public:
  manager();
  ~manager();

  // Для простоты доступа - static методы. Это не принципиально:
  static std::string get_file_name() noexcept;
  static std::string get_text_by_tag(behavior_tag tag) noexcept;

  void save_tag(behavior_tag t);

private:
  static const std::string file_name_;
  static const std::map<behavior_tag, std::string> tags_;
  worker* worker_ = nullptr;
};
