#include <stdio.h>
#include "Passenger.h"

#define EXIT_CODE 5
#define BUFF_SIZE 64

void DialogWithUser(Passenger** passengers, int* count_of_passengers);


int main()
{
    int count_of_passengers = 0;

    PrintTaskTopic();

    PromptUserInputPassengersCount(&count_of_passengers);

    Passenger** passengers = NewPassengersArray(count_of_passengers);

    FillPassengersArray(passengers, count_of_passengers);

	DialogWithUser(passengers, &count_of_passengers);
   
    FreePassengerArray(passengers, count_of_passengers);

    return 0;
}


void DialogWithUser(Passenger** passengers, int* count_of_passengers)
{
	PrintMenu();
	int user_input;

	while ((user_input = PromptUserInputNumber("Enter function number\n")) != EXIT_CODE)  // is not safe
	{
		switch (user_input)
		{
		case 1:
			AppendInPassengersArray(FillPassengerData(NewPassenger()), &passengers, count_of_passengers);
			break;
		case 2:
			PrintPassengersArray(passengers, *count_of_passengers);
			break;
		case 3:
		{
			char* airline_name = NULL;
			PrintAllAirlineFlights(PromptUserInputStr("Enter the name of the airline\n", airline_name), passengers, *count_of_passengers);
			free(airline_name);
			break;
		}
		case 4:
		{
			PrintPassengersOfGivenFlingt(passengers, *count_of_passengers);
			break;
		}
		default:
			break;
		}

		PrintMenu();
	}
}
