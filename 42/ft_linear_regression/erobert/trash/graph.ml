(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_graphics.ml                                     :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/18 13:56:00 by erobert           #+#    #+#             *)
(*   Updated: 2016/01/05 19:27:18 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let () =
  if Array.length (Sys.argv) <> 2 then
	print_endline (Sys.argv.(0) ^ " file.csv")
  else
	let result = ref [] in
	let fd = open_in (Sys.argv.(1)) in
	try
	  while true; do
		let splitted_line = Str.split (Str.regexp "[,\t]+") (input_line fd) in
		result := [float_of_string (List.nth splitted_line 0) , float_of_string (List.nth splitted_line 1)]
	  done;
	with End_of_file ->
	  close_in fd;
	  let print_array a =
		let len = Array.length a - 1 in
		for i = 0 to len do
		  print_float a.(i); print_string ","
		done
	  in
	  print_array result;
  Graphics.open_graph " 1024x768";
  Graphics.set_color Graphics.black;
  Graphics.read_key ();
  print_endline "Ciao"
