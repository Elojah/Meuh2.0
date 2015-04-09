// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Time.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/08 15:56:18 by erobert           #+#    #+#             //
//   Updated: 2015/04/08 15:56:23 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <sys/time.h>
#include "Time.hpp"

Time::Time(void)
{
	gettimeofday(&this->_currentTime, 0);
	gettimeofday(&this->_lastTime, 0);
}
Time::~Time(void) {}

int					Time::msSinceLastTime(void)
{
	unsigned long	ms;
	int				ret;

	ms = static_cast<unsigned long>(this->_currentTime.tv_usec);
	if (this->_currentTime.tv_sec != this->_lastTime.tv_sec)
		ms += (this->_currentTime.tv_sec - this->_lastTime.tv_sec) * 1000000;
	ms -= this->_lastTime.tv_usec;
	ret = static_cast<int>(ms / 1000);
	return (ret);
}

void				Time::setCurrentTime(void)
{
	gettimeofday(&this->_currentTime, 0);
}

void				Time::setLastTime(struct timeval value)
{
	this->_lastTime.tv_usec = value.tv_usec;
	this->_lastTime.tv_sec = value.tv_sec;
}

struct timeval		Time::getCurrentTime(void)
{
	return (this->_currentTime);
}
