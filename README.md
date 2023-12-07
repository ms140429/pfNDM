![Static Badge](https://img.shields.io/badge/Language-C-green)
![Static Badge](https://img.shields.io/badge/Language-Python-green)
![Static Badge](https://img.shields.io/badge/Platform-Win_Mac-pink)
![GitHub all releases](https://img.shields.io/github/downloads/ms140429/Explainable-Neural-Dynamics-Model/total)
# Explainable Neural Dynamics Models for Motor Temperature Prediction
This repository includes the code for the paper "[Explainable Neural Dynamics Models for Motor Temperature Prediction](https://www.techrxiv.org/articles/preprint/Explainable_Neural_Dynamics_Models_for_Motor_Temperature_Prediction/24555889)".
<p align="center">
  <img src="https://github.com/ms140429/Explainable_Neural_Dynamics_Model/blob/main/1_Software_code/frame2.png" width="900px"/>
</p>

# Abstract
The permanent magnet synchronous motor finds extensive use in industrial applications, and the development of effective thermal management solutions is crucial to enhance its power density. Accurate temperature prediction of the permanent magnet synchronous motor serves as the fundamental basis for designing effective thermal management strategies. Model-based prediction methods exhibit superior real-time performance, but the intricate modeling process requires substantial expert knowledge guidance and lacks versatility. Conversely, data-driven prediction methods, while offering flexibility, often lack physical implications in terms of system dynamics. This paper proposed a structured linear neural dynamics model for motor temperature prediction. This model is data-driven, with prior knowledge integrated into its structure, which preserves flexibility while guaranteeing system stability through the Perron-Frobenius theorem. Additionally, this paper achieves the decoupling of control input from state transitions and the embedded deployment of this model. The method is validated with a real dataset. The lightweight feature is demonstrated by the implementation of an STM32 Microcontroller with 1.808 KB and 27 mW.

# Quick start
## Dataset
Download the dataset from this [website](https://www.kaggle.com/wkirgsn/electric-motor-temperature) and put it into the [Data](https://github.com/ms140429/Explainable-Neural-Dynamics-Model/tree/main/1_Software_code/Data) folder **firstly**!
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
Detailed instructions for hardware deployment can be found [**here**](https://github.com/ms140429/Explainable-Neural-Dynamics-Model/blob/main/2_Hardware_Implementation/README.md).:hammer::hammer:
<p align="center">
  <img src="https://github.com/ms140429/Explainable_Neural_Dynamics_Model/blob/main/2_Hardware_Implementation/flow.png"  width="500px"/>
</p>

<p align="center">
  <img src="https://github.com/ms140429/Explainable_Neural_Dynamics_Model/blob/main/2_Hardware_Implementation/1.png"  width="700px"/>
</p>

 More details can be found in the accompanying [**video**](https://github.com/ms140429/Explainable-Neural-Dynamics-Model/blob/main/Hardware_demonstration.mp4).

# Experience result
## Prediction
<p align="center">
  <img src="https://github.com/ms140429/Explainable-Neural-Dynamics-Model/blob/main/1_Software_code/pred1.png"/>
</p>

## Compared with state-of-the-art methods.

| **Method**                                          | **MSE ($K^2$)** | **Model size** |
|:---------------------------------------------------:|:---------------:|:--------------:|
| LPTN [1]          | 3.64            | **34**      |
| CNN  [2]      | 1.52            | 67k            |
| RNN  [2]   | 3.02            | >850k        |
| TCN  [3]    | 1.72            | >320k        |
| ET   [4]  | 6.51            | 5.5M           |
| TNN  [5]    | 2.87            | 1525           |
| NDM (Proposed)                                      | 1.43            | 12.9k          |
| pfNDM (Proposed)                                    | **0.903**  | 15.2k          |

## Decoupling
<p align="center">
  <img src="https://github.com/ms140429/Explainable-Neural-Dynamics-Model/blob/main/1_Software_code/decouple1.png" />
</p>

## The RAM and FLASH occupations

| **Model**    | **RAM**           | **FLASH**          |
|:------------:|:-----------------:|:------------------:|
| $f_{01}$     | 0.416 KB          | 0.416 KB           |
| $f_{02}$     | 0.416 KB          | 10.69 KB           |
| $f_u$        | 0.384 KB          | 29.66 KB           |
| $f_x$        | 0.384 KB          | 9.19 KB            |
| $f_y$        | 0.208 KB          | 0.768 KB           |
| **Total** | **1.808 KB** | **50.724 KB** |

# Reference
[1] Wallscheid, Oliver, and Joachim Böcker. "Global identification of a low-order lumped-parameter thermal network for permanent magnet synchronous motors." IEEE Transactions on Energy Conversion 31.1 (2015): 354-365.

[2] Kirchgässner, Wilhelm, Oliver Wallscheid, and Joachim Böcker. "Deep residual convolutional and recurrent neural networks for temperature estimation in permanent magnet synchronous motors." 2019 IEEE International Electric Machines & Drives Conference (IEMDC). IEEE, 2019.

[3] Kirchgässner, Wilhelm, Oliver Wallscheid, and Joachim Böcker. "Estimating electric motor temperatures with deep residual machine learning." IEEE Transactions on Power Electronics 36.7 (2020): 7480-7488.

[4] Kirchgässner, Wilhelm, Oliver Wallscheid, and Joachim Böcker. "Data-driven permanent magnet temperature estimation in synchronous motors with supervised machine learning: A benchmark." IEEE Transactions on Energy Conversion 36.3 (2021): 2059-2067.

[5] Kirchgässner, Wilhelm, Oliver Wallscheid, and Joachim Böcker. "Thermal neural networks: Lumped-parameter thermal modeling with state-space machine learning." Engineering Applications of Artificial Intelligence 117 (2023): 105537.
# Citation
```
@ARTICLE{Liao23Explainable,
  author={Xinyuan Liao and Shaowei Chen and Yunxiang Long and Shuai Zhao},
  title={Explainable Neural Dynamics Models for Motor Temperature Prediction}, 
  year={2023},
  pages={1-9},
  doi={10.36227/techrxiv.24555889}}
```
