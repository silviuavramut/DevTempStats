package devtempstats.client.devtempstatsapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.RemoteException;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import devtempstats.service.devtempstatsmanager.devtempstatsManager;


public class MainActivity extends AppCompatActivity {

    private devtempstatsManager devtempstats = devtempstatsManager.getInstance();
    private Button cpuButton,cpuMaxButton,cpuAverageButton, gpuButton, gpuMaxButton, gpuAverageButton, ambientButton, ambientMaxButton, ambientAverageButton;
    private TextView cpuTextView, gpuTextView, ambientTextView;
    private Float cpuTemp, gpuTemp, ambientTemp;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        cpuButton = (Button) findViewById(R.id.cpuButton);
        cpuMaxButton = (Button) findViewById(R.id.cpuMaxButton);
        cpuAverageButton = (Button) findViewById(R.id.cpuAverageButton);
        gpuButton = (Button) findViewById(R.id.gpuButton);
        gpuMaxButton = (Button) findViewById(R.id.gpuMaxButton);
        gpuAverageButton = (Button) findViewById(R.id.gpuAverageButton);
        ambientButton = (Button) findViewById(R.id.ambientButton);
        ambientMaxButton = (Button) findViewById(R.id.ambientMaxButton);
        ambientAverageButton = (Button) findViewById(R.id.ambientAverageButton);
        cpuTextView = (TextView) findViewById(R.id.cpuTempTextView);
        gpuTextView = (TextView) findViewById(R.id.gpuTempTextView);
        ambientTextView = (TextView) findViewById(R.id.ambientTempTextView);

        cpuButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try{
                cpuTemp = devtempstats.getCpuTemperature();
                cpuTextView.setText("cpu temp is " + cpuTemp.toString());
                }catch(RemoteException e){

                }
            }
        });
        cpuMaxButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try{
                cpuTemp = devtempstats.getMaxCpuTemperature();
                cpuTextView.setText("cpu temp is " + cpuTemp.toString());
                }catch(RemoteException e){
                }
            }
        });
        cpuAverageButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try{
                cpuTemp = devtempstats.getAverageCpuTemperature();
                cpuTextView.setText("cpu temp is " + cpuTemp.toString());
                }catch(RemoteException e){
                }
            }
        });

        gpuButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try{
                gpuTemp = devtempstats.getGpuTemperature();
                gpuTextView.setText("gpu temp is " + gpuTemp.toString());
                }catch(RemoteException e){
                }
            }
        });
        gpuMaxButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try{
                gpuTemp = devtempstats.getMaxGpuTemperature();
                gpuTextView.setText("gpu temp is " + gpuTemp.toString());
                }catch(RemoteException e){
                }
            }
        });
        gpuAverageButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try{
                gpuTemp = devtempstats.getAverageGpuTemperature();
                gpuTextView.setText("gpu temp is " + gpuTemp.toString());
                }catch(RemoteException e){
                }
            }
        });

        ambientButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try{
                ambientTemp = devtempstats.getAmbientTemperature();
                ambientTextView.setText("ambient temp is " + ambientTemp.toString());
                }catch(RemoteException e){
                }
            }
        });
        ambientMaxButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try{
                ambientTemp = devtempstats.getMaxAmbientTemperature();
                ambientTextView.setText("ambient temp is " + ambientTemp.toString());
                }catch(RemoteException e){
                }
            }
        });
        ambientAverageButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try{
                ambientTemp = devtempstats.getAverageAmbientTemperature();
                ambientTextView.setText("ambient temp is " + ambientTemp.toString());
                }catch(RemoteException e){
                }
            }
        });

        Log.i("devtempstatsapp", "Application started");

    }
}