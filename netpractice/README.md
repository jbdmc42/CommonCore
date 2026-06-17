# NETPRACTICE

*This project has been created as part of the 42 curriculum by joaobarb*

## Description

- ### Overview
**NetPractice** is a small-scale network and addressing training based on understanding the main concepts about these themes:

	- TCP/IP addressing
	- Valid and Invalid IPs and Subnet Masks
	- Gateways
	- General functioning of routers and switches

- ### TCP/IP
***TCP*** or ***Transmission Control Protocol*** is the foundational standard that dictates how data is sent and received across an internet connection.

#### How TCP works:

```bash
	test
```

- ### Valid and Invalid IPs and Subnet Masks
***IP*** or ***Internet Protocol*** is the set of rules that dictates how data is routed and sent across an internet connection. More simply, it is the underlying technology that allows a devices to communicate with each other. IPs are divided in two sections:

	- the Network part
	- the Host part

***Subnet Mask*** is the rule that tells us where the split between those two divisions happens.

#### How IPs and Subnet Masks work:

- Parts and Divisions
```bash
	Example:
	IP:		192.168.1.42
	Mask:	255.255.255.0

	Divisions:
	[ Network Part ] [ Host Part ]
	| 192.168.1	     | 42
```

This means that any machine with ***192.168.1.XXX*** on their IP belong to the same network, while ***X*** are the host (the number assigned to each machine).

This could also be represented as:
```bash
	192.168.1.42/24
```

- But what does ***/24*** mean?

A mask of:
```bash
	255.255.255.0
```
is, in binary:
```bash
	11111111.11111111.11111111.00000000
```

- ### Gateways

- ### General functioning of routers and switches


## Instructions

## Resources