#!/bin/bash

# Name: Harsana Neupane
# Course: CSCE 3600, Section 002
# Date: October 16, 2026
# Assignment: Minor Assignment 2
# Description: A personal assistant for daily tasks.

# Enable debug mode
if [[ "$1" == "--debug" ]]; then
    set -x
fi

# Display the daily briefing
daily_briefing()
{
    echo "Good morning, $(whoami)!"
    echo "Date and Time: $(date)"
    echo "Calendar:"
    cal
    echo "Running Processes: $(ps -e --no-headers | wc -l)"
}

daily_briefing

# Function to organize files
organize_files()
{
    # Ask the user for a directory
    read -p "Enter directory to organize: " myDir

    # Check if the directory exists
    if [[ -d "$myDir" ]]; then
        echo "Scanning $myDir..."

        # Count files in the directory
        totalFiles=$(find "$myDir" -maxdepth 1 -type f | wc -l)
        echo "Total files: $totalFiles"


        # Display text files
        echo "Text files:"
        find "$myDir" -maxdepth 1 -type f -name "*.txt"

        # Display shell scripts
        echo "Shell scripts:"
        find "$myDir" -maxdepth 1 -type f -name "*.sh"

        # Display log files
        echo "Log files:"
        find "$myDir" -maxdepth 1 -type f -name "*.log"


        # Move log files into a logs folder
        if compgen -G "$myDir/*.log" > /dev/null; then
            mkdir -p "$myDir/logs"
            mv "$myDir"/*.log "$myDir/logs/"
            echo "Log files have been  moved to $myDir/logs/"
        else
            echo "No log files to move."
        fi


    else
        echo "Invalid directory."
    fi
}

# organize_files

# Array to store reminders
myReminders=()

# Function to add a new reminder
addMyReminder()
{
    # Check if the reminder list is full
    if [[ ${#myReminders[@]} -ge 5 ]]; then
        echo "Reminder list is full."
    else
        # Ask the user to enter a reminder
        read -r -p "Enter reminder: " newReminder

        # Add the reminder to the array
        myReminders+=("$newReminder")
        echo "Reminder added successfully."
    fi
}

# Function to view saved reminders
viewReminders()
{
    echo "Reminders:"

    if [[ ${#myReminders[@]} -eq 0 ]]; then
        echo "No reminders found."
    else
        for i in "${!myReminders[@]}"
        do
            echo "$i: ${myReminders[$i]}"
        done
    fi
}

# Function to delete a reminder
deleteReminder()
{
    # Check if there are any reminders
    if [[ ${#myReminders[@]} -eq 0 ]]; then
        echo "No reminders to delete."
        return
    fi

    # Ask which reminder to delete
    read -r -p "Enter index to delete: " removeIndex

    # Check if the index is valid
    if [[ "$removeIndex" =~ ^[0-4]$ ]] && [[ -v myReminders[$removeIndex] ]]; then
        unset "myReminders[$removeIndex]"
        myReminders=("${myReminders[@]}")
        echo "Reminder deleted successfully."
    else
        echo "Invalid reminder index."
    fi
}


# Function to check heart rate
checkHealth()
{
    # Ask user to enter heart rate
    read -r -p "Enter your heart rate: " heartRate

    # Check if the input is a valid number
    if [[ ! "$heartRate" =~ ^[0-9]+$ ]]; then
        echo "Invalid heart rate."
    elif [[ "$heartRate" -lt 60 ]]; then
        echo "Heart rate is Low."
    elif [[ "$heartRate" -le 100 ]]; then
        echo "Heart rate is Normal."
    else
        echo "Heart rate is High."
    fi
}

# Function to record user actions
logAction()
{
    echo "$(date): $1" >> "$HOME/minor2_actions.log"
}

# Function to handle interruptions
handleInterrupt()
{
    echo
    echo "Use the menu to exit safely."
    logAction "Script interrupted"
}

# Trap interruption signals
trap 'handleInterrupt' SIGINT SIGTERM


# Display the main menu
mainMenu()
{
    PS3="Enter choice: "

    while true
    do
        echo "Choose an option:"

        select userChoice in "Organize Files" "Add Reminder" "View Reminders" "Delete Reminder" "Health Check" "Exit"
        do
            case "$userChoice" in
                "Organize Files")
                    logAction "Organize Files selected"
                    organize_files
                    break
                    ;;
                "Add Reminder")
                    logAction "Add Reminder selected"
                    addMyReminder
                    break
                    ;;
                "View Reminders")
                    logAction "View Reminders selected"
                    viewReminders
                    break
                    ;;
                "Delete Reminder")
                    logAction "Delete Reminder selected"
                    deleteReminder
                    break
                    ;;
                "Health Check")
                    logAction "Health Check selected"
                    checkHealth
                    break
                    ;;
                "Exit")
                    logAction "Exited program"
                    echo "Goodbye!"
                    return
                    ;;
                *)
                    echo "Invalid choice."
                    logAction "Invalid menu choice: $REPLY"
                    break
                    ;;
            esac
        done
    done
}

mainMenu

