(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   crossover.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/17 15:02:13 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/17 15:29:14 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let crossover l1 l2 =
  let rec cmp_elem list elem =
	match list with
	| [] ->
	   false
	| c::n ->
	   if (c = elem) then
		 true
	   else
		 cmp_elem n elem
  in
  let rec inner l1 l2 result =
	match l1 with
	| [] -> result
	| c::n ->
	   if (cmp_elem l2 c && cmp_elem result c = false) then
		 inner n l2 (result @ [c])
	   else
		 inner n l2 result
  in
  let rec list_length list result =
	match list with
	| [] ->
	   result
	| c::n ->
	   list_length n (result + 1)
  in
  if (list_length l1 0 > list_length l2 0) then
	inner l2 l1 []
  else
	inner l1 l2 []

let () =
  let rec print_list_string myList = match myList with
	| [] -> print_endline "This is the end of the string list!"
	| head::body ->
	   begin
		 print_endline head;
		 print_list_string body
	   end
  in
  let l1 = ["A";
			"apricot";
			"raspberry";
			"cherry";
			"tomato";
			"raspberry";
			"A";
			"A";
			"Mad Max"]
  in
  let l2 = ["A";
			"apricot";
			"raspberry";
		    "A";
			"Mad Max";
			"Max"]
  in
  print_list_string l1;
  print_list_string l2;
  print_list_string (crossover l1 l2);
  print_list_string (crossover l2 l1);
  print_list_string (crossover l1 []);
  print_list_string (crossover [] l2);
  print_list_string (crossover [] [])
