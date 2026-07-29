import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
import matplotlib.pyplot as plt
from autils import *

import logging
logging.getLogger("tensorflow").setLevel(logging.ERROR)
tf.autograph.set_verbosity(0)


X, y = load_data()


print ('The first element of X is: ', X[0])

print ('The first element of y is: ', y[0,0])
print ('The last element of y is: ', y[-1,0])

print ('The shape of X is: ' + str(X.shape))
print ('The shape of y is: ' + str(y.shape))

model = Sequential(                        
    [                                     
        tf.keras.Input(shape=(400,)),    # specify input size (optional)  
        Dense(25, activation='sigmoid'),   
        Dense(15, activation='sigmoid'),   
        Dense(1,  activation='sigmoid')    
    ], name = "my_model"                                      
)
model.summary()

[layer1,layer2,layer3]=model.layers

W1,b1=layer1.get_weights()
print(f"W1 shape: {W1.shape},b1 shape:{b1.shape}")

print(model.layers[2].get_weights())

model.compile(
    loss=tf.keras.losses.BinaryCrossentropy(),
    optimizer=tf.keras.optimizers.Adam(learning_rate=0.001),
    
)
model.fit(
    X,y,
    epochs=20
    
    )

m,n=X.shape
fig,axes=plt.subplots(8,8,figsize=(8,8))
fig.tight_layout(pad=0.1,rect=[0,0.03,1,0.92])
for i,ax in enumerate(axes.flat):
    random_index=np.random.randint(m)
    X_random_reshaped=X[random_index].reshape((20,20)).T
    ax.imshow(X_random_reshaped,cmap="gray")
    prediction=model.predict(X[random_index].reshape(1,400))
    if(prediction>=0.5):
        yhat=1
    else:
        yhat=0
    ax.set_title(f"{y[random_index,0]},{yhat}")
    ax.set_axis_off()
fig.suptitle("Label,yhat",fontsize=16)
plt.show()




