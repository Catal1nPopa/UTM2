import math


#pow(e, -x) * sin(x) + 1

def f1(x):
    #return math.log10(2*x+3) + 2*x - 1
    return math.e(-x) * math.sin(x) + 1 

#--------------------------------------------

# fi (pentru medota aproximarilor)

def f1fi(x):
    #return (1 - math.log10(2*x+3))/2
     return math.e(-x) * math.sin(x) + 1

#-------------------------------------------

#f1 derivat si dublu derivat pentru metoda newton
def f1d(x):
    #return 2/(math.log(10)*(2*x+3)) + 2
     return (-math.sin(x) + math.cos(x))/(math.e(x))



def f1dd(x):
    #return -4/(math.log(10)*(2*x+3)**2)
     return (-math.sin(x) + math.cos(x))/math.e(x)

#---------------------------------------------


#x^3 + 9x - 3
def f2(x):
    return x**3 + 9*x - 3

#-----------------------------------------

# fi (pentru medota aproximarilor)
def f2fi(x):
    return (x**3-3)/(-9)


#-----------------------------------------
#f2 derivat si dublu derivat pentru metoda newton
def f2d(x):
    return 3*x**2 + 9 
def f2dd(x):
    return 6*x

#-----------------------------------------

#metoda injumatatirii intervalelor (bisectoarelor)
def bisect(func,a,b):
    x = a
    y = func(x)
    count=0
    if(func(a) * func(b) < 0):
        while(abs(y) > 10**(-2)):
            count+=1
            x = a+(b-a)/2
            y = func(x)
            if(func(a)*y < 0):
                b = x
            else:
                a = x 
    return x, count

#--------------------------------------------

#metoda aproximatiilor succesive
def aprox(func, a):
    count=0
    while True:
        count+=1
        x = a 
        a = func(x)

        if(abs(a - x) < 10**(-6)):
            return x, count

#---------------------------------------------

#metoda newton
def newton(func, dFunc, ddFunc, a, b):
    count=0
    if(func(a) * ddFunc(a) > 0):
        x = x1 = a
    else:
        x = x1 = b

    while True:
        count+=1
        x = x1
        x1 = x - func(x) / dFunc(x)

        if(abs(x1-x) < 10**(-6)):
            return x1, count

#-------------------------------------------

#metoda secantelor
def secant(func, a, b):
    count = 0
    x1 = 0
    x2 = 0
    if (func(a) * func(b) < 0):
        while True:
            count = count + 1
            x1 = (a * func(b) - b * func(a)) / (func(b) - func(a))
            if (func(a) * func(x1) == 0):
                break

            a = b
            b = x1
            x2 = (a * func(b) - b * func(a)) / (func(b) - func(a))
            if (abs(x2 - x1) < 10**(-6)):
                return x1, count

#----------------------------------------------------------

print("Ecuatia 1: log(2x+3) + 2x - 1")

print("metoda bisectoarelor si numarul de iteratii: ", bisect(f1, 0, 2))

print("metoda aproximatiilor succesive si numarul de iteratii: ", aprox(f1fi, 0))
print("metoda newton si numarul de iteratii: ", newton(f1, f1d, f1dd, 0, 2))
print("metoda secantelor si numarul de iteratii: ", secant(f1, 0, 2))

print("Ecuatia 2: x^3+7x-2")

print("metoda bisectoarelor si numarul de iteratii: ", bisect(f2, 0, 1))

print("metoda aproximatiilor succesive si numarul de iteratii: ", aprox(f2fi, -2))
print("metoda newton si numarul de iteratii: ", newton(f2, f2d, f2dd, 0, 1))
print("metoda secantelor si numarul de iteratii: ", secant(f2, 0, 1))