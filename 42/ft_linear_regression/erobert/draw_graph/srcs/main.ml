(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/01/06 15:03:30 by erobert           #+#    #+#             *)
(*   Updated: 2016/01/07 16:58:14 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let read_csv =
  try
	let data = ref [] in
	let oi = open_in (Sys.argv.(1)) in
	try
	  (
		ignore (input_line oi);
		while true do
		  let splitted = Str.split (Str.regexp "[,\t]+") (input_line oi) in
		  data := [int_of_string (List.nth splitted 0) * 1024 / 300000,
				   int_of_string (List.nth splitted 1) * 1024 / 9000] @ !data
		done;
		[]
	  )
	with End_of_file ->
	  (
		close_in oi;
		!data
	  )
  with _ ->
	  []

let read_result =
  try
	let oi = open_in (Sys.argv.(2)) in
	try
	  let t0 = input_line oi in
	  let t1 = input_line oi in
		(float_of_string (t0), float_of_string (t1))
	with End_of_file ->
	  (
		close_in oi;
		(0., 0.)
	  )
  with _ ->
	  (0., 0.)
		
	  
let () =
  let data = read_csv in
  let (t0, t1) = read_result in
  if data != [] then
	(
	  Graphics.open_graph " 1024x1024";
	  Graphics.set_color Graphics.blue;
	  Graphics.plots (Array.of_list data);
	  Graphics.set_color Graphics.green;
	  Graphics.moveto 0 (int_of_float (t0 *. 1024. /. 9000.));
	  Graphics.lineto 1024
					  (int_of_float ((t0 +. t1 *. 300000.) *. 1024. /. 9000.));
	  Graphics.read_key ();
	  print_endline "Ciao"
	)
  else
	print_endline (Sys.argv.(0) ^ " data.csv result");
