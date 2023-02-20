import numpy as np
import matplotlib.pyplot as plt


def recorrid():
  recorrido = np.loadtxt(fname='recorrido.csv', delimiter= ',')

  x=[]
  y=[]

  for i in range(len(recorrido)):
    for j in range(2):
      if j==0:
        x.append(recorrido[i][j])
      else:
        y.append(recorrido[i][j])

  x.append(recorrido[0][0])
  y.append(recorrido[0][1])

  plt.plot(x,y,marker='.', markersize=7,markerfacecolor='yellow')
  plt.xlabel('LONGITUD')
  plt.ylabel('LATITUD')
  plt.title('Ruta')
  for i in range (len(recorrido)):
    plt.annotate(i, (x[i] + 0.1, y[i]+ 0.1))
  plt.legend()
  plt.savefig('Recorrido.png',dpi=100,bbox_inches="tight")
  plt.show()

def main():
  recorrid()
main()


