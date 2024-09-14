import mosspy, os

userid = os.getenv('MOSS_KEY')

m = mosspy.Moss(userid, "cc")

# m.addBaseFile("")

# Submission Files
# m.addFile("submission/a01-sample.py")
m.addFilesByWildcard("test/*.cpp")

url = m.send() # Submission Report URL

print ("Report Url: " + url)

# Save report file
m.saveWebPage(url, "report.html")

# Download whole report locally including code diff links
mosspy.download_report(url, "submission/report/", connections=8)