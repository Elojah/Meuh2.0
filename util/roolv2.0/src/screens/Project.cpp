/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Project.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 17:36:41 by leeios            #+#    #+#             */
/*   Updated: 2015/08/13 22:01:29 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Project.hpp"
#include "IModule.hpp"
#include "ClassMod.hpp"

Project::Project(const std::string &projectPath, const std::string &projectName) :
	Window() {
	_path = projectPath;
	_name = projectName;
	setTitle(_name);
	_mods[0] = new ClassMod(20, 60, 1, 1);
	_mods[1] = nullptr;
}

Project::~Project(void) {
	for (size_t i = 0; i < MAX_MODULES && _mods[i]; ++i) {
		delete _mods[i];
	}
}

void	Project::run(void) {
	for (size_t i = 0; i < MAX_MODULES && _mods[i]; ++i) {
		_mods[i]->construct(_path, _name);
	}
}
