import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow.keras.layers import Dense, Input
from tensorflow.keras import Sequential
from tensorflow.keras.losses import MeanSquaredError, BinaryCrossentropy
from tensorflow.keras.activations import sigmoid
from lab_utils_common import dlc
from lab_neurons_utils import plt_prob_1d, sigmoidnp, plt_linear, plt_logistic
plt.style.use('./deeplearning.mplstyle')
import logging
logging.getLogger("tensorflow").setLevel(logging.ERROR)
tf.autograph.set_verbosity(0)


X_train = np.array([0., 1, 2, 3, 4, 5], dtype=np.float32).reshape(-1,1)
Y_train = np.array([0,  0, 0, 1, 1, 1], dtype=np.float32).reshape(-1,1)

pos= Y_train==1
neg= Y_train==0

fig,ax=plt.subplots(1,1,figsize=(4,3))
ax.scatter(X_train[pos],Y_train[pos],marker='x',c='red',s=100,label="y=1")
ax.scatter(X_train[neg],Y_train[neg],marker='o',s=80,label="y=0",facecolors='none',edgecolors=dlc["dlblue"],lw=3)

ax.legend()
ax.set_ylim(-0.08,1.1)
ax.set_xlabel("X_train")
ax.set_ylabel("Y_train")
ax.set_title("one variable plot")
plt.show()

model=Sequential(
    [
     tf.keras.layers.Dense(1,input_dim=1,activation="sigmoid",name="L1")
     ]
)
model.summary()

logistic_layer=model.get_layer("L1")
w,b=logistic_layer.get_weights()

set_w=np.array([[2]])
set_b=np.array([-4.5])
logistic_layer.set_weights([set_w,set_b])
print(logistic_layer.get_weights())

a1=model.predict(X_train[0].reshape(1,1))
print(a1)
alog = sigmoidnp(np.dot(set_w,X_train[0].reshape(1,1)) + set_b)
print(alog)

plt_logistic(X_train, Y_train, model, set_w, set_b, pos, neg)