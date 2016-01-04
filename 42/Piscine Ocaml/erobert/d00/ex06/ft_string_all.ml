(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_string_all.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 14:24:00 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/15 14:40:39 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_string_all fct str =
  let rec loop fct str n =
	if (n < String.length str) then
	  if (fct (str.[n])) then
		loop fct str (n + 1)
	  else
		false
	else
	  true
  in
  loop fct str 0

let main () =
  let is_digit c =
	c >= '0' && c <= '9'
  in
  if (ft_string_all is_digit "") then
	print_endline "Nice"
  else
	print_endline "...";
  if (ft_string_all is_digit "0123a456789") then
	print_endline "Nice"
  else
	print_endline "...";
  if (ft_string_all is_digit "0123456789") then
	print_endline "Nice"
  else
	print_endline "...";
  if (ft_string_all is_digit "0123456789a") then
	print_endline "Nice"
  else
	print_endline "..."

let () = main ()
