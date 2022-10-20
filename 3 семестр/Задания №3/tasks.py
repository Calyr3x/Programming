from random import seed
from random import randint
import sys
from operator import itemgetter
from tkinter import *
from tkinter import scrolledtext
from tkinter import messagebox

def first():
    window_1 = Tk()
    window_1.title("Решето Эратосфена")
    window_1.geometry('400x250')
    txt = Entry(window_1, width = 15)
    txt.grid(column = 0, row = 0, padx = 10, pady = 10)
    
    def clicked_1():
        n = int(txt.get())
        a = set(range(2, n+1))
        outp = scrolledtext.ScrolledText(window_1, width = 10, height = 12)
        outp.grid(column = 0, row = 1)
        while a:
            prime = min(a)
            outp.insert(INSERT, str(prime) + '\n')
            a -= set(range(prime, n+1, prime))
        outp.configure(state = 'disabled')
    button_1 = Button(window_1, text = "Ввод", command = clicked_1)\
        .grid(column = 1, row = 0, padx = 10, pady = 10)
    
    window_1.mainloop()

def second():
    messagebox.showwarning('Внимание', 'Вводите размеры сторон разделяя пробелом!')            
    window_2 = Tk()
    window_2.title("Задача про коробку и дверь")
    window_2.geometry('230x110')
    lbl_a = Label(window_2, text = "Размеры коробки:")\
        .grid(column = 0, row = 1, sticky = E, pady = 5)
    txt_a = Entry(window_2, width = 15)
    txt_a.grid(column = 1, row = 1, pady = 5)
    lbl_b = Label(window_2, text = "Размеры двери:")\
        .grid(column = 0, row = 2, sticky = W, pady = 5)
    txt_b = Entry(window_2, width = 15)
    txt_b.grid(column = 1, row = 2, pady = 5)
    
    def clicked_2():
        a, b, c = map(int, txt_a.get().split())
        m, k = map(int, txt_b.get().split())
        minA = min(a, min(b, c))
        minB = a+b+c-minA-max(a, max(b, c))
        if a <= 0 or b <= 0 or c <= 0:
            messagebox.showwarning('Результат', 'Введите корректные размеры')            
        elif minA*minB<=m*k:
            messagebox.showinfo('Результат', 'Коробка пройдет сквозь дверь')
        else:
            messagebox.showerror('Результат', 'Коробка не пройдет сквозь дверь')
        
    button_2 = Button(window_2, text = "Ввод", command = clicked_2)\
        .grid(column = 1, row = 3, pady = 5)
    window_2.mainloop()
    

def third():
    window_3 = Tk()
    window_3.title("НОК двух чисел")
    window_3.geometry('230x110')
    txt_a = Entry(window_3, width = 15)
    txt_a.grid(column = 1, row = 1, pady = 5)
    lbl_a = Label(window_3, text = "Число A:")\
        .grid(column = 0, row = 1, sticky = E, pady = 5)
    lbl_b = Label(window_3, text = "Число B:")\
        .grid(column = 0, row = 2, sticky = W, pady = 5)
    txt_b = Entry(window_3, width = 15)
    txt_b.grid(column = 1, row = 2, pady = 5)
    
    def clicked_3():
        a = int(txt_a.get())
        b = int(txt_b.get())
        A, B = a, b
        while(b>0):
            a, b=b, a % b
        lbl_c = Label(window_3, text = f'НОК: {A*B//a}')\
                .grid(column = 0, row = 3)
        
    button_3 = Button(window_3, text = "Ввод", command = clicked_3)\
        .grid(column = 2, row = 0, rowspan = 3, padx = 5)
    window_3.mainloop()
    
    
def fourth():
    window_4 = Tk()
    window_4.title("Числа Фибоначчи")
    window_4.geometry('450x110')
    txt = Entry(window_4, width = 15)
    txt.grid(column = 1, row = 0, pady = 5, sticky = EW)
    lbl = Label(window_4, text = "Какое число вывести? ")\
        .grid(column = 0, row = 0, sticky = W)

    def clicked_4():
        n = int(txt.get())
        a = [0]*n
        a[0] = 1
        a[1] = 1
        i = 2
        while(i < len(a)):
            a[i] = a[i-1]+a[i-2]
            i += 1
        lbl_a = Label(window_4, text = f'{n}e число Фибоначчи: ')\
                .grid(column = 0, row = 1)
        lbl_a = Label(window_4, text =  str(a[i-1]))\
                .grid(column = 1, row = 1)

    button_4 = Button(window_4, text = "Ввод", command = clicked_4)\
        .grid(column = 2, row = 0, rowspan = 3, padx = 5)
    window_4.mainloop()

def fact(n):
        if(n == 0):
            return 1
        return n*fact(n-1)
    
def fifth():
    window_5 = Tk()
    window_5.title("Факториал")
    window_5.geometry('600x110')
    txt = Entry(window_5, width = 15)
    txt.grid(column = 1, row = 0, pady = 5, sticky = NE)
    lbl = Label(window_5, text = "Введите число:")\
        .grid(column = 0, row = 0, sticky = NE, pady = 2)
    
    def clicked_5():
        outp = scrolledtext.ScrolledText(window_5, width = 43, height = 6)
        outp.grid(column = 3, row = 0, pady = 5)
        n = int(txt.get())
        if n > 1010:
            messagebox.showerror('Error', 'Слишком большое число')
            return
        a = fact(n)
        outp.insert(INSERT, f'Факториал {n}: {a}\n')
        outp.configure(state = 'disabled')
        
    button_5 = Button(window_5, text = "Ввод", command = clicked_5)\
        .grid(column = 2, row = 0, padx = 5, sticky = NE)
    window_5.mainloop()

def sixth():
    window_6 = Tk()
    window_6.title("Калькулятор") 
    window_6.geometry('260x50')
    txt = Entry(window_6, width = 15)
    txt.grid(column = 1, row = 0, pady = 5)
    lbl = Label(window_6, text = "Введите выражение:")\
        .grid(column = 0, row = 0, sticky = W)
    lbl = Label(window_6)
    lbl.grid(column = 0, row = 1, sticky = W)

    def clicked_6():
        lbl.configure(text = f'Результат: {eval(txt.get())}')

    button_6 = Button(window_6, text = "Ввод", command = clicked_6)\
            .grid(column = 2, row = 0, padx = 5)
    window_6.mainloop()

def seventh():
    window_7 = Tk()
    window_7.title("Вероятность") 
    window_7.geometry('405x25')
    a = fact(100)/fact(97)
    lbl = Label(window_7, text = f'Шанс угадать выигрышный лотерейный номер: {1/a}')\
        .grid(column = 0, row = 0)
    window_7.mainloop()
    
def eight():
    window_8 = Tk()
    window_8.title("Массив")
    window_8.geometry('400x160')
    txt = Entry(window_8, width = 20)
    txt.grid(column = 1, row = 0, pady = 5, sticky = EW)
    lbl = Label(window_8, text = "Кол-во элементов:")\
        .grid(column = 0, row = 0, sticky = E)
    lbl_a = Label(window_8, text = 'Исходный массив: ')\
        .grid(column = 0, row = 1, sticky = E)
    lbl_b = Label(window_8, text = 'Только положительные числа: ')\
        .grid(column = 0, row = 2, sticky = E)
    lbl_c = Label(window_8, text = 'Максимум: ')
    lbl_c.grid(column = 0, row = 3, sticky = E)
    lbl_ca = Label(window_8)
    lbl_ca.grid(column = 1, row = 3, sticky = W)

    def clicked_8():
        outp1 = scrolledtext.ScrolledText(window_8, width = 16, height = 2)
        outp1.grid(column = 1, row = 1)
        outp2 = scrolledtext.ScrolledText(window_8, width = 16, height = 2)
        outp2.grid(column = 1, row = 2)
        n = int(txt.get())
        a = [0]*n
        seed(randint(0, 1000))
        a = [randint(-sys.maxsize-1, sys.maxsize)//30000 for i in range(n)]
        for i in range(len(a)):
            outp1.insert(INSERT, str(a[i])+ '\n')
        a = [x for x in a if x  > 0]
        for i in range(len(a)):
            outp2.insert(INSERT, str(a[i])+ '\n')
        lbl_ca.configure(text = str(max(a)))
        outp1.configure(state = 'disabled')
        outp2.configure(state = 'disabled')

    button_8 = Button(window_8, text = "Ввод", command = clicked_8)\
        .grid(column = 2, row = 0, padx = 5)
    window_8.mainloop()

def ninth():
    window_9 = Tk()
    window_9.title("Футбольная секция")
    window_9.geometry('490x400')
    txt = Entry(window_9, width = 35)
    txt.grid(column = 1, row = 0, pady = 5, sticky = E)
    lbl = Label(window_9, text = "Студент и группа: ")\
        .grid(column = 0, row = 0, sticky = E)
    students = {}

    def clicked_9():
        student, group = map(str, txt.get().split())
        students[student] = group
        txt.delete(0, last = END)

    def clicked_10():
        outp = scrolledtext.ScrolledText(window_9, width = 20, height = 10)
        outp.grid(column = 1, row = 1)
        sortedStudents = dict(sorted(students.items(), key=itemgetter(1)))
        for key, value in sortedStudents.items():
            outp.insert(INSERT, "{0} {1}".format(value, key)+'\n')
        outp.configure(state = 'disabled')
            
    button_9 = Button(window_9, text = "Ввод", command = clicked_9)\
        .grid(column = 2, row = 0, padx = 5, sticky = W)
    button_10 = Button(window_9, text = "Вывести список студентов", command = clicked_10)\
        .grid(column = 2, row = 1, padx = 5, sticky = N)
    window_9.mainloop()

def tenth():
    window_10 = Tk()
    window_10.title("Шахматы")
    window_10.geometry('200x60')
    txt_a = Entry(window_10, width = 5)
    txt_a.grid(column = 1, row = 0, pady = 5, sticky = W)
    lbl_a = Label(window_10, text = "Координаты ферзя: ")\
        .grid(column = 0, row = 0)
    txt_b = Entry(window_10, width = 5)
    txt_b.grid(column = 1, row = 1)
    lbl_b = Label(window_10, text = "Координаты пешки: ")\
        .grid(column = 0, row = 1, sticky = E)

    def clicked_10():
        k, l = map(int, txt_a.get().split())
        m, n = map(int, txt_b.get().split())
        if k > 8 or k < 1 or l > 8 or l < 1 or m > 8 or m < 1 or n > 8 or n < 1 or  k == m and l == n:
            messagebox.showwarning('Результат', 'Введите корректные координаты')     
        elif abs(k-m) == abs(l-n) or k == m or l == n:
            messagebox.showerror('Результат', 'YES')
        else:
            messagebox.showinfo('Результат', 'NO')

    button_10 = Button(window_10, text = "Ввод", command = clicked_10)\
        .grid(column = 2, row = 0, rowspan = 2, padx = 5)
    window_10.mainloop()
    
    
def eleventh():
    window_11 = Tk()
    window_11.title("Время падения")
    window_11.geometry('220x60')
    txt = Entry(window_11, width = 18)
    txt.grid(column = 1, row = 0, pady = 5, sticky = W)
    lbl_a = Label(window_11, text = "Высота: ")\
        .grid(column = 0, row = 0)
    lbl_b = Label(window_11, text = "Результат: ")\
        .grid(column = 0, row = 1)
    lbl_ba = Label(window_11)
    lbl_ba.grid(column = 1, row = 1)

    def clicked_11():
        h = int(txt.get())
        lbl_ba.configure(text = str((2*h/9.81)**0.5))

    button_11 = Button(window_11, text = "Ввод", command = clicked_11)\
        .grid(column = 2, row = 0, padx = 5, sticky = W)
    window_11.mainloop()

def twelfth():
    window_12 = Tk()
    window_12.title("Треугольник")
    window_12.geometry('505x180')
    txt = Entry(window_12, width = 15)
    txt.grid(column = 1, row = 0, pady = 5, sticky = EW)
    lbl_a = Label(window_12, text = "Длины сторон: ")\
        .grid(column = 0, row = 0)

    def clicked_12():
        outp = scrolledtext.ScrolledText(window_12, width = 43, height = 8)
        outp.grid(column = 1, row = 1)
        a, b, c = map(int, txt.get().split())
        
        hp = (a+b+c)/2
        area = (hp*(hp-a)*(hp-b)*(hp-c))**0.5
        
        outp.insert(INSERT, 'А)Длины высот:\n')
        for x in [a, b, c]:
            outp.insert(INSERT, str(round(2*area/x, 2))+' ')
            
        outp.insert(INSERT, '\nБ)Длины медиан:\n')
        outp.insert(INSERT, str(round((((2*a**2+2*b**2-c**2)**0.5)/2), 2))+' ')
        outp.insert(INSERT, str(round((((2*c**2+2*b**2-a**2)**0.5)/2), 2))+' ')
        outp.insert(INSERT, str(round((((2*a**2+2*c**2-b**2)**0.5)/2), 2))+'\n')

        outp.insert(INSERT,'В)Длины биссектрис:\n')
        outp.insert(INSERT, str(round((2*(a*b*hp*(hp-c))**0.5)/(a+b), 2))+' ')
        outp.insert(INSERT, str(round((2*(a*c*hp*(hp-b))**0.5)/(a+c), 2))+' ')
        outp.insert(INSERT, str(round((2*(c*b*hp*(hp-a))**0.5)/(a+c), 2))+'\n')

        outp.insert(INSERT, 'Г)Радиусы вписанной и описанной окружности:\n')
        outp.insert(INSERT, str(round(((hp-a)*(hp-b)*(hp-c)/hp)**0.5, 2))+' ')
        outp.insert(INSERT, str(round((a*b*c)/(4*area), 2)))
        outp.configure(state = 'disabled')

    button_12 = Button(window_12, text = "Ввод", command = clicked_12)\
        .grid(column = 2, row = 0, padx = 5, sticky = W)
    window_12.mainloop()


def task():
    window = Tk()
    window.title("Решатель задач")
    window.geometry('360x110')
    button_1ex = Button(text="1", width = 10, height = 1, bg = "#4B0082", command = first)\
        .grid(column = 0, row = 0, padx = 5, pady = 5)
    button_2ex = Button(text="2", width = 10, height = 1, bg = "#800080", command = second)\
        .grid(column = 1, row = 0, padx = 5, pady = 5)
    button_3ex = Button(text="3", width = 10, height = 1, bg = "#8B008B", command = third)\
        .grid(column = 2, row = 0, padx = 5, pady = 5)
    button_4ex = Button(text="4", width = 10, height = 1, bg = "#9400D3", command = fourth)\
        .grid(column = 3, row = 0, padx = 5, pady = 5)
    button_5ex = Button(text="5", width = 10, height = 1, bg = "#483D8B", command = fifth)\
        .grid(column = 0, row = 1, padx = 5, pady = 5)
    button_6ex = Button(text="6", width = 10, height = 1, bg = "#8A2BE2", command = sixth)\
        .grid(column = 1, row = 1, padx = 5, pady = 5)
    button_7ex = Button(text="7", width = 10, height = 1, bg = "#9932CC", command = seventh)\
        .grid(column = 2, row = 1, padx = 5, pady = 5)
    button_8ex = Button(text="8", width = 10, height = 1, bg = "#FF00FF", command = eight)\
        .grid(column = 3, row = 1, padx = 5, pady = 5)
    button_9ex = Button(text="9", width = 10, height = 1, bg = "#6A5ACD", command = ninth)\
        .grid(column = 0, row = 2, padx = 5, pady = 5)
    button_10ex = Button(text="10", width = 10, height = 1, bg = "#7B68EE", command = tenth)\
        .grid(column = 1, row = 2, padx = 5, pady = 5)
    button_11ex = Button(text="11", width = 10, height = 1, bg = "#BA55D3", command = eleventh)\
        .grid(column = 2, row = 2, padx = 5, pady = 5)
    button_12ex = Button(text="12", width = 10, height = 1, bg = "#DA70D6", command = twelfth)\
        .grid(column = 3, row = 2, padx = 5, pady = 5)

    window.mainloop()
