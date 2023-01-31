#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AddIns.h"

enum VehicleState {VS_CAR, VS_TRUCK, VS_BOAT};

typedef struct strCar{
	int numDoors;
	char* rearConfig;
}CarStruct;

typedef struct strTruck{
	int numDoors;
	float towCapacity;
}TruckStruct;

typedef struct strBoat{
	char* motorType;
}BoatStruct;

typedef struct strVehicle{
	enum VehicleState vhcType;
	char* vhcMake;
	char* vhcModel;
	int vhcYear;
	char* vhcVIN;
	union VehicleUnion{
		CarStruct car;
		TruckStruct truck;
		BoatStruct boat;
	}vhcUnion;
}VehicleStruct;
int numVehicle = 0;
VehicleStruct* vehicleArray[500];

/**
* This method swaps pointers.
*
* method: swap
*
* return type: void
*
* parameters:
* xp [VehicleStruct*] first pointer
* yp [VehicleStruct*] second pointer
*
*
* @author Kirk McBrayer
* @since 4/29/22
*
*/	
void swap(VehicleStruct** xp, VehicleStruct** yp)
{
    VehicleStruct* temp = *xp; //tool for swap
    *xp = *yp;
    *yp = temp;
}
/**
* This method sort out the array strings alphabetically.
*
* method: bubbleSort
*
* return type: void
*
* parameters:
* arr[] [VehicleStruct*] pointer of array
* n [int] number of items
*
*
* @author Kirk McBrayer
* @since 4/29/22
*
*/
void bubbleSort(VehicleStruct* arr[], int n)
{
   int i, j; //values of bubble sort 
   bool swapped; //declaration of being swapped
   for (i = 1; i < n; i++)
   {
     swapped = false;
     for (j = 0; j < n - i; j++)
     {
        if (arr[j]->vhcYear > arr[j+1]->vhcYear)
        {
           swap(&(arr[j]), &(arr[j+1]));
           swapped = true;
        }
     }
	 if (swapped == false)
        break;
   }
}
/**
* This method inputs data from the Car type.
*
* method: inputCar
*
* return type: double
*
* parameters:
* inFile [FILE] input the file
* vhcStruct [VehicleStruct*] structure of vehicle arrays
*
*
* @author Kirk McBrayer
* @since 4/29/22
*
*/   

void inputCar(FILE* inFile, VehicleStruct* vhcStruct){
	char buffer[50];
	vhcStruct->vhcType = VS_CAR;
	
	//InputString(inFile, vhcStruct->vhcMake);
	InputString(inFile, buffer);
	vhcStruct->vhcMake = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(vhcStruct->vhcMake, buffer);
	
	//InputString(inFile, vhcStruct->vhcModel);
	InputString(inFile, buffer);
	vhcStruct->vhcModel = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(vhcStruct->vhcModel, buffer);
	
	vhcStruct->vhcYear = InputInteger(inFile);
	
	//InputString(inFile, vhcStruct->vhcVIN);
	InputString(inFile, buffer);
	vhcStruct->vhcVIN = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(vhcStruct->vhcVIN, buffer);
	
	vhcStruct->vhcUnion.car.numDoors = InputInteger(inFile);
	
	//InputString(inFile, vhcStruct->vhcUnion.car.rearConfig);
	InputString(inFile, buffer);
	vhcStruct->vhcUnion.car.rearConfig = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(vhcStruct->vhcUnion.car.rearConfig, buffer);
}

/**
* This method inputs data from the Truck type.
*
* method: inputTruck
*
* return type: double
*
* parameters:
* inFile [FILE] input the file
* vhcStruct [VehicleStruct*] structure of vehicle arrays
*
*
* @author Kirk McBrayer
* @since 4/29/22
*
*/   

void inputTruck(FILE* inFile, VehicleStruct* vhcStruct){
	char buffer[50];
	vhcStruct->vhcType = VS_TRUCK;
	
	//InputString(inFile, vhcStruct->vhcMake);
	InputString(inFile, buffer);
	vhcStruct->vhcMake = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(vhcStruct->vhcMake, buffer);
	
	//InputString(inFile, vhcStruct->vhcModel);
	InputString(inFile, buffer);
	vhcStruct->vhcModel = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(vhcStruct->vhcModel, buffer);
	
	vhcStruct->vhcYear = InputInteger(inFile);
	
	//InputString(inFile, vhcStruct->vhcVIN);
	InputString(inFile, buffer);
	vhcStruct->vhcVIN = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(vhcStruct->vhcVIN, buffer);
	
	vhcStruct->vhcUnion.truck.numDoors = InputInteger(inFile);
	vhcStruct->vhcUnion.truck.towCapacity = InputFloat(inFile);
}

/**
* This method inputs data from the Boat type.
*
* method: inputBoat
*
* return type: double
*
* parameters:
* inFile [FILE] input the file
* vhcStruct [VehicleStruct*] structure of vehicle arrays
*
*
* @author Kirk McBrayer
* @since 4/29/22
*
*/   

void inputBoat(FILE* inFile, VehicleStruct* vhcStruct){
	char buffer[50];
	vhcStruct->vhcType = VS_BOAT;
	
	//InputString(inFile, vhcStruct->vhcMake);
	InputString(inFile, buffer);
	vhcStruct->vhcMake = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(vhcStruct->vhcMake, buffer);
	
	//InputString(inFile, vhcStruct->vhcModel);
	InputString(inFile, buffer);
	vhcStruct->vhcModel = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(vhcStruct->vhcModel, buffer);
	
	vhcStruct->vhcYear = InputInteger(inFile);
	
	//InputString(inFile, vhcStruct->vhcVIN);
	InputString(inFile, buffer);
	vhcStruct->vhcVIN = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(vhcStruct->vhcVIN, buffer);
	
	//InputString(inFile, vhcStruct->vhcUnion.boat.motorType);
	InputString(inFile, buffer);
	vhcStruct->vhcUnion.boat.motorType = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(vhcStruct->vhcUnion.boat.motorType, buffer);
}

/**
* This method outputs data from the Car type.
*
* method: outputCar
*
* return type: double
*
* parameters:
* outFile [FILE] output the file
* vhcStruct [VehicleStruct*] structure of vehicle arrays
*
*
* @author Kirk McBrayer
* @since 4/29/22
*
*/   

void outputCar(FILE* outFile, VehicleStruct* vhcStruct){
	fprintf(outFile, "%s %s %d\nVIN: %s\nDoors: %d\nRear Configuration: %s\n\n", vhcStruct->vhcMake, vhcStruct->vhcModel, vhcStruct->vhcYear, vhcStruct->vhcVIN, vhcStruct->vhcUnion.car.numDoors, vhcStruct->vhcUnion.car.rearConfig);
}

/**
* This method outputs data from the Truck type.
*
* method: outputTruck
*
* return type: double
*
* parameters:
* outFile [FILE] output the file
* vhcStruct [VehicleStruct*] structure of vehicle arrays
*
*
* @author Kirk McBrayer
* @since 4/29/22
*
*/   

void outputTruck(FILE* outFile, VehicleStruct* vhcStruct){
	fprintf(outFile, "%s %s %d\nVIN: %s\nDoors: %d\nMax Towing Capacity: %.1f\n\n", vhcStruct->vhcMake, vhcStruct->vhcModel, vhcStruct->vhcYear, vhcStruct->vhcVIN, vhcStruct->vhcUnion.truck.numDoors, vhcStruct->vhcUnion.truck.towCapacity);
}

/**
* This method outputs data from the Boat type.
*
* method: outputBoat
*
* return type: double
*
* parameters:
* outFile [FILE] output the file
* vhcStruct [VehicleStruct*] structure of vehicle arrays
*
*
* @author Kirk McBrayer
* @since 4/29/22
*
*/   

void outputBoat(FILE* outFile, VehicleStruct* vhcStruct){
	fprintf(outFile, "%s %s %d\nVIN: %s\nMotor: %s\n\n", vhcStruct->vhcMake, vhcStruct->vhcModel, vhcStruct->vhcYear, vhcStruct->vhcVIN, vhcStruct->vhcUnion.boat.motorType);
}

/**
* This program computes a simple ANSI C program to input a set of vehicle values from a text file and
print those values to a separate text file, formatting the output in easily readable form.
*
*
* CSC 3304 Programming project No 6
*
* @author Kirk McBrayer
* @since 4/29/2022
*
*/
int main (){
	VehicleStruct Something;
	
	FILE* inFile = NULL;
	FILE* outFile = NULL;
	
	enum VehicleState vechicleType;
	
	char vhcType[50];
	char vhcMake[50];
	char vhcModel[50];
	int vhcYear;
	char vhcVIN[50];
	int numDoors;
	char rearConfig[50];
	float towCapacity;
	char motorType[50];
	
	char yearLine[50];
	char numLine[50];
	char towLine[50];

	inFile = fopen("TestInput.txt", "r");
	if(!inFile){
		printf("File did not open.");
	}
	outFile = fopen("out.txt", "w");
	if(!outFile){
		printf("File did not open.");
	}
	
	fflush(stdout);
	while(fgets(vhcType, 50, inFile) != NULL){
		
		vehicleArray[numVehicle] = (VehicleStruct*)malloc(sizeof(VehicleStruct));
		
		while(isspace(vhcType[strlen(vhcType) - 1])){
			vhcType[strlen(vhcType) - 1] = '\0';
		}
		if(strcmp(vhcType, "truck") == 0){
			vechicleType = VS_TRUCK;
		}
		else if(strcmp(vhcType, "boat") == 0){
			vechicleType = VS_BOAT;
		}
		else if(strcmp(vhcType, "car") == 0){
			vechicleType = VS_CAR;
		}
		
		switch (vechicleType) {
		case VS_CAR:		
				inputCar(inFile, vehicleArray[numVehicle]);
			break;
		
		case VS_TRUCK:
				inputTruck(inFile, vehicleArray[numVehicle]);
			break;
		
		case VS_BOAT:
				inputBoat(inFile, vehicleArray[numVehicle]);
			break;
		}
		numVehicle++;
	}
	bubbleSort(vehicleArray, numVehicle);
	for(int i = 0; i < numVehicle; i++){
		switch (vehicleArray[i]->vhcType) {
		case VS_CAR:		
				outputCar(outFile, vehicleArray[i]);
			continue;
		
		case VS_TRUCK:
				outputTruck(outFile, vehicleArray[i]);
			continue;
		
		case VS_BOAT:
				outputBoat(outFile, vehicleArray[i]);
			continue;
		}	
	}
	
	for(int i = 0; i < numVehicle; i++){
		//free strings inside struct
		free(vehicleArray[i]->vhcMake);
		free(vehicleArray[i]->vhcModel);
		free(vehicleArray[i]->vhcVIN);
		switch (vehicleArray[i]->vhcType) {
		case VS_CAR:		
				free(vehicleArray[i]->vhcUnion.car.rearConfig);
			continue;
		
		case VS_BOAT:
				free(vehicleArray[i]->vhcUnion.boat.motorType);
			continue;
		}
	}
	
	fclose(inFile);
	fclose(outFile);
	
	return 0;
}


