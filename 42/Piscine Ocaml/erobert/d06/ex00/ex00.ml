(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ex00.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/23 13:26:21 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/23 13:54:48 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module StringSet = Set.Make (String)

let () =
	let set = List.fold_right StringSet.add [ "foo"; "bar"; "baz"; "qux" ]
														StringSet.empty
	in
	StringSet.iter print_endline set;
	print_endline (StringSet.fold ( ^ ) set "")
