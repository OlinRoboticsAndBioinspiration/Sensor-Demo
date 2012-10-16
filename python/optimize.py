import numpy as np

import scipy.optimize

def get_point(x):
  print x
  y = raw_input();
  return float(y);

x0 = [3000, 3000]
res = scipy.optimize.fmin(get_point, x0, disp=True, maxfun=5);
print res
