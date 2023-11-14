import socket

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Define the server address and port
server_address = ('localhost', 12345)

# Connect to the server
client_socket.connect(server_address)
print("Connected to server:", server_address)

while True:
    # Send message to the server
    message = input("Client: ")
    client_socket.send(message.encode())

    # Check if the client wants to terminate the conversation
    if message.lower() == "bye" or message.lower() == "exit":
        break

    # Receive response from the server
    response = client_socket.recv(1024).decode()
    print("Server:", response)

# Close the connection
client_socket.close()
