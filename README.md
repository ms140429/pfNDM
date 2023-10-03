# Structured Linear Neural Dynamics model
This repository includes the code for the paper "Explainable Neural Dynamics Models for Motor Temperature Prediction".
<p align="center">
  <img src="https://github.com/XinyuanLiao/NDM/blob/main/frame1.png" width="900px"/>
</p>

# Abstract
The permanent magnet synchronous motor finds extensive use in industrial applications, and the development of effective thermal management solutions is crucial for enhancing its power density. Accurate temperature prediction serves as the fundamental basis for devising effective thermal management strategies. Prediction methods grounded in the heat conduction model exhibit superior real-time performance, but their intricate modeling process necessitates substantial expert knowledge guidance and may lack versatility. Conversely, prediction methods based on artificial intelligence, while offering flexibility, often lack guarantees regarding the behavior of the systems. This paper proposed a structured linear neural dynamics model for motor temperature prediction. This model is data-driven, with a priori information integrated into its structure. It preserves the flexibility of general data-driven models while guaranteeing system stability through the Perron-Frobenius theorem. Additionally, by leveraging the decoupling properties of the linear state-space model, this paper achieves the decoupling of state transitions from control inputs. The model undergoes evaluation using a motor temperature dataset and demonstrates state-of-the-art prediction accuracy while maintaining a compact model size.

# Quick start
## Dataset
Download the dataset from this [website](https://www.kaggle.com/wkirgsn/electric-motor-temperature) and put it into the [Data](https://github.com/ms140429/explainable_Neural_Dynamic_Model/tree/main/1_Software_code/Data) folder **firstly**!
## Configuration
```
pip install -r requirements.txt
```
## Run
```
python Train.py
```
# Experience result
## Prediction
<p align="center">
  <img src="https://github.com/ms140429/explainable_Neural_Dynamic_Model/tree/main/1_Software_code/pred.png" />
</p>

## Decoupling
<p align="center">
  <img src="https://github.com/ms140429/explainable_Neural_Dynamic_Model/tree/main/1_Software_code/decouple.png" />
</p>

# Citation
```
@artical{
}
```
