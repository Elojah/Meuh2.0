(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   army.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 15:43:59 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/24 16:10:51 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class ['a] army (list: 'a list) =
object
	initializer
		print_endline "We are legion."

	val _list = list

	method add i =
		print_endline i#to_string;
		{< _list = (_list @ [i])>}
	method delete =
		match _list with
		| [] -> {< _list = []>}
		| head::tail -> {< _list = tail>}
	method what_is_your_work =
		let rec inner lst =
			match lst with
			| [] -> ()
			| head::tail ->
				 print_endline head#to_string;
				 inner tail
		in
		inner _list
end
