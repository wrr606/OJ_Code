import pyautogui
import time
from pynput import keyboard

ctrl_pressed = False

def on_press(key):
    global ctrl_pressed

    try:
        if key == keyboard.Key.enter:
            ctrl_pressed = True
    except AttributeError:
        if key == keyboard.Key.ctrl:
            ctrl_pressed = False

def on_release(key):
    global ctrl_pressed
    if key == keyboard.Key.ctrl:
        ctrl_pressed = False

listener = keyboard.Listener(on_press=on_press, on_release=on_release)
listener.start()

while not ctrl_pressed:
    time.sleep(0.1)

import time
for _ in range(20):
    for i in range(10):
        pyautogui.typewrite(f"{i}"*99)
        time.sleep(0.5)
        pyautogui.press('enter')
        time.sleep(0.5)

listener.stop()
listener.join()