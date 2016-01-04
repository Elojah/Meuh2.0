(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_comb.ml                                   :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 13:47:14 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/15 14:08:37 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_print_comb () =
  let rec loop_c a b c =
	if (c < 10) then
	  begin
		print_int(a);
		print_int(b);
		print_int(c);
		if (a <> 7 || b <> 8 || c <> 9) then
		  print_string(", ");
		loop_c a b (c + 1)
	  end
  in
  let rec loop_b a b =
	if (b < 9) then
	  begin
		loop_c a b (b + 1);
		loop_b a (b + 1)
	  end
  in
  let rec loop_a a =
	if (a < 8) then
	  begin
		loop_b a (a + 1);
		loop_a (a + 1)
	  end
  in
  loop_a 0;
  print_string "\n"

let main () =
  ft_print_comb ()

let () = main ()
