#ifndef PASSENGER_H
#define PASSENGER_H

typedef struct Passenger Passenger;

Passenger* NewPassenger();

Passenger* FillPassengerData(Passenger* passenger);

Passenger** NewPassengersArray(int array_size);

void FreePassengerArray(Passenger** passengers, int array_size);

Passenger** FillPassengersArray(Passenger** passengers, int array_size);

Passenger** AppendInPassengersArray(const Passenger* passenger, Passenger*** passengers, int* array_size);

Passenger** FindPassengersOnTheSameFlight
(int flight_number, Passenger** all_passengers, Passenger** passengers_on_the_same_flight, int array_size);

Passenger** FitArraySize_Passenger(Passenger*** passengers, int in_array_size, int* out_array_size);

Passenger** SortPassengerArrayByName(Passenger** passengers, int array_size);

void PrintTaskTopic();

void PrintMenu();

void PrintPassengerInfo(Passenger* passenger);

void PrintPassengersArray(const Passenger** passengers, int array_size);

void PrintAllAirlineFlights(const char* company_name, Passenger** passengers, int count_of_passengers);

void PromptUserInputPassengersCount(int* count_passengers);

char* PromptUserInputStr(const char* prompt);

int PromptUserInputNumber(const char* prompt);

#endif