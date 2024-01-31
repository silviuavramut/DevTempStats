#ifndef DEVTEMPSTATS_SERVICE
#define DEVTEMPSTATS_SERVICE

#include <aidl/devtempstats/service/api/BnDevTempStatsService.h>

namespace dtssapinamespace = ::aidl::devtempstats::service::api;

namespace devtempstats {
namespace service {

class DevTempStatsService
   : public ::aidl::devtempstats::service::api::BnDevTempStatsService
{
public:
   DevTempStatsService();
   ~DevTempStatsService();

   static ::std::shared_ptr<DevTempStatsService> getInstance();

   // IDevTempStatsService AIDL interface callbacks
   ::ndk::ScopedAStatus getCpuTemperature(float* _aidl_return) final;
   ::ndk::ScopedAStatus getGpuTemperature(float* _aidl_return) final;
   ::ndk::ScopedAStatus getAmbientTemperature(float* _aidl_return) final;
   ::ndk::ScopedAStatus getAverageCpuTemperature(float* _aidl_return) final;
   ::ndk::ScopedAStatus getAverageGpuTemperature(float* _aidl_return) final;
   ::ndk::ScopedAStatus getAverageAmbientTemperature(float* _aidl_return) final;
   ::ndk::ScopedAStatus getMaxCpuTemperature(float* _aidl_return) final;
   ::ndk::ScopedAStatus getMaxGpuTemperature(float* _aidl_return) final;
   ::ndk::ScopedAStatus getMaxAmbientTemperature(float* _aidl_return) final;

    const std::string getServiceName(void)
   {
      return std::string() + descriptor + "/default";
   }

private:
   static ::std::shared_ptr<DevTempStatsService> S_INSTANCE;

};

}
}


#endif  // DEVTEMPSTATS_SERVICE