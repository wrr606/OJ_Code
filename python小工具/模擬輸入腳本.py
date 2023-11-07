import pyautogui
import time
import keyboard
import pyperclip

def type_from_clipboard(word,idx):
    pyautogui.typewrite(word[idx])

words = [
    "Renewing", "rental", "lease", "tenant", "cover", "installing", "unruly", "neighbor",
    "disturbing", "mean", "lose", "money", "deposit", "extra", "give", "up", "won",
    "cannot", "early"
]

idx=0
while True:
    if keyboard.is_pressed('enter'):
        type_from_clipboard(words,idx)
        idx+=1
        time.sleep(0.1)