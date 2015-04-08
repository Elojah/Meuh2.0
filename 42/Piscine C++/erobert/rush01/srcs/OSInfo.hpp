// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSInfo.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 16:17:29 by erobert           #+#    #+#             //
//   Updated: 2015/01/17 16:56:54 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef O_S_INFO_HPP
# define O_S_INFO_HPP

# include "IMonitorModule.hpp"

class OSInfo: public IMonitorModule
{
private:
	std::string							_title;
	int									_type;
	std::map<std::string, std::string>	_info;

	OSInfo(OSInfo const &oSI);
	OSInfo								&operator=(OSInfo const &oSI);

public:
	OSInfo(void);
	virtual ~OSInfo(void);

	virtual std::string const					&getTitle(void) const;
	virtual int									getType(void) const;
	virtual std::map<std::string, std::string>	getInfo(void);
};

#endif
