import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
msg = input("Enter message: ")
s.sendto(msg.encode(), ("127.0.0.1", 6000))
data, addr = s.recvfrom(1024)
print("Server:", data.decode())
s.close()
