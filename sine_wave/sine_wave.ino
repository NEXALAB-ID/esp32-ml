// This example demonstrates running a TensorFlow Lite model on ESP32
// to predict sine wave values without any external sensors or wiring.

#include <TensorFlowLite_ESP32.h>
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "sine_model.h" // pre-trained model converted to C array

const int kTensorArenaSize = 8 * 1024;
uint8_t tensor_arena[kTensorArenaSize];

tflite::AllOpsResolver resolver;
const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* input = nullptr;
TfLiteTensor* output = nullptr;

const float kXrange = 2.f * 3.14159265358979323846f;
const int kInferencesPerCycle = 20;

void setup() {
  Serial.begin(115200);

  model = tflite::GetModel(sine_model);
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

  Serial.println("Sine Wave Model Ready!");
}

void loop() {
  for (int i = 0; i < kInferencesPerCycle; i++) {
    float x = (float)i * kXrange / (float)kInferencesPerCycle;
    input->data.f[0] = x;

    interpreter->Invoke();

    float predicted = output->data.f[0];
    float actual    = sin(x);

    Serial.print("x: ");
    Serial.print(x);
    Serial.print(" | Predicted: ");
    Serial.print(predicted);
    Serial.print(" | Actual: ");
    Serial.println(actual);

    delay(100);
  }
}
