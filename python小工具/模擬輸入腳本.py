import pyautogui
import time
import keyboard
import pyperclip

def type_from_clipboard(word,idx):
    pyautogui.typewrite(word[idx])

words = [
    "conversation", "place", "accounting", "firm", "software", "advertising", "manufacturing",
    "plant", "suggest", "downsizing", "staff", "replace", "former", "employee", "hiring",
    "workers", "manager", "meet", "manager", "assistant", "secretary"
]


idx=0
while True:
    if keyboard.is_pressed('enter'):
        type_from_clipboard(words,idx)
        idx+=1
        time.sleep(0.001)