(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_print_rev.ml                                    :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/15 14:09:27 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/15 14:23:17 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

let ft_print_rev (str) =
  let rec loop str n =
	if (n > 0) then
	  begin
		print_char (str.[n - 1]);
		loop str (n - 1)
	  end
  in
  loop str (String.length str);
  print_char '\n'

let main () =
  ft_print_rev "Hello, I'm Max, Mad Max";
  ft_print_rev ""
	
let () = main ()
