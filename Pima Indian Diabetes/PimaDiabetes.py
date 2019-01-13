import pandas as pd
import numpy as np
import tensorflow as tf
from keras.models import Sequential
from keras.layers import Dense, Activation
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import cross_validate, StratifiedKFold
from sklearn.ensemble import GradientBoostingClassifier, AdaBoostClassifier, ExtraTreesClassifier
from sklearn.metrics import classification_report

def load_dataset(filename):
    data = pd.read_csv(filename + ".csv")
    print("data for " + filename + " loaded successfully")
    X = data.iloc[1:, 0:8]
    y = data.iloc[1:, 8]
    #X = data.iloc[1:, 17:]
    #y = data.iloc[1:, 6]
    return X, y

def SVM(X, y, crit):
    clf = SVM(criterion = crit, kernel = 'linear')
    clf.fit(X, y)
    scoring={'accuracy':'accuracy'}
    folds = StratifiedKFold(n_splits = 5, shuffle = True, random_state = 1234)
    scores = cross_validate(clf, X, y,  scoring=scoring, return_train_score=False, cv=folds)
    print(scores['test_accuracy'].mean())

def decisionTree(X, y, crit):
    clf = DecisionTreeClassifier(criterion = crit)
    clf.fit(X, y)
    scoring={'accuracy':'accuracy'}
    folds = StratifiedKFold(n_splits = 5, shuffle = True, random_state = 1234)
    scores = cross_validate(clf, X, y,  scoring=scoring, return_train_score=False, cv=folds)
    print(scores['test_accuracy'].mean())

def ada(X, y):
    clf = AdaBoostClassifier(DecisionTreeClassifier(max_depth=5),algorithm="SAMME",n_estimators=50)
    scoring={'accuracy':'accuracy'}
    folds = StratifiedKFold(n_splits = 5, shuffle = True, random_state = 1234)
    scores = cross_validate(clf, X, y,  scoring=scoring, return_train_score=False, cv=folds)
    print(scores['test_accuracy'].mean())
    
def neuralNet(X, y):
    model = Sequential()
    model.add(Dense(15, input_dim = 8, init = 'uniform', activation = 'relu'))
    model.add(Dense(10, init = 'uniform', activation = 'relu'))
    model.add(Dense(1, init = 'uniform', activation = 'sigmoid'))
    model.compile(loss = 'binary_crossentropy', optimizer = 'adam', metrics = ['accuracy'])
    model.fit(X, y, nb_epoch = 150, batch_size = 10)
    scores = model.evaluate(X, y)
    print(model.metrics_names[1], scores[1])
    
def main():
    filename = "Pima Indians Diabetes Binary Classification dataset"
    X, y = load_dataset(filename)
    #decisionTree(X, y, 'gini')
    #ada(X, y)
    neuralNet(X, y)
    

main()
