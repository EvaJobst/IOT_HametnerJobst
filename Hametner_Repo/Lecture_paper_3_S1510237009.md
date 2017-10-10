# Vorlesungsarbeit
Magdalena Hametner - Mo, 10. Oktober 2017
## Folie 2 - Exchange Formats: How to speak IoT?
### Yaml:
- YAML was said to mean Yet Another Markup Language
- human-readable data serialization language
- angelegt an XML und an die Sprachen Perl, Python, C and RFC2822
- used for applications where data is being stored
- offers an "in-line" style for denoting associative arrays and lists --> similar to JSON
![YAML](https://i.stack.imgur.com/rnC8H.png)

### Binary:
- compact representations for XML (Extensible Markup Language)
- reducing the cost of parsing
- used for applications where the performance of standard XML is insufficient
- usability challenges the user
- Not readable
![Binary](https://www.nayuki.io/res/what-are-binary-and-text-files/binary-file-in-hex-editor.png)

### XML: (= Extensible Markup Language)
- rules for encoding documents in a format that is both human-readable and machine-readable

![XML](http://www.perfectxml.com/articles/xml/images/samplexml.gif)

#### !!! andere machen (Binary[CBOR], Text, XML[SOAP], JSON, YAML)

## Folie 4 - Consortiums/Foundations/Alliances: Who does IoT?
### OCF (= Open Connectivity Foundation)
#### members:
- General: (https://openconnectivity.org/foundation/membership-list)
  - Diamound Members : (Canon, Cisco, Intel, Samsung)
  - Platinum Members: (hp, Sony, Comcast)
  - Gold Members: (GoPro, Inc., D-Link Corporation)
  - Founders: Samsung, Intel

#### purpose
- OCF delivers a framework that enables easy discovery, and trusted and reliable connectivity between things in a network via a specification and a certification program
- source: https://en.wikipedia.org/wiki/Open_Connectivity_Foundation

#### costs
- https://openconnectivity.org/foundation/membership-list
- Diamond Member Benefits (Annual Dues: $350,000 USD)
- Platinum Member Benefits (Annual Dues: Tiered from $5,000 to $50,000 USD**)
- Gold Member Benefits (Annual Dues: $2,000 USD)
- Non-Profit, Educational Gold Member Benefits (One time fee: $1,000 USD***)
- Basic Member Benefits (Annual Dues: $0 USD)

--> I have done OCF, the others are extra

### AllSeen Alliance
= AllJoyn framework
AllJoyn is an open source software framework that makes it easy for devices and apps to discover and communicate with each other.

#### members
- https://allseenalliance.org/alliance/members

#### purpose
- The AllSeen Alliance is dedicated to the widespread adoption of products, systems and services that support the Internet of Things with AllJoyn®, a universal development framework.

#### costs
- ?

### Thread Group
#### title
- Connect and control IoT devices at home.
- Providing a Thread which connects all devices at home
#### members
- founded: by ARM, Samsung and Nest
- http://threadgroup.org/joinus
#### purpose
- Simple for consumers to use
- Always secure
- Power-efficient
- An open protocol that carries IPv6 natively
- Based on a robust mesh network with no single point of failure
- Runs over standard 802.15.4 radios
- Designed to support a wide variety of products for the home:
  - appliances
  - access control
  - climate control
  - energy management
  - lighting
  - safety
  - security

#### costs
- ?

### IIC (= Industrial Internet Consortium)
#### members
- Intel, IBM, GE, Cisco, AT&T (founded in 2014) and Bosch, Huawei, SAP

#### Purpose
- setting the architectural framework for industrial IoT - making it easier to adopt interconnected machines and intelligent analysis.

#### Cost
- from $2500 to $150.000 in six levels of membership

## Folie 7 - Protocols
### CoAP (= Constrained Application Protocol)
- Data is send via UDP or a UDP analogue
- specialized Internet Application Protocol
- defined in RFC 7228
- designed for use between devices on the same constrained network (e.g., low-power, lossy networks)
- between devices and general nodes on the Internet
- and between devices on different constrained networks both joined by an internet
-  service layer protocol that is intended for use in resource-constrained internet devices
- can be used easily translate to HTTP for simplified integration with the web
- IPv6 over Low-Power Wireless Personal Area Networks
- high packet error rates
- typical throughput of 10s of kbit/s
- latency is much smaller than MQTT AND HTTP
- Overhead and parsing complexity.
- URI and content-type support.
- Support for the discovery of resources provided by known CoAP services.
- Simple subscription for a resource, and resulting push notifications.
- Simple caching based on max-age.
- many different Libraries and Languages
- a Server is needed
  - run on microcontroller
