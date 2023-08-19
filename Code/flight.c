#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Mflight 100

// Structure to represent a flight
typedef struct {
    int flightID;
    char airline[50];
    char source[50];
    char destination[50];
    int departureTime;
    int arrivalTime;
} Flight;

// Global array to store flights
Flight flights[Mflight];
int totalFlights = 0;

// Function to add a new flight
void addFlight() {
    Flight newFlight;
    printf("\nEnter Flight ID: ");
    scanf("%d", &newFlight.flightID);
    printf("Enter Airline: ");
    scanf(" %[^\n]s", newFlight.airline);
    printf("Enter Source: ");
    scanf(" %[^\n]s", newFlight.source);
    printf("Enter Destination: ");
    scanf(" %[^\n]s", newFlight.destination);
    printf("Enter Departure Time (in 24-hour format): ");
    scanf("%d", &newFlight.departureTime);
    printf("Enter Arrival Time (in 24-hour format): ");
    scanf("%d", &newFlight.arrivalTime);

    if (totalFlights < Mflight) {
        flights[totalFlights++] = newFlight;
        printf("\nFlight added successfully!\n");
    } else {
        printf("\nFlight database is full. Cannot add more flights.\n");
    }
}

// Function to display all flights
void displayFlights() {
    if (totalFlights == 0) {
        printf("\nNo flights in the database.\n");
    }
    else {
        printf("\nFlights in the database:\n");
        printf("----------------------------------------------------------\n");
        printf("ID\tAirline\t\tSource\t\tDestination\tDeparture\tArrival\n");
        printf("----------------------------------------------------------\n");

        for (int i = 0; i < totalFlights; i++) {
            printf("%d\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n", flights[i].flightID, flights[i].airline,
                   flights[i].source, flights[i].destination, flights[i].departureTime, flights[i].arrivalTime);
        }

        printf("----------------------------------------------------------\n");
    }
}

// Function to search for flights by source and destination
void searchFlights() {
    char searchSource[50];
    char searchDestination[50];
    printf("\nEnter the source airport: ");
    scanf(" %[^\n]s", searchSource);
    printf("Enter the destination airport: ");
    scanf(" %[^\n]s", searchDestination);

    int found = 0;
    for (int i = 0; i < totalFlights; i++) {
        if (strcmp(flights[i].source, searchSource) == 0 && strcmp(flights[i].destination, searchDestination) == 0) {
            printf("\nFlight found!\n");
            printf("ID: %d\n", flights[i].flightID);
            printf("Airline: %s\n", flights[i].airline);
            printf("Source: %s\n", flights[i].source);
            printf("Destination: %s\n", flights[i].destination);
            printf("Departure Time: %d\n", flights[i].departureTime);
            printf("Arrival Time: %d\n", flights[i].arrivalTime);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo flights found for the specified source and destination.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nFlight Management System\n");
        printf("----------------------------\n");
        printf("1. Add Flight\n");
        printf("2. Display Flights\n");
        printf("3. Search Flights\n");
        printf("4. Exit\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFlight();
                break;
            case 2:
                displayFlights();
                break;
            case 3:
                searchFlights();
                break;
            case 4:
                printf("\nThank you for using the Flight Management System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
