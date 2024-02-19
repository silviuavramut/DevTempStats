#include "DevTempStatsService.hpp"

#include <utils/Log.h>

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "devtempstats_service"

namespace devtempstats
{
   namespace service
   {

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
         ReadColumnFromCSV("/vendor/etc/temperatures.csv", 0, cpu_column_data_);
         ReadColumnFromCSV("/vendor/etc/temperatures.csv", 1, gpu_column_data_);
         ReadColumnFromCSV("/vendor/etc/temperatures.csv", 2, ambient_column_data_);
      }

      DevTempStatsService::~DevTempStatsService()
      {
      }

      ::ndk::ScopedAStatus DevTempStatsService::getCpuTemperature(float *_aidl_return)
      {

         *_aidl_return = cpu_value();
         return ndk::ScopedAStatus::ok();
      }

      ::ndk::ScopedAStatus DevTempStatsService::getGpuTemperature(float *_aidl_return)
      {

         *_aidl_return = gpu_value();
         return ndk::ScopedAStatus::ok();
      }

      ::ndk::ScopedAStatus DevTempStatsService::getAmbientTemperature(float *_aidl_return)
      {

         *_aidl_return = ambient_value();
         return ndk::ScopedAStatus::ok();
      }

      ::ndk::ScopedAStatus DevTempStatsService::getAverageCpuTemperature(float *_aidl_return)
      {

         *_aidl_return = average_cpu_value();
         return ndk::ScopedAStatus::ok();
      }

      ::ndk::ScopedAStatus DevTempStatsService::getAverageGpuTemperature(float *_aidl_return)
      {

         *_aidl_return = average_gpu_value();
         return ndk::ScopedAStatus::ok();
      }

      ::ndk::ScopedAStatus DevTempStatsService::getAverageAmbientTemperature(float *_aidl_return)
      {

         *_aidl_return = average_ambient_value();
         return ndk::ScopedAStatus::ok();
      }

      ::ndk::ScopedAStatus DevTempStatsService::getMaxCpuTemperature(float *_aidl_return)
      {

         *_aidl_return = max_cpu_value();
         return ndk::ScopedAStatus::ok();
      }

      ::ndk::ScopedAStatus DevTempStatsService::getMaxGpuTemperature(float *_aidl_return)
      {
         *_aidl_return = max_gpu_value();
         return ndk::ScopedAStatus::ok();
      }

      ::ndk::ScopedAStatus DevTempStatsService::getMaxAmbientTemperature(float *_aidl_return)
      {
         *_aidl_return = max_ambient_value();
         return ndk::ScopedAStatus::ok();
      }

      void DevTempStatsService::ReadColumnFromCSV(const std::string &filename, int col_index, std::vector<float> &column_data)
      {
         std::ifstream file(filename);
         std::string line;

         if (file.is_open())
         {
            while (getline(file, line))
            {
               std::stringstream ss(line);
               std::string cell;
               int current_col = 0;
               while (getline(ss, cell, ',') && current_col <= col_index)
               {
                  if (current_col == col_index)
                  {
                     column_data.push_back(std::stof(cell));
                     break; // Stop reading after finding the desired column
                  }
                  ++current_col;
               }
            }
            file.close();
         }
         else
         {
            std::cerr << "Unable to open file: " << filename << std::endl;
         }
      }

      float DevTempStatsService::GetCpuNextValue(std::vector<float> &vec)
      {
         static std::size_t index_cpu = 0;

         if (index_cpu >= vec.size())
         {
            index_cpu = 0;
         }

         return vec[index_cpu++];
      }

      float DevTempStatsService::GetGpuNextValue(std::vector<float> &vec)
      {
         static std::size_t index_gpu = 0;

         if (index_gpu >= vec.size())
         {
            index_gpu = 0;
         }

         return vec[index_gpu++];
      }

      float DevTempStatsService::GetAmbientNextValue(std::vector<float> &vec)
      {
         static std::size_t index_ambient = 0;

         if (index_ambient >= vec.size())
         {
            index_ambient = 0;
         }

         return vec[index_ambient++];
      }

      float DevTempStatsService::CalculateMaxValue(const std::vector<float> &vec)
      {
         float max = vec[0]; // Initialize max to the first element of the vector

         // Iterate through the vector to find the maximum element
         for (size_t i = 1; i < vec.size(); ++i)
         {
            if (vec[i] > max)
            {
               max = vec[i];
            }
         }

         return max;
      }

      float DevTempStatsService::CalculateAverageValue(const std::vector<float> &vec)
      {
         float sum = 0.0;

         for (int i = 0; i < (int)vec.size(); i++)
         {
            sum += vec[i];
         }

         return (sum / vec.size());
      }

      float DevTempStatsService::cpu_value()
      {

         cpu_temp_ = GetCpuNextValue(cpu_column_data_);

         return cpu_temp_;
      }

      float DevTempStatsService::gpu_value()
      {

         gpu_temp_ = GetGpuNextValue(gpu_column_data_);

         return gpu_temp_;
      }

      float DevTempStatsService::ambient_value()
      {

         ambient_temp_ = GetAmbientNextValue(ambient_column_data_);

         return ambient_temp_;
      }

      float DevTempStatsService::max_cpu_value()
      {

         cpu_temp_ = CalculateMaxValue(cpu_column_data_);

         return cpu_temp_;
      }

      float DevTempStatsService::max_gpu_value()
      {

         gpu_temp_ = CalculateMaxValue(gpu_column_data_);

         return gpu_temp_;
      }

      float DevTempStatsService::max_ambient_value()
      {

         ambient_temp_ = CalculateMaxValue(ambient_column_data_);

         return ambient_temp_;
      }

      float DevTempStatsService::average_cpu_value()
      {

         cpu_temp_ = CalculateAverageValue(cpu_column_data_);

         return cpu_temp_;
      }

      float DevTempStatsService::average_gpu_value()
      {

         gpu_temp_ = CalculateAverageValue(gpu_column_data_);

         return gpu_temp_;
      }

      float DevTempStatsService::average_ambient_value()
      {

         ambient_temp_ = CalculateAverageValue(ambient_column_data_);

         return ambient_temp_;
      }

   }
   
}
