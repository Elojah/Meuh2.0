(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_alphabet.ml                               :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 13:38:35 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/15 13:45:38 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_print_alphabet () =
  let rec ft_loop c =
	if (c = 'z') then
	  print_char (c)
	else
	  begin
		print_char (c);
		ft_loop (char_of_int(int_of_char(c) + 1))
	  end
  in
  ft_loop 'a';
  print_char '\n'
	
let main () =
  ft_print_alphabet ()

let () = main ()
