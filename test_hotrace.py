#!/usr/bin/env python3
"""
Unit tests for HotRace
"""
import unittest
from hotrace import Racer, Race


class TestRacer(unittest.TestCase):
    """Test cases for Racer class"""
    
    def test_racer_creation(self):
        """Test creating a racer"""
        racer = Racer("TestRacer", speed=2.0)
        self.assertEqual(racer.name, "TestRacer")
        self.assertEqual(racer.speed, 2.0)
        self.assertEqual(racer.position, 0.0)
        self.assertFalse(racer.finished)
    
    def test_racer_default_speed(self):
        """Test racer with default speed"""
        racer = Racer("DefaultRacer")
        self.assertEqual(racer.speed, 1.0)
    
    def test_racer_move(self):
        """Test racer movement"""
        racer = Racer("Mover", speed=2.0)
        initial_position = racer.position
        movement = racer.move()
        
        self.assertGreater(racer.position, initial_position)
        self.assertGreater(movement, 0)
        # Movement should be between 0.8*speed and 1.2*speed
        self.assertGreaterEqual(movement, 2.0 * 0.8)
        self.assertLessEqual(movement, 2.0 * 1.2)
    
    def test_racer_repr(self):
        """Test racer string representation"""
        racer = Racer("ReprTest", speed=1.5)
        racer.position = 10.5
        repr_str = repr(racer)
        self.assertIn("ReprTest", repr_str)
        self.assertIn("10.5", repr_str)


class TestRace(unittest.TestCase):
    """Test cases for Race class"""
    
    def test_race_creation(self):
        """Test creating a race"""
        race = Race(distance=100.0)
        self.assertEqual(race.distance, 100.0)
        self.assertEqual(len(race.racers), 0)
        self.assertEqual(len(race.results), 0)
    
    def test_race_default_distance(self):
        """Test race with default distance"""
        race = Race()
        self.assertEqual(race.distance, 100.0)
    
    def test_race_invalid_distance(self):
        """Test that race raises error with invalid distance"""
        with self.assertRaises(ValueError):
            Race(distance=0)
        with self.assertRaises(ValueError):
            Race(distance=-10)
    
    def test_add_racer(self):
        """Test adding racers to a race"""
        race = Race()
        racer1 = Racer("Racer1")
        racer2 = Racer("Racer2")
        
        race.add_racer(racer1)
        self.assertEqual(len(race.racers), 1)
        
        race.add_racer(racer2)
        self.assertEqual(len(race.racers), 2)
        self.assertIn(racer1, race.racers)
        self.assertIn(racer2, race.racers)
    
    def test_race_no_racers(self):
        """Test that race raises error with no racers"""
        race = Race()
        with self.assertRaises(ValueError):
            race.start(display=False)
    
    def test_race_with_racers(self):
        """Test a complete race"""
        race = Race(distance=50.0)
        race.add_racer(Racer("Fast", speed=3.0))
        race.add_racer(Racer("Slow", speed=1.0))
        
        results = race.start(display=False)
        
        # Check that we have results
        self.assertEqual(len(results), 2)
        
        # All racers should have finished
        for racer in race.racers:
            self.assertTrue(racer.finished)
            self.assertGreaterEqual(racer.position, race.distance)
        
        # Results should be ordered by finish time (first to finish is first)
        self.assertEqual(results[0].name, "Fast")
        self.assertEqual(results[1].name, "Slow")
    
    def test_race_order(self):
        """Test that faster racers generally finish first"""
        race = Race(distance=100.0)
        race.add_racer(Racer("VeryFast", speed=5.0))
        race.add_racer(Racer("VerySlow", speed=0.5))
        
        results = race.start(display=False)
        
        # The very fast racer should finish before the very slow one
        self.assertEqual(results[0].name, "VeryFast")
        self.assertEqual(results[1].name, "VerySlow")
    
    def test_multiple_racers(self):
        """Test race with multiple racers"""
        race = Race(distance=75.0)
        racers = [
            Racer("R1", speed=2.0),
            Racer("R2", speed=2.5),
            Racer("R3", speed=1.5),
            Racer("R4", speed=3.0),
        ]
        
        for racer in racers:
            race.add_racer(racer)
        
        results = race.start(display=False)
        
        # All 4 racers should finish
        self.assertEqual(len(results), 4)
        
        # All should have reached the finish line
        for racer in racers:
            self.assertGreaterEqual(racer.position, race.distance)


if __name__ == "__main__":
    unittest.main()
