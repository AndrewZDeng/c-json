import json

file = open("./cmake-build-debug/test.json", 'r')

while fileline := file.readline():
		dic = json.loads(fileline)
		print(dic)

file.close()