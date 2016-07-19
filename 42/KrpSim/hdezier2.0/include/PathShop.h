/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PathShop.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:42:09 by leeios            #+#    #+#             */
/*   Updated: 2016/07/19 17:02:03 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_SHOP_H
# define PATH_SHOP_H

# include "path_type.h"
# include "resource_type.h"
# include "task_type.h"

class ResourceShop;

class PathShop
{
public:
	static const t_path_origin_mult	get_paths(
		const std::string &resource_name
		, const t_resource_pack &initial_resources
		, ResourceShop &resource_shop
		, const t_tasks &tasks);
private:
	PathShop(void) = default;
	~PathShop(void) = default;
};

#endif
