import nltk
from nltk.classify import NaiveBayesClassifier

import os
print(os.listdir("student"))
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

f= open("student/answer.txt")
xxxx=0.0
comp = 0.0
for line in f.readlines():
    xxxx+=1.0
    comp += sid.polarity_scores(line)['compound']
# comp/=xxxx
# print (comp)
comp/=xxxx
f= open("teacher/answer"++".txt")
xxxx=0.0
comp = 0.0
for line in f.readlines():
    xxxx+=1.0
    comp += sid.polarity_scores(line)['compound']
# comp/=xxxx
# print (comp)
comp/=xxxx