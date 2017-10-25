# Report
25th October 2017; Eva Jobst
______________________

## Predictive Maintenance
#### What is predictive maintenance?
- Are techniques that help decide to predict when the maintenance should be performed

#### What problem does it solve?
- Reduce maintenance cost
- increase asset availability
- improve customer satisfaction
- generate new service revenue

#### How is it related to IoT?
- Use of sensors

#### Give 3 examples of predictive maintenance in the IoT.
- Microsoft: Predictive analytics help optimize Rolls-Royce airplane engine performance
- Microsoft: IoT solutions fuel oil and gas industry success at Rockwell Automation
- Automotive
- Energy & Utilities
- Industrial Robotics

#### Which role does data analytics play?
- Visualization and Prediction of possible Maintenance issues


## Heartbeat Monitoring of Network Nodes

#### How does a heartbeat monitor in a network work?
In computer clusters, heartbeat network is a private network which is shared only by the cluster nodes, and is not accessible from outside the cluster. It is used by cluster nodes in order to monitor each node's status and communicate with each other.
Source: https://en.wikipedia.org/wiki/Heartbeat_network

#### What can it be used for?
- Monitor each others status, to communicate with each other

#### What can be secured in an IoT system with this type of monitoring?
- Determine the status (online/offline) of devices -> owner needs to be notified when offline
- 

#### What feature in ulnoiot already supports heartbeats?
- MQTT-messages of the single node
- "devices" command in MicroPython

#### Is this predictive maintenance (or what would need to be added)?
- Not quite, data analytics, that make the prediction of device failures possible, are missing
