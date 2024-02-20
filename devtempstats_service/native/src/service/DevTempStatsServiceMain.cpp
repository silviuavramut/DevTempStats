#include "DevTempStatsService.hpp"
#include <utils/Log.h>
#include <iostream>
#include <signal.h>
#include <android/binder_ibinder.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "devtempstats-service"

namespace dtssnamespace = devtempstats::service;

int main()
{
   ALOGI("%s:%d: starting service", __FUNCTION__, __LINE__);

   signal(SIGPIPE, SIG_IGN);
   if (ABinderProcess_setThreadPoolMaxThreadCount(1))
   {
      std::shared_ptr<dtssnamespace::DevTempStatsService> dtsObj = dtssnamespace::DevTempStatsService::getInstance();
      if (dtsObj)
      {
         binder_status_t status = AServiceManager_addService(dtsObj->asBinder().get(),
         dtsObj->getServiceName().c_str());
         if (status != STATUS_OK)
         {
            ALOGE("%s:%d: adding service failed", __FUNCTION__, __LINE__);
         }
         else
         {
            int32_t version = -1;
            dtsObj->getInterfaceVersion(&version);
            ALOGI("%s:%d: service ready (registered version V%d)", __FUNCTION__, __LINE__, version);
            ABinderProcess_joinThreadPool();
         }
      }
      else
      {
         ALOGE("%s:%d: service NULL", __FUNCTION__, __LINE__);
      }
   }
   else
   {
      ALOGE("%s:%d: configure thread-pool failed", __FUNCTION__, __LINE__);
   }
   ALOGW("%s:%d: service joined", __FUNCTION__, __LINE__);

   return 0;  // should never get here
}