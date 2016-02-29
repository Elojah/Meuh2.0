(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   ex01.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/23 13:55:04 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/23 14:40:43 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type STRINGHASH =
	sig
		type t = string
		val equal: t -> t -> bool
		val hash: t -> int
	end

module StringHash: STRINGHASH=
	struct
		type t = string
		let equal s1 s2 = s1 = s2
		let hash str =
			let rec inner str i result =
				if (i = String.length str) then
					result
				else
					inner str (i + 1)
								((Hashtbl.hash str) mod int_of_char(String.get str i))
			in
			inner str 0 0
	end

module StringHashtbl = Hashtbl.Make (StringHash)

let () =
	let ht = StringHashtbl.create 5 in
	let values = [ "Hello"; "world"; "42"; "Ocaml"; "H" ] in
	let pairs = List.map (fun s -> (s, String.length s)) values in
	List.iter (fun (k,v) -> StringHashtbl.add ht k v) pairs;
	StringHashtbl.iter (fun k v -> Printf.printf "k = \"%s\", v = %d\n" k v) ht
