(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/26 12:22:42 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/26 19:57:06 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type TRY =
	sig
		type 'a t = Success of 'a | Failure of exn
		val bind: 'a t -> ('a -> 'b t) -> 'b t
		val recover: 'a t -> (exn -> 'a t) -> 'a t
		val filter: 'a t -> ('a -> bool) -> 'a t
		val flatten: 'a t t -> 'a t
		val return: 'a -> 'a t
	end

module Try: TRY =
	struct
		exception Filter
		
		type 'a t = Success of 'a | Failure of exn
		let bind t f =
			match t with
			| Success (a) -> (try (f a) with e -> Failure (e))
			| Failure (e) -> Failure (e)
		let recover t f =
			match t with
			| Failure (e) -> f e
			| Success (a) -> t
		let filter t f =
			match t with
			| Failure (e) -> Failure Filter
			| Success (a) ->
				 if (f a) then
					 Success (a)
				 else
					 Failure Filter
		let flatten t =
			match t with
			| Failure (e) -> Failure (e)
			| Success (a) ->
				 (
					 match a with
					 | Failure (e) -> Failure e
					 | Success (a) -> Success (a)
				 )
		let return t = Success (t)
	end

let () =
	let print t =
		match t with
		| Try.Failure (_) -> print_endline "Failure"
		| Try.Success (_) -> print_endline "Success"
	in
	let null = Try.return 0 in
	let b = Try.bind null (fun x -> Try.return (1 / x)) in
	print null;
	print b;
	let test = Try.return "String_test" in
	let fn (s:string): bool = String.length s > 20 in
	let result = Try.filter test fn in
	print result;
	let fla = Try.return (result) in
	print (Try.flatten fla);
	let fn_error (e:exn) = match e with
		| _ -> Try.return "I am recovered !"
	in
	let recovered = Try.recover result fn_error in
	print recovered;
	let fla2 = Try.return (Try.return "Inception ...") in
	print (Try.flatten fla2);
	print_endline "Ciao"
