import os,time

if raw_input()=="1":
    os.system("cd Model/pre_process && python preprocess.py")

    os.system("cd assignment && git add .")
    os.system("cd assignment && git commit -m \"1\"")
    os.system("cd assignment && git push")

os.system("cd Model/Training/src && python main.py --gettext")
print("The text:\n")
f= open("Evaluator/student/answer"+".txt")

for line in f.readlines():
    print (line)
os.system("cd Evaluator && ./set_questions")