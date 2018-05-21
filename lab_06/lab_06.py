from math import *
from scipy.optimize import *
import numpy
import time

EPS = 1e-6

def legandra(t):
    temp1 = 1
    temp2 = t
    
    for i in range(2, N + 1):
        cur = 1 / i * ((2 * i - 1) * t * temp2 - (i - 1) * temp1)
        temp2, temp1 = cur, temp2
    return cur

def dichotomy_method(a, b):
    return bisect(legandra, a, b, xtol = EPS)

def legandra_roots(N):
    # ищем отрезки с корнями
    h = 2 / N
    count_root = 0
    while (count_root != N):
        cur = -1
        count_root = 0
        SEGMENT = []
        while (cur < 1):
            if legandra(cur) * legandra(cur + h) < 0:
                SEGMENT.append([cur, cur + h])
                count_root += 1
            cur += h
        h /= 2

    # ищем корни
    ROOT = []
    for seg in SEGMENT:
        ROOT.append(dichotomy_method(seg[0], seg[1]))

    return ROOT            

'''
N = 300
t1 = time.clock()
r = legandra_roots(N)
t2 = time.clock()

print(r)
print('Время поиска корней полинома Лежандра (секунды) = ', t2 - t1)

'''

def f(x):
    return (1 / sqrt(2*pi))*exp(-x**2/2)
    #return x**9- x**5

def x_new(x, a, b):
    return (b - a)/2 * x + (b + a)/2

def fill_T(N, ROOT):
    T = [[0]*N for x in range(N)]
    for k in range(N):
        for h in range(N):
            T[k][h] = ROOT[h]**k
    return T

def fill_B(N):
    B = [0]*N
    for k in range(N):
        if (k % 2) == 0:
            B[k] = 2 / (k + 1)
    return B

def find_A(N, ROOT):
    # зполнение матрицы уравнения
    T = fill_T(N, ROOT)
    
    # заполнение векора столбца для уравнения            
    B = fill_B(N)
    
    # решить систему
    q1 = numpy.array(T)
    q2 = numpy.array(B)
    A = numpy.linalg.solve(q1, q2)
    return A

def solve_inegral(a, b, N):
    ROOT = legandra_roots(N)
    A = find_A(N, ROOT)
    # Собрать наш интегарл
    I = 0
    for k in range(N):
        I += A[k]*f(x_new(ROOT[k], a, b))
    I *= (b - a) / 2
    return I

def function(x):
    I = solve_inegral(0, x, N)
    #print(x, "x")
    #print(I, "I")
    #print(I - alpha)
    return I - alpha

print("N :")
N = int(input())
#N = 40
print("alpha :")
alpha = float(input())
'''
print("x :")
x = float(input())
'''
res = bisect(function, 0, 50, xtol = EPS)#пол. деления
print(res,  "result")

'''

N = 
a = 0
b = 100
I = solve_inegral(a, b, N)
print(I)
'''
