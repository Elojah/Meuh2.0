(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   dalek.ml                                           :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 15:14:06 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/24 15:51:28 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class dalek =
object
	initializer
		print_endline "New Dalek constructed."
									
	val _name =
		"Dalek" ^ (String.make 1 (char_of_int ((Random.int 26) + 65)))
		^ (String.make 1 (char_of_int ((Random.int 26) + 97)))
		^ (String.make 1 (char_of_int ((Random.int 26) + 97)))
	val _hp = 100
	val mutable _shield = true
													
	method set_hp hp =
		if (_shield) then
			{<_name = _name; _hp = _hp; _shield = _shield>}
		else
			{<_name = _name; _hp = hp; _shield = _shield>}
				
	method to_string =
		let is_shield_on =
			if (_shield) then
				"on."
			else
				"off."
		in
		_name ^ " with " ^ (string_of_int _hp) ^ "hp and his shield "
			^ is_shield_on
	method talk =
		match (Random.int 3) with
		| 0 -> print_endline "Explain! Explain!"
		| 1 -> print_endline "Exterminate! Exterminate!"
		| 2 -> print_endline "I obey!"
		| _ ->
			 print_endline "You are the Doctor! You are the enemy of the Daleks!"
	method exterminate (people:People.people) =
		_shield <- (not _shield);
		(people#set_hp 0)#die
	method die =
		print_endline "Emergency Temporal Shift!"
end
