<div align="center">

<img src="https://raw.githubusercontent.com/NEXALAB-ID/.github/main/assets/banner.png" width="100%" alt="NEXALAB ID Banner"/>

<p>&nbsp;</p>

[![Organization](https://img.shields.io/badge/GitHub-NEXALAB--ID-0ea5e9?style=for-the-badge&logo=github&logoColor=white)](https://github.com/NEXALAB-ID)
[![Board](https://img.shields.io/badge/Board-ESP32-000000?style=for-the-badge&logo=espressif&logoColor=white)](#)
[![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](#)
[![Framework](https://img.shields.io/badge/Framework-TensorFlow%20Lite-FF6F00?style=for-the-badge&logo=tensorflow&logoColor=white)](#)
[![License](https://img.shields.io/badge/License-MIT-22c55e?style=for-the-badge)](#)

</div>

<br/>

---

## About

**esp32-ml** is a collection of machine learning examples running on ESP32 using **TensorFlow Lite for Microcontrollers**. These examples demonstrate how to deploy pre-trained ML models directly on an ESP32 — no cloud, no external server, just inference on the edge.

No wiring required — all examples use simulated or generated data.

---

## Contents

| Example | Description |
|:--------|:------------|
| **sine_wave** | Predict sine wave values using a pre-trained TensorFlow Lite model |
| **anomaly_detection** | Detect anomalies in simulated sensor data using a TensorFlow Lite model |

---

## Notes

> **Pre-trained Models Required** — Each example requires a model file (e.g., `sine_model.h`, `anomaly_model.h`) converted to a C array. These are not included in this repository. See the [Getting Started](#getting-started) section for how to obtain or generate them.

> **Simulated Data** — All examples use simulated or mathematically generated data. No external sensors or wiring are required to run these examples.

---

## Requirements

- ESP32 board (any variant)
- [Arduino IDE](https://www.arduino.cc/en/software) with ESP32 board support installed
- Library: `TensorFlowLite_ESP32` — install via Arduino Library Manager
- Pre-trained model converted to C array (`.h` file)

---

## Getting Started

1. Clone this repository
   ```bash
   git clone https://github.com/NEXALAB-ID/esp32-ml.git
   ```

2. Obtain or generate the model file:
   - For `sine_wave` — follow the [TensorFlow Lite Hello World tutorial](https://github.com/tensorflow/tflite-micro/tree/main/tensorflow/lite/micro/examples/hello_world) to generate `sine_model.h`
   - For `anomaly_detection` — train a simple autoencoder and convert it using `xxd -i model.tflite > anomaly_model.h`

3. Place the `.h` model file inside the example folder

4. Open the example in Arduino IDE, select your ESP32 board, and upload

5. Open Serial Monitor at **115200 baud** to see inference results

---

## How It Works

**sine_wave**
A small neural network trained to predict `sin(x)` is loaded onto the ESP32. The model takes an x value as input and outputs a predicted sine value, which is compared to the actual `sin(x)` in Serial Monitor.

**anomaly_detection**
A model trained on normal sensor data range (20–30) is loaded onto the ESP32. Every 10th reading injects an anomalous value (50–80) to demonstrate detection. The model outputs an anomaly score — values above the threshold are flagged as anomalies.

---

## Project Structure

```
esp32-ml/
├── sine_wave/
│   ├── sine_wave.ino
│   └── sine_model.h        ← not included, generate separately
└── anomaly_detection/
    ├── anomaly_detection.ino
    └── anomaly_model.h     ← not included, generate separately
```

---

## Contributing

Want to add more ML examples for ESP32? Feel free to open a [Discussion](https://github.com/NEXALAB-ID/discussions/discussions) or submit a Pull Request.

---

<div align="center">

<sub>Part of NEXALAB ID &nbsp;·&nbsp; <strong>Innovate | Build | Connect</strong></sub>

</div>
