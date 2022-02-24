import pandas as pd
#import numpy as np
#import matplotlib.pyplot as plt
import turtle as t

def getCoord(r, n, df):
    for i in range(0,n):
        if df.iat[i,0]==r:
            result = [df.iat[i,5],df.iat[i,6]]
            print (result[0]," ", result[1]) #debug (working)
            return result

def calibrate(bbox, window, point):
    squale = 3
    
    xa = -window[0]/2
    xb = window[0]/2
    xc = bbox[0]
    xd = bbox[1]
    xp = point[0]

    ya = -window[1]/2
    yb = window[1]/2
    yc = bbox[2]
    yd = bbox[3]
    yp = point[1]

    x_mapmid = (bbox[0]+bbox[1])/2
    y_mapmid = (bbox[2]+bbox[3])/2

    x_mapcoef = (bbox[1]-bbox[0])/window[0]
    y_mapcoef = (bbox[3]-bbox[2])/window[1]

    x = (point[0]*x_mapcoef-x_mapmid)*squale
    y = (point[0]*y_mapcoef-y_mapmid)*squale
    
    #x = ((point[0]-bbox[2])*(window[0]/bbox[3]))/squale   -window[0]/2)
    #y = ((point[1]-bbox[0])*(window[1]/bbox[1]))/squale   -window[1]/2)
    #x = ((point[0]-bbox[2])*(window[0]/bbox[3]))-3300
    #y = ((point[1]-bbox[0])*(window[1]/bbox[1]))+500
    #x = ((point[0]-bbox[0])/(bbox[1]-bbox[0]))*((-window[0]/2)*(window[0]/2))
    #y = ((point[1]-bbox[2])/(bbox[3]-bbox[2]))*((-window[1]/2)*(window[1]/2))

    #blubb = point[0]*(((window[0]/2)-(-window[0]/2))/100)
    #x = blubb*(bbox[1]-bbox[0])

    #blubb = point[1]*(((window[1]/2)-(-window[1]/2))/100)
    #y = blubb*(bbox[3]-bbox[2])

    #xratio = (xp-xc)/(xd-xc)
    #x = xratio*(xa-xb)+xa

    #yratio = (yp-yc)/(yd-yc)
    #y = yratio*(ya-yb)+ya
    
    result = [x, y]
    return result
    


df = pd.read_excel(r'../data/communes.xlsx')

#print (df.iat[0,5])
#print (df.iat[1,5])
#print (df.iat[0,6])
#print (df.iat[1,6])


window = [606, 569]
t.setup(window[0], window[1])
t.bgpic("france.png")

filin = open("result.txt", "r")
lines = filin.readlines()
n = len(lines)

bbox =  [-5.625, 9.602,  41.853, 51.618]

t.speed(0)
t.penup
t.color('red')
t.goto(calibrate(bbox, window, getCoord(0, n, df)))
t.pendown()
for i in range(1,n-1):
    t.goto(calibrate(bbox, window, getCoord(i, n, df)))
t.goto(calibrate(bbox, window, getCoord(0, n, df)))
t.done()



