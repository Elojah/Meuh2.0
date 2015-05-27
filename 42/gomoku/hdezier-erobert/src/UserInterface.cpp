#include "UserInterface.hpp"

UserInterface::UserInterface(void)
{}

UserInterface::~UserInterface(void)
{
	if (_window.isOpen())
		_window.close();
}

void	UserInterface::init(int size)
{
	(void)size;
}

void	UserInterface::render(Board const &b
	, Player const &p1, Player const &p2) const
{
}

const UserInterface::sEvent	&UserInterface::getEvent(void) const
{
	return *(new sEvent);
}
