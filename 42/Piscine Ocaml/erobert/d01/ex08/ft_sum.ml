(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_sum.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/16 17:12:15 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/16 18:22:36 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_sum (f : int -> float) i n =
  if (i > n) then
	nan
  else
	let rec inner_sum (f : int -> float) i n s =
	  if (n = i) then
		(f i) +. s
	  else
		inner_sum f (i + 1) n ((f i) +. s)
	in
	inner_sum f i n 0.

let main () =
  print_float (ft_sum (fun i -> float_of_int (i * i)) 1 10);
  print_char '\n';
  print_float (ft_sum (fun i -> float_of_int (i * i)) 100 10);
  print_char '\n';
  print_float (ft_sum (fun i -> float_of_int (i * i)) 10 10);
  print_char '\n';
  print_float (ft_sum (fun i -> float_of_int (i * i * i)) 1 1000);
  print_char '\n'
  
let () = main ()
