from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

# 設定 ChromeDriver 的檔案路徑
driver = webdriver.Chrome('D:\chromedriver.exe')

driver.maximize_window()
driver.get("https://1968.freeway.gov.tw/n_speed")

WebDriverWait(driver, 5).until(
    EC.presence_of_element_located((By.XPATH, "//table[@class='table_normal spd_table']/tbody"))
)
dom = driver.find_elements(By.XPATH, "//table[@class='table_normal spd_table']/tbody")
for i in dom:
    print(i.text)
# 關閉 WebDriver
driver.quit()