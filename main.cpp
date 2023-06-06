#include <iostream>

#include "custom_lib/manager.h"


int main() {
  const std::string str = "Поймал исключение, сгенерированное сторонней библиотекой:\n";
  manager* m = nullptr;

  try {
    m = new manager();
//  } catch (const std::exception& e) { // Если мы не собираемся по-разному обрабатывать
//                                      // разные типы исключений, то этого достаточно
//    std::cout << e.what() << std::endl;
  } catch (const std::bad_alloc& e) {
    std::cout << str << e.what() << std::endl;
    m->save_tag(behavior_tag::runtime_error); // Здесь может быть какой-нибудь код обработки исключения...
  } catch (const std::runtime_error& e) {
    std::cout << str << e.what() << std::endl;
    m->save_tag(behavior_tag::custom_exception);
  } catch (const custom_exception& e) {
    std::cout << str << e.what() << std::endl;
    m->save_tag(behavior_tag::bad_alloc);
  }

  return 0;
}
