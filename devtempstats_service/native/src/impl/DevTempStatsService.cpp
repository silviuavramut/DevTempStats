#include "DevTempStatsService.hpp"
#include <utils/Log.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "devtempstats_service"

namespace devtempstats {
namespace service {

::std::shared_ptr<DevTempStatsService> DevTempStatsService::S_INSTANCE = NULL;

::std::shared_ptr<DevTempStatsService> DevTempStatsService::getInstance()
{
   if (S_INSTANCE == NULL)
   {
      S_INSTANCE = ndk::SharedRefBase::make<DevTempStatsService>();
   }
   return S_INSTANCE;
}

DevTempStatsService::DevTempStatsService()
{

}

DevTempStatsService::~DevTempStatsService()
{

}




}
}
