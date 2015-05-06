// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorDisplay.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 14:25:12 by erobert           #+#    #+#             //
//   Updated: 2015/01/17 15:04:10 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef I_MONITOR_DISPLAY_HPP
# define I_MONITOR_DISPLAY_HPP

class IMonitorDisplay
{
private:
	IMonitorDisplay(void) {}
	IMonitorDisplay(IMonitorDisplay const &iMD);

	virtual IMonitorDisplay		&operator=(IMonitorDisplay const &iDM);
public:
	virtual ~IMonitorDisplay(void) {}
};

#endif
