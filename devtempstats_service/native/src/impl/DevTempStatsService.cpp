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

::ndk::ScopedAStatus DevTempStatsService::getCpuTemperature(float* _aidl_return)
{
   float cpuTemp;
   
   cpuTemp = 10.0;

   *_aidl_return = cpuTemp;
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getGpuTemperature(float* _aidl_return)
{
   float gpuTemp;
   
   gpuTemp = 10.0;

   *_aidl_return = gpuTemp;
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getAmbientTemperature(float* _aidl_return)
{
   float ambientTemp;
   
   ambientTemp = 10.0;

   *_aidl_return = ambientTemp;
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getAverageCpuTemperature(float* _aidl_return)
{
   float cpuTemp;
   
   cpuTemp = 20.0;

   *_aidl_return = cpuTemp;
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getAverageGpuTemperature(float* _aidl_return)
{
   float gpuTemp;
   
   gpuTemp = 20.0;

   *_aidl_return = gpuTemp;
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getAverageAmbientTemperature(float* _aidl_return)
{
   float ambientTemp;
   
   ambientTemp = 20.0;

   *_aidl_return = ambientTemp;
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getMaxCpuTemperature(float* _aidl_return)
{
   float cpuTemp;
   
   cpuTemp = 30.0;

   *_aidl_return = cpuTemp;
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getMaxGpuTemperature(float* _aidl_return)
{
   float gpuTemp;
   
   gpuTemp = 30.0;

   *_aidl_return = gpuTemp;
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getMaxAmbientTemperature(float* _aidl_return)
{
   float ambientTemp;
   
   ambientTemp = 30.0;

   *_aidl_return = ambientTemp;
   return ndk::ScopedAStatus::ok();
}


}
}
