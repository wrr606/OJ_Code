import pyautogui
import pyperclip
import time
import keyboard
import pyperclip

def type_from_clipboard(word,idx):
    pyautogui.typewrite(word[idx])
words = [
    "article", "mainly", "museum", "closing", "down", "exhibition", "held", "gallery",
    "regain", "fame", "repair", "building", "implied", "uses", "multiple", "forms",
    "originally", "gained", "fame", "stylistic", "designs", "moved", "sculptures",
    "popular", "gallery", "remodeled", "complained", "about", "confusing", "layout",
    "damaged", "natural", "disaster", "age", "lack", "Vandals", "exterior", "capture",
    "details", "quickly", "rose", "prominence"
]


idx=0
while True:
    if keyboard.is_pressed('enter'):
        type_from_clipboard(words,idx)
        idx+=1
        time.sleep(0.1)