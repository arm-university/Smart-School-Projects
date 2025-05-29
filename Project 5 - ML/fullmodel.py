import scipy
import numpy
import pandas
import sklearn
from pandas import read_csv
#from sklearn.model_selection import StratifiedKFold
from sklearn.model_selection import train_test_split
#new imports
#import pandas as pd
import seaborn as sns
from sklearn.ensemble import RandomForestClassifier
#from sklearn.svm import SVC
from sklearn import svm
from sklearn.neural_network import MLPClassifier
#from sklearn.linear_model import SGDClassifier
#from sklearn.metrics import confusion_matrix, classification_report
from sklearn.preprocessing import StandardScaler, LabelEncoder
#from sklearn.model_selection import train_test_split
headers=['Sepal Length','Sepal Width','Petal Length','Petal Width','Class']
dataset=read_csv("iris.csv",names=headers)
print(dataset.shape)
print(dataset.head(10))
print(dataset.describe())
print(dataset.groupby('Class').size())
print(dataset)
array = dataset.values
X = array[:,0:4]
y = array[:,4]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.20, random_state=1)
##test
sc = StandardScaler()  #scaling
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)
X_train[:10]
rfc = RandomForestClassifier(n_estimators=200) #how many trees in the forest? how many models?
rfc.fit(X_train, y_train)
pred_rfc = rfc.predict(X_test)
pred_rfc[:20]
#How well has the model performed?
#print(classification_report(y_test, pred_rfc))
#print(confusion_matrix(y_test, pred_rfc))
#clf = svm.SVC()
#clf.fit(X_train, y_train)
#pred_clf = clf.predict(X_test)
#How well has the model performed?
#print(classification_report(y_test, pred_clf))
#print(confusion_matrix(y_test, pred_clf))
#3 hidden layers of 11 nodes each, since we have 11 variables
mlpc = MLPClassifier(hidden_layer_sizes=(11,11,11), max_iter=1000) #default max iteration is 200
mlpc.fit(X_train, y_train)
#pred_mlpc = mlpc.predict(X_test)
#How well has the model performed?
#print(classification_report(y_test, pred_mlpc))
#print(confusion_matrix(y_test, pred_mlpc))
#from sklearn.metrics import accuracy_score
#cm = accuracy_score(y_test, pred_rfc)
#print(cm)
Xnew = [[5.1,3.5,1.4,0.2]]
Xnew = sc.transform(Xnew)
ynew = rfc.predict(Xnew)
print("Precicted Classification",ynew)