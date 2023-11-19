import pyautogui
import time
import keyboard
import pyperclip

def type_from_clipboard(word,idx):
    pyautogui.typewrite(word[idx])

words = [
    "As", "changes", "policy", "regarding", "leave", "absence", "renew", "familiarize",
    "analyze", "present", "memorandum", "currently", "circulating", "endorsed", "by",
    "reflection", "whether", "nor", "each", "how"
]

idx=0
while True:
    if keyboard.is_pressed('enter'):
        type_from_clipboard(words,idx)
        idx+=1
        time.sleep(0.001)