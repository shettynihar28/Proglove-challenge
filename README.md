# Proglove-challenge
Abstract:
Built a small TCP/IP based client-server, where the client system takes the arbitrary length input , splits it into packages of 20 bytes length, transmits it over a socket to the server where server reassembles the received data.

Dependencies used: Socket programming using C, Ubuntu OS with GCC compiler for execution. 

File Discription: 
split.c: initial program to split the received code into 20byte arrays/packets.
server.c: program to setup a server for the communication between client and server and receive the packets from client. 
client.c: Program to setup a client for the communication between client and server to accept a long input data, splitting it into 20 byte packets and sending them to the server.

Output can be seen in the Output.png file.
