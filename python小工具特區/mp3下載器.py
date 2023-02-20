import os
from pytube import YouTube

def change_file_name(name):
    old_name=name+".mp4"
    new_name=name+".mp3"
    os.rename("D:\\"+old_name,"D:\\"+new_name)

while 1:
    try:
        #print(os.getcwd())
        link=YouTube(input())
        link.streams.filter().get_audio_only().download("D:")
        vedio_title=link.title
        change_file_name(vedio_title)
        print("Download completed")
    except:
        print("wrong")