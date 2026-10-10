# CN Lab Experiments

This repository contains simplified, runnable implementations for Computer Networks lab experiments 2, 4, 5, and 6.

## Folder structure

```text
CN-Lab/
├── README.md
├── Exp2/
│   ├── crc.c
│   └── checksum.c
├── Exp4/
│   ├── arps.java
│   ├── arpc.java
│   ├── rarps.java
│   └── rarpc.java
├── Exp5/
│   ├── rip.c
│   └── ospf.c
└── Exp6/
    ├── TCPServer.java
    ├── TCPClient.java
    ├── udp_server.py
    └── udp_client.py
```

## Experiment 2 - CRC and checksum

### C program for CRC

```bash
cd Exp2
clang crc.c -o crc
./crc
```

Example:

```text
Enter data bits: 101100
Enter divisor bits: 1101
Remainder: 011
```

### C program for checksum

```bash
cd Exp2
clang checksum.c -o checksum
./checksum
```

Example input:

```text
4
100 50 30 20
```

## Experiment 4 - ARP and RARP

Compile Java files:

```bash
cd Exp4
javac arps.java arpc.java rarps.java rarpc.java
```

### ARP

Terminal 1:

```bash
cd Exp4
java arps
```

Terminal 2:

```bash
cd Exp4
java arpc
```

Input:

```text
172.16.5.200
```

Expected MAC:

```text
12.13.24.0.0.1
```

### RARP

Stop the ARP server, then run:

Terminal 1:

```bash
cd Exp4
java rarps
```

Terminal 2:

```bash
cd Exp4
java rarpc
```

Input:

```text
12.13.24.0.0.3
```

Expected IP:

```text
172.16.5.202
```

## Experiment 5 - Routing algorithms

### RIP example

```bash
cd Exp5
clang rip.c -o rip
./rip
```

### OSPF / Dijkstra example

```bash
cd Exp5
clang ospf.c -o ospf
./ospf
```

Example input:

```text
4
0 1 4 9999
1 0 2 6
4 2 0 3
9999 6 3 0
0
```

Expected output:

```text
Shortest paths from router 0:
To router 0: 0
To router 1: 1
To router 2: 3
To router 3: 6
```

## Experiment 6 - TCP and UDP

### TCP

```bash
cd Exp6
javac TCPServer.java TCPClient.java
```

Terminal 1:

```bash
cd Exp6
java TCPServer
```

Terminal 2:

```bash
cd Exp6
java TCPClient
```

Expected output:

```text
Server: Message received
```

### UDP

Terminal 1:

```bash
cd Exp6
python3 udp_server.py
```

Terminal 2:

```bash
cd Exp6
python3 udp_client.py
```

Enter a message such as:

```text
Hello Server
```

Expected output:

```text
Server: Message received
```

## GitHub setup

Create a new repository on GitHub called `CN-Lab` and then run:

```bash
cd CN-Lab
git init
git add .
git commit -m "Add Computer Networks lab experiments"
git branch -M main
git remote add origin https://github.com/YOUR-USERNAME/CN-Lab.git
git push -u origin main
```

Replace `YOUR-USERNAME` with your GitHub username.

## Notes

These are simplified learning implementations for classroom use. They demonstrate the core logic of CRC, checksum, ARP/RARP, routing examples, and TCP/UDP communication in a runnable format.
