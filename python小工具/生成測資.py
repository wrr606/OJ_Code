import subprocess

s="a072"
FILE_NAME="test.cpp"
question=[
     "2\n1",
     "6\n2 3 1 5 6",
     "10\n2 8 10 6 5 1 3 7 4",
]

compile_command = ["g++" if FILE_NAME[-1]=='p' else "gcc", FILE_NAME, "-o", "test.exe"]
compile_process = subprocess.run(compile_command, capture_output=True, text=True)

for i, j in enumerate(question):
    in_filename = f"{s}_{i:02d}.in"
    out_filename = f"{s}_{i:02d}.out"
    
    with open(in_filename, 'w') as f_in:
        f_in.write(j)
    
    with open(out_filename, 'w') as f_out:
        f_out

    print(f"MAKE：{in_filename} and {out_filename}")

    with open(in_filename, "r") as infile:
            run_command = ["./test.exe"]
            run_process = subprocess.run(run_command, stdin=infile, stdout=open(out_filename, "w"), stderr=subprocess.PIPE, text=True)