/*
TODO:
    1. Сheck for correspondence between the flight numberand the name of the airline
    2. Safe input in functions marked with "is not safe" comments
    3. Fix functions marked with "TODO"
	4. Sometimes an error pops up when the program ends
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Passenger.h"

#define BUFF_SIZE 64

void PromptUserInputPassengerData_str(const char* prompt, char** field_p, char* buff, int buff_size);
void PromptUserInputPassengerData_int(const char* prompt, int* field);

void SetStructFieldFromKeyboard_str(char** field_p, char* buff, int buff_size);
void SetStructFieldFromKeyboard_int(int* field);

void PrintPassengerInfo_Row(const Passenger* passenger);
void PrintAllAirlineFlights(const char* company_name, Passenger** passengers, int count_of_passengers);
void PrintSeparatorStr();

Passenger** FindPassengersOnTheSameFlight
(int flight_number, Passenger** all_passengers, Passenger** passengers_on_the_same_flight, int array_size);

Passenger** FitArraySize_Passenger(Passenger*** passengers, int in_array_size, int* out_array_size);
Passenger** SortPassengerArrayByName(Passenger** passengers, int array_size);

int cmp_str(const Passenger** a, const Passenger** b);
int cmp_int(const int* a, const int* b);


typedef struct Passenger
{
    char* company_name;
    char* passenger_surname;
    char* passenger_name;
    int   flight_number;
    int   ticket_price;
} Passenger;


void PrintTaskTopic()
{
    printf("Task topic:\n");
    printf("   - Create structure\n");
    printf("   - Implement functions:\n");
    printf("      - add a new passenger\n");
    printf("      - print out information about the passenger in a tabular form\n");
    printf("      - find all flights of a given company\n");
    printf("      - find all passengers of a given flight, sort the result alphabetically\n\n\n");
}


void PromptUserInputPassengersCount(int* count_passengers)  // is not safe
{
    printf("Enter the number of passengers:\n");
    PrintSeparatorStr();
    assert(scanf_s("%d", count_passengers) != 0);
    PrintSeparatorStr();
    printf("\n\n");
}


Passenger* NewPassenger()
{
    Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));
    assert(passenger != NULL);

    (Passenger*)passenger->company_name = NULL;
    (Passenger*)passenger->passenger_surname = NULL;
    (Passenger*)passenger->passenger_name = NULL;
    (Passenger*)passenger->flight_number = NULL;
    (Passenger*)passenger->ticket_price = NULL;

    return passenger;
}


Passenger* FillPassengerData(Passenger* passenger)
{
    char buff[BUFF_SIZE];

    PromptUserInputPassengerData_str
    ("Enter the name of the airline\n", &(passenger->company_name), buff, BUFF_SIZE);

    PromptUserInputPassengerData_str
    ("Enter the last name of the passenger\n", &(passenger->passenger_surname), buff, BUFF_SIZE);

    PromptUserInputPassengerData_str
    ("Enter the first name of the passenger\n", &(passenger->passenger_name), buff, BUFF_SIZE);

    PromptUserInputPassengerData_int
    ("Enter the flight number\n", &passenger->flight_number);

    PromptUserInputPassengerData_int
    ("Enter the ticket_price\n", &passenger->ticket_price);

    printf("\n\n");

    return passenger;
}


void PromptUserInputPassengerData_str(const char* prompt, char** field_p, char* buff, int buff_size)
{
    printf("%s", prompt);
    PrintSeparatorStr();
    printf("   ");
    SetStructFieldFromKeyboard_str(field_p, buff, BUFF_SIZE);
    PrintSeparatorStr();
}


void PromptUserInputPassengerData_int(const char* prompt, int* field)
{
    printf("%s", prompt);
    PrintSeparatorStr();
    printf("   ");
    SetStructFieldFromKeyboard_int(field);
    PrintSeparatorStr();
}


char* PromptUserInputStr(const char* prompt, char* output)     // is not safe
{
    char* buff = (char*)calloc(BUFF_SIZE, sizeof(char));
    printf("%s", prompt);
    PrintSeparatorStr();
    printf("   ");
    assert(scanf_s("%s", buff, BUFF_SIZE) != 0);
	int str_len = strlen(buff) + 1;

	if (output == NULL)
	{
		output = (char*)malloc(sizeof(char) * str_len);
		assert(output != NULL);
	}
	else
	{
		char* tmp = (char*)realloc(output, str_len * sizeof(char));
		assert(tmp != NULL);
		output = tmp;
	}

	strcpy_s(output, str_len, buff);

    PrintSeparatorStr();
    printf("\n\n");
    return output;
}


int PromptUserInputNumber(const char* prompt)     // is not safe
{
    int number = -1;
    printf("%s", prompt);
    PrintSeparatorStr();
    printf("   ");
    assert(scanf_s("%d", &number) != 0);
    PrintSeparatorStr();
    printf("\n\n");
    return number;
}


void PrintSeparatorStr()
{
    printf("--------------------------------------------------------------------------------------\n");
}


void SetStructFieldFromKeyboard_str(char** field_p, char* buff, int buff_size)     // is not safe
{
    int scan_res = scanf_s("%s", buff, BUFF_SIZE);
    assert(scan_res != 0 && scan_res != EOF);       // TODO: buffer overflow protection
    int str_len = strlen(buff) + 1;                 // with \0

    if (*field_p == NULL)
    { 
        *field_p = (char*)malloc(sizeof(char) * str_len);
        assert(*field_p != NULL);
    }
    else
    {
        char* temp = (char*)realloc(*field_p, sizeof(char) * str_len);
        assert(temp != NULL);
        *field_p = temp;
    }

    strcpy_s(*field_p, str_len, buff);
    //scanf("%*[^\n]");     // clear cin buffer
}


void SetStructFieldFromKeyboard_int(int* field)     // is not safe
{
    int value = -1;
    scanf_s("%d", &value);  // returns -1 if int overflow
    assert(value >= 0);     // TODO: overflow protection
    *field = value;
}


void PrintPassengerInfo(const Passenger* passenger)
{
    printf("Field\t\t\tValue\n");
    PrintSeparatorStr();
    printf("Company name\t\t%s\n", passenger->company_name);
    printf("Passenger surname\t%s\n", passenger->passenger_surname);
    printf("Passenger name\t\t%s\n", passenger->passenger_name);
    printf("Flight number\t\t%d\n", passenger->flight_number);
    printf("Ticket price\t\t%d\n", passenger->ticket_price);
    printf("\n\n");
}


void PrintPassengerInfo_Row(const Passenger* passenger)
{
    printf
    (
        "%12s\t%17s\t%14s\t%13d\t%12d\n", passenger->company_name, passenger->passenger_surname,
        passenger->passenger_name, passenger->flight_number, passenger->ticket_price
    );
}


void PrintPassengersArray(const Passenger** passengers, int array_size)
{
    printf("Company name\tPassenger surname\tPassenger name\tFlight number\tTicket price\n");
    PrintSeparatorStr();

    for (int i = 0; i < array_size; i++)
        PrintPassengerInfo_Row(passengers[i]);

    PrintSeparatorStr();
    printf("\n\n");
}


void PrintAllAirlineFlights(const char* company_name, const Passenger** passengers, int count_of_passengers)    // TODO: if no flights were found
{
    int* flights = (int*)calloc(count_of_passengers, sizeof(int));
    assert(flights != NULL);
    int* flight_ptr = flights;

    for (int i = 0; i < count_of_passengers; i++)
    {
        if (strcmp(passengers[i]->company_name, company_name) == 0)     // strings are equal
        {
            *(int*)flight_ptr = passengers[i]->flight_number;
            flight_ptr++;
        }
    }

	int count_of_flights = flight_ptr - flights;

    printf("Company name: %s\n\n", company_name);
    printf("Flights:\n");

	qsort(flights, count_of_flights, sizeof(int), cmp_int);

	if (count_of_flights > 0)
		printf("%d\n", flights[0]);

	for (int i = 1; i < count_of_flights; i++)
	{
		if (flights[i - 1] != flights[i])
			printf("%d\n", flights[i]);
	}

	printf("\n\n");

    free(flights);
}


#pragma warning(push)
#pragma warning(disable : 6386)
Passenger** NewPassengersArray(int array_size)
{
    Passenger** passengers = (Passenger**)malloc(sizeof(Passenger*) * array_size);
    assert(passengers != NULL);

    for (int i = 0; i < array_size; i++)
        passengers[i] = NewPassenger();

    return passengers;
}
#pragma warning(pop)


void FreePassengerArray(Passenger** passengers, int array_size)
{
    for (int i = 0; i < array_size; i++)
        free(passengers[i]);
    free(passengers);
}


Passenger** FillPassengersArray(Passenger** passengers, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        printf("Passenger %d:\n", i + 1);
        FillPassengerData(passengers[i]);
    }

    return passengers;
}


Passenger** AppendInPassengersArray(const Passenger* passenger, Passenger*** passengers, int* array_size)
{
    assert(array_size != NULL);
    (*array_size)++;
    Passenger** tmp = (Passenger**)realloc(*passengers, *array_size * sizeof(Passenger*));
    assert(tmp != NULL);
    *passengers = tmp;

    (*passengers)[*array_size - 1] = passenger;

    return *passengers;
}


Passenger** FindPassengersOnTheSameFlight
(int flight_number, const Passenger** in_passengers, Passenger** out_passengers, int array_size)
{
    Passenger** passengers_on_the_same_flight_ptr = out_passengers;

    for (int i = 0; i < array_size; i++)
    {
        if (in_passengers[i]->flight_number == flight_number)
        {
            memcpy(*passengers_on_the_same_flight_ptr, in_passengers[i], sizeof(Passenger));
            passengers_on_the_same_flight_ptr++;
        }
    }

    return out_passengers;
}


Passenger** FitArraySize_Passenger(Passenger*** passengers, int in_array_size, int* out_array_size)     // TODO: error if size == 0
{
    *out_array_size = 0;
    for (int i = 0; i < in_array_size && (*passengers)[i]->company_name != NULL; i++, (*out_array_size)++);

    Passenger** tmp = (Passenger**)realloc(*passengers, *out_array_size * sizeof(Passenger*));
    assert(tmp != NULL);
    *passengers = tmp;

    return *passengers;
}


Passenger** SortPassengerArrayByName(Passenger** passengers, int array_size)
{
    qsort(passengers, array_size, sizeof(Passenger*), cmp_str);
    return passengers;
}


int cmp_str(const Passenger** a, const Passenger** b)
{
    return strcmp((*a)->passenger_surname, (*b)->passenger_surname);
}


int cmp_int(const int* a, const int* b)
{
	return *a - *b;
}


void PrintPassengersOfGivenFlingt(Passenger** passengers, int count_of_passengers)
{
	Passenger** passengers_on_the_same_flight = NewPassengersArray(count_of_passengers);
	FindPassengersOnTheSameFlight(PromptUserInputNumber("Enter the flight number\n"), passengers, passengers_on_the_same_flight, count_of_passengers);
	int count_of_passengers_on_the_same_flight = 0;
	FitArraySize_Passenger(&passengers_on_the_same_flight, count_of_passengers, &count_of_passengers_on_the_same_flight);
	SortPassengerArrayByName(passengers_on_the_same_flight, count_of_passengers_on_the_same_flight);
	PrintPassengersArray(passengers_on_the_same_flight, count_of_passengers_on_the_same_flight);
	FreePassengerArray(passengers_on_the_same_flight, count_of_passengers_on_the_same_flight);
}


void PrintMenu()
{
    printf("Add new passenger\t\t\t..... 1\n");
    printf("Print passenger database\t\t..... 2\n");
    printf("Find all flights of a given company\t..... 3\n");
    printf("Print passengers of a given flight\t..... 4\n");
    printf("Exit the program\t\t\t..... 5\n\n\n");
}
