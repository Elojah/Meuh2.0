(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   eu_dist.ml                                         :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 16:45:55 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/22 17:02:11 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)


let ft_sum (f: float -> float -> float) u v n =
	if (1 > n) then
		nan
	else
		let rec inner_sum (f: float -> float -> float) i n s =
			if (n = i) then
				s
			else
				inner_sum f (i + 1) n ((f u.(i) v.(i)) +. s)
		in
		sqrt (inner_sum f 0 n 0.)

let eu_dist u v =
	if (Array.length u <> Array.length v) then
		nan
	else
		ft_sum (fun a b -> (a -. b) *. (a -. b)) u v (Array.length u)

let () =
	print_float (eu_dist [|0.1; 0.2; 0.3|] [|1.3; 1.5; 12.|]);
	print_char '\n';
	print_float (eu_dist [||] [||]);
	print_char '\n';
	print_float (eu_dist [|1.; 1.; 1.|] [|2.; 2.; 2.|]);
	print_char '\n';
	print_float (eu_dist [|0.1; 0.2; 0.3|] [|1.3; 1.5|]);
	print_char '\n';
	print_float (eu_dist [|1.; 2.; 3.; 4.12|] [|7.; 6.;65.; (-7.)|])
