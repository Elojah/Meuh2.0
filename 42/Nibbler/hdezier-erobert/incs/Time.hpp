// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Time.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/08 13:26:20 by erobert           #+#    #+#             //
//   Updated: 2015/04/08 13:27:48 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TIME_HPP
# define TIME_HPP

# include <sys/time.h>

class Time
{
public:
	Time(void);
	~Time(void);

	int				msSinceLastTime(void);
	void			setCurrentTime(void);
	void			setLastTime(struct timeval value);
	struct timeval	getCurrentTime(void);
private:
	Time(const Time &t);

	Time			&operator=(const Time &t);

	struct timeval	_currentTime;
	struct timeval	_lastTime;
};

#endif
