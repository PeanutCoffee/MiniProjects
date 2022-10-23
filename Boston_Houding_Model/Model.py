# Importing Modules
import numpy as np
import pandas as pd
import sklearn

# Importing and Loading Dataset
from sklearn.datasets import load_boston
df = load_boston()
df.keys()

print(df.data)

# Analyzing Dataset using Pandas
boston = pd.DataFrame(df.data, columns=df.feature_names)
boston.head(10)

boston['MEDV'] = df.target
boston.head(10)

boston.isnull()

boston.isnull().sum()

# Importing Algos
from sklearn.model_selection import train_test_split
X = boston.drop('MEDV', axis=1)
Y = boston['MEDV']
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size = 0.15, random_state=4)

print(X_train.shape)
print(X_test.shape)
print(Y_train.shape)
print(Y_test.shape)

# Importing the Linear Regression Model
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

# Training Model
lin_model = LinearRegression()
lin_model.fit(X_train, Y_train)

# Predictions
y_train_predict = lin_model.predict(X_train)
rmse = (np.sqrt(mean_squared_error(Y_train, y_train_predict)))

print('RMSE is {}'.format(rmse))

y_test_predict = lin_model.predict(X_test)
rmse = (np.sqrt(mean_squared_error(Y_test, y_test_predict)))

print('RMSE is {}'.format(rmse))