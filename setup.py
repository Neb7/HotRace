#!/usr/bin/env python3
"""
Setup script for HotRace
"""
from setuptools import setup, find_packages

with open("README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()

setup(
    name="hotrace",
    version="1.0.0",
    author="Benjamin PICARD",
    description="A simple and exciting racing game simulation",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/Neb7/HotRace",
    py_modules=["hotrace"],
    classifiers=[
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.6",
        "Programming Language :: Python :: 3.7",
        "Programming Language :: Python :: 3.8",
        "Programming Language :: Python :: 3.9",
        "Programming Language :: Python :: 3.10",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
        "Development Status :: 4 - Beta",
        "Intended Audience :: Developers",
        "Topic :: Games/Entertainment :: Simulation",
    ],
    python_requires=">=3.6",
    entry_points={
        "console_scripts": [
            "hotrace=hotrace:main",
        ],
    },
)
