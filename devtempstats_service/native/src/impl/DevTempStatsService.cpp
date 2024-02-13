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
   readColumnFromCSV("/vendor/etc/temperatures.csv",0,cpuColumnData);
   readColumnFromCSV("/vendor/etc/temperatures.csv",1,gpuColumnData);
   readColumnFromCSV("/vendor/etc/temperatures.csv",2,ambientColumnData);

}

DevTempStatsService::~DevTempStatsService()
{

}

::ndk::ScopedAStatus DevTempStatsService::getCpuTemperature(float* _aidl_return)
{


   *_aidl_return = cpuValue();
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getGpuTemperature(float* _aidl_return)
{
   
   *_aidl_return = gpuValue();
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getAmbientTemperature(float* _aidl_return)
{
   

   *_aidl_return = ambientValue();
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getAverageCpuTemperature(float* _aidl_return)
{

   *_aidl_return = averageCpuValue();
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getAverageGpuTemperature(float* _aidl_return)
{

   *_aidl_return = averageGpuValue();
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getAverageAmbientTemperature(float* _aidl_return)
{

   *_aidl_return = averageAmbientValue();
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getMaxCpuTemperature(float* _aidl_return)
{

   *_aidl_return = maxCpuValue();
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getMaxGpuTemperature(float* _aidl_return)
{
   *_aidl_return = maxGpuValue();
   return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus DevTempStatsService::getMaxAmbientTemperature(float* _aidl_return)
{
   *_aidl_return = maxAmbientValue();
   return ndk::ScopedAStatus::ok();
}

void DevTempStatsService::readColumnFromCSV(const std::string& filename, int colIndex, std::vector<float>& columnData) {
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string cell;
            int currentCol = 0;
            while (getline(ss, cell, ',') && currentCol <= colIndex) {
                if (currentCol == colIndex) {
                    columnData.push_back(std::stof(cell));
                    break; // Stop reading after finding the desired column
                }
                ++currentCol;
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

float DevTempStatsService::getCpuNextValue(std::vector<float>& vec) {
    static std::size_t index_cpu = 0;

    if (index_cpu >= vec.size()) {
        index_cpu = 0;
    }

    return vec[index_cpu++];
}
float DevTempStatsService::getGpuNextValue(std::vector<float>& vec) {
    static std::size_t index_gpu = 0;

    if (index_gpu >= vec.size()) {
        index_gpu = 0;
    }

    return vec[index_gpu++];
}
float DevTempStatsService::getAmbientNextValue(std::vector<float>& vec) {
    static std::size_t index_ambient = 0;

    if (index_ambient >= vec.size()) {
        index_ambient = 0;
    }

    return vec[index_ambient++];
}

float DevTempStatsService::calculateMaxValue(const std::vector<float>& vec) {
    float max = vec[0]; // Initialize max to the first element of the vector

    // Iterate through the vector to find the maximum element
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }

    return max;
}

float DevTempStatsService::calculateAverageValue(const std::vector<float>& vec)
{
        float sum = 0.0;
       
        for ( int i=0; i < (int)vec.size(); i++)
        {
            sum += vec[i];
        }
       
        return ( sum / vec.size());
}



float DevTempStatsService::cpuValue(){
   
   cpuTemp = getCpuNextValue(cpuColumnData);

   return cpuTemp;
}

float DevTempStatsService::gpuValue(){
   
   gpuTemp = getGpuNextValue(gpuColumnData);

   return gpuTemp;
}

float DevTempStatsService::ambientValue(){
   
   ambientTemp = getAmbientNextValue(ambientColumnData);

   return ambientTemp;
}

float DevTempStatsService::maxCpuValue(){
   
   cpuTemp = calculateMaxValue(cpuColumnData);

   return cpuTemp;
}

float DevTempStatsService::maxGpuValue(){
   
   gpuTemp = calculateMaxValue(gpuColumnData);
   return gpuTemp;
}

float DevTempStatsService::maxAmbientValue(){
   
   ambientTemp = calculateMaxValue(ambientColumnData);

   return ambientTemp;
}

float DevTempStatsService::averageCpuValue(){
   
   cpuTemp = calculateAverageValue(cpuColumnData);

   return cpuTemp;
}

float DevTempStatsService::averageGpuValue(){
   
   gpuTemp = calculateAverageValue(gpuColumnData);
   return gpuTemp;
}

float DevTempStatsService::averageAmbientValue(){
   
   ambientTemp = calculateAverageValue(ambientColumnData);

   return ambientTemp;
}


}
}
