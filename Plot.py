from pylab import *
import matplotlib.pyplot as plt
import numpy as np
import math as m

def file2List(File):
	Data = [];
	f = File.readlines()
	for line in f:
		Newline = line.split()
		Data.append(Newline)
	return Data


JacobiFile = open("Jacobi150.txt")
Jacobi = file2List(JacobiFile)
JacobiTime = []
JacobiMax = []
JacobiAverage = []


GaussFile = open("Gauss150.txt")
Gauss = file2List(GaussFile)
GaussTime = []
GaussMax = []
GaussAverage = []

LineFile = open("Line150.txt")
Line = file2List(LineFile)
LineTime = []
LineMax = []
LineAverage = []


for oneline in Jacobi:
	JacobiTime.append(oneline[0])
	JacobiMax.append(m.log(float(oneline[1])))
	
for oneline in Gauss:
	GaussTime.append(oneline[0])
	GaussMax.append(m.log(float(oneline[1])))

for oneline in Line:
	LineTime.append(oneline[0])
	LineMax.append(m.log(float(oneline[1])))


plt.figure()
JacobiLine, = plt.plot(JacobiTime,JacobiMax,label="Jacobi")
GaussLine,=plt.plot(GaussTime,GaussMax,label = "Gauss")
LineLine,=plt.plot(LineTime,LineMax,label = "Line")

plt.legend(handles = [JacobiLine,GaussLine,LineLine])
plt.show()

