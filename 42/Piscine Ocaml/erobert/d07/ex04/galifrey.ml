(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   galifrey.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 16:16:19 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/24 18:03:55 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class galifrey (rlst: Dalek.dalek list)
							 (dlst: Doctor.doctor list)
							 (plst: People.people list) =
object
	initializer
		print_endline "This is WAR!"

	val _rlst = new Army.army (rlst: Dalek.dalek list)
	val _dlst = new Army.army (dlst: Doctor.doctor list)
	val _plst = new Army.army (plst: People.people list)

	method do_time_war =
		let rec inner daleks people doctors =
			if (daleks#is_empty) then
				print_endline "People win."
			else if (people#is_empty) then
				print_endline "Dalek win."
			else if (doctors#is_empty) then
				print_endline "Doctors left people with their sad story."
			else
				(
					daleks#get_first#exterminate people#get_first;
					doctors#get_first#use_sonic_screwdriver;
					daleks#get_first#die;
					if (Random.int 3 = 1) then
						(
							doctors#get_first#travel_in_time 2015 3015;
							inner (daleks#delete) (people#delete) (doctors#delete)
						)
					else
							inner (daleks#delete) (people#delete) (doctors)
				)
		in
		inner _rlst _plst _dlst
end
