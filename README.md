<h1>Hermes Project</h1>

<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16308198/54ea414a-3964-11e6-9d4b-2ba3543733ee.jpg" /></p>

<p>Hermes Project is an autonomous connected device in order to store alerts during shipping.
This project is able to handle various form of data, including:</p>

- Temperature
- Humidity
- GPS
- Acceleration and Angular Acceleration
- Angular Position
- DateTime
- Light level

<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16308423/316115ea-3965-11e6-9005-b7155d6840fd.png" /></p>

<p>Hermes Project is maintained by Exia CESI Toulouse A4L.
This repository is for educational purpose only and you can use it as an example for any
engineering project. <br /> Each process and step are documented below.</p>

# Chronology

<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16318978/9802e5cc-3991-11e6-81d7-3761500a6dd6.png" /></p>

# Mind Map

<p>A mind map is a diagram used to visually organize information.
Often used during brainstorming session, Mind Maps are particulary suited in order to understand
concept and ideas during team sessions. </p>

<p>The Mind Map below shows the entire project area, with all particularities and was drawn during the opening
session of the project. The objective was to find the more constraints as possible in order to make easiest the future designing.</p>

<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16319468/c1ce39f4-3993-11e6-8445-64abb2495414.png" /></p>

# Phase 1 - Connected Device 

During the first phase, team's goal was to create the connected device used to collect data in order to proceed the further big data analysis.

<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16190604/6f799622-36e0-11e6-8e90-47059148459a.png" /></p>

## Conception

The conception is in two parts : hardware conception and software conception.

During the hardware conception, we made 2D et 3D designing in order to make a box with a 3D printer. In the meantime, we also worked on Fritzing in order to create a virtual prototype of the electronic system.

Durign the software conception, we made an UML representation of the system and some mockups in order to represent the user interface.

### General Overview - Hardware

#### Casing Designing

The first step in casing designing was about measuring the dimension of the device in order to draw the plans.
Plans were made with Catia and were used as references in order to make the 3D designing.

<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16233852/fba02162-37cf-11e6-8098-4db12e32b809.jpg" /></p>

The second step was the 3D Designing, which was made with 123Design.
Each part of the casing has been printed with a 3D Printer inside Exia Cesi Toulouse's Fablab.

<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16321556/d1ed9f96-399d-11e6-9d2b-f47db18e98ae.png" /></p>

#### Prototyping with Fritzing

Fritzing is an open source initiative to develop amateur or hobby CAD software for the design of electronics hardware, to support designers and artists ready to move from experimenting with a prototype to building a more permanent circuit. It was developed at the University of Applied Sciences of Potsdam.

We used it in order to design electronics hardware of Hermes Project.

<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16234120/cedd3722-37d0-11e6-8bb0-04d2fe67dd39.png" /></p>

### General Overview - Software

During software conception, most of the time was UML Designing.
The Unified Modeling Language (UML) is a general-purpose, developmental, modeling language in the field of software engineering, that is intended to provide a standard way to visualize the design of a system.

#### UML Component Diagram

In order to represent the whole system, we used an UML Component Diagram (thanks to StarUML) and represented interaction between components and artifacts.
It is possible to see that the application is entirely threaded, so each sensor can work at its rythm without being bothered by the others.

A circular buffer was also developed in order to store data and alert awaiting for writter.

<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16233778/c7598204-37cf-11e6-8e46-18837fe142e8.png" /></p>

The following class diagram shows sensors classes and structures used inside the application.

<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16233777/c7594578-37cf-11e6-876c-b93a359413e6.png"/></p>

The following class diagram shows buffer and alert manager classes used inside the application.
<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16233779/c76849d8-37cf-11e6-98d1-e3766d274eb1.png"/></p>

# Phase 2 - Big Data and Business Intelligence

## Step 1 - Concatenation Software

In order to get a full JSON File, a concatenation software has been developed.
This software is able to browse inside a whole directory to concatenate all files inside in one big file which you can save wherever you please.
Sources can be found inside this repository.

<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16323140/ca06e606-39a8-11e6-9b00-c480129da958.png"/></p>

## Step 2 - Exploitation Software

Finally, in order to retrieve indicator and statistics about shipping, an exploitation software has been developed.
This software is able to browse inside JSON Collection stored into a CouchDB Database (NoSQL) and draw a map of the shipping with all major alerts displayed.
Sources can be found inside this repository.

<p align="center"><img src="https://cloud.githubusercontent.com/assets/11026659/16323573/11e07250-39ac-11e6-85c0-06c3d2e385c8.png"/></p>

# Additional notes and improvement ideas

In addition to the previous work, a business analysis has also been made for this project.

<p align="center"><img src="https://cloud.githubusercontent.com/assets/9677426/16322531/fca4a832-39a3-11e6-9241-30044945a71f.png"/></p>

This analysis demonstrates this project to be a typical case for Business Model development.
By the way, many improvements can be made to this project, for example:

- Casing optimization in weight and size
- Software optimization for the connected device
- Full optimization of the product life circle
- Migration to a Service Oriented Software for the exploitation

Feel free to contribute to this repository by doing pull request.

