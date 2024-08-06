from keras.datasets import mnist
from keras.models import Sequential
from keras.layers import Dense, Flatten

# Load the training and testing sets
(train_X, train_y), (test_X, test_y) = mnist.load_data()


# Create a sequential model
model = Sequential()

# Add layers to the model
model.add(Flatten(input_shape=(28, 28)))  # Flatten the 28x28 images
model.add(Dense(128, activation='relu'))  # Hidden layer with 128 neurons and ReLU activation
model.add(Dense(10, activation='softmax'))  # Output layer with 10 classes (digits) and softmax activation

# Compile the model
model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])

# Train the model
model.fit(train_X, train_y, epochs=5)  # Use ds_train if you're using TFDS, or train_X and train_y if using Keras
