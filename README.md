# HotRace 🏁

A simple and exciting racing game simulation written in Python!

## Features

- 🏎️ Multiple racers with different speeds
- 📊 Real-time race progress visualization
- 🏆 Ranking system with medals
- 🎲 Randomized race outcomes for excitement
- 🎯 Customizable race distance and racer attributes

## Installation

No external dependencies required! Just Python 3.6+.

```bash
git clone https://github.com/Neb7/HotRace.git
cd HotRace
```

## Usage

### Running a Race

Simply run the main script:

```bash
python hotrace.py
```

### Custom Race Example

```python
from hotrace import Race, Racer

# Create a race
race = Race(distance=150.0)

# Add racers
race.add_racer(Racer("Speed Demon", speed=3.0))
race.add_racer(Racer("Turbo", speed=2.8))
race.add_racer(Racer("Flash", speed=2.9))

# Start the race
results = race.start()
```

## Classes

### Racer

Represents a participant in the race.

**Parameters:**
- `name` (str): The racer's name
- `speed` (float): Base speed multiplier (default: 1.0)

### Race

Manages the race and tracks results.

**Parameters:**
- `distance` (float): Total race distance in meters (default: 100.0)

**Methods:**
- `add_racer(racer)`: Add a racer to the race
- `start(display=True)`: Start the race and return results

## Testing

Run the test suite:

```bash
python test_hotrace.py
```

## License

MIT License

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests.