# Satellite Docking & Filming Robot

A two-part robotic system simulating satellite deployment, inspection, and re-docking — built as a 25-person, one-semester engineering project.

## Overview

The project reproduces a mechanism found on real satellites: a **fixed module** (simulating the main satellite) and a **mobile module** that ejects from it, films the fixed module from the outside using an onboard camera, and then autonomously re-docks.

Team of 25 students over one semester. I was responsible for the **entire software/electronics stack**: code, motor selection, battery selection, camera integration, and wiring.

## My Role

- Full embedded software (Arduino) controlling the mobile module's motors and camera
- Motor selection and sizing for the ejection/return mechanism
- Battery selection (capacity/weight tradeoff for the mobile module)
- Camera integration for the filming sequence
- Full wiring/harness design for the mobile module

## Tech Stack

- **Hardware:** Arduino
- **Domain:** Motor control, embedded C/C++, power budgeting, camera systems

## Key Technical Points

- Coordinating ejection, filming, and return in a single autonomous sequence
- Balancing battery weight vs. flight/operation time on the mobile module
- Wiring reliability on a moving, ejectable platform

## Demo

<!-- Add photos/video of the fixed + mobile module here -->

## Context

School project — ICAM, 2nd year engineering, group project (25 students, 1 semester).

> Note: source code comments, the full project report, and documentation are in French (school requirement). This README provides an English summary of the project.
