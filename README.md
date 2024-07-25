Engineering materials
====

This repository contains engineering materials of a self-driven vehicle's model participating in the WRO Future Engineers competition in the season 2024.

## Content

* `t-photos` contains 2 photos of the team (an official one and one funny photo with all team members)
* `v-photos` contains 6 photos of the vehicle (from every side, from top and bottom)
* `video` contains the video.md file with the link to a video where driving demonstration exists
* `schemes` contains one or several schematic diagrams in form of JPEG, PNG or PDF of the electromechanical components illustrating all the elements (electronic components and motors) used in the vehicle and how they connect to each other.
* `src` contains code of control software for all components which were programmed to participate in the competition
* `models` is for the files for models used by 3D printers, laser cutting machines and CNC machines to produce the vehicle elements.
* `other` is for other files which can be used to understand how to prepare the vehicle for the competition. It may include documentation how to connect to a SBC/SBM and upload files there, datasets, hardware specifications, communication protocols descriptions etc.

## Introduction

Our vehicle is built upon the CKK011 chasis made by COKOINO with some modifications made, the code for the vehicle was made by us. This vehicle uses the Arduino UNO microcontroller to execute the instructions, we program in C/C++ with the Arduino IDE to then upload it via USB type-B to the board. It is composed by the following electronic components:
* **Two Rechargables 9V batteries:** powers the board
* **An Arduino UNO Microcontroller:** distributes the power to all components and executes instructions
* **A breadboard:** allows for more pin connections
* **Various cables:** connect components to the board
* **One Ultrasonic Proximity Sensor:** determines distance to objects
* **Two RGB Color Sensors:** determines the color of the object in front of it
* **One 5V DC Motor:** rotates both back wheels
* **Two Servo Motors:** rotates components like the Proximity Sensor and steering wheels
