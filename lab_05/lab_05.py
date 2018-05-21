from math import *
from scipy.optimize import *
import numpy

EPS = 1e-12

v = -1
x = [-1, -1, -100, -120, -140]
z = [0, 1, 2, 3, 4]
E = [12.13, 21.2, 32.1, 45, 57] 

#     v   x1  x2  x3  x4  x5
J = [[1, -1,  1,  0,  0,  0],
     [1,  0, -1,  1,  0,  0],
     [1,  0,  0, -1,  1,  0],
     [1,  0,  0,  0, -1,  1],
     [0,  0,  0,  0,  0,  0],
     [0,  0,  0,  0,  0,  0]]

F = [0] * 6

P = 5
T = 14000

def gamma(g):
    summ = 0
    for i in range(1, 5):
        summ += (exp(x[i]) * z[i]**2) / (1 + z[i]**2 * g / 2)
        
    return g**2 - 5.87 * 1e+10 / T**3 * (exp(v) / (1 + g/2) + summ)

print(gamma(10))

def dichotomy_method(a, b):
    g = bisect(gamma, a, b, xtol = EPS)#, maxiter = 100000)
    return g

def dE(i):
    dE = 8.61 * 1e-5 * T * log((1 + z[i + 1] **2 * g/2) * (1 + g/2) / (1 + z[i]**2 * g/2))
    return dE
    
def K(i):
    #print(Q[i+1], Q[i], T**(3/2), exp((-E[i] + dE(i)) * 11606 / T), (-E[i] + dE(i)) * 11606 / T)
    k = 2 * 2.415 * 1e-3 * (Q[i+1] / Q[i]) * T**(3/2) * exp((-E[i] + dE(i)) * 11606 / T)
    return k

def Qu(T): 
    if (T <= 4000): 
        Q = [1, 4.05, 5.15, 6, 7]
    elif (T <= 8000):
        Q = [1, 4.30, 5.98, 6, 7]
    elif (T <= 10000):
        Q = [1.0025, 4.44, 6.47, 7, 8]
    elif (T <= 12000):
        Q = [1.020, 4.57, 6.96, 7.5, 8]
    elif (T <= 14000):
        Q = [1.0895, 4.65, 7.41, 8, 9]
    return Q

def nach_znach():
    
    print("de")
    k = K(1)
    print("k = ",k)

    var1 = (- k  + sqrt(k *k  + k * 7242 * P / T))
    print(var1, "var1")
    #if (var1 <=0):
    #    var1 = (- 2 * k  - sqrt(4 * k *k  + 4 * k * 7.242 / T)) / 2
    
    v = log(var1)
    var2 = 7242 * P / T - 2 * var1
    print(var2, "var2")
    x1 = log(var2)
    x2 = v
    return v, x1, x2

def print_matrix(A):
    n = len(A)
    print()
    for i in range(n):
        for j in range(n):
            print("{:6.7f}".format(A[i][j]))#, #end = ' ')
        print()
    print()
        

def fill_jacobi():
    # 5 строка
    J[4][0] = -exp(v)
    for k in range (1, 6):
        J[4][k] = -exp(x[k - 1]) 

    # 6 строка
    J[5][0] = -J[4][0]
    for k in range (2, 6):
        J[5][k] = -z[k - 1] * exp(x[k - 1])
    
    return J

def fill_F():
    alpha = 0.285 * 1e-11 * (g * T)**3
    
    for i in range(4):
        F[i] = - (v + x[i+1] - x[i] - log(K(i)))

    F[4] = -(P * 7.242 * 1e+3 / T - exp(v) - exp(x[0]) - exp(x[1]) - exp(x[2]) - exp(x[3]) - exp(x[4]) + alpha)
    F[5] = -(exp(v) - z[1] * exp(x[1]) - z[2] * exp(x[2]) - z[3] * exp(x[3]) - z[4] * exp(x[4]))
    return F

def abs_max(dX, v, X):
    indx = 0
    max_item = abs(dX[0] / v)
    for i in range(1, len(dX)):
        if (abs(dX[i] / X[i - 1]) > max_item):
            indx = i
            max_item = abs(dX[i] / X[i - 1])
    return max_item

def solve_nonlinear_system():
    global J, F, g, v, x, z, E
    while True:
        g = dichotomy_method(0, 3)
        print("\ngamma = ", g)
        print(K(1))
        print_matrix(J)
        J = fill_jacobi()
        print_matrix(J)
        
        F = fill_F()
        print(F)
        q1 = numpy.array(J)
        q2 = numpy.array(F)
        res = numpy.linalg.solve(q1, q2)
        print(res)
        
        # корректировка результатов
        v += res[0]
        for i in range(5):
            x[i] += res[i + 1]
        
        if abs_max(res, v, x) < EPS :
            break
    g = dichotomy_method(0, 3)
        
'''
print("ввод\n")
print("давление: ")
P = float(input())
print("температура: ")
T = float(input())
'''
print(15/1.38, "232323")
Q = Qu(T)
g = dichotomy_method(0, 1)
v, x[0], x[1] = nach_znach()
#v, x[0], x[1] = nach_znach()
print("print v, x", v, x)
solve_nonlinear_system()
print("result")
print(v, x)
print(exp(v))
for k in range(len(x)):
    print(exp(x[k]))
print(g , "gamma")
