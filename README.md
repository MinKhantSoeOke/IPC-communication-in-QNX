# Synchronous IPC using QNX Neutrino RTOS

**by**: Min Khant Soe Oke, Kaung Sithu

## Overview

This project implements synchronous interprocess communication (IPC) using the Send-Receive-Reply model in QNX Neutrino RTOS. The project includes a server and a client application where the server handles incoming requests from clients and responds with the appropriate results. This exercise aims to enhance understanding of IPC mechanisms, crucial for developing efficient and responsive real-time systems.

## Dependencies

**To run this project, you need to have the following dependencies installed:**

* QNX Neutrino RTOS
* Basic knowledge of C programming
* Familiarity with system calls in Unix-like operating systems
* Understanding of interprocess communication concepts and client-server architectures

## Features

**Interprocess Communication (IPC)**
- Enables processes to communicate and synchronize their actions.
- Utilizes message passing for direct data exchange between processes.

**Send-Receive-Reply Model**
- Ensures synchronous communication where the client sends a message to the server, the server processes it, and replies back.

**Name Registration**
- Uses QNX's naming service for dynamic and flexible communication between unrelated processes.

## How to Use

1. **Start the Server**:
   - Open a terminal and run `./server`.

2. **Start the Client**:
   - Open another terminal and run `./client`.

3. **Client-Server Interaction**:
   - The client will send a series of messages to the server.
   - The server will process each message and send a reply.
   - The client will display the received replies.

## Authors

- Min Khant Soe Oke
- Kaung Sithu
