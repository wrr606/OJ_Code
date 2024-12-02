num_files = 5

for i in range(num_files):
    s="a065"
    in_filename = f"{s}_{i:02d}.in"
    out_filename = f"{s}_{i:02d}.out"
    
    with open(in_filename, 'w') as f_in:
        f_in
    
    with open(out_filename, 'w') as f_out:
        f_out

    print(f"已創建檔案：{in_filename} 和 {out_filename}")