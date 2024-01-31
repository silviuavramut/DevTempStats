package devtempstats.service.api;

@VintfStability
interface IDevTempStatsService{

    float getCpuTemperature();
    float getGpuTemperature();
    float getAmbientTemperature();
    float getAverageCpuTemperature();
    float getAverageGpuTemperature();
    float getAverageAmbientTemperature();
    float getMaxCpuTemperature();
    float getMaxGpuTemperature();
    float getMaxAmbientTemperature();
	
}
