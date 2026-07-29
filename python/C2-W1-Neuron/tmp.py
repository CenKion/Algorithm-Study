import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
import matplotlib.pyplot as plt
from autils import *

import logging
logging.getLogger("tensorflow").setLevel(logging.ERROR)
tf.autograph.set_verbosity(0)

def my_dense(a_in,W,b,g):
    units=W.shape[1]
    a_out=np.zeros(units)
    for i in range(units):
        a_out[i]=g(np.dot(W[:,i],a_in)+b[i])
    return a_out

def my_sequential(x,W1,b1,W2,b2,W3,b3):
    a1=my_dense(x,W1,b1,sigmoid)
    a2=my_dense(a1,W2,b2,sigmoid)
    a3=my_dense(a2,W3,b3,sigmoid)
    return a3

X, y = load_data()


print ('The first element of X is: ', X[0])

print ('The first element of y is: ', y[0,0])
print ('The last element of y is: ', y[-1,0])

print ('The shape of X is: ' + str(X.shape))
print ('The shape of y is: ' + str(y.shape))

model=Sequential(
    [
     tf.keras.Input(shape=(400,)),
     Dense(25,activation="sigmoid"),
     Dense(15,activation="sigmoid"),
     Dense(1,activation="sigmoid"),
     ],name="my_model"
)
model.summary()

model.compile(
    loss=tf.keras.losses.BinaryCrossentropy(),
    optimizer=tf.keras.optimizers.Adam(learning_rate=0.001)    
)

model.fit(
    X,y,
    epochs=20
    
)

[layer1,layer2,layer3]=model.layers

W1_tmp,b1_tmp=layer1.get_weights()
W2_tmp,b2_tmp=layer2.get_weights()
W3_tmp,b3_tmp=layer3.get_weights()

m,n=X.shape


fig,axes=plt.subplots(8,8,figsize=(8,8))
fig.tight_layout(pad=0.1,rect=[0,0.03,1,0.92])

for i,ax in enumerate(axes.flat):
    random_index=np.random.randint(m)
    X_random_reshaped=X[random_index].reshape(20,20).T
    ax.imshow(X_random_reshaped,cmap="gray")
    prediction1=model.predict(X[random_index].reshape((1,400)))
    prediction2=my_sequential(X[random_index],W1_tmp,b1_tmp,W2_tmp,b2_tmp,W3_tmp,b3_tmp)
    yhat1=int(prediction1>=0.5)
    yhat2=int(prediction2>=0.5)
    ax.set_title(f"{y[random_index,0]},{yhat1},{yhat2}")
    ax.set_axis_off()
fig.suptitle("label,yhat1,yhat2")
plt.show()
    
