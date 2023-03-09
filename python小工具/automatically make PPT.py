import pyautogui
from selenium import webdriver
from selenium.webdriver.common.by import By
import keyboard

#讀取txt的單字並存到list
word_file=open('word.txt','r')
word=[]
for line in word_file.readlines():
    word.append(line)
print(word)

#爬蟲
driver = webdriver.Chrome('D:\chromedriver')
driver.maximize_window()
driver.get('https://dictionary.cambridge.org/zht/')
translation_and_example=[[""]*5 for i in range(40)]
print(translation_and_example)
counter=-1
for i in word:
    counter+=1
    translation_and_example[counter][0]=i
    print(i)
    #driver.find_element(By.XPATH,'//*[@id="searchForm"]/div[2]/div/div/div/span[1]').click()
    for j in range(50):
        driver.find_element(By.NAME,'q').send_keys("\ue017")
    driver.find_element(By.NAME,'q').send_keys(i)
    driver.find_element(By.NAME,'q').submit()
    traslation=driver.find_elements(By.CLASS_NAME,"trans.dtrans.dtrans-se.break-cj")
    for j in traslation:
        temp=j.text
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
print(translation_and_example)

#設定貼上的位置
print("移動到單字位置")
keyboard.wait('ctrl')
