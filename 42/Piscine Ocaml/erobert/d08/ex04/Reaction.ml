(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   Reaction.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/25 16:05:33 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/26 13:54:01 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

class virtual reaction (s: Molecule.molecule list)
											 (e: Molecule.molecule list) =
				object
					method virtual get_start: (Molecule.molecule * int) list
					method virtual get_result: (Molecule.molecule * int) list
					method virtual balance: reaction
					method virtual is_balanced: bool
				end

class alkane_combustion (alkanes: Alkane.alkane list) =
object (this)
	val _alkanes = alkanes

	method private format_alkanes =
		let rec add_list elem list result =
			match list with
			| [] ->
				 result @ [(elem, 1)]
			| (data, count)::tail ->
				 if (data#equal elem) then
					 result @ [(elem, count + 1)] @ tail
				 else
					 add_list elem tail (result @ [(data, count)])
		in
		let rec store list result =
			match list with
			| [] ->
				 result
			| head::tail ->
				 store tail (add_list head result [])
		in
		store _alkanes []
		
	method get_start: (Molecule.molecule * int) list =
		if (this#is_balanced) then
			let rec inner list carbon hydrogen =
				match list with
				| [] ->
					 carbon + hydrogen / 4
				| head::tail ->
					 inner tail (carbon + head#n) (hydrogen + head#n * 2 + 2)
			in
			this#format_alkanes @ [(new Molecule.oxygen, (inner _alkanes 0 0))]
		else
			raise (Invalid_argument "Reaction not balanced")
	method get_result: (Molecule.molecule * int) list =
		if (this#is_balanced) then
			let rec inner list carbon hydrogen =
				match list with
				| [] ->
					 (carbon, hydrogen)
				| head::tail ->
					 inner tail (carbon + head#n) (hydrogen + head#n * 2 + 2)
			in
			match (inner _alkanes 0 0) with
			| (c, h) ->
				 [(new Molecule.carbon_dioxyde, c)] @ [(new Molecule.water, h / 2)]
		else
			raise (Invalid_argument "Reaction not balanced")
	method balance =
		if (this#is_balanced) then
			{<_alkanes = alkanes>}
		else
			let smallest lst =
				let rec inner lst smallest =
					match lst with
					| [] -> smallest
					| head::tail ->
						 if (((head#n * 2 + 2) mod 4) = 0) then
							 inner tail smallest
						 else
							 inner tail (min head#n smallest)
				in
				match _alkanes with
				| [] -> 0
				| _ ->
					 inner _alkanes 4000000
			in
			let alkane = smallest _alkanes in
			{<_alkanes = _alkanes @ [new Alkane.alkane alkane]>}
		
	method is_balanced: bool =
		let rec inner lst hydrogen =
			match lst with
			| [] -> hydrogen
			| head::tail -> inner tail (hydrogen + head#n * 2 + 2)
		in
		if (((inner _alkanes 0) mod 4) = 0) then
			true
		else
			false
end
