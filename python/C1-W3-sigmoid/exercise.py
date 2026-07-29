import numpy as np
import matplotlib.pyplot as plt
from utils import *
import copy
import math
from public_tests import *
def sigmoid(z):
    return 1/(1+np.exp(-z))

def compute_cost(X,y,w,b,lambda_=1):
    cost=0.0
    m,n=X.shape
    sum_w=0.0
    for i in range(m):
        f_wb=sigmoid(np.dot(X[i],w)+b)
        cost+=-y[i]*np.log(f_wb)-(1-y[i])*np.log(1-f_wb)
    for i in range(n):
        sum_w+=w[i]**2
    sum_w*=lambda_/2
    cost+=sum_w
    cost/=m
    return cost
    
def compute_gradient(X,y,w,b,lambda_=0):
    m,n=X.shape
    dj_dw=np.zeros(n)
    dj_db=0.0
    for i in range(m):
        f_wb=sigmoid(np.dot(X[i],w)+b)
        err=f_wb-y[i]
        for j in range(n):
            dj_dw[j]+=err*X[i,j]
        dj_db+=err
    for i in range(n):
        dj_dw[i]+=lambda_*w[i]
    dj_dw/=m
    dj_db/=m
    return dj_db,dj_dw
    
def gradient_descent(X,y,w_in,b_in,cost_function,gradient_function,alpha,iterations,lambda_):
    J_history=[]
    w_history=[]
    m,n=X.shape
    w=copy.deepcopy(w_in)
    b=b_in
    for i in range(iterations):
        dj_db,dj_dw=gradient_function(X,y,w,b,lambda_)
        w-=alpha*dj_dw
        b-=alpha*dj_db
        if(i<100000):
            J_history.append(cost_function(X,y,w,b,lambda_))
        if(i%(math.ceil(iterations/10))==0 or i==iterations-1):
            w_history.append(w)
            print(f"Iterations {i:5d}:Cost {J_history[-1]:8.2f}")
    return w,b,J_history,w_history
    
def predict(X,w,b):
    m,n=X.shape
    y_pred=np.zeros(m)
    for i in range(m):
        f_wb=sigmoid(np.dot(X[i],w)+b)
        if(f_wb>=0.5):
            y_pred[i]=1
        else:
            y_pred[i]=0
    return y_pred        
    
    

X_train, y_train = load_data("data/ex2data2.txt")
print("Original shape of data:", X_train.shape)

mapped_X =  map_feature(X_train[:, 0], X_train[:, 1])
print("Shape after feature mapping:", mapped_X.shape)


X_mapped = map_feature(X_train[:, 0], X_train[:, 1])
np.random.seed(1)
initial_w = np.random.rand(X_mapped.shape[1]) - 0.5
initial_b = 0.5
lambda_ = 0.5
cost = compute_cost(X_mapped, y_train, initial_w, initial_b, lambda_)

print("Regularized cost :", cost)

# UNIT TEST    
compute_cost_reg_test(compute_cost)


X_mapped = map_feature(X_train[:, 0], X_train[:, 1])
np.random.seed(1) 
initial_w  = np.random.rand(X_mapped.shape[1]) - 0.5 
initial_b = 0.5
alpha=0.01
lambda_ = 0.5
dj_db, dj_dw = compute_gradient(X_mapped, y_train, initial_w, initial_b, lambda_)

print(f"dj_db: {dj_db}", )
print(f"First few elements of regularized dj_dw:\n {dj_dw[:4].tolist()}", )

# UNIT TESTS    
compute_gradient_reg_test(compute_gradient)

lambda_=0.01
iterations=10000
w,b, J_history,_ = gradient_descent(X_mapped, y_train, initial_w, initial_b, 
                                    compute_cost, compute_gradient, 
                                    alpha, iterations, lambda_)

plot_decision_boundary(w, b, X_mapped, y_train)

p=predict(X_mapped,w,b)
print(f"Accuracy: {np.mean(p==y_train)*100:4.2f}")

