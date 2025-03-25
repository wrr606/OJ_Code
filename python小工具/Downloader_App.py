import tkinter as tk
import yt_dlp
import os
import threading

ffmpeg_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'ffmpeg.exe')

def download_video(url, output_path='.'):
    ydl_opts = {
        'format': 'bestvideo+bestaudio/best',
        'outtmpl': f'{output_path}/%(title)s.%(ext)s',
        'merge_output_format': "mp4",
        'ffmpeg_location': ffmpeg_path
    }
    with yt_dlp.YoutubeDL(ydl_opts) as ydl:
        ydl.download([url])

def download_sound(url, output_path='.'):
    ydl_opts = {
        'format': 'bestaudio/best',
        'outtmpl': f'{output_path}/%(title)s.%(ext)s',
        'postprocessors': [{
            'key': 'FFmpegExtractAudio',
            'preferredcodec': 'mp3',  
            'preferredquality': '192', 
        }],
        'ffmpeg_location': ffmpeg_path
    }
    with yt_dlp.YoutubeDL(ydl_opts) as ydl:
        ydl.download([url])

root = tk.Tk()
root.title("Youtube Downloader")
root.geometry("300x300")

selected_option = tk.StringVar(value="mp4")

options = [("mp4", "mp4"), ("mp3", "mp3")]

for text, value in options:
    tk.Radiobutton(root, text=text, variable=selected_option, value=value).pack()

entry = tk.Entry(root, width=30)
entry.pack(pady=5)
warning = tk.Label(root, text="", font=("Arial", 12))
warning.pack(pady=10)

def on_button_click():
    def download_task():
        try:
            warning.config(text="Downloading...")
            if selected_option.get() == "mp4":
                download_video(entry.get())
            else:
                download_sound(entry.get())
            warning.config(text="Download Complete")
        except:
            warning.config(text="ERROR!!")
    
    threading.Thread(target=download_task, daemon=True).start()
    
button = tk.Button(root, text="download", command=on_button_click)
button.pack(pady=10)

root.mainloop()