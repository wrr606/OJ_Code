import pyautogui
import time
from pynput import keyboard

ctrl_pressed = False

def on_press(key):
    global ctrl_pressed

    try:
        if key.char == 'c':
            ctrl_pressed = True
    except AttributeError:
        if key == keyboard.Key.ctrl:
            ctrl_pressed = True

def on_release(key):
    global ctrl_pressed

    if key == keyboard.Key.ctrl:
        ctrl_pressed = False

listener = keyboard.Listener(on_press=on_press, on_release=on_release)
listener.start()

while not ctrl_pressed:
    time.sleep(0.1)

for _ in range(1000):
    pyautogui.click()

listener.stop()
listener.join()
