# Parking Garage Simulator

**Data Structure:** Stack, Deque <BR>
**Programming Focus:** STL Stack, STL Deque

## Overview

Welcome to the Parking Garage Simulator! This C++ program simulates a parking garage that accommodates a single lane of up to 10 cars. The program uses the `car` and `garage` classes to manage car arrivals and departures.

## Features

- **Car Arrival:**
  - Displays information when a car arrives at the parking garage.
  - Handles the case when the garage is full.

- **Car Departure:**
  - Handles car departures, updating the number of moves within the garage.
  - Displays information about the departure, including the number of times the car was moved.

- **Invalid Actions:**
  - Detects and notifies users of invalid actions.

## Test Runs

The program has undergone extensive testing to ensure its correct functionality. Various test cases cover different scenarios, including car arrivals, departures, and situations where the garage is at full capacity.

1. Car Arrival and Departure
   - Simulates the arrival and departure of multiple cars.
   - Displays information about each event, including moves within the garage.

2. Garage Full Scenario
   - Tests the handling of a full garage when a car arrives.

3. Invalid Action
   - Checks for proper detection and notification of invalid actions.

## Code Organization

All the code for this project is located in the accompanying file named `parking.cc`. The document is structured to be read from top to bottom, providing a detailed explanation of the code, its functions, and the rationale behind design decisions.

The code for this program is organized into two main classes:

- `car`: Represents an individual car with an ID, license plate, and move tracking.
- `garage`: Simulates the parking garage, managing car arrivals and departures.

## Skills Showcase

This project demonstrates proficiency in several key areas:

- **C++ Programming:**
  - Utilizes C++ language features, including classes, data structures, and I/O operations.
  - Implements the parking garage simulation efficiently.

- **Problem Solving:**
  - Addresses the challenge of managing car arrivals and departures within the constraints of a single-lane parking garage.

- **Documentation:**
  - The accompanying code includes comments explaining the logic and functionality of different sections.

- **Simulation:**
  - Simulates a parking garage scenario, providing meaningful output based on user input.

These skills collectively showcase the ability to design, implement, and document a C++ program that effectively addresses a specific problem domain.

