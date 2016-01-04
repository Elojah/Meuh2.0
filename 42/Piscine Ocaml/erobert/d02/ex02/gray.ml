(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   gray.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/17 15:31:42 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/17 19:11:25 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let gray n =
  let list = ["0"; "1"]
  in
  let rec list_back list elem =
	match list with
	| [] -> [elem]
	| current::next ->
	   current::(list_back next elem)
  in
  let rec list_concat l1 l2 =
	match l2 with
	| [] ->
	   l1
	| current::next ->
	   list_concat (list_back l1 current) next
  in
  let rec add_reverse list save reverse =
	match list with
	| [] ->
	   list_concat save reverse
	| current::next ->
	   add_reverse next save (current::reverse)
  in
  let rec list_lenght list result=
	match list with
	| [] ->
	   result
	| current::next -> list_lenght next (result + 1)
  in
  let rec add_stage list middle result =
	match list with
	| [] ->
	   result
	| current::next ->
	   if (middle = 0) then
		 add_stage next 0 (list_back result ("1" ^ current))
	   else
		 add_stage next (middle - 1) (list_back result ("0" ^ current))
  in
  let rec inner n result =
	if (n = 1) then
	  result
	else
	  inner (n - 1) (add_stage (add_reverse result result [])
							   (list_lenght result 0)
							   [])
  in
  let rec print_list_int myList = match myList with
	| [] -> print_endline ""
	| head::body ->
	   begin
		 print_string head;
		 if (body <> []) then
		   print_char ' ';
		 print_list_int body
	   end
  in
  if (n > 1) then
	print_list_int (inner n list)
  else if (n = 1) then
	print_list_int list
  else
	print_list_int []

let () =
  if (Array.length (Sys.argv) <> 2) then
	print_endline "Need int for argv"
  else
	gray (int_of_string Sys.argv.(1))
