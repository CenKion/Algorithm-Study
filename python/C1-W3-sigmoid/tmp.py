import numpy as np
import matplotlib.pyplot as plt
import math,copy
from sklearn.linear_model import LinearRegression,LogisticRegression,SGDRegressor
from sklearn.preprocessing import StandardScaler
def sigmoid(z):
    return 1/(1+np.exp(-z))

def z_score_normalization(X):
    sig=np.std(X,axis=0)
    mu=np.mean(X,axis=0)
    X_norm=(X-mu)/sig
    return X_norm

def compute_cost_linear(X,y,w,b):
    cost=0.0
    m=X.shape[0]
    for i in range(m):
        cost+=(np.dot(X[i],w)+b-y[i])**2
    cost/=2*m
    return cost

def compute_gradient_linear(X,y,w,b):
    m,n=X.shape
    dj_dw=np.zeros(n)
    dj_db=0.0
    for i in range(m):
        err=np.dot(X[i],w)+b-y[i]
        for j in range(n):
            dj_dw[j]+=err*X[i,j]
        dj_dw+=err
    dj_dw/=m
    dj_db/=m
    return dj_dw,dj_db

def compute_cost_logistic(X,y,w,b):
    m,n=X.shape
    cost=0.0
    for i in range(m):
        f_wb=sigmoid(np.dot(X[i],w)+b)
        cost+=-y[i]*(np.log(f_wb))-(1-y[i])*(np.log(1-f_wb))
    cost/=m
    return cost

def compute_gradient_logistic(X,y,w,b):
    m,n=X.shape
    dj_dw=np.zeros(n)
    dj_db=0.0
    for i in range(m):
        f_wb=sigmoid(np.dot(X[i],w)+b)
        err=f_wb-y[i]
        for j in range(n):
            dj_dw[j]+=err*X[i,j]
        dj_db+=err
    dj_dw/=m
    dj_db/=m
    return dj_dw,dj_db
def gradient_descent(X,y,w_in,b_in,compute_cost,compute_gradient,alpha=0.001,iterations=10000):
    J_history=[]
    m,n=X.shape
    w=copy.deepcopy(w_in)
    b=b_in
    for i in range(iterations):
        dj_dw,dj_db=compute_gradient(X, y, w, b)
        w-=dj_dw*alpha
        b-=dj_db*alpha
        if(i<10000):
            J_history.append(compute_cost(X, y, w, b))
        if(i%(math.ceil(iterations/10))==0):
            print(f"Iterations {i:4d}:Cost {J_history[-1]:0.2f}")
    return w,b,J_history

def compute_cost_linear_reg(X,y,w,b,lambda_=1):
    cost=0.0
    sum_w=0.0
    m,n=X.shape
    for i in range(n):
        sum_w+=w[i]**2
    for i in range(m):
        cost+=(np.dot(X[i],w)+b-y[i])**2
    sum_w*=lambda_
    cost+=sum_w
    cost/=2*m
    return cost

def compute_cost_logistic_reg(X,y,w,b,lambda_=1):
    cost=0.0
    m,n=X.shape
    sum_w=0.0
    for i in range(n):
        sum_w+=w[i]**2
    for i in range(m):
        f_wb=sigmoid(np.dot(X[i],w)+b)
        cost+=-y[i]*np.log(f_wb)-(1-y[i])*np.log(1-f_wb)
    sum_w=sum_w*lambda_/2
    cost+=sum_w
    cost/=m
    return cost

def compute_gradient_logistic_reg(X,y,w,b,lambda_=1):
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

np.random.seed(1)
X_tmp=np.random.rand(5,3)
y_tmp=np.array([0,1,0,1,0])
w_tmp=np.random.rand(3)
b_tmp=0.5
lambda_tmp=0.7
dj_db,dj_dw=compute_gradient_logistic_reg(X_tmp,y_tmp,w_tmp,b_tmp,lambda_tmp)
print(f"dj_db: {dj_db}", )
print(f"Regularized dj_dw:\n {dj_dw.tolist()}", )


















