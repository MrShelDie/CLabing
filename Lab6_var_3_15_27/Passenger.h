#ifndef PASSENGER_H
#define PASSENGER_H

typedef struct Passenger Passenger;

Passenger* NewPassenger();

Passenger* FillPassengerData(Passenger* passenger);

Passenger** NewPassengersArray(int array_size);

void FreePassengerArray(Passenger** passengers, int array_size);

Passenger** FillPassengersArray(Passenger** passengers, int array_size);

Passenger** AppendInPassengersArray(const Passenger* passenger, Passenger*** passengers, int* array_size);

void PrintTaskTopic();

void PrintMenu();

void PrintPassengerInfo(Passenger* passenger);

void PrintPassengersArray(const Passenger** passengers, int array_size);

void PrintPassengersOfGivenFlingt(Passenger** passengers, int count_of_passengers);

void PromptUserInputPassengersCount(int* count_passengers);

char* PromptUserInputStr(const char* prompt, char* output);

int PromptUserInputNumber(const char* prompt);

#endif
