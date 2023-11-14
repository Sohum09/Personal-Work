import socket

s = socket.socket()
print("Socket created.")

port = 12345

s.bind(('', port))
print("socket binded to %s" %(port))

s.listen(5)
print("Socket listening for connections...")

while True:
    c, addr = s.accept()
    print("Got connection from", addr)

    c.send("Thank you for connecting".encode())
    c.close()

    break