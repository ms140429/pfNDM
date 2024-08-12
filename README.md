<div align="center">
<h1>pfNDM: Perron-Frobenius Neural Dynamics Model</h1>

![languages](https://img.shields.io/github/languages/top/ms140429/pfNDM)
![Static Badge](https://img.shields.io/badge/Platform-Win_Mac-pink)
![GitHub all releases](https://img.shields.io/github/downloads/ms140429/pfNDM/total)
</div>

This repository includes the code for the paper [Neural Dynamics Model for Temperature Estimation of Permanent Magnet Synchronous Motor](https://www.techrxiv.org/users/706792/articles/691946-explainable-neural-dynamics-models-for-electric-motor-temperature-estimation).

<p align="center">
  <img src="https://github.com/ms140429/pfNDM/blob/main/1_Software_code/frame.jpg" width="800px"/>
</p>

# Abstract
Accurate temperature estimation of permanent magnet synchronous motors is the basis for ensuring safe operation and designing effective thermal management strategies. Model-based estimation methods exhibit superior real-time performance, but the intricate modeling process requires substantial expert knowledge and lacks versatility. To the contrary, data-driven estimation methods, while offering flexibility, often lack physical implications in terms of system dynamics. This paper proposed a structured linear neural dynamics model for motor temperature estimation. The stability of the data-driven pipeline is facilitated by the Perron-Frobenius theorem, and the smooth evolution of the state between time steps is achieved by utilizing a physics-informed loss term. The effectiveness of the proposed method is verified by temperature estimation tasks at the edge end, and its practicality is demonstrated by measuring the memory and power usage of a deployed STM32 microcontroller.

# Quick start
## Dataset
Download the dataset from this [website](https://www.kaggle.com/wkirgsn/electric-motor-temperature) and put it into the [Data](https://github.com/ms140429/pfNDM/1_Software_code/Data) folder **firstly**!
## Configuration
Go into the folder *1_Software_code*, and
```
pip install -r requirements.txt
```
## Run
Go into the folder *1_Software_code*, and
```
python Train.py
```
# Hardware deployment
Detailed instructions for hardware deployment can be found [**here**](https://github.com/ms140429/pfNDM/2_Hardware_Implementation/README.md). :hammer::hammer: The trained pfNDM firstly split into many tiny parts, convolutional neural networks models are converted to .keras models, and others are converted to .onnx models. Then each model is converted into a .c model by Cube.AI. Finally, every model deployed on the microcontroller by Keil.
<p align="center">
  <img src="https://github.com/ms140429/pfNDM/blob/main/1_Software_code/flow.jpg"  width="500px"/>
</p>

<p align="center">
  <img src="https://github.com/ms140429/pfNDM/blob/main/1_Software_code/overall.png"  width="350px"/>
  <img src="https://github.com/ms140429/pfNDM/blob/main/1_Software_code/idle.png"  width="350px"/>
</p>

The left figure shows the current and voltage of the system at the full running state, and the right figure shows the current and voltage of the system at idle state. According to the current and voltage, the algorithm power can be calculated as 27 mW.

# Experience result
## Estimation and Decoupling
The first figure is the estimation result and the ground truth, the first row of the second figure is the decoupling result of NDM, and the second row of the second figure is the decoupling result of pfNDM.
<p align="center">
  <img src="https://github.com/ms140429/pfNDM/blob/main/1_Software_code/pred1.png"/>
  <img src="https://github.com/ms140429/pfNDM/blob/main/1_Software_code/decouple1.png" />
</p>

## Compared with state-of-the-art methods.
<div align="center">
  <img src="https://github.com/ms140429/pfNDM/blob/main/1_Software_code/comparsion.jpg" width="450px"/>
</div>

## The RAM and FLASH occupations
<div align="center">
  
| **Model**    | **RAM**           | **FLASH**          |
|:------------:|:-----------------:|:------------------:|
| f_01    | 0.416 KB          | 0.416 KB           |
| f_02     | 0.416 KB          | 10.69 KB           |
| f_u        | 0.384 KB          | 29.66 KB           |
| f_x        | 0.384 KB          | 9.19 KB            |
| f_y        | 0.208 KB          | 0.768 KB           |
| **Total** | **1.808 KB** | **50.724 KB** |

</div>

# Citation
```
@ARTICLE{Liao23Explainable,
  author={Xinyuan Liao and Shaowei Chen and Yunxiang Long and Shuai Zhao},
  title={Explainable Neural Dynamics Models for Motor Temperature Prediction}, 
  year={2023},
  pages={1-9},
  doi={10.36227/techrxiv.24555889}}
```
