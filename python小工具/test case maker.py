import os
import random

class Solution:
    def minPairSum(self, nums) -> int:
        return nums.sort() or max(nums[i]+nums[-1-i] for i in range((len(nums)>>1)+1))

def save_keys_to_text_files(dictionary, output_folder):
    os.makedirs(output_folder, exist_ok=True)
    cnt=0
    for key in dictionary:
        filename = f"a_{str(cnt).zfill(2)}.in"
        with open(filename, 'w') as file:
            file.write(str(key))
        filename = f"a_{str(cnt).zfill(2)}.out"
        with open(filename, 'w') as file:
            file.write(str(dictionary[key]))
        cnt+=1

s=Solution()
keys_data = []
values_data = []

for j in range(0,3):
    temp=[]
    random_number = random.randint(2, 50) #n
    keys_data.append(f"{random_number}\n")
    for i in range(random_number):
        temp.append(random.randint(1, 10**2))
        random.shuffle(temp)
    x=temp.copy()
    values_data.append(s.minPairSum(x))
    keys_data[-1]+=" ".join(map(str,temp))

for j in range(3,6):
    temp=[]
    random_number = random.randint(100, 500) #n
    keys_data.append(f"{random_number}\n")
    for i in range(random_number):
        temp.append(random.randint(1, 10**5))
        random.shuffle(temp)
    x=temp.copy()
    values_data.append(s.minPairSum(x))
    keys_data[-1]+=" ".join(map(str,temp))

for j in range(6,10):
    temp=[]
    random_number = random.randint(500, 1000) #n
    keys_data.append(f"{random_number}\n")
    for i in range(random_number):
        temp.append(random.randint(1, 10**8))
        random.shuffle(temp)
    x=temp.copy()
    values_data.append(s.minPairSum(x))
    keys_data[-1]+=" ".join(map(str,temp))

data_dict = dict(zip(keys_data, values_data))

save_keys_to_text_files(data_dict, 'output_folder')
