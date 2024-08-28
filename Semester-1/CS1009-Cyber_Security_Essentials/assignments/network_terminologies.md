# Cybersecurity essentials

**Write briefly about each network terminologies, add architecture/flowchart representation wherever needed**

***Submit by 14 September***

## Terms

1. Router
2. Switch
3. IP Address
4. LAN
5. WAN
6. DHCP
7. Firewall
8. DNS
9. Subnet
10. Gateway
11. NAT
12. VPN
13. OSI Model
14. Modem
15. Port forwarding
16. ISP
17. Packet
18. MAC Address
19. ARP
20. SNMP
21. FTP
22. SMTP
23. DDoS
24. MITM
25. SSL

<hr>

## Answers

1. Router

A router is a physical device that connects two or more subnetworks. It primarily forwards data packets to their intended IP addresses and allows multiple devices to use the same network connections. A common use of the router is to connect a device to the internet.

2. Switch

A switch is a device which connects devices withing a network (or a subnetwork). Unlike a router, a switch is intended to be used within a network, not between two networks. A switch forwards data packets between different devices within the same network.

3. IP Address

IP Address is an abbreviation for *Internet Protocol* Address. It is the basic entity required for intercommunication between network devices. An IP address is essentially an address assigned to a device when it is connected to a network, and it used to reach that particular device later.
There are two types of IP addresses, namely private IP address and public IP address. Public IP addresses can either be static or dynamic. There are two versions of IP addresses in wide use today, namely IPv4 (version 4, 32 bits) and IPv6 (version 6, 128 bits)

4. LAN

LAN is an abbreviation for Local Area Network. A LAN is a computer network (collection of devices) connected together in a limited area (mostly one physical location) like home, school, office building, etc.

5. WAN

WAN is an abbreviation for Wide Area Network. A WAN is a computer network that connects multiple LANs over large distances. A WAN can be public or private. Private WANs are used by businesses to interconnect their buildings. The largest public WAN is the internet.

6. DHCP

DHCP is an abbreviation for Dynamic Host Configuration Protocol. It is a network management protocol that assigns IP addresses and other parameters (like DNS servers, gateway, etc) to devices that requests them. A DHCP server is commonly present in a switch or router, but it can be a separate device too.

7. Firewall

A firewall blocks unauthorized network access from outside the network to inside and/or vice-versa. A firewall filters the incoming packets from the internet and uses rules to determine whether to allow or deny the packet. The set of rules (or filters) is called an Access Control List (ACL). There are commonly two types of firewall, namely Host-based firewall and Network-based firewall.present

8. DNS

DNS is an abbreviation for Domain Name System. A DNS is commonly used to resolve a domain name to an IP address so computers can reach it. A DNS maps computers, services, websites and other resources on the inter to human-friendly names.

9. Subnet

A subnet is a smaller network inside a large network. A subnet is used for efficient routing of packets between two devices. A data packet doesn't need to travel the whole network to find its right device if the network is subnetted properly. Instead, if the destination device is in the same subnet as the sender, the data packets reaches quickly and efficiently. Subnets narrows down the IP address to ranges.

10. Gateway

A gateway is a device that connects separate devices by translating communications between different protocols. A gateway is different from a router as a router ensures delivery of the data whereas a gateway is used for communication translation. Nowadays, it is becoming common for a gateway's and router's functions to be combined and simply be called a router. All the data going in and out of a network will pass through the gateway.

11. NAT

NAT is an abbreviation for *Network Address Translation*. It is used to map multiple private addresses inside a local network to a public IP address before transferring information inside and out of the network. NAT is a process of converting local IP address (single/multiple) to global IP address (single/multiple). NAT is also responsible for post forwarding i.e., mapping a port of a public IP address to another port of a local device.

12. VPN

VPN is an abbreviation for Virtual Private Network. It is used for virtually extending a private network across multiple other network which are untrusted o need to be isolated. One can use a VPN to virtually connect to a private network from another location to access the resources inside that particular network. It is safer than exposing the private resources to the public internet.

13. OSI Model

OSI Model is an abbreviation for *Open Systems Interconnection Model*. It describes a common standard for coordination and communication between network systems. It is a conceptual framework for how network functions, separated into layers.

| Number | Layer | Details |
| --------------- | --------------- | --------------- |
| 1 | Physical Layer | Raw data stream. Mostly used to capture information |
| 2 | Data Link Layer | Defines the format of data. Structure definition. |
| 3 | Network Layer | Describes data path. The transmission path |
| 4 | Transport Layer | Does the data transmission using protocols like TCP or UDP |
| 5 | Session Layer | Maintains connections and controls ports |
| 6 | Presentation Layer | Converts data for presentation and presents it in human readable format. Also is responsible for data encryption/decryption |
| 7 | Application Layer | Human - Machine interface. Handles interaction between end-user and systems |

14. Modem

A modem is a network device that connects a LAN to the WAN. A modem is different from a router as a router is used for intercommunication between the network devices, while a modem acts as a bridge between the LAN (home network) and the WAN (internet). Nowadays, it is becoming common to have integrated modem and router.

15. Port forwarding

Port forwarding is a process to forward data from a port opened for a public IP to a port (same or different) inside the local network. It is safer than exposing the local resource to the internet since only the required port will be exposed instead of all the ports on the system, making it more vulnerable. It is also better since different ports on the public IP can be mapped to different systems on the local network, reducing load and ensuring availability.

16. ISP

ISP is an abbreviation for Internet Service Provider. An ISP is an organization that provides services for various services on the internet. There can be smaller ISPs which pay larger ISPs to route customers' traffic through them, or large ISPs owning/leasing the under-sea cables to facilitate inter-continental transmission.

17. Packet

A packet is the smallest unit of data carried by a network. A network packet is a small segment of a larger message that is sent over a network. Data sent over a network is divided into multiple packets and are recombined by the receiving computer. In the event of a transmission failure, only the failed packet needs to be resent instead of the entire data.

18. MAC Address

MAC address is an abbreviation for *Media Access Control Address*. It is a unique identifier for a device that connects to a network (like Wi-Fi, Ethernet, Bluetooth, etc). It is tied to a connection device called a NIC (Network Interface Card). A MAC address is hard-coded to a device's NIC and is unique to it.

19. ARP

ARP is an abbreviation for *Address Resolution Protocol*. It is the protocol responsible for discovering a link layer address (level 2 of OSI model) to a IP address.

20. SNMP

SNMP is an abbreviation for *Simple Network Management Protocol*. It is an internet standard for collecting and organizing information about devices on networks. It is responsible for providing network devices (routers, servers, etc) with a common language for sharing information. It is used to monitor the network, detect network faults and can also be used to configure remote devices. A SNMP's client-server architecture has three components, namely: SNMP manager, SNMP agent, and MIB (Management Information Base).

21. FTP

FTP is an abbreviation for *File Transfer Protocol*. It is a standart communication protocol used for transfer of files in a client-server model architecture. It is commonly operated on port number 21.

22. SMTP

SMTP is an abbreviation for *Simple Mail Transfer Protocol*. It is an internet standard communication protocol for E-mail transmissions. It is an essential component in email communication and operates at the application layer in TCP/IP stack (OSI Model). It normally operates on port number 25.

23. DDoS

DDos is an abbreviation for *Distributed Denial of Service*. A DDoS occurs when a large number of systems from various locations (distributed) sent network requests to a particular server or service, effectively overwhelming it with a flood of internet traffic and causing it unable to function, ultimately denying its service for legitimate users. A DDoS can be planned/targeted. It is then called a DDoS attack. It is achieved by utilizing multiple compromised computers, commonly by malware, to DDoS attack a service.

24. MITM

MITM is an abbreviation for Man-in-the-Middle. It is a cyber attack where a attackers connects between two computers in a network, and forwards data and information between them, while also sniffing the packets and examining them. The end parties believe they are communicating with each other, but in reality, they are communicating with the attacker who relays information between them.

25. SSL

SSL is an abbreviation for *Secure Sockets Layer*. It is a security protocol that is used for on-the-fly encryption-based internet security protocol. SSL protects inter-device communication by encryption, uses authentication to make sure the two communicating devices are who they claim to be (to prevent MITM), and digitally signs data to ensure data integrity. Nowadays, SSL is mostly replaced by TLS encryption.
