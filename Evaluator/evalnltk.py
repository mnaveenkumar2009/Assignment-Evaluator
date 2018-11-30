import nltk
from nltk.classify import NaiveBayesClassifier

import os
# print(os.listdir("student"))
import math

from nltk.corpus import subjectivity
from nltk.sentiment import SentimentAnalyzer
from nltk.sentiment.util import *

from nltk.sentiment.vader import SentimentIntensityAnalyzer

sid = SentimentIntensityAnalyzer()

ss  = (sid.polarity_scores("sentence is not nice"))
# print(ss['neg'])
# print(ss['pos'])
# print(ss['neu'])
# print(ss['compound'])
f =open("teacher/noq.txt")
noq= (int(f.read()))
print(noq)
for qnno in range(noq):
    f= open("student/answer"+str(qnno)+".txt")
    xxxx=0.0
    comp = 0.0
    for line in f.readlines():
        xxxx+=1.0
        comp += sid.polarity_scores(line)['compound']
    comp/=xxxx
    # print (comp)
    
    f= open("teacher/answer"+str(qnno)+".txt")
    xxxx=0.0
    comp2 = 0.0
    for line in f.readlines():
        xxxx+=1.0
        comp2 += sid.polarity_scores(line)['compound']
    comp2/=xxxx
    # print(comp2)

    f= open("mismatchs/m"+str(qnno)+".txt","w+")
    mism=1
    if comp2>=0 and comp >=0:
        mism=0
    if comp<=0 and comp2<=0:
        mism=0
    absdif=(comp-comp2)
    if absdif<0:
        absdif=-absdif
    if(absdif<0.1):
        mism=0
    f.write(str(mism))