import numpy as np
from keras.models import Sequential
from keras.layers import Dense

# XOR inputs and outputs
inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
outputs = np.array([[0], [1], [1], [0]])

# Create a sequential model
model = Sequential()

# Add layers
model.add(Dense(2, input_dim=2, activation='relu'))
model.add(Dense(1, activation='sigmoid'))

# Compile the model
model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['accuracy'])

# Train the model
model.fit(inputs, outputs, epochs=500, verbose=0)

# Evaluate the model
print(model.evaluate(inputs, outputs)
