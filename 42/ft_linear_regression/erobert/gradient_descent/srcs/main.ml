(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <marvin@42.fr>                     +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2016/01/06 12:32:30 by erobert           #+#    #+#             *)
(*   Updated: 2016/01/06 14:52:12 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type t = {t0: float; t1: float}

let sub_sum data teta =
  let rec inner data result =
	match data with
	| [] ->
	   result
	| (mileage, price)::tail ->
	   let x = teta.t0 +. teta.t1 *. mileage -. price in
	   inner tail {t0 = result.t0 +. x; t1 = result.t1 +. x *. mileage}
  in
  inner data {t0 = 0.; t1 = 0.}
		
let rec gradient_descent data teta alpha iter =
  let tmp = sub_sum data teta in
  if (abs_float tmp.t1) > 0.001 && iter > 0 then
	let len = float_of_int (List.length data) in
	gradient_descent data
					 {
					   t0 = teta.t0 -. alpha /. len *. tmp.t0;
					   t1 = teta.t1 -. alpha /. len *. tmp.t1
					 }
					 alpha
					 (iter - 1)
  else
	teta

let scale (mileage, price) =
  (mileage /. 300000., price)

let read_csv =
  try
	  let data = ref [] in
	  let oi = open_in (Sys.argv.(1)) in
	  try
		(
		  ignore (input_line oi);
		  while true do
			let splitted = Str.split (Str.regexp "[,\t]+") (input_line oi) in
			data := [float_of_string (List.nth splitted 0),
					float_of_string (List.nth splitted 1)] @ !data
		  done;
		  []
		)
	  with End_of_file ->
		(
		  close_in oi;
		  !data
		)
  with _ ->
	print_endline (Sys.argv.(0) ^ " file.csv");
	[]

let () =
  let data = read_csv in
  let teta = gradient_descent (List.map scale data) {t0 = 0.; t1 = 0.} 1. 999 in
  if data != [] then
	(
	  let oc = open_out "result" in
	  output_string oc ((string_of_float teta.t0) ^ "\n");
	  output_string oc ((string_of_float teta.t1) ^ "\n");
	  close_out oc;
	  print_endline "Result printed in the result file";
	  print_string "\tteta0: ";
	  print_float teta.t0;
	  print_string "\n\tteta1: ";
	  print_float teta.t1;
	  print_char '\n';
	)
  else
	();
