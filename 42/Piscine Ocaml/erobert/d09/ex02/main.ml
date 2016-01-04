(* ************************************************************************** *)
(*                                                                            *)
(*                                                        :::      ::::::::   *)
(*   main.ml                                            :+:      :+:    :+:   *)
(*                                                    +:+ +:+         +:+     *)
(*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        *)
(*                                                +#+#+#+#+#+   +#+           *)
(*   Created: 2015/06/26 12:22:42 by erobert           #+#    #+#             *)
(*   Updated: 2015/06/26 14:50:51 by erobert          ###   ########.fr       *)
(*                                                                            *)
(* ************************************************************************** *)

module type MONOID =
	sig
		type element
		val zero1: element
		val zero2: element
		val	add: element -> element -> element
		val	sub: element -> element -> element
		val	mul: element -> element -> element
		val	div: element -> element -> element
	end

module INT =
	struct
		type element = int
		let zero1 = 0
		let zero2 = 1
		let add = ( + )
		let sub = ( - )
		let mul = ( * )
		let div = ( / )
	end

module FLOAT =
	struct
		type element = float
		let zero1 = 0.
		let zero2 = 1.
		let add = ( +. )
		let sub = ( -. )
		let mul = ( *. )
		let div = ( /. )
	end
		
module type Calc =
	functor (M: MONOID) ->
					sig
						val add : M.element -> M.element -> M.element
						val sub : M.element -> M.element -> M.element
						val mul : M.element -> M.element -> M.element
						val div : M.element -> M.element -> M.element
						val power : M.element -> int -> M.element
						val fact : M.element -> M.element
					end

module Calc: Calc =
	functor (M: MONOID) ->
					struct
						let add = M.add
						let sub = M.sub
						let mul = M.mul
						let div = M.div
						let power e n =
							let rec inner n result =
								if (n = 0) then
									result
								else
									inner (n - 1) (mul result e)
							in
							if (n < 0) then
								div M.zero2 (inner (-n) M.zero2)
							else
								inner n M.zero2
						let fact e =
							let rec inner n result =
								if (e < n) then
									if ((add e M.zero2) = n) then
										result
									else
										invalid_arg "Factorial need an integer"
								else
									inner (add n M.zero2) (mul result n)
							in
							inner M.zero2 M.zero2
					end

module Calc_int = Calc(INT)
module Calc_float = Calc(FLOAT)

let () =
	print_endline (string_of_int (Calc_int.power 3 3));
	print_endline (string_of_float (Calc_float.power 3.0 3));
	print_endline (string_of_int (Calc_int.mul (Calc_int.add 20 1) 2));
	print_endline (string_of_float (Calc_float.mul (Calc_float.add 20.0 1.0)
																								 2.0));
	print_endline (string_of_int (Calc_int.fact 9));
	print_endline (string_of_float (Calc_float.fact 9.));
	print_endline (string_of_int (Calc_int.fact 0));
	print_endline (string_of_float (Calc_float.fact 0.));
	print_endline (string_of_int (Calc_int.div 9 2));
	print_endline (string_of_float (Calc_float.div 9. 2.));
	print_endline (string_of_int (Calc_int.power 9 0));
	print_endline (string_of_float (Calc_float.power 0.5 (-2)));
	print_endline "Ciao"
