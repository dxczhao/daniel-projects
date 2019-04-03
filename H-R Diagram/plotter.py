import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import matplotlib.colors
import matplotlib as mpl

def make_cmap(colors, position=None, bit=False):
    bit_rgb = np.linspace(0,1,256)
    if position == None:
        position = np.linspace(0,1,len(colors))
    else:
        if len(position) != len(colors):
            sys.exit("position length must be the same as colors")
        elif position[0] != 0 or position[-1] != 1:
            sys.exit("position must start with 0 and end with 1")
    if bit:
        for i in range(len(colors)):
            colors[i] = (bit_rgb[colors[i][0]],
                         bit_rgb[colors[i][1]],
                         bit_rgb[colors[i][2]])
    cdict = {'red':[], 'green':[], 'blue':[]}
    for pos, color in zip(position, colors):
        cdict['red'].append((pos, color[0], color[0]))
        cdict['green'].append((pos, color[1], color[1]))
        cdict['blue'].append((pos, color[2], color[2]))

    cmap = mpl.colors.LinearSegmentedColormap('my_colormap',cdict,256)
    return cmap

def plot_HR(temp, lum, plotfilename=''):
    ticker.rcParams['xtick.minor.size'] = 0
    ticker.rcParams['xtick.minor.width'] = 0

    fig = plt.figure()
    ax1 = fig.add_subplot(111)
    ax2 = ax1.twiny()
    ax3 = ax1.twinx()

    ax1.set_xlabel("Spectral Class")
    ax2.set_xlabel("Temperature (K)", labelpad = 15)
    ax1.set_ylabel("Absolute magnitude")
    ax3.set_ylabel("Luminosity {Relative to Sun)")
    ax2.set_xlim(2500, 35000)
    ax2.invert_xaxis()
    ax2.set_ylim(-10, 15)
    ax2.invert_yaxis()
    ax2.set_xscale('log')
    ax1.set_xlim(2500, 35000)
    ax1.invert_xaxis()
    ax1.set_ylim(-10, 15)
    ax1.invert_yaxis()
    ax1.set_xscale('log')
    ax3.set_ylim(-10, 15)

    ticks = np.array([2500, 3500, 5000, 6000, 7500, 10000, 25000, 35000]) #temperature boundaries for spectral type
    ax1.set_xticks(ticks)

    ticks = np.array([2950, 4190, 5500, 6720, 8670, 15800, 30000]) #specific values to center labels
    labels = np.array(["M", "K", "G", "F", "A", "B", "O"])

    ax1.xaxis.set_major_formatter(ticker.NullFormatter())
    ax1.xaxis.set_minor_locator(ticker.FixedLocator(ticks))
    ax1.xaxis.set_minor_formatter(ticker.FixedFormatter(labels))

    ticks = np.array([3000, 6000, 10000, 30000])
    labels = np.array(["3000", "6000", "10000", "30000"])

    ax2.set_xticks(ticks)
    ax2.set_xticklabels(labels)

    ticks = np.array([-5.259720399, -0.259720399, 4.740279601, 9.740279601]) #corrosponding magnitude values to luminosity
    labels = np.array(['0.01', '1', '100', '10000'])

    ax3.set_yticks(ticks)
    ax3.set_yticklabels(labels)

    #plt.title("H-R Diagram", pad = 30)
    ax1.set_facecolor('black')
    fig.patch.set_facecolor('#e6e6e6')

    colors = [(255,0,0), (255,0,0), (255,0,0), (255,0,0),
              (255, 225,110),
              (255,255,255),
              (235,235,255),
              (230,180,255),
              (0,0,255)] # This example uses the 8-bit RGB
    ### Call the function make_cmap which returns your colormap
    my_cmap = make_cmap(colors, bit=True)

    #ax1.scatter(temp, lum, c=temp, cmap=plt.cm.get_cmap('RdBu'), s=2)  #jet or viridis_r
    ax1.scatter(temp, lum, s=2,c=temp, cmap=my_cmap, norm=matplotlib.colors.LogNorm())
    if plotfilename=='':
        plt.show()
    return plt
    
