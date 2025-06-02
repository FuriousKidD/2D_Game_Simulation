# 🛸 Raiders of the Lost Nark

A terminal-based adventure simulation game written in **C++**, where you pilot a drone over a jungle terrain to locate hidden **map fragments** and assist treasure hunters in reconstructing the **Lost Nark treasure map**. Inspired by exploration strategy games, this project showcases **dynamic 2D arrays**, **resource management**, and **procedural game design** — all running in a simple command-line interface.
## 🎥 Project Demo

| Game Start | Scanning & Collecting | Game Over |
|------------|------------------------|------------------------|
| <img width="500" alt="Start" src="https://github.com/user-attachments/assets/650ab17b-fe97-404a-99bb-23080a86fbb2" /> | <img width="527" alt="Example3-ScanFunction" src="https://github.com/user-attachments/assets/635dcc5e-8a2f-41e3-a912-49e4e83fa5b0" /> | <img width="596" alt="Example4-GameOver" src="https://github.com/user-attachments/assets/f042721c-395e-4240-85c7-c05151807aaf" /> |

> _Screenshots simulate the drone in action, scanning forest terrain and collecting map fragments._
## 🌴 Game Storyline

> **“You have been chosen to assist a team of treasure hunters in finding the Lost Nark.”**

The ancient **Utopian jungle** hides pieces of a torn treasure map, and only you, piloting a **Utopian drone**, can recover them. Watch your **battery**, locate **charging towers**, and **scan** carefully — or you may crash before uncovering the secret.
## 🧠 Game Mechanics

### Objective
- Recover **all map fragments** using a drone before running out of battery.

### Environment
- The world is a **grid** full of trees (`^`), some of which hide **map pieces**.
- Each row has **one charging tower** (`C`) for recharging the drone.
- The **drone** (`O`) starts at the far-right side of the map.

### Gameplay Actions

| Action       | Battery Cost | Description                                      |
|--------------|--------------|--------------------------------------------------|
| Move         | 1 unit       | Move in any of 8 directions (incl. diagonals)   |
| Scan Area    | 3 units      | Reveal hidden features within scan range        |
| Collect Map  | 2 units      | Collect discovered map piece at current location|

- **Charging towers** may randomly be **destroyed** based on a command-line defined chance.
- **Scanning** uncovers nearby hidden objects beneath trees.
- Players must **explicitly choose to collect** a map piece after finding it.

## ⚙️ How to Run
Make sure that gcc is installed and set up into your environment
### Compile in CMD


```bash
g++ -std=c++11 -o lost_nark main.cpp forest.cpp drone.cpp
./lost_nark <width> <height> <tower_destruction_chance%> <num_map_pieces>
