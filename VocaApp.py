import json

with open("data.json") as f:
    d = json.load(f)

print("\nSelect a lesson :")

for i in range(0, len(d)):
    print(str(i) + " - Lesson " + str(d[i]["lessonNumber"]) + " | " + d[i]["languageFrom"] + " to " + d[i]["languageTo"])

numberSelect = input("Lesson number select : ")

lessonFrom = d[int(numberSelect)]["languageFrom"]
lessonTo = d[int(numberSelect)]["languageTo"]
lessonData = d[int(numberSelect)]["words"]

for i in range(0, len(lessonData)):

    print("\n---------------------------\n" + lessonFrom + " : " + lessonData[i]["origin"])
    rep = input(lessonTo + " : ")
    if rep == lessonData[i]["translate_1"] or rep == lessonData[i]["translate_2"]:
        print("Correct answer")
    else:
        print("Wrong answer")
    