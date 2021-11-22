import scipy
import numpy
import pandas
import sklearn
from pandas import read_csv
from sklearn.model_selection import train_test_split
#new imports
from sklearn.ensemble import RandomForestClassifier
from sklearn import svm
from sklearn.neural_network import MLPClassifier
from sklearn.preprocessing import StandardScaler, LabelEncoder

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
sc = StandardScaler()  #scaling
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)
X_train[:10]
rfc = RandomForestClassifier(n_estimators=200) #how many trees in the forest? how many models?
rfc.fit(X_train, y_train)
mlpc = MLPClassifier(hidden_layer_sizes=(11,11,11), max_iter=1000) #default max iteration is 200
mlpc.fit(X_train, y_train)
S_length=float(input("Enter sepal Length"))
S_width=float(input("Enter sepal Width"))
P_length=float(input("Enter Petal Length"))
P_width=float(input("Enter Petal Width"))

predictClassInputs=[[S_length,S_width,P_length,P_width]]
predictClassInputs = sc.transform(predictClassInputs)
predictedClass = rfc.predict(predictClassInputs)
print("Precicted Classification",predictedClass[0])