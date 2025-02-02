import mosspy, os

userid = os.getenv('MOSS_KEY')

m = mosspy.Moss(userid, "cc")

# m.addBaseFile("")

# Submission Files
# m.addFile("submission/a01-sample.py")
def add_cpp_files_recursively(folder_path):
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            if file.endswith(".cpp") or file.endswith(".c"):
                full_path = os.path.join(root, file)
                m.addFile(full_path)
                print(f"已添加檔案: {full_path}")
add_cpp_files_recursively("homework")

# m.addFilesByWildcard("homework/*.cpp")

url = m.send() # Submission Report URL

print ("Report Url: " + url)

# Save report file
m.saveWebPage(url, "report.html")

# Download whole report locally including code diff links
mosspy.download_report(url, "submission/report/", connections=8)