(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   sequence.ml                                        :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/17 17:39:11 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/17 20:13:43 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let sequence n =
  let list = [1]
  in
  let rec list_to_string list result = match list with
	| [] ->
	   result
	| head::body ->
	   list_to_string body (result ^ (string_of_int head))
  in
  let rec build_level list n elem result =
	match list with
	| [] ->
	   result @ [n] @ [elem]
	| current::next ->
	   if (elem = (-1)) then
		 build_level next (n + 1) current result
	   else if (current = elem) then
		 build_level next (n + 1) elem result
	   else
		 build_level next 1 current (result @ [n] @ [elem])
  in
  let rec build_sequence list n =
	match list with
	| [] ->
	   []
	| current::next ->
	   if (n = 0) then
		 list
	   else
		 build_sequence (build_level next 1 current [])
						(n - 1)
  in
  list_to_string (build_sequence list (n - 1)) ""

let () =
  if (Array.length (Sys.argv) <> 2) then
	print_endline "Need int for argv"
  else if ((int_of_string Sys.argv.(1)) < 1) then
	print_endline "Need argv > 0"
  else
	print_endline (sequence (int_of_string Sys.argv.(1)))
