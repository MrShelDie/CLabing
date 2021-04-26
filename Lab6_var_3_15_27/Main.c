#include <stdio.h>
#include "Passenger.h"

#define EXIT_CODE 5
#define BUFF_SIZE 64

int main()
{
    int count_of_passengers = 0;

    PrintTaskTopic();
    PromptUserInputPassengersCount(&count_of_passengers);
    Passenger** passengers = NewPassengersArray(count_of_passengers);
    FillPassengersArray(passengers, count_of_passengers);

    PrintMenu();
    int user_input;

    while ((user_input = PromptUserInputNumber("Enter function number\n")) != EXIT_CODE)  // is not safe
    {
        switch (user_input)
        {
        case 1:
            AppendInPassengersArray(FillPassengerData(NewPassenger()), &passengers, &count_of_passengers);
            break;
        case 2:
            PrintPassengersArray(passengers, count_of_passengers);
            break;
        case 3:
            PrintAllAirlineFlights(PromptUserInputStr("Enter the name of the airline\n"), passengers, count_of_passengers);
            break;
        case 4:
        {
            Passenger** passengers_on_the_same_flight = NewPassengersArray(count_of_passengers);
            FindPassengersOnTheSameFlight(PromptUserInputNumber("Enter the flight number\n"), passengers, passengers_on_the_same_flight, count_of_passengers);
            int count_of_passengers_on_the_same_flight = 0;
            FitArraySize_Passenger(&passengers_on_the_same_flight, count_of_passengers, &count_of_passengers_on_the_same_flight);
            SortPassengerArrayByName(passengers_on_the_same_flight, count_of_passengers_on_the_same_flight);
            PrintPassengersArray(passengers_on_the_same_flight, count_of_passengers_on_the_same_flight);
            FreePassengerArray(passengers_on_the_same_flight, count_of_passengers_on_the_same_flight);
            break;
        }
        default:
            break;
        }

        PrintMenu();
    }

    FreePassengerArray(passengers, count_of_passengers);

    //AppendInPassengersArray(FillPassengerData(NewPassenger()), &passengers, &count_of_passengers);
    //
    //PrintPassengerInfo(passengers[0]);
    //PrintPassengerInfo(passengers[1]);


    //Passenger** passengers_on_the_same_flight = NewPassengersArray(count_of_passengers);

    //FindPassengersOnTheSameFlight(1, passengers, passengers_on_the_same_flight, count_of_passengers);

    //int fitted_array_size = 0;

    //FitArraySize_Passenger(&passengers_on_the_same_flight, count_of_passengers, &fitted_array_size);

    //SortPassengerArrayByName(passengers_on_the_same_flight, fitted_array_size);

    //PrintPassengerInfo(passengers_on_the_same_flight[0]);
    //PrintPassengerInfo(passengers_on_the_same_flight[1]);

    return 0;
}