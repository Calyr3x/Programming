from tkinter import *
from math import *
from random import *

def firstMethod(c, r, x, y):
    c.create_oval(x+r, y+r, x-r, y-r, width = 2)

def secondMethod(c, radius, x1, y1, x2, y2):
    centerOfTwoDots = [(x1+x2)/2, (y1+y2)/2]
    lenA = ((centerOfTwoDots[0]-x1)**2+(centerOfTwoDots[1]-y1)**2)**0.5
    lenB = (radius**2-lenA**2)**0.5
    center = [centerOfTwoDots[0], centerOfTwoDots[1]+lenB]
    firstMethod(c, radius, center[0], center[1])

def second(c):
    dot1 = [10, 20]
    dot2 = [110, 120]
    r = 90
    secondMethod(c, r, dot1, dot2)

def third(c, r):
    center = [450, 450]
    firstMethod(c, r, center)
    c.create_rectangle(center[0]+r*cos(pi/4), center[0]+r*sin(pi/4), center[1]-r*cos(pi/4), center[1]-r*sin(pi/4), width = 2)


def fouth(c):
    x, y = 450, 450
    r = 150
    c.create_polygon(x-r, y-r, x-r, y+r*2, x+r*3, y-r, fill = 'white', outline = 'black')
    c.create_oval(x-r, y-r, x+r, y+r)

def five(c):
    i = 0
    while i < 10000:
        r = randint(0, 100)
        center = [randint(0, 900), randint(0, 900)]
        c.create_oval(center[0]-r, center[1]-r, center[0]+r, center[1]+r, fill="#"+("%06x"%randint(0,16777215)))
        i += 1

def six(c):
    x, y = 450, 450
    r = 150
    c.create_polygon(x, y-2*r, x+1.75*r, y+r, x-1.75*r, y+r, fill='white', outline='black')
    c.create_oval(x-r, y-r, x+r, y+r)

def seven(c):
    s1 = 11132
    s2 = 13993
    r = sqrt((s1+s2)/pi)
    x = y = 150
    c.create_oval(x - r, y - r, x + r, y + r)
    c.create_arc(x - r, y - r, x + r, y + r, start=75, extent=s1*360/(s1+s2), style=CHORD)
    

def task():
    while(True):
        n = int(input('Введите номер задания: ' ))
        window = Tk()
        c = Canvas(window, width = 900, height = 900, bg = 'white')
        c.pack()
        match n:
           
            case 1:
                print('Задание №1')
                print('Введите метод(1/2)')
                method = int(input())
                match method:
                    case 1:
                        print('Введите координаты центра')
                        x, y = map(int, input().split())
                        firstMethod(c, 30, x, y)
                    case 2:
                        print('Введите координаты двух точек и радиус')
                        x1, y1, x2, y2, r = map(int, input().split())
                        secondMethod(c, r, x1, y1, x2, y2)
            case 2:
                print('Задание №2')
                print('Введите 5 чисел разделенных пробелом')
                a, b, c, m, k = map(int, input().split())
                second(a, b, c, m, k)
            case 3:
                print('Задание №3')
                print('Введите 2 числа разделенных пробелом')
                a, b = map(int, input().split())
                third(a, b)
            case 4:
                print('Задание №4')
                a = int(input())
                fourth(a)
            case 5:
                print('Задание №5')
                n = int(input())
                a = fifth(n)
                print(f'Факториал {n}: {a}')
            case 6:
                print('Задание №6')
                sixth()
            case 7:
                print('Задание №7')
                seventh()

task()
