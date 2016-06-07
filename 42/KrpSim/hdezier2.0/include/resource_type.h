/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_type.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 04:23:04 by leeios            #+#    #+#             */
/*   Updated: 2016/06/06 04:24:09 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <vector>

typedef std::tuple<std::string, uint64_t> t_resource_number;
typedef std::vector<std::tuple<std::string, uint64_t>> t_resource_pack;
