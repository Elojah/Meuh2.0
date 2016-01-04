(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_is_palindrome.ml                                :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 14:35:40 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/15 14:44:31 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_is_palindrome str =
  let rec loop str len i =
	if (i <= len / 2 && len <> 0) then
	  if (str.[i] <> str.[len - i - 1]) then
		false
	  else
		loop str len (i + 1)
	else
	  true
  in
  loop str (String.length str) 0

let main () =
  if (ft_is_palindrome "radar") then
	print_endline "Nice"
  else
	print_endline "...";
  if (ft_is_palindrome "MAX") then
	print_endline "Nice"
  else
	print_endline "...";
  if (ft_is_palindrome "00") then
	print_endline "Nice"
  else
	print_endline "...";
    if (ft_is_palindrome "01") then
	print_endline "Nice"
  else
	print_endline "...";
  if (ft_is_palindrome "") then
	print_endline "Nice"
  else
	print_endline "..."

let () = main ()
		 
