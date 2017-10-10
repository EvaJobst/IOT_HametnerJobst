# Report
10th October 2017; Eva Jobst
______________________


## How to speak IoT?
### Binary
  Trouble with Big and Low Endian whenever you send something in Binary; with a lot of data Binary is used

### Text
  - General: Communication protocol; human-readable format; examples: FTP (File Transfer Protocol), SMTP (Simple MAil Transfer Protocol) and finger protocol; Used whenever human inspection is necessary
  - Speed:
  - Readibility:
  - User Friendlyness:
  - More overhead; no key; more bytes needed for the same format than in binary; hard to read for computers

### XML (SOAP)

### JSON

### Yaml
Human readable data serialization language; used for configuration files; targets many of the same applications as XML;

  ##### Speed
  Slower than JSON --> increased overhead because the YAML parsers are complex; extension of JSON

  ##### Readibility
  ##### User Friendlyness

  ##### Example
  > --- # Favorite movie
 - Casablanca
 - North by Northwest
 - The Man Who Wasn't There


## Consortiums/Foundations/Alliances
### OCF
Open Connectivity Foundation

##### Members
Cisco Systems, General Electric, Intel, MediaTek, LG, Haier, Canon, Samsung

##### Purpose
While some devices can communicate with others, no universal language existed for the Internet of Things. Device makers instead had to choose between disparate frameworks (e.g. Apple, Amazon and Google) limiting their market share, or develop across multiple ecosystems, increasing their costs. The burden then falls on end users to determine whether the products they want are compatible with the ecosystem they bought into, or find ways to integrate their devices into their network and try to solve interoperability issues on their own.

##### Costs
Ranging from 0$-350.000$ per year

**Basic Member**
- Eligible to have read only rights for members-only materials
- Eligible to access the OCF and UPnP certification test tools for pre-testing purposes only (cannot certify devices)

**Diamond Member**
- Board of Director representative appointment eligibility
- Eligible to have a representative appointed or elected as an Officer of the organization
- Eligible to participate and Chair in the Working Groups and Task Groups
- Eligible to seek OCF and UPnP certification of products and/or services
- Eligible to use the organization's trademarks in connection with Member's certified products and/or services

## Protocols
### MQTT
##### Example
Facebook Messenger, Amazon Web Services, Microsoft Azure, Platform "Home Assistant" offers four options for MQTT brokers

##### Purpose
Lightweight publish-subscribe messaging protocol used on top of TCP/IP; used when a "small code footprint" is required; Server runs on Gateway

##### Software Support
https://github.com/mqtt/mqtt.github.io/wiki/software?id=software

### CoAP
- Based on REST model
- Compared to HTTP Post --> REST over UDP
- Format is more precise and shorter
- Faster with less overhead
- Latency of CoAP is much smaller
