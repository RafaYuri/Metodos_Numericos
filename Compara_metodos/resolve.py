import numpy as np
import numpy.linalg as npla
import time
import matplotlib.pyplot as plt

# size of the matrix to be calculated
SIZE = [10,50,100,1000]

# create list
cpu_time_numpy = []
cpu_time_mycode = []

# define seed 
np.random.seed(10)

# loop over the size
for size in SIZE :
  # create the system
  A = np.random.rand(size,size)
  f = np.random.rand(size)
  # nummpy
  t0 = time.process_time()
  w=npla.solve(A,f)
  cpu_time_numpy.append(time.process_time()-t0)
  
print(cpu_time_numpy)
