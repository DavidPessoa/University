import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt
import scipy, math
from sklearn.metrics import mean_squared_error, r2_score, accuracy_score


print("List of commands:\n -printData()\n -meanSqError()\n -variance()",
      "\n -predict(Time, Distance, Rate code)\n -dataDistribution() \n -dataPlots()")
        

dataset = pd.read_csv('taxi.csv')
        
# PREPROCESSING CODE -------------------------------------------------------------

#Limiting the fate amount to bigger than 0
dataset = dataset[dataset.fare_amount > 0]

# Limiting the minimum travel time of 30s
dataset = dataset[dataset.trip_time_in_secs >30]

#The trips have to have passengers
dataset = dataset[dataset.passenger_count > 0]  

#Creation of speed column
dataset['speed'] = ((dataset.trip_distance*1.0)/dataset.trip_time_in_secs)*3600 

#Limiting speed
dataset = dataset[(dataset.speed < 100.0) & (dataset.speed > 2.0)]

#--------------------LINEAR REGRESSION--------------------------------------------------#


X = np.array(dataset[['trip_time_in_secs','trip_distance','rate_code']])  
Y = np.array(dataset[['fare_amount']])

#This line splits the data for thee testing and the data for the training  
X_train, X_test, Y_train, Y_test = train_test_split(X,Y,test_size=0.2,random_state = 4)

regr = LinearRegression()
regr.fit(X_train,Y_train)

Y_pred = regr.predict(X_test)

def printData():
    print(dataset)

def meanSqError():
    print("Mean squared error: %.2f" % mean_squared_error(Y_test, Y_pred))

def variance():    
    print('Variance score: %.2f' % r2_score(Y_test, Y_pred))
   
def predict(time, distance, rate_code):
    pred = regr.predict(np.array([[time,distance,rate_code]]))
    print(pred[0][0])

#------------------PLOTING SECTION------------------------------------------------------#

def dataDistribution():

    plt.figure('Histogram Fare')
    plt.hist(dataset.fare_amount, bins=[0, 10, 20, 30, 40, 50, 100,120])
    plt.xlabel('Trip fare')

    plt.figure('Histogram Time')
    plt.hist(dataset.trip_time_in_secs)
    plt.xlabel('Trip time')

    plt.figure('Histogram Distance')
    plt.hist(dataset.trip_distance)
    plt.xlabel('Trip distance')
    plt.ylabel('Frequency')

    plt.figure('Histogram Rate')
    plt.hist(dataset.rate_code)
    plt.xlabel('Rate Code')
    plt.ylabel('Frequency')
    plt.show()



def dataPlots():
    plt.figure("Distance/Fare")
    plt.plot(dataset.fare_amount,dataset.trip_distance, linestyle='', marker='o', markersize=0.7)
    plt.xlabel('Fare amount')
    plt.ylabel('Trip distance')

    plt.figure("Distance/Time")
    plt.plot(dataset.trip_time_in_secs, dataset.trip_distance ,linestyle='', marker='o', markersize=0.7)
    plt.xlabel('Trip time')
    plt.ylabel('Trip distance')

    plt.figure("Time/Fare")
    plt.plot(dataset.fare_amount, dataset.trip_time_in_secs ,linestyle='', marker='o', markersize=0.7)
    plt.xlabel('Fare amount')
    plt.ylabel('Trip time')

    plt.figure("Rate/Fare")
    plt.plot(dataset.fare_amount, dataset.rate_code ,linestyle='', marker='o', markersize=0.7)
    plt.xlabel('Fare amount')
    plt.ylabel('Rate Code')
    plt.show()

