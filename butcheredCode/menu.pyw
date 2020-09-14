import os
os.system("python -m pip install winsound --user")
os.system("python -m pip install turtle --user")
os.system("python -m pip install tkinter --user")
os.system("python -m pip install math -- user")
import tkinter as tk
import math
from winsound import PlaySound, SND_ASYNC
import turtle

button_flag = True
root = tk.Tk()

lengthA = 0.0
lengthB = 0.0
lengthC = 0.0

def anglesExcluding90(sideB, sideC):
    print(str(sideB) + " / " + str(sideC))
    print("math.asin("+str(sideB / sideC) + ")")
    angleAsin = math.asin(sideB / sideC)
    print("Output = " + str(angleAsin))
    angleA = math.degrees(angleAsin)

    return angleA




#Main function
def lenPythag():
    #Start of configuration of menu{


    global root


    root.destroy()
    print("Clicked length Pythagorean Theorem.")
    root = tk.Tk()
    root.geometry("500x700")
    root.configure(bg="grey")

    label = tk.Message(text="Please input Length A below:", bg="grey", width=200)
    label.pack()

    lengthAInput = tk.Text(root, height=5, width=10)
    disclaimer = tk.Message(text="In order to calculate properly, after the press of each 'solve' button, you will need to press submit on each side length.")
    disclaimer.pack()

    lengthBInput = tk.Text(root, height=5, width=10)
    #End of Configuration of menu}
    def getInputA():
        global lengthA
        inputValue = lengthAInput.get("1.0", "end-1c")
        print("Submitted Value A as " + str(inputValue))
        PlaySound("untitled.wav", SND_ASYNC)
        try:
            print("Attempted to set lengthA to " + str(float(inputValue)))
            lengthA = float(inputValue)
        except:
            print("Couldn't input " + str(inputValue) + ". Prompted user to re-input.")
            PlaySound("untitled2.wav", SND_ASYNC)

    lengthAInput.pack()
    buttonInputA = tk.Button(text="Submit A", command=getInputA)
    buttonInputA.pack()

    def getInputB():
        global lengthA
        global lengthB
        print("TEST:::: A = " + str(lengthA))
        global lengthB
        inputValue = lengthBInput.get("1.0", "end-1c")
        print("Submitted Value B as " + str(inputValue))
        try:
            lengthB = float(inputValue)
            PlaySound("untitled.wav", SND_ASYNC)
        except:
            print("Couldn't input " + str(inputValue) + ". Promped user to re-input")
            PlaySound("untitled2.wav", SND_ASYNC)

    buttonInputB = tk.Button(text="Submit B", command=getInputB)

    lable2 = tk.Message(text="Please input length B below:", bg="grey", width=200)
    lable2.pack()

    lengthBInput.pack()
    buttonInputB.pack()

    def getInputB():
        global lengthB
        inputValue = lengthBInput.get("1.0", "end-1c")


    lengthBInput.pack()

    lable3 = tk.Message(text="Please input length C below:", bg="grey", width = 200)


    lengthCInput = tk.Text(root, height = 5, width = 10)

    def getInputC():
        global lengthC
        inputValue = lengthCInput.get("1.0", "end-1c")
        print("Submitted Value C as " + str(inputValue))
        try:
            lengthC = float(inputValue)
            PlaySound("untitled.wav", SND_ASYNC)
        except:
            print("Couldn't input " + str(inputValue) + ". Prompted user to re-input")
            PlaySound("untitled2.wav", SND_ASYNC)

    buttonInputC = tk.Button(text ="Submit C", command = getInputC)

    lable3.pack()
    lengthCInput.pack()
    buttonInputC.pack()
    photo2 = tk.PhotoImage(file="button_solve.png")

    def calculate():
        global lengthA
        global lengthB
        global lengthC

        print(lengthA)

        print("Calculating")


        if lengthA == "" or lengthA == 0.0:
            print("Found A to be the only missing value. Calculating for A.")
            lengthB = lengthB ** 2
            lengthC = lengthC ** 2
            lengthA = math.sqrt((lengthC - lengthB))
            lengthB = math.sqrt(lengthB)
            lengthA = math.sqrt(lengthA)
            lengthC = math.sqrt(lengthC)
            print("Found A = " + str(lengthA))

            label4 = tk.Message(text=str(lengthA) + " = side A", bg="light blue", width = 150)
            label4.pack()
            turtle.color("red", "yellow")
            turtle.speed("slow")
            turtle.begin_fill()
            turtle.speed(3)
            turtle.degrees()
            print("\nGoing right " + str(lengthB * 4) + "\n")
            turtle.forward(lengthB)
            turtle.left(180 - anglesExcluding90(lengthB, lengthC))
            print("\nGoing up " + str(lengthC * 4) + "\n")
            turtle.forward(lengthC)
            turtle.left(180 - anglesExcluding90(lengthB, lengthC))
            print("\nGoing down " + str(lengthA * 4) + "\n")
            turtle.forward(lengthA)
            turtle.end_fill()
            turtle.done()

            lengthA = 0.0
            lengthB = 0.0
            lengthC = 0.0
        elif lengthB == "" or lengthB == 0.0:
            print("Found B to be the only missing value. Calculating for B")
            lengthA = lengthA ** 2
            lengthC = lengthC ** 2
            lengthB = math.sqrt((lengthC - lengthA))
            lengthA = math.sqrt(lengthA)
            lengthC = math.sqrt(lengthC)
            print("Found B = " + str(lengthB))

            label4 = tk.Message(text=(str(lengthB) + " = side B"), bg="light blue", width  = 150)
            label4.pack()

            turtle.color("red", "yellow")
            turtle.speed("slow")
            turtle.begin_fill()
            turtle.speed(3)
            turtle.degrees()
            turtle.forward(lengthB * 4)
            turtle.left(180 - anglesExcluding90(lengthB, lengthC))
            turtle.forward(lengthC * 4)
            turtle.left(180 - anglesExcluding90(lengthB,lengthC))
            turtle.forward(lengthA * 4)
            turtle.end_fill()
            turtle.done()
            lengthA = 0.0
            lengthB = 0.0
            lengthC = 0.0
        elif lengthC == "" or lengthC == 0.0:
            print("Found C to be the only missing value. Calculating for C")
            lengthA = lengthA ** 2
            lengthB = lengthB ** 2
            lengthC = math.sqrt((lengthA + lengthB))
            lengthB = math.sqrt(lengthB)
            lengthA = math.sqrt(lengthA)
            print("Found C = " + str(lengthC))

            label4 = tk.Message(text=(str(lengthC)) + " = side C", bg="light blue", width = 150)
            label4.pack()
            turtle.color("red", "yellow")
            turtle.speed("slow")
            turtle.begin_fill()
            turtle.speed(3)
            turtle.degrees()
            turtle.forward(lengthB)
            print(str(math.degrees(180 - anglesExcluding90(lengthB, lengthC))))
            turtle.left(180 - anglesExcluding90(lengthB, lengthC))
            turtle.forward(lengthC)
            turtle.left(180 - anglesExcluding90(lengthB,lengthC))
            turtle.forward(lengthA)
            turtle.end_fill()

            turtle.done()

            lengthA = 0.0
            lengthB = 0.0
            lengthC = 0.0


        else:
            print("Fatal Error. Either all values are filled or an improper value has been inputted.")

    solveButton = tk.Button(command=calculate, image=photo2)
    solveButton.pack()
    root.mainloop()



def clickRightTriangle():
    global root
    print("Clicked Right Triangle Button")
    root.destroy()
    root = tk.Tk()

    root.geometry("1000x1000")

    root.configure(bg="grey")
    photo2 = tk.PhotoImage(file="button_pythagorean-solver-lengths.png")
    buttonLength = tk.Button(root, image=photo2, command=lenPythag)
    buttonLength.pack()
    root.mainloop()


photo1 = tk.PhotoImage(file="right-triangles.png")
button1 = tk.Button(root, image=photo1, command=clickRightTriangle)
button1.pack()
root.mainloop()
