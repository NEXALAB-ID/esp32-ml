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

> **Simulated Data** — All examples use simulated or mathematically generated data. No external sensors or wiring are required to run these examples.

> **Generating Models** — Each example folder includes a Jupyter notebook (`generate_*.ipynb`) to train and export the model. Run it in Google Colab to regenerate `sine_model.h` or `anomaly_model.h` if needed.

---

## Requirements

- ESP32 board (any variant)
- [Arduino IDE](https://www.arduino.cc/en/software) with ESP32 board support installed
- Library: `TensorFlowLite_ESP32` — install via Arduino Library Manager

---

## Getting Started

1. Clone this repository
   ```bash
   git clone https://github.com/NEXALAB-ID/esp32-ml.git
   ```

2. Open the example you want in Arduino IDE

3. Select your ESP32 board under **Tools → Board**

4. Upload and open Serial Monitor at **115200 baud** to see inference results

> To regenerate the model files, open the `generate_*.ipynb` notebook in Google Colab and run all cells. Download the generated `.h` file and replace the existing one in the example folder.

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
│   ├── generate_sine_model.ipynb
│   ├── sine_model.tflite
│   └── sine_model.h
└── anomaly_detection/
    ├── anomaly_detection.ino
    ├── generate_anomaly_model.ipynb
    ├── anomaly_model.tflite
    └── anomaly_model.h
```

---

## Contributing

Want to add more ML examples for ESP32? Feel free to open a [Discussion](https://github.com/NEXALAB-ID/discussions/discussions) or submit a Pull Request.

---

<div align="center">

<sub>Part of NEXALAB ID &nbsp;·&nbsp; <strong>Innovate | Build | Connect</strong></sub>

</div>
