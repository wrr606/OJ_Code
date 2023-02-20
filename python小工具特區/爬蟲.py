from selenium import webdriver
import time
driver = webdriver.Chrome('D:\chromedriver')
driver.get('https://www.gamer.com.tw/')
driver.maximize_window()
driver.find_element_by_name('search').send_keys('LOL')
driver.find_element_by_class_name('gsc-search-button').click()
driver.find_element_by_class_name('gs-title').click()
driver.get('//forum.gamer.com.tw/B.php?bsn=17532')