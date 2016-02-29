(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   encode.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/17 13:20:42 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/17 15:19:37 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let encode list =
  let rec add_list elem list result =
	match list with
	| [] ->
	   result @ [(1, elem)]
	| (count, data)::tail ->
	   if (data = elem) then
		 result @ ([(count + 1, elem)] @ tail)
	   else
		 add_list elem tail (result @ [(count, data)])
  in
  let rec store list result =
	match list with
	| [] ->
	   result
	| head::tail ->
	   store tail (add_list head result [])
  in
  store list []

let () =
  let rec print_list_string myList = match myList with
	| [] -> print_endline "This is the end of the string list!"
	| head::body ->
	   begin
		 print_endline head;
		 print_list_string body
	   end
  in
  let rec print_list_tuple myList = match myList with
	| [] -> print_endline "This is the end of the string list!"
	| (count, elt)::body ->
	   begin
		 print_int count;
		 print_char '_';
		 print_endline elt;
		 print_list_tuple body
	   end
  in
  let lst = ["A";
			 "apricot";
			 "raspberry";
			 "cherry";
			 "tomato";
			 "raspberry";
			 "A";
			 "A"]
  in
  print_list_string lst;
  print_list_tuple (encode lst);
  print_list_tuple (encode [])
