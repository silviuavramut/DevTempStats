#ifndef DEVTEMPSTATS_SERVICE
#define DEVTEMPSTATS_SERVICE

#include <aidl/devtempstats/service/api/BnDevTempStatsService.h>

namespace dtssapinamespace = ::aidl::devtempstats::service::api;

namespace devtempstats
{
   namespace service
   {

      class DevTempStatsService
          : public ::aidl::devtempstats::service::api::BnDevTempStatsService
      {
      public:
         DevTempStatsService();
         ~DevTempStatsService();

         static ::std::shared_ptr<DevTempStatsService> getInstance();

         // IDevTempStatsService AIDL interface callbacks
         ::ndk::ScopedAStatus getCpuTemperature(float *_aidl_return) final;
         ::ndk::ScopedAStatus getGpuTemperature(float *_aidl_return) final;
         ::ndk::ScopedAStatus getAmbientTemperature(float *_aidl_return) final;
         ::ndk::ScopedAStatus getAverageCpuTemperature(float *_aidl_return) final;
         ::ndk::ScopedAStatus getAverageGpuTemperature(float *_aidl_return) final;
         ::ndk::ScopedAStatus getAverageAmbientTemperature(float *_aidl_return) final;
         ::ndk::ScopedAStatus getMaxCpuTemperature(float *_aidl_return) final;
         ::ndk::ScopedAStatus getMaxGpuTemperature(float *_aidl_return) final;
         ::ndk::ScopedAStatus getMaxAmbientTemperature(float *_aidl_return) final;

         const std::string getServiceName(void)
         {
            return std::string() + descriptor + "/default";
         }

      private:
         static ::std::shared_ptr<DevTempStatsService> S_INSTANCE;

         void ReadColumnFromCSV(const std::string &filename, int col_index, std::vector<float> &column_data);
         float GetCpuNextValue(std::vector<float> &vec);
         float GetGpuNextValue(std::vector<float> &vec);
         float GetAmbientNextValue(std::vector<float> &vec);
         float CalculateMaxValue(const std::vector<float> &vec);
         float CalculateAverageValue(const std::vector<float> &vec);

         float cpu_value();
         float gpu_value();
         float ambient_value();
         float max_cpu_value();
         float max_gpu_value();
         float max_ambient_value();
         float average_cpu_value();
         float average_gpu_value();
         float average_ambient_value();

         ::std::vector<float> cpu_column_data_, gpu_column_data_, ambient_column_data_;
         float cpu_temp_, gpu_temp_, ambient_temp_;
      };

   }
}


#endif // DEVTEMPSTATS_SERVICE