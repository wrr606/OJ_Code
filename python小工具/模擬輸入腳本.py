import pyautogui
import time
import keyboard
import pyperclip

def type_from_clipboard(word,idx):
    pyautogui.typewrite(word[idx])

words = [
    "calling", "introduce", "investment", "opportunity", "change", "remind", "orientation",
    "payroll", "information", "Replace", "current", "access", "Sign", "contract", "dress", "at",
    "Conduct", "floor", "parking", "located", "on", "top", "bottom", "ground"
]


idx=0
while True:
    if keyboard.is_pressed('enter'):
        type_from_clipboard(words,idx)
        idx+=1
        time.sleep(0.001)