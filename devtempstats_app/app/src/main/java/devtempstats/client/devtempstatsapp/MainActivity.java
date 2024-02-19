package devtempstats.client.devtempstatsapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

//import devtempstats.service.devtempstatsmanager;


public class MainActivity extends AppCompatActivity {

    //private devtempstatsManager devtempstats = devtempstatsManager.getInstance();
    private Button cpuButton,cpuMaxButton,cpuAverageButton, gpuButton, gpuMaxButton, gpuAverageButton, ambientButton, ambientMaxButton, ambientAverageButton;
    private TextView cpuTextView, gpuTextView, ambientTextView;
    private String cpuTemp, gpuTemp, ambientTemp;
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
                cpuTemp = "10";
                cpuTextView.setText("cpu temp is " + cpuTemp);
            }
        });
        cpuMaxButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                cpuTemp = "20";
                cpuTextView.setText("cpu temp is " + cpuTemp);
            }
        });
        cpuAverageButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                cpuTemp = "30";
                cpuTextView.setText("cpu temp is " + cpuTemp);
            }
        });

        gpuButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                gpuTemp = "10";
                gpuTextView.setText("gpu temp is " + gpuTemp);
            }
        });
        gpuMaxButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                gpuTemp = "20";
                gpuTextView.setText("gpu temp is " + gpuTemp);
            }
        });
        gpuAverageButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                gpuTemp = "20";
                gpuTextView.setText("gpu temp is " + gpuTemp);
            }
        });

        ambientButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ambientTemp = "10";
                ambientTextView.setText("ambient temp is " + ambientTemp);
            }
        });
        ambientMaxButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ambientTemp = "20";
                ambientTextView.setText("ambient temp is " + ambientTemp);
            }
        });
        ambientAverageButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ambientTemp = "30";
                ambientTextView.setText("ambient temp is " + ambientTemp);
            }
        });

        Log.i("devtempstatsapp", "Application started");

    }
}