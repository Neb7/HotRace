#!/usr/bin/env python3
"""
HotRace - A simple racing game simulation
"""
import random
import time
from typing import List, Dict


class Racer:
    """Represents a racer in the race"""
    
    def __init__(self, name: str, speed: float = 1.0):
        self.name = name
        self.speed = speed
        self.position = 0.0
        self.finished = False
        
    def move(self) -> float:
        """Move the racer forward based on speed with some randomness"""
        movement = self.speed * random.uniform(0.8, 1.2)
        self.position += movement
        return movement
    
    def __repr__(self) -> str:
        return f"Racer(name='{self.name}', position={self.position:.2f})"


class Race:
    """Manages the race between multiple racers"""
    
    def __init__(self, distance: float = 100.0):
        self.distance = distance
        self.racers: List[Racer] = []
        self.results: List[Racer] = []
        
    def add_racer(self, racer: Racer) -> None:
        """Add a racer to the race"""
        self.racers.append(racer)
        
    def start(self, display: bool = True) -> List[Racer]:
        """
        Start the race and return the results
        
        Args:
            display: Whether to display the race progress
            
        Returns:
            List of racers in finishing order
        """
        if not self.racers:
            raise ValueError("No racers in the race!")
            
        if display:
            print(f"🏁 Starting HotRace! Distance: {self.distance}m")
            print(f"Racers: {', '.join(r.name for r in self.racers)}")
            print("-" * 50)
        
        step = 0
        while len(self.results) < len(self.racers):
            step += 1
            
            for racer in self.racers:
                if not racer.finished:
                    racer.move()
                    
                    if racer.position >= self.distance:
                        racer.position = self.distance
                        racer.finished = True
                        self.results.append(racer)
                        if display:
                            position = len(self.results)
                            print(f"🏆 {racer.name} finished in position {position}!")
            
            if display and step % 10 == 0:
                self._display_progress()
            
            time.sleep(0.05)  # Small delay for visualization
        
        if display:
            self._display_results()
            
        return self.results
    
    def _display_progress(self) -> None:
        """Display current race progress"""
        print("\nCurrent positions:")
        for racer in sorted(self.racers, key=lambda r: r.position, reverse=True):
            progress = int((racer.position / self.distance) * 30)
            bar = "█" * progress + "░" * (30 - progress)
            status = "✓" if racer.finished else "→"
            print(f"  {status} {racer.name:15s} {bar} {racer.position:.1f}m")
    
    def _display_results(self) -> None:
        """Display final race results"""
        print("\n" + "=" * 50)
        print("🏁 RACE RESULTS 🏁")
        print("=" * 50)
        for i, racer in enumerate(self.results, 1):
            medal = ["🥇", "🥈", "🥉"][i-1] if i <= 3 else "  "
            print(f"{medal} {i}. {racer.name} - {racer.position:.2f}m")


def main():
    """Main function to run a sample race"""
    # Create a race
    race = Race(distance=100.0)
    
    # Add racers with varying speeds
    race.add_racer(Racer("Lightning", speed=2.5))
    race.add_racer(Racer("Thunder", speed=2.3))
    race.add_racer(Racer("Storm", speed=2.4))
    race.add_racer(Racer("Blaze", speed=2.2))
    
    # Start the race
    race.start()


if __name__ == "__main__":
    main()
