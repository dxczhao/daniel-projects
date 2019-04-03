import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from plotter1 import plot_HR
def load_data(source):
        if source=='nasa': df = pd.read_csv("data//nasa-data.csv")
        elif source=='wiki': df = pd.read_csv("data//wiki-data.csv")
        elif source=='combined': df = pd.read_csv("data//combined-data.csv")
        else: print("Wrong source")
        temp = df["Temperature (K)"].values
        lum = df["absolute-magnitude"].values
        return temp, lum

source='combined'

plotfilename = source + '-H-R-diagram.pdf'
temp,lum=load_data(source)
# if plotfilanme is given, save diagram as a PDF file
#plt = plot_HR(temp, lum, plotfilename)
print('Plotting H-R diagram...')
plt = plot_HR(temp,lum)


