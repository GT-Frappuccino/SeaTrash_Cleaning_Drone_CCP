C:\Users\heesu\PycharmProjects\CCP_detection\trash_detect


# Python Interpreter requirement
pillow
requests
jupyter
numpy
pandas
matplotlib
seaborn
graphviz
Cython
Opencv

# dataset
download Dataset by download.py
C:\Users\heesu\PycharmProjects\CCP_detection\trash_detect\Detect\data
There are images in batch1~15, and they are classified into train, val, test whose formats are .json

# model
mask_rcnn_coco.h5 is created by running model.py

# How to run detector.py

python detector.py evaluate --model=coco --dataset=C:\Users\heesu\PycharmProjects\CCP_detection\trash_detect\Detect\data --class_map=C:\Users\heesu\PycharmProjects\CCP_detection\trash_detect\Detect\detector\taco_config\map_17.csv --round=0

type them in Terminal

option of command: trained evaluate test
model: coco 
dataset: path to data
round: 0
