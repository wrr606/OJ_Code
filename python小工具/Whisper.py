import os
import time
from faster_whisper import WhisperModel
from opencc import OpenCC

os.environ['KMP_DUPLICATE_LIB_OK']='True'

# 設定影片名稱
file_name="test"

# https://techdiylife.github.io/blog/blog.html?category1=c02&blogid=0021
# 更，幸好我有留這個網址...
os.environ["PATH"] += os.environ["PATH"] \
    +  ";" +  r"C:\Users\Function\AppData\Local\Programs\Python\Python312\Lib\site-packages\nvidia\cudnn\bin" \
    +  ";" +  r"C:\Users\Function\AppData\Local\Programs\Python\Python312\Lib\site-packages\nvidia\cublas\bin"

start_time = time.time()

#model 在 c:\Users\Function\.cache 中
model_size = "large-v3"

# Run on GPU with FP16
model = WhisperModel(model_size, device="cuda", compute_type="float16")

# or run on GPU with INT8
#model = WhisperModel(model_size, device="cuda", compute_type="int8_float16")
# or run on CPU with INT8
#model = WhisperModel(model_size, device="cpu", compute_type="int8")
print(f"Model load: {time.time()-start_time} s")

start_time = time.time()
segments, info = model.transcribe(file_name+".mp4", beam_size=5,vad_filter=True,word_timestamps=True)
print(f"Recognition: {time.time()-start_time} s")

print("Detected language '%s' with probability %f" % (info.language, info.language_probability))

def convert_to_traditional_chinese(text):
    cc = OpenCC('s2twp')
    return cc.convert(text)

subtitles=[]
for segment in segments:
    text=convert_to_traditional_chinese(segment.text)
    subtitles.append((float(format(segment.start,'.2f')), float(format(segment.end,'.2f')),text))
    print((float(format(segment.start,'.2f')), float(format(segment.end,'.2f')),text))

def convert_to_srt(subtitles):
    srt_content = ""
    count = 1
    for subtitle in subtitles:
        start_time = int(subtitle[0] * 1000)
        end_time = int(subtitle[1] * 1000)
        srt_content += f"{count}\n"
        srt_content += f"{format_time(start_time)} --> {format_time(end_time)}\n"
        srt_content += f"{subtitle[2]}\n\n"
        count += 1
    return srt_content

def format_time(milliseconds):
    seconds, milliseconds = divmod(milliseconds, 1000)
    minutes, seconds = divmod(seconds, 60)
    hours, minutes = divmod(minutes, 60)
    return f"{hours:02d}:{minutes:02d}:{seconds:02d},{milliseconds:03d}"

srt_content = convert_to_srt(subtitles)

cnt=1
while 1:
    output_file = f"{file_name}{cnt}.srt"
    if not os.path.exists(output_file):
        with open(f"{file_name}.srt" if cnt == 1 else f"{file_name}{cnt}.srt", "w", encoding="utf-8") as file:
            file.write(srt_content)
        break
    cnt+=1
print("END")