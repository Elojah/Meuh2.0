(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   leibniz_pi.ml                                      :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 17:40:52 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/16 18:08:25 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let leibniz_pi x =
  if (x <= 0.) then
	-1
  else
	let fct i =
	  if ((i mod 2) = 1) then
		(-1.) /. (2. *. float_of_int(i) +. 1.)
	  else
		1. /. (2. *. float_of_int(i) +. 1.)
	in
	let pi = 4. *. atan 1. in
	let dist x y =
	  if (x < y) then
		y -. x
	  else
		x -. y
	in
	let rec sum (f : int -> float) i x s =
	  if ((dist pi (4. *. s)) < x) then
		i
	  else
		sum f (i + 1) x ((f i) +. s)
	in
	sum fct 0 x 0.

let main () =
  print_int (leibniz_pi 3.);
  print_char '\n';
  print_int (leibniz_pi 0.00000001);
  print_char '\n';
  print_int (leibniz_pi (-3.));
  print_char '\n';
  print_int (leibniz_pi (0.));
  print_char '\n';
  print_int (leibniz_pi 0.0001);
  print_char '\n'

let () = main ()
