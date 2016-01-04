(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/26 12:22:42 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/26 12:59:06 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module Watchtower =
	struct
		type hour = int
		let (zero:hour) = 12
		let add (h1:hour) (h2:hour): hour =
			let result = (h1 mod zero + h2 mod zero + zero + zero) mod zero in
			if (result = 0) then
				zero
			else
				result
		let sub (h1:hour) (h2:hour): hour =
			let result = (h1 mod zero - h2 mod zero + zero + zero) mod zero in
			if (result = 0) then
				zero
			else
				result
	end

let () =
	let h1:Watchtower.hour = 12
	and h2:Watchtower.hour = 3
	and h3:Watchtower.hour = -1
	and h4:Watchtower.hour = 10
	in
	print_int (Watchtower.add h1 0);
	print_char '\n';
	print_int (Watchtower.add h1 h2);
	print_char '\n';
	print_int (Watchtower.add h3 h4);
	print_char '\n';
	print_int (Watchtower.sub h2 h4);
	print_char '\n';
	print_int (Watchtower.add h2 h4);
	print_char '\n';
	let rec inner n f =
		match n with
		| 24 ->
			 ()
		| _ ->
			 print_int (f 0 n);
			 print_char '-';
			 inner (n + 1) f
	in
	inner 0 (Watchtower.add);
	print_char '\n';
	inner 0 (Watchtower.sub);
	print_char '\n';
	print_endline "Ciao"
