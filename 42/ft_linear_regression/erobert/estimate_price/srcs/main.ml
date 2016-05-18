(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/01/06 15:03:30 by erobert           #+#    #+#             *)
(*   Updated: 2016/01/07 20:44:22 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let read_result =
  try
	let oi = open_in (Sys.argv.(1)) in
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
	   print_endline (Sys.argv.(0) ^ " result");
	   (0., 0.)

let () =
  let (t0, t1) = read_result in
  print_endline "Estimate your car price, enter your car mileage:";
  let rec inner () =
	try
	  (
		let price = ceil (t0 +. t1 *. (read_float ())); in
		print_endline "Your car value:";
		print_float price;
		print_endline "\nCiao"
	  )
	with _ ->
	  (
		print_endline "Will you enter a real value?";
		inner ()
	  )
  in
  inner ()
