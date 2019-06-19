import json

def main(): 
    inMenu = True
    while inMenu:
        print("\nSelect a lesson :")

        for i in range(0, len(data)):
            print(str(i) + " - Lesson " + str(data[i]["lessonNumber"]) + " | " + data[i]["languageFrom"] + " to " + data[i]["languageTo"])

        correctNumber = False
        while not correctNumber:
            numberSelect = input("Lesson number select : ")
            try: 
                int(numberSelect)
                correctNumber = True
            except ValueError:
                print("Selection incorrect")


        lessonFrom = data[int(numberSelect)]["languageFrom"]
        lessonTo = data[int(numberSelect)]["languageTo"]
        lessonData = data[int(numberSelect)]["words"]

        correctRep = 0
        for i in range(0, len(lessonData)):
            print("\n---------------------------\n" + lessonFrom + " : " + lessonData[i]["origin"])
            rep = input(lessonTo + " : ")
            if rep == lessonData[i]["translate_1"] or rep == lessonData[i]["translate_2"]:
                print("Correct answer")
                correctRep += 1
            else:
                print("Wrong answer")
                print("Correction : " + lessonData[i]["translate_1"] + " | " + lessonData[i]["translate_2"])
        
        percent = correctRep / len(lessonData) * 100
        print("\n---------------------------\nOverall result : " + str(round(percent)) + " % good answers")

        rep = ""
        while rep != "y" and rep != "n":
            rep = input("\n---------------------------\nNew test ? (y/n) : ")
        
        if rep == "n":
            inMenu = False

if __name__ == "__main__":
    with open("data.json") as f:
        data = json.load(f)
    main()