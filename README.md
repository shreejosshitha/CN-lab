# Computer Networks Lab Programs

This repository contains Computer Networks lab programs for Experiments 2, 4, 5 and 6.

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
├── Exp6/
│   ├── tcps.java
│   ├── tcpc.java
│   ├── udpp.java
│   └── udps.java
└── .gitignore
```

## Experiment 2: Error Detection

### 1. CRC

File: `Exp2/crc.c`

```bash
cd Exp2
clang crc.c -o crc
./crc
```

Sample output:

```text
CRC
1. Transmitting side
2. Receiving side
3. Exit
Enter your choice: 1
Enter data bits: 1101
Enter divisor bits: 1011
Remainder: 001
Codeword to send: 1101001
```

To test the receiving side, select `2` and enter the complete codeword `1101001` and divisor `1011`.

### 2. Checksum

File: `Exp2/checksum.c`

```bash
cd Exp2
clang checksum.c -o checksum
./checksum
```

Sample output:

```text
Checksum
1. Transmitting side
2. Receiving side
3. Exit
Enter your choice: 1
Enter number of data bytes: 4
Enter data bytes (0-255): 100 50 30 20
Checksum: 55
Data sent: 100 50 30 20 55
```

## Experiment 4: ARP and RARP

Files:
- `Exp4/arps.java` — ARP server
- `Exp4/arpc.java` — ARP client
- `Exp4/rarps.java` — RARP server
- `Exp4/rarpc.java` — RARP client

Compile:

```bash
cd Exp4
javac arps.java arpc.java rarps.java rarpc.java
```

### ARP

Terminal 1:

```bash
java arps
```

Terminal 2:

```bash
java arpc
```

Sample client output:

```text
Enter IP address: 172.16.5.200
MAC address: 12.13.24.0.0.1
```

### RARP

Stop the ARP server using `Ctrl+C`, then run this in Terminal 1:

```bash
java rarps
```

Terminal 2:

```bash
java rarpc
```

Sample client output:

```text
Enter MAC address: 12.13.24.0.0.3
IP address: 172.16.5.202
```

## Experiment 5: Routing Algorithms

### 3. RIP — Distance Vector Routing

File: `Exp5/rip.c`

```bash
cd Exp5
clang rip.c -o rip
./rip
```

Sample output:

```text
Enter number of entries: 3
Enter network ID, cost and hop: 1 2 1
Enter network ID, cost and hop: 2 4 2
Enter network ID, cost and hop: 3 5 3

Routing Table
Network Cost    Hop
1       2       1
2       4       2
3       5       3

Updated Routing Table
1       3       1
2       5       2
3       6       3
```

### 4. OSPF — Link State Routing

File: `Exp5/ospf.c`

```bash
cd Exp5
clang ospf.c -o ospf
./ospf
```

Sample output:

```text
Enter number of routers: 4
Enter cost matrix (9999 for no link):
0 1 4 9999
1 0 2 6
4 2 0 3
9999 6 3 0
Enter source router: 0

Shortest paths from router 0:
To router 0: 0
To router 1: 1
To router 2: 3
To router 3: 6
```

## Experiment 6: TCP and UDP

### 5. TCP File Listing

Files: `Exp6/tcps.java`, `Exp6/tcpc.java`

Compile:

```bash
cd Exp6
javac tcps.java tcpc.java
```

Terminal 1:

```bash
java tcps
```

Terminal 2:

```bash
java tcpc
```

Sample output:

```text
Enter directory path: .
tcps.java
tcpc.java
udpp.java
udps.java
```

Server output:

```text
Waiting for connection...
Connection accepted...
Processing files in .
List sent to the client...
```

### 6. UDP Peer Communication

Files: `Exp6/udpp.java`, `Exp6/udps.java`

Compile:

```bash
cd Exp6
javac udpp.java udps.java
```

Terminal 1:

```bash
java udpp
```

Enter your port as `6000` and peer's port as `7000`.

Terminal 2:

```bash
java udps
```

Enter your port as `7000` and peer's port as `6000`.

Sample output:

Peer 1:

```text
Enter your port: 6000
Enter peer's port: 7000
You: Hi from 6000!
Peer: Hello, I got it from 7000!
```

Peer 2:

```text
Enter your port: 7000
Enter peer's port: 6000
You: Hello, I got it from 7000!
Peer: Hi from 6000!
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

- Start servers before connecting clients.
- Run network programs in separate terminals.
- The ARP/RARP examples use predefined address mappings.
- The RIP program is a simplified routing-table demonstration.
- The TCP program sends file names, not file contents.
- The UDP example uses localhost for communication between programs on the same computer.
