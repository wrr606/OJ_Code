import pandas as pd
import numpy as np

x = pd.read_excel("程式設計-資工一.xlsx")
y = pd.read_csv("2024 期中考 Midterm Exam.csv")
z = pd.read_csv("2024 期中補考.csv")
scores = z[["帳號", "分數"]].to_numpy().tolist()
for i in y[["帳號", "分數"]].to_numpy().tolist():
    scores.append(i)
scores = [list(map(int, row)) for row in scores]
x["學號"] = x["學號"].str.strip()
for i, j in scores:
    x.loc[x["學號"] == str(i), "期中考"] = j
print(x)
x.to_excel("程式設計-資工一_更新後.xlsx", index=False, engine='openpyxl')