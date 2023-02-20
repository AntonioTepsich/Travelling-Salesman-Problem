
import numpy as np
import matplotlib.pyplot as plt

def progres():
  progreso = np.loadtxt(fname='progreso.csv', delimiter= ',')

  x=[]
  y=[]

  for i in range(len(progreso)):
    for j in range(2):
      if j==0:
        x.append(progreso[i][j])
      else:
        y.append(progreso[i][j])

  plt.plot(x,y)
  plt.plot(x[0],y[0],marker='.',markerfacecolor='yellow',markersize=10)
  plt.plot(x[-1],y[-1],marker='.',markerfacecolor='yellow',markersize=10)
  plt.xlabel('INTERACIONES')
  plt.ylabel('DISTANCIA')
  plt.title('Evolucion de la mejor ruta')

  plt.annotate(y[0], (x[0] + 8, y[0]))
  plt.annotate(y[-1], (x[-1]-40, y[-1]+ 2))

  plt.legend()
  plt.savefig('Progreso.png',dpi=100,bbox_inches="tight")
  plt.show()

def main():
  progres()
main()


