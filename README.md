# Structured Linear Neural Dynamics model
This repository includes the code for the paper "Explainable Neural Dynamics Models for Motor Temperature Prediction".
<p align="center">
  <img src="https://github.com/ms140429/Explainable_Neural_Dynamics_Model/blob/main/1_Software_code/frame2.png" width="900px"/>
</p>

# Abstract
Accurate temperature prediction of the permanent magnet synchronous motor serves as the fundamental basis for designing effective thermal management strategies. Model-based prediction methods exhibit superior real-time performance, but their intricate modeling process necessitates substantial expert knowledge guidance and lacks versatility. Conversely, data-driven prediction methods, while offering flexibility, often lack physical implications in terms of system dynamics. This paper proposed a structured linear neural dynamics model for motor temperature prediction. This model is data-driven, with prior information integrated into its structure, which preserves flexibility while guaranteeing system stability through the Perron-Frobenius theorem. Additionally, this paper achieves the decoupling of control input from state transitions and the embedded deployment of this model. The method is validated with a real dataset. The lightweight feature is demonstrated by the implementation of an STM32 Microcontroller.

# Quick start
## Dataset
Download the dataset from this [website](https://www.kaggle.com/wkirgsn/electric-motor-temperature) and put it into the [Data](https://github.com/ms140429/Explainable_Neural_Dynamics_Model/tree/main/1_Software_code/Data) folder **firstly**!
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
# Experience result
## Prediction
<p align="center">
  <img src="https://github.com/ms140429/Explainable_Neural_Dynamics_Model/blob/main/1_Software_code/pred1.png" />
</p>

## Decoupling
<p align="center">
  <img src="https://github.com/ms140429/Explainable_Neural_Dynamics_Model/blob/main/1_Software_code/decouple1.png" />
</p>

# Citation
```
@artical{
}
```
