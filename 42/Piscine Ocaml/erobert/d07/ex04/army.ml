(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   army.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/24 15:43:59 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/24 17:54:58 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class ['a] army (list: 'a list) =
object
	initializer
		print_endline "We are legion."

	val _list = list

	method get_first =
		match _list with
		| [] -> invalid_arg "No more."
		| head::tail -> head
	method is_empty =
		_list = []
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
