#!/bin/bash

# Scripts directory
SCRIPTS_DIR="scripts"

# Check if the scripts directory exists
if [ ! -d "$SCRIPTS_DIR" ]; then
  echo "Scripts directory does not exist: $SCRIPTS_DIR"
  exit 1
fi

# Function to execute a specific script multiple times
execute_script_multiple_times() {
  script="$SCRIPTS_DIR/$1.sh"
  times=$2

  for ((i = 1; i <= times; i++)); do
    sbatch "$script"
  done
}

# Function to execute all scripts multiple times
execute_all_scripts_multiple_times() {
  for script in "$SCRIPTS_DIR"/*.sh; do
    sbatch "$script"
  done
}

# Main logic based on arguments
if [ -z "$1" ]; then
  echo "Usage: $0 <script_name|all> [times]"
  exit 1
fi

if [ "$1" == "all" ]; then
  if [ -z "$2" ]; then
    echo "Usage: $0 all [times]"
    exit 1
  fi
  execute_all_scripts_multiple_times "$2"
else
  if [ -z "$2" ]; then
    echo "Usage: $0 <script_name|all> [times]"
    exit 1
  fi
  execute_script_multiple_times "$1" "$2"
fi

mv slurm*.out out/

exit 0

