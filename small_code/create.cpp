#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "create.h"

CreateAndDestroy::CreateAndDestroy( int value )
{
	data = value;
	cout << "Object " << data << "  constructor";
}

CreateAndDestroy::~CreateAndDestroy()
{
	cout << "Object " << data << "  destructor " << endl;
}

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include "create.h"

void create( void );

CreateAndDestroy first(1);

int main()
{
	cout << "  (global created before main)" << endl;
	
	CreateAndDestroy second(2);
	cout << "  (local automatic in main)" << endl;
	
	static CreateAndDestroy third(3);
	cout << "  (local static in main)" << endl;
	
	create();
	
	CreateAndDestroy fourth(4);
	cout << "  (local automatic in main)" << endl;
	return 0;
}

void create( void )
{
	CreateAndDestroy fifth(5);
	cout << "  (local automatic in create)" << endl;
	
	static CreateAndDestroy sixth(6);
	cout << "  (local static in create)" << endl;
	
	CreateAndDestroy seventh(7);
	cout << "  (local automatic in create)" << endl;
}


