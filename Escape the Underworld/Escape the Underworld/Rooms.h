#ifndef ROOMS
#define ROOMS



class Rooms{
public:
	char name[39];
	char description[250];	
	Rooms();
	~Rooms();
	Rooms *position;
	Rooms *origin;
	Rooms *destination;
};

#endif //ROOMS