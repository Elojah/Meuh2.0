(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   converges.ml                                       :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 16:33:54 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/16 17:14:56 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let converges f a n =
  if (n < 0) then
	false
  else if (n = 0) then
	true
  else
	let rec inner f a n o =
	  if (a = o) then
		true
	  else if (n = 0) then
		(f a) = a
	  else
		inner f (f a) (n - 1) a
	in
	inner f (f a) (n - 1) a

let main () =
  if (converges (( * ) 2) 2 5) then
	print_endline "True"
  else
	print_endline "false";
  if (converges (fun x -> x / 2) 2 3) then
	print_endline "True"
  else
	print_endline "false";
  if (converges (fun x -> x / 2) 2 2) then
	print_endline "True"
  else
	print_endline "false";
  if (converges (fun x -> x / 2) 2 1) then
	print_endline "True"
  else
	print_endline "false";
  if (converges (fun x -> x / 2) 2 0) then
	print_endline "True"
  else
	print_endline "false";
  if (converges (fun x -> x / 2) 2 (-1)) then
	print_endline "True"
  else
	print_endline "false";
  if (converges (fun x -> x /. 2.0) 2.0 4) then
	print_endline "True"
  else
	print_endline "false"

let () = main ()
