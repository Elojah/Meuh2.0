/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 13:11:30 by leeios            #+#    #+#             */
/*   Updated: 2015/08/15 14:32:45 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_HPP
# define LOG_HPP

# include <fstream>

class Log
{
public:
	Log(void);
	virtual ~Log(void);
	static void									write(const std::string &msg);
	static void									close(void);
	static std::ofstream				&getLog(void);
protected:
private:
	static const char						logFile[15];
	static std::ofstream				_log;
};

#endif
