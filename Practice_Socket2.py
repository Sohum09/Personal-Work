import socket
import sys

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print ("Yo you entered the socketverse")
except socket.error as err:
    print("Access denied. Error code: {}".format(err))

port = 80

try:
    host_ip = socket.gethostbyname('www.google.com')
except socket.gaierror:
    print("Host address not resolved")
    sys.exit()

s.connect((host_ip, port))
print("Connection successful")