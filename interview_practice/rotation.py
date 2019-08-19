import cv2
import os
import sys
import numpy as np



img= cv2.imread("/idiap/home/amartinez/cpm-dependencies.png")
img= cv2.resize(img, (368, 368))

N=img.shape[0]

for i in range(N):
    for j in range(i, N-i):
        temp= img[N-1-j, i].copy()
        img[N-1-j, i]= img[i,j].copy()

        temp2= img[N-1-i, N-1-j].copy()
        img[N-1-i, N-1-j]= temp.copy()

        temp= img[j, N-1-i].copy()
        img[j, N-1-i]= temp2.copy()

        img[i,j]= temp.copy()
        


cv2.imshow("Original", img)
cv2.waitKey()








