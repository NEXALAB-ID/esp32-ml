// This example demonstrates simple anomaly detection on ESP32
// using simulated sensor data — no external sensors or wiring required.

#include <TensorFlowLite_ESP32.h>
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "anomaly_model.h" // pre-trained model converted to C array

const int kTensorArenaSize = 8 * 1024;
uint8_t tensor_arena[kTensorArenaSize];

tflite::AllOpsResolver resolver;
const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* input  = nullptr;
TfLiteTensor* output = nullptr;

// Simulated normal data range
const float kNormalMin = 20.0f;
const float kNormalMax = 30.0f;
const float kAnomalyThreshold = 0.7f;

float simulateSensorData(bool inject_anomaly) {
  if (inject_anomaly) {
    return random(50, 80);  // anomalous value
  }
  return kNormalMin + (random(0, 100) / 100.0f) * (kNormalMax - kNormalMin);
}

void setup() {
  Serial.begin(115200);

  model = tflite::GetModel(anomaly_model);
  if (model->version() != TFLITE_SCHEMA_VERSION) {
    Serial.println("Model schema mismatch!");
    return;
  }

  static tflite::MicroInterpreter static_interpreter(
    model, resolver, tensor_arena, kTensorArenaSize
  );
  interpreter = &static_interpreter;
  interpreter->AllocateTensors();

  input  = interpreter->input(0);
  output = interpreter->output(0);

  Serial.println("Anomaly Detection Model Ready!");
}

void loop() {
  // Every 10th reading inject an anomaly for demonstration
  static int count = 0;
  bool inject_anomaly = (count % 10 == 0);
  count++;

  float sensor_value = simulateSensorData(inject_anomaly);
  input->data.f[0] = sensor_value;

  interpreter->Invoke();

  float anomaly_score = output->data.f[0];
  bool  is_anomaly    = anomaly_score > kAnomalyThreshold;

  Serial.print("Sensor Value: ");
  Serial.print(sensor_value);
  Serial.print(" | Anomaly Score: ");
  Serial.print(anomaly_score);
  Serial.print(" | Status: ");
  Serial.println(is_anomaly ? "ANOMALY DETECTED" : "Normal");

  delay(1000);
}
