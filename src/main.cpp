#include "exported.h"
#include "utilitronAPI.hpp"

utilitronAPI *api = nullptr;

extern "C"
{
  EXPORTED void init()
  {
    api = new utilitronAPI();
  }

  EXPORTED void destroy()
  {
    delete api;
  }

  EXPORTED int add(int a, int b)
  {
    return api->add(a, b);
  }
}
