package devtempstats.service.devtempstatsmanager;

import android.util.Log;
import android.os.ServiceManager;
import android.os.IBinder;
import android.os.RemoteException;

import devtempstats.service.api.IDevTempStatsService;

public class devtempstatsManager {
    private IBinder binder;
    private IDevTempStatsService service;

    private static devtempstatsManager instance;

    private devtempstatsManager() {
        binder = ServiceManager.getService("devtempstats.service.api.IDevTempStatsService/default");
        if (binder != null) {
            service = IDevTempStatsService.Stub.asInterface(binder);
            if (service != null)
                Log.d("devtempstatsManager", "Success");
            else
                Log.e("devtempstatsManager", "Error accessing service");
            }
        else
            Log.e("devtempstatsManager", "Error acessing binder");
    }

    public static devtempstatsManager getInstance() {
        if (instance == null)
            instance = new devtempstatsManager();
        return instance;
    }

    public Float getCpuTemperature() throws RemoteException {
        return service.getCpuTemperature();
    }
    public Float getMaxCpuTemperature() throws RemoteException {
        return service.getMaxCpuTemperature();
    }
    public Float getAverageCpuTemperature() throws RemoteException {
        return service.getAverageCpuTemperature();
    }
    public Float getGpuTemperature() throws RemoteException {
        return service.getGpuTemperature();
    }
    public Float getMaxGpuTemperature() throws RemoteException {
        return service.getMaxGpuTemperature();
    }
    public Float getAverageGpuTemperature() throws RemoteException {
        return service.getAverageGpuTemperature();
    }
    public Float getAmbientTemperature() throws RemoteException {
        return service.getAmbientTemperature();
    }
    public Float getMaxAmbientTemperature() throws RemoteException {
        return service.getMaxAmbientTemperature();
    }
    public Float getAverageAmbientTemperature() throws RemoteException {
        return service.getAverageAmbientTemperature();
    }

}