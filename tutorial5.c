#include <stdio.h>

struct dogsFavs {

	char *food;
	char *friend;

};


typedef struct dog{

	const char *name;
	const char *breed;
	const int avgHeightCm;
	int avgWeightLbs;

	struct dogsFavs favouriteThings;

} dog;

void getDogInfo(struct dog theDog){

	printf("\n");
	printf("Name: %s\n\n", theDog.name);
	printf("Breed: %s\n\n", theDog.breed);
	printf("Height: %d\n\n", theDog.avgHeightCm);
	printf("Weight: %d\n\n", theDog.avgWeightLbs);

}


void getMemoryLocations(struct dog theDog){
	
	printf("Name location: %p\n\n", theDog.name);
	printf("Breed location: %p\n\n", theDog.breed);
	printf("Height location: %p\n\n", &theDog.avgHeightCm);
	printf("Weight location: %p\n\n", &theDog.avgWeightLbs);
	printf("Size of Name: %lu\n\n", sizeof(theDog.name));
	printf("Size of Breed: %lu\n\n", sizeof(theDog.breed));
	printf("Size of Height: %lu\n\n", sizeof(&theDog.avgHeightCm));
	printf("Size of Weight: %lu\n\n", sizeof(theDog.avgWeightLbs));


}

void getDogsFavs(dog theDog){

	printf("\n");

	printf("%s loves %s and his friend is %s\n\n", 
		theDog.name,
		theDog.favouriteThings.food,
		theDog.favouriteThings.friend);

}

void setDogWeight(dog theDog, int newWeight){

	theDog.avgWeightLbs = newWeight;

	printf("the weight was changed to %d\n\n", theDog.avgWeightLbs);

}

void setDogWeightPtr(dog *theDog, int newWeight){

	(*theDog).avgWeightLbs = newWeight; //can use (* ) for structs or 							//use arrows

	printf("the weight was changed to %d\n\n", theDog->avgWeightLbs);

}

void main(){

	//struct dog cujo = {"Cujo", "Saint Bernard", 90, 264};

	//getDogInfo(cujo);

	//struct dog cujo2 = cujo;

	//getMemoryLocations(cujo);

	//getMemoryLocations(cujo2);

	dog benji = {"Benji", "Terrier", 25, 9, {"Biscuits", "Simon"}};

	//getDogsFavs(benji);

	//setDogWeight(benji, 11);

	setDogWeightPtr(&benji, 11);

	printf("the weight in main() %d \n\n", benji.avgWeightLbs);

}
