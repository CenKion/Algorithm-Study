import numpy as np
import matplotlib.pyplot as plt
plt.style.use('./deeplearning.mplstyle')
import tensorflow as tf
from lab_utils_common import dlc, sigmoid
from lab_coffee_utils import load_coffee_data, plt_roast, plt_prob, plt_layer, plt_network, plt_output_unit
import logging
logging.getLogger("tensorflow").setLevel(logging.ERROR)
tf.autograph.set_verbosity(0)

def my_dense(a_in,W,b,g):
    units=W.shape[1]
    a_out=np.zeros(units)
    for i in range(units):
        a_out[i]=g(np.dot(W[:,i],a_in)+b[i])
    return a_out
    
def my_sequential(x,W1,b1,W2,b2):
    a1=my_dense(x,W1,b1,sigmoid)
    a2=my_dense(a1,W2,b2,sigmoid)
    return a2

def my_predict(X,W1,b1,W2,b2):
    m=X.shape[0]
    p=np.zeros((m,1))
    for i in range(m):
        p[i,0]=my_sequential(X[i],W1,b1,W2,b2)
    return p


X,Y = load_coffee_data();


plt_roast(X,Y)


norm_l=tf.keras.layers.Normalization(axis=-1)
norm_l.adapt(X)
Xn=norm_l(X)
print(f"X mean:{np.mean(X,axis=0)}")
print(f"Xn mean:{np.mean(Xn,axis=0)}")

W1_tmp = np.array( [[-8.93,  0.29, 12.9 ], [-0.1,  -7.32, 10.81]] )
b1_tmp = np.array( [-9.82, -9.28,  0.96] )
W2_tmp = np.array( [[-31.18], [-27.59], [-32.56]] )
b2_tmp = np.array( [15.41] )

X_tst = np.array([
    [200,13.9],  # postive example
    [200,17]])
X_tstn=norm_l(X_tst)
predictions=my_predict(X_tstn,W1_tmp,b1_tmp,W2_tmp,b2_tmp)
yhat= (predictions>=0.5).astype(int)
print(f"decisions: {yhat}")

netf=lambda x:my_predict(norm_l(x),W1_tmp,b1_tmp,W2_tmp,b2_tmp)
plt_network(X,Y,netf)
