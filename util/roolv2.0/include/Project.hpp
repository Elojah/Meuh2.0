/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Project.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 17:33:43 by leeios            #+#    #+#             */
/*   Updated: 2015/08/10 20:21:42 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_HPP
# define PROJECT_HPP
# define MAX_MODULES 5

# include "Window.hpp"
# include <string>
# include <vector>

class IModule;

class Project : public Window
{
public:
	Project(const std::string &projectPath, const std::string &projectName);
	virtual ~Project(void);
	void	run(void);
protected:
private:
	IModule			*_mods[MAX_MODULES];
	std::string	_path;
	std::string	_name;
};

#endif
