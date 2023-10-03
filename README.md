# Structured Linear Neural Dynamics model
This repository includes the code for the paper "Explainable Neural Dynamics Models for Motor Temperature Prediction".
<p align="center">
  <img src="https://github.com/ms140429/explainable_Neural_Dynamics_Model/tree/main/1_Software_code/frame1.png" width="900px"/>
</p>

# Abstract
The permanent magnet synchronous motor finds extensive use in industrial applications, and the development of effective thermal management solutions is crucial to enhance its power density. Accurate temperature prediction serves as the fundamental basis for the design of effective thermal management strategies. Physics-based prediction methods exhibit superior real-time performance, but their intricate modeling process necessitates substantial expert knowledge guidance and lacks versatility. Conversely, data-driven prediction methods, while offering flexibility, often lack guarantees regarding the behavior of the systems. This paper proposed a structured linear neural dynamics model for motor temperature prediction. This model is data-driven, with a priori information integrated into its structure, which preserves flexibility while guaranteeing system stability through the Perron-Frobenius theorem. Additionally, this paper achieves the decoupling of control input from state transitions and the embedded implementation of this model on STM32. The model undergoes evaluation using a motor temperature dataset and demonstrates state-of-the-art prediction accuracy while maintaining a compact model size.

# Quick start
## Dataset
Download the dataset from this [website](https://www.kaggle.com/wkirgsn/electric-motor-temperature) and put it into the [Data](https://github.com/ms140429/explainable_Neural_Dynamics_Model/tree/main/1_Software_code/Data) folder **firstly**!
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
  <img src="https://github.com/ms140429/explainable_Neural_Dynamics_Model/tree/main/1_Software_code/pred.png" />
</p>

## Decoupling
<p align="center">
  <img src="https://github.com/ms140429/explainable_Neural_Dynamics_Model/tree/main/1_Software_code/decouple.png" />
</p>

# Citation
```
@artical{
}
```
