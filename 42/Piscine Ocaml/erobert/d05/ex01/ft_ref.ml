(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ft_ref.ml                                          :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/22 13:43:14 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/22 17:20:54 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

type 'a ft_ref = {mutable a: 'a}

let return a =
	{a = a}

let get r =
	r.a

let set r a =
	r.a <- a

let bind r (f: 'a -> 'b ft_ref) =
	(f r.a)

let () =
	let a = return "Hey" in
	print_endline (get a);
	set a "Nice";
	print_endline (get a);
	let b = bind a (fun a -> return (a ^ " and cool")) in
	print_endline (get b);
	print_endline (get a);
	set b "Ciao";
	print_endline (get b);
