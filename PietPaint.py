from tkinter import *
from tkinter.ttk import *
import os
import math
import random
import time

root = Tk()
root.title('Piet Paint')
root.geometry('800x600')
root.resizable(False, False)
if os.name == 'nt':
    root.iconbitmap('PietIcon.ico')
else:
    icon_image = PhotoImage(file="PietIcon.png")
    root.iconphoto(True, icon_image)

Label(root, text='Welcome to Piet Paint!', font=('Helvetica', 25), foreground='blue').pack(side=TOP, pady=20)
Label(root, text='You will have a Canvas window and a Shape window.', font=('Helvetica', 17), foreground='red').pack(side=TOP, pady=10)
Label(root, text='You can click on the Canvas to create a shape.', font=('Helvetica', 17), foreground='red').pack(side=TOP, pady=10)
Label(root, text='The longer you hold the click the larger the shape grows.', font=('Helvetica', 17), foreground='red').pack(side=TOP, pady=10)
Label(root, text='You can edit the Shape by either choosing values or setting them to random.', font=('Helvetica', 17), foreground='red').pack(side=TOP, pady=10)
Label(root, text="Click 'Create Canvas' to create a new canvas!", font=('Helvetica', 19), foreground='red').pack(side=TOP, pady=15)

default_colors = ["black", "red", "blue", "yellow", "gray", "white"]

def on_button_click():
    root.iconify()

    window1 = Tk()
    window1.title("Canvas")
    window1.geometry("600x300")
    window1.resizable(False, False)
    if os.name == 'nt':
        window1.iconbitmap('Canvas.ico')
    else:
        icon_image = PhotoImage(file="Canvas.png")
        window1.iconphoto(True, icon_image)

    Label(window1, text='Use your inner creativity...', font=('Helvetica', 17), foreground='red').pack(side=TOP, pady=40)
    Label(window1, text='Imagine on mouse clicks there are squares...', font=('Helvetica', 17), foreground='blue').pack(side=TOP, pady=10)
    Label(window1, text='Don\'t lose focus...', font=('Helvetica', 17), foreground='red').pack(side=TOP, pady=40)

    window2 = Tk()
    window2.title("Shape")
    window2.geometry("550x200")
    window2.resizable(False, False)
    if os.name == 'nt':
        window2.iconbitmap('Shape.ico')
    else:
        icon_image = PhotoImage(file="Shape.png")
        window2.iconphoto(True, icon_image)

    Button(window2, text='Color', width=25).pack(side=LEFT, padx=11)
    Button(window2, text='Rotation', width=25).pack(side=LEFT, padx=11)
    Button(window2, text='Outline', width=25).pack(side=LEFT, padx=11)

buttonStyle = Style()
buttonStyle.configure('TButton',
                      font=('Arial', 20),
                      background='blue',
                      foreground='blue',
                      padding=10)

Button(root, text='Create Canvas', command=on_button_click, width=25, style='TButton').pack(side=TOP, pady=80)

root.protocol("WM_DELETE_WINDOW", root.quit)

mainloop()