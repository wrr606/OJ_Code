from selenium import webdriver
from selenium.webdriver.common.by import By
import pyautogui
import keyboard
import xerox

def double_esc():
    pyautogui.press('esc')
    pyautogui.press('esc')

#讀取txt的單字並存到list
word_file=open('word.txt','r')
word=[]
for line in word_file.readlines():
    word.append(line)
#print(word)

#爬蟲
driver = webdriver.Edge('msedgedriver.exe')
driver.maximize_window()
driver.get('https://dictionary.cambridge.org/zht/')
translation_and_example=[[""]*5 for i in range(40)]
#print(translation_and_example)
counter=-1
for i in word:
    counter+=1
    print(i)
    #driver.find_element(By.XPATH,'//*[@id="searchForm"]/div[2]/div/div/div/span[1]').click()
    for j in range(50):
        driver.find_element(By.NAME,'q').send_keys("\ue017")
    driver.find_element(By.NAME,'q').send_keys(i)
    driver.find_element(By.NAME,'q').submit()
    traslation=driver.find_elements(By.CLASS_NAME,"trans.dtrans.dtrans-se.break-cj")
    for j in traslation:
        temp=j.text
        print(temp)
        break
    translation_and_example[counter][0]=temp
    try:
        inp=driver.find_element(By.XPATH,'//*[@id="dataset-example"]/div[2]/div[2]/div[1]/span')
        translation_and_example[counter][1]=inp.text
        inp=driver.find_element(By.XPATH,'//*[@id="dataset-example"]/div[2]/div[2]/div[2]/span')
        translation_and_example[counter][2]=inp.text
        inp=driver.find_element(By.XPATH,'//*[@id="dataset-example"]/div[2]/div[2]/div[3]/span')
        translation_and_example[counter][3]=inp.text
    except:
        continue

#debug
#print(translation_and_example)

#設定貼上的位置
print("移動到單字位置")
keyboard.wait('ctrl')
word_location=pyautogui.position()
print("移動到中文位置")
keyboard.wait('ctrl')
translation_location=pyautogui.position()
print("移動到例句1位置")
keyboard.wait('ctrl')
example1_location=pyautogui.position()
print("移動到例句2位置")
keyboard.wait('ctrl')
example2_location=pyautogui.position()
print("移動到例句3位置")
keyboard.wait('ctrl')
example3_location=pyautogui.position()

#執行貼上動作
counter=-1
for i in word:
    counter+=1
    pyautogui.moveTo(word_location[0],word_location[1])
    pyautogui.click()
    xerox.copy(i)
    pyautogui.hotkey('ctrl','v')
    double_esc()
    pyautogui.moveTo(translation_location[0],translation_location[1])
    pyautogui.click()
    xerox.copy(translation_and_example[counter][0])
    pyautogui.hotkey('ctrl','v')
    double_esc()
    pyautogui.moveTo(example1_location[0],example1_location[1])
    pyautogui.click()
    xerox.copy(translation_and_example[counter][1])
    pyautogui.hotkey('ctrl','v')
    double_esc()
    pyautogui.moveTo(example2_location[0],example2_location[1])
    pyautogui.click()
    xerox.copy(translation_and_example[counter][2])
    pyautogui.hotkey('ctrl','v')
    double_esc()
    pyautogui.moveTo(example3_location[0],example3_location[1])
    pyautogui.click()
    xerox.copy(translation_and_example[counter][3])
    pyautogui.hotkey('ctrl','v')
    double_esc()
    pyautogui.hotkey('ctrl','pagedown')