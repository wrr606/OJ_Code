import pyautogui
import time
import keyboard

def type_from_clipboard(word,idx):
    pyautogui.typewrite(word[idx])

words = [
    "shocked", "learn", "president", "admitted", "heart", "surgery", "apart", "from", "prior",
    "so", "to", "learn", "nutrition", "appointment", "nutritionist", "local", "health", "booked",
    "canceled", "observed", "investigated"
]

idx=0
while True:
    if keyboard.is_pressed('enter'):
        type_from_clipboard(words,idx)
        idx+=1
        time.sleep(0.001)