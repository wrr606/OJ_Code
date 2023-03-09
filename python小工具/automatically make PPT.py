import pyautogui
import os
from selenium import webdriver

#讀取txt的單字並存到list
word_file=open('word.txt','r')
word=[]
for line in word_file.readlines():
    word.append(line)
print(word)

#爬蟲
driver = webdriver.Chrome('D:\chromedriver')
driver.get('https://dictionary.cambridge.org/zht/')
translation_and_example=[[""]*5]*40
print(translation_and_example)
counter=0
for i in word:
    translation_and_example[counter][0]=i
    print(i)
    driver.find_element_by_name('q').send_keys(i)
    driver.find_element_by_name('q').submit()
    traslation=driver.find_elements_by_class_name('trans dtrans dtrans-se  break-cj')
    for j in traslation:
        print(j.text)
    inp=driver.find_element_by_xpath('//*[@id="dataset-example"]/div[2]/div[2]/div[1]/span')
    translation_and_example[counter][1]=inp.text
    counter+=1
#driver.maximize_window()

word_file=open('word.txt','r')
#os.system('')
