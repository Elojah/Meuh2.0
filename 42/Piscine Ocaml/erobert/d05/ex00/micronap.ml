(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   micronap.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 13:14:06 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/22 14:11:10 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

(* oo unix.cmxa micronap.ml *)

let my_sleep () = Unix.sleep 1

let str_digit str =
	let result = ref true in
	for i = 0 to ((String.length str) - 1) do
		if str.[i] < '0' || str.[i] > '9' then
			result := false
	done;
	!result

let () =
	if Array.length (Sys.argv) <> 2 then
		print_endline (Sys.argv.(0) ^ " int positif")
	else
		if str_digit Sys.argv.(1) then
			for i = 1 to int_of_string Sys.argv.(1) do
				my_sleep ()
			done
		else
			print_endline (Sys.argv.(0) ^ " int positif")
