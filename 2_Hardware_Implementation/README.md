# Hardware Deployment Guide
The PfNDM is split into five networks: f01, f02, fu, fx, and fy. The fu, fx and fy are onnx models converted into C language models. Due to a bug in cubeAI when converting the onnx model containing one-dimensional convolutions into a C language model, the original f0 network was split into two subnetworks, f01 and f02, and the keras model was selected for conversion.

The MCU board is STM32H743.Enable rs232 serial port to transmit prediction results to the computer and a LCD screen  to display the output results.

The environment includes:
STM32CUBEMX 6.8.0
X-CUBE-AI 8.1.0
MDK-ARM V5.32
