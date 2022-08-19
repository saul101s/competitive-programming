#!/bin/bash

set -e

SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"

# Install g++ compiler
sudo apt install -y g++

# Install geany
sudo apt install -y geany

# Restore configuration
cp -r "$SCRIPTPATH/geany" ~/.config

# Get colorful terminal in Geany
sed -i "s/#force_color_prompt=yes/force_color_prompt=yes/" ~/.bashrc

# Set stack limit to 2GB
if [ -z $(grep "ulimit -s 2000123" ~/.bashrc) ]
then
  echo "ulimit -s 2000123" >> ~/.bashrc
fi

# Install Guake Terminal
sudo apt install -y guake

# Make competitive script available from terminal
sudo cp "$SCRIPTPATH/../competitive.sh" /usr/bin

exit 0
