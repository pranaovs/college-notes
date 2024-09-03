# Cyber Security Essentials

---

Author: Pranaov S

Lecturer: Mr. Praveen Raj

Subject Code: CS1009

---

<!--toc:start-->
- [Cyber Security Essentials](#cyber-security-essentials)
  - [DNS Records](#dns-records)
  - [OSI Model](#osi-model)
  - [Essential Concepts](#essential-concepts)
    - [NIC](#nic)
    - [Router](#router)
    - [Switch](#switch)
    - [IP Address](#ip-address)
    - [Subnet Mask (Subnetting IP)](#subnet-mask-subnetting-ip)
    - [MAC Address](#mac-address)
    - [Firewall](#firewall)
  - [Encryption](#encryption)
    - [Symmetric encryption](#symmetric-encryption)
    - [Asymmetric encryption](#asymmetric-encryption)
  - [Virtualization](#virtualization)
    - [Hypervisor](#hypervisor)
      - [Benefits](#benefits)
      - [Disadvantages](#disadvantages)
    - [Containers](#containers)
      - [Advantages](#advantages)
      - [Disadvantages](#disadvantages)
<!--toc:end-->

## DNS Records

**Domain Name System**

Commonly used to resolve domain names to IP addresses.

Commonly looks like _x.y.z_ where x is name server, y is top level domain server and z is root server.

Example: <www.example.com>

| Record Type   | Usage    |
|--------------- | --------------- |
| A   | Resolve domain name to IPv4 addresses   |
| AAAA   | Resolve domain name to IPv6 addresses   |
| MX   | Mail Exchange record. Resolves a mail server address to an ip usually for an email client   |
| SRV | Service record. Has a poert entry to resolve a domain name to a port in a server   |
| TXT | Misc information about the domain |
| CNAME | Resolve domain name to another domain name. Used for aliasing or forwarding |
| NS | Name Server record. Used to redirect a DNS request to a name server from a top level server |
| SOA | Start Of Authority record. Stores inportant information about a domain or a zone, and TTL |

## OSI Model

Open Systems Interconnection model.

It describes 7 layers for network transmission.

| Number | Layer | Details |
| --------------- | --------------- | --------------- |
| 1 | Physical Layer | Raw data stream. Mostly used to capture information |
| 2 | Data Link Layer | Defines the format of data. Structure definition. |
| 3 | Network Layer | Describes data path. The transmission path |
| 4 | Transport Layer | Does the data transmission using protocols like TCP or UDP |
| 5 | Session Layer | Maintains connections and controls ports |
| 6 | Presentation Layer | Converts data for presentation and presents it in human readable format. Also is responsible for data encryption/decryption |
| 7 | Application Layer | Human - Machine interface. Handles interaction between end-user and systems |

## Essential Concepts

### NIC

**Network Interface Card**

It is used in interfacing a system to a network. It can be wired or wireless NIC.

### Router

It is used to route a device (mostly a switch) to the internet.

### Switch

A Switch is used to route packets between various devices. It can intelligently handle various packets and route packets to destinations efficiently.

### IP Address

**Internet Protocol**

It is a basic entity for a device to communicate with any other device.
It has 4 octets (4 * 8 bits).

_x.x.x.x_ (x = 0 to 255)

And IP Address has multiple classes (A, B, C, D, E). D and E are used for scientific purposes whereas A, B, C are used for consumers and businesses.

### Subnet Mask (Subnetting IP)

A subnet mask is used to divide IP addresses into multiple subnets. A subnet mask cannot include 0 and 255. _0.x.x.x_ and _x.x.x.255_ cannot be used.

### MAC Address

**Media Access Control**

It is a fixed value which is assigned for a hardware.

A laptop, for example, has two WiFi MAC addresses, one for wired NIC and one for wireless NIC.

### Firewall

A firewall blocks network access from outside the network to inside (or vice versa).
It acts as a network barrier.

A firewall blocks harmful activity from outside the network to inside.

A firewall filters the incoming network packets and decided whether it is allowed to enter. It is a set of rules called an Access Control List (ACL).

Firewall rules can be based on:

* IP Address
* Domain names
* Word list
* Ports

Types of firewall:

1. Host-based firewall:
It is a software firewall that is installed on a system and it protects the computer only.
Example: Zonewall, 3rd party anti-virus programs, Microsoft Windows firewall preinstalled in Windows OSes.
2. Network-based firewall:
Protects the entire network. It is a combination of hardware or software. Can be a stand alone device, a software or can be cloud based.

Usually, both firewalls are used in a network.

## Encryption

There are two types of encryption.

1. Asymmetric encryption
2. Symmetric encryption

### Symmetric encryption

Symmetric encryption is a method to encrypt a message using a common password/passphrase. It is a common shared key used for encryption and decryption.

### Asymmetric encryption

Uses public-private key to encrypt messages. A keypair is generated and only the public key is shared. Other users use the public key to encrypt a message and send it to the owner. The encrypted message can be decrypted using the private key. One common encryption algorithm is RSA (Rivest-Shamir-Adleman). ECC (Elliptic-curve cryptography) is another asymmetric encryption algorithm.

## Virtualization

Running multiple machines (OS) inside one physical host is called virtualization. It is the process of simulating hardware in software for running other software.

### Hypervisor

A software that acts as a host for the VMs. It allocates resources like RAM, storage, etc for the virtual machines.

1. Type-1 Hypervisor: Installed on base metal. Example: Proxmox, VMware ESXi, Citrix Zen-server, Microsoft Hyper-v, etc
2. Type-2 Hypervisor: Installed as a software. Example: QEMU, VMware workstation, VirtualBox, etc

#### Benefits

1. Saves money on hardware and electricity
2. Saves money on floor space
3. Saves money on maintenance
4. Ease of portability
5. Takes advantage of full computing capability by running multiple OS on the host.
6. Easier disaster recovery management with snapshots, guest redundancy, RAID, etc

#### Disadvantages

1. Can consume a lot of RAM and storage space, because each VM is an entire operating system.
2. Take time to boot up
3. Requires OS licenses (Use GNU/Linux)

### Containers

A container is an application with with all the required files, configurations, dependencies, etc which is required to run it, packaged in it.

Docker is a leading software to manage containers.

Containers use a container engine to run the containers. It unpacks the file and passes it over to the container to run it.

#### Advantages

1. Light weight
2. Faster compared to VMs
3. Smaller footprint, better portability

#### Disadvantages

1. It requires the same host as it was packed in to run
