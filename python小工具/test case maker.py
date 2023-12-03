import os

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

keys_data = ["12 3", "1200 5", "1200 1200", "3 2", "25326 3652", "456987 326596", "8492 142", "15881 300", "10677 119", "1000 5"]
values_data = [17, 1499, 1201, 5, 25332, 456988, 8552, 15934, 10767, 1249]

data_dict = dict(zip(keys_data, values_data))

save_keys_to_text_files(data_dict, 'output_folder')
