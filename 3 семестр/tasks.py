from random import seed
from random import randint
import sys
from operator import itemgetter

def first(n):
    a = set(range(2, n+1))
    while a:
        prime = min(a)
        print(prime)
        a -= set(range(prime, n+1, prime)) #Удаление prime и кратных ему чисел

def second(a, b, c, m, k):
    if a <= 0 or b <= 0 or c <= 0:
        return -1
    minA = min(a, min(b, c))
    minB = a+b+c-minA-max(a, max(b, c))
    print(minA*minB<=m*k)

def third(a, b):
    A, B = a, b
    while(b>0):
        a, b=b, a % b
    print(f'НОК: {A*B//a}')
    
def fourth(n):
    a = [0]*n
    a[0] = 1
    a[1] = 1
    i = 2
    while(i < len(a)):
        a[i] = a[i-1]+a[i-2]
        i += 1
    print(f'{n}e число Фибоначчи: {a[n-1]}')

def fifth(n):
        if(n == 0):
            return 1
        return n*fifth(n-1)

def sixth():
    flag = True
    print("Допустимые знаки: '+' '-' '*' '/'. '0' - завершение программы")
    while(flag):
        s = input()
        if s == '0':
            flag = False
        elif s in ('+', '-', '*', '/'):
            print('Введите 2 числа разделенных пробелом')
            a, b = map(float, input().split())
            match s:    #python 3.10 и выше
                case '+':
                    print(f'{a}+{b}={a+b}')
                case '-':
                    print(f'{a}-{b}={a-b}')
                case '*':
                    print(f'{a}*{b}={a*b}')
                case '/':
                    print(f'{a}/{b}={a/b}')
        else:
                print('Неправильный символ')

def seventh():
    a = fifth(100)/fifth(97)
    print(1/a)
    
def eight(n):
    a = [0]*n
    seed(randint(0, 1000))
    a = [randint(-sys.maxsize-1, sys.maxsize) for i in range(n)]
    a = [x for x in a if x  > 0]
    print(a, max(a))

def ninth(n):
    students = {}
    for i in range(n):
        student, group = map(str, input().split())
        students[student] = group
    sortedStudents = dict(sorted(students.items(), key=itemgetter(1)))
    for key, value in sortedStudents.items():
        print("{0} {1}".format(key,value))

def tenth(k, l, m, n):
    if k > 8 or k < 1 or l > 8 or l < 1 or m > 8 or m < 1 or n > 8 or n < 1 or  k == m and l == n:
        return 1
    elif abs(k-m) == abs(l-n) or k == m or l == n:
        print('YES')
    else:
        print('NO')
    
def eleventh(h):            
    print((2*h/9.81)**0.5)

def twelfth(a, b, c):
    hp = (a+b+c)/2
    area = (hp*(hp-a)*(hp-b)*(hp-c))**0.5
    print('А) Длины высот:')
    for x in [a, b, c]:
        print(2*area/x)
    print('Б) Длины медиан:')
    print(((2*a**2+2*b**2-c**2)**0.5)/2)
    print(((2*c**2+2*b**2-a**2)**0.5)/2)
    print(((2*a**2+2*c**2-b**2)**0.5)/2)
    print('В) Длины биссектрис:')
    print((2*(a*b*hp*(hp-c))**0.5)/(a+b))
    print((2*(a*c*hp*(hp-b))**0.5)/(a+c))
    print((2*(c*b*hp*(hp-a))**0.5)/(a+c))
    print('Г) Радиусы вписанной и описанной окружности:')
    print(((hp-a)*(hp-b)*(hp-c)/hp)**0.5)
    print((a*b*c)/(4*area))

def task():
    while(True):
        n = int(input('Введите номер задания: ' ))
        match n:
            case 1:
                print('Задание №1')
                x = int(input())
                first(x)
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
            case 8:
                print('Задание №8')
                a = int(input())
                eight(a)
            case 9:
                print('Задание №9')
                print('Вводите студентов в формате: Студент Группа')
                a = int(input('Введите количество студентов: '))
                ninth(a)
            case 10:
                print('Задание №10')
                print('Вводите координаты клеток через пробел')
                a, b = map(int, input('Координаты ферзя: ').split())
                c, d = map(int, input('Координаты поля: ').split())
                tenth(a, b, c, d)
            case 11:
                print('Задание №11')
                a = int(input())
                eleventh(a)
            case 12:
                print('Задание №12')
                a, b, c = map(int, input('Введите три стороны треугольника через пробел: ').split())
                twelfth(a, b, c)

            
